#include"VectorMyJosephus.h"

//this main function is used to test Josephus using the vector

int main(void)
{
//declaring and assigning variables 
int a = 0;
int passes=0;
int size=0;
vector<int> result;
int winner=0;
Person reciever;
VectorMyJosephus gamelist;

cout<<"enter the number of players"<<endl;
cin >> size;
cout << "enter the number of passes which is M" << endl;
cin >> passes;
gamelist.init(size, passes);
auto  startgame = std::chrono::steady_clock::now();
//begin the game
while(gamelist.isEmpty() != true)
{

reciever = gamelist.eliminateNext();
//used to determine the winner
if(gamelist.isEmpty() == true)
{
winner = reciever.getPerson();

}
else
{
//add a losing player to the list used to determine the order of elemination
result.push_back(reciever.getPerson());
//prints out who is still alive
cout<<"currently alive"<<endl;
gamelist.currentSize();
gamelist.printAll();
}
a++;
}
//the game is over
auto endgame = std::chrono::steady_clock::now();
//prints out the order of elimination
cout<<"the final results"<<endl;
for(int b=0; b <(size -1); b++)
{
cout<<' '<<result[b];

}
//prints out the winner and the running times in the experiment
cout<<endl;
cout<<"the winner is"<< endl;
cout<< winner << endl;
cout<<"total game time in microseconds" << endl;
cout<< std::chrono::duration_cast<std::chrono::microseconds>(endgame - startgame).count()<<endl;
cout<<"average elimination time in microseconds"<< endl;
cout<< std::chrono::duration_cast<std::chrono::microseconds>((endgame - startgame)/size).count()<<endl;
return 0;
}




