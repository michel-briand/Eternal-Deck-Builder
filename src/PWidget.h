#ifndef PWIDGET_H
#define PWIDGET_H

#include <QFrame>
#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QPushButton>

///////////////////////////////////////////////////////////////////////////////////////////
// Ma Subclass de QFrame

class PFrame : public QFrame
{
   //Q_OBJECT

public:
    explicit PFrame(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void startDrag();
    QPixmap *BloodPxm;
    QPoint startPos;
};

class DisciplineButton : public QAbstractButton
{
public:
    explicit DisciplineButton(QWidget *parent = 0);
    void setupDiscipline(QString dis);
    QString get_sql_request();

protected:
    void paintEvent(QPaintEvent *e);
    void nextCheckState();

private:
    int state;
    enum state_list{ a, b, c };
    QString discipline;
    QPixmap icone;
    QString sql_request;
};

#endif // PWIDGET_H


