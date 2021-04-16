#ifndef OPENACCOUNT_H
#define OPENACCOUNT_H

#include <QDialog>

namespace Ui {
class openAccount;
}

class openAccount : public QDialog
{
    Q_OBJECT

public:
    explicit openAccount(QWidget *parent = nullptr);
    ~openAccount();

private:
    Ui::openAccount *ui;

private slots:
    void btnCreateAccount();
};

#endif // OPENACCOUNT_H
