#include "mainwindow.h"
#include <QPalette>
#include <iostream>
#include <windows.h>

using namespace std;

//last step pawn
//if movement is not avaible dont go to the second part

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QWidget * widget = new QWidget;
    widget->resize(1000,900);

    undo = new QPushButton(widget);
    undo->resize(40,40);
    undo->move(20,50);
    undo->setText("Undo");
    connect(undo , SIGNAL(clicked(bool)) , this , SLOT(undo_clicked()));
    undo_num=0;

    dd =0;
    turn = "white";

    player=new QMediaPlayer(this);


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

    for(int i=0 ; i<8 ; i++)
    {
        for(int j=0 ;j<8;j++)
        {
            cout<<btn[i][j].id_piece<<" ";
        }
        cout<<endl;
    }
    //    set_connetions();

    //    connect(btn[6][0].pushbutton , SIGNAL(clicked(bool)) , this , SLOT(button_clicked()));

    //newing pieces

    //     btn[6 ][0].pushbutton->setIcon(QIcon());


    //    QPixmap pixmap("C:\\Users\\yunes\\Desktop\\Chess-master\\horse1.png");
    //    QIcon ButtonIcon(pixmap);
    //    btn[2][2].pushbutton->setIcon(ButtonIcon);
    //    btn[2][2].pushbutton->setIconSize(QSize(100,100));
    //    btn[2][2].pushbutton->setIcon(QIcon());

    //    btn[0][1].pushbutton->setStyleSheet(" background-color: white;"
    //                                        "border-style: outset;"
    //                                        "border-width: 10px;"
    //                                        "border-color: red;");
    //    btn[0][0].pushbutton->setStyleSheet("background-color: white");

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
    rook_W2 = new rook ("white" , 64 , 7 , 7); //changed 7,7
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
    rook_white   = new QPixmap("D:\\piecesssss\\rook1.png");
    rook_black   = new QPixmap("D:\\piecesssss\\rook.png");

    knight_white = new QPixmap("D:\\piecesssss\\horse1.png");
    knight_black = new QPixmap("D:\\piecesssss\\horse.png");

    bishop_white = new QPixmap("D:\\piecesssss\\bishop1.png");
    bishop_black = new QPixmap("D:\\piecesssss\\bishop.png");

    queen_white  = new QPixmap("D:\\piecesssss\\queen1.png");
    queen_black  = new QPixmap("D:\\piecesssss\\queen.png");

    king_white   = new QPixmap("D:\\piecesssss\\king1.png");
    king_black   = new QPixmap("D:\\piecesssss\\king.png");

    pawn_white   = new QPixmap("D:\\piecesssss\\pawn1.png");
    pawn_black   = new QPixmap("D:\\piecesssss\\pawn.png");

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
                ((turn =="black") && (btn[id/10][id%10].id_piece < 17)&&(btn[id/10][id%10].id_piece >0)))
        {
//            if()
            id_first = id;
            dd=1;
            myset.clear();
            myset2.clear();
            fillset(id);
            colorize();


        }
    }
    else
    {

//        if( king_in_danger(id_first , id) == 0)
//        {
//            dd=0;
//            return;
//        }

        if( movement_is_aviable(id) && (id!=id_first) )
        {

            QIcon temp ;

            //playing sounds
            soundes();

            //filling undo lists
            {
                first_place_icon_list.push_front(btn[id_first/10][id_first%10].pushbutton->icon());
                second_place_icon_list.push_front(btn[id/10][id%10].pushbutton->icon());
                first_place_id_list.push_front(id_first);
                second_place_id_list.push_front(id);
                first_place_idpiece_list.push_front(btn[id_first/10][id_first%10].id_piece);
                second_place_idpiece_list.push_front(btn[id/10][id%10].id_piece);
                undo_num++;
            }


            temp = btn[id_first/10][id_first%10 ].pushbutton->icon();
            btn[(id_first)/10][id_first%10 ].pushbutton->setIcon(QIcon());
            btn[(id)/10][id%10 ].pushbutton->setIcon(temp);
            btn[(id)/10][id%10 ].pushbutton->setIconSize(QSize(100,100));




            btn[(id)/10][id%10 ].id_piece = btn[(id_first)/10][id_first%10 ].id_piece ;
            btn[(id_first)/10][id_first%10 ].id_piece = 0;

            uncolorize();

            dd=0;
            if(turn=="white")
                turn = "black";
            else turn = "white";


        }
    }

}



