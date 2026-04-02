#pragma once

#include <QtGui>

#include "menu.h"

class MENU;

class CONTACTOS : public QWidget{

    Q_OBJECT

    private:

        QTableWidget *lista;
        QTableWidget *buscar;
        QString espacio;

        QLabel * nom_PERSONA ;
        QLineEdit *persona;

        int row;
        FILE *FP;
        MENU * Menu;

        int i, j ;

    public:
        CONTACTOS(QWidget * parent=0);
        void setMenu(MENU*);
        void mostrarDatos();
        void mostrarDatos(struct DATOS);
        void eliminarDatos();
        QLabel * elegirOpcion;

        QPushButton * aceptar_cer;
        QComboBox * cercania;

        QComboBox * estado;
        QPushButton * aceptar_est;



    public slots:
    void BuscarPersona();
    void OrdenarCer();
    void OrdenarEst();




};
