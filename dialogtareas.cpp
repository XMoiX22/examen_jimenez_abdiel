#include "dialogtareas.h"
#include "ui_dialogtareas.h"
#include <QDate>

DialogTareas::DialogTareas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTareas)
{
    ui->setupUi(this);
    setWindowTitle(tr("NUEVA TAREA"));

    //ahora agregamos las prioridades al combo box
    ui->prioridad->addItem(tr("Alta"));
    ui->prioridad->addItem(tr("Media"));
    ui->prioridad->addItem(tr("Baja"));
}

DialogTareas::~DialogTareas()
{
    delete ui;
}
//metodos que extraen la informacion suministrada en el dialogo
int DialogTareas::getNumero() const{

    return ui->numero->text().toInt();
}
QString DialogTareas::getNombre() const{
    return ui->nombre->text();
}
QDate DialogTareas::getFecha() const{
    return ui->fecha->date();
}
char DialogTareas::getPrioridad() const{
    QString priorid = ui->prioridad->currentText(); //extraemos el texto de el lineEdit
    QByteArray array_char = priorid.toLocal8Bit(); //cnvertimos el texto en un array de byts
    const char *chars = array_char.data(); //convertimos los byts en caracteres
    return chars[0]; //retornamos el primer caracter
}
QString DialogTareas::getTipo() const{
    return ui->tipo->text();
}
//metodo para informar que salimos meidante accept para guardar la tarea
void DialogTareas::on_buttonBox_accepted()
{
    accept();
}
//informamos que slaimos mediante reject, es decir cancelar el ingreso de una nueva tarea
void DialogTareas::on_buttonBox_rejected()
{
    reject();
}
