#include <iostream>
#include <vector>
using namespace std;

template<typename T> struct MyArrayQueue
{
	MyArrayQueue(int n){
		max_size_=n;
		inner_vector_.resize(max_size_);
		front=1;
		rear=0;
	}

	void clear()
	{
		front=rear+1;
	}
	
	bool enQueue(const T &item){
		if((rear+2)%max_size_ == front)
			return false;
		rear = (rear+1)%max_size_;
		inner_vector_[rear]=item;
		return true;
	}
	bool deQUeue(T &item)
	{
		if(length()==0)
			return false;
		item=inner_vector_[front];
		front = (front+1)%max_size_;
		return true;
	}

	int length()
	{
		return (max_size_+rear-front+1)%max_size_;
	}

	bool frontItem(T &item)
	{
		if(length()==0)
			return false;
		item=inner_vector_[front];
		return true;
	}

private:
	vector<T> inner_vector_;
	int max_size_;
	int front;
	int rear;
};

int main()
{
	int n;
	cin>>n;
	MyArrayQueue<int> mq(n+1);
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		mq.enQueue(t);
	}
	return 0;
}
