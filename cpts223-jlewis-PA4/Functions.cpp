#include "header.h"
using namespace std;

//////////////////////////////////////////////Player Functions
//constructor
player::player()
{
	this->id = 0;
	this->x = 0;
	this->y = 0;
}

//copy constructor
player::player(int ID, int newx, int newy)
{
	this->id = ID;
	this->x = newx;
	this->y = newy;
}

//destructor
player :: ~player()
{
}

//getter for the player id
int player::getid() const
{
	return this->id;
}

//getter for the x coordinate
int player::getx() const
{
	return this->x;
}

//getter for the y coordinate
int player::gety() const
{
	return this->y;
}

//setter for all values in the player class
void player::setAll(int newID, int newx, int newy) {
	this->id = newID;
	this->x = newx;
	this->y = newy;
}

//setter for player id
void player::setid(int idx)
{
	this->id = idx;
}

//setter for the x coordinate
void player::setx(int newx)
{
	this->x = newx;
}

//setter for the y coordinate
void player::sety(int newy)
{
	this->y = newy;
}

//used to print information about a player
void player::print() const {
	cout << "Player " << this->id << " is located at (" << this->x << ", " << this->y << ") (x, y)." << endl;
}
///////////////////////////////////////////////////Board Functions

//constructor
Board::Board() {
	this->N = 0;
	this->M = 0;
}
Board::Board(int size) {
	this->M = size;
	this->N = 0;
}

//destructor
Board :: ~Board() {
	this->players.clear();
}

//getter for the board size
const int Board::getM()
{
	return this->M;
}

//getter for the number of players on the board
const int Board::getN()
{
	return this->N;
}

//setter for the board size
void Board::setM(int newsize)
{
	this->M = newsize;
}

//setter for the number of players on the board
void Board::setN(int newplayers)
{
	this->N = newplayers;
}

//used to add new players to the board
bool Board::Insert(int ID, int x, int y) {
	player* newP = new player(ID, x, y);
	map<int, player>::iterator i;
	if (x >= this->M || y >= this->M)//trying to place out of board
	{
		cout << "ERROR! Attempting to place out of board." << endl;
		return false;
	}
	for (i = this->players.begin(); i != this->players.end(); i = next(i))
	{
		if (i->second.getx() == x && i->second.gety() == y)// place taken
		{
			cout << "ERROR! Location is already occupied." << endl;
			return false;
		}
		if (i->second.getid() == ID)//ID used
		{
			cout << "ERROR! ID is already being used." << endl;
			return false;
		}
	}
	this->N++;
	this->players.emplace(ID, *(new player(ID, x, y)));
	return true;
}


//used to move a player if the result is true
bool Board::MoveTo(int ID, int x, int y) {
	map<int, player>::iterator i;
	int remove = -1;
	if (x >= this->M || y >= this->M)//trying to move out of board
	{
		cout << "ERROR! Attempting to place out of board." << endl;
		return false;
	}
	if (this->players.count(ID) == 0)//ID not Present
	{
		cout << "ERROR! ID does not exist on board." << endl;
		return false;
	}

	for (i = this->players.begin(); i != this->players.end(); i = next(i))
	{
		if (i->second.getid() == ID)//remove from old space
		{
			i->second.setAll(ID, x, y);
		}
		if (i->second.getx() == x && i->second.gety() == y && i->second.getid() != ID)//remove any piece that gets landed on
		{
			remove = i->first;
		}
	}
	if (remove != -1)
	{
		this->Remove(remove);
	}
	return true;
}

//used to remove a player from the game
bool Board::Remove(int ID) {
	map<int, player>::iterator i;
	if (this->players.count(ID) == 0)//ID not Present
	{
		cout << "ERROR! ID does not exist on board." << endl;
		return false;
	}
	for (i = this->players.begin(); i != this->players.end(); i = next(i))
	{
		if (i->second.getid() == ID)//remove from old space
		{
			cout << "Removed player " << i->second.getid() << " from the board." << endl;
			this->players.erase(i->second.getid());
			this->N--;
			return true;
		}
	}
}

//used to determine if a player is on the board by searching for its id number.  We are using a bst map and the key is the player id #
bool Board::Find(int ID) {
	map<int, player>::iterator i;
	if (this->players.count(ID) == 0)//ID not Present
	{
		cout << "ERROR! ID does not exist on board." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

//prints all of the players on the board
void Board::PrintByID() {
	map<int, player>::iterator i;
	cout << "\n\nPlayer List:\n";
	for (i = this->players.begin(); i != this->players.end(); i = next(i))
	{
		i->second.print();
	}
}
