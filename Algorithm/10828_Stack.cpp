#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<int> s;
    string str;
    int num;
    cin >> num ;
    for(int i=0; i < num; i++)
    {
        cin >> str;
        if(str == "push")
        {
            int number;
            cin >> number;
            s.push(number);
        }
        else if(str == "pop")
        {
            if(s.empty())
                cout << -1 << "\n";
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }               
        }
        else if(str == "top")
        {
            if (s.empty())
                cout << -1 << "\n";
            else 
                cout << s.top() << "\n";
        }
        else if (str == "size") 
        {
			cout << s.size() << "\n";
        }

		else if (str == "empty") 
        {
			if (s.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";

		}
    }
    // for(int j=0; j < num; j++)
    // {
    //     str2 = s.top();
    //     s.pop();
    //     cout << str2 << "\n";        
    // }
    return 0;
}