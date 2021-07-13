/*
 * at24c32.c
 *
 *  Created on: 1 Oca 2020
 *      Author: MS
 */
#include "at24c256.h"
#include <stdint.h>

#include <stm32f1xx_hal.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t _readEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres) {
	uint8_t val[2] = { 0 };
	val[0] = (memAdres >> 8) & 0xFF; //0000 1101
	val[1] = (memAdres & 0xFF); //1010 1100
	uint8_t buf2[50] = { 0 };
	ret = HAL_I2C_Master_Transmit(i2cbus, devAdres, val, 2, HAL_MAX_DELAY);
	HAL_Delay(10);
	if (ret != HAL_OK) {
		strcpy((char*) buf2, "EEPROM Read Error I2C-TX\r\n");
	} else {
		ret = HAL_I2C_Master_Receive(i2cbus, devAdres, val, 1, HAL_MAX_DELAY);
		HAL_Delay(10);
		if (ret != HAL_OK) {
			strcpy((char*) buf2, "EEPROM Read Error I2C-RX\r\n");
		} else {
			// buf2 usart ile gonder hatayi
			
		}
	}
	return val[0];
}

void _writeEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres, uint8_t value) {
	uint8_t val[3] = { 0 };
	//val[0] = devAdres;
	val[0] = (memAdres >> 8) & 0xFF;
	val[1] = (memAdres & 0xFF);
	val[2] = value;

	uint8_t buf2[50] = { 0 };
	ret = HAL_I2C_Master_Transmit(i2cbus, devAdres, val, 3, 1000);
	HAL_Delay(10);
	if (ret != HAL_OK) {
		strcpy((char*) buf2, "EEPROM Write Error I2C-TX\r\n");
	} else {
		strcpy((char*) buf2, "EEPROM Write Success I2C-TX\r\n");
	}
}

void _writeEEPROMString(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres, uint8_t *value) {
	int pos = 0; //char ch[] = "Selam"; 'S', 'e', 'l', 'a', 'm', '\0';
	while (*value != '\0') {
		_writeEEPROM(i2cbus, devAdres, memAdres + pos, *value++);
		pos++;
	}
}

void _readEEPROMString(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres, uint16_t len, uint8_t retValue[]) {
	for (int i = 0; i < len; i++) {
		retValue[i] = _readEEPROM(i2cbus, devAdres, memAdres + i);
	}
}

void _eraseEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres) {
	for (uint16_t i = 0; i < 32768; i += 64) {
		uint8_t val2[34] = { 0 };
		val2[0] = ((i) >> 8) & 0xFF;
		val2[1] = ((i) & 0xFF);
		ret = HAL_I2C_Master_Transmit(i2cbus, devAdres, val2, 66, 1000);
		HAL_Delay(10);
	}
	uint8_t buf2[50] = { 0 };
	if (ret != HAL_OK) {
		strcpy((char*) buf2, "ERASE EEPROM Error I2C-TX\r\n");
	} else {
		strcpy((char*) buf2, "ERASE EEPROM Success I2C-TX\r\n");
	}
}

void _fillEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres) {
	uint8_t fc = 32;
	for (uint16_t memAdres = 0; memAdres < 32768; memAdres += 32) {
		uint8_t val2[34] = { 0 };
		val2[0] = (memAdres >> 8) & 0xFF;
		val2[1] = (memAdres & 0xFF);
		for (uint8_t j = 2; j <= 33; j++) {
			val2[j] = fc++;
			if (fc > 127) fc = 32;
		}
		ret = HAL_I2C_Master_Transmit(i2cbus, devAdres, val2, 34, 1000);
		HAL_Delay(10);
	}
	uint8_t buf2[50] = { 0 };
	if (ret != HAL_OK) {
		strcpy((char*) buf2, "FILL EEPROM Error I2C-TX\r\n");
	} else {
		strcpy((char*) buf2, "FILL EEPROM Success I2C-TX\r\n");
	}
}

void _readAllEEPROM(I2C_HandleTypeDef *i2cbus, uint8_t devAdres, uint16_t memAdres, uint16_t len, uint8_t retValue[]) {
	uint8_t val[2] = { 0 };
	val[0] = (memAdres >> 8) & 0xFF;
	val[1] = (memAdres & 0xFF);
	uint8_t buf2[50] = { 0 };
	ret = HAL_I2C_Master_Transmit(i2cbus, devAdres, val, 2, 1000);
	HAL_Delay(10);
	if (ret != HAL_OK) {
		strcpy((char*) buf2, "EEPROM Read Error I2C-TX\r\n");
	} else {
		ret = HAL_I2C_Master_Receive(i2cbus, devAdres, retValue, len, HAL_MAX_DELAY);
		HAL_Delay(10);
		if (ret != HAL_OK) {
			strcpy((char*) buf2, "EEPROM Read Error I2C-RX\r\n");
		} else {

		}
	}
}