void MainWindow::fillset(int id)
{
    int row1 =  id/10;
    int col1 =  id%10;
    myset.clear();
    myset2.clear();

    //rook
    if(btn[row1][col1].id_piece == 1 || btn[row1][col1].id_piece == 8 || btn[row1][col1].id_piece == 57 || btn[row1][col1].id_piece == 64)
    {
        if(turn == "white")
        {
            for(int i=row1+1 ; i<8 ; i++)
            {
                if((btn[i][col1].id_piece <17) && (btn[i][col1].id_piece>0))
                {
                    myset2.insert(i*10 + col1);
                    break;
                }
                else if(btn[i][col1].id_piece >48)
                    break;

                myset.insert(i*10 + col1);

            }

            for(int i=row1-1 ; i>=0 ; i--)
            {
                if(btn[i][col1].id_piece <17 && btn[i][col1].id_piece>0)
                {
                    myset2.insert(i*10 + col1);
                    break;
                }
                else if(btn[i][col1].id_piece >48)
                    break;

                myset.insert(i*10 + col1);

            }


            for(int i=col1+1 ; i<8 ; i++)
            {
                if(btn[row1][i].id_piece <17 && btn[row1][i].id_piece>0)
                {
                    myset2.insert(row1*10 + i);
                    break;
                }
                else if(btn[row1][i].id_piece >48)
                    break;

                myset.insert(row1*10 + i);

            }


            for(int i=col1-1 ; i>=0 ; i--)
            {
                if(btn[row1][i].id_piece <17 && btn[row1][i].id_piece>0)
                {
                    myset2.insert(row1*10 + i);
                    break;
                }
                else if(btn[row1][i].id_piece >48)
                    break;

                myset.insert(row1*10 + i);

            }



        }

        else if(turn == "black")
        {
            for(int i=row1+1 ; i<8 ; i++)
            {
                if((btn[i][col1].id_piece <17) && (btn[i][col1].id_piece>0))
                    break;

                else if(btn[i][col1].id_piece >48)
                {
                    myset2.insert(i*10 + col1);
                    break;
                }

                myset.insert(i*10 + col1);

            }

            for(int i=row1-1 ; i>=0 ; i--)
            {
                if(btn[i][col1].id_piece >48)
                {
                    myset2.insert(i*10 + col1);
                    break;
                }
                else if( btn[i][col1].id_piece <17 && btn[i][col1].id_piece>0)
                    break;

                myset.insert(i*10 + col1);

            }


            for(int i=col1+1 ; i<8 ; i++)
            {
                if(btn[row1][i].id_piece >48)
                {
                    myset2.insert(row1*10 + i);
                    break;
                }
                else if(btn[row1][i].id_piece <17 && btn[row1][i].id_piece>0)
                    break;

                myset.insert(row1*10 + i);

            }


            for(int i=col1-1 ; i>=0 ; i--)
            {
                if(btn[row1][i].id_piece >48)
                {
                    myset2.insert(row1*10 + i);
                    break;
                }
                else if(btn[row1][i].id_piece <17 && btn[row1][i].id_piece>0)
                    break;

                myset.insert(row1*10 + i);

            }



        }
    }
    //bishop
    else if(btn[row1][col1].id_piece == 3 || btn[row1][col1].id_piece == 6 || btn[row1][col1].id_piece == 59 || btn[row1][col1].id_piece == 62)
    {
        if(turn=="white")
        {
            for(int i=1 ; i+row1<8 && i+col1<8 ; i++)
            {
                if((btn[row1+i][col1+i].id_piece <17) && (btn[row1+i][col1+i].id_piece>0))
                {
                    myset2.insert((row1+i)*10 + col1+i);
                    break;
                }
                else if(btn[row1+i][col1+i].id_piece >48)
                    break;

                myset.insert((row1+i)*10 + col1+i);
            }

            for(int i=1 ; i+row1<8 && col1-i>=0 ; i++)
            {
                if((btn[row1+i][col1-i].id_piece <17) && (btn[row1+i][col1-i].id_piece>0))
                {
                    myset2.insert((row1+i)*10 + col1-i);
                    break;
                }
                else if(btn[row1+i][col1-i].id_piece >48)
                    break;

                myset.insert((row1+i)*10 + col1-i);
            }

            for(int i=1 ; row1-i>=0 && col1-i>=0 ; i++)
            {
                if((btn[row1-i][col1-i].id_piece <17) && (btn[row1-i][col1-i].id_piece>0))
                {
                    myset2.insert((row1-i)*10 + col1-i);
                    break;
                }
                else if(btn[row1-i][col1-i].id_piece >48)
                    break;

                myset.insert((row1-i)*10 + col1-i);
            }

            for(int i=1 ; row1-i>=0 && i+col1<8 ; i++)
            {
                if((btn[row1-i][col1+i].id_piece <17) && (btn[row1-i][col1+i].id_piece>0))
                {
                    myset2.insert((row1-i)*10 + col1+i);
                    break;
                }
                else if(btn[row1-i][col1+i].id_piece >48)
                    break;

                myset.insert((row1-i)*10 + col1+i);
            }

        }
        else if(turn=="black")
        {
            for(int i=1 ; i+row1<8 && i+col1<8 ; i++)
            {
                if(btn[row1+i][col1+i].id_piece >48)
                {
                    myset2.insert((row1+i)*10 + col1+i);
                    break;
                }
                else if((btn[row1+i][col1+i].id_piece <17) && (btn[row1+i][col1+i].id_piece>0))
                    break;

                myset.insert((row1+i)*10 + col1+i);
            }

            for(int i=1 ; i+row1<8 && col1-i>=0 ; i++)
            {
                if(btn[row1+i][col1-i].id_piece >48)
                {
                    myset2.insert((row1+i)*10 + col1-i);
                    break;
                }
                else if((btn[row1+i][col1-i].id_piece <17) && (btn[row1+i][col1-i].id_piece>0))
                    break;

                myset.insert((row1+i)*10 + col1-i);
            }

            for(int i=1 ; row1-i>=0 && col1-i>=0 ; i++)
            {
                if(btn[row1-i][col1-i].id_piece >48)
                {
                    myset2.insert((row1-i)*10 + col1-i);
                    break;
                }
                else if((btn[row1-i][col1-i].id_piece <17) && (btn[row1-i][col1-i].id_piece>0))
                    break;

                myset.insert((row1-i)*10 + col1-i);
            }

            for(int i=1 ; row1-i>=0 && i+col1<8 ; i++)
            {
                if(btn[row1-i][col1+i].id_piece >48)
                {
                    myset2.insert((row1-i)*10 + col1+i);
                    break;
                }
                else if((btn[row1-i][col1+i].id_piece <17) && (btn[row1-i][col1+i].id_piece>0))
                    break;

                myset.insert((row1-i)*10 + col1+i);
            }

        }

    }
    //queen
    else if(btn[row1][col1].id_piece == 4 || btn[row1][col1].id_piece == 60)
    {
        if(turn=="white")
        {
            for(int i=row1+1 ; i<8 ; i++)
            {
                if((btn[i][col1].id_piece <17) && (btn[i][col1].id_piece>0))
                {
                    myset2.insert(i*10 + col1);
                    break;
                }
                else if(btn[i][col1].id_piece >48)
                    break;

                myset.insert(i*10 + col1);

            }

            for(int i=row1-1 ; i>=0 ; i--)
            {
                if(btn[i][col1].id_piece <17 && btn[i][col1].id_piece>0)
                {
                    myset2.insert(i*10 + col1);
                    break;
                }
                else if(btn[i][col1].id_piece >48)
                    break;

                myset.insert(i*10 + col1);

            }


            for(int i=col1+1 ; i<8 ; i++)
            {
                if(btn[row1][i].id_piece <17 && btn[row1][i].id_piece>0)
                {
                    myset2.insert(row1*10 + i);
                    break;
                }
                else if(btn[row1][i].id_piece >48)
                    break;

                myset.insert(row1*10 + i);

            }


            for(int i=col1-1 ; i>=0 ; i--)
            {
                if(btn[row1][i].id_piece <17 && btn[row1][i].id_piece>0)
                {
                    myset2.insert(row1*10 + i);
                    break;
                }
                else if(btn[row1][i].id_piece >48)
                    break;

                myset.insert(row1*10 + i);

            }


            for(int i=1 ; i+row1<8 && i+col1<8 ; i++)
            {
                if((btn[row1+i][col1+i].id_piece <17) && (btn[row1+i][col1+i].id_piece>0))
                {
                    myset2.insert((row1+i)*10 + col1+i);
                    break;
                }
                else if(btn[row1+i][col1+i].id_piece >48)
                    break;

                myset.insert((row1+i)*10 + col1+i);
            }

            for(int i=1 ; i+row1<8 && col1-i>=0 ; i++)
            {
                if((btn[row1+i][col1-i].id_piece <17) && (btn[row1+i][col1-i].id_piece>0))
                {
                    myset2.insert((row1+i)*10 + col1-i);
                    break;
                }
                else if(btn[row1+i][col1-i].id_piece >48)
                    break;

                myset.insert((row1+i)*10 + col1-i);
            }

            for(int i=1 ; row1-i>=0 && col1-i>=0 ; i++)
            {
                if((btn[row1-i][col1-i].id_piece <17) && (btn[row1-i][col1-i].id_piece>0))
                {
                    myset2.insert((row1-i)*10 + col1-i);
                    break;
                }
                else if(btn[row1-i][col1-i].id_piece >48)
                    break;

                myset.insert((row1-i)*10 + col1-i);
            }

            for(int i=1 ; row1-i>=0 && i+col1<8 ; i++)
            {
                if((btn[row1-i][col1+i].id_piece <17) && (btn[row1-i][col1+i].id_piece>0))
                {
                    myset2.insert((row1-i)*10 + col1+i);
                    break;
                }
                else if(btn[row1-i][col1+i].id_piece >48)
                    break;

                myset.insert((row1-i)*10 + col1+i);
            }
        }
        else if(turn=="black")
        {
            for(int i=row1+1 ; i<8 ; i++)
            {
                if((btn[i][col1].id_piece <17) && (btn[i][col1].id_piece>0))
                    break;

                else if(btn[i][col1].id_piece >48)
                {
                    myset2.insert(i*10 + col1);
                    break;
                }

                myset.insert(i*10 + col1);

            }

            for(int i=row1-1 ; i>=0 ; i--)
            {
                if(btn[i][col1].id_piece >48)
                {
                    myset2.insert(i*10 + col1);
                    break;
                }
                else if( btn[i][col1].id_piece <17 && btn[i][col1].id_piece>0)
                    break;

                myset.insert(i*10 + col1);

            }


            for(int i=col1+1 ; i<8 ; i++)
            {
                if(btn[row1][i].id_piece >48)
                {
                    myset2.insert(row1*10 + i);
                    break;
                }
                else if(btn[row1][i].id_piece <17 && btn[row1][i].id_piece>0)
                    break;

                myset.insert(row1*10 + i);

            }


            for(int i=col1-1 ; i>=0 ; i--)
            {
                if(btn[row1][i].id_piece >48)
                {
                    myset2.insert(row1*10 + i);
                    break;
                }
                else if(btn[row1][i].id_piece <17 && btn[row1][i].id_piece>0)
                    break;

                myset.insert(row1*10 + i);

            }

            for(int i=1 ; i+row1<8 && i+col1<8 ; i++)
            {
                if(btn[row1+i][col1+i].id_piece >48)
                {
                    myset2.insert((row1+i)*10 + col1+i);
                    break;
                }
                else if((btn[row1+i][col1+i].id_piece <17) && (btn[row1+i][col1+i].id_piece>0))
                    break;

                myset.insert((row1+i)*10 + col1+i);
            }

            for(int i=1 ; i+row1<8 && col1-i>=0 ; i++)
            {
                if(btn[row1+i][col1-i].id_piece >48)
                {
                    myset2.insert((row1+i)*10 + col1-i);
                    break;
                }
                else if((btn[row1+i][col1-i].id_piece <17) && (btn[row1+i][col1-i].id_piece>0))
                    break;

                myset.insert((row1+i)*10 + col1-i);
            }

            for(int i=1 ; row1-i>=0 && col1-i>=0 ; i++)
            {
                if(btn[row1-i][col1-i].id_piece >48)
                {
                    myset2.insert((row1-i)*10 + col1-i);
                    break;
                }
                else if((btn[row1-i][col1-i].id_piece <17) && (btn[row1-i][col1-i].id_piece>0))
                    break;

                myset.insert((row1-i)*10 + col1-i);
            }

            for(int i=1 ; row1-i>=0 && i+col1<8 ; i++)
            {
                if(btn[row1-i][col1+i].id_piece >48)
                {
                    myset2.insert((row1-i)*10 + col1+i);
                    break;
                }
                else if((btn[row1-i][col1+i].id_piece <17) && (btn[row1-i][col1+i].id_piece>0))
                    break;

                myset.insert((row1-i)*10 + col1+i);
            }

        }
    }
    //knight
    else if(btn[row1][col1].id_piece == 2 || btn[row1][col1].id_piece == 7 || btn[row1][col1].id_piece == 58 || btn[row1][col1].id_piece == 63)
    {
        if(turn=="white")
        {
            if( (row1+2)<8 )
            {
                if((col1+1)<8)
                {
                    if(btn[row1+2][col1+1].id_piece<17 && btn[row1+2][col1+1].id_piece>0)
                        myset2.insert((row1+2)*10 + col1+1 );
                    else if(btn[row1+2][col1+1].id_piece == 0)
                        myset.insert((row1+2)*10 + col1+1);
                }
                if((col1-1)>=0)
                {
                    if(btn[row1+2][col1-1].id_piece<17 && btn[row1+2][col1-1].id_piece>0)
                        myset2.insert((row1+2)*10 + col1-1 );
                    else if(btn[row1+2][col1-1].id_piece == 0)
                        myset.insert((row1+2)*10 + col1-1);
                }
            }

            if( (row1-2)>=0 )
            {
                if((col1+1)<8)
                {
                    if(btn[row1-2][col1+1].id_piece<17 && btn[row1-2][col1+1].id_piece>0)
                        myset2.insert((row1-2)*10 + col1+1 );
                    else if(btn[row1-2][col1+1].id_piece == 0)
                        myset.insert((row1-2)*10 + col1+1);
                }
                if((col1-1)>=0)
                {
                    if(btn[row1-2][col1-1].id_piece<17 && btn[row1-2][col1-1].id_piece>0)
                        myset2.insert((row1-2)*10 + col1-1 );
                    else if(btn[row1-2][col1-1].id_piece == 0)
                        myset.insert((row1-2)*10 + col1-1);
                }
            }


            if( (col1+2)<8 )
            {
                if((row1+1)<8)
                {
                    if(btn[row1+1][col1+2].id_piece<17 && btn[row1+1][col1+2].id_piece>0)
                        myset2.insert((row1+1)*10 + col1+2 );
                    else if(btn[row1+1][col1+2].id_piece == 0)
                        myset.insert((row1+1)*10 + col1+2);
                }
                if((row1-1)>=0)
                {
                    if(btn[row1-1][col1+2].id_piece<17 && btn[row1-1][col1+2].id_piece>0)
                        myset2.insert((row1-1)*10 + col1+2 );
                    else if(btn[row1-1][col1+2].id_piece == 0)
                        myset.insert((row1-1)*10 + col1+2);
                }
            }

            if( (col1-2)>=0 )
            {
                if((row1+1)<8)
                {
                    if(btn[row1+1][col1-2].id_piece<17 && btn[row1+1][col1-2].id_piece>0)
                        myset2.insert((row1+1)*10 + col1-2 );
                    else if(btn[row1+1][col1-2].id_piece == 0)
                        myset.insert((row1+1)*10 + col1-2);
                }
                if((row1-1)>=0)
                {
                    if(btn[row1-1][col1-2].id_piece<17 && btn[row1-1][col1-2].id_piece>0)
                        myset2.insert((row1-1)*10 + col1-2 );
                    else if(btn[row1-1][col1-2].id_piece == 0)
                        myset.insert((row1-1)*10 + col1-2);
                }
            }


        }

        else if(turn=="black")
        {
            if( (row1+2)<8 )
            {
                if((col1+1)<8)
                {
                    if(btn[row1+2][col1+1].id_piece>48)
                        myset2.insert((row1+2)*10 + col1+1 );
                    else if(btn[row1+2][col1+1].id_piece == 0)
                        myset.insert((row1+2)*10 + col1+1);
                }
                if((col1-1)>=0)
                {
                    if(btn[row1+2][col1-1].id_piece>48)
                        myset2.insert((row1+2)*10 + col1-1 );
                    else if(btn[row1+2][col1-1].id_piece == 0)
                        myset.insert((row1+2)*10 + col1-1);
                }
            }

            if( (row1-2)>=0 )
            {
                if((col1+1)<8)
                {
                    if(btn[row1-2][col1+1].id_piece>48)
                        myset2.insert((row1-2)*10 + col1+1 );
                    else if(btn[row1-2][col1+1].id_piece == 0)
                        myset.insert((row1-2)*10 + col1+1);
                }
                if((col1-1)>=0)
                {
                    if(btn[row1-2][col1-1].id_piece>48)
                        myset2.insert((row1-2)*10 + col1-1 );
                    else if(btn[row1-2][col1-1].id_piece == 0)
                        myset.insert((row1-2)*10 + col1-1);
                }
            }


            if( (col1+2)<8 )
            {
                if((row1+1)<8)
                {
                    if(btn[row1+1][col1+2].id_piece>48)
                        myset2.insert((row1+1)*10 + col1+2 );
                    else if(btn[row1+1][col1+2].id_piece == 0)
                        myset.insert((row1+1)*10 + col1+2);
                }
                if((row1-1)>=0)
                {
                    if(btn[row1-1][col1+2].id_piece>48)
                        myset2.insert((row1-1)*10 + col1+2 );
                    else if(btn[row1-1][col1+2].id_piece == 0)
                        myset.insert((row1-1)*10 + col1+2);
                }
            }

            if( (col1-2)>=0 )
            {
                if((row1+1)<8)
                {
                    if(btn[row1+1][col1-2].id_piece>48)
                        myset2.insert((row1+1)*10 + col1-2 );
                    else if(btn[row1+1][col1-2].id_piece == 0)
                        myset.insert((row1+1)*10 + col1-2);
                }
                if((row1-1)>=0)
                {
                    if(btn[row1-1][col1-2].id_piece>48)
                        myset2.insert((row1-1)*10 + col1-2 );
                    else if(btn[row1-1][col1-2].id_piece == 0)
                        myset.insert((row1-1)*10 + col1-2);
                }
            }

        }
    }
    //pawn
    else if(((btn[row1][col1].id_piece<17)&&(btn[row1][col1].id_piece>8)) || ((btn[row1][col1].id_piece<57)&&(btn[row1][col1].id_piece>48)) )
    {
        if(turn=="white")
        {
            if(row1-1 >=0)
            {
                if(col1-1>=0)
                {
                    if(btn[row1-1][col1-1].id_piece < 17 && btn[row1-1][col1-1].id_piece>0)
                        myset2.insert((row1-1)*10 + col1-1);
                }
                if(col1+1 <8)
                {
                    if(btn[row1-1][col1+1].id_piece < 17 && btn[row1-1][col1+1].id_piece>0)
                        myset2.insert((row1-1)*10 + col1+1);
                }
            }

            if(row1 == 6)
            {
                for(int i=1;i<=2;i++)
                {
                    if(btn[row1-i][col1].id_piece == 0)
                        myset.insert((row1-i)*10 + col1);
                    else
                        break;
                }
            }
            else if(row1>1)
            {
                if(btn[row1-1][col1].id_piece == 0)
                    myset.insert((row1-1)*10 + col1);
            }
            else if(row1 == 1)
            {

            }

        }
        else if(turn =="black")
        {
            if(row1+1 < 8)
            {
                if(col1-1 >=0)
                {
                    if(btn[row1+1][col1-1].id_piece >48)
                        myset2.insert((row1+1)*10 + col1-1);
                }
                if(col1+1 < 8)
                {
                    if(btn[row1+1][col1+1].id_piece >48)
                        myset2.insert((row1+1)*10 + col1+1);
                }
            }

            if(row1 == 1)
            {
                for(int i=1;i<=2;i++)
                {
                    if(btn[row1+i][col1].id_piece == 0)
                        myset.insert((row1+i)*10 + col1);
                    else
                        break;
                }
            }
            else if(row1<6)
            {
                if(btn[row1+1][col1].id_piece == 0)
                    myset.insert((row1+1)*10 + col1);
            }
            else if(row1 == 6)
            {

            }
        }
    }
    //king
    else if(btn[row1][col1].id_piece == 5 || btn[row1][col1].id_piece == 61 )
    {
        if(turn == "white")
        {
            if(row1+1<8)
            {
                if(btn[row1+1][col1].id_piece == 0)
                    myset.insert((row1+1)*10 +col1);
                else if(btn[row1+1][col1].id_piece < 17 && btn[row1+1][col1].id_piece >0)
                    myset2.insert((row1+1)*10 +col1);

                if((col1+1)<8)
                {
                    if(btn[row1+1][col1+1].id_piece < 17 && btn[row1+1][col1+1].id_piece >0 )
                        myset2.insert(((row1+1)*10)+col1+1);
                    else if(btn[row1+1][col1+1].id_piece ==0)
                        myset.insert(((row1+1)*10)+col1+1);
                }
                if(col1-1 >=0)
                {
                    if(btn[row1+1][col1-1].id_piece < 17 && btn[row1+1][col1-1].id_piece >0 )
                        myset2.insert(((row1+1)*10)+col1-1);
                    else if(btn[row1+1][col1-1].id_piece  == 0)
                        myset.insert(((row1+1)*10)+col1-1);

                }
            }
            if(row1-1>=0)
            {
                if(btn[row1-1][col1].id_piece == 0)
                    myset.insert((row1-1)*10 +col1);
                else if(btn[row1-1][col1].id_piece<17 && btn[row1-1][col1].id_piece>0)
                    myset2.insert((row1-1)*10 +col1);
                if((col1+1)<8)
                {
                    if(btn[row1-1][col1+1].id_piece < 17 && btn[row1-1][col1+1].id_piece >0 )
                        myset2.insert(((row1-1)*10)+col1+1);
                    else if(btn[row1-1][col1+1].id_piece == 0)
                        myset.insert(((row1-1)*10)+col1+1);
                }
                if(col1-1 >=0)
                {
                    if(btn[row1-1][col1-1].id_piece < 17 && btn[row1-1][col1-1].id_piece >0 )
                        myset2.insert(((row1-1)*10)+col1-1);
                    else if(btn[row1-1][col1-1].id_piece ==0)
                        myset.insert(((row1-1)*10)+col1-1);
                }
            }
            if(col1+1<8)
            {
                if(btn[row1][col1+1].id_piece <17 && btn[row1][col1+1].id_piece >0)
                    myset2.insert(row1*10 + col1+1);
                else if(btn[row1][col1+1].id_piece  ==0 )
                    myset.insert(row1*10 + col1+1);
            }
            if(col1-1 >= 0)
            {
                if(btn[row1][col1-1].id_piece <17 && btn[row1][col1-1].id_piece >0)
                    myset2.insert(row1*10 + col1-1);
                else if(btn[row1][col1-1].id_piece  ==0 )
                    myset.insert(row1*10 + col1-1);
            }

        }
        else if(turn == "black")
        {
            if(row1+1<8)
            {
                if(btn[row1+1][col1].id_piece == 0)
                    myset.insert((row1+1)*10 +col1);
                else if(btn[row1+1][col1].id_piece >48)
                    myset2.insert((row1+1)*10 +col1);

                if((col1+1)<8)
                {
                    if(btn[row1+1][col1+1].id_piece >48)
                        myset2.insert(((row1+1)*10)+col1+1);
                    else if(btn[row1+1][col1+1].id_piece ==0)
                        myset.insert(((row1+1)*10)+col1+1);
                }
                if(col1-1 >=0)
                {
                    if(btn[row1+1][col1-1].id_piece >48)
                        myset2.insert(((row1+1)*10)+col1-1);
                    else if(btn[row1+1][col1-1].id_piece  == 0)
                        myset.insert(((row1+1)*10)+col1-1);

                }
            }
            if(row1-1>=0)
            {
                if(btn[row1-1][col1].id_piece == 0)
                    myset.insert((row1-1)*10 +col1);
                else if(btn[row1-1][col1].id_piece>48)
                    myset2.insert((row1-1)*10 +col1);
                if((col1+1)<8)
                {
                    if(btn[row1-1][col1+1].id_piece >48)
                        myset2.insert(((row1-1)*10)+col1+1);
                    else if(btn[row1-1][col1+1].id_piece == 0)
                        myset.insert(((row1-1)*10)+col1+1);
                }
                if(col1-1 >=0)
                {
                    if(btn[row1-1][col1-1].id_piece >48)
                        myset2.insert(((row1-1)*10)+col1-1);
                    else if(btn[row1-1][col1-1].id_piece ==0)
                        myset.insert(((row1-1)*10)+col1-1);
                }
            }
            if(col1+1<8)
            {
                if(btn[row1][col1+1].id_piece >48)
                    myset2.insert(row1*10 + col1+1);
                else if(btn[row1][col1+1].id_piece  ==0 )
                    myset.insert(row1*10 + col1+1);
            }
            if(col1-1 >= 0)
            {
                if(btn[row1][col1-1].id_piece >48)
                    myset2.insert(row1*10 + col1-1);
                else if(btn[row1][col1-1].id_piece  ==0 )
                    myset.insert(row1*10 + col1-1);
            }

        }

    }
}
void MainWindow::colorize()
{

    for(QSet<int> ::iterator itr = myset.begin() ; itr != myset.end() ; itr++)
    {
        int row1 = (*itr) / 10;
        int col1 = (*itr) % 10;
        if((row1+col1)%2==0)
        {
            btn[row1][col1].pushbutton->setStyleSheet(" background-color: white;"
                                                      "border-style: outset;"
                                                      "border-width: 10px;"
                                                      "border-color: green;");
        }
        else
        {
            btn[row1][col1].pushbutton->setStyleSheet(" background-color: gray;"
                                                      "border-style: outset;"
                                                      "border-width: 10px;"
                                                      "border-color: green;");
        }
    }


    for(QSet<int> ::iterator itr = myset2.begin() ; itr != myset2.end() ; itr++)
    {
        int row1 = (*itr) / 10;
        int col1 = (*itr) % 10;
        if((row1+col1)%2==0)
        {
            btn[row1][col1].pushbutton->setStyleSheet(" background-color: white;"
                                                      "border-style: outset;"
                                                      "border-width: 10px;"
                                                      "border-color: red;");
        }
        else
        {
            btn[row1][col1].pushbutton->setStyleSheet(" background-color: gray;"
                                                      "border-style: outset;"
                                                      "border-width: 10px;"
                                                      "border-color: red;");
        }
    }
}

