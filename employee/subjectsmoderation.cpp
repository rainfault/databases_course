#include "subjectsmoderation.h"
#include "ui_subjectsmoderation.h"

SubjectsModeration::SubjectsModeration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectsModeration)
{
    ui->setupUi(this);
}

SubjectsModeration::~SubjectsModeration()
{
    delete ui;
}
