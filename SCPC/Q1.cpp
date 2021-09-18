#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int N;
vector<int> people;
vector<int> group;

void DFS()
{
}

int main(int argc, char **argv)
{
    int T, test_case;

    // freopen("input.txt", "r", stdin);

    cin >> T;
    cin >> N;
    vector<int> group(N);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        people.push_back(x);
    }

    // for(int i=0; i<=N; i++){
    //     if(people[i] + i < N && group[i]==0 && group[people[i]+i]==0){
    //         count += 1;
    //         group[i] = count;
    //         group[people[i]+i]] = count;
    //     }
    //     else if(people[i] + i > N && group[i]==0){
    //         count += 1;
    //         group[i] = count;
    //     }
    //     else if(people[i] + i < N && group[i]==0 && group[people[i]+i]!=0){
    //         group[i] = group[people[i]+i];
    //     }
    //     else if (people[i] + i < N && group[i]!=0 && group[people[i]+i]!=0){
    //         find(group.begin(), group[i], group[i]);
    //         group[i] = group[people[i]+i]!=0;
    //     }
    // }

    // for(test_case = 0; test_case  < T; test_case++)
    // {

    // 	Answer = 0;
    // 	/////////////////////////////////////////////////////////////////////////////////////////////
    // 	/*
    // 	   Implement your algorithm here.
    // 	   The answer to the case will be stored in variable Answer.
    // 	 */

    // 	/////////////////////////////////////////////////////////////////////////////////////////////

    // 	// Print the answer to standard output(screen).
    // 	cout << "Case #" << test_case+1 << endl;
    // 	cout << Answer << endl;
    // }

    return 0; //Your program should return 0 on normal termination.
}
