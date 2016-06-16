#include "AbstractFactory.h"
#include "yayButton.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    AbstractFactory* factory;
    string platform;

    do
    {
        cout << "Qt or Win32? ";
        cin >> platform;
    }
    while (platform != "Qt" && platform != "Win32");

    factory = AbstractFactory::getInstance(platform);

    yayButton *w = factory->createButton();
    w->draw();
    w->drawPressed();
    delete w;

    Window win1(*factory, "First Window", 1);
    Window win2(*factory, "Second Window", 2);
    win1.draw();
    win2.draw();
    return 0;
}