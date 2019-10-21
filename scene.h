#ifndef SCENE_H
#define SCENE_H

#include "shape.h"
#include <QGLWidget>
#include <list>


class Scene : public QGLWidget
{
private:
    std::list<Shape*> *_items = nullptr;
public:
    Scene();
    Scene(Shape* item);
    void append(Shape* item);
    void paintGL();
    void resizeGL(int w, int h);
    void initializeGL();
    ~Scene(){}
};

#endif // SCENE_H
