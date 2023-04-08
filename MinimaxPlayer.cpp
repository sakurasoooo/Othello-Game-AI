/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 27, 2021
 *      Author: ying
 */
#include <iostream>
#include <assert.h>
#include <algorithm>
#include "MinimaxPlayer.h"

using std::vector;
using std::list;
using std::max;
using std::min;

MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
	
	list<Move> actions = get_actions(b, symbol);
	Move best_move(0,0,symbol);
	int best_v = 999;
	while(!actions.empty()) {
		OthelloBoard new_b = *b;
		Move m = actions.front();
		new_b.play_move(m.get_col(),m.get_row(),symbol);
		int v = min_value(new_b);
		if(v < best_v) {
			best_v = v;
			best_move = m;
		}
		actions.pop_front();
	}
    col = best_move.get_col();
	row = best_move.get_row();
}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	
	return result;
}

int max_value(OthelloBoard b) {
	char player = b.get_p1_symbol();
	if(terminal_test(&b,b.get_p1_symbol())) {
		return utility(&b);
	}
	int value = -999;
	list<Move> actions = get_actions(&b, player);
	// for (list<Move>::iterator it = actions.begin(); it != actions.end(); ++it){
		
	// }
	while(!actions.empty()) {
		OthelloBoard new_b = b;
		Move m = actions.front();
		new_b.play_move(m.get_col(),m.get_row(),player);
		value = max(value,min_value(new_b));
		actions.pop_front();
	}
	return value;
}

int min_value(OthelloBoard b) {
	char player = b.get_p2_symbol();
	if(terminal_test(&b,b.get_p2_symbol())) {
		return utility(&b);
	}
	int value = 999;
	list<Move> actions = get_actions(&b, player);
	// for (list<Move>::iterator it = actions.begin(); it != actions.end(); ++it){
		
	// }
	while(!actions.empty()) {
		OthelloBoard new_b = b;
		Move m = actions.front();
		new_b.play_move(m.get_col(),m.get_row(),player);
		value = min(value,max_value(new_b));
		actions.pop_front();
	}
	return value;
}

bool terminal_test(OthelloBoard* b,char symb) {
	char p1 = b->get_p1_symbol();
	char p2 = b->get_p2_symbol();
	if(b->has_legal_moves_remaining(symb)){
		return false;
	}
	return true;
}

/* Utility function */
int utility(OthelloBoard* b) {
	char p1 = b->get_p1_symbol();
	char p2 = b->get_p2_symbol();
	int p1_score = b->count_score(p1);
	int p2_score = b->count_score(p2);
	if(p1 > p2){
		return 1;
	}
	if(p1 < p2){
		return -1;
	}
	return 0;
}


/* Successor function */
list<Move> get_actions(OthelloBoard* b, char symb) {
	list<Move> actions;
	int rows = b->get_num_rows();
	int cols = b->get_num_cols();
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			if(b->is_legal_move(c,r,symb)){
				actions.push_back(Move(c,r,symb));
			}
		}
	}
	return actions;
}
