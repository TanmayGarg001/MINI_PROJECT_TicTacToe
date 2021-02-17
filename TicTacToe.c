/*
Made by - Tanmay Garg.
Date -  17/1/2020
Tic Tac Toe using divide and conquering techniques.

Display tested on cmd(Command prompt) and powerShell .
Build and tested on Code::Blocks version_20.03

Debugged on VisualStudioCode
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int playerChoice, player;

int winCheck();
//returns 0 for draw
//returns 1 for game over and a win
//returns -1 for game in progress
void displayPlayField();
void markPlayField(char mark);

//Game-play function
int main()
{
   int statusOfTheGame;
   char mark;
   player = 1; // game starts from player 1.

   do
   {
      displayPlayField();
      player = (player % 2) ? 1 : 2; //oscillates between player turns ezpz :)
      printf("Plyer %d, enter a number to mark : ", player);
      scanf("%d", &playerChoice);

      mark = (player == 1) ? 'X' : 'O';

      markPlayField(mark);

      statusOfTheGame = winCheck();
      player++; //changes player turn.

   } while (statusOfTheGame == -1);
   if (statusOfTheGame == 1)
   {
      printf("Congratulations!! Player %d won the game!", --player);
   }
   else
   {
      printf("---DRAW---");
   }

   return 0;
}

int winCheck()
{

   int returnValue = 0; //initialize the case of draw

   if (square[1] == square[2] && square[2] == square[3])
   {
      returnValue = 1; //horizontal match
   }
   else if (square[4] == square[5] && square[5] == square[6])
   {
      returnValue = 1; //horizontal match
   }
   else if (square[7] == square[8] && square[8] == square[9])
   {
      returnValue = 1; //horizontal match
   }
   else if (square[1] == square[4] && square[4] == square[7])
   {
      returnValue = 1; //vertical match
   }
   else if (square[2] == square[5] && square[5] == square[8])
   {
      returnValue = 1; //vertical match
   }
   else if (square[3] == square[6] && square[6] == square[9])
   {
      returnValue = 1; //vertical match
   }
   else if (square[1] == square[5] && square[5] == square[9])
   {
      returnValue = 1; //diagonal match
   }
   else if (square[3] == square[5] && square[5] == square[7])
   {
      returnValue = 1; //diagonal match
   }
   else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
   {
      returnValue = 0; //draw
   }
   else
   {
      returnValue = -1; //continues the game
   }
   return returnValue;
}

void displayPlayField()
{

   system("cls"); //clears the screen
   printf("\n\n                                                      Tic Tac Toe\n\n");
   printf("                                                Player 1(X) || Player 2(O)\n\n");

   printf("                                                         |     |     \n");
   printf("                                                      %c  |  %c  |  %c  \n", square[1], square[2], square[3]);

   printf("                                                    _____|_____|_____\n");
   printf("                                                         |     |     \n");

   printf("                                                      %c  |  %c  |  %c  \n", square[4], square[5], square[6]);
   printf("                                                    _____|_____|_____\n");
   printf("                                                         |     |     \n");

   printf("                                                      %c  |  %c  |  %c  \n", square[7], square[8], square[9]);
   printf("                                                         |     |     \n\n");
}

void markPlayField(char mark)
{
   if (playerChoice == 1 && square[1] == '1')
   {
      square[1] = mark;
   }
   else if (playerChoice == 2 && square[2] == '2')
   {
      square[2] = mark;
   }
   else if (playerChoice == 3 && square[3] == '3')
   {
      square[3] = mark;
   }
   else if (playerChoice == 4 && square[4] == '4')
   {
      square[4] = mark;
   }
   else if (playerChoice == 5 && square[5] == '5')
   {
      square[5] = mark;
   }
   else if (playerChoice == 6 && square[6] == '6')
   {
      square[6] = mark;
   }
   else if (playerChoice == 7 && square[7] == '7')
   {
      square[7] = mark;
   }
   else if (playerChoice == 8 && square[8] == '8')
   {
      square[8] = mark;
   }
   else if (playerChoice == 9 && square[9] == '9')
   {
      square[9] = mark;
   }

   else
   {
      printf("Invalid move !!");
      player--;
      getch(); //pauses the program and wait for enter
   }
}
