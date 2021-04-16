#ifndef SHOWACCOUNTS_H
#define SHOWACCOUNTS_H

#include <QDialog>

namespace Ui {
class showaccounts;
}

class showaccounts : public QDialog
{
    Q_OBJECT

public:
    explicit showaccounts(QWidget *parent = nullptr);
    ~showaccounts();

private:
    Ui::showaccounts *ui;

public slots:
    void showAllAccounts();
};

#endif // SHOWACCOUNTS_H
