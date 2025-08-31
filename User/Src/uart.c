#include "uart.h"

// flag
bool forcedMove = 0;
bool restart = 0;
bool choosingFloor = 0;
bool executeRotation = false;
//
//uint8_t ACK1[] = "Continue...\r\n\r\n";
//uint8_t ACK2[] = "Going to nearest Floor...\r\n\r\n";
//uint8_t ACK3[] = "Choose Floor to go:\r\n1. 1st Floor\r\n2. 2nd Floor\r\n3. 3rd Floor\r\n4. Cancel\r\n\r\n";
//uint8_t ACK4[] = "Going to Floor 1...\r\n\r\n";
//uint8_t ACK5[] = "Going to Floor 2...\r\n\r\n";
//uint8_t ACK6[] = "Going to Floor 3...\r\n\r\n";
//
//uint8_t Warn1[] = "Invalid input! Please enter between 1 and 3.\r\n\r\n";
//uint8_t Warn2[] = "Invalid input! Please enter between 1 and 4.\r\n\r\n";
//
//uint8_t nextMove = 0;
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//    if (huart->Instance == USART2) {
//        if(choosingFloor){
//            // 층 선택 처리
//            if(rxData == '1'){
//                HAL_UART_Transmit_IT(&huart2, ACK4, sizeof(ACK4));
//                nextMove = 1;
//            }
//            else if(rxData == '2'){
//                HAL_UART_Transmit_IT(&huart2, ACK5, sizeof(ACK5));
//                nextMove = 2;
//            }
//            else if(rxData == '3'){
//                HAL_UART_Transmit_IT(&huart2, ACK6, sizeof(ACK6));
//                nextMove = 3;
//            }
//            else if(rxData == '4'){
//            	choosingFloor = false;
//            }
//            else{
//                // 에러 메시지(1~3 이외의 입력)
//                HAL_UART_Transmit_IT(&huart2, Warn2, sizeof(Warn2));
//            }
//            choosingFloor = false;  // 선택 종료
//        }
//        else {
//            // Continue
//            if (rxData == '1') {
//                HAL_UART_Transmit_IT(&huart2, ACK1, sizeof(ACK1));
//                restart = true;
//            }
//            // 가장 가까운 층으로 이동
//            else if (rxData == '2') {
//                HAL_UART_Transmit_IT(&huart2, ACK2, sizeof(ACK2));
//                executeRotation = true;
//                nextMove = 4; // 가장 가까운 층으로 이동
//            }
//            else if (rxData == '3') {
//                HAL_UART_Transmit_IT(&huart2, ACK3, sizeof(ACK3));
//                choosingFloor = true;  // 상태 변경: 층 선택 중
//            }
//            // 에러 메시지(1~3 이외의 입력)
//            else {
//                HAL_UART_Transmit_IT(&huart2, Warn1, sizeof(Warn1));
//            }
//        }
//
//        // 다시 UART 수신 인터럽트 활성화
//        HAL_UART_Receive_IT(&huart2, &rxData, sizeof(rxData));
//    }
//}
//
//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
//    if (huart->Instance == USART2 && executeRotation) {
//        executeRotation = false; // 플래그 초기화
//        switch(nextMove) {
//        	// 1층으로
//            case 1:
//                if(currentFloor == 1){
//                    rotateSteps(i_global, !direction_global);
//                }
//                else{
//                    infiniteRotation(DIR_CCW, 1);
//                }
//                forcedMove = true;
//                break;
//            // 2층으로
//            case 2:
//                if(currentFloor == 2){
//                    rotateSteps(i_global, !direction_global);
//                }
//                else{
//                    if(area == 1 || area == 2)
//                        infiniteRotation(DIR_CW, 2);
//                    else
//                        infiniteRotation(DIR_CCW, 2);
//                }
//                forcedMove = true;
//                break;
//            // 3층으로
//            case 3:
//                if(currentFloor == 3){
//                    rotateSteps(i_global, !direction_global);
//                }
//                else{
//                    infiniteRotation(DIR_CW, 3);
//                }
//                forcedMove = true;
//                break;
//            // 가장 가까운 층으로 이동
//            case 4:
//                switch(area){
//                    case 1:
//                        if(currentFloor == 1)
//                            rotateSteps(i_global, !direction_global);
//                        else
//                            infiniteRotation(DIR_CCW, 1);
//                        break;
//                    case 2:
//                        if(currentFloor == 2)
//                            rotateSteps(i_global, !direction_global);
//                        else
//                            infiniteRotation(DIR_CW, 2);
//                        break;
//                    case 3:
//                        if(currentFloor == 2)
//                            rotateSteps(i_global, !direction_global);
//                        else
//                            infiniteRotation(DIR_CCW, 2);
//                        break;
//                    case 4:
//                        if(currentFloor == 3)
//                            rotateSteps(i_global, !direction_global);
//                        else
//                            infiniteRotation(DIR_CW, 3);
//                        break;
//                }
//                forcedMove = true;
//                break;
//        }
//    }
//}
