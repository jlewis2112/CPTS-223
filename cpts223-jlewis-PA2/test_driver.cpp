#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<chrono>

using std :: atoi;
using std :: string;
using std :: cin;
using std :: cout;
using std :: endl;
using std :: ostream;
using std :: ifstream;
using std :: vector;
using std :: stringstream;
using namespace  std :: chrono;

//declaring functions

int maxSubSum1( const vector<int> & a);
int maxSubSum2( const vector<int> & a);
int maxSumRec(const vector<int> & a, int left, int right);
int maxSubSum3(const vector<int> & a);
int maxSubSum4( const vector<int> & a);



//This function is maxSubSum1, which was included in the assignment

int maxSubSum1(const vector<int> & a)
{

int maxSum = 0;

for (int i=0; i < a.size(); ++i)
{
for(int j=i; j < a.size(); ++j)
{
int thisSum = 0;

for(int k=i; k <= j ; ++k)
{
thisSum += a[k];

}
if( thisSum > maxSum)
{
maxSum = thisSum;
}
}

}
return maxSum;
}



//this is the function maxSubSum2, which was included with the assignment

int maxSubSum2( const vector<int> & a)
{
int maxSum = 0;

for ( int i=0; i < a.size(); ++i)
{
int thisSum =0;
for(int j=i; j < a.size(); ++j)
{
 thisSum += a[j];

if (thisSum > maxSum)
{
maxSum = thisSum;
}

}

}

return maxSum;
}

//this is the function maxSumRec.  This is included with the assignment and is declared in the
//function maxSubSum3.
int maxSumRec( const vector<int> & a, int left, int right)
{
if(left == right )
{
if(a[left] > 0)
{
return a[left];
}
else
{
return 0;
}
}

int center = (left + right) / 2;
int maxLeftSum = maxSumRec( a, left, center);
int maxRightSum = maxSumRec( a,(center + 1), right);

int maxLeftBorderSum = 0, leftBorderSum=0;
for( int i = center; i >= left; --i)
{
leftBorderSum += a[i];
if(leftBorderSum > maxLeftBorderSum)
{
maxLeftBorderSum = leftBorderSum;
}
}


int maxRightBorderSum = 0, rightBorderSum=0;
for(int j = center + 1; j <= right; ++j)
{
rightBorderSum += a[j];

if( rightBorderSum > maxRightBorderSum)
{
maxRightBorderSum = rightBorderSum;

}
}

if((maxLeftSum > maxRightSum)&&(maxLeftSum > maxLeftBorderSum + maxRightBorderSum))
{

return maxLeftSum;
}
else if((maxRightSum > maxLeftSum) && (maxRightSum > maxLeftBorderSum + maxRightBorderSum))
{
return maxRightSum;
}
else
{
return(maxLeftBorderSum + maxRightBorderSum);
}
}

//this is the function maxsubsum3.  This function was included with the assignment
int maxSubSum3( const vector<int> & a)
{

return maxSumRec(a, 0, a.size() - 1);
}


//this is the function maxsubsum4. This function was include with the assignment
int maxSubSum4( const vector<int> & a)
{
int maxSum = 0, thisSum = 0;

for( int j=0; j < a.size(); ++j)
{
thisSum += a[j];
if (thisSum > maxSum)
{
maxSum = thisSum;
}
else if(thisSum < 0)
{
thisSum = 0;
}
}

return maxSum;
}


//This is the main.  The main is used to read a text file full of integers and create an integer 
//vector array using the given results.  The array will then be used as a test subject
//to determine running time for four different functions using the chrono library.

int main(void)
{
//declaring variables
ifstream infile;

string filename;
char  numberscan[200];

int result1=0, result2=0, result3=0, result4=0;
int enter=0;




vector<int> array;

//promps the user to enter the name wanted text file wanting that will be scanned

cout<< "enter file Name" << endl;
cin >> filename;

infile.open(filename.c_str());

if(infile)
{

//scaning every integer in the text file and adding it to the vector array
while(!infile.eof())
{
infile.getline(numberscan, 3);
enter = atoi(numberscan);
array.push_back(enter);
}


//testing for maxSubSum1
auto start = std::chrono::steady_clock::now();
result1 = maxSubSum1(array);
auto end = std::chrono::steady_clock::now();

cout<<"results for maxSubSum1 maxSubSum: " << result1 << " time: " <<std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()  << " microseconds" << endl;

//testing for maxSubSum2
auto start2 = std::chrono::steady_clock::now();
result2 = maxSubSum2(array);
auto end2 = std::chrono::steady_clock::now();
cout<<"result for maxSubSum2 maxSubSum: " << result2 << " time: " <<std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds" <<  endl;

//testing for maxSubsum3
auto start3 = std::chrono::steady_clock::now();
result3 = maxSubSum3(array);
auto end3 = std::chrono::steady_clock::now();

cout<<"result for maxSubSum3 maxSubSum: " << result3 << " time: " <<std::chrono::duration_cast<std::chrono::microseconds>(end3-start3).count()<< " microseconds" << endl;

//testing for maxSubsum4
auto start4 = std::chrono::steady_clock::now();
result4 = maxSubSum4(array);
auto end4 = std::chrono::steady_clock::now();

cout<< "result for maxSubSum4 maxSubSum: " << result4 << " time: " <<std::chrono::duration_cast<std::chrono::microseconds>(end4-start4).count() << " microseconds" <<  endl;




}

infile.close();
return 0;
}
















