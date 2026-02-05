//Insertion in Circular Queue using Array
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of Circular Queue: ";
    cin>>n;
    int arr[n];
    int front=-1,rear=-1;
    int choice;
    do
    {
        cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int val;
                cout<<"Enter value to be inserted: ";
                cin>>val;
                //Insertion
                if((front==0 && rear==n-1) || (rear+1)%n==front)
                {
                    cout<<"Queue Overflow\n";
                }
                else if(front==-1 && rear==-1)
                {
                    front=rear=0;
                    arr[rear]=val;
                }
                else
                {
                    rear=(rear+1)%n;
                    arr[rear]=val;
                }
                break;
            }
            case 2:
            {
                //Deletion
                if(front==-1 && rear==-1)
                {
                    cout<<"Queue Underflow\n";
                }
                else if(front==rear)
                {
                    cout<<"Deleted element is: "<<arr[front]<<"\n";
                    front=rear=-1;
                }
                else
                {
                    cout<<"Deleted element is: "<<arr[front]<<"\n";
                    front=(front+1)%n;
                }
                break;
            }
            case 3:
            {
                //Display
                if(front==-1 && rear==-1)
                {
                    cout<<"Queue is empty\n";
                }
                else
                {
                    cout<<"Elements in Circular Queue are: ";
                    int i=front;
                    while(i!=rear)
                    {
                        cout<<arr[i]<<" ";
                        i=(i+1)%n;
                    }
                    cout<<arr[rear]<<"\n";
                }
                break;
            }
            case 4:
            {
                cout<<"Exiting...\n";
                break;
            }
            default:
            {
                cout<<"Invalid choice! Please try again.\n";
            }
        }
    }while(choice!=4);
    return 0;
}