
#include "menu.h"
#include "contactos.h"

CONTACTOS::CONTACTOS(QWidget * parent) : QWidget(parent){


    setGeometry(500,50,1200,520);
    setFixedSize(1200,520);
    setWindowTitle("Lista de contactos");

    lista = new QTableWidget(100, 6, this);
    lista->setGeometry(0,0,1000,400);

    buscar = new QTableWidget (1, 6 , this);
    buscar ->setGeometry(15,440,900,70);

// BUSCAR PERSONA
    nom_PERSONA =new QLabel("Buscar Nombre:",this);
    QFont fuenteNom("Arial",10, QFont::Bold);
    nom_PERSONA->setFont(fuenteNom);
    nom_PERSONA ->setGeometry(15,410,100,20);

    persona= new QLineEdit(this);
    persona->setGeometry(150,410,120,20);
    connect(persona , SIGNAL(returnPressed()), this , SLOT(BuscarPersona()));

//  ELEGIR OPCION
    elegirOpcion = new QLabel("*Seleccione una Opcion*", this);
    QFont fuenteEst("Arial",10, QFont::Bold);
    elegirOpcion->setFont(fuenteEst);
    elegirOpcion->setGeometry(1015,10,160,20);
    elegirOpcion->hide();

//  BOTON ACEPTAR
    aceptar_cer = new QPushButton ("Aceptar" ,this);
    aceptar_cer->setGeometry(1100,40,60,20);
    connect(aceptar_cer, SIGNAL(clicked()), this, SLOT(OrdenarCer()));
    aceptar_cer->hide();

    aceptar_est = new QPushButton ("Aceptar" ,this);
    aceptar_est->setGeometry(1070,70,60,20);
    connect(aceptar_est, SIGNAL(clicked()), this, SLOT(OrdenarEst()));
    aceptar_est->hide();


//  CERCANIA
    cercania = new QComboBox(this);
    cercania->setGeometry(1020,40,60,20);
    cercania->addItem("Alta" , 1 );
    cercania->addItem("Media", 2 );
    cercania->addItem("Baja", 3 );
    cercania->hide();

// ESTADO
    estado = new QComboBox(this);
    estado->setGeometry(1020,40,160,20);
    estado->addItem("Socio" , 1 );
    estado->addItem("Cliente", 2 );
    estado->addItem("No Interesado", 3 );
    estado->addItem("Visita Programada", 4 );
    estado->hide();



    row=0;
    lista->verticalHeader()->hide();
    buscar->verticalHeader()->hide();


}

void CONTACTOS::setMenu(MENU* m){
    Menu = m;
}

void CONTACTOS::mostrarDatos(){

        QTableWidgetItem *nombre = new QTableWidgetItem(tr("%1").arg(Menu->getNom()));
        lista->setItem(row, 0, nombre);

        QTableWidgetItem *telefono = new QTableWidgetItem(tr("%1").arg(Menu->getTel()));
        lista->setItem(row, 1, telefono);

        QTableWidgetItem *cercania = new QTableWidgetItem(tr("%1").arg(Menu->getCer()));
        lista->setItem(row, 2, cercania);

        QTableWidgetItem *estado = new QTableWidgetItem(tr("%1").arg(Menu->getEst()));
        lista->setItem(row, 3, estado );

        QTableWidgetItem *caract = new QTableWidgetItem(tr("%1").arg(Menu->getCaract()));
        lista->setItem(row, 4, caract);

        QTableWidgetItem *desc = new QTableWidgetItem(tr("%1").arg(Menu->getDesc()));
        lista->setItem(row, 5, desc);


    row++;
}

void CONTACTOS::mostrarDatos(struct DATOS X){

        QTableWidgetItem *nombre = new QTableWidgetItem(tr("%1").arg(X.NOM));
        lista->setItem(row, 0, nombre);

        QTableWidgetItem *telefono = new QTableWidgetItem(tr("%1").arg(X.TEL));
        lista->setItem(row, 1, telefono);

        QTableWidgetItem *cercania = new QTableWidgetItem(tr("%1").arg(X.CER));
        lista->setItem(row, 2, cercania);

        QTableWidgetItem *estado = new QTableWidgetItem(tr("%1").arg(X.EST));
        lista->setItem(row, 3, estado );

        QTableWidgetItem *caract = new QTableWidgetItem(tr("%1").arg(X.CAR));
        lista->setItem(row, 4, caract);

        QTableWidgetItem *desc = new QTableWidgetItem(tr("%1").arg(X.DES));
        lista->setItem(row, 5, desc);


    row++;

}

void CONTACTOS :: eliminarDatos(){

    QString espacio = "";

    for(i=0 ; i < row ; i++){
        for(j=0 ; j < 6 ; j++){
            QTableWidgetItem *eliminar = new QTableWidgetItem(tr("%1").arg(espacio));
            lista->setItem( i , j , eliminar);
        }
    }

    row = 0 ;

}


