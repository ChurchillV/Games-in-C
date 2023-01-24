#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Global Varaibles
char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

//Function declarations
void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Move();
void player2Move();
char checkWinner();
void printWinner(char);


int main() {

   char winner = ' ';
   char response;

   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();
      while( winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         player1Move();
         winner = checkWinner();
         printBoard();
         printf("\n");
         winner = checkWinner();
         if (winner != ' ' || checkFreeSpaces() == 0) 
         {
            break;
         }

         player2Move();
         winner = checkWinner();
         printBoard();
         printf("\n");
         winner = checkWinner();
         if (winner != ' ' || checkFreeSpaces() == 0) 
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);

      printf("\nWould you like to play again? (Y/N):");
      scanf("%c");
      scanf("%c", &response);
      response = toupper(response);
   } while (response == 'Y');
      
   printf("Thanks for playing!");

   return 0;
}
//Function definitions 
void resetBoard(){
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         board[i][j] = ' ';
      }
   }
};

void printBoard() {
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
};

int checkFreeSpaces(){
   int freeSpaces = 9;
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
};

void player1Move(){
   int x;
   int y;
   printf("PLAYER 1's turn\n");
   do
   {
      printf("Enter row number (1-3): ");
      scanf("%d", &x);
      x--;

      printf("Enter column number (1-3): ");
      scanf("%d", &y);
      y--;

      if (board[x][y] != ' ')
      {
         printf("Invalid Move!\n");
      }
      else 
      {
         board[x][y] = PLAYER1;
         break;
      }
   } while (board[x][y] != ' ');
};

void player2Move()
{
   int x;
   int y;
   printf("PLAYER 2's turn\n");

   do
   {
      printf("Enter row number (1-3): ");
      scanf("%d", &x);
      x--;

      printf("Enter column number (1-3): ");
      scanf("%d", &y);
      y--;

      if (board[x][y] != ' ')
      {
         printf("Invalid Move!\n");
      }
      else 
      {
         board[x][y] = PLAYER2;
         break;
      }
   } while (board[x][y] != ' ');
};

char checkWinner()
{
   //check rows
   for (int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }

   //check columns
   for (int i = 0; i < 3; i++)
   {
       if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }

   //check diagonals 1
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }

   //check diagonal 2
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
};

void printWinner(char winner){
   if(winner == PLAYER1)
   {
      printf("PLAYER 1 WINS");
   }

   else if(winner == PLAYER2)
   {
      printf("PLAYER 2 WINS");
   }

   else 
   {
      printf("DRAW");
   }
};

