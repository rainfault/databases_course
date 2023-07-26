#ifndef SUBJECTSMODERATION_H
#define SUBJECTSMODERATION_H

#include <QWidget>

namespace Ui {
class SubjectsModeration;
}

class SubjectsModeration : public QWidget
{
    Q_OBJECT

public:
    explicit SubjectsModeration(QWidget *parent = nullptr);
    ~SubjectsModeration();

private:
    Ui::SubjectsModeration *ui;
};

#endif // SUBJECTSMODERATION_H
