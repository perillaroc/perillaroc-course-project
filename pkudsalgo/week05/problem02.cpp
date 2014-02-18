#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class BinarySearchTreeNode
{
public:
    BinarySearchTreeNode():
        left(NULL),
        right(NULL){}
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
    int value;
};

void insert(BinarySearchTreeNode* root, int value)
{
    BinarySearchTreeNode* node = root;
    if(node->value > value)
    {
        if(node->left == NULL)
        {
            BinarySearchTreeNode* new_node = new BinarySearchTreeNode();
            new_node->value = value;
            node->left = new_node;
            return;
        }
        else
        {
            insert(node->left, value);
        }
    }
    else if(node->value < value)
    {
        if(node->right == NULL)
        {
            BinarySearchTreeNode* new_node = new BinarySearchTreeNode();
            new_node->value = value;
            node->right = new_node;
            return;
        }
        else
        {
            insert(node->right, value);
        }
    }
    else
        return;
}

void preOrderVisit(BinarySearchTreeNode* tree)
{
    cout<<tree->value<<" ";
    if(tree->left)
        preOrderVisit(tree->left);
    if(tree->right)
        preOrderVisit(tree->right);
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    ss>>num;
    BinarySearchTreeNode* tree = new BinarySearchTreeNode();
    tree->value = num;
    while(ss>>num)
    {
        insert(tree, num);
    }
    
    preOrderVisit(tree);

    return 0;
}
