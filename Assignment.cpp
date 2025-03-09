#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[10][10];
int replayMove[100];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

int menu();
int menuBot();
void playVersus();
void playBot();
void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Move();
void player2Move();
void computerMove();
char checkWinner(char);
void printWinner(char);
void printWinner2(char);
void replay();
void playerInfo();
void guild();

int main()
{
   int i=0, userChoice;
   while(i==0)
   {
   do
   { 
     system("cls");
	 userChoice = menu();
     switch (userChoice)
     {
    	case 1:
			playVersus();
    		break;
    	case 2:
    		int botChoice;
			while(i==0)
    		{
			  do
			  {
    		    system("cls");
				botChoice = menuBot();
    		    switch (botChoice)
    		    {
    		    	case 1:
						playBot();
    				    break;
    			    case 2:
    				    playBot();
    				    break;
    			    case 3:
    				    playBot();
					    break;
    			    case 4:
    				    i++;
    				    botChoice++;
    				    printf("\n");
    				    break;
			    }
			  }
			  while(botChoice>0 && botChoice<5);
			}
			i--;
			break;
    	case 3:
    		replay();
    		break;
    	case 4:
    		playerInfo();
    		break;
    	case 5:
    		guild();
    		break;
    	case 6:
    		printf("\nGoodbye!\n\033[0m");
    		return 0;
	 }
   }
   while (userChoice>0 && userChoice<7);
   printf("\n");
   }
}
int menu()
{
	int choice;
	do
	{
	fflush(stdin);
	system("cls");
	printf("\033[1;33m*-------\033[0mMAIN MENU\033[1;33m-------*\n");
	printf("\033[1;31m1.Play\033[0m with Other Player\n");
	printf("\033[1;31m2.Play\033[0m with Bot\n");
	printf("\033[1;31m3.Replay\n");
	printf("\033[1;31m4.Player's\033[0m Information\n");
	printf("\033[1;31m5.Guild\n");
	printf("\033[1;31m6.Exit\n");
	printf("\033[0mPress number to choice: \033[1;31m");
	scanf("%d",&choice);
	}
	while(choice>6||choice<1);
	return choice;
}
int menuBot()
{
	int choice;
	do
	{
	fflush(stdin);
	system("cls");
	printf("\033[1;33m*-------\033[0mPlay with BOT\033[1;33m-------*\n");
	printf("\033[1;31m1.Easy\033[0m Mode\n");
	printf("\033[1;31m2.Normal\033[0m Mode\n");
	printf("\033[1;31m3.Hard\033[0m Mode\n");
	printf("\033[1;31m4.Back\033[0m to MAIN MENU\n");
	printf("\033[0mPress number to choice: \033[1;31m");
	scanf("%d",&choice);
	}
	while(choice>4||choice<1);
	return choice;
}
void playVersus()
{
   printf("\n");
   char winner,response;

   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         system("cls");
		 printf("\033[1;33m=>\033[0m Player\033[1;31m 1 \033[1;33m=\033[0m X\033[1;33m, \033[0mPlayer\033[1;31m 2 \033[1;33m=\033[0m O\033[1;33m:\n\n");
		 printBoard();
         player1Move();
         printf("\033[1;33m=>\033[0m Player\033[1;31m 1 \033[1;33m=\033[0m X\033[1;33m, \033[0mPlayer\033[1;31m 2 \033[1;33m=\033[0m O\033[1;33m:\n\n");
		 system("cls");
		 printf("\033[1;33m=>\033[0m Player\033[1;31m 1 \033[1;33m=\033[0m X\033[1;33m, \033[0mPlayer\033[1;31m 2 \033[1;33m=\033[0m O\033[1;33m:\n\n");
		 printBoard();
         winner = checkWinner('X');
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
         player2Move();
         winner = checkWinner('O');
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      
      printWinner2(winner); 
	  printf("\n\033[0mWould you like to play again? (Y/N)\033[1;33m:\033[1;31m ");
      scanf("%c");
      scanf("%c", &response);
      response = toupper(response);
   } while (response == 'Y');

   printf("\n\033[0mThanks for playing!\n\n");
   system("pause");
}
void playBot()
{
   printf("\n");
   char winner,response;

   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         system("cls");
		 printf("\033[1;33m=>\033[0m Player\033[1;31m 1 \033[1;33m=\033[0m X\033[1;33m, \033[0mComputer \033[1;33m=\033[0m O\033[1;33m:\n\n");
		 printBoard();
         player1Move();
         winner = checkWinner('X');
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         computerMove();
         winner = checkWinner('O');
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }
      printf("\033[1;33m=>\033[0m Player\033[1;31m 1 \033[1;33m=\033[0m X\033[1;33m, \033[0mComputer \033[1;33m=\033[0m O\033[1;33m:\n\n");
      printBoard();
      printWinner(winner); 
	  printf("\n\033[0mWould you like to play again? (Y/N)\033[1;33m:\033[1;31m ");
      scanf("%c");
      scanf("%c", &response);
      response = toupper(response);
   } while (response == 'Y');

   printf("\n\033[0mThanks for playing!\n\n");
   system("pause");
}
void resetBoard()
{
   for(int i = 0; i < 10; i++)
   {
      for(int j = 0; j < 10; j++)
      {
         board[i][j] = ' ';
      }
   }
}
void printBoard()
{
   printf("\033[1;31m    0   1   2   3   4   5   6   7   8   9");
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m0 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7], board[0][8], board[0][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m1 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7], board[1][8], board[1][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m2 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7], board[2][8], board[2][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m3 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7], board[3][8], board[3][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m4 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7], board[4][8], board[4][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m5 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7], board[5][8], board[5][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m6 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7], board[6][8], board[6][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m7 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7], board[7][8], board[7][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m8 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[8][6], board[8][7], board[8][8], board[8][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n");
   printf("\033[1;31m9 \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m| \033[0m%c \033[1;33m|", board[9][0], board[9][1], board[9][2], board[9][3], board[9][4], board[9][5], board[9][6], board[9][7], board[9][8], board[9][9]);
   printf("\n\033[1;33m  |---|---|---|---|---|---|---|---|---|---|\n\n");
}
int checkFreeSpaces()
{
   int freeSpaces = 100;

   for(int i = 0; i < 10; i++)
   {
      for(int j = 0; j < 10; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void player1Move()
{
   int x, y;
   do
   {
      do
      {
      	fflush(stdin);
		printf("\033[0mPlayer\033[1;31m 1's \033[0mturn\033[1;33m:\033[1;31m ");
	    scanf("%d%d", &x, &y);
	  }
	  while((x>9||x<1)&&(y>9||y<1));
      printf("\n");
      if(board[x][y] != ' ')
      {
         printf("\033[0mInvalid move!\n\n");
      }
      else
      {
         board[x][y] = PLAYER1;
         break;
      }
   } while (board[x][y] != ' ');
   
}
void player2Move()
{
   int x, y;

   do
   {
      do
      {
      	fflush(stdin);
		printf("\033[0mPlayer\033[1;31m 2's \033[0mturn\033[1;33m:\033[1;31m ");
	    scanf("%d%d", &x, &y);
	  }
	  while((x>9||x<1)&&(y>9||y<1));
      printf("\n");
      if(board[x][y] != ' ')
      {
         printf("\033[0mInvalid move!\n\n");
      }
      else
      {
         board[x][y] = PLAYER2;
         break;
      }
   } while (board[x][y] != ' ');
   
}
void computerMove()
{
   //creates a seed based on current time
   srand(time(0));
   int x, y;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 10;
         y = rand() % 10;
      } while (board[x][y] != ' ');
      
      board[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}
char checkWinner(char move)
{
   char token = move;
   //check rows
   for(int i = 0; i < 10; i++)
      for(int j = 0; j < 6; j++)
      	if(token == board[i][j] && token == board[i][j+1] && token == board[i][j+2] && token == board[i][j+3] && token == board[i][j+4])
		   return token;
    //check columns
   for(int i = 0; i < 6; i++)
      for(int j = 0; j < 10; j++)
	     if(token == board[i][j] && token == board[i+1][j] && token == board[i+2][j] && token == board[i+3][j] && token == board[i+4][j])
		   return token;
   //check diagonals 1
   for(int i = 4; i < 10; i++)
      for(int j = 0; j < 6; j++)
	     if(token == board[i][j] && token == board[i-1][j+1] && token == board[i-2][j+2] && token == board[i-3][j+3] && token == board[i-4][j+4])
		  return token;
   //check diagonals 2
   for(int i = 0; i < 6; i++)
      for(int j = 0; j < 6; j++)
	    if(token == board[i][j] && token == board[i+1][j+1] && token == board[i+2][j+2] && token == board[i+3][j+3] && token == board[i+4][j+4])
		  return token;
   return ' ';
}
void printWinner(char winner)
{
   if(winner == PLAYER1)
   {
      printf("\033[1;31mYOU WIN!\n");
   }
   else if(winner == COMPUTER)
   {
      printf("\033[1;31mYOU LOSE!\n");
   }
   else{
      printf("\033[1;31mIT'S A TIE!\n");
      }
}
void printWinner2(char winner)
{
   if(winner == PLAYER1)
   {
      printf("\033[1;31mPLAYER 1 WIN!\n");
   }
   else if(winner == PLAYER2)
   {
      printf("\033[1;31mPLAYER 2 WIN!\n");
   }
   else{
      printf("\033[1;31mIT'S A TIE!\n");
      }
}
void replay()
{
	printf("\n\033[0mPlease scroll up and scroll down again\n\n");
	system("pause");
}
void playerInfo()
{
	printf("\n\033[1;31mPlayer's Name: \033[0mEchorio\n");
	printf("\033[1;31mRank: \033[0m1st\n");
	printf("\033[1;31mWins: \033[0m69\n");
	printf("\033[1;31mLosses: \033[0m0\n\n");
	system("pause");
	printf("\n");
}
void guild()
{
	printf("\n\033[1;31mGuild's Name: \033[0mASC's Hood\n");
	printf("\033[1;31mRank: \033[0m1st\n");
	printf("\033[1;31mTotal Wins: \033[0m6969\n");
	printf("\033[1;31mTotal Losses: \033[0m251\n\n");
	system("pause");
	printf("\n");
}
