#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void onTimerTimeout();

    void on_pomiarButton_clicked();

    void on_resetButton_clicked();

private:
    Ui::Widget *ui;
    QTimer *timer;
    qint64 time;
};
#endif // WIDGET_H
