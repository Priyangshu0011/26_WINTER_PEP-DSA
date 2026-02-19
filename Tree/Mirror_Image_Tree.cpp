//Create a code for the mirror image of a tree both side ways and bottom(invert) ways 
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertLevelOrder(int arr[], int i, int n)
{
    if(i >= n || arr[i] == -1)
        return NULL;

    Node* root = new Node(arr[i]);
    root->left = insertLevelOrder(arr, 2*i + 1, n);
    root->right = insertLevelOrder(arr, 2*i + 2, n);
    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void mirrorSideways(Node* root)
{
    if(root == NULL)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorSideways(root->left);
    mirrorSideways(root->right);
}

Node* invertBottom(Node* root)
{
    if(root == NULL || root->left == NULL)
        return root;

    Node* newRoot = invertBottom(root->left);

    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL;

    return newRoot;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter nodes in level order (-1 for NULL): ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Node* root = insertLevelOrder(arr, 0, n);

    cout << "Original Inorder: ";
    inorder(root);
    cout << endl;

    mirrorSideways(root);
    cout << "Sideways Mirror Inorder: ";
    inorder(root);
    cout << endl;

    root = invertBottom(root);
    cout << "Bottom Inverted Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}
