// Implementation of ADT Buckets
// data structure is doubly-linked list
//    data object: buckets with one pebble in each bucket
//    operations: create, destroy, copy, swap, fill
//               (finish)

#include "buckets.h"
#include <iostream>

typedef int ItemType;

using namespace std;



// helper function for the constructor
void addAtFront(Node*& frontptr, Node*& backptr)
{
    Node* newptr;
    newptr = new Node;
    newptr -> next = nullptr;
    newptr -> previous = nullptr;
    if (frontptr == nullptr)
    {
        frontptr = newptr;
        backptr = newptr;
    } else {
        newptr -> next = frontptr;
        frontptr -> previous = newptr;
        frontptr = newptr;
    }
    
}

void deleteAtBack(Node*& firstptr, Node*& lastptr)
{
    Node* delptr;
	if(firstptr == lastptr)
	{
        delptr = lastptr;
        firstptr = nullptr;
        lastptr = nullptr;
	}
	else
	{
		delptr = lastptr;
        lastptr = lastptr -> previous;
		delptr -> previous -> next = nullptr;
		delptr -> previous = nullptr;
	}
    delete delptr;
}


// creates the buckets in front of the robot
// pre: numberBuckets is assigned value >= 1
// post: numberBuckets empty Buckets are made
// usage: Buckets b(5);
Buckets::Buckets(int numberBuckets)
{
    buckets = new BucketStuff;
    buckets -> frontptr = nullptr;
    buckets -> backptr = nullptr;
    buckets -> numberOfBuckets = numberBuckets;
    
    for (int k = 0; k < numberBuckets; k++)
    {
        addAtFront(buckets -> frontptr, buckets -> backptr);
    }
}


// destroys the buckets object
// pre: buckets object exists
// post: buckets object does not exist
// usage: automatically done at the end of scope
Buckets::~Buckets()
{
	for (int k = buckets -> numberOfBuckets; k > 0; k--)
	{
		deleteAtBack(buckets -> frontptr, buckets -> backptr);
	}
    buckets -> numberOfBuckets = 0;
}

//look looks inside the bucket number bucketNumber and determines what color 
//  the pebble is and what number the bucket that was looked into is
//pre: bucketNumber is assigned a positive integer, the buckets are labeled 1,2,3...
//post: looks inside the bucket number bucketNumber and returns what color the pebble is
// usage: bucekts.look(color,3);
void Buckets::look (Pebble& color, int bucketNumber) const
{
   Node* tempptr = buckets -> frontptr;
   if(bucketNumber <= 0 || bucketNumber > buckets -> numberOfBuckets)
   {
	   cout << "That is not a valid bucket. Please try again" << endl;
   }
   else
   {
		for(int k = 1; k < bucketNumber; k++)
		{
			tempptr = tempptr -> next;
		}
		color = tempptr -> color;
   }
}

//pre: leftBucket and rightBucket are positions of buckets
//      positions of buckets are labeled 1, 2, 3...
//post: the pebble at position leftBucket has been switched with pebble at position rightBucket
//      robots left arm finds position leftBucket, starting at position 1 and moving right
//      robots right arm finds position rightBucket, starting at the last position and moving left
//usage: buckets.swap(b1, b2);
void Buckets::swap(int leftBucket, int rightBucket)
{
   Node* tempLeft;
   Node* tempRight;
   Node* holder;
   tempLeft = buckets -> frontptr;
   tempRight = buckets -> backptr;
   for(int l = 1; l < leftBucket; l++)
   {
	   tempLeft = tempLeft -> next;
	   //buckets -> frontptr -> next;
   }
   for(int r = buckets -> numberOfBuckets; r > rightBucket; r--)
   {
	   tempRight = tempRight -> previous;
	   //buckets -> backptr -> previous;
   }
   
   if(leftBucket <= 0 || rightBucket > buckets -> numberOfBuckets)
   {
	   cout << "That is not a valid swap. Please try again" << endl;
   }
   else if(leftBucket == rightBucket)
   {
	   // do nothing
   }
   else
   {
	   if(rightBucket < leftBucket)
	   {
		   int temp = rightBucket;
		   rightBucket = leftBucket;
		   leftBucket = temp;
	   }
	   if(tempRight -> color == RED)
	   {
		   if(tempLeft -> color == RED)
		   {
			   // do nothing
		   }
		   else if(tempLeft -> color == WHITE)
		   {
			   tempRight -> color = WHITE;
			   tempLeft -> color = RED;
		   }
		   else
		   {
			   tempRight -> color = BLUE;
			   tempLeft -> color = RED;
		   }
	   }
	   else if(tempRight -> color == WHITE)
	   {
		   if(tempLeft -> color == RED)
		   {
			   tempRight -> color = RED;
			   tempLeft -> color = WHITE;
		   }
		   else if(tempLeft -> color == WHITE)
		   {
			   // do nothing
		   }
		   else
		   {
			   tempRight -> color = BLUE;
			   tempLeft -> color = WHITE;
		   }
	   }
	   else
	   {
		   if(tempLeft -> color == RED)
		   {
			   tempRight -> color = RED;
			   tempLeft -> color = BLUE;
		   }
		   else if(tempLeft -> color == WHITE)
		   {
			   tempRight -> color = WHITE;
			   tempLeft -> color = BLUE;
		   }
		   else
		   {
			   // do nothing
		   }
	   }
	}
}



//Puts a random color pebble in each bucket
//pre: buckets have been created and are in front of robot
//post: all buckets contain one pebble
//usage: robot.fillBuckets();
void Buckets::fillBuckets()
{
    Node* helperptr = buckets -> frontptr;
    srand((unsigned)time(0)); 
    for(int k = 0; k < buckets -> numberOfBuckets; k++)
    {
        int randomInteger = rand() % 3;
        if(randomInteger == 0)
        {
            helperptr -> color = RED;
        } else if (randomInteger == 1)
        {
            helperptr -> color = WHITE;
        } else {
            helperptr -> color = BLUE;
        }
        helperptr = helperptr -> next;
    }
}



