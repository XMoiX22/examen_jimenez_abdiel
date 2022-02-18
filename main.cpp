#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion"); //le damos un estilo a la ventana principal
    // Objeto para manejar las traducciones
        QTranslator traducion;
        // Solicitando al usuario que seleccione un idioma
        QStringList idiomas;
        idiomas << "Español" << "Inglés" << "Frances";
        QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                   "Idioma",
                                   "Seleccione un idioma",
                                   idiomas);
        // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
        if (idiomaSeleccionado == "Frances"){
            traducion.load(":/Tareas_fr_FR.qm");
        }else if (idiomaSeleccionado == "Inglés"){
            traducion.load(":/Tareas_en_IN.qm");
        }
        // Si es diferente de español, se instala la traducción en TODA la aplicación
        if (idiomaSeleccionado != "Español"){
            a.installTranslator(&traducion);
        }
        // Muestra la ventana principal
    MainWindow w;
    w.show();

    return a.exec();
}
