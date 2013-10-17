#include <iostream>
#include <vector>

using namespace std;

void sort1(vector<int> &a)
{
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<n-i;j++)
		{
			if(a[j-1]>a[j])
			{
				int t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;
			}
		}
	}
}


int main()
{
	vector<int> a(10);
	for(int i=0;i<10;i++)
	{
		int t;
		cin>>a[i];
	}

	sort1(a);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]%2==1)
			cout<<a[i]<<" ";
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]%2==0)
			cout<<a[i]<<" ";
	}

	return 0;
}
