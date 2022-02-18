#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tarea.h"
#include "acercade.h"
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_finalizar_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_actionSalir_triggered();

    void on_actionAgregar_Tarea_triggered();

    void on_actionNueva_Lista_triggered();

    void on_actionAcerca_de_Organizador_triggered();

private:
    Ui::MainWindow *ui;
    QList<Tarea> listaTareas; //para almacenar la lista de tareas

    int fila_actual; //para guaardar la fila que se ha presionado
};

#endif // MAINWINDOW_H
