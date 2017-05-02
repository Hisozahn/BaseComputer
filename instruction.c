//
// Created by 123 on 28.04.2017.
//

#include <assert.h>
#include "instruction.h"
#include "core.h"

static uint8_t has_even_parity(uint8_t x){
    uint8_t count = 0, i, b = 1;

    for (i = 0; i < 8; i++){
        if ( x & (b << i) ) {
            count++;
        }
    }

    if (count % 2) {
        return 0;
    }

    return 1;
}

void anl_a_r_indirect(uint8_t r_num) {
    assert(r_num < REGISTER_COUNT);
    assert(r[r_num] < DATA_SIZE);

    ic++;
    acc &= data_memory[r[r_num]];
    psw.p = has_even_parity(acc);
}

void anl_a_address(uint8_t data_address) {
    assert(data_address < DATA_SIZE);

    ic++;
    acc &= data_memory[data_address];
    psw.p = has_even_parity(acc);
}

void anl_c_bit(uint8_t bit_address) {
    assert(bit_address < BIT_DATA_SIZE);

    ic++;
    psw.c &= bit_memory[bit_address];
}

void anl_c_not_bit(uint8_t bit_address) {
    assert(bit_address < BIT_DATA_SIZE);

    ic++;
    psw.c &= !bit_memory[bit_address];
}

void mov_r_direct_address(uint8_t r_num, uint8_t data_address) {
    assert(r_num < REGISTER_COUNT);
    assert(data_address < DATA_SIZE);

    ic++;
    r[r_num] = data_memory[data_address];
}

void mov_r_indirect_address(uint8_t r_num, uint8_t data_address) {
    assert(r_num < REGISTER_COUNT);
    assert(data_address < DATA_SIZE);
    assert(r[r_num] < DATA_SIZE);

    ic++;
    data_memory[r[r_num]] = data_memory[data_address];
}

void djnz_r_direct_offset(uint8_t r_num, uint8_t offset) {
    assert(r_num < REGISTER_COUNT);

    ic++;
    r[r_num]--;
    if (r[r_num] != 0) {
        ic += offset;
    }
}