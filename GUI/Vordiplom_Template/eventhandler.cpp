#include "eventhandler.h"
#include "mywidget.h"

eventhandler::eventhandler(MyWidget *parent) : parent(parent)
{
}

void eventhandler::OnButtonAddClicked(){
    parent->OnButtonAddClicked();
}

void eventhandler::OnButtonClearClicked(){
    parent->OnButtonClearClicked();
}

void eventhandler::OnButtonSortClicked(){
    parent->OnButtonSortClicked();
}
