// author: Adam Pesch
// date: November 30, 2017
// file bucketstester.cpp

#include "buckets.h"
#include <iostream>

using namespace std;

// helper method for printing the row of buckets
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: screen has printed the row of buckets in an easy to read format
// usage: printPebblesInBuckets(pebbles, howManyBuckets);
void printPebblesInBuckets(const Buckets& pebbles, int howManyBuckets);

int main()
{
	//int i;
    //cin >> i; 
    Buckets robotBuckets(5);
	
	robotBuckets.fillBuckets();
	
	cout << "The current line up of pebbles in buckets is ";
	printPebblesInBuckets(robotBuckets, 5);
	cout << endl;
	
	cout << "Now we swap space 1 and space 3" << endl << endl;
	robotBuckets.swap(0, 3);
	robotBuckets.swap(1, 6);
	robotBuckets.swap(1, 3);
	
	cout << "The new line up of pebbles in buckets is ";
	printPebblesInBuckets(robotBuckets, 5);
    cout << endl;
	
	Pebble p;
	robotBuckets.look(p, -1);
	robotBuckets.look(p, 8);
	robotBuckets.look(p, 5);
	if(p == RED)
	{
		cout << "The color of the pebble in bucket 5 is red" << endl;
	}
	else if(p == WHITE)
	{
		cout << "The color of the pebble in bucket 5 is white" << endl;
	}
	else
	{
		cout << "The color of the pebble in bucket 5 is blue" << endl;
	}
    return 0;
}

// helper method for printing the row of buckets
// pre: pebbles is an existing Buckets, how many buckets is an integer greater than zero
// post: screen has printed the row of buckets in an easy to read format
// usage: printPebblesInBuckets(pebbles, howManyBuckets);
void printPebblesInBuckets(const Buckets& pebbles, int howManyBuckets)
{
	cout << endl;
	for(int i = 1; i <= howManyBuckets; i++)
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
