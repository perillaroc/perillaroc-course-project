/**
 * week 1 problem 1
 * add
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct polyitem{
	int c;
	int exp;
	friend bool operator< (const polyitem& left, const polyitem& right)
	{
		return left.exp<right.exp;
	}
};
int main()
{
	int n=0;
	cin>>n;
	vector< vector<polyitem> > results; 
	for(int i=0;i<n;i++)
	{
		vector<polyitem> a_poly;
		int c,exp;
		while(cin>>c>>exp)
		{
			if(exp<0)
				break;
			polyitem a_item;
			a_item.c=c;
			a_item.exp=exp;
			a_poly.push_back(a_item);
		}
		while(cin>>c>>exp)
		{
			if(exp<0)
				break;
			int j=0;
			for(j=0;j<a_poly.size();j++)
			{
				if(a_poly[j].exp==exp)
				{
					a_poly[j].c+=c;
					break;
				}
					
			}
			if(j==a_poly.size())
			{
				polyitem a_item;
				a_item.c=c;
				a_item.exp=exp;
				a_poly.push_back(a_item);
			}
		}
		results.push_back(a_poly);
	}
	
	for(int i=0;i<n;i++)
	{
		sort(results[i].rbegin(),results[i].rend());
		for(int j=0;j<results[i].size();j++)
		{
			if(results[i][j].c==0)
				continue;
			if(j!=0)
				cout<<" ";
			cout<<"[ "<<results[i][j].c<<" "<<results[i][j].exp<<" ]";
		}
		cout<<endl;
	}
	return 0;
}
