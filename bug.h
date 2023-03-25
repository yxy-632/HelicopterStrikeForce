#ifndef BUG_H
#define BUG_H

#include <QWidget>

namespace Ui {
class bug;
}

class bug : public QWidget
{
    Q_OBJECT

public:
    explicit bug(QWidget *parent = nullptr);
    ~bug();

private:
    Ui::bug *ui;
};

#endif // BUG_H
