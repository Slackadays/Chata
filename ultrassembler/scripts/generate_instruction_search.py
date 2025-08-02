'''
This script automatically generates an accelerated string lookup function for the RISC-V instructions array. When generated, the code looks something like this if the example instructions are: 
add (offset 0)
addw (offset 1)
and (offset 2)
mul (offset 3)
mulw (offset 4)

if (ins.size() < 1) return -1; // First, check if there are candidates at the 0 depth. There are none, so return -1
if (ins[0] == 'a') { // Then check if there are instructions with prefix 'a'. There are, so add this if statement
	if (ins.size() < 2) return -1; // Check if there are candidates with value 'a'. There are none, so return -1
	if (ins[1] == 'd') { // Check if there are instructions with prefix 'ad'. There are, so add this if statement
		if (ins.size() < 3) return -1; // Check if there are candidates with value 'ad'. There are none, so return -1
		if (ins[2] == 'd') { // Check if there are instructions with prefix 'add'. There are, so add this if statement
			if (ins.size() < 4) return 0; // Check if there are candidates with value 'add'. There are, so return 0
			if (ins[3] == 'w') { // Check if there are instructions with prefix 'addw'. There are, so add this if statement
				if (ins.size() < 5) return 1; // Check if there are candidates with value 'addw'. There are, so return 1
			}
		}
	} else if (ins[1] == 'n') {
		if (ins.size() < 3) return -1;
		if (ins[2] == 'd') {
			if (ins.size() < 4) return 2;
		}
	}
} else if (ins[0] == 'm') {
	etc.
} else {
	return -1;
}
'''

input = "src/instructions.cpp"
output = "src/generated/instruction_search.cpp"

import re

content = ""
with open(input, "r") as file:
    content = file.read()

regex = "(?<={)\"([\w.]+)\""

instructions = re.findall(regex, content)

# Now add each instruction's list position to itself along with length
for i in range(len(instructions)):
    instructions[i] = (instructions[i], i, len(instructions[i]))

instructions.sort()

print(instructions)

min_len = min([i[2] for i in instructions])

max_len = max([i[2] for i in instructions])

depth = 0

current_instr = ""

code = "// SPDX-License-Identifier: MPL-2.0\n"
code += "// The generate_instruction_search.py script automatically generated this code. DO NOT MODIFY!\n"
code += "#include \"../instructions.hpp\"\n"
code += "#include \"../ultrassembler.hpp\"\n\n"
code += "namespace ultrassembler_internal {\n\n"
code += "const uint16_t fast_instr_search(const ultrastring& inst) {\n"
code += "    const auto size = inst.size();\n\n"

def ind():
    return "    " * (depth + 2)

def instr_exists(instr, length):
    #return instr in [i[0] for i in instructions]
    for i in instructions:
        if i[0] == instr and i[2] == length:
            return True
    return False
    
def prefix_exists(prefix, length):
    #return any([instr.startswith(prefix) for instr in [i[0] for i in instructions]])
    for i in instructions:
        if i[0].startswith(prefix) and i[2] == length:
            return True
    return False

potentialchars = ""

# Get all used chars in instructions
for instr in instructions:
    for char in instr[0]:
        if char not in potentialchars:
            potentialchars += char

def process_depth(current_len):
    global code, current_instr, depth
    #if instr_exists(current_instr):
    #    code += ind() + f"if (inst.size() < {depth + 1}) return {instructions[[i[0] for i in instructions].index######(current_instr)][1]};\n"
    #else:
    #    code += ind() + f"if (inst.size() < {depth + 1}) return instr_search_failed;\n"
    for letter in potentialchars:
        if instr_exists(current_instr + letter, current_len):
            code += ind() + f"if (inst[{depth}] == '{letter}') return {instructions[[i[0] for i in instructions].index(current_instr + letter)][1]};\n"
        elif prefix_exists(current_instr + letter, current_len):
            code += ind() + f"if (inst[{depth}] == '{letter}') {{\n"
            current_instr += letter
            depth += 1
            process_depth(current_len)
            depth -= 1
            current_instr = current_instr[:-1]
            code += ind() + "}\n"
        

for i in range(min_len, max_len + 1):
    code += f"    if (size == {i}) {{\n"
    process_depth(i)
    code += "    }\n\n"

code += "    return instr_search_failed;\n"
code += "}\n\n"
code += "} // namespace ultrassembler_internal"

print(code)

#exit()

with open(output, "w") as file:
    file.write(code)