//
// Created by 123 on 28.04.2017.
//

#ifndef COMPUTER_INSTRUCTION_H
#define COMPUTER_INSTRUCTION_H

#include <stdint.h>

typedef enum {
    ANL_A_R_INDIRECT,
    ANL_A_ADDRESS,
    ANL_C_BIT,
    ANL_C_NOT_BIT,

    MOV_R_DIRECT__ADDRESS,
    MOV_R_INDIRECT__ADDRESS,

    DJNZ_R_DIRECT__OFFSET
} InstructionName;

typedef struct {
    InstructionName name;
    uint8_t arg1;
    uint8_t arg2;
} Instruction;

static uint8_t has_even_parity(uint8_t x);
void anl_a_r_indirect(uint8_t r_num);
void anl_a_address(uint8_t data_address);
void anl_c_bit(uint8_t bit_address);
void anl_c_not_bit(uint8_t bit_address);
void mov_r_direct_address(uint8_t r_num, uint8_t data_address);
void mov_r_indirect_address(uint8_t r_num, uint8_t data_address);
void djnz_r_direct_offset(uint8_t r_num, uint8_t offset);

#endif //COMPUTER_INSTRUCTION_H
