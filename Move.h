#ifndef MOVE_H
#define MOVE_H

class Move{
public:
    Move(int c, int r, char symb);

    Move& operator=(const Move& m);

    int get_row() {return row;}
    int get_col() {return col;}
    char get_symbol() {return symbol;}
private:
    int row, col;
    char symbol;
};

#endif