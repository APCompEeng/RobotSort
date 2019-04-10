// Specification of ADT Buckets
//    data object: buckets with one pebble in each bucket
//    operations: create, destroy, copy, swap, fill
//               (finish)

#ifndef BUCKETS_H
#define BUCKETS_H

enum Pebble {RED, WHITE, BLUE};

struct Node
{
	Node* previous;
	Node* next;
	Pebble color;
};

struct BucketStuff
{
	Node* frontptr;
    Node* backptr;
	int numberOfBuckets;
};


typedef int ItemType;

class Buckets
{
public:

// creates the buckets in front of the robot
// pre: numberBuckets is assigned value >= 1
// post: numberBuckets empty Buckets are made
// usage: Buckets b;
Buckets(int numberBuckets);

// destroys the buckets object
// pre: buckets object exists
// post: buckets object does not exist
// usage: automatically done at the end of scope
~Buckets();

//look looks inside the bucket number bucketNumber and determines what color 
//  the pebble is and what number the bucket that was looked into is
//pre: bucketNumber is assigned a positive integer, the buckets are labeled 1,2,3...
//post: looks inside the bucket number bucketNumber and returns what color the pebble is
// usage: bucekts.look(color,3);
void look (Pebble& color, int bucketNumber) const;

//pre: leftBucket and rightBucket are positions of buckets
//      positions of buckets are labeled 1, 2, 3...
//post: the pebble at position leftBucket has been switched with pebble at position rightBucket
//      robots left arm finds position leftBucket, starting at position 1 and moving right
//      robots right arm finds position rightBucket, starting at the last position and moving left
//usage: buckets.swap(b1, b2);
void swap(int leftBucket, int rightBucket);

//Puts a random color pebble in each bucket
//pre: buckets have been created and are in front of robot
//post: all buckets contain one pebble
//usage: robot.fillBuckets();
void fillBuckets();

private:

BucketStuff* buckets;

};
#endif




