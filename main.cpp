#include "mainclass.h"
#include "box.h"
#include "scene.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Box* box = new Box(0, -0.5, -0.25, 0.5);
    Scene* scene = new Scene(box);
    scene->show();
    return app.exec();
}
