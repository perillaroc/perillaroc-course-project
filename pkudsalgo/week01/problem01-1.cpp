#include <iostream>
#include <vector>
using namespace std;
struct SingleLink{
	SingleLink()
	{
		next=0;
	}
	SingleLink *next;
	int c;
	int exp;
};

void add_to_poly(SingleLink *head, int c, int exp)
{
	SingleLink *p=head->next;
	SingleLink *pre=head;
	while(p!=0)
	{
		if(p->exp==exp)
		{
			p->c+=c;
			break;
		}
		else if(p->exp > exp)
		{
			pre=p;
			p=p->next;
		}
		else if(p->exp < exp)
		{
			// insert between pre and p
			SingleLink *a=new SingleLink();
			a->c=c;
			a->exp=exp;
			a->next=p;
			pre->next=a;
			break;
		}
	}
	if(p==0)
	{
		// insert between pre and p
		SingleLink *a=new SingleLink();
		a->exp=exp;
		a->c=c;
		a->next=p;
		pre->next=a;
	}
}

void print_poly(SingleLink *head)
{
	SingleLink *p=head->next;
	while(p)
	{
		if(p->c==0)
		{
			p=p->next;
			continue;
		}
		cout<<"[ "<<p->c<<" "<<p->exp<<" ]";
		if(p->next)
			cout<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	vector<SingleLink*> l;
	for(int i=0;i<n;i++)
	{
		SingleLink *a_poly_head=new SingleLink();
		int c,exp;
		while(cin>>c>>exp)
		{
			if(exp<0)
				break;
			add_to_poly(a_poly_head,c,exp);
		}
		while(cin>>c>>exp)
		{
			if(exp<0)
				break;
			add_to_poly(a_poly_head,c,exp);
		}
		l.push_back(a_poly_head);
		//print_poly(a_poly_head);
	}
	for(int i=0;i<n;i++)
		print_poly(l[i]);
	return 0;
}
