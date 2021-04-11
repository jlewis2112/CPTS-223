#include"ListMyJosephus.h"

//this main function is used to test josephus using a list

int main(void)
{
//declaring and assigning values
int a=0;
int passes=0;
int size=0;
vector<int> result;
int winner = 0;
Person reciever;
ListMyJosephus gamelist;
cout<<"enter the number of players"<< endl;
cin >>  size;
cout<<"enter the number of passes which is M" << endl;
cin >> passes;

gamelist.init(size, passes);
//the game has began
auto startgame = std::chrono::steady_clock::now();
while(gamelist.isEmpty() != true)
{
//eliminate a player
reciever = gamelist.eliminateNext();
//used to determine the winner
if(gamelist.isEmpty() == true)
{
winner = reciever.getPerson();
}
else
{
result.push_back(reciever.getPerson());
}
cout<<"currently alive"<< endl;
gamelist.currentSize();
gamelist.printAll();
a++;
}

//the game has ended
auto endgame = std::chrono::steady_clock::now();
//prints the order of the eliminations
cout<<"the final results"<< endl;
for(int b=0; b <(size - 1); ++b)
{
cout<<' '<< result[b];
}
cout<<endl;
//prints the winner and the running time used in the experiments
cout<<"the winner is"<< endl;
cout<<winner<<endl;
cout<<"total time in microseconds" << endl;
cout<< std::chrono::duration_cast<std::chrono::microseconds>(endgame - startgame).count()<< endl;
cout<<"average elimination time in microseconds" << endl;
cout<< std::chrono::duration_cast<std::chrono::microseconds>((endgame - startgame)/size).count()<< endl;

return 0;
}
