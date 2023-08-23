//============================================================================
// Name        : animated_time.cpp
// Author      : Ben Clark
// Version     :
// Copyright   : n/a
// Description : loading bar
//============================================================================

// i am changing things!


#include <iostream>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <ctime>
#include <windows.h>
using namespace std;


unsigned char B[15]={205,218,196,191,179,195,180,194,193,217,192,220,223,219};

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if(!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h,c);
}

void wait (float seconds)
{
	clock_t endwait;
	endwait = clock() + seconds + CLOCKS_PER_SEC/20;
	while (clock() < endwait){}
}

void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon,color);
}

void M(int n)
{
	for (int i=1; i <= n; i++)
	{
		cout << B[2];
	}
}

int main ()
{
	setcolor(9);
	gotoxy(16,13); cout << B[1];  M(91); cout << B[3] << endl;
	gotoxy(16,14); cout << B[4]; gotoxy(108,14); cout << B[4];
	gotoxy(16,15); cout << B[10]; M(91); cout << B[9];

	setcolor(14);
	for  (int i=10; i <= 100; i++)
	{
		gotoxy(7+i,14); cout << B[13]; wait(0); gotoxy(109,14); cout << ends << i << " %"; gotoxy(53,16); cout << ". . . LOADING . . .";
		if (i==100)
		{
			setcolor(10);
			gotoxy(53,16); cout << ". . . COMPLETE . . .";
			Beep(800,125);
			Beep(800,125);
		}
	}
	getch();
	return 0;
}
