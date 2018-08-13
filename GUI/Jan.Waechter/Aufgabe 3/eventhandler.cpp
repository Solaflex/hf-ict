#include "eventhandler.h"
#include "mywidget.h"

eventhandler::eventhandler(MyWidget *parent) : parent(parent)
{
    this->parent = parent;
}

void eventhandler::generatePasswordEvent(){
    parent->generatePassword();
}

