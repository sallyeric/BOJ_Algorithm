#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<int> s;
    int N;
    cin >> N;
    for(int i=0; i < N; i++)
    {
        string str;
        cin >> str;
        if(str == "push")
        {
            int number;
            cin >> number;
            s.push(number);
        }
        else if(str == "pop")
        {
            if(s.size() == 0)
                cout << -1 << "\n";
            else
            {
                cout << s.front() << "\n";
                s.pop();
            }               
        }
        else if (str == "size") 
        {
			cout << s.size() << "\n";
        }
		else if (str == "empty") 
        {
			if (s.size() == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
        else if(str == "front")
        {
            if (s.size() == 0)
                cout << -1 << "\n";
            else 
                cout << s.front() << "\n";
        }
        else if(str == "back")
        {
            if (s.size() == 0)
                cout << -1 << "\n";
            else 
                cout << s.back() << "\n";
        }
    }
    return 0;
}