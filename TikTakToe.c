/*
Description: <This program allows players to play similar to a tic tac toe game>
Programmed by: <Mata, Maria Sarah Althea; Ranada, Arianne M.> <S12>
Last modified: <April 8, 2023>
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Fuction Prototypes. These functions are later used in the program
void systemInitialization();
void posboard();
int nextPlayerMove(int, char);
int gameOver(char);
void startGame(char *p1, char *p2);
void playAgain();
int main();
//2D Array
char board[3][3];
/*This function show the peg values in the game board to guide the players
@param i and j are used as loop control variables
*/
void systemInitialization()
{
int i, j;
int count = 1;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
board[i][j] = ' ';
}
}
printf("\n\t ");
for(i = 0; i < 3; i++)
{
for(j = 0; j < 3; j++)
{
printf(" %d () ", count++);
if (j < 2)
{
printf(" | ");
}
}
if (i < 2)
printf("\n\t -----------------------------\n\t ");
}
printf("\n\n");
printf("\t (1,1) | (1,2) | (1,3)");
printf("\n\t ---------------------\n\t");
printf(" (2,1) | (2,2) | (2,3)");
printf("\n\t ---------------------\n\t");
printf(" (3,1) | (3,2) | (3,3)");
}
/*This function is called once a game is finished
@param choice gets the input from the use if should
they wish to play again or exit */
void playAgain()
{
int choice;
while (choice != 2)
{
printf("\n*************** MAIN MENU ****************\n");
printf("\n [1]Play Again");
printf("\n [2]Exit Game");
printf("\n\nEnter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
{
main();
break;
}
case 2:
{
printf("\nTHANKS FOR PLAYING!!");
exit(0);
break;
}
default:
{
printf("\nInvalid input! Please try again.\n");
}
}
}
}
/*This function shows the marked moved on the game board
@param i and j are used as loop control variables
@param count prints #1-9 in the peg board */
void posboard()
{
int i, j;
int count = 1;
printf("\n\n\t ");
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
printf(" %d", count++);
printf(" (%c)", board[i][j]);
if (j < 2)
{
printf(" | ");
}
}
if (i < 2)
printf("\n\t--------------------------------\n\t ");
}
printf("\n\n\n");
}
/*This function updates the game board for every move of the players
@param row and col determines which spot on the board is occupied
@return This function returns isValid to see if there are still moves to play */
int nextPlayerMove(int peg, char mark)
{
int row = (peg - 1) / 3;
int col = (peg - 1) % 3;
int isValid = 1;
// checking which pegs are occupied
if (board[row][col] != ' ')
{
printf("\nInvalid: Peg is already Filled!\n");
isValid = 0;
}
else
{
board[row][col] = mark;
}
posboard(row, col);
return isValid;
}
/*This function determines the winner of the game
@return 1 if there's a winner
@return 0 if there's no winner */
int gameOver(char k)
{
if (board[0][0] == k && board[0][1] == k && board[0][2] == k)
{
printf("Sum of row: 6\n");
printf("Peg: 1 + 2 + 3 = 6\n");
printf("6 < 15\n\n");
return 1;
}
else if (board[1][0] == k && board[1][1] == k && board[1][2] == k)
{
printf("Sum of row: 15\n");
printf("Peg: 4 + 5 + 6 = 15\n");
printf("15 = 15\n\n");
return 1;
}
else if (board[0][0] == k && board[1][0] == k && board[2][0] == k)
{
printf("Sum of column: 12\n");
printf("Peg: 1 + 4 + 7 = 12\n");
printf("12 < 15\n\n");
return 1;
}
else if (board[0][1] == k && board[1][1] == k && board[2][1] == k)
{
printf("Sum of column: 15\n");
printf("Peg: 2 + 5 + 8 = 15\n");
printf("15 = 15\n\n");
return 1;
}
else if (board[0][0] == k && board[1][1] == k && board[2][2] == k)
{
printf("Sum of diagonal: 15\n");
printf("Peg: 1 + 5 + 9 = 15\n");
printf("15 = 15\n\n");
return 1;
}
else if (board[0][2] == k && board[1][1] == k && board[2][0] == k)
{
printf("Sum of diagonal: 15\n");
printf("Peg: 3 + 5 + 7 = 15\n");
printf("15 = 15\n\n");
return 1;
}
return 0;
}
/*This functions starts the game and checks if there is a winner for every move
@param result checks if winning criteria is met of having 3 marks in a row
@param peg gets the move of the players
@param playCount refers to the total number of moves. Even play counts are for
player 1 and odd for player 2. This game has a total of 9 moves/plays
@param updationResult checks if the peg move is not yet filled/valid. If valid,
program proceeds to check if there's a winner
@param mark refers to the symbols X and O of the players or '' if peg is empty */
void startGame(char *p1, char *p2)
{
int result = 0;
int peg = 0;
int playCount = 0;
int updationResult = 1;
char mark = ' ';
while (!result && playCount < 9)
{
if (playCount % 2 == 0)
{
// player 1
printf("\nPlayer 1 %s [ X ] : ", p1);
mark = 'X';
}
else
{
// player 2
printf("\nPlayer 2 %s [ O ] : ", p2);
mark = 'O';
}
scanf("%d", &peg);
if (peg > 0 && peg < 10)
{
updationResult = nextPlayerMove(peg, mark);
if (updationResult)
{
result = gameOver(mark);
if (result)
{
printf("============> Player %d Won!! <============\n", mark ==
'X' ? 1 : 2);
}
playCount++;
}
}
else if (peg == 0)
{
printf("\n\tEND OF PLAY\n");
playAgain();
}
else
{
printf("\nPlease Enter a valid peg value\n");
}
}
if (!result && playCount == 9)
{
printf("\n-----------------> DRAW! <----------------\n");
}
printf("\n--------------> GAME OVER! <-------------- \n");
playAgain();
}
/*This function initializes the program
@param start gets the input from user to start or exit the program
@param p1 and p2 gets the names of the players */
int main()
{
int start = 1;
char p1[50], p2[50];
while (start != 0)
{
printf("\n************** Let's Play Tic Tac Toe! **************\n");
printf("\n\t\t INSTRUCTIONS: \n");
printf("\t\tPlayer 1 Symbol = X\n");
printf("\t\tPlayer 2 Symbol = O\n");
printf(" Winner is to get 3 marks in a row with sum < 15 or = 15.\n");
printf("\tIf sum of 3 marks is > 15, game continues.\n\n");
printf("\t\tThe game is a DRAW if:\n");
printf(" All 9 () are full and no 3 marks in a row sums to <=15.\n\n");
printf("\t\tPress [0] to EXIT\n");
printf("\t\tPress [1] to START\n");
printf("\n----------------> System Set Origin <----------------\n");
systemInitialization();
printf("\n-----------------------------------------------------\n");
printf("Enter your choice: ");
scanf("%d", &start);
fflush(stdout);
if (start == 0)
{
exit(0);
}
else if (start == 1)
{
printf("\nEnter Name of Player 1: ");
scanf("%s", p1);
printf("Enter Name of Player 2: ");
scanf("%s", p2);
startGame(p1, p2);
}
else
{
printf("\nInvalid input! Please try again.\n");
}
}
return 0;
}