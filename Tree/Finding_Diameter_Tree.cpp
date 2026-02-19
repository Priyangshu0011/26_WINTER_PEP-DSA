//Finding Diameter of the Tree      
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

int diameter(Node* root)
{
    if(root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    int d1 = l + r + 1;
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    int max1 = d1 > d2 ? d1 : d2;
    return max1 > d3 ? max1 : d3;
}

int main()
{
    Node* root = create();
    cout << diameter(root);
}
