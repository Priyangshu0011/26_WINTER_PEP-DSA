// A hospital treats patients on their severity and not on their arrival time. 
// Every patient has patient id and severity number (larger is high) based on the criticality of the patient. 
// 1. Insert new patient in emergency system 
// 2. Most critical patient treat 
// 3. Display current waiting patient
// Use linked list to implement the priority queue for this problem.
#include <iostream>
using namespace std;
struct Patient {
    int id;
    int severity;
    Patient* next;
    Patient(int id, int severity) : id(id), severity(severity), next(nullptr) {}
};
class HospitalPriorityQueue {
public:
    Patient* front;
    HospitalPriorityQueue() : front(nullptr) {}
    
    void insertPatient(int id, int severity) {
        Patient* newPatient = new Patient(id, severity);
        if (!front || front->severity < severity) { // Higher severity has higher priority
            newPatient->next = front;
            front = newPatient;
        } else {
            Patient* temp = front;
            while (temp->next && temp->next->severity >= severity) {
                temp = temp->next;
            }
            newPatient->next = temp->next;
            temp->next = newPatient;
        }
    }
    void treatPatient() {
        if (isEmpty()) {
            cout << "No patients to treat" << endl;
            return;
        }
        Patient* temp = front;
        cout << "Treating patient ID: " << temp->id << " with severity: " << temp->severity << endl;
        front = front->next;
        delete temp;
    }
    bool isEmpty() {
        return !front;
    }
    void displayPatients() {
        if (isEmpty()) {
            cout << "No patients waiting" << endl;
            return;
        }
        Patient* temp = front;
        cout << "Current waiting patients:" << endl;
        while (temp) {
            cout << "ID: " << temp->id << ", Severity: " << temp->severity << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    HospitalPriorityQueue hospital;
    cout<<"Enter number of patients to insert: ";
    int n;
    cin>>n;
    while(true)
    {
        cout<<"1. Insert new patient\n2. Treat most critical patient\n3. Display current waiting patients\n4. Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        cout<<endl;
        if(choice==1)
        {
            int id, severity;
            cout<<"Enter patient ID : ";
            cin>>id;
            cout<<"Enter patient severity : ";
            cin>>severity;
            hospital.insertPatient(id, severity);
        }
        else if(choice==2)
        {
            hospital.treatPatient();
        }
        else if(choice==3)
        {
            hospital.displayPatients();
        }
        else if(choice==4)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice, try again."<<endl;
        }
    }
}