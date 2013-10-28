#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class arrayStack
{
public:
	arrayStack(int size=101)
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
	int m,n;
	cin>>m;
	vector< arrayStack<int> > stacks(m);
	for(int i=0;i<m;i++)
	{
		cin>>n;
		bool flag=true;
		for(int j=0;j<n;j++)
		{
			string op;
			cin>>op;
			if(op=="push")
			{
				int num;
				cin>>num;
				stacks[i].push(num);
			}
			else if(op=="pop")
			{
				int p;
				if(!stacks[i].pop(p))
				{
					//cout<<"error"<<endl;
					flag=false;
					//break;
				}
			}
		}
		if(flag)
		{
			arrayStack<int> tmp_stack;
			int a;
			if(stacks[i].isEmpty())
			{
				cout<<endl;
			}
			else
			{
				while(stacks[i].pop(a))
					tmp_stack.push(a);
				if(tmp_stack.pop(a))
					cout<<a;
				while(tmp_stack.pop(a))
				{
					cout<<" "<<a;
				}
				cout<<endl;
			}
		}
		else
		{
			cout<<"error"<<endl;
		}
	}
	return 0;
}
