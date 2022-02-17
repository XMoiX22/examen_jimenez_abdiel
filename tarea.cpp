#include "tarea.h"

Tarea::Tarea()
{
    this->finalizada = false;
}

void Tarea::setNumero(int numero){
    this->numero = numero;
}
void Tarea::setNombre(QString nombre){
    this->nombre = nombre;
}
void Tarea::setFecha(QDate fecha)
{
    this->fecha = fecha;
}
void Tarea::setPrioridad(char prioridad){
    this->prioridad = prioridad;
}
void Tarea::setTipo(QString tipo){
    this->tipo = tipo;
}
void Tarea::finalizarTarea(){
    this->finalizada = true;
}
bool Tarea::isTareaFinalizada(){
    return this->finalizada;
}
int Tarea::getNumero(){
    return this->numero;
}
QString Tarea::getNombre(){
    return this->nombre;
}
QDate Tarea::getFecha(){
    return this->fecha;
}
char Tarea::getPrioridad(){
    return this->prioridad;
}
QString Tarea::getTipo(){
    return this->tipo;
}
