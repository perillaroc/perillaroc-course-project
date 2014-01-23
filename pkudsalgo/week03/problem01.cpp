#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int line_count;
    cin>>line_count;
    vector<string> output(line_count);
    for(int i=0;i<line_count;i++)
    {
        vector<int> letter_count(26,0);
        string a_string;
        if(i>0)
        {
            getline(cin,a_string);
        }
        cin>>a_string;
        for(int j=0;j<a_string.length();j++)
        {
            int current_pos = a_string[j]-'a';
            letter_count[current_pos]+=1;
        }
        int max_pos=0;
        for(int j=1;j<26;j++)
        {
            if(letter_count[max_pos]<letter_count[j])
            {
                max_pos = j;
            }
        }
        stringstream ss;
        ss << letter_count[max_pos];
        char max_char='a'+max_pos;
        output[i]=string(&max_char,1)+" "+ss.str();

    }
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
