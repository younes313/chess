#ifndef ROOK_H
#define ROOK_H

#include <piece.h>

class rook : public piece
{
public:
    rook(QString s , int id ,int row , int col);
};

#endif // ROOK_H
