#include <iostream>
#include <string>
#include <QApplication>
#include "MyStack.h"
#include "Person.h"
#include "PersonKeeper.h"
#include "mygui.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MyGUI* gui = new MyGUI();
    gui->show();
    return app.exec();
}
