#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class BinaryTreeNode
{
public:
    BinaryTreeNode():left_child_(0),right_child_(0){}

    BinaryTreeNode* left_child_;
    BinaryTreeNode* right_child_;
    char value_;
    int depth_;
    int fill_;
};

BinaryTreeNode* createBinaryTree()
{
    BinaryTreeNode* head = NULL;
    stack<BinaryTreeNode*> v;
    string line;
    cin>>line;
    head = new BinaryTreeNode;
    head->value_ = line[0];
    head->depth_=0;
    head->fill_=0;
    v.push(head);
    while(cin>>line)
    {
        if("0"==line)
            break;
        int length = line.length();
        BinaryTreeNode* p1 = new BinaryTreeNode;
        p1->value_ = line[length-1];
        p1->depth_ = length - 1;
        p1->fill_ = 0;
        BinaryTreeNode* p2;
        p2 = v.top();
        while(p1->depth_ - p2->depth_ !=1 )
        {
            v.pop();
            p2 = v.top();
        }
        if(p1->value_ == '*')
        {
            p2->fill_++;
            continue;
        }
        if(p2->fill_==0)
        {
            p2->left_child_ = p1;
            p2->fill_++;
        }
        else if(p2->fill_==1)
        {
            p2->right_child_ = p1;
            p2->fill_++;
        }

        if(p2->fill_ == 2)
        {
            v.pop();
        }
        v.push(p1);
    }
    return head;
}

void preOrderVisit(BinaryTreeNode* tree)
{
    cout<<tree->value_;
    if(tree->left_child_)
        preOrderVisit(tree->left_child_);
    if(tree->right_child_)
        preOrderVisit(tree->right_child_);
}

void inOrderVisit(BinaryTreeNode* tree)
{
    if(tree->left_child_)
        inOrderVisit(tree->left_child_);
    cout<<tree->value_;
    if(tree->right_child_)
        inOrderVisit(tree->right_child_);
}
void afterOrderVisit(BinaryTreeNode* tree)
{
    if(tree->left_child_)
        afterOrderVisit(tree->left_child_);
    if(tree->right_child_)
        afterOrderVisit(tree->right_child_);
    cout<<tree->value_;
}



int main()
{
    int tree_count;
    cin>>tree_count;
    for(int i=0;i<tree_count;i++)
    {
        BinaryTreeNode* tree = createBinaryTree();
        preOrderVisit(tree);
        cout<<endl;
        afterOrderVisit(tree);
        cout<<endl;
        inOrderVisit(tree);
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
