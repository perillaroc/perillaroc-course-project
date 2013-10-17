// count of 1
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int t;
		int s=0;
		cin>>t;
		int b=0;
		while(t>0)
		{
			if(t%2==1)
				s++;
			t=t/2;
		}
		a.push_back(s);
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}		
