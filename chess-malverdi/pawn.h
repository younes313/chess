#ifndef PAWN_H
#define PAWN_H

#include <piece.h>

class pawn : public piece
{
public:
    pawn(QString s ,int id , int row , int col);
};

#endif // PAWN_H
