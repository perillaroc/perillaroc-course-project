#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    
    string line;
    vector<string> results;

    do{
        getline(cin,line);
        if(line=="START")
        {
            string current_result;
            getline(cin,line);
            for(int i=0;i<line.length();i++)
            {
                if(line[i]>='A' && line[i]<='Z')
                {
                    char ch = (line[i]-'A'+26-5)%26+'A';
                    current_result+=string(&ch,1);
                }
                else
                {
                    current_result+=string(&line[i],1);
                }
            }
            getline(cin,line);
            if(line=="END")
            {
                results.push_back(current_result);
            }
            else
            {
                cout<<"ERROR: need END";
                return -1;
            }
        }
        else if(line=="ENDOFINPUT")
        {
            break;
        }
        else
        {
            cout<<"ERROR"<<endl;
            return -1;
        }
    }while(1);

    for(int i=0;i<results.size();i++)
    {
        cout<<results[i]<<endl;
    }
    return 0;
}
