//Reversing a Linked List
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* reverseList(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

int main()
{
    int n;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    head = reverseList(head);
    Node* curr = head;
    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}
