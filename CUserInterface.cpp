#define _CRT_SECURE_NO_WARNINGS
#include "CUserInterface.h"
#include<iostream>
using namespace std;
#include "CLife.h"
#include<Windows.h>
#include<fstream>
#include<string.h>

CUserInterface::CUserInterface() :turns(0) {        //Default constructor
	COLS = 20;
	ROWS = 20;
}

CUserInterface::~CUserInterface() {

}


int CUserInterface::menu1()
{

	cout << endl << "1-start game " << endl;
	cout << "2-load game " << endl;
	cout << "3-Map Editor" << endl;
	cout << "4-Settings" << endl;
	cout << "5-exit" << endl;
	cout << endl << "choice ->>";

	int z;
	cin >> z;
	cin.ignore();
	return z;
}
int CUserInterface::menu2()
{
	cout << "1-Step By Step" << endl;
	cout << "2-Animation" << endl;
	cout << "3-Back" << endl;
	cout << "choice ->>" << endl;
	int i;
	cin >> i;
	cin.ignore();
	return i;
}
int CUserInterface::menu3()
{
	cout << "1-save Game" << endl;
	cout << "2-Back" << endl;
	cout << "Choice ->>";
	int i;
	cin >> i;
	cin.ignore();
	return i;
}
int CUserInterface::menu4()
{
	cout << "1 - width" << endl;
	cout << "2 - height" << endl;
	cout << "3 - intensity" << endl;
	cout << "4 - back" << endl;
	cout << "Choice ->>";
	int i;
	cin >> i;
	cin.ignore();

	return i;
}

const char* CUserInterface::menu5()
{

	cout << "Select file in which you saved your game?" << endl;
	fstream file_names;
	file_names.open("file_names.txt", ios::in);
	int counter = 1;

	string tp;
	while (getline(file_names, tp)) {  //read data from file object and put it into string.
		cout << counter++ << " : " << tp << "\n";   //print the data of the string
	}


	file_names.close();
	char* ch = new char[100];
	cout << "Please carefully enter the valid file name ->>";
	cin >> ch;


	return ch;

}
const char* CUserInterface::file_name() {
	char* file = new char[100];
	cout << "Enter the file name: ";
	cin >> file;
	fstream file_names;
	file_names.open("file_names.txt", ios::app | ios::out);
	file_names << file << "\n";
	file_names.close();
	return file;
}
void CUserInterface::startGame() {
	int ch = menu2();
	if (ch == 1)
	{

		cout << "How many steps should be animated at most?";

		int step;
		cin >> step;
		int end = 0;
		step = step - 1;
		system("cls");
		for (int i = 0; end == 0; i++)
		{
			U.display();
			cout << "ITERATION NUMBER" << i + 1 << endl;
			if (end != 1) {
				cout << "1- next Generation" << endl;
				cout << "choice>>" << endl;
			}
			int u;
			cin >> u;
			if (i != step)
				system("cls");

			if (i == step)
			{
				end = 1;

			}


		}

		char* f = new char[100];      //-->
		const char* temp;
		switch (menu3())
		{

		case 1:

			system("cls");
			temp = file_name();
			strcpy(f, temp);
			delete temp;
			saveGame(f);
			system("cls");
			break;
		case 2:
			system("cls");

			break;
		}
	}
	else if (ch == 2) {



		cout << "How many steps should be animated at most?";
		int step1;
		cin >> step1;
		int enddd = 0;
		step1 = step1 - 1;
		system("cls");
		for (int i = 0; enddd == 0; i++)
		{
			U.display();
			Sleep(1);

			if (i != step1)  system("cls");

			if (i == step1)
			{
				enddd = 1;

			}


		}

		char f2[100];
		const char* temp;
		switch (menu3())
		{
		case 1:
			system("cls");
			temp = file_name();
			strcpy(f2, temp);
			delete temp;
			saveGame(f2);             //-->
			system("cls");
			break;
		case 2:
			system("cls");

			break;
		}
	}

	if (ch == 3) {

		system("cls");

	}

}
void CUserInterface::saveGame(const char* fileName)
{  //-->


	ofstream file; //wirte file
	file.open(fileName, ios::in | ios::out | ios::trunc);
	char** temp = nullptr;
	temp = U.getBoard();
	if (file.is_open()) {
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (temp[i][j] == 1) {

					file << "*";
				}
				else {
					file << " ";
				}
			}
			file << "\n";
		}
	}
	else
	{
		cout << "we can not open this file";
	}
	file.close();


}

void CUserInterface::loadSavedGame(const char* fileName) {


	ifstream file; //read file
	file.open(fileName);
	char** temp = new char* [20];
	for (int i = 0; i < 20; i++)
	{
		temp[i] = new char[20];
	}

	if (file.is_open()) {

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				file >> temp[i][j];
			}

		}


		U.update_board(temp);
		system("cls");
		startGame();
	}
	else
	{
		cout << "we can not open this file,please try again" << endl;
		Sleep(2000);
	}

	file.close();

}

