// You're given the head of 2 sorted linked lists list 1 and 2 - [1 2 4] & [1 3 4] merge the 2 lists in 1 sorted list the list should be made by splicing together the nodes of 1st two list

// Splicing - joining two list together

//1 1 2 3 4 4

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node* &head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void printList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n1,n2;
    cout<<"Enter the size of list 1: ";
    cin >> n1;
    cout<<"Enter the size of list 2: ";
    cin >> n2;
    //Inserting ele
    for(int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        insertEnd(head1, x);
    }
    for(int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        insertEnd(head2, x);
    }
    //traversing
    Node* ans = NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;
    int c1=0,c2=0;
    while(temp1 != NULL && temp2 !=NULL)
    {
        if(temp1->data <= temp2->data)
        {
            insertEnd(ans, temp1->data);
            temp1 = temp1->next;
            c1+=1;
        }
        else
        {
            insertEnd(ans, temp2->data);
            temp2 = temp2->next;
            c2+=1;
        }
    }
    while(temp1 != NULL)
    {
        insertEnd(ans, temp1->data);
        temp1 = temp1->next;
        c1+=1;
    }
    while(temp2 != NULL)
    {
        insertEnd(ans, temp2->data);
        temp2 = temp2->next;
        c2+=1;
    }
    printList(ans);
    cout<<endl<<"c1 : "<<c1<<" c2 : "<<c2<<endl;
    return 0;
}