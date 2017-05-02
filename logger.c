//
// Created by 123 on 28.04.2017.
//
#include "logger.h"

void print_instruction(Instruction instruction) {
    printf("%s", "++++++++++++++++++++++++");
    switch (instruction.name) {
        case ANL_A_R_INDIRECT:
            printf("ANL A, @R%d", instruction.arg1);
            break;
        case ANL_A_ADDRESS:
            printf("ANL A, %dh", instruction.arg1);
            break;
        case ANL_C_BIT:
            printf("ANL C, %dh", instruction.arg1);
            break;
        case ANL_C_NOT_BIT:
            printf("ANL C, /%dh", instruction.arg1);
            break;
        case MOV_R_DIRECT__ADDRESS:
            printf("MOV R%d, %dh", instruction.arg1, instruction.arg2);
            break;
        case MOV_R_INDIRECT__ADDRESS:
            printf("MOV @R%d, %dh", instruction.arg1, instruction.arg2);
            break;
        case DJNZ_R_DIRECT__OFFSET:
            printf("DJNZ R%d, %d", instruction.arg1, instruction.arg2);
            break;
        default:
            fputs("Unknown instruction", stderr);
            return;
    }
    printf("%s", "++++++++++++++++++++++++\n");
}

void print_main_registers() {
    puts("===MAIN REGISTERS===");
    printf("ACC:\t%d\nIC:\t%d\nPSW:\tC %d | P %d\n",
            acc, ic, psw.c, psw.p);
}
void print_r_registers() {
    puts("===R REGISTERS===");
    for (size_t i = 0; i < REGISTER_COUNT; i++) {
        printf("%d\t", r[i]);
    }
    puts("");
}
void print_data() {
    puts("===DATA===");
    for (size_t i = 0; i < DATA_SIZE; i++) {
        printf("%d\t", data_memory[i]);
        if (i != 0 && i % 8 == 7) {
            puts("");
        }
    }
}
void print_bit_data() {
    puts("===BIT DATA===");
    for (size_t i = 0; i < BIT_DATA_SIZE; i++) {
        printf("%d\t", bit_memory[i]);
        if (i != 0 && i % 8 == 7) {
            puts("");
        }
    }
}

void print_full_core_state() {
    print_main_registers();
    print_r_registers();
    print_data();
    print_bit_data();
}