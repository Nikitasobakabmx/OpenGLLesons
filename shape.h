#ifndef SHAPE_H
#define SHAPE_H

#include <QGLWidget>

class Shape
{
public:
    virtual void draw(QGLWidget& item) = 0;
    virtual ~Shape(){}
};

#endif // SHAPE_H
