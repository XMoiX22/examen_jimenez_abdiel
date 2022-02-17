#ifndef TAREAS_H
#define TAREAS_H

#include <QWidget>

namespace Ui {
class tareas;
}

class tareas : public QWidget
{
    Q_OBJECT

public:
    explicit tareas(QWidget *parent = nullptr);
    ~tareas();

private:
    Ui::tareas *ui;
};

#endif // TAREAS_H
