/**
 *  week 06 problem 02
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_SIZE=10000;

void takeTest(int count, string line)
{
    int forest_depth = 0, bitree_depth = 0;
    int current_forest_depth = 0, current_bitree_depth = 0;

    vector<int> parent(MAX_SIZE,0);
    vector<int> child_count(MAX_SIZE,0);
    vector<int> bi_depth(MAX_SIZE,0);

    parent[0] = -1; // the first node
    int cur_pos = 0;
    int num=1;
    for(int i=0;i<line.size();i++)
    {
        if(line[i]=='d')
        {
            current_forest_depth++;
            if(current_forest_depth>forest_depth)
                forest_depth = current_forest_depth;

            child_count[cur_pos]++;
            current_bitree_depth += child_count[cur_pos];
            bi_depth[num] = current_bitree_depth;
            if(current_bitree_depth>bitree_depth)
                bitree_depth = current_bitree_depth;
            parent[num] = cur_pos;
            cur_pos = num;
            num++;
        }
        else if(line[i]=='u')
        {
            current_forest_depth--;

            cur_pos = parent[cur_pos];
            current_bitree_depth = bi_depth[cur_pos];
        }
    }

    cout<<"Tree "<<count<<": "<<forest_depth<<" => "<<bitree_depth<<endl;
}

int main()
{
    int count = 0;
    string line;
    getline(cin, line);
    while(line!="#")
    {
        count++;
        takeTest(count, line);
        getline(cin,line);
    }
    return 0;
}