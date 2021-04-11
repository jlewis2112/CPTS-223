#include"ListMyJosephus.h"


//constructor
ListMyJosephus :: ListMyJosephus()
{



size = 0;
N = 0;
M = 0;
pot=0;


}

//copy constructor
ListMyJosephus ::ListMyJosephus( int Nx, int Mx)
{
N = Nx;
M = Mx;
size = Nx;
pot=0;
}


//destructor
ListMyJosephus :: ~ListMyJosephus()
{
circ.clear();


pot = 0;
size = 0;
N = 0;
M = 0;

}

//used to create a new game.  assigns values to N, M, and size.  Also, this functions adds players to the list circ.
void ListMyJosephus :: init(int Nx, int Mx)
{
N = Nx;
M = Mx;
pot = 0;
size = Nx;
Person entree;
for(int a=0; a < N; a++)
{
entree.setPerson(a);
circ.push_back(entree);
}

}


//clears circ
void ListMyJosephus :: clearx()
{
circ.clear();

}

//prints the amount of player remaining in the game
void ListMyJosephus :: currentSize()
{
cout << size << endl;
}




//determines if circ is empty or not
bool ListMyJosephus :: isEmpty()
{
bool result = false;
if((circ.empty()) && (size == 0))
{
result = true;
}

return result;
}

//this functions determines and returns the eleminated player, while removing the eliminated player from circ.
Person ListMyJosephus :: eliminateNext()
{
Person eliminated;
int count = pot + M;
while(count >= size)
{
count = count - size;
}
std::list<Person>::iterator player = circ.begin();
advance (player, count);
eliminated = *player;
circ.erase(player);
size--;
pot = count;
return eliminated;
}


//prints all of the players remaining in the game
void ListMyJosephus :: printAll()
{
Person printer;
cout<< "remaining players" << endl;
for(std::list<Person>::iterator  player=circ.begin() ; player != circ.end() ; ++player)
{
printer = *player;
cout<<' '<< printer.getPerson();

}
cout << endl;

}








