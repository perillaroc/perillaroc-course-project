#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BinaryTreeNode
{
public:
    BinaryTreeNode():
        left_child_(0),
        right_child_(0)
    {
        
    }

    void destroy()
    {
        destroyChild(left_child_);
        destroyChild(right_child_);
        delete left_child_;
        left_child_ = 0;
        delete right_child_;
        right_child_ = 0;
    }

    void destroyChild(BinaryTreeNode* a_child)
    {
        if(a_child)
            a_child->destroy();
        return;
    }

    BinaryTreeNode* left_child_;
    BinaryTreeNode* right_child_;
    int value_;
};

class BinaryTree
{
public:
    BinaryTree():
        root_(0),
        index_(0)
    {
    }
    BinaryTree(int count):
        root_(0),
        index_(count,NULL)
    {
    }
    BinaryTreeNode* root_;
    vector<BinaryTreeNode*> index_;
};

void swapBinaryTreeNode(BinaryTree* tree, int a, int b)
{
    //交换a,b两个节点的value，两个子节点指针，和索引
    BinaryTreeNode* node_a = tree->index_[a];
    BinaryTreeNode* node_b = tree->index_[b];
    
    int inttemp = node_a->value_;
    node_a->value_ = node_b->value_;
    node_b->value_ = inttemp;

    BinaryTreeNode* ptrtemp = node_a->left_child_;
    node_a->left_child_ = node_b->left_child_;
    node_b->left_child_ = ptrtemp;

    ptrtemp = node_a->right_child_;
    node_a->right_child_ = node_b->right_child_;
    node_b->right_child_ = ptrtemp;

    tree->index_[a] = node_b;
    tree->index_[b] = node_a;   
}

int mostLeftChild(BinaryTree* tree, int a)
{
    BinaryTreeNode *node = tree->index_[a];
    while(node->left_child_ != NULL)
        node = node->left_child_;
    return node->value_;
}

int takeOneSample()
{
    int num_count;
    int oper_count;
    cin>>num_count>>oper_count;
    BinaryTree tree(oper_count);
    // 创建节点指针的索引
    for(int i=0;i<num_count;i++)
    {
        int current_num=0;
        int left_child_num=-1,right_child_num=-1;
        cin>>current_num>>left_child_num>>right_child_num;
        // 检查是否创建当前节点
        BinaryTreeNode* current_node =NULL; 
        if(!tree.index_[current_num])
        {
            // 创建当前节点及两个子节点
            current_node = new BinaryTreeNode;
            current_node->value_ = current_num;
            tree.index_[current_num]=current_node;
        }
        else
        {
            current_node = tree.index_[current_num];
        }
        if(left_child_num != -1)
        {
            BinaryTreeNode* left_child_node = new BinaryTreeNode;
            left_child_node->value_ = left_child_num;
            tree.index_[left_child_num] = left_child_node;
            current_node->left_child_ = left_child_node;
        }
        if(right_child_num != -1)
        {
            BinaryTreeNode* right_child_node = new BinaryTreeNode;
            right_child_node->value_ = right_child_num;
            tree.index_[right_child_num] = right_child_node;
            current_node->right_child_ = right_child_node;
        }
    }

    tree.root_ = tree.index_[0];

    for(int i=0;i<oper_count;i++)
    {
        int oper_type;
        cin>>oper_type;
        if(oper_type == 1)
        {
            int a,b;
            cin>>a>>b;
            swapBinaryTreeNode(&tree,a,b);
        }
        else if(oper_type == 2)
        {
            int a;
            cin>>a;
            cout<<mostLeftChild(&tree, a)<<endl;
        }
    }
    tree.root_->destroy();
    delete tree.index_[0];

    return 0;
}

int main()
{
    int count;
    cin>>count;
    for(int i=0;i<count;i++)
        takeOneSample();
    return 0;
}
