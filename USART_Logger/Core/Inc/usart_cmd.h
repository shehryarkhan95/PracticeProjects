/*
 * usart_cmd.h
 *
 *  Created on: Jul 10, 2025
 *      Author: blazi
 */

#ifndef INC_USART_CMD_H_
#define INC_USART_CMD_H_

#include "stm32l4xx_hal.h"

void USART_StartReceive_IT(void);
void USART_ProcessChar(uint8_t c);
void USART_ProcessCommand(const char* cmd);

#endif /* INC_USART_CMD_H_ */
