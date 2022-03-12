#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "CLife.h"
#include<string>
class CUserInterface
{
private:
	int turns;
	CLife U;
	int ROWS, COLS;

public:
	CUserInterface();
	int menu1();
	int menu2();
	int menu3();
	int menu4();
	void changeWidth(int width);
	void changeHeight(int height);
	const char* menu5();
	void  print_board_for_map(char** board);
	void startGame();
	void display();
	void saveGame(const char* fileName);
	void loadSavedGame(const char* fileName);
	const char* file_name();
	void  settings();
	void updateRelativeIntensity(int newI);
	void updateAbsoulateIntensity(int newI);
	void  decreaseIntensity(int oldI, int newI);
	void  increaseIntensity(int oldI, int newI);
	~CUserInterface();
};


