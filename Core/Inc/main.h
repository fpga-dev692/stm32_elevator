/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define FND0_Pin GPIO_PIN_5
#define FND0_GPIO_Port GPIOA
#define FND1_Pin GPIO_PIN_6
#define FND1_GPIO_Port GPIOA
#define FND2_Pin GPIO_PIN_7
#define FND2_GPIO_Port GPIOA
#define Emergency_Pin GPIO_PIN_4
#define Emergency_GPIO_Port GPIOC
#define Emergency_EXTI_IRQn EXTI4_IRQn
#define Stepper3_Pin GPIO_PIN_5
#define Stepper3_GPIO_Port GPIOC
#define Stepper2_Pin GPIO_PIN_6
#define Stepper2_GPIO_Port GPIOC
#define FND4_Pin GPIO_PIN_7
#define FND4_GPIO_Port GPIOC
#define Stepper1_Pin GPIO_PIN_8
#define Stepper1_GPIO_Port GPIOC
#define Stepper0_Pin GPIO_PIN_9
#define Stepper0_GPIO_Port GPIOC
#define FND6_Pin GPIO_PIN_8
#define FND6_GPIO_Port GPIOA
#define FND5_Pin GPIO_PIN_9
#define FND5_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define FND3_Pin GPIO_PIN_6
#define FND3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
