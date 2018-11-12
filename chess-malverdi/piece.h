#ifndef PIECE_H
#define PIECE_H

#include <QString>

class piece
{
public:
    piece( );

    int id;
    QString side;
    bool exist;
    int row;
    int col;
};

#endif // PIECE_H
