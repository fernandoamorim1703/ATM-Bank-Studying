#ifndef INTERFACEBANK_H
#define INTERFACEBANK_H

#include <QDialog>

namespace Ui {
class interfaceBank;
}

class interfaceBank : public QDialog
{
    Q_OBJECT

public:
    explicit interfaceBank(QWidget *parent = nullptr);
    ~interfaceBank();

private:
    Ui::interfaceBank *ui;

public:
    void apertarBotao();
};

#endif // INTERFACEBANK_H
