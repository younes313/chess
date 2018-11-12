#ifndef QUEEN_H
#define QUEEN_H

#include <piece.h>

class queen : public piece
{
public:
    queen(QString s ,int id,int row,int col);
};

#endif // QUEEN_H
