#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n/2;i++)
	{
		int t;
		t=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=t;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
