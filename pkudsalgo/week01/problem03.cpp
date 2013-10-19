/**
 * week 1 problem 3
 * bit operation
 */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int num_count,op_count;
	cin>>num_count>>op_count;
	vector<int> nums(num_count);
	vector<int> query_results;
	for(int i=0;i<num_count;i++)
	{
		cin>>nums[i];
	}
	for(int i=0;i<op_count;i++)
	{
		char op;
		int a;
		cin>>op>>a;
		int t=0;
		if(op=='C')
		{
			for(int j=0;j<nums.size();j++)
			{
				nums[i]=(nums[i]+a)%65536;
			}
		}
		if(op=='Q')
		{
			int n=0;
			for(int j=0;j<num_count;j++)
			{
				int t=nums[j]>>a;
				if(t%2==1)
					n++;
			}
			cout<<n<<endl;
		}
	}
	return 0;
}
	
