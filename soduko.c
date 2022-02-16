
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define SIZE 9
#define LINE 3
void main();
void createBoard (char*, char*);
void printBoard (char*);
int testBoard(char*);
void completeBoard(char*);


void completeBoard(char board[SIZE][SIZE]) {
	int sum;
	int maxsum;
	int counter = 0;
	int j, posirow, posiamoda;
	int x = 1;
	while (x!=0) {
		for (int i = 0; i < SIZE; i++) {
			counter = 0;
			sum = 477;
			for (j = 0; j < SIZE; j++) {
				if (board[i][j] == '_') {
					counter++;
					posirow = i, posiamoda = j;
					continue;
				}
				else sum -= (board[i][j]);
			}
			char c =  sum;
			if (counter == 1) board[posirow][posiamoda] =  sum;
		}
	
		
		for (int i = 0; i < SIZE; i++) {
			counter = 0;
			sum = 477;
			for (j = 0; j < SIZE; j++) {
				if (board[j][i] == '_') {
					counter++;
					posirow = j, posiamoda = i;
					continue;
				}
				else sum -= board[j][i];
			}
			if (counter == 1) board[posirow][posiamoda] =sum;
		}
		
		for (int x = 0; x < LINE; x++) {
			for (int y = 0; y < LINE; y++) {
				counter = 0;
				sum = 477;
				for (int i = (x * LINE); i < (x + 1) * LINE; i++) {
					for (int j = (y * LINE); j < (y + 1) * LINE; j++) {
						if (board[i][j] == '_') {
							counter++;
							posirow = i, posiamoda = j;
							continue;
						}
						else sum -= board[i][j];
					}
				}
				if (counter == 1) board[posirow][posiamoda] = sum;
			}
		}
		 maxsum = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				maxsum += (board[i][j]);
			}
		}
		if (maxsum == (477 * SIZE))x = 0;
	}	
return;
	
}

int testBoard(char board[SIZE][SIZE]) {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE - 2; j++) {
			if (board[i][j] == '_') continue;
			for (int z = j + 1; z < SIZE - 1; z++) {
				if (board[i][z] == '_') continue;
				if (board[i][j] == board[i][z]) return 0;
			}
		}
	}
	for (int i = 0; i < SIZE-2; i++) {
		for (int j = 0; j < SIZE ; j++) {
			if (board[j][i] == '_') continue;
			for (int z = i + 1; z < SIZE - 1; z++) {
				if (board[j][z] == '_') continue;
				if (board[j][i] == board[j][z]) return 0;
			}
		}
	}
	for (int x = 0; x < LINE; x++)	{
		for (int y = 0; y < LINE; y++)	{
			for (int i = (x*LINE); i < (x+1)*LINE; i++)	{
				for (int j = (y*LINE); j < (y+1)*LINE; j++)	{
					if (board[i][j] == '_')continue;
					for (int i2 = i; i2 < LINE; i2++)	{
						for (int j2 = j; j2 < LINE; j2++)	{
							if (i == i2 && j == j2) continue;
							if (board[i][j] == board[i2][j2])return 0;
						}
					}
				}
			}
		}
	}
	return 1;

}
	
void printBoard(char board[SIZE][SIZE]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%c  ", board[i][j]);
		}
		printf("\n");
	}
}
void createBoard(char board[SIZE][SIZE], char str[]) {
	int len = strlen(str);
	int x = 0, counter = 0;
	int i, j;
	for ( i = 0; i < SIZE; i++)	{
		for ( j = 0; j < SIZE; j++) {
			counter++;
			if (str[x] == 'A' || str[x] == 'a') {
				board[i][j] = '_';
				x++;
			}
			else if (str[x] == 'B' || str[x] == 'b') {
				board[i][j] = '_';
				str[x] = 'A';
			}
			else if (str[x] == 'C' || str[x] == 'c') {
				board[i][j] = '_';
				str[x] = 'b';
			}
			else if (x == len )
				board[i][j] = '_';
			else board[i][j] = str[x++];
			if (counter == 81 && x < len ) {
				printf("the string is incorect - too long\n");
				return;
			}
		}
	}
	printBoard(board);
	return;
}

void main()
{
	printf("this masterpiece made by TOMER YAISH\n  enjoy!\n");
	char str[] = "91a78a365a85a16792726593b889a6a754a4a3a5187957194823a1b32965a2a716a98363a875124";
	char board[SIZE][SIZE];
	createBoard(board, str);
	int flag = testBoard (board);
	(flag == 0) ? printf("the board is  incorrect\n") : printf("the board is just fine :)\n now we fill it with the charm numbers\n");
	completeBoard(board);
	for (int i = 0; i < SIZE; i++)  {
		for (int j = 0; j < SIZE; j++)	{
			printf("%c  ", board[i][j]);
		}
		printf("\n");
	}
	printf("IT'S DONE!! man this code looks amazing!\n\n");
}	