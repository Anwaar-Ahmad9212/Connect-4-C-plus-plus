#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
/*This program uses  switch case to perform 5 functions which acts as a menu driven program*/
using namespace std;
const int row = 6;
const int column = 7;
int turn_player1, turn_player2, total_turn, player, win = 0, tie = 0;
char board[row][column] = { }; string name1, name2;

/*globally declared variable used in whole code*/
void game();
int check(int& current_player, int& win, int& tie);/*function declare*/
// game is playing here
void game()
{
	win = 0, tie = 0;
	//srand(time(NULL));
	cin.ignore();
	cout << "Enter first character name: ";
	string num1, num2;
	getline(cin, num1);
	cout << "Enter second character name: ";
	getline(cin, num2);
	int num = 0, begin;
	num = rand() % 15;
	// array intializations
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			board[i][j] = { ' ' };
		}
	}
	// toss winning conditions
	if (num % 2 == 0)
	{
		cout << num1 << " you win the toss!" << endl;
		begin = 1;
	}
	else
	{
		cout << num2 << " you win the toss!" << endl;
		begin = 0;
	}
	player = 0;
	turn_player1 = 0; turn_player2 = 0;
	do
	{
		if (begin == 1)
		{
			cout << "Its your turn " << num1 << endl;
			cout << "Your color is blue" << endl;
			begin = 0;
			turn_player1++;
			player = 1;
			total_turn++;
		}
		else
		{
			cout << "Its your turn " << num2 << endl;
			cout << "Your color is red" << endl;
			begin = 1;
			turn_player2++;
			player = 2;
			total_turn++;
		}
		// call the check function
		check(player, win, tie);
		if (win == 1)
		{
			break;
		}
		if (tie == 1)
		{
			break;
		}
	} while (true);
	// output the winner name
	if (win == 1)
	{
		if (player == 1)
		{
			name1 = num1;
			cout << num1 << " you are winner!!" << endl;
			cout << " 1      2      3     4      5      6      7" << endl;
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < column; ++j)
				{
					cout << board[i][j] << "   |  ";
				}
				cout << endl;
				cout << "-----------------------------------------------" << std::endl;
			}
		}
		else
		{
			name2 = num2;
			cout << num2 << " you are winner!!" << endl;
			cout << " 1      2      3     4      5      6      7" << endl;
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < column; ++j)
				{
					cout << board[i][j] << "   |  ";
				}
				cout << endl;
				cout << "-----------------------------------------------" << std::endl;
			}
		}
	}
	else
	{
		if (tie == 1)
		{
			cout << "Match is tie no one win!" << endl;
			cout << "Total turns of " << num1 << "  &  " << num2 << " = " << total_turn << endl;
		}

	}
}
// check function define 
int check(int& current_player, int& win, int& tie)
{
	char current_color;
	if (current_player == 1)
	{
		current_color = 'B';
	}
	else
	{
		current_color = 'R';
	}
	cout << " 1      2      3     4      5      6      7" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << board[i][j] << "   |  ";
		}
		cout << endl;
		cout << "-----------------------------------------------" << std::endl;
	}

	int current_row = 0, current_column = 0;
	int col, filled = 0;
	while (true)
	{
		cout << "Select the column between\n1 to " << column << endl;
		int num = 0;
		cin >> num;
		col = num - 1;
		if (col >= 0 && col <= 6)
		{
			break;
		}
		else
		{
			cout <<
				"Invalid!" << endl;
		}
	}
	int j = col;
	for (int i = row - 1; i >= 0; --i)
	{
		if (board[i][j] == 32)
		{
			if (current_player == 1)
			{
				board[i][j] = 'B';
			}
			else
			{
				board[i][j] = 'R';
			}
			current_row = i;
			current_column = j;
			filled++;
			break;
		}

	}
	int horizontal_right = 0, horizontal_left = 0, vertical = 0, diagonal_forward = 0, diagonal_backward = 0;
	// horizatol right
	bool right = true;
	for (int i = 0; i < 4; i++)
	{
		if (right == true)
		{
			for (int z = row - 1; z > 0; --z)
			{
				if (board[current_row][current_column] == board[z][column - 3] || board[current_row][current_column] == board[z][column - 4] ||
					board[current_row][current_column] == board[z][column - 5] || board[current_row][current_column] == board[z][column - 6])
				{
					horizontal_right++;
					right = false;
				}
			}
		}
		if (board[current_row][current_column + i] == current_color)
		{
			horizontal_right++;
		}
		else
		{
			break;
		}
	}
	// horizatol left
	bool left = true;
	for (int i = 0; i < 4; i++)
	{
		if (left == true)
		{
			for (int z = row - 1; z > 0; --z)
			{
				if (board[current_row][current_column] == board[z][column - 5] || board[current_row][current_column] == board[z][column - 4] ||
					board[current_row][current_column] == board[z][column - 3] || board[current_row][current_column] == board[z][column - 2])
				{
					horizontal_left++;
					left = false;
				}
			}
		}
		if (board[current_row][current_column - i] == current_color)
		{
			horizontal_left++;
		}
		else
		{
			break;
		}
	}
	// vertical check
	for (int i = 0; i < 4; i++)
	{
		if (board[current_row + i][current_column] == current_color)
		{
			vertical++;
		}
		else
			break;
	}
	// diagonal forward
	for (int i = 0; i < 4; i++)
	{
		if (board[current_row + i][current_column + i] == current_color)
		{
			diagonal_forward++;
		}
		else
		{
			break;
		}
	}
	//diagonal backward
	for (int i = 0; i < 4; i++)
	{
		if (board[current_row + i][current_column - i] == current_color)
		{
			diagonal_backward++;
		}
		else
		{
			break;
		}
	}
	// check the above conditions 
	if (horizontal_left == 4 || vertical == 4 || diagonal_forward == 4 || horizontal_right == 4 || diagonal_backward == 4)
	{
		win = 1;
		return win;
	}
	if (filled == 42)
	{
		tie = 1;
		return tie;
	}
}
// main function
int main()
{
	srand(time(NULL));
	while (true)
	{
		cout << setw(50) << "---------------- Welcome to connect four -----------------" << endl;
		cout << "Please select an option: " << endl;
		cout << "1. Play Game " << endl << "2. Credits" << endl << "3. Instructions" << endl << "4. Record" << endl << "5. Exit " << endl;
		int select;
		cin >> select;
		// switch case for manu driven
		switch (select)
		{
		case 1:
			cout << "Let's begin!" << endl;
			game();
			break;
		case 2:
			cout << "Credits: " << endl;
			cout << "This game is created with Hardwork by " << endl;
			
			break;
		case 3:
			cout << " Instructions " << endl;
			cout << "Players take turns to drop one of their colored colors into any of the seven columns." << endl << "The color will then occupy the lowest available empty space within that column.The game is played on a 6x7 grid(6 rows and 7 columns)" << endl << "Traditionally, one player is assigned 'R' and the other 'B' " << endl << "The goal is to connect four of your own colors in a row either horizontally, vertically, or diagonally before your opponent does" << endl << "Horizontal Connection : Connect four colors of the same color in a horizontal row" << endl << "Vertical Connection : Connect four colors of the same color in a vertical column." << endl << "Diagonal Connection : Connect four colors of the same color diagonally" << endl;
			cout << "Players must choose a column where there is an available space(i.e., the column is not already full)." << endl;
			cout << "Invalid moves(such as choosing a full column) result in the player losing their turn.The game ends when one player successfully connects four colors and wins the game." << endl;
			cout << "If the grid is completely filled, and no player has connected four colors, the game is a draw.Players take turns dropping one color at a time." << endl;
			cout << "The first player to connect four colors wins, and the game ends immediately " << endl;
			break;
		case 4:
		{
			if (win == 1)
			{
				if (player == 1)
				{
					cout << "Number of taken by " << name1 << "is : " << turn_player1 << endl;
				}
				else
				{
					cout << "Number of taken by " << name2 << "is : " << turn_player2 << endl;
				}
			}
			else
			{
				if (tie == 1)
				{
					cout << "The number of turns taken by " << name1 << " & " << name2 << " " << "is : " << total_turn;
				}
			}
			name1 = {}, name2 = {};
		}
		break;
		case 5:
			cout << "Goodbye: ";
			break;
		default:
			cout << "Wrong option selected." << endl;
			continue;
		}

		if (select == 5)
		{
			break;
		}
		else
		{
			cout << "Do you want to continue?\n enter YES if not enter NO " << endl;
			string choice = {};
			cin >> choice;
			if (choice == "Yes" || choice == "yes")
			{
				continue;
			}
			else
			{
				cout << "Thanks" << endl; break;
			}
		}
	}
	system("pause");
	return 0;
}
