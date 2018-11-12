#ifndef BUTTON_H
#define BUTTON_H
#include<Qstring>
#include<QPushButton>

class button :public QPushButton , public QWidget
{
public:
    button();

    int row;
    int col;
    QString color;



};

#endif // BUTTON_H
