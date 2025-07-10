#include "main.h"
#include <string.h>
#include <stdio.h>

#define CMD_BUFFER_SIZE 64

static char rxBuffer[CMD_BUFFER_SIZE];
static uint8_t rxChar;
static uint8_t rxIndex = 0;

extern UART_HandleTypeDef huart2;

void USART_StartReceive_IT(){
	HAL_UART_Receive_IT(&huart2, &rxChar, 1);
}

void USART_ProcessChar(uint8_t c){
	if(c == '\n' || c == '\r'){
		rxBuffer[rxIndex] = 0;
		USART_ProcessCommand(rxBuffer);
		rxIndex = 0;
	}
	else if(rxIndex < CMD_BUFFER_SIZE - 1){
		rxBuffer[rxIndex++] = c;
	}
}

void USART_ProcessCommand(const char* cmd){
	if(strcmp(cmd, "LED ON") == 0){
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
		printf("LED turned ON\r\n");
	}
	else if(strcmp(cmd, "LED OFF") == 0){
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
		printf("LED turned OFF\r\n");
	}
	else if(strcmp(cmd, "STATUS") == 0){
		GPIO_PinState state = HAL_GPIO_ReadPin(LD3_GPIO_Port, LD3_Pin);
		printf("LED is %s\r\n", (state == GPIO_PIN_SET) ? "ON" : "OFF");
	}
	else {
		printf("Unknown command. Try: LED ON, LED OFF, STATUS\r\n");
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (huart->Instance == USART2){
		USART_ProcessChar(rxChar);
		HAL_UART_Receive_IT(&huart2, &rxChar, 1);
	}
}
