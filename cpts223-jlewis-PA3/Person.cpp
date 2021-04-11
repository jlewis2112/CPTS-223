#include"Person.h"


//constructor
Person :: Person()
{

position = 0;
}

//destructor
Person :: ~Person()
{


}

//getter for the integer person
int Person :: getPerson()
{

return position;
}

//setter for the integer person
void Person :: setPerson(int positionx)
{

position = positionx; 
}

//prints the position of a player
void Person :: print()
{
cout << position << endl;
}


