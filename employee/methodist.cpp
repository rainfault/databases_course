#include <QMenu>

#include "methodist.h"
#include "ui_methodist.h"

Methodist::Methodist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Methodist)
{
    ui->setupUi(this);

    subjects_window_ = new SubjectsModeration();
    teachers_window_ = new TeachersModeration();
    journal_window_ = new Journal();

    ui->showing_selector_->addWidget(subjects_window_);
    ui->showing_selector_->addWidget(teachers_window_);
    ui->showing_selector_->addWidget(journal_window_);

    ui->showing_selector_->setCurrentWidget(subjects_window_);

    // connects:
    connect(journal_window_, &Journal::goBack, this, &Methodist::closeJournal);
    connect(subjects_window_, &SubjectsModeration::journalRequested, this, &Methodist::openJoural);
    connect(subjects_window_, &SubjectsModeration::subjectSelected, this, &Methodist::setJournalSubject);


    configureBoxesMenus();

    subjects_window_->fillUIOptions();
}

Methodist::~Methodist()
{
    delete ui;
}

void Methodist::setCurrentUser(User user)
{
    current_methodist_ = user;
}

void Methodist::closeJournal()
{
    ui->showing_selector_->setCurrentWidget(subjects_window_);
}

void Methodist::setJournalSubject(Subject subject)
{
    journal_window_->setCurrentSubject(subject);
}

void Methodist::openJoural(QString group)
{
    ui->showing_selector_->setCurrentWidget(journal_window_);
    journal_window_->openGroup(group);
}

void Methodist::configureBoxesMenus()
{
    QMenu* study_menu = new QMenu(this);
    QMenu* prepare_menu = new QMenu(this);

    study_menu->addAction("Текущие дисциплины", [this]() {
        ui->showing_selector_->setCurrentWidget(subjects_window_);
    });

    prepare_menu->addAction("Назначить преподавателя", [this] {
        ui->showing_selector_->setCurrentWidget(teachers_window_);
    });

    for (auto &menu: {study_menu, prepare_menu})
    menu->setStyleSheet("QMenu {"
                        "   background: none repeat scroll 0 0 #008cba;"
                        "   color: white;"
                        "   border: 0 none;"
                        "};");

    ui->study_button->setMenu(study_menu);
    ui->prepare_button->setMenu(prepare_menu);
}
