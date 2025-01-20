input = "pseudoinstructions.cpp"
output = "assembler.cpp"

import re

content = ""
with open(input, "r") as file:
    content = file.read()

regex = "chatavector<instruction> ([\w_-]+)_instr\("

pseudoinstructions = re.findall(regex, content)

def to_real_name(instr):
    # Replace all "-" with "." to convert to the real instruction name
    return instr.replace("_", ".")

pseudoinstructions = [to_real_name(instr) for instr in pseudoinstructions]

pseudoinstructions.sort()

print(pseudoinstructions)

depth = 0

current_instr = ""

code = "// Start make_inst_from_pseudoinst\n"
code += "chatavector<instruction> make_inst_from_pseudoinst(assembly_context& c) {\n"

def ind():
    return "    " * (depth + 1)

def instr_exists(instr):
    return instr in pseudoinstructions
    
def prefix_exists(prefix):
    return any([instr.startswith(prefix) for instr in pseudoinstructions])

def to_cpp_name(instr):
    return instr.replace(".", "_")

potentialchars = ""

# Get all used chars in pseudoinstructions
for instr in pseudoinstructions:
    for char in instr:
        if char not in potentialchars:
            potentialchars += char

def process_depth():
    global code, current_instr, depth
    if instr_exists(current_instr):
        code += ind() + f"if (c.inst.size() < {depth + 1}) return {to_cpp_name(current_instr)}_instr(c);\n"
    else:
        code += ind() + f"if (c.inst.size() < {depth + 1}) return {{}};\n"
    for letter in potentialchars:
        if prefix_exists(current_instr + letter):
            code += ind() + f"if (c.inst[{depth}] == '{letter}') {{\n"
            current_instr += letter
            depth += 1
            process_depth()
            depth -= 1
            current_instr = current_instr[:-1]
            code += ind() + "}\n"
        

process_depth()

code += ind() + "return {};\n"
code += "}\n"
code += "// End make_inst_from_pseudoinst"

print(code)

replace_regex = "\/\/ Start make_inst_from_pseudoinst(.*)\/\/ End make_inst_from_pseudoinst"

output_content = ""

with open(output, "r") as file:
    output_content = file.read()

with open(output, "w") as file:
    file.write(re.sub(replace_regex, code, output_content, flags=re.DOTALL))