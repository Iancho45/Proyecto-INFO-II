
#pragma once

#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QComboBox>
#include <QCheckBox>
#include <QTextEdit>

#include "contactos.h"

struct DATOS{

    char NOM[20];
    char TEL[20];
    char CER[7];
    char EST[20];
    char CAR[70];
    int  cont_CAR;
    char DES[100];

};


class CONTACTOS;

class MENU : public QWidget{

    Q_OBJECT

    private:
        QPushButton *agregar;
        QPushButton * salir;
        QPushButton *ordenar_ALF;
        QPushButton *ordenar_CER;
        QPushButton *ordenar_EST;
        QPushButton *ordenar_CAR;


        QLabel * titulo;
        QLabel * nom_DISTRIBUIDORA;

        QLabel * nom_CLIENTE ;
        QLineEdit *nombre;

        QLabel * num_TELEFONO;
        QLineEdit *telefono;

        QLabel * rel_CERCANIA;
        QRadioButton * alta;
        QRadioButton * media;
        QRadioButton * baja;

        QLabel * est_CLIENTE;
        QComboBox * estado;

        QLabel * CARACTERISTICA;
        QCheckBox * emprendedor;
        QCheckBox * influyente;
        QCheckBox * aprend_rap;
        QCheckBox * recursos;

        QLabel * DESCRIPCION;
        QTextEdit * descripcion;

        CONTACTOS * Contacto;
        QTableWidget *tableWidget1;
        QTableWidget *tableWidget2;


        FILE *FP;
        struct DATOS X;
        struct DATOS data1, data2;
        int cont_contactos, i, j;


    public:
        MENU(QWidget *parent=0);
        QString getNom();
        QString getTel();
        QString getCer();
        QString getEst();
        QString getCaract();
        QString getDesc();
        QString getEliminar();
        void limpiarVentana();
        void ocultar();


    public slots:
        void agregarContacto();
        void cerrarApp();
        void ordenarNom();
        void botonCercania();
        void botonEstado();
        void botonCaract();


};
