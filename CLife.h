

#pragma once

class CLife
{
private:
    int rows, cols;
    char** board;

public:

    CLife();
    void display();
    void update_board(char **board);
    int count_first_corner(int board[20][20]);
    int count_row_below(int board[20][20], int x, int y);
    int count_second_corner(int board[20][20], int rows, int cols);
    int count_third_corner(int board[20][20], int rows, int cols);
    int count_fourth_corner(int board[20][20], int rows, int cols);
    int count_upper_row(int board[20][20], int x, int y);
    int count_right_cols(int board[20][20], int x, int y);
    int count_left_cols(int board[20][20], int x, int y);
    int count_middle(int board[20][20], int x, int y);
    void change_coordinate(int x, int y,char ch);
    char** getBoard();
    int count_neighbors(char **board, int x, int y);
    void change_intensity(char** array);
    ~CLife();
};
