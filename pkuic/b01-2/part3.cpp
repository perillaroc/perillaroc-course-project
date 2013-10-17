#include <iostream>
using namespace std;

int main()
{
	int k;
	cin>>k;
	int one=0;
	int five=0;
	int ten=0;
	for(int i=0;i<k;i++)
	{
		int t;
		cin>>t;
		switch(t)
		{
		case 1:
			one++;
			break;
		case 5:
			five++;
			break;
		case 10:
			ten++;
			break;
		}
	}
	cout<<one<<endl;
	cout<<five<<endl;
	cout<<ten<<endl;
	return 0;
}
