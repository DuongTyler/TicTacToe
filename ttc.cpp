#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class Board
{
	public:
		Board()
		{}
		
		char getPiece(int x, int y)
		{
			return board[x][y];
		}

		int getTurn()
		{
			return turn;
		}

		bool checkWin()
		{
			for (int x = 0; x < 3; x++)
				if ( board[0][x] != ' ' && board[0][x] == board[1][x] && board[1][x] == board[2][x] )		return true;
			for (int y = 0; y < 3; y++)
				if ( board[y][0] != ' ' &&  board[y][0] == board[y][1] && board[y][1] == board[y][2] )		return true;
			if ( board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] )			return true;
			if ( board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0] )			return true;
			return false;
		}

		void setPiece(int x, int y)
		{
			if ( board[y][x] == ' ')
			{
				switch (turn%2)
				{
					case 0:
						board[y][x] = 'X';
						break;
					case 1:
						board[y][x] = 'O';
						break;
				}
				turn++;
			}
			else
			{
				printf("Space already taken, try again\n");
			}
		}

		void print()
		{
			
			for (int y = 2; y >= 0; y--)
			{
				for (int x = 0; x < 3; x++)
				{
					printf(" %c ", board[y][x]);
					
					if (x < 2)	printf("|");
				else		printf(" %d", y+1);
				}
				if ( y != 0 )	printf("\n===========");
				printf("\n");
			}
			printf(" 1   2   3\n\n");

		}

	private:
		int turn = 0;
		char board[3][3] = {
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
		};
};


int main()
{
	Board *b = new Board();

	bool won = false;
	while (!won && b -> getTurn() < 9)
	{
		b -> print();
		switch (b -> getTurn()%2)
		{
			case 0:
				printf("Turn: X\n", b -> getTurn());
				break;
			case 1:
				printf("Turn: O\n", b -> getTurn());
				break;
		}
		int x;
		int y;
		printf("X: ");
		std::cin >> x;
		printf("Y: ");
		std::cin >> y;
		b -> setPiece(x-1,y-1);
		printf("\n\n");
		won = b -> checkWin();
	}

	if (b -> getTurn() < 9)		printf("Winning player: Player %d\n", (b -> getTurn() - 1) %2);
	else				printf("Cat's Game!\n");
	b -> print();
	
	delete b;
}
