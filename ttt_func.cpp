#include <iostream>
#include <cmath>
#include <vector>

// 4 Local Helper printers
void print_x(int line);
void print_o(int line);
void print_space();
void print_line(int size);

// 3 Local Helper Win Checks
bool check_r(std::vector<char> board, int row);
bool check_c(std::vector<char> board, int col);
bool check_d(std::vector<char> board, int pos);

//Returns the number of rows, i.e. board is size x size matrix
int get_size(){
     int size;
     std::cout << "How many rows should the board have (standard is 3)?\n";
     std::cin >> size;
  
     return size;
}

// Initializes and returns a blank board
std::vector<char> initialize(int size){
     std::vector<char> board;
     for (int i=0; i<size*size; i++){
          board.push_back('_');
     }
  
     return board;
}

//Retrieves input from player
//Returns position index if valid, -1 otherwise
int get_input(std::vector<char> board){
     int size = sqrt(board.size());
     int row, col, position;
  
     std::cout << "Row (1-" << size << "): ";
     std::cin >> row;
     row--;
     std::cout << "Column (1-" << size << "): ";
     std::cin >> col;
     col--;

     position = row*size+col;

     if ((row<0 || row>size) || (col<0 || col>size)){
          std::cout << "Invalid position\n";
          return -1;
     }
     if (board[position] != '_'){
          std::cout << "Already used\n";
          return -1;
     }
  
     return position;
}


// Prints out the board's current state
void display_board(std::vector<char> board){
     int size = sqrt(board.size());
     print_line(size);
     for (int i=0; i<size; i++){
          for (int l=0; l<7; l++){
               for (int j=0; j<size; j++){
                    std::cout << "|";
                    if (board[i*size + j] == 'x')
                         print_x(l);
                    else if (board[i*size + j] == 'o')
                         print_o(l);
                    else
                         print_space();
                    std::cout << "|";
               }
               std::cout << "\n";
          }
          print_line(size);
     }
     std::cout << "\n";
}

//Helper printers
void print_x(int line){
     switch(line){
          case 0:
               std::cout << "  x     x  ";
               break;
          case 1:
               std::cout << "  x     x  ";
               break;
          case 2:
               std::cout << "   x   x   ";
               break;
          case 3:
               std::cout << "     x     ";
               break;
          case 4:
               std::cout << "   x   x   ";
               break;
          case 5:
               std::cout << "  x     x  ";
               break;
          case 6:
               std::cout << "  x     x  ";
               break;
     }
}

void print_o(int line){
     switch(line){
          case 0:
               std::cout << "   ooooo   ";
               break;
          case 1:
               std::cout << "  o     o  ";
               break;
          case 2:
               std::cout << "  o     o  ";
               break;
          case 3:
               std::cout << "  o     o  ";
               break;
          case 4:
               std::cout << "  o     o  ";
               break;
          case 5:
               std::cout << "  o     o  ";
               break;
          case 6:
               std::cout << "   ooooo   ";
               break;
     }
  
}

void print_space(){
     std::cout << "           ";
}

void print_line(int size){
     std::cout << "  ";
     for (int i=0; i<12*size; i++)
          std::cout << "_";
     std::cout << "\n";
}

// Check win by checking completed row, column, or diagonal
bool check_win(std::vector<char> board, int pos){
     int size = sqrt(board.size());
     int row = pos/size;
     int col = pos%size;
     return (check_r(board, row) || check_c(board, col) || check_d(board, pos));
}

// Helper checkers
bool check_r(std::vector<char> board, int row){
     int size = sqrt(board.size());
     char c = board[row*size];
     for (int i=1; i<size; i++){
          if (board[row*size+i] != c)
               return false;
     }

     return true;
}

bool check_c(std::vector<char> board, int col){
     int size = sqrt(board.size());
     char c = board[col];
     for (int i=1; i<size; i++){
          if (board[col + i*size] != c)
               return false;
     }

     return true;
}

bool check_d(std::vector<char> board, int pos){
     int size = sqrt(board.size());
     // Diagonals only work when board has odd length
     if (size%2==0)
          return false;
     bool result = false;
     char c = board[pos];

     // Check TopLeft-->BottomRight Diagonal
     if (pos%(size+1) == 0){
          result = true;
          for (int i=0; i<size; i++){
               if (board[i*(size+1)] != c)
                    result = false;
          }
     }

     // Check TopRight-->BottomLeft Diagonal
     if (!result && pos>0 && pos%(size-1)==0){
          result = true;
          for (int i=0; i<size; i++){
               if (board[i*(size-1)] != c)
                    result = false;
          }
     }

     return result;
}

// Display Winner
void congratulate(char player){
     int p = player=='x' ? 1 : 2;
     std::cout << "Congratulations, Player " << p << "! You won!\n";
}
