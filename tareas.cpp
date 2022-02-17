#include "tareas.h"
#include "ui_tareas.h"

Tareas::Tareas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tareas)
{
    ui->setupUi(this);
    this->finalizada = false;
    setWindowTitle("NUEVA TAREA");
}

Tareas::~Tareas()
{
    delete ui;
}

void Tareas::setNumero(int numero){
    this->numero = numero;
}
void Tareas::setNombre(QString nombre){
    this->nombre = nombre;
}
void Tareas::setFecha(QDate fecha)
{
    this->fecha = fecha;
}
void Tareas::setPrioridad(char prioridad){
    this->prioridad = prioridad;
}
void Tareas::setTipo(QString tipo){
    this->tipo = tipo;
}
void Tareas::finalizarTarea(){
    this->finalizada = true;
}
bool Tareas::isTareaFinalizada(){
    return this->finalizada;
}
int Tareas::getNumero(){
    return this->numero;
}
QString Tareas::getNombre(){
    return this->nombre;
}
QDate Tareas::getFecha(){
    return this->fecha;
}
char Tareas::getPrioridad(){
    return this->prioridad;
}
QString Tareas::getTipo(){
    return this->tipo;
}

void Tareas::on_buttonBox_accepted()
{
    reject();
}

void Tareas::on_buttonBox_rejected()
{

}
