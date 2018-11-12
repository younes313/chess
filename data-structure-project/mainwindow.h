#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSignalMapper>
#include <QVector>
#include <QSet>
#include <QList>
#include <QMediaPlayer>

#include "buttons.h"
#include "QWidget"
#include"bishop.h"
#include"king.h"
#include"knight.h"
#include"pawn.h"
#include"queen.h"
#include"rook.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

    buttons * * btn;
    bool dd;
    int id_first;
    QString turn;

    QPushButton * undo;
    int undo_num;

    QMediaPlayer * player ;


    QSet <int> myset;
    QSet <int> myset2;
    QSet <int> mysetCopy;
    QSet <int> myset2Copy;
    QSet <int> mysetKing;

    QList <int> first_place_id_list;
    QList <int> second_place_id_list;
    QList <int> first_place_idpiece_list;
    QList <int> second_place_idpiece_list;
    QList <QIcon> first_place_icon_list;
    QList <QIcon> second_place_icon_list;

    QVector <int> vtr;

    bishop * bishop_W1;
    bishop * bishop_W2;
    bishop * bishop_B1;
    bishop * bishop_B2;

    king *   king_w;
    king *   king_B;

    knight * knight_W1;
    knight * knight_W2;
    knight * knight_B1;
    knight * knight_B2;

    pawn *   pawn_W1;
    pawn *   pawn_W2;
    pawn *   pawn_W3;
    pawn *   pawn_W4;
    pawn *   pawn_W5;
    pawn *   pawn_W6;
    pawn *   pawn_W7;
    pawn *   pawn_W8;

    pawn *   pawn_B1;
    pawn *   pawn_B2;
    pawn *   pawn_B3;
    pawn *   pawn_B4;
    pawn *   pawn_B5;
    pawn *   pawn_B6;
    pawn *   pawn_B7;
    pawn *   pawn_B8;

    queen *  queen_W;
    queen *  queen_B;

    rook *   rook_W1;
    rook *   rook_W2;
    rook *   rook_B1;
    rook *   rook_B2;

    //iscons
    QPixmap * rook_white ;
    QPixmap * rook_black ;

    QPixmap * knight_white;
    QPixmap * knight_black;

    QPixmap * bishop_white;
    QPixmap * bishop_black;

    QPixmap * queen_white ;
    QPixmap * queen_black ;

    QPixmap * king_white  ;
    QPixmap * king_black  ;

    QPixmap * pawn_white  ;
    QPixmap * pawn_black  ;

    QIcon * rook_white1   ;
    QIcon * rook_black1   ;
    QIcon * knight_white1 ;
    QIcon * knight_black1 ;
    QIcon * bishop_white1 ;
    QIcon * bishop_black1 ;
    QIcon * queen_white1  ;
    QIcon * queen_black1  ;
    QIcon * king_white1   ;
    QIcon * king_black1   ;
    QIcon * pawn_white1   ;
    QIcon * pawn_black1   ;

    QSignalMapper * signalMapper ;


    void set_pieces();
    void set_places();
    void pixmap();
    void set_connetions();
    void set_signalMapper();
    void fillset(int id);
    void colorize();
    void uncolorize();
    bool movement_is_aviable(int id);
    bool kingIsInDanger(QString s);
    void filter_set(int id);


public slots:
    void button_clicked(int id);
    void undo_clicked();



public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
