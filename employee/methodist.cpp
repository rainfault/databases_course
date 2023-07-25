#include "methodist.h"
#include "ui_methodist.h"

Methodist::Methodist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Methodist)
{
    ui->setupUi(this);

}

Methodist::~Methodist()
{
    delete ui;
}

void Methodist::setCurrentUser(User user)
{
    current_methodist_ = user;
}
