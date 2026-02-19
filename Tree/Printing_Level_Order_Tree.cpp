//Printing Level Order of the Tree
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

int height(Node* root)
{
    if(root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

void printLevel(Node* root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->data << " ";
    else
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int main()
{
    Node* root = create();
    int h = height(root);
    for(int i = 1; i <= h; i++)
        printLevel(root, i);
}
