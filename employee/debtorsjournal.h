#ifndef DEBTORSJOURNAL_H
#define DEBTORSJOURNAL_H

#include <QWidget>
#include <QSqlQuery>

#include "base/user.h"


namespace Ui {
class DebtorsJournal;
}

class DebtorsJournal : public QWidget
{
    Q_OBJECT

public:
    explicit DebtorsJournal(QWidget *parent = nullptr);
    ~DebtorsJournal();

    void openSelectedSubject(QString subject);
    void fillDebtorsList(QSqlQuery query);
    void setCurrentUser(User user);
    void setJournalTableParameters();

private:
    Ui::DebtorsJournal *ui;
    User current_user_;

signals:
    void goBack();
};

#endif // DEBTORSJOURNAL_H
