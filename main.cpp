
#include <QApplication>
#include <QFont>
#include <QPushButton>

#include "menu.h"
#include "contactos.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MENU *m = new MENU();

    m->show();


    return app.exec();
}
