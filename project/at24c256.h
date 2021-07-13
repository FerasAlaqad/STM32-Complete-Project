/*
 * at24c32.h
 *
 *  Created on: 1 Oca 2020
 *      Author: MS
 */

#ifndef INC_AT24C256_H_
#define INC_AT24C256_H_

#include <stdint.h>
#include <stm32f1xx_hal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern HAL_StatusTypeDef ret;

uint8_t _readEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres);

void _writeEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres, uint8_t value);

void _writeEEPROMString(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres, uint8_t *value);

void _readEEPROMString(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres, uint16_t len, uint8_t retValue[]);

void _eraseEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres);

void _fillEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres);

void _readAllEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres, uint16_t len, uint8_t retValue[]);


#endif /* INC_AT24C256_H_ */
