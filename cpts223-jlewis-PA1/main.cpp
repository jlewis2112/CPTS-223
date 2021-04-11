#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::ifstream;


// crediting this site for helping me create a class that allow nullptr to 
// be defined in linux www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2431.pdf
//this class is used to defined a pointer a null.

const class
{
public:
template<class T>
operator T*() const
{
return 0;
}
template<class C, class T>
operator T C::*() const
{
return 0;
}
private:
void operator&() const;
}nullptr ={};





//this class is the node of the linked list

class listnode
{
public:
listnode();
listnode(listnode &copy);
~listnode();

int getnumber();
listnode * getnext();

void setnext(listnode *next);
void setnumber(int numberx);

private:

int number;
listnode *pNext;
};


//this is the constructor

listnode :: listnode()
{
number=0;
this->pNext=nullptr;
};


listnode :: listnode(listnode &copy)
{
this->pNext= copy.getnext();
number=copy.getnumber();
};

//this is the deconstructor
listnode :: ~listnode()
{

};


//this is the getters functions for listnode


int listnode :: getnumber()
{

return number;

};


listnode * listnode :: getnext()
{

return this->pNext;

};


//this is the setter functions for listnode

void listnode :: setnext(listnode *next)
{
this->pNext=next;
};


void listnode :: setnumber(int numberx)
{

number = numberx;

};

//this is the class that is the overall list

class list
{
public:
list();
list(list &copyList);
~list();

listnode * gethead();
void setHeadPtr(listnode * const pNewHead);

void insertinorder(int newData);

int findbig();
int findsmall();
int findmed(int amount);

private:

listnode *mpHead;
listnode * makeNode(int newData);

void destroyList();
void destroyListHelper(listnode * const pMem);
};

//these are constructors for the class list. one creates memory, while the
//other creates a deep copy.

//creates memory for mpHead
list :: list()
{
mpHead=nullptr;
};

//this functions initiates a deep copy
list :: list(list &copyList)
{

listnode *newData;
listnode *pNextx;

pNextx = copyList.gethead();

while (pNextx != NULL)
{
newData = makeNode(pNextx->getnumber());

mpHead = newData;
mpHead = mpHead;
pNextx = pNextx->getnext();
}

};



// this is the deconstructor for the list.
// calls the function destroy list to destroy the list.

list :: ~list()
{
destroyList();
};




//these are the getters for the list class


listnode * list:: gethead()
{

return mpHead;

};

//these are the setters for the list class


void list::setHeadPtr(listnode * pNewHead)
{
mpHead=pNewHead;
};


//this function inserts listodes in the list from least to greatest
//by creating a new node from the input data and comparing them to other nodes.
//This function organizes from least to greatest.

void list :: insertinorder(int newData)
{

listnode *pMem = makeNode(newData);
listnode *pPrev= nullptr;
listnode *pCur= this->mpHead;

if (mpHead != nullptr)
{

while((pCur != nullptr)&&(pCur->getnumber()<newData))
{
pPrev = pCur;
pCur = pCur->getnext();
}

if(pPrev != nullptr)
{
pPrev->setnext(pMem);
pMem->setnext(pCur);
}
else
{
mpHead = pMem;
pMem->setnext(pCur);
}

}
else
{
pMem->setnext(mpHead);
mpHead=pMem;
}

};




//this function finds the greatest number in the list

int list::findbig()
{

listnode *pCur = this->mpHead;

while (pCur->getnext() != nullptr)
{

pCur = pCur->getnext();
}

return pCur->getnumber();
};


//this function finds the smallest number in the list

int list::findsmall()
{

return this->mpHead->getnumber();

};

//this function finds the median of the list

