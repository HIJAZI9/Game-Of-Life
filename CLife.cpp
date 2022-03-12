#include<iostream>
using namespace std;

#include "CLife.h"
#include<time.h>

CLife::CLife()  //Default constructor
{

	cols = 20;
	rows = 20;
	board = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		board[i] = new char[20];
	}
	int nr;
	const int max = 1, min = 0;
	srand(time(NULL));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			nr = (rand() % (max - min + 1)) + min;
			board[i][j] = nr;
		}
	}
}

int CLife::count_first_corner(int board[20][20]) {
	return board[0][1] + board[1][1] + board[1][0];
}

int CLife::count_row_below(int board[20][20], int x, int y) {
	return board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1];
}

int CLife::count_second_corner(int board[20][20], int rows, int cols) {
	return board[0][cols - 2] + board[1][cols - 2] + board[1][cols - 1];
}
int CLife::count_third_corner(int board[20][20], int rows, int cols) {
	return board[rows - 1][1] + board[rows - 2][0] + board[rows - 2][1];
}
int CLife::count_fourth_corner(int board[20][20], int rows, int cols) {
	return board[rows - 1][cols - 2] + board[rows - 2][cols - 1] + board[rows - 2][cols - 2];
}

int CLife::count_upper_row(int board[20][20], int x, int y) {
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1];
}

int CLife::count_right_cols(int board[20][20], int x, int y) {
	return board[x - 1][y + 1] + board[x][y + 1] + board[x + 1][y + 1];
}
int CLife::count_left_cols(int board[20][20], int x, int y) {
	return board[x - 1][y - 1] + board[x][y - 1] + board[x + 1][y - 1];
}
int CLife::count_middle(int board[20][20], int x, int y) {
	int row_below = count_row_below(board, x, y);
	int row_upper = count_upper_row(board, x, y);
	return row_below + row_upper + board[x][y - 1] + board[x][y + 1];
}
void CLife::update_board(char **board) {
	char result_board[20][20];
	int neighbors = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			result_board[i][j] = board[i][j];
		}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			neighbors = count_neighbors(board, i, j);
			if (board[i][j] == 1) {             //  wert 1 ist '*'
				if (neighbors < 2 || neighbors > 3) {
					result_board[i][j] = 0;
				}
			}
			else if (board[i][j] == 0) {        // der wert 0 ist ' '
				if (neighbors == 3) {
					result_board[i][j] = 1;
				}
			}
		}
	}


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = result_board[i][j];
		}
	}

}
int CLife::count_neighbors(char **board, int x, int y) {
	int neighbors = 0;
	int ones_board[20][20];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == 1)
				ones_board[i][j] = 1;
			else
				ones_board[i][j] = 0;
		}
	}

	if (x == 0) {
		if (y == 0) {
			neighbors = count_first_corner(ones_board);
		}
		else if (y == cols - 1) {
			neighbors = count_second_corner(ones_board, rows, cols);
		}
		else {
			neighbors = count_upper_row(ones_board, x, y);

		}

	}
	else if (x == rows - 1) {
		if (y == 0) {
			neighbors = count_third_corner(ones_board, rows, cols);
		}
		else if (y == cols - 1) {
			neighbors = count_fourth_corner(ones_board, rows, cols);
		}
		else {
			neighbors = count_row_below(ones_board, x, y);

		}
	}
	else {
		if (y == 0) {
			neighbors = count_right_cols(ones_board, x, y);
		}
		else if (y == cols - 1) {
			neighbors = count_left_cols(ones_board, x, y);
		}
		else {
			neighbors = count_middle(ones_board, x, y);
		}
	}
	return neighbors;
}


void CLife::display()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == 1) {

				cout << "*";

			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	update_board(board);
}

void CLife::change_coordinate(int x, int y, char ch)
{
	board[x][y] = ch=='*'?1:0;
}
void CLife::change_intensity(char** array) {
	//board = array;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = array[i][j];
		}
	}
	
	
}

char** CLife::getBoard()
{
	char**temp = new char* [20];
	for (int i = 0; i < 20; i++)
	{
		temp[i] = new char[20];
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			temp[i][j] = board[i][j];
		}
	}
	return temp;
}

CLife::~CLife() {

}




