#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogtareas.h"
#include "Tarea.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LISTADO DE TAREAS PENDIENTES"); //indicamos el nombre de la ventana

    ui->tableWidget->setColumnCount(4); //le damos el numero de columna a la tabla
    //ahora creamos una lista con los nombres de las columnas
    QStringList labels;
    labels << "Numero" << "Nombre" << "Tipo" << "Fecha";
    ui->tableWidget->setHorizontalHeaderLabels(labels);

    //inicializamos la fila seleccionada en -1
    this->fila_actual = -1; //porque aun no se ha presionado

    //vaciamos el archivo de tareas existente
    QFile imc("Tareas.txt"); //variable de tipo File para generar un archivo
    imc.open(QIODevice::WriteOnly | QIODevice::Text); //abrimos el archivo para escritura reemplazando el existente

    imc.close();

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
    int opcion = tarea->exec(); //ejecutamos la ventana

    if( opcion == QDialog::Rejected){ //verificamos si se cancelo la introduccion de una nueva tarea
        return;
    }else{ //se dio en agregar la tarea

        //verificamos que los campos conetngan texto
        if( tarea->getTipo().size() > 0 && tarea->getNumero() > 0 && tarea->getNombre().size() > 0){
            Tarea *new_tarea = new Tarea(); //creamos una nueva tarea

            //extraemos la informacion de los campos de la nueva tarea y la almacenamos en la nueva tarea
            new_tarea->setNumero(tarea->getNumero());
            new_tarea->setNombre(tarea->getNombre());
            new_tarea->setTipo(tarea->getTipo());
            new_tarea->setFecha(tarea->getFecha());
            new_tarea->setPrioridad(tarea->getPrioridad());

            ui->tableWidget->insertRow(ui->tableWidget->rowCount()); //agregamos una fila al final
            //ahora agregamos los datos de la fila agregada
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0, new QTableWidgetItem(QString::number(new_tarea->getNumero())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1, new QTableWidgetItem(new_tarea->getNombre()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2, new QTableWidgetItem(new_tarea->getTipo()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3, new QTableWidgetItem(new_tarea->getFecha().toString()));

            //ahora verificamos la prioridad para cambiar el color del texto
            if( new_tarea->getPrioridad() == 'A'){
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->setTextColor(Qt::red);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,1)->setTextColor(Qt::red);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,2)->setTextColor(Qt::red);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,3)->setTextColor(Qt::red);
            }else if( new_tarea->getPrioridad() == 'M'){
                QColor c("orange"); //para acceder a la lista de colores como el naranja
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->setTextColor(c);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,1)->setTextColor(c);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,2)->setTextColor(c);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,3)->setTextColor(c);
            }else{
                QColor c("yellow"); //para acceder a la lista de colores como el naranja
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->setTextColor(c);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,1)->setTextColor(c);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,2)->setTextColor(c);
                ui->tableWidget->item(ui->tableWidget->rowCount()-1,3)->setTextColor(c);
            }

            //ahora agregamos la nueva tarea en el archivo
            QFile imc("Tareas.txt"); //variable de tipo File para generar un archivo
            imc.open(QIODevice::ReadWrite | QIODevice::Text); //abrimos el archivo para escritura

            QTextStream stream(&imc);
            stream.seek(imc.size());

            //agregamos
            stream << new_tarea->getNumero() << " - " << new_tarea->getNombre() << " - " << new_tarea->getTipo() << " - " << new_tarea->getPrioridad() << " - "  << new_tarea->getFecha().toString() << " - " << new_tarea->isTareaFinalizada() << "\n";

            imc.close();

            //por ultimo almacenamos la tarea en la lista de tareas locales
            this->listaTareas.append(*new_tarea);
        }else{
            QMessageBox::information(this,"Eroor","Complete todos los campos"); //indicamos que debe completar todos los campos
        }

    }
}

void MainWindow::on_finalizar_clicked()
{
    if(this->fila_actual == -1){
        QMessageBox::information(this,"Eroor","Seleccione una fila a eliminar"); //damos una alerta de que debe seleccionar una fila
    }else{
        ui->tableWidget->removeRow(this->fila_actual);

        //ahora actualizamos la tarea a finalizada

        //buscamos el valor de la fila eliminada
        //recorremos la lista para ir ocntando las tareas ya finalizadas
        int cont = -1; //contador para identificar la tarea que ha sido finalizada
        for(int i = 0; i < this->listaTareas.size(); i++){
            if( !this->listaTareas[i].isTareaFinalizada()){
                cont++;
            }

            if( cont == this->fila_actual){
                cont = i;
                break; //cerramos el for porque se ha encontrado la tarea eliminada
            }
        }
        this->listaTareas[cont].finalizarTarea();
        // ahora guardamos en el archivo las tareas con las modificaciones

        QFile imc("Tareas.txt"); //variable de tipo File para generar un archivo
        imc.open(QIODevice::WriteOnly | QIODevice::Text); //abrimos el archivo para escritura reemplazando el existente

        QTextStream stream(&imc);
        stream.seek(imc.size());

        //recorremos la lista de tareas
        for(int i = 0; i < this->listaTareas.size(); i++){
            stream << this->listaTareas[i].getNumero() << " - " << this->listaTareas[i].getNombre() << " - " << this->listaTareas[i].getTipo() << " - " << this->listaTareas[i].getPrioridad() << " - "  << this->listaTareas[i].getFecha().toString() << " - " << this->listaTareas[i].isTareaFinalizada() << "\n";
        }
        imc.close(); //cerramos el archivo

        this->fila_actual = -1; //ponemos en -1 para quitar la seleccion, lo que para eliminar otro elemento debe presionarlo

    }
}
//metodo para obtener la fila que el usuario selecciona para posterios eliminarla
void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    this->fila_actual = item->row(); //guardamos la fila que se ha seleccionado
}
