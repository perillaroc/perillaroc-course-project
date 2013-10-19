#include <iostream>
using namespace std;
int main()
{
	char str[16];
	char substr[4];
	while(cin>>str>>substr)
	{
		int maxpos=0;
		int curpos=1;
		char maxchar=str[maxpos];
		while(str[curpos]!='\0')
		{
			if(str[curpos]>maxchar)
			{
				maxpos=curpos;
				maxchar=str[curpos];
			}
			curpos++;
		}
		for(int i=curpos;i>=maxpos+1;i--)
		{
			str[i+3]=str[i];
		}
		for(int i=1;i<=3;i++)
		{
			str[maxpos+i]=substr[i-1];
		}
		cout<<str<<endl;
	}
	return 0;
}
