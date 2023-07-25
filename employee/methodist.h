#ifndef METHODIST_H
#define METHODIST_H

#include <QWidget>
#include "subjectselection.h"
#include "groupselection.h"
#include "base/user.h"
#include "debtorsjournal.h"

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

private:
    Ui::Methodist *ui;
    SubjectSelection *subjects_window;
    GroupSelection *groups_window;

    User current_methodist_;
};

#endif // METHODIST_H
