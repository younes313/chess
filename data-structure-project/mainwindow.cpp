#include "mainwindow.h"
#include <QPalette>
#include <iostream>
#include <windows.h>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QWidget * widget = new QWidget;
    widget->resize(1000,900);

    dd =0;
    turn = "white";

    //newing buttons
    btn = new buttons * [8];
    for(int i=0;i<8;i++)
    {
        btn [i] = new buttons [8] ;
    }

    //initializing vector of pieces location
    for(int i=0 ;i<=64 ;i++)
    {
        if( ( (i!=0) &&  (i<17) ) || (i>48)  )
            vtr.push_back(i);
        else
            vtr.push_back(0);

    }


    //initializing buttons
    for(int i=0 ; i<8 ; i++)
    {
        for(int j=0 ;j<8;j++)
        {
            btn[i][j].pushbutton = new QPushButton(widget);
            btn[i][j].id = (i*8)+j+1;

            if((i<2)|| (i>5))
                btn[i][j].id_piece = (8*i)+j +1;
            else
                btn[i][j].id_piece = 0;


            btn[i][j].pushbutton->resize(100,100);
            btn[i][j].pushbutton->move(100+ j*100 ,50+ i*100 );
            if((i+j)%2==1)
                btn[i][j].pushbutton->setStyleSheet("background-color:gray;");
            else
                btn[i][j].pushbutton->setStyleSheet("background-color:white;");

            //            Sleep(1000);
        }
    }

    set_pieces();
    pixmap();
    set_places();
    set_signalMapper();
    set_connetions();

    //    connect(btn[6][0].pushbutton , SIGNAL(clicked(bool)) , this , SLOT(button_clicked()));

    //newing pieces

    //     btn[6 ][0].pushbutton->setIcon(QIcon());


    //    QPixmap pixmap("C:\\Users\\yunes\\Desktop\\Chess-master\\horse1.png");
    //    QIcon ButtonIcon(pixmap);
    //    btn[2][2].pushbutton->setIcon(ButtonIcon);
    //    btn[2][2].pushbutton->setIconSize(QSize(100,100));
    //    btn[2][2].pushbutton->setIcon(QIcon());

    this->setCentralWidget(widget);
}


void MainWindow::set_pieces()
{
    bishop_W1 = new bishop("white" , 59 , 7 , 2);
    bishop_W2 = new bishop("white" , 62 , 7 , 5);
    bishop_B1 = new bishop("black" , 3 , 0 , 2);
    bishop_B2 = new bishop("black" , 6 , 0 , 5);

    king_w = new king("white" , 61 , 7 ,4);
    king_B = new king("black" , 5 , 0 , 4);

    knight_W1 = new knight ("white" , 58 , 7 , 1);
    knight_W2 = new knight ("white" , 63 , 7 , 6);
    knight_B1 = new knight ("black" , 2 , 0 , 1);
    knight_B2 = new knight ("black" , 7 , 0 , 6);

    pawn_W1 = new pawn ("white" , 49 , 6 , 0);
    pawn_W2 = new pawn ("white" , 50 , 6 , 1);
    pawn_W3 = new pawn ("white" , 51 , 6 , 2);
    pawn_W4 = new pawn ("white" , 52 , 6 , 3);
    pawn_W5 = new pawn ("white" , 53 , 6 , 4);
    pawn_W6 = new pawn ("white" , 54 , 6 , 5);
    pawn_W7 = new pawn ("white" , 55 , 6 , 6);
    pawn_W8 = new pawn ("white" , 56 , 6 , 7);

    pawn_B1 = new pawn ("black" , 9 , 1 , 0);
    pawn_B2 = new pawn ("black" , 10 , 1 , 1);
    pawn_B3 = new pawn ("black" , 11 , 1 , 2);
    pawn_B4 = new pawn ("black" , 12 , 1 , 3);
    pawn_B5 = new pawn ("black" , 13 , 1 , 4);
    pawn_B6 = new pawn ("black" , 14 , 1 , 5);
    pawn_B7 = new pawn ("black" , 15 , 1 , 6);
    pawn_B8 = new pawn ("black" , 16 , 1 , 7);

    queen_W = new queen ("white" , 60 , 7 , 3);
    queen_B = new queen ("black" , 4 , 0 , 3);

    rook_W1 = new rook ("white" , 57 , 7 , 0);
    rook_W2 = new rook ("white" , 64 , 7 , 7);
    rook_B1 = new rook ("black" , 1 , 0 , 0);
    rook_B2 = new rook ("black" , 8 , 0 , 7);

}

// visibility stolen

