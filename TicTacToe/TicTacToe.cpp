#include <iostream>
using namespace std;

bool isWon(char player, char board[3][3]);
bool isDraw(char board[3][3]);
void displayBoard(char board[3][3]);
void makeAMove(char board[3][3], char player);

int main() {

	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);
	//Start the game
	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}

void makeAMove(char board[3][3], char player) {
	int row;
	int col;

	//Prompt the player to enter a valid row number
	cout << "Enter a row (0, 1, 2) for player " << player << "   : ";
	while (!(cin >> row) || (row != 0 && row != 1 && row != 2)) {
		cout << "Enter a row (0, 1, 2) for player " << player << "   : ";
		cin.clear();
		cin.ignore(10000, '\n');
	}


	//Prompt the player to enter a valid column number
	cout << "Enter a column (0, 1, 2) for player " << player << ": ";
	while (!(cin >> col) || (col != 0 && col != 1 && col != 2)) {
		cout << "Enter a column (0, 1, 2) for player " << player << ": ";
		cin.clear();
		cin.ignore(10000, '\n');
	}

	//If the cell is already marked, ask player to mark a different cell
	while (board[row][col] == 'X' || board[row][col] == 'O') {
		cout << "This cell is already occupied. Try a different cell.\n" << endl;
		cout << "Enter a row (0, 1, 2) for player " << player << "   : ";
		while (!(cin >> row) || (row != 0 && row != 1 && row != 2)) {
			cout << "Enter a row (0, 1, 2) for player " << player << "   : ";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "Enter a column (0, 1, 2) for player " << player << ": ";
		while (!(cin >> col) || (col != 0 && col != 1 && col != 2)) {
			cout << "Enter a column (0, 1, 2) for player " << player << ": ";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	//Mark the cell on the board based on player's choice
	board[row][col] = player;

}

void displayBoard(char board[3][3]) {

	//Iterate through the entire 2D array to display the board
	for (int row = 0; row < 3; row++) {
		cout << endl << "-------------" << endl;
		cout << "| ";
		for (int col = 0; col < 3; col++) {
			cout << board[row][col] << " | ";
		}
	}
	cout << endl << "-------------" << endl;
}

bool isDraw(char board[3][3]) {

	//Return false if any of the board slots are empty 
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (board[row][col] == ' ')
				return false;
		}
	}
	//Draw if the entire board is filled
	return true;
}

bool isWon(char player, char board[3][3]) {
	bool won = false;
	//Player wins if there are 3 marks in a row horizontally
	for (int row = 0; row < 3; row++) {
		int horizontal = 0;
		for (int col = 0; col < 3; col++) {
			if (board[row][col] == player)
				horizontal++;
			if (horizontal == 3)
				won = true;
		}
	}
	//Player wins if there are 3 marks in a row vertically
	for (int col = 0; col < 3; col++) {
		int vertical = 0;
		for (int row = 0; row < 3; row++) {
			if (board[row][col] == player)
				vertical++;
			if (vertical == 3)
				won = true;
		}
	}
	//Player wins if there are 3 marks diagonally 
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
		(board[2][0] == player && board[1][1] == player && board[0][2] == player))
		won = true;

	return won;
}