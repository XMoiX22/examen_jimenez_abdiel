#ifndef DIALOGTAREAS_H
#define DIALOGTAREAS_H

#include <QDialog>
#include <QDate>

namespace Ui {
class DialogTareas;
}

class DialogTareas : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTareas(QWidget *parent = nullptr);
    ~DialogTareas();
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

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogTareas *ui;
    //propiedades de las tareas(atributos de la clase)
    int numero;
    QString nombre;
    QDate fecha;
    char prioridad;
    QString tipo;
    bool finalizada;
};

#endif // DIALOGTAREAS_H
