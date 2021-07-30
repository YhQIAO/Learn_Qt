#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWidget)
{
    ui->setupUi(this);

    void(QSpinBox::*spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal, ui->horizontalSlider, &QSlider::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

void smallWidget::setNum(int num){
    ui->spinBox->setValue(num);
}

int smallWidget::getNum(){
    return ui->spinBox->value();
}

smallWidget::~smallWidget()
{
    delete ui;
}
