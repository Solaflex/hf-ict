#include "eventhandler.h"
#include<QDebug>
#include<mywidget.h>

EventHandler::EventHandler(MyWidget *parent):parent(parent)
{

}

void EventHandler::onButtonClicked(){

    parent->DisplayTextbox();
}
