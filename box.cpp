#include "box.h"

#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>

Box::Box()
{

}

//Box::Box(double size, int weight, int height, double positionX, double positionY, double positionZ)
//{
//    setFormat(QGLFormat(QGL::DoubleBuffer)); // Двойная буферизация
//    glDepthFunc(GL_LEQUAL);
//    init(size, weight, height, positionX, positionY, positionZ);
//}
//void Box::init(double size, int weight, int height, double positionX, double positionY,double positionZ)
//{
//    _side_size = size;
//    _window_weight = weight;
//    _window_height = height;
//    _dx = positionX;
//    _dy = positionY;
//    _dz = positionZ;
//}
//void Box::paintGL()
//{
//    glMatrixMode(GL_PROJECTION);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear buffer
//    //glMatrixMode(GL_PROJECTION);
//    //glOrtho(0, _window_weight, _window_height, 0, 1, 0);//x0, x1, y1, y0, hz, hz

//    glLoadIdentity();
//    //glTranslatef(0.0,0.0,-10.0);
//    glRotatef(_x_move,1,0,0);
//    glRotatef(_x_move,0,1,0);
//    glRotatef(0,0,0,1);

//    drawBox();
//    //glFlush();
//    swapBuffers();
//    _x_move += (float)0.25;
//    _y_move += (float)0.25;
//}
//void Box::resizeGL(int w, int h)
//{
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glViewport(0, 0, w, h);
//    _window_height = h;
//    _window_weight = w;
//}

//void Box::initializeGL()
//{
//    qglClearColor(Qt::black);
//    glEnable(GL_DEPTH_TEST);
////    glEnable(GL_CULL_FACE);
////    glShadeModel(GL_SMOOTH);
////    glEnable(GL_LIGHTING);
////    glEnable(GL_LIGHT0);

////    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
////    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
//}

void Box::drawSideX(double position, QGLWidget& item)
{
    item.qglColor(Qt::red);//r g b // 4f -  rgb + transparency
    //4 button that draw the box
    glVertex3d(position, _dy, _dz);
    glVertex3d(position, _dy, _dz - _side_size);
    glVertex3d(position, _dy + _side_size, _dz - _side_size);
    glVertex3d(position, _dy + _side_size, _dz);
}

void Box::drawSideY(double position, QGLWidget& item)
{
    item.qglColor(Qt::white);//r g b // 4f -  rgb + transparency
    //4 button that draw the box
    glVertex3d(_dx, position, _dz);
    glVertex3d(_dx, position, _dz - _side_size);
    glVertex3d(_dx + _side_size, position, _dz - _side_size);
    glVertex3d(_dx + _side_size, position, _dz);
}
void Box::drawSideZ(double position, QGLWidget& item)
{
    item.qglColor(Qt::green);//r g b // 4f -  rgb + transparency
    //4 button that draw the box
    glVertex3d(_dx, _dy, position);
    glVertex3d(_dx, _dy + _side_size, position);
    glVertex3d(_dx + _side_size, _dy + _side_size, position);
    glVertex3d(_dx + _side_size, _dy, position);
}

void Box::draw(QGLWidget& item)
{
    glBegin(GL_QUADS);
        drawSideZ(_dz - _side_size, item);
        drawSideX(_dx, item);
        drawSideX(_dx + _side_size, item);
        drawSideY(_dy + _side_size, item);
        drawSideY(_dy, item);
        drawSideZ(_dz, item);
    glEnd();
}
