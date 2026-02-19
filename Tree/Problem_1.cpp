//There is a BST but we don't know how many nodes are there. You will be given a target node, if this target is not found then print entire tree in pre-order. If this target exist in the tree then print the complete level at which the tree is located. (First ask the user to input the number of nodes then tree nodes data and then ask for the target node)
#include <iostream>
using namespace std;

class Node
{
public:
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

Node* insert(Node* root, int x)
{
    if(root == NULL)
        return new Node(x);
    if(x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

void printPreorder(Node* root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printGivenLevel(Node* root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->data << " ";
    else
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int findLevel(Node* root, int target)
{
    int level = 1;
    while(root != NULL)
    {
        if(root->data == target)
            return level;
        else if(target < root->data)
            root = root->left;
        else
            root = root->right;
        level++;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    Node* root = NULL;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int target;
    cin >> target;

    int level = findLevel(root, target);

    if(level == 0)
        printPreorder(root);
    else
        printGivenLevel(root, level);

    return 0;
}

//Explanation:
//1. We define a Node class to represent each node in the BST.  
//2. The insert function is used to insert nodes into the BST based on the value of the node.
//3. The printPreorder function is used to print the tree in pre-order traversal.
//4. The printGivenLevel function is used to print all nodes at a given level in the tree.
//5. The findLevel function is used to find the level of the target node in the BST. It returns 0 if the target node is not found.
//6. In the main function, we first read the number of nodes and then insert the nodes into the BST. We then read the target node and find its level. If the target node is not found, we print the entire tree in pre-order. If the target node is found, we print all nodes at that level.

//Level is 0 based index, so if the target node is found at level 1, it means it is the root node. If it is found at level 2, it means it is a child of the root node, and so on.
