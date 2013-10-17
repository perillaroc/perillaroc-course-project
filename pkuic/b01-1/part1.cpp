#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums;
    int total=0;
    cin>>total;
    for(int i=0;i<total;i++)
    {
        int t;
	cin>>t;
	nums.push_back(t);
    }

    for(int i=0;i<total-1;i++)
    {
    	for(int j=1;j<total-i;j++)
	{
             if(nums[j-1]>nums[j])
	     {
	         int t=nums[j-1];
		 nums[j-1]=nums[j];
		 nums[j]=t;
             }
	}
    }
    
    for(int i=0;i<total;i++)
    {
        cout<<nums[i]<<endl;
    }
    return 0;
}
