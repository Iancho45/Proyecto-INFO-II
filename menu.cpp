
#include "menu.h"
#include <iostream>

MENU::MENU(QWidget *parent) : QWidget(parent) {

    setGeometry(50,50,500,700);
    setFixedSize(500,700);
    setWindowTitle("Agenda de contactos");

    nom_DISTRIBUIDORA =new QLabel("DISTRIBUIDORA",this);
    QFont fuenteNom_DIS("Arial",14, QFont::Bold);
    nom_DISTRIBUIDORA->setFont(fuenteNom_DIS);
    nom_DISTRIBUIDORA ->setGeometry(15,25,190,20);

//NOMBRE
    nom_CLIENTE =new QLabel("Nombre:",this);
    QFont fuenteNom("Arial",10, QFont::Bold);
    nom_CLIENTE->setFont(fuenteNom);
    nom_CLIENTE ->setGeometry(15,70,55,20);

    nombre= new QLineEdit(this);
    nombre->setGeometry(80,70,120,20);


//TELEFONO
    num_TELEFONO = new QLabel("Telefono:",this);
    QFont fuenteTel("Arial",10, QFont::Bold);
    num_TELEFONO->setFont(fuenteTel);
    num_TELEFONO->setGeometry(15,100,120,20);

    telefono=new QLineEdit(this);
    telefono->setGeometry(80,100,120,20);



//RELACION DE CERCANIA
    rel_CERCANIA = new QLabel("Relacion de cercania:" ,this);
    QFont fuenteRel("Arial",10, QFont::Bold);
    rel_CERCANIA->setFont(fuenteRel);
    rel_CERCANIA->setGeometry(15,150,160,20);

    alta = new QRadioButton("Alta" , this);
    alta->setGeometry(15,190,60,20);

    media = new QRadioButton("Media" , this);
    media-> setGeometry(85,190,60,20);

    baja = new QRadioButton("Baja" , this);
    baja->setGeometry(155,190,60,20);


//ESTADO
    est_CLIENTE = new QLabel("Estado del Contacto", this);
    QFont fuenteEst("Arial",10, QFont::Bold);
    est_CLIENTE->setFont(fuenteEst);
    est_CLIENTE->setGeometry(15,250,160,20);

    estado = new QComboBox(this);
    estado->setGeometry(15,290,160,20);
    estado->addItem("Socio" , 1 );
    estado->addItem("Cliente", 2 );
    estado->addItem("No Interesado", 3 );
    estado->addItem("Visita Programada", 4 );

//CARACTERISTICA

    CARACTERISTICA = new QLabel("Caracteristicas del Contacto", this);
    QFont fuenteCar("Arial",10, QFont::Bold);
    CARACTERISTICA->setFont(fuenteCar);
    CARACTERISTICA->setGeometry(15,340,180,20);

    emprendedor = new QCheckBox("Emprendedor", this);
    emprendedor->setGeometry(15,370,180,20);

    influyente = new QCheckBox("Influyente" , this);
    influyente-> setGeometry(115,370,180,20);

    aprend_rap = new QCheckBox("Aprendizaje Rapido" , this);
    aprend_rap-> setGeometry(215,370,180,20);

    recursos = new QCheckBox ("Recursos" , this);
    recursos-> setGeometry(355,370,180,20);


//DESCRIPCION
    DESCRIPCION = new QLabel("Descripcion" , this);
    QFont fuenteDes("Arial",10, QFont::Bold);
    DESCRIPCION->setFont(fuenteDes);
    DESCRIPCION->setGeometry(280,60,80,20);

    descripcion = new QTextEdit(this);
    descripcion->setGeometry(280,80,200,100);


// BOTON AGREGAR

    agregar = new QPushButton ("Agregar Contacto" ,this);
    agregar->setGeometry(310,275,140,40);
    connect(agregar, SIGNAL(clicked()), this, SLOT(agregarContacto()));

    Contacto = new CONTACTOS();
    Contacto->show();
    Contacto->setMenu(this);

// SALIR DE LA APP
    salir =new QPushButton("Salir",this);
    salir ->setGeometry(180,630,140,40);
    connect(salir,SIGNAL(clicked()),this, SLOT(cerrarApp()));

// ORDENAR ALFABETICAMENTE
    ordenar_ALF = new QPushButton ("Ordenar Alfabeticamente", this);
    ordenar_ALF ->setGeometry(15,440,140,40);
    connect(ordenar_ALF,SIGNAL(clicked()),this, SLOT(ordenarNom()));

// ORDENAR RELACION DE CERCANIA
    ordenar_CER = new QPushButton ("Ordenar Cercania", this);
    ordenar_CER ->setGeometry(180,440,140,40);
    connect(ordenar_CER,SIGNAL(clicked()),this, SLOT(botonCercania()));

// ORDENAR ESTADO
    ordenar_EST = new QPushButton ("Ordenar Estado", this);
    ordenar_EST ->setGeometry(345,440,140,40);
    connect(ordenar_EST,SIGNAL(clicked()),this, SLOT(botonEstado()));

// ORDENAR CARACTERISTICA
    ordenar_CAR = new QPushButton ("Ordenar Caracteristica", this);
    ordenar_CAR ->setGeometry(180,510,140,40);
    connect(ordenar_CAR,SIGNAL(clicked()),this, SLOT(botonCaract()));


// LEO LOS CONTACTOS EN MEMORIA
    if((FP = fopen("BD", "rb"))== NULL ){
        QMessageBox msgBox;
        msgBox.setText("sin archivo");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();

    }
    else{
        fseek(FP , (long)sizeof(X), 2);
        cont_contactos = (ftell(FP)/sizeof(X))-1;
        rewind(FP);
        fread( &X , (long)sizeof(X) , 1 , FP );
        for(int i=0; i < cont_contactos  ;i++){
            Contacto->mostrarDatos(X);
            fread( &X , (long)sizeof(X) , 1 , FP );
        }
    }
    fclose(FP);

}


