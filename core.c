//
// Created by 123 on 28.04.2017.
//

#include "core.h"

void execute_instruction(Instruction instruction) {
    switch (instruction.name) {
        case ANL_A_R_INDIRECT:
            anl_a_r_indirect(instruction.arg1);
            break;
        case ANL_A_ADDRESS:
            anl_a_address(instruction.arg1);
            break;
        case ANL_C_BIT:
            anl_c_bit(instruction.arg1);
            break;
        case ANL_C_NOT_BIT:
            anl_c_not_bit(instruction.arg1);
            break;
        case MOV_R_DIRECT__ADDRESS:
            mov_r_direct_address(instruction.arg1, instruction.arg2);
            break;
        case MOV_R_INDIRECT__ADDRESS:
            mov_r_indirect_address(instruction.arg1, instruction.arg2);
            break;
        case DJNZ_R_DIRECT__OFFSET:
            djnz_r_direct_offset(instruction.arg1, instruction.arg2);
            break;
        default:
            fputs("Unknown instruction", stderr);
            exit(1);
    }
}