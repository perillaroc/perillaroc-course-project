#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


void printPreOrder(vector<int>* in_order, 
                   int in_order_begin, 
                   int in_order_end, // 最后一个元素的坐标
                   vector<int>* post_order,
                   int post_order_begin,
                   int post_order_end)
{
    int num = (*post_order)[post_order_end];
    cout<<num<<" ";
    if(post_order_end - post_order_begin == 0)
        return;
    int i;
    for(i=in_order_begin;i<in_order_end;i++)
    {
        if(num == (*in_order)[i])
            break;
    }
    if(i-1>=in_order_begin)
        printPreOrder(in_order, in_order_begin, i-1, 
                      post_order, 
                      post_order_begin,
                      post_order_begin + i - 1 - in_order_begin);
    if(i+1<=post_order_end)
        printPreOrder(in_order,
                      i+1,
                      in_order_end,
                      post_order,
                      post_order_begin + i + in_order_begin,
                      post_order_end - 1);
    return;
}

int main()
{
    string in_order_string, post_order_string;
    getline(cin,in_order_string);
    getline(cin,post_order_string);

    int a;    
    stringstream in_order_ss(in_order_string);
    vector<int> in_order_vector;
    while(in_order_ss>>a)
        in_order_vector.push_back(a);

    stringstream post_order_ss(post_order_string);
    vector<int> post_order_vector;
    while(post_order_ss>>a)
        post_order_vector.push_back(a);
    
    printPreOrder(&in_order_vector,
                  0, in_order_vector.size()-1,
                  &post_order_vector,
                  0, post_order_vector.size()-1);
    return 0;
}
