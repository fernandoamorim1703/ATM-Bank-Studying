#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include "openaccount.h"
#include "showaccounts.h"
#include "infoaccount.h"

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
    infoAccount *ia;

public slots:
    void btnMainCreatAccount();
    void btnShowAllAccounts();
    void btnSeeAccount();
};

#endif // INTERFACE_H