void MainWindow::uncolorize()
{
    for(QSet<int> ::iterator itr = myset.begin() ; itr != myset.end() ; itr++)
    {
        int row1 = (*itr) / 10;
        int col1 = (*itr) % 10;
        if((row1+col1)%2==0)
        {
            btn[row1][col1].pushbutton->setStyleSheet(" background-color: white;");
        }
        else
        {
            btn[row1][col1].pushbutton->setStyleSheet(" background-color: gray;");

        }
    }


    for(QSet<int> ::iterator itr = myset2.begin() ; itr != myset2.end() ; itr++)
    {
        int row1 = (*itr) / 10;
        int col1 = (*itr) % 10;
        if((row1+col1)%2==0)
        {
            btn[row1][col1].pushbutton->setStyleSheet(" background-color: white;");

        }
        else
        {
            btn[row1][col1].pushbutton->setStyleSheet(" background-color: gray;");

        }
    }
}

void MainWindow::soundes()
{

    if(btn[id_first/10][id_first%10].id_piece == 2 || btn[id_first/10][id_first%10].id_piece == 7 || btn[id_first/10][id_first%10].id_piece == 63 ||btn[id_first/10][id_first%10].id_piece == 58)
    {
        player->setMedia(QUrl::fromLocalFile("D:\\sounds\\knight.mp3"));
        player->setVolume(70);
        player->play();
    }

    if(btn[id_first/10][id_first%10].id_piece == 3 || btn[id_first/10][id_first%10].id_piece == 6 || btn[id_first/10][id_first%10].id_piece == 62 || btn[id_first/10][id_first%10].id_piece == 59)
    {
        player->setMedia(QUrl::fromLocalFile("D:\\sounds\\bishop.mp3"));
        player->setVolume(70);
        player->play();
    }
    if(btn[id_first/10][id_first%10].id_piece == 4 || btn[id_first/10][id_first%10].id_piece == 60)
    {
        player->setMedia(QUrl::fromLocalFile("D:\\sounds\\queen.mp3"));
        player->setVolume(70);
        player->play();
    }
    if(btn[id_first/10][id_first%10].id_piece == 5 || btn[id_first/10][id_first%10].id_piece == 61)
    {
        player->setMedia(QUrl::fromLocalFile("D:\\sounds\\king.mp3"));
        player->setVolume(70);
        player->play();
    }
    if(btn[id_first/10][id_first%10].id_piece == 1 || btn[id_first/10][id_first%10].id_piece == 8 || btn[id_first/10][id_first%10].id_piece == 64 || btn[id_first/10][id_first%10].id_piece == 57)
    {
        player->setMedia(QUrl::fromLocalFile("D:\\sounds\\rook.mp3"));
        player->setVolume(80);
        player->play();
    }
    if((btn[id_first/10][id_first%10].id_piece>8 && btn[id_first/10][id_first%10].id_piece<17) || (btn[id_first/10][id_first%10].id_piece>48 && btn[id_first/10][id_first%10].id_piece<57))
    {
        player->setMedia(QUrl::fromLocalFile("D:\\sounds\\pawn.mp3"));
        player->setVolume(80);
        player->play();
    }
}

