#include "scene.h"
#include <list>

Scene::Scene()
{
    setFormat(QGLFormat(QGL::DoubleBuffer)); // Двойная буферизация
    glDepthFunc(GL_LEQUAL);
}

Scene::Scene(Shape* item)
{
    setFormat(QGLFormat(QGL::DoubleBuffer)); // Двойная буферизация
    glDepthFunc(GL_LEQUAL);
    _items = new std::list<Shape*>();
    _items->push_back(item);
}
void Scene::append(Shape* item)
{
    if(_items == nullptr)
        _items = new std::list<Shape*>();
    _items->push_back(item);
}

void Scene::paintGL()
{
    glMatrixMode(GL_PROJECTION);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear buffer
    //glMatrixMode(GL_PROJECTION);
    //glOrtho(0, _window_weight, _window_height, 0, 1, 0);//x0, x1, y1, y0, hz, hz

    glLoadIdentity();
    //glTranslatef(1.0, 1.0, 1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glTranslatef(0.0,0.0,-10.0);
    glRotatef(45,1,0,0);
    glRotatef(10,0,1,0);
//    glRotatef(0,0,0,1);

    for(auto it : *_items)
        it->draw(*this);
    //glFlush();
    swapBuffers();
}

void Scene::resizeGL(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
}

void Scene::initializeGL()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(1.0, 1.0, 1.0);
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0, 0, 0, 0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glPopMatrix();
}
