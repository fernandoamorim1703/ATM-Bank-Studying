#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(PressButton()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(slotMiddleButton()));
}

widget::~widget()
{
    delete ui;
}

void widget::PressButton();
{


}
