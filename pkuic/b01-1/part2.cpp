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
	return;
}


int main()
{
	vector<int> odd;
	vector<int> even;
	for(int i=0;i<10;i++)
	{
		int t;
		cin>>t;
		if(t%2==0)
			even.push_back(t);
		else
			odd.push_back(t);
	}

	sort1(odd);
	sort1(even);
	for(int i=0;i<odd.size();i++)
	{
		cout<<odd[i]<<" ";
	}
	for(int i=0;i<even.size();i++)
	{
		cout<<even[i]<<" ";
	}


	return 0;
}
