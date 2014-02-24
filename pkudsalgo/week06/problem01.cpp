#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class TreeNode
{
public:
    TreeNode():
        first_child(NULL),
        next_sibling(NULL)
    {}
    string value;
    TreeNode *first_child;
    TreeNode *next_sibling;
};

class Tree
{
public:
    Tree():root(NULL){}
    
    void preOrderVisit()
    {
        stack<TreeNode*> s;
        if(root==NULL)
            return;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* p = s.top();
            cout<<p->value<<endl;
            s.pop();
            if(p->next_sibling)
            {
                s.push(p->next_sibling);
            }
            if(p->first_child)
            {
                s.push(p->first_child);
            }
        }
    }
    
    TreeNode* find(string value_to_find)
    {
        stack<TreeNode*> s;
        if(root==NULL)
            return NULL;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* p = s.top();
            if(p->value == value_to_find)
                return p;
            s.pop();
            if(p->next_sibling)
            {
                s.push(p->next_sibling);
            }
            if(p->first_child)
            {
                s.push(p->first_child);
            }
        }
        return NULL;
    }
    TreeNode* root;
};

void doOneTest()
{
    stack<TreeNode*> s;
    const int buffer_size = 50;
    char buffer[buffer_size];
    Tree tree;
    tree.root = new TreeNode;
    TreeNode* p1 = tree.root;
    string str;
    getline(cin, str);
    while(!str.empty())
    {
        if(str=="{")
        {
            s.push(p1);
            getline(cin, str);
            TreeNode* p2 = new TreeNode;
            p2->value = str;
            p1->first_child = p2;
            p1 = p2;
        }
        else if(str=="}")
        {
            p1 = s.top();
            s.pop();
        }
        else
        {
            TreeNode* p2 = new TreeNode;
            p2->value = str;
            p1->next_sibling = p2;
            p1 = p2;
        }
        getline(cin, str);
    }
    
    getline(cin, str);
    string value_to_find = str;
    TreeNode* node = tree.find(value_to_find);
    string output;
    if(node)
    {
        node = node->next_sibling;
        while(node)
        {
            output+=node->value;
            node = node->next_sibling;
        }
    }
    else
    {
        output = "No";
    }

    getline(cin,str);
    if(!str.empty())
    {
       cerr<<"ERROR"<<endl;
       return;
    }
    getline(cin,str);
    if(!str.empty())
    {
       cerr<<"ERROR"<<endl;
       return;
    }

    cout<<output<<endl;

}


int main()
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    int count;
    ss>>count;
    for(int i=0;i<count;i++)
    {
        doOneTest();
    }
    getline(cin,str);
    if(str!="!")
    {
        cerr<<"ERROR"<<endl;
    }
    return 0;
}
