#include <iostream>
#include <vector>
using namespace std;

template<typename T> struct MyArrayQueue
{
	MyArrayQueue(){
		max_size_=102;
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
	bool deQueue(T &item)
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

struct Card
{
	Card()
	{
		color='\0';
		point=-1;
	}
	Card(char c,int p)
	{
		color=c;
		point=p;
	}
	void print()
	{
		cout<<color<<point;
	}
	char color;
	int point;
};

int main()
{
	vector< MyArrayQueue<Card> > queues(9);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int p;char c;
		cin>>c>>p;
		Card a_card(c,p);
		queues[p-1].enQueue(a_card);
	}
	vector< MyArrayQueue<Card> > color_queues(4);
	for(int i=0;i<9;i++)
	{
		cout<<"Queue"<<i+1<<":";
		Card a_card;
		int j=0;
		while(queues[i].deQueue(a_card))
		{
			int x=static_cast<int>(a_card.color-'A');
			color_queues[x].enQueue(a_card);
		    if(j!=0)
				cout<<" ";
			a_card.print();
			j++;
		}
		cout<<endl;
	}
	int j=0;
	for(int i=0;i<4;i++)
	{
		Card a_card;
		while(color_queues[i].deQueue(a_card))
		{
			if(j!=0)
				cout<<" ";
			a_card.print();
			j++;
		}
	}
	cout<<endl;
	
	return 0;
}
