/*
 * MinimaxPlayer.h
 *
 *  Created on: Apr 27, 2021
 *      Author: ying
 */

#ifndef MINIMAXPLAYER_H
#define MINIMAXPLAYER_H

#include "OthelloBoard.h"
#include "Player.h"
#include "Move.h"
#include <vector>
#include <list>

using std::list;

/**
 * This class represents an AI player that uses the Minimax algorithm to play the game
 * intelligently.
 */
class MinimaxPlayer : public Player {
public:

	/**
	 * @param symb This is the symbol for the minimax player's pieces
	 */
	MinimaxPlayer(char symb);

	/**
	 * Destructor
	 */
	virtual ~MinimaxPlayer();

	/**
	 * @param b The board object for the current state of the board
	 * @param col Holds the return value for the column of the move
	 * @param row Holds the return value for the row of the move
	 */
    void get_move(OthelloBoard* b, int& col, int& row);

    /**
     * @return A copy of the MinimaxPlayer object
     * This is a virtual copy constructor
     */
    MinimaxPlayer* clone();

private:

};

list<Move> get_actions(OthelloBoard* b, char symb);

int utility(OthelloBoard* b);

bool terminal_test(OthelloBoard* b, char symb);

int max_value(OthelloBoard b);

int min_value(OthelloBoard b);

#endif
