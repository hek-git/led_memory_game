#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

extern "C" {
#include <stdio.h>
#include "stm32f4xx.h"
#include "main.h"
//#include "stm32f429i_discovery.h"
}

MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
    : view(v)
{

}

void MainScreenPresenter::activate()
{
}

void MainScreenPresenter::deactivate()
{
}
