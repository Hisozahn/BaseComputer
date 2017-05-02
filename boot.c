#include <stdio.h>
#include <stdint.h>
#include <mem.h>
#include "instruction.h"
#include "core.h"
#include "logger.h"

Instruction test_program[] = {
        { ANL_C_BIT, 0},
        { ANL_C_NOT_BIT, 0},
        { ANL_A_R_INDIRECT, 0},
        { ANL_A_ADDRESS, 1},
        { MOV_R_DIRECT__ADDRESS, 1, 2},
        { MOV_R_INDIRECT__ADDRESS, 2, 3},
        { DJNZ_R_DIRECT__OFFSET, 3, 1},
        { MOV_R_DIRECT__ADDRESS, 0, 5},
        { ANL_C_BIT, 0 }
};

void prepare_test_data() {
    // 1-2
    psw.c = 1;
    bit_memory[0] = 1;
    // 3
    r[0] = 0;
    data_memory[0] = 0xd6;
    acc = 0x35;
    psw.p = 1;
    // 4
    data_memory[1] = 0xf0;
    // 5
    data_memory[2] = 0xED;
    // 6
    data_memory[3] = 0x51;
    r[2] = 4;
    // 7
    r[3] = 2;
    // 8
    data_memory[5] = 0xff;
}

void init_core() {
    memset(data_memory, 0, sizeof(data_memory) / sizeof(data_memory[0]));
    memset(bit_memory, 0, sizeof(bit_memory) / sizeof(bit_memory[0]));
    memset(code, 0, sizeof(code) / sizeof(code[0]));
    memset(r, 0, sizeof(r) / sizeof(r[0]));
    ic = 0;
    acc = 0;
    psw.p = 0;
    psw.c = 0;
}

void load_test_program() {
    for (size_t i = 0; i < sizeof(test_program) / sizeof(test_program[0]); i++) {
        code[i] = test_program[i];
    }
}

void run_test() {
    print_full_core_state();
    while (ic < 9) {
        print_instruction(code[ic]);
        execute_instruction(code[ic]);
        print_full_core_state();
    }
}

int main() {
    init_core();
    prepare_test_data();
    load_test_program();
    run_test();
    return 0;
}