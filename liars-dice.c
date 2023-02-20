#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

//Global variables
int PLAYER1;
int PLAYER2;
int sum;
int x;
int y;
int prediction;

//Function declarations
void startGame();
void playerOneMove();
void playerTwoMove();
int rollDice();
int predictSum();
int checkTruth1(int, int);
int checkTruth2(int, int);
void showScore();
void showWinner();


int main()
{
   int rounds;
   char response;
   int round = 1;
   startGame();                        //Game Title
   printf("How many rounds?\n");       //Enter the number of rounds
   scanf("%d", &rounds);


   while (rounds > 0)                        //The rounds variable decrements after each round, so the game goes on as long as rounds > 0
   {
      printf("### Round %d ###", round);

      playerOneMove();                       //Player one makes a move
      int truth1 = rollDice();               //The sum of the dice is stored
      predictSum();                          //Player one tries to guess the sum
      checkTruth1(prediction, sum);          //Program checks if it's true by comparing the prediction to the actual answer
      printf("TRUTH: %d\n", truth1);         //The program then reveals the answer

      playerTwoMove();                       //Player one makes a move
      int truth2 = rollDice();               //The sum of the dice is stored
      predictSum();                          //Player one tries to guess the sum
      checkTruth2(prediction, sum);          //Program checks if it's true by comparing the prediction to the actual answer
      printf("TRUTH: %d\n\n", truth2);        //The program then reveals the answer


      rounds--;                              //The number of rounds remaining decrements after each play
      round++;                               //The round variable increases to keep track of the round
      printf("End of Round %d\n", round);
      showScore();                           //Display the results at the end of the round
   }
   showWinner();                             //Display the winner
   printf("\n\nType 'liar' to play again.");
   /*printf("Care for another game? (Y/N)" );
   scanf("%c", &response);*/

   return 0;
}


//Function Definitions
void startGame()                 //Game title
{
   printf("########## LIAR'S DICE ##########\n\n");
   printf("Press any key to continue.\n");
   getch();
}

void playerOneMove()             //Indicate Player 1's turn
{
   printf("\n\nPLAYER 1, READY?\n");
};

void playerTwoMove()            //Indicate Player 2's turn
{
   printf("\n\nPLAYER 2, READY?\n");
};

int rollDice()                //Generate two random numbers which we'll add to give our sum
{
   printf("Roll your Dice.\n");
   getch();
   srand(time(0));
   x = rand() % 7;
   y = rand() % 7;
   sum = x + y;
   return sum;
};

int predictSum()                     //Ask the player to predict their score
{
   printf("What's your guess?\n");
   scanf("%d", &prediction);
   printf("\nCall me a liar\n");
   return prediction;
};

int checkTruth1(int lie, int truth)    //Check the answer of Player 1
{
   int gap = lie - truth;
   printf("Let's see shall we?\n");
   getch();
   if (lie == truth)                   //If the sum and the prediction are equal, the player earns 3 points
   {
      printf("TRUTH\n");
      PLAYER1 += 3;
   }
   else if (abs(gap) == 1)             //If there's a difference of 1, the player earns a point
   {
      printf("Honest lie!\n");
      PLAYER1 += 1;
   }
   else 
   {
      printf("LIAR!\n");
   }
   return PLAYER1;
};

int checkTruth2(int lie, int truth)   //Check the answer of Player 2
{
   int gap = lie - truth;
   printf("Let's see shall we?\n");
   getch();
   if (lie == truth)                  //If the sum and the prediction are equal, the player earns 3 points
   {
      printf("TRUTH\n");
      PLAYER2 += 3;
   }
   else if (abs(gap)  == 1)          //If there's a difference of 1, the player earns a point
   {
      printf("Honest lie!\n");
      PLAYER2 += 1;
   }
   else 
   {
      printf("LIAR!\n");
   }
   return PLAYER2;
};

void showScore()    //Show the score at the end of each round
{
   printf("\n##### SCORES #####\n");
   printf("PLAYER 1: %d\n", PLAYER1);
   printf("PLAYER 2: %d\n", PLAYER2);
};

void showWinner()  //Check the winner at the end of the contest
{
   if (PLAYER1 > PLAYER2)
   {
      printf("PLAYER 1 wins!");
   }
   else if (PLAYER2 > PLAYER1)
   {
      printf("PLAYER 2 wins!");
   }
   else 
   {
      printf("DRAW!");
   }
};