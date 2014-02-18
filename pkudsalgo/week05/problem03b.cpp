#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
public:
    MinHeap();
    void insert(int a_num);
    int top();
    void pop();
    int parent(int position);
    int currentSize();
    void printHeap();
private:
    void shiftDown(int position);
    void shiftUp(int position);

    vector<int> values_;
    int max_size_;
    int current_size_;
};

MinHeap::MinHeap()
{
    max_size_ = 102;
    values_.resize(max_size_,0);
    current_size_ = 0;
}

int MinHeap::currentSize()
{
    return current_size_;
}

int MinHeap::parent(int position)
{
    if(position!=0)
        return position/2;
    else
        return -1;
}

void MinHeap::printHeap()
{
    for(int i=0;i<current_size_;i++)
    {
        cout<<values_[i]<<" ";
    }
    cout<<endl;
}

void MinHeap::shiftUp(int position)
{
    int pos = position;
    int temp = values_[position];
    while((pos>0)&&(values_[pos]<values_[parent(pos)]))
    {
        values_[pos] = values_[parent(pos)];
        pos = parent(pos);
    }
    values_[pos] = temp;
}

void MinHeap::shiftDown(int position)
{
    int i = position;
    int temp = values_[position];
    int j = 2*i + 1;
    while(j<current_size_)
    {
        if(values_[j]>values_[j+1])
            j++;
        if(values_[j]<temp)
        {
            values_[i] = values_[j];
            i = j;
            j = 2*i+1;
        }
        else
            break;
    }
    values_[i] = temp;
    return;
}
void MinHeap::insert(int a_num)
{
    values_[current_size_] = a_num;
    current_size_++;
    shiftUp(current_size_-1);
}

void MinHeap::pop()
{
    values_[0] = values_[--current_size_];
    shiftDown(0);
}

int MinHeap::top()
{
    if(current_size_)
        return values_[0];
    else
        return -1;
}

void takeOneTest()
{
    int num_count;
    cin>>num_count;
    MinHeap heap;
    for(int i=0;i<num_count;i++)
    {
        int num;
        cin>>num;
        heap.insert(num);     
    }
    //heap.printHeap();
    int total_sum = 0;
    while(heap.currentSize()>=2)
    {
        int min1 = heap.top();
        heap.pop();

        int min2 = heap.top(); 
        heap.pop();

        int current_sum = min1 + min2;
        total_sum+=current_sum;
        heap.insert(current_sum);
        //heap.printHeap();
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
    

