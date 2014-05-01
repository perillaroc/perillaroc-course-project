/**
 * 二叉树与森林 习题04：电话号码
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_CHILD = 10;

struct TreeNode{
    TreeNode()
        :value(-1),
         check(false)
    {
        children.resize(MAX_CHILD);
        for(int i=0;i<children.size();i++)
            children[i]=NULL;
    }

    ~TreeNode()
    {
        for(int i=0;i<children.size();i++)
        {
            if(children[i]!=NULL)
            {
                delete children[i];
                children[i] = NULL;
            }
        }
    }

    int value;
    bool check;
    vector<TreeNode*> children; 
};

struct Tree{
    Tree(){
        root = new TreeNode;
    }

    ~Tree(){
        delete root;
        root = NULL;
    }

    TreeNode* createNode(int value)
    {
        TreeNode* node = new TreeNode;
        node->value = value;
        return node;
    }

    void insert(string num_string)
    {
        TreeNode *parent = root;
        int i=0;
        for(i=0;i<num_string.length();i++)
        {
            int value = num_string[i]-'0';
            if(parent->children[value]==NULL)
            {
                parent->children[value] = createNode(value);
            }
            parent = parent->children[value];
        }
        parent->check = true;

    }

    bool find(string num_string)
    {
        TreeNode *parent = root;
        int i=0;
        for(i=0;i<num_string.length();i++)
        {
            int value = num_string[i]-'0';
            if(parent->children[value]==NULL || parent->children[value]->check == true)
            {
                break;
            }
            parent = parent->children[value];
        }
        if(i<num_string.length()-1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    TreeNode *root;
};


void takeTest(){
    int total;
    cin>>total;
    Tree tree;
    vector<string> lines(total);
    for(int i=0;i<total;i++)
    {
        string line;
        cin>>lines[i];
        tree.insert(lines[i]);
    }
    bool flag=true;
    for(int i=0;i<total;i++)
    {
        if(!tree.find(lines[i]))
        {
            flag=false;
            break;
        }
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
        takeTest();
    return 0;
}
