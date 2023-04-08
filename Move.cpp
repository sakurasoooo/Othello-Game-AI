#include "Move.h"

Move::Move(int c, int r, char symb){
    row = r;
    col = c;
    symbol = symb;
}

Move& Move::operator=(const Move& m){
    row = m.row;
    col = m.col;
    symbol = m.symbol;
    return *this;
}