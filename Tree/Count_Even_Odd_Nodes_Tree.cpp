//Count Even and Odd Nodes in the Tree
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* create()
{
    int x;
    cin >> x;
    if(x == -1)
        return NULL;
    Node* temp = new Node();
    temp->data = x;
    temp->left = create();
    temp->right = create();
    return temp;
}

void countNodes(Node* root, int &even, int &odd)
{
    if(root == NULL)
        return;
    if(root->data % 2 == 0)
        even++;
    else
        odd++;
    countNodes(root->left, even, odd);
    countNodes(root->right, even, odd);
}

int main()
{
    Node* root = create();
    int even = 0, odd = 0;
    countNodes(root, even, odd);
    cout << even << " " << odd;
}
