#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

namespace Ui {
class interface;
}

class interface : public QWidget
{
    Q_OBJECT

public:
    explicit interface(QWidget *parent = nullptr);
    ~interface();

private:
    Ui::interface *ui;
private slots:
    void inserir();
    void showAll();
};

#endif // INTERFACE_H
