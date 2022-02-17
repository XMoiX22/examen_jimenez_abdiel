#ifndef TAREAS_H
#define TAREAS_H

#include <QWidget>
#include <QDate>

namespace Ui {
class Tareas;
}

class Tareas : public QWidget
{
    Q_OBJECT

public:
    explicit Tareas(QWidget *parent = nullptr);
    ~Tareas();
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


private:
    Ui::Tareas *ui;
    //propiedades de las tareas(atributos de la clase)
    int numero;
    QString nombre;
    QDate fecha;
    char prioridad;
    QString tipo;
    bool finalizada;
};

#endif // TAREAS_H
