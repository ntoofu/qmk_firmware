#include "matrix.h"
#include "i2c_master.h"
#include "quantum.h"
#include "debounce.h"


static const uint16_t timeout = 100;

static matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
static matrix_row_t matrix[MATRIX_ROWS];      // debounced values

extern uint8_t matrix_num_keys;
uint8_t matrix_num_keys = 64;

__attribute__((weak)) void matrix_init_quantum(void) { matrix_init_kb(); }
__attribute__((weak)) void matrix_scan_quantum(void) { matrix_scan_kb(); }
__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }
__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }
__attribute__((weak)) void matrix_init_user(void) {}
__attribute__((weak)) void matrix_scan_user(void) {}

void handle_i2c_error(uint8_t addr) {
    return;
}

void matrix_init(void) {
    i2c_init();
    _delay_ms(1000);
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i]     = 0;
    }
    for (uint8_t addr = 0; addr < matrix_num_keys; addr++) {
        uint8_t data = 0xb0;
        i2c_status_t i2c_status = i2c_transmit(addr << 1, &data, 1, timeout);
        if (i2c_status != I2C_STATUS_SUCCESS) {
            handle_i2c_error(addr);
        }
    }
    _delay_ms(500);
    for (uint8_t addr = 0; addr < matrix_num_keys; addr++) {
        uint8_t data = 0x00;
        i2c_status_t i2c_status = i2c_transmit(addr << 1, &data, 1, timeout);
        if (i2c_status != I2C_STATUS_SUCCESS) {
            handle_i2c_error(addr);
        }
    }
    debounce_init(MATRIX_ROWS);
    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    bool changed = false;
    uint8_t addr = 0;
    const uint8_t effective_rows = ( matrix_num_keys + MATRIX_COLS - 1 ) / MATRIX_COLS;
    for (uint8_t current_row = 0; current_row < effective_rows; ++current_row) {
        matrix_row_t row = 0;
        const uint8_t effective_cols = matrix_num_keys - current_row * MATRIX_COLS;
        for (uint8_t current_col = 0; current_col < effective_cols; ++current_col) {
            uint8_t key_pressed = 0;
            i2c_status_t i2c_status = i2c_receive(addr++ << 1, &key_pressed, 1, timeout);
            if (i2c_status != I2C_STATUS_SUCCESS) {
                handle_i2c_error(addr);
            }
            if (key_pressed) {
                writePinLow(F5);
                row |= 1 << current_col;
            }
        }
        if (raw_matrix[current_row] != row) {
            raw_matrix[current_row] = row;
            changed = true;
        }
    }

    debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    matrix_scan_quantum();
    return (uint8_t)changed;
}

void matrix_print(void) {
    uint8_t num = 0;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        matrix_row_t data = matrix_get_row(row);
        for (int col = 0; col < MATRIX_COLS; col++) {
            printf("%d: ", ++num);
            if (data & (1<<col))
                printf("1\n");
            else
                printf("0\n");
        }
    }
}

inline matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}
