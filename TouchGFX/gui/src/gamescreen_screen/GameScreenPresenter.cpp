#include <gui/gamescreen_screen/GameScreenView.hpp>
#include <gui/gamescreen_screen/GameScreenPresenter.hpp>

extern "C" {
#include <stdio.h>
#include "stm32f4xx.h"
#include "main.h"

#define GAME_COUNT 7
//#include "stm32f429i_discovery.h"
}

GameScreenPresenter::GameScreenPresenter(GameScreenView& v)
    : view(v)
{

}

void GameScreenPresenter::activate()
{
	int* gameInfo = model->setUpGame(GAME_COUNT);
	for(int i = 0; i < GAME_COUNT; i++) {
		model->turnLedOn(gameInfo[i]);
		printf("%d ", gameInfo[i]);
		HAL_Delay(300);
	}
	printf("setUpGame on the presenter\n");
}

void GameScreenPresenter::deactivate()
{
	printf("gameScreenPresenter deactivate!\n");
	model->destroyGame();
}

void GameScreenPresenter::turnLedOn(int idx)
{
	model->turnLedOn(idx);

}

void GameScreenPresenter::saveUserAnswer(int idx)
{
	int cnt = model->saveAnswer(idx);
	if(cnt == GAME_COUNT)
	{
		bool isSolved = model->getCorrect();
		if(isSolved)
		{
			view.setCorrect();
		} else
		{
			view.setIncorrect();
		}
	}
}
