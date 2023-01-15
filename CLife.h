#define _CRT_SECURE_NO_WARNINGS

#pragma once

class CLife
{
private:
    int rows, cols;
    char** board;

public:

    CLife();
    void display();
    void update_board(char** board);
    int count_first_corner(int** board);
    int count_row_below(int** board, int x, int y);
    int count_second_corner(int** board, int rows, int cols);
    int count_third_corner(int** board, int rows, int cols);
    int count_fourth_corner(int** board, int rows, int cols);
    int count_upper_row(int** board, int x, int y);
    int count_right_cols(int** board, int x, int y);
    int count_left_cols(int** board, int x, int y);
    int count_middle(int** board, int x, int y);
    void change_coordinate(int x, int y, char ch);
    char** getBoard();
    void changeWidth(int w);
    void changeHeight(int h);
    int count_neighbors(char** board, int x, int y);
    void change_intensity(char** array);
    ~CLife();
};
