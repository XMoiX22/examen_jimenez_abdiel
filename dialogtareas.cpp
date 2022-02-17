#include "dialogtareas.h"
#include "ui_dialogtareas.h"
#include <QDate>

DialogTareas::DialogTareas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTareas)
{
    ui->setupUi(this);

    this->finalizada = false;
    setWindowTitle("NUEVA TAREA");
}

DialogTareas::~DialogTareas()
{
    delete ui;
}
void DialogTareas::setNumero(int numero){
    this->numero = numero;
}
void DialogTareas::setNombre(QString nombre){
    this->nombre = nombre;
}
void DialogTareas::setFecha(QDate fecha)
{
    this->fecha = fecha;
}
void DialogTareas::setPrioridad(char prioridad){
    this->prioridad = prioridad;
}
void DialogTareas::setTipo(QString tipo){
    this->tipo = tipo;
}
void DialogTareas::finalizarTarea(){
    this->finalizada = true;
}
bool DialogTareas::isTareaFinalizada(){
    return this->finalizada;
}
int DialogTareas::getNumero(){
    return this->numero;
}
QString DialogTareas::getNombre(){
    return this->nombre;
}
QDate DialogTareas::getFecha(){
    return this->fecha;
}
char DialogTareas::getPrioridad(){
    return this->prioridad;
}
QString DialogTareas::getTipo(){
    return this->tipo;
}

void DialogTareas::on_buttonBox_accepted()
{
    reject();
}

void DialogTareas::on_buttonBox_rejected()
{
    accept();
}
