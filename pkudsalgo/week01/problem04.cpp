/**
 *  week 1 problem 4
 *  put apple
 */

#include <iostream>
#include <vector>
using namespace std;
int apple_problem(int m, int n)
{
	if(m<0 || n<0)
		return 0;
	else if(m==0)
		return 1;
	else if(n==1)
		return 1;
	else
		return apple_problem(m-n,n)+apple_problem(m,n-1);
}
int main()
{
	int count;
	cin>>count;
	vector<int> results;
	while(count-->0)
	{
		int m,n;
		cin>>m>>n;
		results.push_back(apple_problem(m,n));
	}
	for(int i=0;i<results.size();i++)
	{
		cout<<results[i]<<endl;
	}
	return 0;
}
