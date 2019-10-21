#ifndef BOX_H
#define BOX_H
#include <QGLWidget>
#include "shape.h"


class Box:public Shape
{
private:
    double _side_size = 0;
    double _dx, _dy, _dz;
public:
    Box();
    Box(double posX, double posY, double posZ, double size):_side_size(size), _dx(posX), _dy(posY), _dz(posZ){}
    void drawSideX(double position, QGLWidget& item);
    void drawSideY(double position, QGLWidget& item);
    void drawSideZ(double position, QGLWidget& item);
    void draw(QGLWidget& item);
    ~Box(){}
};

#endif // BOX_H
