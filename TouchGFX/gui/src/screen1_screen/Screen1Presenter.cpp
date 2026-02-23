#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

extern "C" {
#include <stdio.h>
#include "stm32f4xx.h"
#include "main.h"
//#include "stm32f429i_discovery.h"
}

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{
	printf("MainPresenter:activate\n");

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}
