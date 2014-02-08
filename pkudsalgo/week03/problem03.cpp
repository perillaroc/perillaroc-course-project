#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int length=-1;
    int current_no = 0;
    vector<string> output;
    cin>>length;
    while(length)
    {
        string str;
        stringstream ss;
        cin>>str;
        current_no++;
        ss<<current_no;
        output.push_back("Test case #"+ss.str());
        ss.clear();

        for(int prefix_length=2;prefix_length<=str.length();prefix_length++)
        {
            // per perfix
            string current_prefix=str.substr(0,prefix_length);
            //cout<<"current prefix:"<<current_prefix<<endl;
            for(int j=1;j<=prefix_length/2;j++)
            {
                if(prefix_length%j==0)
                {
                    string a=str.substr(0,j);
                    string b;
                    for(int i=0;i<prefix_length/j;i++)
                        b+=a;
                    //cout<<"b:"<<b<<endl;
                    if(current_prefix==b)
                    {
                        //cout<<prefix_length<<" "<<prefix_length/j<<endl;
                        stringstream sss;
                        sss<<prefix_length<<" "<<prefix_length/j;
                        //cout<<sss.str()<<endl;
                        output.push_back(sss.str());
                        ss.clear();
                        break;
                    }
                }
            }
        }
        output.push_back("");
        cin>>length;
    }
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<endl;
    }

    return 0;
}
