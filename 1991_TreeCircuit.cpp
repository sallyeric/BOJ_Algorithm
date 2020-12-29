#include <iostream>
#include <string>
using namespace std;

int N;

struct node
{
    char left;
    char right;
};

struct node arr[27];

void preOrder(char root)
{
    if(root == '.') return;
    cout << root;
    preOrder(arr[root].left);
    preOrder(arr[root].right);
}

void inOrder(char root)
{
    if(root == '.') return;
    inOrder(arr[root].left);
    cout << root;
    inOrder(arr[root].right);
}

void postOrder(char root)
{
    if(root == '.') return;
    postOrder(arr[root].left);
    postOrder(arr[root].right);
    cout << root;
}

int main()
{
    cin >> N;
    char a, b, c;
    for(int i=0; i<N; i++)
    {
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }
    
    // 전위 순회
    preOrder('A');
    cout << "\n";
    // 중위 순회
    inOrder('A');
    cout << "\n";
    // 후위 순회
    postOrder('A');
    cout << "\n";

    return 0;
}