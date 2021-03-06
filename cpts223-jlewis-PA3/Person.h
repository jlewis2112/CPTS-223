/*
 * Person:
 * This class encapsulates a person within the Josephus circle.
 */

#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<chrono>

using namespace std :: chrono;
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl;
using std :: ostream;
using std :: ifstream;
using std :: vector;
using std :: stringstream;


#ifndef __PERSON_H__
#define __PERSON_H__


class Person {

	public: 
		// Constructor:
		// Note: A person object should be created only if there is a position available for that person to occupy. 
		//		And of course, no two people can occupy the same position, and 
		//		no person can occupy more than one position at any given time.
		// ...
		Person();

		// Destructor
		// ...
		~Person();
		
		// print the position
		void print();
int getPerson();
void setPerson(int positionx);
	private:
		int position; // position occupied by the person at any point of the game
						// Note: Because each position occupies a unique position initially, 
						// 		that initial position can also be treated as the identifier (id)
						//		or name for that person.
						//		And as the potato is passed around and people are eliminated,
						//			that id can be retained.
};
 
#endif
