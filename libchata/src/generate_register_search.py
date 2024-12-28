input = "registers.cpp"
output = "register_search.cpp"

import re

content = ""
with open(input, "r") as file:
    content = file.read()

regex = "(?<={)\"([\w]+)\", \"([\w]+)\""

registers = re.findall(regex, content)

# Now add each register's list position to itself
for i in range(len(registers)):
    registers[i] = (registers[i], i)

# Now transform the register list from [[name1, name2], id] to [[name1, id], [name2, id]]
new_registers = []
for i in range(len(registers)):
    new_registers.append((registers[i][0][0], registers[i][1]))
    new_registers.append((registers[i][0][1], registers[i][1]))
registers = new_registers

registers.sort()

print(registers)

depth = 0

current_reg = ""

code = "// SPDX-License-Identifier: MPL-2.0\n"
code += "// The generate_register_search.py script automatically generated this code. DO NOT MODIFY!\n"
code += "#include \"libchata.hpp\"\n"
code += "#include \"registers.hpp\"\n\n"
code += "namespace libchata_internal {\n\n"
code += "const uint8_t fast_reg_search(const chatastring& reg) {\n"

def ind():
    return "    " * (depth + 1)

def reg_exists(reg):
    return reg in [i[0] for i in registers]
    
def prefix_exists(prefix):
    return any([reg.startswith(prefix) for reg in [i[0] for i in registers]])

potentialchars = ""

# Get all used chars in registers
for reg in registers:
    for char in reg[0]:
        if char not in potentialchars:
            potentialchars += char

def process_depth():
    global code, current_reg, depth
    if reg_exists(current_reg):
        code += ind() + f"if (reg.size() < {depth + 1}) return {registers[[i[0] for i in registers].index(current_reg)][1]};\n"
    else:
        code += ind() + f"if (reg.size() < {depth + 1}) return reg_search_failed;\n"
    for letter in potentialchars:
        if prefix_exists(current_reg + letter):
            code += ind() + f"if (reg[{depth}] == '{letter}') {{\n"
            current_reg += letter
            depth += 1
            process_depth()
            depth -= 1
            current_reg = current_reg[:-1]
            code += ind() + "}\n"
        

process_depth()

code += ind() + "return -1;\n"
code += "}\n\n"
code += "} // namespace libchata_internal"

print(code)

with open(output, "w") as file:
    file.write(code)