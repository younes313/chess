#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include <QPushButton>

class buttons : public QWidget
{
    Q_OBJECT
public:
    explicit buttons(QWidget *parent = 0);

    QPushButton * pushbutton;
//    int row;
//    int col;
    QString color;
    int id;
    int id_piece;


signals:

public slots:
};

#endif // BUTTONS_H
