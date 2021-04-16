#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include"openaccount.h"
#include "showaccounts.h"

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
    openAccount *ca;
    showaccounts *sa;

public slots:
    void btnMainCreatAccount();
    void btnShowAllAccounts();
};

#endif // INTERFACE_H
