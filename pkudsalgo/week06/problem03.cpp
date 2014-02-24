#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ParentTreeNode
{
public:
    ParentTreeNode():
        value(-1),
        count(0),
        parent(NULL)
    {}
    int value;
    int count;
    ParentTreeNode* parent;
};

class ParentTree
{
public:
    ParentTree(int a_size);
    ~ParentTree();
    ParentTreeNode* Find(ParentTreeNode* node);
    void Union(int i,int j);
    
    vector<ParentTreeNode> array;
    int size;
};

ParentTree::ParentTree(int a_size):
    size(a_size),
    array(a_size)
{
}

ParentTree::~ParentTree(){}

ParentTreeNode* ParentTree::Find(ParentTreeNode* node)
{
    ParentTreeNode* p = node;
    while(p->parent!=NULL)
        p=p->parent;
    return p;
}

void ParentTree::Union(int i,int j)
{
    ParentTreeNode* pi = Find(&array[i-1]);
    ParentTreeNode* pj = Find(&array[j-1]);
    if(pi!=pj)
    {
        if(pi->count >= pj->count)
        {
            pj->parent = pi;
            pi->count += pj->count;
        }
        else
        {
            pi->parent = pj;
            pj->count += pi->count;
        }
    }

}
int doOneTest(int n,int m)
{
    ParentTree tree(n);
    for(int i=0;i<n;i++)
    {
        tree.array[i].value = i+1;
        tree.array[i].count = 1;
        tree.array[i].parent = NULL;
    }

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        tree.Union(a,b);
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(tree.array[i].parent==NULL)
            count++;
    }
    return count;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int count = 0;
    while(!(n==0&&m==0))
    {
        int result = doOneTest(n,m);
        cout<<"Case "<<++count<<": "<<result<<endl;
        cin>>n>>m;
    }
    return 0;
}
