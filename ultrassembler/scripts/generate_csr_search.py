input = "src/csrs.cpp"
output = "src/generated/csr_search.cpp"

import re

content = ""
with open(input, "r") as file:
    content = file.read()

csrex = "(?<={)\"([\w.]+)\""

csrs = re.findall(csrex, content)

# Now add each csr's list position to itself
for i in range(len(csrs)):
    csrs[i] = (csrs[i], i)

csrs.sort()

print(csrs)

depth = 0

current_csr = ""

code = "// SPDX-License-Identifier: MPL-2.0\n"
code += "// The generate_csrister_search.py script automatically generated this code. DO NOT MODIFY!\n"
code += "#include \"../csrs.hpp\"\n"
code += "#include \"../ultrassembler.hpp\"\n\n"
code += "namespace ultrassembler_internal {\n\n"
code += "const uint16_t fast_csr_search(const ultrastring& csr) {\n"

def ind():
    return "    " * (depth + 1)

def csr_exists(csr):
    return csr in [i[0] for i in csrs]
    
def prefix_exists(prefix):
    return any([csr.startswith(prefix) for csr in [i[0] for i in csrs]])

potentialchars = ""

# Get all used chars in csrs
for csr in csrs:
    for char in csr[0]:
        if char not in potentialchars:
            potentialchars += char

def process_depth():
    global code, current_csr, depth
    if csr_exists(current_csr):
        code += ind() + f"if (csr.size() < {depth + 1}) return {csrs[[i[0] for i in csrs].index(current_csr)][1]};\n"
    else:
        code += ind() + f"if (csr.size() < {depth + 1}) return csr_search_failed;\n"
    for letter in potentialchars:
        if prefix_exists(current_csr + letter):
            code += ind() + f"if (csr[{depth}] == '{letter}') {{\n"
            current_csr += letter
            depth += 1
            process_depth()
            depth -= 1
            current_csr = current_csr[:-1]
            code += ind() + "}\n"
        

process_depth()

code += ind() + "return csr_search_failed;\n"
code += "}\n\n"
code += "} // namespace ultrassembler_internal"

print(code)

with open(output, "w") as file:
    file.write(code)