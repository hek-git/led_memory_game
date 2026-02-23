#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <random>
extern "C" {
#include <stdio.h>
#include "stm32f4xx.h"
#include "main.h"
//#include "stm32f429i_discovery.h"
}

Model::Model() : modelListener(0)
{
	userAnswerCnt = 0;
}

void Model::tick()
{

}

void Model::turnLedOn(int idx)
{
	if(idx == 0)
	{
		HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_Pin, GPIO_PIN_SET);
		HAL_Delay(250);
		HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_Pin, GPIO_PIN_RESET);
	} else if(idx == 1)
	{
		HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_Pin, GPIO_PIN_SET);
		HAL_Delay(250);
		HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_Pin, GPIO_PIN_RESET);
	} else
	{
		HAL_GPIO_WritePin(LED3_GPIO_PORT, LED3_Pin, GPIO_PIN_SET);
		HAL_Delay(250);
		HAL_GPIO_WritePin(LED3_GPIO_PORT, LED3_Pin, GPIO_PIN_RESET);
	}
}

int* Model::setUpGame(int count)
{
	std::mt19937 gen(HAL_GetTick());             // Mersenne Twister 엔진
	std::uniform_int_distribution<> dist(0, 2);  // 0~2 균등 분포

	problemCnt = count;
	for(int i = 0; i < problemCnt; i++) {
		problem[i] = dist(gen);
	}
	return problem;
}

int Model::saveAnswer(int idx) {
	userAnswer[userAnswerCnt++] = idx;
	if(problemCnt == userAnswerCnt) {
		if(isCorrect()) isSolved = true;
		else isSolved = false;
	}
	return userAnswerCnt;
}

bool Model::isCorrect()
{
	for(int i = 0; i < problemCnt; i++) {
		int a = problem[i];
		int b = userAnswer[i];
		if(a != b) return false;
	}
	return true;
}

bool Model::getCorrect()
{
	return isSolved;
}

void Model::destroyGame()
{
	printf("game destroyed\n");
	for(int i = 0; i < countMax; i++) {
		problem[i] = 0;
		userAnswer[i] = 0;
	}
	problemCnt = 0;
	userAnswerCnt = 0;
}