bool MainWindow::movement_is_aviable(int id)
{
    for(QSet<int> ::iterator itr = myset.begin() ; itr != myset.end() ; itr++)
    {
        if( (*itr)==id )
            return true;
    }


    for(QSet<int> ::iterator itr = myset2.begin() ; itr != myset2.end() ; itr++)
    {
        if( (*itr)==id )
            return true;
    }

    dd=0;
    return false;
}



bool MainWindow::king_in_danger(int id_first,int id)
{
    int rowcpy = id_first/10;
    int colcpy = id_first%10;

    int destinationid = btn[id/10][id%10].id_piece;

    int idpiece_cpy=btn[rowcpy][colcpy].id_piece;

    btn[rowcpy][colcpy].id_piece = 0;

    btn[id/10][id%10].id_piece =  idpiece_cpy;

    if(turn == "white")
        turn="black";
    else
        turn = "white";

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {

            myset2.clear();
             myset.clear();
            fillset(i*10 + j);




   // danger = myset2 ;


    int alaki = myset2.size();




    for(QSet<int>::iterator itr = myset2.begin() ; itr != myset2.end() ;itr++ )
    {

        int piece_id = btn[(*itr)/10][(*itr)%10].id_piece ;

        if(btn[(*itr)/10][(*itr)%10].id_piece == 61 || btn[(*itr)/10][(*itr)%10].id_piece==5 )
        {
            uncolorize();
            btn[rowcpy][colcpy].id_piece=idpiece_cpy;

             btn[id/10][id%10].id_piece = destinationid;
             if(turn == "white")
                 turn="black";
             else
                 turn = "white";

            return false;
        }
    }
 }



    danger .clear();

   }

    uncolorize();

    myset2.clear();

    btn[rowcpy][colcpy].id_piece=idpiece_cpy;

     btn[id/10][id%10].id_piece = 0;
     if(turn == "white")
         turn="black";
     else
         turn = "white";

    return true;


}

