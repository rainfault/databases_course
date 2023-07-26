#ifndef TEACHERSMODERATION_H
#define TEACHERSMODERATION_H

#include <QWidget>

namespace Ui {
class TeachersModeration;
}

class TeachersModeration : public QWidget
{
    Q_OBJECT

public:
    explicit TeachersModeration(QWidget *parent = nullptr);
    ~TeachersModeration();

private:
    Ui::TeachersModeration *ui;
};

#endif // TEACHERSMODERATION_H
