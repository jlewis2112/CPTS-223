#include"VectorMyJosephus.h"




//constructor

VectorMyJosephus :: VectorMyJosephus()
{

 size=0;
 N=0;
 M=0;
pot=0;
}


//copy constructor
VectorMyJosephus :: VectorMyJosephus(int Nx, int Mx)
{
M=Mx;
N=Nx;
size=Nx;
pot=0;

}

//destructor
VectorMyJosephus :: ~VectorMyJosephus()
{

circ.clear();
pot=0;
size=0;
N=0;
M=0;
}

//used to created a new game.
//this function assigns values and adds the players to circ. 
void VectorMyJosephus :: init(int  Nx, int Mx)
{
M=Mx;
N=Nx;
pot=0;
size=Nx;
Person entree;
for(int a=0 ; a <  N; a++)
{
entree.setPerson(a);
circ.push_back(entree);

}

}

//clears circ
void VectorMyJosephus :: clearx()
{
circ.clear();
}
//prints out the number of players still in the game
void  VectorMyJosephus :: currentSize()
{
cout<< size << endl ;
}


//determines if circ is empty
bool VectorMyJosephus :: isEmpty()
{
bool result = false;
if((circ.empty()) && (size==0))
{
result = true;

}


return result;
}

//this functions returns the eliminated player and deletes the player from circ
Person VectorMyJosephus ::  eliminateNext()
{
Person eliminated;
int count = pot + M ;

while(count  >=  size)
{
count = count - size;
}

eliminated = circ[count];
circ.erase(circ.begin()+count);
size--;
pot = count;
return eliminated;
}


//prints all of the players in circ
void VectorMyJosephus :: printAll()
{
Person printer;
cout<<"remaining players" << endl;
for(int a=0; a < size ; a++)
{
printer = circ[a];
cout<<' '<<printer.getPerson();

}
cout << endl;

}



