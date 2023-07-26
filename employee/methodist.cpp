#include <QMenu>

#include "methodist.h"
#include "ui_methodist.h"

Methodist::Methodist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Methodist)
{
    ui->setupUi(this);

    subjects_window_ = new SubjectsModeration();

    ui->showing_selector_->setCurrentWidget(subjects_window_);
}

Methodist::~Methodist()
{
    delete ui;
}

void Methodist::setCurrentUser(User user)
{
    current_methodist_ = user;
}

void Methodist::configureBoxesMenus()
{
    QMenu* study_menu = new QMenu(this);
    QMenu* prepare_menu = new QMenu(this);

    study_menu->addAction("Текущие дисциплины", [this]() {
        ui->showing_selector_->setCurrentWidget(subjects_window_);
    });

}
