#ifndef INFOACCOUNT_H
#define INFOACCOUNT_H

#include <QDialog>

namespace Ui {
class infoAccount;
}

class infoAccount : public QDialog
{
    Q_OBJECT

public:
    explicit infoAccount(QWidget *parent = nullptr);
    ~infoAccount();

private:
    Ui::infoAccount *ui;
public slots:
    void btnSeachCpf();
};

#endif // INFOACCOUNT_H
