//============================================================================
// Name        : animated_time.cpp
// Author      : Ben Clark
// Version     :
// Copyright   : n/a
// Description : loading bar
//============================================================================

// Made another change!


#include <iostream>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <ctime>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;


// these help draw the box using the extended ASCII table
unsigned char B[15]={205,218,196,191,179,195,180,194,193,217,192,220,223,219};
//                double horizontal,

unsigned char box[5]={193,194,255,179};
//unsigned char B[15]={97,98,99,100,101,102,103,104,105,106,107,108,109,110};
////                 ={a ,b ,c ,d  ,e  ,f  ,g  ,h  ,i  ,j  ,k  ,l  ,m  ,n  }

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if(!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h,c);
}

// This function makes user wait for 1 second
void wait (float seconds)
{
	clock_t endwait;
	endwait = clock() + seconds + CLOCKS_PER_SEC/900;
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
	// declare variables for counting
	int seconds = 0;
	int minutes= 0;
	int hours = 0;
	float course1 = 0;

	// Draw the thirds box
	setcolor(9);
	gotoxy(6,13); cout << B[1];  M(60); cout << B[3] << endl;
	gotoxy(6,14); cout << B[4]; gotoxy(67,14); cout << B[4];
	gotoxy(6,15); cout << B[10]; M(60); cout << B[9];


	// Draw the seconds box and label it as seconds
	setcolor(9);
	gotoxy(6,16); cout << B[1]; M(60); cout << B[3] << endl;
	gotoxy(6,17); cout << B[4]; gotoxy(67,17); cout << B[4];
	gotoxy(6,18); cout << B[10]; M(60); cout << B[9];
	gotoxy(69,17); cout << ends << seconds << " seconds";


	// Draw the minutes box and label it as minutes
	setcolor(9);
	gotoxy(6,19); cout << B[1]; M(60); cout << B[3] << endl;
	gotoxy(6,20); cout << B[4]; gotoxy(67,20); cout << B[4];
	gotoxy(6,21); cout << B[10]; M(60); cout << B[9];
	gotoxy(69,20); cout << ends << minutes << " minutes";


	// Draw box for timeslot 1
	setcolor(9);
	gotoxy(6,24); cout << B[1]; M(15); cout << B[3] << endl;
	gotoxy(6,25); cout << B[4]; gotoxy(22,25); cout << B[4];
	gotoxy(6,26); cout << B[10]; M(15); cout << B[9];
	setcolor(14);
	gotoxy(7,25); cout << ends << "CSCI-327 " << course1/15 << '%';
	setcolor(9);



	while (minutes != 60)
	{
		// Fill the inside of seconds box based on the clock
		setcolor(14);
		for  (int i=1; i <= 60; i++)
		{
			// The below if-else block causes the bar to fill up with alternating characters
			if (seconds % 2 == 0)
			{
				wait(0);
				if (i < 10)
				{
					gotoxy(6+i,14); cout <<  box[0];
					gotoxy(69,14); cout << ends <<  "00/60th second";
				}
				else if (i >=10)
				{
					gotoxy(6+i,14); cout <<  box[0];
					gotoxy(69,14); cout << ends << i << "/60th second";
				}
			}
			else if (seconds % 2 != 0)
			{
				wait(0);
				if (i < 10)
				{
					gotoxy(6+i,14); cout <<  box[1];
					gotoxy(69,14); cout << ends <<  "00/60th second";
				}
				else if (i >=10)
				{
					gotoxy(6+i,14); cout <<  box[1];
					gotoxy(69,14); cout << ends << i << "/60th second";
				}
			// End if-else block of alternating characters
			}
		}


		// Increment seconds by one when finished with loop
		// and begin filling the seconds box
		seconds += 1;
		if (seconds <= 60)
		{
			gotoxy(6+seconds,17); cout << B[13]; gotoxy(69,17); cout << ends << seconds << " seconds";
		}
		if (seconds >= 60)
		{
			for (int i=1; i<=60; i++)
			{
				gotoxy(6+i,17); cout << box[2];
			}

		}


		// Increment minutes-variable when 60 seconds go by
		if (seconds == 60)
		{
			gotoxy(79,17); cout << " "; // remove the extra 's' when seconds is a single-digit number
			if (course1 < 15)
				course1 += 1;
			minutes += 1;
			seconds = 0;
		}
		if (minutes == 0)
		{
			setcolor(14);
			gotoxy(69,20); cout << ends << minutes << " minutes";
			gotoxy(6+minutes,21); cout << box[3];
			gotoxy(6+minutes,22); cout << box[3];
			gotoxy(6+minutes,23); cout << box[3];
			gotoxy(6+minutes,24); cout << box[3];
			gotoxy(6+minutes,25); cout << box[3];
			gotoxy(6+minutes,26); cout << box[3];
			gotoxy(6+minutes,27); cout << box[3];
			gotoxy(6+minutes,28); cout << box[3];
		}
		if (minutes == 1)
		{
			// redraw box
			setcolor(9);
			gotoxy(5+minutes,21); cout << ' ';
			gotoxy(5+minutes,22); cout << ' ';
			gotoxy(5+minutes,23); cout << ' ';
			gotoxy(5+minutes,24); cout << ' ';
			gotoxy(5+minutes,25); cout << ' ';
			gotoxy(5+minutes,26); cout << ' ';
			gotoxy(5+minutes,27); cout << ' ';
			gotoxy(5+minutes,28); cout << ' ';

			// Redraw box for timeslot 1
			setcolor(14);
			gotoxy(6+minutes,20); cout << B[13]; gotoxy(69,20); cout << ends << minutes << " minutes";
			setcolor(9);
			gotoxy(6,24); cout << B[1]; M(15); cout << B[3] << endl;
			gotoxy(6,25); cout << B[4]; gotoxy(22,25); cout << B[4];
			gotoxy(6,26); cout << B[10]; M(15); cout << B[9];
			gotoxy(6,19); cout << B[1]; M(60); cout << B[3] << endl;
			gotoxy(6,20); cout << B[4]; gotoxy(67,20); cout << B[4];
			gotoxy(6,21); cout << B[10]; M(60); cout << B[9];

			// Place the minute-line
			setcolor(14);
			gotoxy(7+minutes,21); cout << box[3];
			gotoxy(7+minutes,22); cout << box[3];
			gotoxy(7+minutes,23); cout << box[3];
			gotoxy(7+minutes,24); cout << box[3];
			gotoxy(7+minutes,25); cout << box[3];
			gotoxy(7+minutes,26); cout << box[3];
			gotoxy(7+minutes,27); cout << box[3];
			gotoxy(7+minutes,28); cout << box[3];
			if (course1/15 != 1)
			{
				gotoxy(7,25); cout << ends << "CSCI-327 " << setprecision(2) << setw(3) << (course1/15 * 100)  << '%';
			}
			if (course1/15 == 1)
			{
				gotoxy(7,25); cout << ends << "CSCI-327 " << setprecision(3) << setw(3) << (course1/15 * 100)  << '%';
			}
		}


		if (minutes > 1)
		{
			// redraw box
			setcolor(9);
			gotoxy(6+minutes,21); cout << ' ';
			gotoxy(6+minutes,22); cout << ' ';
			gotoxy(6+minutes,23); cout << ' ';
			gotoxy(6+minutes,24); cout << ' ';
			gotoxy(6+minutes,25); cout << ' ';
			gotoxy(6+minutes,26); cout << ' ';
			gotoxy(6+minutes,27); cout << ' ';
			gotoxy(6+minutes,28); cout << ' ';

			// Redraw box for timeslot 1
			setcolor(9);
			gotoxy(6,24); cout << B[1]; M(15); cout << B[3] << endl;
			gotoxy(6,25); cout << B[4]; gotoxy(22,25); cout << B[4];
			gotoxy(6,26); cout << B[10]; M(15); cout << B[9];
			gotoxy(6,19); cout << B[1]; M(60); cout << B[3] << endl;
			gotoxy(6,20); cout << B[4]; gotoxy(67,20); cout << B[4];
			gotoxy(6,21); cout << B[10]; M(60); cout << B[9];

			// Place the minute-line
			setcolor(14);
			gotoxy(6+minutes,20); cout << B[13]; gotoxy(69,20); cout << ends << minutes << " minutes";
			gotoxy(7+minutes,21); cout << box[3];
			gotoxy(7+minutes,22); cout << box[3];
			gotoxy(7+minutes,23); cout << box[3];
			gotoxy(7+minutes,24); cout << box[3];
			gotoxy(7+minutes,25); cout << box[3];
			gotoxy(7+minutes,26); cout << box[3];
			gotoxy(7+minutes,27); cout << box[3];
			gotoxy(7+minutes,28); cout << box[3];
			if (course1/15 != 1)
			{
				gotoxy(7,25); cout << ends << "CSCI-327 " << setprecision(2) << setw(3) << (course1/15 * 100)  << '%';
			}
			if (course1/15 == 1)
			{
				gotoxy(7,25); cout << ends << "CSCI-327 " << setprecision(3) << setw(3) << (course1/15 * 100)  << '%';
			}
		}
	}



	getch();
	return 0;
}