//RETORNO EL NOMBRE
QString MENU::getNom(){
    return nombre->text();
}

//RETORNO EL TELEFONO
QString MENU::getTel(){
    return telefono->text();
}
//RETORNA REL DE CERCANIA
QString MENU::getCer(){
    if(alta->isChecked()){
        return "Alta";
    }
    if(media->isChecked()){
        return "Media";
    }
    if(baja->isChecked()){
        return "Baja";
    }

}
//RETORNA EL ESTADO
QString MENU::getEst(){
    if(estado->itemData(estado->currentIndex()).toInt()==1){
        return "Socio";
    }
    if(estado->itemData(estado->currentIndex()).toInt()==2){
        return "Cliente";
    }
    if(estado->itemData(estado->currentIndex()).toInt()==3){
        return "No Interesado";
    }
    if(estado->itemData(estado->currentIndex()).toInt()==4){
        return "Visita Programada";
    }

}

//RETORNA CARACTERISTICA
QString MENU::getCaract(){
    QString mensaje = "" ;
    int cont = 0;

    if(emprendedor->isChecked()){
        mensaje.append(" *Emprendedor* ");
        cont++;
    }
    if(influyente->isChecked()){
        mensaje.append(" *Influyente* ");
        cont++;
    }
    if(aprend_rap->isChecked()){
        mensaje.append(" *Aprendizaje Rapido* ");
        cont++;
    }
    if(recursos->isChecked()){
        mensaje.append(" *Recursos* ");
        cont++;
    }
    if(!emprendedor->isChecked()&&!influyente->isChecked()&&!aprend_rap->isChecked()&&!recursos->isChecked()){
        mensaje.append(" *Ninguna* ");
    }

    X.cont_CAR = cont ;


    return mensaje;

}

//RETORNA UNA DESCRIPCION
QString MENU::getDesc(){

    return descripcion->toPlainText();
}

QString MENU::getEliminar(){
    QString mensaje = "" ;
    return mensaje;
}



//MANDO LOS DATOS A LA VENTANA 2
void MENU :: agregarContacto(){

    if(!alta->isChecked()&&!media->isChecked()&&!baja->isChecked()){
        QMessageBox msgBox;
        msgBox.setText("Debe elegir relacion de cercania");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }
    if(nombre->text().length()<3){
       QMessageBox msgBox;
        msgBox.setText("Debe completar con un nombre");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }
     if(telefono->text().length()<1){
       QMessageBox msgBox;
        msgBox.setText("Debe agregar un telefono");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }

    if((FP = fopen("BD", "ab"))== NULL ){
        QMessageBox msgBox;
        msgBox.setText("error de archivo");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }


    strcpy(X.NOM, ((getNom()).toStdString().c_str()));
    strcpy(X.TEL, ((getTel()).toStdString().c_str()));
    strcpy(X.CER, ((getCer()).toStdString().c_str()));
    strcpy(X.EST, ((getEst()).toStdString().c_str()));
    strcpy(X.CAR, ((getCaract()).toStdString().c_str()));
    strcpy(X.DES, ((getDesc()).toStdString().c_str()));

    fwrite( &X , (long)sizeof(X) , 1 , FP );
    fclose(FP);

    Contacto->mostrarDatos();


    limpiarVentana();

}

