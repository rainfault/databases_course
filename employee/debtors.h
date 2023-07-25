#ifndef DEBTORS_H
#define DEBTORS_H

#include <QWidget>
#include "debtorsjournal.h"
#include "base/subject.h"
#include "base/user.h"
#include <QPushButton>

namespace Ui {
class debtors;
}

class Debtors : public QWidget
{
    Q_OBJECT

public:
    void setDebtorTableParameters();
    void setCurrentUser(User user);

    void fillDebtorsGroupsTable(QSqlQuery debtors_query);
    void findContingent();
    explicit Debtors(QWidget *parent = nullptr);
    ~Debtors();

private:
    Ui::debtors *ui;
    User current_user_;

private slots:
    void handleDebtorsJournalRequest(int record_line);

signals:
    void debtorsJournalRequested(QString subject);

};

#endif // DEBTORS_H
