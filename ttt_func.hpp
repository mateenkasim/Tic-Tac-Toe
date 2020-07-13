#include <vector>

int get_size();

std::vector<char> initialize(int size);

int get_input(std::vector<char> board);

void display_board(std::vector<char> board);

bool check_win(std::vector<char> board, int pos);

void congratulate(char player);