//CERRAR APP
void MENU :: cerrarApp(){
    QMessageBox msgBox;
    msgBox.setText("¿Seguro desea cerrar la app?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setIcon(QMessageBox::Question);
    int ret=msgBox.exec();

    if(ret==QMessageBox::Yes) qApp->quit();
}

// OCULTAR OPCIONES
void MENU :: ocultar(){

    Contacto->elegirOpcion->hide();

    Contacto->cercania->hide();
    Contacto->aceptar_cer->hide();

    Contacto->estado->hide();
    Contacto->aceptar_est->hide();
}

// LIMPIAR VENTANA
void MENU :: limpiarVentana(){

    nombre -> clear();
    telefono -> clear();
    descripcion -> clear();
    emprendedor->setChecked(false);
    influyente->setChecked(false);
    aprend_rap->setChecked(false);
    recursos->setChecked(false);
}

//ORDENAR ALFABETICAMENTE
void MENU :: ordenarNom(){
    Contacto -> eliminarDatos();
    ocultar();

    if((FP = fopen("BD", "r+b"))== NULL ){
        QMessageBox msgBox;
        msgBox.setText("sin archivo");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();

    }
    fseek(FP , (long)sizeof(X), 2);
    cont_contactos = (ftell(FP)/sizeof(X))-1;
    rewind(FP);

    for(i=0 ; i< cont_contactos-1 ; i++){
        fseek(FP , 0 , 0);
        for(j=0 ; j < cont_contactos -1-i ; j++){
            fseek(FP , (long)(-1)*sizeof(data1) , 1);
            fread(&data1 , sizeof(data1) , 1 , FP);
            fread(&data2 , sizeof(data2) , 1 , FP);
            if(( strcmp(data1.NOM , data2.NOM) > 0 ) ){
                fseek(FP , (long)(-2)*sizeof(data1) , 1);
                fwrite(&data2 , sizeof(data2) , 1 , FP);
                fwrite(&data1, sizeof(data1) , 1 , FP);
                }
        }
	}
	rewind(FP);
    fread( &X , (long)sizeof(X) , 1 , FP );
    for( i=0; i < cont_contactos  ;i++){
        Contacto->mostrarDatos(X);
        fread( &X , (long)sizeof(X) , 1 , FP );
    }
    fclose(FP);
}



void MENU :: botonCercania(){
    ocultar();

    Contacto->cercania->show();
    Contacto->elegirOpcion->show();
    Contacto->aceptar_cer->show();

}

void MENU :: botonEstado(){
    ocultar();

    Contacto->estado->show();
    Contacto->elegirOpcion->show();
    Contacto->aceptar_est->show();

}

void MENU :: botonCaract(){
    Contacto -> eliminarDatos();
    ocultar();

    if((FP = fopen("BD", "r+b"))== NULL ){
        QMessageBox msgBox;
        msgBox.setText("sin archivo");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();

    }
    fseek(FP , (long)sizeof(X), 2);
    cont_contactos = (ftell(FP)/sizeof(X))-1;
    rewind(FP);

    for(i=0 ; i< cont_contactos-1 ; i++){
        fseek(FP , 0 , 0);
        for(j=0 ; j < cont_contactos -1-i ; j++){
            fseek(FP , (long)(-1)*sizeof(data1) , 1);
            fread(&data1 , sizeof(data1) , 1 , FP);
            fread(&data2 , sizeof(data2) , 1 , FP);
            if( data2.cont_CAR > data1.cont_CAR ){
                fseek(FP , (long)(-2)*sizeof(data1) , 1);
                fwrite(&data2 , sizeof(data2) , 1 , FP);
                fwrite(&data1, sizeof(data1) , 1 , FP);
                }
        }
	}
	rewind(FP);
    fread( &X , (long)sizeof(X) , 1 , FP );
    for( i=0; i < cont_contactos  ;i++){
        if(X.cont_CAR != 0){
            Contacto->mostrarDatos(X);
        }
        fread( &X , (long)sizeof(X) , 1 , FP );
    }
    fclose(FP);


}


