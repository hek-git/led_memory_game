#include <gui/gamescreen_screen/GameScreenView.hpp>
#include <stdio.h>

GameScreenView::GameScreenView()
{

}

void GameScreenView::setupScreen()
{
    GameScreenViewBase::setupScreen();
    image3.setVisible(false);
    image4.setVisible(false);
}

void GameScreenView::tearDownScreen()
{
    GameScreenViewBase::tearDownScreen();
}


void GameScreenView::onLed1Clicked()
{
//	printf("led 0 on!\n");
	presenter->turnLedOn(0);
	presenter->saveUserAnswer(0);
}

void GameScreenView::onLed2Clicked()
{
//	printf("led 1 on!\n");
	presenter->turnLedOn(1);
	presenter->saveUserAnswer(1);
}

void GameScreenView::onLed3Clicked()
{
	presenter->turnLedOn(2);
	presenter->saveUserAnswer(2);
}

void GameScreenView::setCorrect()
{
	image3.setVisible(true);
	image3.invalidate();
}

void GameScreenView::setIncorrect()
{
	image4.setVisible(true);
	image4.invalidate();
}
