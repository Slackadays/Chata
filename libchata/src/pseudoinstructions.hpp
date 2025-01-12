// SPDX-License-Identifier: MPL-2.0
#include "assembler.hpp"
#include "libchata.hpp"

namespace libchata_internal {

chatavector<instruction> li_instr(assembly_context& c);
chatavector<instruction> la_instr(assembly_context& c);
chatavector<instruction> mv_instr(assembly_context& c);
chatavector<instruction> not_instr(assembly_context& c);
chatavector<instruction> neg_instr(assembly_context& c);
chatavector<instruction> bgt_instr(assembly_context& c);
chatavector<instruction> ble_instr(assembly_context& c);
chatavector<instruction> bgtu_instr(assembly_context& c);
chatavector<instruction> bleu_instr(assembly_context& c);
chatavector<instruction> beqz_instr(assembly_context& c);
chatavector<instruction> bnez_instr(assembly_context& c);
chatavector<instruction> bgez_instr(assembly_context& c);
chatavector<instruction> blez_instr(assembly_context& c);
chatavector<instruction> bgtz_instr(assembly_context& c);
chatavector<instruction> j_instr(assembly_context& c);
chatavector<instruction> call_instr(assembly_context& c);
chatavector<instruction> ret_instr(assembly_context& c);
chatavector<instruction> nop_instr(assembly_context& c);
chatavector<instruction> fmvsx_instr(assembly_context& c);
chatavector<instruction> fmvxs_instr(assembly_context& c);

} // namespace libchata_internal