#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QString>
#include <QStatusBar>
#include <filesystem.h>
#include <QMessageBox>
#include <Folder.h>
#include <archivo.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_salir_clicked(){
    close();
}

/*

Folder MainWindow::listarElementos(){
    return fs->listarElementos(fs->raiz);

}

string MainWindow::refrescar(){
    if(listarElementos()==Folder){
       return QMessageBox::setInformativeText("ENCONTRAMOS FOLDERS");
    }
    if(listarElementos()==Archivo){
        return QMessageBox::setInformativeText("ENCONTRAMOS ARCHIVOS");
    }
}
*/

void MainWindow::on_agregar_clicked(){

    int respuesta;
    QString nombre;
    respuesta = QInputDialog::getInt(this,"Agregar Elemento","Que desea agregar? Folder(1) o Archivo de Texto(2)");

    if(respuesta==1){
        nombre = QInputDialog::getText(this,"Agregar Folder","Ingrese el nombre del Folder");
        fs->agregarElemento(fs->raiz,nombre.toStdString(),1);
        Agregar = new QPushButton("agregar",this);
        connect(Agregar, SIGNAL (clicked()), this, SLOT (on_agregar_clicked()));
        Folder = new QPushButton("",this);
        Folder->setGeometry(QRect(QPoint(Posx,Posy),QSize(100,50)));
        Folder->setIcon(QIcon("C:/Users/Samuel Borjas/Documents/C++ Projects/FileExplorerQT/folder.png"));
        Folder->setText(nombre);
        Folder->setIconSize(QSize(30,30));
        Folder->resize(80,80);
        Folder->setVisible(true);
        if(Posx>480){
            Posy +=80;
            Posx = 20;
        }else{
            Posx += 80;
        }
        //cant_folder+=1;

        //refrescar();
    }else if(respuesta==2){
        nombre = QInputDialog::getText(this,"Agregar Archivo","Ingrese el nombre del Archivo");
        fs->agregarElemento(fs->raiz,nombre.toStdString(),2);
        Agregar = new QPushButton("agregar",this);
        connect(Agregar, SIGNAL (clicked()), this, SLOT (on_agregar_clicked()));
        Texto = new QPushButton("",this);
        Texto->setGeometry(QRect(QPoint(Posx,Posy),QSize(100,50)));
        Texto->setIcon(QIcon("C:/Users/Samuel Borjas/Documents/C++ Projects/FileExplorerQT/texto.png"));
        Texto->setText(nombre);
        Texto->setIconSize(QSize(30,30));
        Texto->resize(80,80);
        Texto->setVisible(true);
        if(Posx>480){
            Posy +=80;
            Posx = 20;
        }else{
            Posx += 80;
        }
        //cant_texto+=1;

    }

}


void MainWindow::on_eliminar_clicked(){
    /*
    int respuesta;
    QString nombre;

    respuesta = QInputDialog::getInt(this,"Eliminar Elemento","Que elemento desea eliminar? Folder(1) o Archivo de Texto(2)");
    if(respuesta==1){
        nombre = QInputDialog::getText(this,"Eliminar Folder","Ingrese el nombre del Folder que desea eliminar");
        for(int x=0;x<cant_folder;x++){
            if(Folder->text()==nombre){
                Folder->setText("Eliminado");
                //Folder->setVisible(false);
            }
        }


    }
    if(respuesta==2){

    }
    */
}

