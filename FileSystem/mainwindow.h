#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <filesystem.h>
#include <Folder.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_salir_clicked();
    void on_agregar_clicked();


    void on_eliminar_clicked();

private:
    Ui::MainWindow *ui;
    filesystem *fs = new filesystem();
    QPushButton *Agregar;
    QPushButton *Eliminar;
    QPushButton *Folder;
    QPushButton *Texto;
    //void listarElementos();
    string refrescar();
    int cant_folder=0;
    int cant_texto=0;
    int Posx =20;
    int Posy = 50;
};

#endif // MAINWINDOW_H