void CUserInterface::display() {
	int x = -1, y = -1;
	char ch;
	char ch_1;
	char ch_2;
	while (1)
	{
		char file[100];
		const char* temp;
		switch (menu1())
		{
		case 1:
			system("cls");
			startGame();
			break;
		case 2:
			system("cls");
			temp = menu5();
			strcpy(file, temp);
			delete temp;
			loadSavedGame(file);
			system("cls");

			break;
		case 3:
			while (1)
			{
				system("cls");
				print_board_for_map(U.getBoard());
				cout << "Enter the Coordinate you wanna edit: " << endl;
				cin >> x;
				cin.ignore();
				cin >> y;
				cin.ignore();
				cout << "\nEnter character(space for nothing/* for living cell): " << endl;
				cin >> noskipws >> ch_1;
				cin.ignore();
				if (ch_1 == '*')
					U.change_coordinate(x, y, '*');
				else
					U.change_coordinate(x, y, ' ');
				cout << "Do you want edit again(y/n): ";
				cin >> ch_2;
				cin.ignore();
				if (ch_2 == 'n')
				{
					system("cls");
					temp = file_name();
					strcpy(file, temp);
					delete temp;
					saveGame(file);
					system("cls");
					cin.ignore();
					break;
				}

			}

			break;

		case 4:
			system("cls");
			settings();



			break;
		case 5:
			system("cls");
			exit(0);
			break;
		}


	}


}
void CUserInterface::changeWidth(int width)
{
	U.changeWidth(width);
}
void CUserInterface::changeHeight(int height)
{
	U.changeHeight(height);
}
void  CUserInterface::print_board_for_map(char** board)
{

	int row, col;

	cout << "   ";
	for (int i = 0; i < COLS; i++)
	{

		cout << i << " ";
	}
	cout << endl;

	for (int i = 0; i < COLS; i++)
	{
		if (i % 2 == 0)
			cout << "-----";
		else
			cout << "----";
	}
	cout << endl;
	for (row = 0; row < ROWS; row++)
	{
		cout << row << "|";
		for (col = 0; col < COLS; col++)
		{
			if (board[row][col] == 1)
			{
				cout << " * ";
			}
			else
				cout << "   ";

		}
		cout << endl;
	}
	for (int i = 0; i < COLS; i++)
	{
		if (i % 2 == 0)
			cout << "-----";
		else
			cout << "----";
	}
	cout << endl;
}
void  CUserInterface::settings() {
	int u = 0;
	int intesity = 0;
	int number = 0;
	switch (menu4())
	{
	case 1:
		cout << "Enter new Width: ";
		cin >> number;
		cin.ignore();
		changeWidth(number);
		break;
	case 2:
		cout << "Enter new Height: ";
		cin >> number;
		cin.ignore();
		changeHeight(number);
		break;
	case 3:



		cout << "\t--- CHANGE INTENSITY ---" << endl;
		cout << "1 - relative change \n";
		cout << "2 - absolute change \n";
		cout << "choice: ";
		cin >> u;

		cout << "Enter intensity: ";
		cin >> intesity;
		if (u == 1)
		{
			updateRelativeIntensity(intesity);
		}
		else if (u == 2)
		{
			updateAbsoulateIntensity(intesity);
		}
		else
		{
			cout << "Invalies option!!!\n";
			getchar();
		}

		system("cls");

		break;
	default:
		break;
	}

}
void CUserInterface::updateAbsoulateIntensity(int newI)
{
	char** temp = new char* [20];
	for (int i = 0; i < 20; i++)
	{
		temp[i] = new char[20];
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			temp[i][j] = 0;
		}

	}
	int a = rand() % ROWS;
	int b = rand() % COLS;
	int count = 0;
	while (count < newI)
	{
		while (1)
		{
			if (temp[a][b] == 0)
			{
				temp[a][b] = 1;
				count++;
				break;
			}
			a = rand() % ROWS;
			b = rand() % COLS;
		}
	}
	U.change_intensity(temp);
}
void  CUserInterface::updateRelativeIntensity(int newI)
{
	char** temp = new char* [20];
	for (int i = 0; i < 20; i++)
	{
		temp[i] = new char[20];
	}
	temp = U.getBoard();
	int count = 0;
	int newCount = newI;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (temp[i][j] == 1)
				count++;
		}
	}
	if (count == newI)
		return;
	if (count > newI)
		decreaseIntensity(count, newI);
	else
		increaseIntensity(count, newI);
}
void  CUserInterface::decreaseIntensity(int oldI, int newI)
{
	char** temp = new char* [20];
	for (int i = 0; i < 20; i++)
	{
		temp[i] = new char[20];
	}
	temp = U.getBoard();
	int a = rand() % ROWS;
	int b = rand() % COLS;
	while (oldI <= newI)
	{
		while (1)
		{
			if (temp[a][b] == 1)
			{
				temp[a][b] = 0;
				oldI--;
				break;
			}
			a = rand() % ROWS;
			b = rand() % COLS;
		}

	}
	U.change_intensity(temp);

}
void  CUserInterface::increaseIntensity(int oldI, int newI)
{
	char** temp = new char* [20];
	for (int i = 0; i < 20; i++) {
		temp[i] = new char[20];
	}

	temp = U.getBoard();
	int a = rand() % ROWS;
	int b = rand() % COLS;
	while (oldI <= newI)
	{
		while (1)
		{
			if (temp[a][b] == 0)
			{
				temp[a][b] = 1;
				oldI++;
				break;
			}
			a = rand() % ROWS;
			b = rand() % COLS;
		}

	}

	U.change_intensity(temp);
}
