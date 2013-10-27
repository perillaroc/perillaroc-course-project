#include <iostream>
#include <cstdlib>

using namespace std;

template <class T> 
class arrQueue{ 
private: 	
	int 	mSize; 						// 存放队列的数组的大小
	int 	front;							// 表示队头所在位置的下标
	int 	rear;							// 表示队尾所在位置的下标
	T 	    *qu;							// 存放类型为T的队列元素的数组
public: 								// 队列的运算集
   	arrQueue(int size=120)  {    				// 创建队列的实例
		mSize = size +1;					// 浪费一个存储空间，以区别队列空和队列满
		qu = new T[mSize];
		front = rear = 0;
}
   	~arrQueue()  {  					// 消除该实例，并释放其空间
		delete [] qu;
}
void clear() {						// 清空队列
	front = rear; 
}
   	bool enQueue(const T item)  { 			//  item入队，插入队尾
		if (((rear + 1 ) % mSize) == front) {
			return false;
		}
		qu[rear] = item;
		rear = (rear +1) % mSize;  			// 循环后继
		return true;
	}
 	bool deQueue(T*item)  {     			// 返回队头元素并从队列中删除
		if ( front == rear)  {
			return false;
		}
		*item = qu[front];
		front = (front +1) % mSize;
		return true;
 	}
    bool getFront(T* item) {	     			// 返回队头元素，但不删除
		if (front == rear)  {
			return false;
		}
		*item = qu[front];
		return true;
	}
	void print() {	     			// 返回队头元素，但不删除
		if (front == rear)  {
		}
		int p = front;
		while(p != rear ) {
              cout << qu[p] << " ";
              p =( p + 1)  % mSize;  
        } 
        cout << endl;
	}
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
	arrQueue<Card> queues[9];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int p;char c;
		cin>>c>>p;
		Card a_card(c,p);
		queues[p-1].enQueue(a_card);
	}	
	arrQueue<Card> color_queues[4];
	for(int i=0;i<9;i++)
	{
		cout<<"Queue"<<i+1<<":";
		Card a_card;
		int j=0;
		while(queues[i].deQueue(&a_card))
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
	for(int i=0;i<4;i++)
	{
		int j=0;
		Card a_card;
		cout<<"Queue";
		cout<<char('A'+i)<<":";
		while(color_queues[i].deQueue(&a_card))
		{
			if(j!=0)
				cout<<" ";
			a_card.print();
			j++;
			queues[0].enQueue(a_card);
		}
		cout<<endl;
	}
	Card a_card;
	if(queues[0].deQueue(&a_card))
		a_card.print();
	while(queues[0].deQueue(&a_card))
	{
		cout<<" ";
		a_card.print();
	}
	cout<<endl;
	return 0;
}
