/*
 * stepper.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Stardust
 */

#include "stepper.h"

uint32_t i_global = 0;
uint8_t area = 1;
uint8_t direction = 0;

bool targetFloor1 = false;
bool targetFloor2 = false;
bool targetFloor3 = false;

bool direction_global = 0;

extern uint8_t currentFloor;

void stepMotor(uint8_t step){
	HAL_GPIO_WritePin(IN1_Port, IN1_Pin, HALF_STEP_SEQ[step][0]);
	HAL_GPIO_WritePin(IN2_Port, IN2_Pin, HALF_STEP_SEQ[step][1]);
	HAL_GPIO_WritePin(IN3_Port, IN3_Pin, HALF_STEP_SEQ[step][2]);
	HAL_GPIO_WritePin(IN4_Port, IN4_Pin, HALF_STEP_SEQ[step][3]);
}

void rotateSteps(uint16_t steps, bool direction){
	for(uint16_t i=0; i<steps; i++){
		uint8_t step;
		// 회전 방향에 맞춰서 스텝 패턴 설정
		if(direction == DIR_CW){
			step = i % 8;
		}
		else{
			step = 7 - (i % 8);
		}
		stepMotor(step);
		delay_us(STEP_DELAY_US);	// 각 스텝간의 지연
	}
}

void RotationUp(){
	uint32_t i = 0;
	uint8_t step;
	while(1){
		if (interruptFlag) {
			// 플래그가 설정되면 함수 실행 중단
			break;
		}
		i++;
		if(((currentFloor == 1) && (targetFloor2 || targetFloor3)) || ((currentFloor == 2) && targetFloor3)){
			direction = DIR_CW;
			step = i % 8;
		}
		else if(((currentFloor == 3) && (targetFloor2 || targetFloor1)) || ((currentFloor == 2) && targetFloor1)){
			direction = DIR_CCW;
			step = 7 - (i % 8);
		}
		else{
			direction = 0;
			break;
		}
		direction_global = direction;
		stepMotor(step);
		findCurrentState(direction, i);
		i_global = i % (UNIT_STEPS * 2);
		delay_us(STEP_DELAY_US);
	}
}

void RotationDown(){
	uint32_t i = 0;
	uint8_t step;
	while(1){
		if (interruptFlag) {
			// 플래그가 설정되면 함수 실행 중단
			break;
		}
		i++;
		if(((currentFloor == 3) && (targetFloor2 || targetFloor1)) || (((currentFloor == 2) && targetFloor1))){
			direction = DIR_CCW;
			step = 7 - (i % 8);
		}
		else{
			direction = 0;
			break;
		}
		direction_global = direction;
		stepMotor(step);
		findCurrentState(direction, i);
		i_global = i % (UNIT_STEPS * 2);
		delay_us(STEP_DELAY_US);
	}
}

void findCurrentState(uint8_t direction, uint32_t steps){
	uint8_t nextFloor;
	steps = steps % (UNIT_STEPS * 2);
	if(direction == DIR_CW){
		nextFloor = currentFloor + 1;
	}
	else if(direction == DIR_CCW){
		nextFloor = currentFloor - 1;
	}
	if(currentFloor == 1 && nextFloor == 2){
		if(steps < UNIT_STEPS)
			area = 1;
		else
			area = 2;
	}
	else if(currentFloor == 2 && nextFloor == 3){
		if(steps < UNIT_STEPS)
			area = 3;
		else
			area = 4;
	}
	else if(currentFloor == 3 && nextFloor == 2){
		if(steps < UNIT_STEPS)
			area = 4;
		else
			area = 3;
	}
	else if(currentFloor == 2 && nextFloor == 1){
		if(steps < UNIT_STEPS)
			area = 2;
		else
			area = 1;
	}
}
