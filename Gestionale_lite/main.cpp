
#include <QApplication>

#include "QDebug"
#include "Gestionale_lite/HeaderGrafica/welcome.h"



using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Welcome PP;

    PP.show();


    return a.exec();

}
