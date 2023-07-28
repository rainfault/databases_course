#include "debtorsjournal.h"
#include "ui_debtorsjournal.h"
#include "tables_stuff/centeralignmentdelegate.h"
#include "tables_stuff/tabledelegate.h"

DebtorsJournal::DebtorsJournal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DebtorsJournal)
{
    ui->setupUi(this);
    setJournalTableParameters();

    connect(ui->go_back_button, &QPushButton::clicked, this, &DebtorsJournal::goBack);
}

DebtorsJournal::~DebtorsJournal()
{
    delete ui;
}

void DebtorsJournal::openSelectedSubject(QString subject)
{
    QSqlQuery debtors_query;

    if (current_user_.getAcessLevel() == User::AcessLevel::teacher)
        debtors_query.prepare("SELECT debtor_students.group_id, debtor_students.surname "
                              "FROM debtor_students LEFT OUTER JOIN field "
                              "ON debtor_students.debt_subject_id = field.field_id "
                              "WHERE field.field_name = :subject "
                              "AND field.professor_id = :id");
    else
        debtors_query.prepare("SELECT debtor_students.group_id, debtor_students.surname "
                              "FROM debtor_students LEFT OUTER JOIN field "
                              "ON debtor_students.debt_subject_id = field.field_id "
                              "WHERE field.field_name = :subject ");

    debtors_query.bindValue(":subject", subject);
    debtors_query.bindValue(":id", current_user_.getUserId());
    debtors_query.exec();

    fillDebtorsList(std::move(debtors_query));
}

void DebtorsJournal::fillDebtorsList(QSqlQuery query)
{
    ui->journal->clearContents();
    ui->journal->setRowCount(0);

    int rows = 0;

    while (query.next()) {
        QString group = query.value(0).toString();
        QString surname = query.value(1).toString();

        ui->journal->insertRow(rows);

        ui->journal->setItem(rows, 0, new QTableWidgetItem(group));
        ui->journal->setItem(rows, 1, new QTableWidgetItem(surname));
        ui->journal->setItem(rows, 2, new QTableWidgetItem("2"));

        ui->journal->setRowHeight(rows, 50);
    }
}

void DebtorsJournal::setCurrentUser(User user)
{
    this->current_user_ = user;
}

void DebtorsJournal::setJournalTableParameters()
{

    ui->journal->horizontalHeader()->setVisible(false);
    ui->journal->verticalHeader()->setVisible(false);

    ui->journal->setColumnCount(3);

    ui->journal->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->journal->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->journal->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);

    ui->journal->setShowGrid(false);

    // Делегаты для оцентровки:
    CenterAlignmentDelegate *center_delegate = new CenterAlignmentDelegate();
    ui->journal->setItemDelegateForColumn(0, center_delegate);
    ui->journal->setItemDelegateForColumn(1, center_delegate);

    // Установка делегата для покраски стобца:
    TableDelegate *delegate = new TableDelegate(this);
    ui->journal->setItemDelegateForColumn(2, delegate);
}
