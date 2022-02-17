#include "tareas.h"
#include "ui_tareas.h"

tareas::tareas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tareas)
{
    ui->setupUi(this);
}

tareas::~tareas()
{
    delete ui;
}
