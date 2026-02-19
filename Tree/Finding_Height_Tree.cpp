#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        Node* temp = new Node();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int height(Node* root)
{
    if(root == NULL)
        return 0;

    int l = height(root->left);
    int r = height(root->right);

    return (l > r ? l : r) + 1;
}

int main()
{
    int n;
    cout << "input no of nodes: ";
    cin >> n;

    Node* root = NULL;

    cout << "nodes: ";
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    cout << "Height = " << height(root);
}
