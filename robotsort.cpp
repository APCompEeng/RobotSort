// author: Adam Pesch
// date: December 04, 2017
// file robotsort.cpp

#include "buckets.h"
#include <iostream>
using namespace std;

typedef int ItemType;

// sorts the pebbles into order of Reds, Whites, and Blues
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: the pebbles in the buckets are sorted into Reds, then Whites, then Blues
// usage: robotSort(pebbles, 15);
void robotSort(Buckets& pebbles, int howManyBuckets);

// prints the list before its sorted in a friendly and easy to read format
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: screen has printed the row of buckets in an easy to read format
// usage: printBeforeRobot(pebbles, 15);
void printBeforeRobot(const Buckets& pebbles, int howManyBuckets);

// prints the list after its sorted in a friendly and easy to read format
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: screen has printed the row of buckets in an easy to read format
// usage: printAfterRobot(pebbles, 15);
void printAfterRobot(const Buckets& pebbles, int howManyBuckets);

// helper method for printing the row of buckets
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: screen has printed the row of buckets in an easy to read format
// usage: printPebblesInBuckets(pebbles, howManyBuckets);
void printPebblesInBuckets(const Buckets& pebbles, int howManyBuckets);

// prints a number of spaces
// pre: spaces is assigned
// post: prints spaces spaces on the screen
// usage: printSpaces(4);
void printSpaces(int spaces);

// prints a number of blanklines
// pre: numberOfLines is assigned
// post: prints numberOfLines blanklines on the screen
// usage: printBlankLines(4);
void printBlankLines(int numberOfLines);

int main()
{
	Buckets pebbles(15);
	pebbles.fillBuckets();
	printBeforeRobot(pebbles, 15);
	printBlankLines(2);
	robotSort(pebbles, 15);
	printAfterRobot(pebbles, 15);
	
	Buckets pebblesRound2(10);
	pebblesRound2.fillBuckets();
	printBeforeRobot(pebblesRound2, 10);
	printBlankLines(2);
	robotSort(pebblesRound2, 10);
	printAfterRobot(pebblesRound2, 10);
	return 0;
}


// sorts the pebbles into order of Reds, Whites, and Blues
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: the pebbles in the buckets are sorted into Reds, then Whites, then Blues
// usage: robotSort(pebbles, 15);
void robotSort(Buckets& pebbles, int howManyBuckets)
{
	int lastRed = 0, lastWhite = 0, firstMixed = 1;
	Pebble checkPebble;
	
	while (firstMixed <= howManyBuckets)
	{
		pebbles.look(checkPebble, firstMixed);
		if(checkPebble == RED)
		{
			pebbles.swap(lastWhite + 1, firstMixed);
			pebbles.swap(lastWhite + 1, lastRed + 1);
			lastRed++;
			lastWhite++;
		}
		else if(checkPebble == WHITE)
		{
			pebbles.swap(firstMixed, lastWhite + 1);
			lastWhite++;
		}
		else
		{
			// do nothing
		}
		firstMixed++;
	}
}

// prints the list before its sorted in a friendly and easy to read format
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: screen has printed the row of buckets in an easy to read format
// usage: printBeforeRobot(pebbles, 15);
void printBeforeRobot(const Buckets& pebbles, int howManyBuckets)
{
	printSpaces(howManyBuckets);
	cout << "  _______________" << endl;
	printSpaces(howManyBuckets);
	cout << " |  O      O    |" << endl;
	printSpaces(howManyBuckets);
	cout << "[|     /\\       |]" << endl;
	printSpaces(howManyBuckets);
	cout << " |   _________  |　 ／￣￣￣￣￣￣￣￣￣\\" << endl;
	printSpaces(howManyBuckets);
	cout << " |  |_|_|_|_|_| | ＜　READY FOR SORTING  |" << endl;
	printSpaces(howManyBuckets);
	cout << " |______________|  ＼＿＿＿＿＿＿＿＿＿＿/" << endl;
	
	cout << " _";
	printSpaces(howManyBuckets * 3);
	cout << "  _" << endl;
	cout << "( )";
	printSpaces(howManyBuckets * 3);
	cout << "( )";
	printPebblesInBuckets(pebbles, howManyBuckets);
}

// prints the list after its sorted in a friendly and easy to read format
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: screen has printed the row of buckets in an easy to read format
// usage: printAfterRobot(pebbles, 15);
void printAfterRobot(const Buckets& pebbles, int howManyBuckets)
{
	printSpaces(howManyBuckets);
	cout << "  _______________" << endl;
	printSpaces(howManyBuckets);
	cout << " |  ^      ^    |" << endl;
	printSpaces(howManyBuckets);
	cout << "[|     /\\       |]" << endl;
	printSpaces(howManyBuckets);
	cout << " |   _________  |　 ／￣￣￣￣￣￣￣￣￣\\" << endl;
	printSpaces(howManyBuckets);
	cout << " |  |_|_|_|_|_| | ＜　SORTING COMPLETE!  |" << endl;
	printSpaces(howManyBuckets);
	cout << " |______________|  ＼＿＿＿＿＿＿＿＿＿＿/" << endl;
	
	cout << "(_)";
	printSpaces(howManyBuckets * 3);
	cout << "(_)";
	printPebblesInBuckets(pebbles, howManyBuckets);
}

// helper method for printing the row of buckets
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: screen has printed the row of buckets in an easy to read format
// usage: printPebblesInBuckets(pebbles, howManyBuckets);
void printPebblesInBuckets(const Buckets& pebbles, int howManyBuckets)
{
	printBlankLines(1);
	for(int i = 1; i < howManyBuckets; i++)
	{
	   Pebble look;
	   pebbles.look(look, i);
	   if(look == RED)
	   {
		   cout << "\\R/ ";
	   }
	   else if(look == WHITE)
	   {
		   cout << "\\W/ ";
	   }
	   else
	   {
		   cout << "\\B/ ";
	   }
   }
   cout << endl;
}

// prints a number of spaces
// pre: spaces is assigned
// post: prints spaces spaces on the screen
// usage: printSpaces(4);
void printSpaces(int spaces)
{
	for(int i = 0; i < spaces; i++)
	{
		cout  << " ";
	}
}

// prints a number of blanklines
// pre: numberOfLines is assigned
// post: prints numberOfLines blanklines on the screen
// usage: printBlankLines(4);
void printBlankLines(int numberOfLines)
{
	for(int i = 0; i < numberOfLines; i++)
	{
		cout  << endl;
	}
}
