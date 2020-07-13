#include <iostream>
#include <vector>
#include "ttt_func.hpp"

int main(){
  
	int size = get_size();
	std::vector<char> board = initialize(size);
	display_board(board);

	bool inPlay = true;
	int plays = 0;
	char player;
	  
	while (inPlay && plays<board.size()){
		player = 'x';
	    	std::cout << "Player 1: Where is your next play?\n";
	    	int pos = -1;
	    	while (pos<0){
	      	pos = get_input(board);
	    	}
	    	board[pos] = player;
	    	display_board(board);
	    	if (check_win(board, pos))
	      	break;
	    	plays++;
	    	if (plays>=board.size())
	      	break;
	  
	    	player = 'o';
	    	std::cout << "Player 2: Where is your next play?\n";
	    	pos = -1;
	    	while (pos<0){
	      	pos = get_input(board);
	    	}
	    	board[pos] = player;
	    	display_board(board);
	    	if (check_win(board, pos))
	      	break;
	    	plays++;
	  	}
	if (plays<board.size())
		congratulate(player);
	else
	    	std::cout << "Tie!";

}