void MainWindow::set_places()
{
    btn[0][0].pushbutton->setIcon(*rook_black1);
    btn[0][0].pushbutton->setIconSize(QSize(100,100));
    btn[0][7].pushbutton->setIcon(*rook_black1);
    btn[0][7].pushbutton->setIconSize(QSize(100,100));


    btn[0][1].pushbutton->setIcon(*knight_black1);
    btn[0][1].pushbutton->setIconSize(QSize(100,100));
    btn[0][6].pushbutton->setIcon(*knight_black1);
    btn[0][6].pushbutton->setIconSize(QSize(100,100));

    btn[0][2].pushbutton->setIcon(*bishop_black1);
    btn[0][2].pushbutton->setIconSize(QSize(100,100));
    btn[0][5].pushbutton->setIcon(*bishop_black1);
    btn[0][5].pushbutton->setIconSize(QSize(100,100));

    btn[0][3].pushbutton->setIcon(*queen_black1);
    btn[0][3].pushbutton->setIconSize(QSize(100,100));

    btn[0][4].pushbutton->setIcon(*king_black1);
    btn[0][4].pushbutton->setIconSize(QSize(100,100));

    for(int i=0;i<8;i++)
    {
        btn[1][i].pushbutton->setIcon(*pawn_black1);
        btn[1][i].pushbutton->setIconSize(QSize(100,100));

        btn[6][i].pushbutton->setIcon(*pawn_white1);
        btn[6][i].pushbutton->setIconSize(QSize(100,100));

    }

    btn[7][0].pushbutton->setIcon(*rook_white1);
    btn[7][0].pushbutton->setIconSize(QSize(100,100));
    btn[7][7].pushbutton->setIcon(*rook_white1);
    btn[7][7].pushbutton->setIconSize(QSize(100,100));

    btn[7][1].pushbutton->setIcon(*knight_white1);
    btn[7][1].pushbutton->setIconSize(QSize(100,100));
    btn[7][6].pushbutton->setIcon(*knight_white1);
    btn[7][6].pushbutton->setIconSize(QSize(100,100));

    btn[7][2].pushbutton->setIcon(*bishop_white1);
    btn[7][2].pushbutton->setIconSize(QSize(100,100));
    btn[7][5].pushbutton->setIcon(*bishop_white1);
    btn[7][5].pushbutton->setIconSize(QSize(100,100));

    btn[7][3].pushbutton->setIcon(*queen_white1);
    btn[7][3].pushbutton->setIconSize(QSize(100,100));

    btn[7][4].pushbutton->setIcon(*king_white1);
    btn[7][4].pushbutton->setIconSize(QSize(100,100));





}

void MainWindow::pixmap()
{
    rook_white = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\rook1.png");
    rook_black = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\rook.png");

    knight_white = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\horse1.png");
    knight_black = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\horse.png");

    bishop_white = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\bishop1.png");
    bishop_black = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\bishop.png");

    queen_white = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\queen1.png");
    queen_black = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\queen.png");

    king_white = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\king1.png");
    king_black = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\king.png");

    pawn_white = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\pawn1.png");
    pawn_black = new QPixmap("C:\\Users\\yunes\\Desktop\\piecesssss\\pawn.png");

    rook_white1   = new QIcon(*rook_white);
    rook_black1   = new QIcon(*rook_black);
    knight_white1 = new QIcon(*knight_white);
    knight_black1 = new QIcon(*knight_black);
    bishop_white1 = new QIcon(*bishop_white);
    bishop_black1 = new QIcon(*bishop_black);
    queen_white1  = new QIcon(*queen_white);
    queen_black1  = new QIcon(*queen_black);
    king_white1   = new QIcon(*king_white);
    king_black1   = new QIcon(*king_black);
    pawn_white1   = new QIcon(*pawn_white);
    pawn_black1   = new QIcon(*pawn_black);
}

void MainWindow::set_connetions()
{
    //    for(int i=0 ; i<8 ; i++)
    //    {
    //        for(int j=0 ;j<8;j++)
    //        {
    //
    //    int a=49;
    //            connect(btn[6][0].pushbutton , SIGNAL(clicked(bool)) , this , SLOT(button_clicked(int)));
    //        }
    //    }
}

void MainWindow::set_signalMapper()
{
    signalMapper = new QSignalMapper(this);

    for(int i = 0;i<8;i++)
        for(int j=0 ;j<8 ;j++)
        {
            signalMapper->setMapping(btn[i][j].pushbutton , i*10 + j);
            connect(btn[i][j].pushbutton , SIGNAL(clicked(bool)), signalMapper , SLOT(map()));
        }

    connect(signalMapper , SIGNAL(mapped(int)) , this , SLOT(button_clicked(int)));
}


void MainWindow::button_clicked(int id)
{
    if(!dd)
    {
        if( ((turn=="white")&&(btn[id/10][id%10].id_piece > 48))   /*player can choose  button :  it's his turn & king is not in danger */
                ||
                ((turn =="black")&& (btn[id/10][id%10].id_piece < 17)&&(btn[id/10][id%10].id_piece >0)))
        {
            id_first = id;
            dd=1;

        }
    }
    else
    {
        if(1 /*movement is avaible */ )
        {
            QIcon temp ;
            //            if(id_first >=10)
            temp = btn[id_first/10][id_first%10 ].pushbutton->icon();
            btn[(id_first)/10][id_first%10 ].pushbutton->setIcon(QIcon());
            btn[(id)/10][id%10 ].pushbutton->setIcon(temp);
            btn[(id)/10][id%10 ].pushbutton->setIconSize(QSize(100,100));

            int tmp;
            vtr[]
            btn[(id)/10][id%10 ].id_piece = btn[(id_first)/10][id_first%10 ].id_piece ;


            dd=0;
            if(turn=="white")
                turn = "black";
            else turn = "white";
        }
    }

}



MainWindow::~MainWindow()
{

}
