#include "eventhandler.h"
#include<QDebug>
#include<widget.h>

EventHandler::EventHandler(Widget *parent):parent(parent)
{

}

void EventHandler::onButtonClicked(){

    parent->PaintPoints();
}

void EventHandler::onResetButtonClicked(){
    parent->ResetPoints();
}
