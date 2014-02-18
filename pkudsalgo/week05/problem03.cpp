#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void takeOneTest()
{
    int num_count;
    cin>>num_count;
    vector<int> array(num_count);
    for(int i=0;i<num_count;i++)
    {
        cin>>array[i];
    }
    int total_sum = 0;

    make_heap(array.begin(), array.end(), greater<int>());
    
    while(array.size()>=2)
    {
        pop_heap(array.begin(), array.end(), greater<int>());
        int min1 = array.back();
        array.pop_back();

        pop_heap(array.begin(), array.end(), greater<int>());
        int min2 = array.back();
        array.pop_back();
        
        int current_sum = min1 + min2;
        total_sum+=current_sum;
        array.push_back(current_sum);
        push_heap(array.begin(), array.end(), greater<int>());
    }

    cout<<total_sum<<endl;
}

int main()
{
    int count;
    cin>>count;
    while(count--)
    {
        takeOneTest();
    }
    return 0;
}