int list :: findmed(int amount)
{

listnode *pCur = this->mpHead;
int result=0;
int number1=0, number2=0;

if((amount / 2) ==0)
{

for(int b=0; b<= (amount/2); b++)
{
pCur = pCur->getnext();
}
number1= pCur->getnumber();

pCur= pCur->getnext();

number2 = pCur->getnumber();

result=((number1 + number2) / 2);

}
else
{
for(int a=0; a <= ((amount / 2)+1); a++)
{

pCur = pCur->getnext();


}

result = pCur->getnumber();
}

return result;

};

//this function creates a new node using an integer as an input



listnode * list::makeNode(int newData)
{
listnode *pMem = new listnode();
pMem->setnumber(newData);

return pMem;
}

//these functions are called in the list deconstructer to delete the list

void list::destroyListHelper(listnode * pMem)
{
if(pMem != nullptr)
{
destroyListHelper(pMem->getnext());
delete pMem;
}
}

void list::destroyList()
{

destroyListHelper(mpHead);

}




//this is the main function


//The main function promps the user to type a file name. If the file name requested is in the PA1 folder, then the program will start reading data from the list.
//Time intervals are recorded during the insertion of nodes and finding the min, max, and med by finding 2 time intervalls using time(NULL)
//and using subraction.
//The main prints out the results as well.

int main(void)
{

// declaring variables
list file1;



ifstream infile1;




int info1 =0;
int count1=0;
int big1=0, small1=0, median1=0;
string filename;

int timebig1a=0, timebig1b=0, timebig1=0, timesmall1a=0, timesmall1b=0, timesmall1=0, timemed1a=0, timemed1b=0, timemed1=0;
clock_t clock1;
clock_t clock2;
clock_t clock3;
clock_t clock4;


int timeins1a=0, timeins1b=0, timeins1=0;

//prompting user to enter the file name


cout <<"enter file name" << endl;
cin >> filename;

//determining if the file exists

infile1.open(filename.c_str());
if(infile1)
{

//begin reading the numeric data and entering it to the list
clock1 = clock();

timeins1a=time(NULL);
while(!infile1.eof())
{
infile1 >> info1;
file1.insertinorder(info1);
count1++;
}
clock1=clock()-clock1;
timeins1b = time(NULL);

timeins1 = timeins1b - timeins1a;

//finding the largest number in the list
//note: The time to complete a processes is recorded by the current recorded time minus the last recorded time before the algothrithm is executed.
// For example timebig1a is recorded before the this algorithm is executed and time1b is the time recorded after the algorithm is executed.
// To find the total time (timebig) we subtract timebigb by timebiga.



clock2 = clock();
timebig1a=time(NULL);
big1 = file1.findbig();
timebig1b = time(NULL);
timebig1 = timebig1b  - timebig1a;
clock2=clock()-clock2;

clock3 = clock();
timesmall1a= time(NULL);
small1 = file1.findsmall();
timesmall1b= time(NULL);
timesmall1= timesmall1b - timesmall1a;
clock3=clock()-clock3;

//finding the median in the list

clock4 = clock();
timemed1a = time(NULL);
median1= file1.findmed(count1);
timemed1b = time(NULL);
timemed1 = timemed1b - timemed1a;
clock4= clock() - clock4;

//printing out the data

cout << "min= " << small1 << " max= " << big1 << " med= " << median1 << endl;
cout<< "time_insert= " << timeins1 << " s " <<(( int)((double)clock1/(CLOCKS_PER_SEC)*100)%100) << " cs" << endl;
cout<< " time_min= " << timesmall1 << " s "  <<(( int)((double)clock3/(CLOCKS_PER_SEC)*100)%100) << " cs" << endl;
cout << " time_max= " << timebig1 << " s "  <<(( int)((double)clock2/(CLOCKS_PER_SEC)*100)%100) << " cs" << endl;
cout << " time_med= " << timemed1 << " s "  <<(( int)((double)clock4/(CLOCKS_PER_SEC)*100)%100) <<  " cs" << endl;



}
else
{
cout<< "file does not exists" << endl;

}

infile1.close();


return 0;

}























































