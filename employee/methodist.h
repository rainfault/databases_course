#ifndef METHODIST_H
#define METHODIST_H

#include <QWidget>
// #include "groupselection.h"
#include "base/user.h"
// #include "debtorsjournal.h"
#include "subjectsmoderation.h"
//#include "groupselection.h"
#include "journal.h"
#include "teachersmoderation.h"

namespace Ui {
class Methodist;
}

/*
 *  Интерфейс методиста
 */

class Methodist : public QWidget
{
    Q_OBJECT

public:
    explicit Methodist(QWidget *parent = nullptr);
    ~Methodist();

    void setCurrentUser(const User user);
    void openTeachersModeration();
    void openSubjectsModeration();

public slots:
    void closeJournal();
    void setJournalSubject(Subject subject);
    void openJoural(QString group);

private:
    Ui::Methodist *ui;
    // SubjectSelection *subjects_window;
    // GroupSelection *groups_window;
    SubjectsModeration *subjects_window_;
    TeachersModeration *teachers_window_;
    Journal *journal_window_;

    void configureBoxesMenus();

    User current_methodist_;
};

#endif // METHODIST_H
