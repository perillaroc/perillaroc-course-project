#include <iostream>
#include <vector>

using namespace std;

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

bool isOperator(char ch)
{
	switch(ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
		return true;
		break;
	default:
		return false;
		break;
	}
}

int readNumber(const string &input, int &curpos)
{
	int result=0;
	while(input[curpos]>='0' && input[curpos]<='9')
	{
		result=result*10+static_cast<int>(input[curpos]-'0');
		curpos++;
	}
	return result;
}

int operatorPriority(char op)
{
	switch(op)
	{
	case '(':
		return 0;
		break;
	case '+':
	case '-':
		return 1;
		break;
	case '*':
	case '/':
		return 2;
		break;
	default:
		return -1;
		break;
 	}
}

int calculateByOperator(int a, char op, int b)
{
	switch(op)
	{
	case '+':
		return a+b;
		break;
	case '-':
		return a-b;
		break;
	case '*':
		return a*b;
		break;
	case '/':
		return a/b;
		break;
	}
}

int main()
{
	int n;
	cin>>n;
	char a;
	a=cin.get();
	ArrayStack<char> operator_stack;
	ArrayStack<int> num_stack;
	for(int i=0;i<n;i++)
	{
		operator_stack.clear();
		num_stack.clear();
		string input;
		getline(cin,input);

		int curpos=0;
		int length=input.length();
		while(curpos<length)
		{
			if(isOperator(input[curpos]))
			{
				if(input[curpos]=='(')
				{
					operator_stack.push(input[curpos]);
				}
				else if(input[curpos]==')')
				{
					char c;
					while(operator_stack.pop(c) && c!='(')
					{
						int a,b;
						num_stack.pop(a);
						num_stack.pop(b);
						int r=calculateByOperator(b,c,a);
						num_stack.push(r);
					}
				}
				else
				{
					int cur_p=operatorPriority(input[curpos]);
					char op2;
					while(!operator_stack.isEmpty() && operator_stack.top(op2) && op2!='(' && 
						operatorPriority(op2)>=cur_p )
					{
						operator_stack.pop(op2);
						int a,b;
						num_stack.pop(a);
						num_stack.pop(b);
						int r=calculateByOperator(b,op2,a);
						num_stack.push(r);

					}
					operator_stack.push(input[curpos]);
				}
				curpos++;
			}
			else
			{
				num_stack.push(readNumber(input,curpos));
			}
		}
		char op;
		while(operator_stack.pop(op))
		{
			int a,b;
			num_stack.pop(a);
			num_stack.pop(b);
			int r=calculateByOperator(b,op,a);
			num_stack.push(r);
		}
		int a;
		num_stack.pop(a);
		cout<<a<<endl;
	}
	return 0;
}
