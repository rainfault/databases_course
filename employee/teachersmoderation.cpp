#include "teachersmoderation.h"
#include "ui_teachersmoderation.h"

TeachersModeration::TeachersModeration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeachersModeration)
{
    ui->setupUi(this);
}

TeachersModeration::~TeachersModeration()
{
    delete ui;
}