void CONTACTOS :: BuscarPersona(){

        struct DATOS X;
        int cont_contactos;
        int flag = 0;

        if((FP = fopen("BD", "rb"))== NULL ){
        QMessageBox msgBox;
        msgBox.setText("sin archivo");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        }
        fseek(FP , (long)sizeof(X), 2);
        cont_contactos = (ftell(FP)/sizeof(X))-1;
        rewind(FP);

        fread( &X , (long)sizeof(X) , 1 , FP );
        for(i=0; i < cont_contactos  ;i++){
            if(strcmp( X.NOM , (persona->text()).toStdString().c_str() )== 0){

                QTableWidgetItem *nombre = new QTableWidgetItem(tr("%1").arg(X.NOM));
                buscar->setItem(0, 0, nombre);

                QTableWidgetItem *telefono = new QTableWidgetItem(tr("%1").arg(X.TEL));
                buscar->setItem(0, 1, telefono);

                QTableWidgetItem *cercania = new QTableWidgetItem(tr("%1").arg(X.CER));
                buscar->setItem(0, 2, cercania);

                QTableWidgetItem *estado = new QTableWidgetItem(tr("%1").arg(X.EST));
                buscar->setItem(0, 3, estado );

                QTableWidgetItem *caract = new QTableWidgetItem(tr("%1").arg(X.CAR));
                buscar->setItem(0, 4, caract);

                QTableWidgetItem *desc = new QTableWidgetItem(tr("%1").arg(X.DES));
                buscar->setItem(0, 5, desc);

                persona->clear();

                flag=1;
            }

            fread( &X , (long)sizeof(X) , 1 , FP );
        }
        if(flag == 0){
            QMessageBox msgBox;
            msgBox.setText("No se encuentra en la agenda");
            msgBox.setWindowTitle("Error");
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.exec();

            persona->clear();
        }

        fclose(FP);

}

void CONTACTOS :: OrdenarCer(){
    struct DATOS X;
    int cont_contactos;
     if((FP = fopen("BD", "rb"))== NULL ){
        QMessageBox msgBox;
        msgBox.setText("sin archivo");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }

    fseek(FP , (long)sizeof(X), 2);
    cont_contactos = (ftell(FP)/sizeof(X))-1;
    rewind(FP);

    eliminarDatos();
    row = 0;


    if(cercania->itemData(cercania->currentIndex()).toInt()==1){
        fread( &X , (long)sizeof(X) , 1 , FP );
        for(int i=0; i < cont_contactos  ;i++){
            if(strcmp(X.CER , "Alta")==0){
                mostrarDatos(X);
            }
            fread( &X , (long)sizeof(X) , 1 , FP );
        }

    }
    if(cercania->itemData(cercania->currentIndex()).toInt()==2){
        fread( &X , (long)sizeof(X) , 1 , FP );
        for(int i=0; i < cont_contactos  ;i++){
            if(strcmp(X.CER , "Media")==0){
                mostrarDatos(X);
            }
            fread( &X , (long)sizeof(X) , 1 , FP );
        }
    }
    if(cercania->itemData(cercania->currentIndex()).toInt()==3){
        fread( &X , (long)sizeof(X) , 1 , FP );
        for(int i=0; i < cont_contactos  ;i++){
            if(strcmp(X.CER , "Baja")==0){
                mostrarDatos(X);
            }
            fread( &X , (long)sizeof(X) , 1 , FP );
        }
    }

    fclose(FP);

}

void CONTACTOS :: OrdenarEst(){
    struct DATOS X;
    int cont_contactos;
     if((FP = fopen("BD", "rb"))== NULL ){
        QMessageBox msgBox;
        msgBox.setText("sin archivo");
        msgBox.setWindowTitle("Error");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }

    fseek(FP , (long)sizeof(X), 2);
    cont_contactos = (ftell(FP)/sizeof(X))-1;
    rewind(FP);

    eliminarDatos();
    row = 0;


    if(estado->itemData(estado->currentIndex()).toInt()==1){
        fread( &X , (long)sizeof(X) , 1 , FP );
        for(int i=0; i < cont_contactos  ;i++){
            if(strcmp(X.EST , "Socio")==0){
                mostrarDatos(X);
            }
            fread( &X , (long)sizeof(X) , 1 , FP );
        }
    }
    if(estado->itemData(estado->currentIndex()).toInt()==2){
        fread( &X , (long)sizeof(X) , 1 , FP );
        for(int i=0; i < cont_contactos  ;i++){
            if(strcmp(X.EST , "Cliente")==0){
                mostrarDatos(X);
            }
            fread( &X , (long)sizeof(X) , 1 , FP );
        }
    }
    if(estado->itemData(estado->currentIndex()).toInt()==3){
        fread( &X , (long)sizeof(X) , 1 , FP );
        for(int i=0; i < cont_contactos  ;i++){
            if(strcmp(X.EST , "No Interesado")==0){
                mostrarDatos(X);
            }
            fread( &X , (long)sizeof(X) , 1 , FP );
        }
    }

    if(estado->itemData(estado->currentIndex()).toInt()==4){
        fread( &X , (long)sizeof(X) , 1 , FP );
        for(int i=0; i < cont_contactos  ;i++){
            if(strcmp(X.EST , "Visita Programada")==0){
                mostrarDatos(X);
            }
            fread( &X , (long)sizeof(X) , 1 , FP );
        }
    }

    fclose(FP);

}


