#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include<map>
#include<iterator>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::ifstream;
using std::vector;
using std::map;


// the player class.  used to describe a player on the board
class player
{
public:
	player();
	player(int ID, int newx, int newy);
	~player();

	void setid(int idx);
	void setx(int newx);
	void sety(int newy);
	void setAll(int newID, int newx, int newy);

	int getid() const;
	int getx() const;
	int gety() const;

	void print() const;

private:
	int id;
//player ID
//x and y cordinates of a player
	int x;
	int y;
};


////////////////////////////////////
//the board class.  used to implement the needed functions in the assignment involving the board.
class Board
{
public:
	Board();
	Board(int size);
	~Board();

	const int getM();
	const int getN();

	void setM(int newSize);
	void setN(int newPlayers);

	bool Insert(int ID, int x, int y);
	bool MoveTo(int ID, int x, int y);
	bool Remove(int ID);
	bool Find(int ID);
	void PrintByID();

private:
	int M;//board size m by m
	int N;//number of players on the board
	map<int, player> players;//using the bst msp to keep track of the players during gameplay.  The players id is the key.
};
