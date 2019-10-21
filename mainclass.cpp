#include "mainclass.h"
#include "ui_mainclass.h"

MainClass::MainClass(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainClass)
{
    ui->setupUi(this);
}

MainClass::~MainClass()
{
    delete ui;
}