void MainWindow::undo_clicked()
{


    if(!dd && undo_num!=0)
    {
        QIcon temp1 , temp2;
        QList<QIcon>::iterator icon_itr = first_place_icon_list.begin();
        QList<int>::iterator int_itr = first_place_id_list.begin();
        QList<int>::iterator id_itr = first_place_idpiece_list.begin();
        temp1 = (*icon_itr);
        btn[(*int_itr)/10][(*int_itr)%10].pushbutton->setIcon(temp1);
        btn[(*int_itr)/10][(*int_itr)%10].id_piece = (*id_itr);

        icon_itr = second_place_icon_list.begin();
        int_itr = second_place_id_list.begin();
        id_itr = second_place_idpiece_list.begin();
        temp2 = (*icon_itr);
        btn[(*int_itr)/10][(*int_itr)%10].pushbutton->setIcon(temp2);
        btn[(*int_itr)/10][(*int_itr)%10].id_piece = (*id_itr);

        first_place_icon_list.pop_front();
        first_place_idpiece_list.pop_front();
        first_place_id_list.pop_front();
        second_place_icon_list.pop_front();
        second_place_idpiece_list.pop_front();
        second_place_id_list.pop_front();

        if(turn=="white")
            turn="black";
        else
            turn="white";

        undo_num--;

    }
}


MainWindow::~MainWindow()
{

}
