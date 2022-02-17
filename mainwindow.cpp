#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogtareas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LISTADO DE TAREAS PENDIENTES");
}

MainWindow::~MainWindow()
{
    delete ui;
}
//metodo para agregar una tarea
void MainWindow::on_agregar_clicked()
{
    //instanciamos una nueva tarea
    DialogTareas *tarea = new DialogTareas();
    tarea->setVisible(true);
}
