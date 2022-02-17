#ifndef TAREA_H
#define TAREA_H

#include <QDate>
#include <QString>
class Tarea
{
private:
    //propiedades de las tareas(atributos de la clase)
    int numero;
    QString nombre;
    QDate fecha;
    char prioridad;
    QString tipo;
    bool finalizada;
public:
    Tarea();
    //lista de mtodos get y set para acceder a las propiedades de las tareas
    void setNumero(int numero);
    void setNombre(QString nombre);
    void setFecha(QDate fecha);
    void setPrioridad(char prioridad);
    void setTipo(QString tipo);
    void finalizarTarea();
    bool isTareaFinalizada();
    int getNumero();
    QString getNombre();
    QDate getFecha();
    char getPrioridad();
    QString getTipo();

};

#endif // TAREA_H
