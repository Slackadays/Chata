input = "src/registers.cpp"
output = "src/generated/register_search.cpp"

import re

content = ""
with open(input, "r") as file:
    content = file.read()

regex = "(?<={)\"([\w]+)\", \"([\w]+)\""

registers = re.findall(regex, content)

# Now add each register's list position to itself
for i in range(len(registers)):
    registers[i] = (registers[i], i)

# Now transform the register list from [[name1, name2], id] to [[name1, id, len], [name2, id, len]]
new_registers = []
for i in range(len(registers)):
    new_registers.append((registers[i][0][0], registers[i][1], len(registers[i][0][0])))
    new_registers.append((registers[i][0][1], registers[i][1], len(registers[i][0][1])))
registers = new_registers

registers.sort()

print(registers)

min_len = min([i[2] for i in registers])

max_len = max([i[2] for i in registers])

depth = 0

current_reg = ""

code = "// SPDX-License-Identifier: MPL-2.0\n"
code += "// The generate_register_search.py script automatically generated this code. DO NOT MODIFY!\n"
code += "#include \"../ultrassembler.hpp\"\n"
code += "#include \"../registers.hpp\"\n\n"
code += "namespace ultrassembler_internal {\n\n"
code += "const uint8_t fast_reg_search(const ultrastring& reg) {\n"
code += "    const auto size = reg.size();\n\n"

def ind():
    return "    " * (depth + 2)

def reg_exists(reg, length):
    #return reg in [i[0] for i in registers]
    for r in registers:
        if r[0] == reg and r[2] == length:
            return True
    return False
    
def prefix_exists(prefix, length):
    #return any([reg.startswith(prefix) for reg in [i[0] for i in registers]])
    #the above line but with the current length
    for reg in registers:
        if reg[0].startswith(prefix) and reg[2] == length:
            return True
    return False

potentialchars = ""

# Get all used chars in registers
for reg in registers:
    for char in reg[0]:
        if char not in potentialchars:
            potentialchars += char

def process_depth(current_len):
    global code, current_reg, depth
    #if reg_exists(current_reg):
    #    code += ind() + f"if (reg.size() < {depth + 1}) return {registers[[i[0] for i in registers].index(current_reg)][1]};\n"
    #else:
    #    code += ind() + f"if (reg.size() < {depth + 1}) return reg_search_failed;\n"
    for letter in potentialchars:
        
        if reg_exists(current_reg + letter, current_len):
            print(f"Found register {current_reg + letter} at depth {depth} with length {current_len}")
            code += ind() + f"if (reg[{depth}] == '{letter}') return {registers[[i[0] for i in registers].index(current_reg + letter)][1]};\n"
        elif prefix_exists(current_reg + letter, current_len):
            print(f"Found prefix {current_reg + letter} at depth {depth} with length {current_len}")
            code += ind() + f"if (reg[{depth}] == '{letter}') {{\n"
            current_reg += letter
            depth += 1
            process_depth(current_len)
            depth -= 1
            current_reg = current_reg[:-1]
            code += ind() + "}\n"
        
for i in range(min_len, max_len + 1):
    code += f"    if (size == {i}) {{\n"
    process_depth(i)
    code += "    }\n\n"

code += "    return reg_search_failed;\n"
code += "}\n\n"
code += "} // namespace ultrassembler_internal"

print(code)

#exit()

with open(output, "w") as file:
    file.write(code)