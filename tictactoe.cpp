#include <iostream>
using namespace std;
void drawBoard(char board[3][3])
{
	cout << "-------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "| ";
			for (int j = 0; j < 3; j++)
			{
				cout << board[i][j] << " | ";
		}
			cout << "\n----------------\n" << endl;
	}
}



bool CheckWinner(char board[3][3],char player) {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player
			&& board[i][2] == player)
			return true;
		if (board[0][i] == player && board[1][i] == player
			&& board[2][i] == player)
			return true;
	}
	if (board[0][0] == player && board[1][1] == player
		&& board[2][2] == player)
		return true;
	if (board[0][2] == player && board[1][1] == player
		&& board[2][0] == player)
		return true;
	return false;
}


int main() {
	cout << R"(
 █████                                               ██            ███████████ ███████████ ███████████
░░███                                               ███           ░█░░░███░░░█░█░░░███░░░█░█░░░███░░░█
 ░███ █████  ██████   ██████  ████████   █████ ████░░░   █████    ░   ░███  ░ ░   ░███  ░ ░   ░███  ░ 
 ░███░░███  ███░░███ ███░░███░░███░░███ ░░███ ░███      ███░░         ░███        ░███        ░███    
 ░██████░  ░███████ ░███████  ░███ ░███  ░███ ░███     ░░█████        ░███        ░███        ░███    
 ░███░░███ ░███░░░  ░███░░░   ░███ ░███  ░███ ░███      ░░░░███       ░███        ░███        ░███    
 ████ █████░░██████ ░░██████  ████ █████ ░░████████     ██████        █████       █████       █████   
░░░░ ░░░░░  ░░░░░░   ░░░░░░  ░░░░ ░░░░░   ░░░░░░░░     ░░░░░░        ░░░░░       ░░░░░       ░░░░░    
                                                                                                      
                                                                                                      
                                                                                                      

)" << endl;
	int col, row, turn;
	bool active = true;
	char player = 'X';
	char board[3][3] = {{' ', ' ', ' '}, { ' ', ' ', ' ' }, { ' ', ' ', ' ' }};
	drawBoard(board);

	for (turn = 0; turn < 9; turn++) 
	{
		while (active == true)
		{
			cout << "Player:" << player << endl;
			cout << "Pick a coordinate between(0,2) and (0,2)" << endl;
			cin >> col >> row;
			if (board[col][row] != ' ' || col < 0 || col>2 || row < 0 || row>2)
			{
				cout << "Invalid Responce..." << endl;
			}
			else
			{
				break;
			}
		}

		board[col][row] = player;
		if(CheckWinner(board,player)==true)
		{
			cout << "Player " << player << "Wins!" << endl;
			break;
		}
		drawBoard(board);
		if (player == 'X')
		{
			player = 'O';
		}
		else
		{
			player = 'X';
		}
	}

	return 0;
}
