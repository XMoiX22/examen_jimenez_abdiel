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
    //metodos para extraer los campos de el dialogo
    int getNumero() const;
    QString getNombre() const;
    QDate getFecha() const;
    char getPrioridad() const;
    QString getTipo() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogTareas *ui;

};

#endif // DIALOGTAREAS_H
