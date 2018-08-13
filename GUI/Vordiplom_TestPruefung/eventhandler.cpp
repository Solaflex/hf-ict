#include "eventhandler.h"
#include "mainwindow.h"

eventhandler::eventhandler(MainWindow *parent) : parent(parent)
{

}


void eventhandler::OnAddButtonClicked(){

    parent->OnAddButtonClicked();
}
