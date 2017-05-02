//
// Created by 123 on 28.04.2017.
//

#ifndef COMPUTER_CORE_H
#define COMPUTER_CORE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "instruction.h"

enum {
    DATA_SIZE = 16,
    BIT_DATA_SIZE = 16,
    REGISTER_COUNT = 8,
    CODE_SIZE = 16
};

uint8_t data_memory[DATA_SIZE];
uint8_t bit_memory[BIT_DATA_SIZE];
uint8_t r[REGISTER_COUNT];
uint8_t ic;
uint8_t acc;

Instruction code[CODE_SIZE];

struct {
    uint8_t c;
    uint8_t p;
} psw;

void execute_instruction(Instruction instruction);

#endif //COMPUTER_CORE_H
