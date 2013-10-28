#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T> struct ArrayQueue
{
	ArrayQueue(int n=2000){
		max_size_=n;
		inner_vector_.resize(max_size_);
		front_=1;
		rear_=0;
	}

	void clear()
	{
		front_=rear_+1;
	}
	
	bool enQueue(const T &item){
		if((rear_+2)%max_size_ == front_)
			return false;
		rear_ = (rear_+1)%max_size_;
		inner_vector_[rear_]=item;
		return true;
	}
	bool deQueue(T &item)
	{
		if(length()==0)
			return false;
		item=inner_vector_[front_];
		front_ = (front_+1)%max_size_;
		return true;
	}

	int length()
	{
		return (max_size_+rear_-front_+1)%max_size_;
	}

	bool front(T &item)
	{
		if(length()==0)
			return false;
		item=inner_vector_[front_];
		return true;
	}

private:
	vector<T> inner_vector_;
	int max_size_;
	int front_;
	int rear_;
};

template <typename T>
class ArrayStack
{
public:
	ArrayStack(int size=2000)
	{
		array.resize(size);
		max_size_=size;
		clear();
	}

	void clear()
	{
		top_=-1;
	}
	bool push(const T item)
	{
		if(isFull())
			return false;
		array[++top_]=item;
		return true;
	}
	bool pop(T &item)
	{
		if(isEmpty())
			return false;
		item=array[top_--];
		return true;
	}
	bool top(T &item)
	{
		if(isEmpty())
			return false;
		item=array[top_];
		return true;
	}
	bool isEmpty()
	{
		return top_==-1;
	}
	bool isFull()
	{
		return top_==max_size_;
	}
private:
	int max_size_;
	int top_;
	vector<T> array;
};

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		ArrayQueue<int> queue;
		ArrayStack<int> stack;
		string str;
		bool finished=false;
		for(int j=0;j<n;j++)
		{
			int op,num;
			cin>>op>>num;
			if(!finished)
			{
			if(op==1)
			{
				queue.enQueue(num);
				stack.push(num);
			}
			else if(op==2)
			{
				int t;
				if(!(queue.deQueue(t) && t==num) )
				{
					finished=true;
					str="Stack";
				}
				if(!(stack.pop(t) && t==num) )
				{
					finished=true;
					str="Queue";
				}
			}
			}
		}
		cout<<str<<endl;
	}
	return 0;
}
