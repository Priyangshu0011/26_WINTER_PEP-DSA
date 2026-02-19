//Suppose there is a pyramid in tree structure but not BST, now there are 2 pyramids now you are standing on the root of one pyramid and same for your friend on the other pyramid so you two have to reach the very last node available in the 2 trees traversing all the nodes for each of you, say for you both which will have the fastest traversal technique (let suppose the two tree structure is entirely different) [Consider the height and diameter of the tree, now chec kwhether BFS or DFS or any other traversal techniques or whatever which one the fastest in each case] // If the height of the tree is more then implement dfs and if diameter is more then BFS

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

Node* buildTree(int n) {
    if (n <= 0) return NULL;
    Node** arr = new Node*[n];
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr[i] = new Node(val);
    }
    for (int i = 0; i < n; i++) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n) arr[i]->left = arr[l];
        if (r < n) arr[i]->right = arr[r];
    }
    return arr[0];
}

int height(Node* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int diameterUtil(Node* root, int &h) {
    if (!root) {
        h = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = diameterUtil(root->left, lh);
    int rd = diameterUtil(root->right, rh);
    h = (lh > rh ? lh : rh) + 1;
    int curr = lh + rh + 1;
    if (ld > rd && ld > curr) return ld;
    if (rd > ld && rd > curr) return rd;
    return curr;
}

int diameter(Node* root) {
    int h = 0;
    return diameterUtil(root, h);
}

void dfs(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    dfs(root->left);
    dfs(root->right);
}

void bfs(Node* root) {
    if (!root) return;
    Node** q = new Node*[10000];
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front < rear) {
        Node* temp = q[front++];
        cout << temp->data << " ";
        if (temp->left) q[rear++] = temp->left;
        if (temp->right) q[rear++] = temp->right;
    }
}

int main() {
    int n1, n2;
    cin >> n1;
    Node* root1 = buildTree(n1);
    cin >> n2;
    Node* root2 = buildTree(n2);

    int h1 = height(root1);
    int d1 = diameter(root1);

    int h2 = height(root2);
    int d2 = diameter(root2);

    if (h1 > d1)
        dfs(root1);
    else
        bfs(root1);

    cout << endl;

    if (h2 > d2)
        dfs(root2);
    else
        bfs(root2);

    return 0;
}
