// A company has a hierarchy structure like the tree, CEO is the root each manager can have at most 2 direct sub-ordinates, when CEO sends an emergency message it spreads level by level but if any manager is on leave (node marked -1) that entire subtree under them doesn't receive the message. You are given a Binary tree where each node is equal to employee (-  means employee is on leave) WAP to 

// 1. Remove all subtrees starting from employees marked -1
// 2. Print the level order broadcast list

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
    if(i >= n)
        return NULL;

    Node* root = new Node(arr[i]);
    root->left = insertLevelOrder(arr, 2*i + 1, n);
    root->right = insertLevelOrder(arr, 2*i + 2, n);
    return root;
}

Node* removeLeaveManagers(Node* root)
{
    if(root == NULL)
        return NULL;

    if(root->data == -1)
        return NULL;

    root->left = removeLeaveManagers(root->left);
    root->right = removeLeaveManagers(root->right);

    return root;
}

void levelOrder(Node* root)
{
    if(root == NULL)
        return;

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear)
    {
        Node* temp = queue[front++];
        cout << temp->data << " ";

        if(temp->left != NULL)
            queue[rear++] = temp->left;

        if(temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main()
{
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    int arr[n];
    cout << "Enter employees in level order (-1 for leave): ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Node* root = insertLevelOrder(arr, 0, n);

    root = removeLeaveManagers(root);

    cout << "Broadcast Order: ";
    levelOrder(root);

    return 0;
}
