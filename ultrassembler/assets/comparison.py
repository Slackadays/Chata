import matplotlib.pyplot as plt
from matplotlib import font_manager
import os.path
import numpy as np

riscv_platform = "T-Head TH1520"
x86_platform = "AMD 5900x"

as_name = "as 2.43.1/2.28"
llvm_name = "llvm-mc 17/20"
ultrassembler_name = "Ultrassembler 06d5281"

riscv_as_cycles = 222987317
riscv_llvm_cycles = 442515070
riscv_ultrassembler_cycles = 25441650

x86_as_cycles = 53377222
x86_llvm_cycles = 88401270
x86_ultrassembler_cycles = 4010538

maxcycles = max(riscv_as_cycles, riscv_llvm_cycles, riscv_ultrassembler_cycles)

riscv_as_cycles = riscv_as_cycles / maxcycles * 100

riscv_llvm_cycles = riscv_llvm_cycles / maxcycles * 100

riscv_ultrassembler_cycles = riscv_ultrassembler_cycles / maxcycles * 100

maxcycles = max(x86_as_cycles, x86_llvm_cycles, x86_ultrassembler_cycles)

x86_as_cycles = x86_as_cycles / maxcycles * 100

x86_llvm_cycles = x86_llvm_cycles / maxcycles * 100

x86_ultrassembler_cycles = x86_ultrassembler_cycles / maxcycles * 100

chart_title = "Cycles to assemble 16kinstrs.s (normalized per platform)"

theme = "dark_background"

barwidth = 0.25

multiplier = 0

# Bar graph with riscv and x86 in two different sections, comparing as, llvm, and ultrassembler each

plt.style.use(theme)

fontloc = "/home/jackson/.local/share/fonts/Unbounded-VariableFont_wght.ttf"

if os.path.isfile(fontloc):
    font_manager.fontManager.addfont(fontloc)
    plt.rcParams.update({'font.family': 'Unbounded'})


plt.bar(np.arange(2), [riscv_llvm_cycles, x86_llvm_cycles], color='r', width=barwidth, edgecolor='grey', label=llvm_name)
plt.bar_label(plt.bar(np.arange(2), [riscv_llvm_cycles, x86_llvm_cycles], color='r', width=barwidth, edgecolor='grey'), fmt='%.2f%%')
plt.bar(np.arange(2) + barwidth, [riscv_as_cycles, x86_as_cycles], color='b', width=barwidth, edgecolor='grey', label=as_name)
plt.bar_label(plt.bar(np.arange(2) + barwidth, [riscv_as_cycles, x86_as_cycles], color='b', width=barwidth, edgecolor='grey'), fmt='%.2f%%')
plt.bar(np.arange(2) + barwidth * 2, [riscv_ultrassembler_cycles, x86_ultrassembler_cycles], color='g', width=barwidth, edgecolor='grey', label=ultrassembler_name)
plt.bar_label(plt.bar(np.arange(2) + barwidth * 2, [riscv_ultrassembler_cycles, x86_ultrassembler_cycles], color='g', width=barwidth, edgecolor='grey'), fmt='%.2f%%')

plt.xlabel("Host Platform CPU")

plt.ylabel("Cycles (%)")

plt.xticks(np.arange(2) + barwidth, [riscv_platform, x86_platform])

plt.title(chart_title)

# Move the legend a little down
plt.legend(bbox_to_anchor=(.58, .87), shadow=True)

plt.show()
