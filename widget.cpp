#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QtCore>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    time=0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));


    ui->czasLabel->setText( QDateTime::fromMSecsSinceEpoch(time, Qt::UTC).toString("hh:mm:ss.zzz") );
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startButton_clicked()
{
    qDebug() << "start";
    timer->start(1);
}

void Widget::on_stopButton_clicked()
{
    qDebug() << "stop";
    timer->stop();
}

void Widget::onTimerTimeout()
{
    time++;

    ui->czasLabel->setText( QDateTime::fromMSecsSinceEpoch(time, Qt::UTC).toString("hh:mm:ss.zzz") );
}

void Widget::on_pomiarButton_clicked()
{
    ui->pomiaryTextEdit->setPlainText( QDateTime::fromMSecsSinceEpoch(time, Qt::UTC).toString("hh:mm:ss.zzz") +"\n"+ ui->pomiaryTextEdit->toPlainText());
}

void Widget::on_resetButton_clicked()
{
    time = 0;
    ui->czasLabel->setText( QDateTime::fromMSecsSinceEpoch(time, Qt::UTC).toString("hh:mm:ss.zzz") );
    ui->pomiaryTextEdit->clear();
}
