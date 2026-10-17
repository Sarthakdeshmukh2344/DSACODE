
#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    int processID;
    string processName;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    Node* next;
};

// Head pointer
Node* head = NULL;

// Function to add a process
void addProcess()
{
    Node* newNode = new Node();

    cout << "\nEnter Process ID: ";
    cin >> newNode->processID;

    // Check duplicate Process ID
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->processID == newNode->processID)
        {
            cout << "Process ID already exists!\n";
            delete newNode;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Process Name: ";
    cin >> newNode->processName;

    cout << "Enter Burst Time: ";
    cin >> newNode->burstTime;

    if (newNode->burstTime <= 0)
    {
        cout << "Burst time must be positive!\n";
        delete newNode;
        return;
    }

    newNode->waitingTime = 0;
    newNode->turnaroundTime = 0;
    newNode->next = NULL;

    // Insert at the end of the linked list
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    cout << "Process added successfully!\n";
}

// Function to display all processes
void displayProcesses()
{
    if (head == NULL)
    {
        cout << "\nNo processes available.\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== PROCESS LIST ==========\n";

    while (temp != NULL)
    {
        cout << "\nProcess ID       : " << temp->processID;
        cout << "\nProcess Name     : " << temp->processName;
        cout << "\nBurst Time       : " << temp->burstTime;
        cout << "\nWaiting Time     : " << temp->waitingTime;
        cout << "\nTurnaround Time  : " << temp->turnaroundTime;
        cout << "\n----------------------------------\n";

        temp = temp->next;
    }
}

// Function to execute processes using FCFS
void scheduleProcesses()
{
    if (head == NULL)
    {
        cout << "\nNo processes to schedule.\n";
        return;
    }

    int currentTime = 0;
    int totalWaiting = 0;
    int totalTurnaround = 0;
    int count = 0;

    Node* temp = head;

    cout << "\n========== FCFS SCHEDULING ==========\n";
    cout << "Process\tBurst\tWaiting\tTurnaround\n";

    while (temp != NULL)
    {
        temp->waitingTime = currentTime;
        temp->turnaroundTime =
            temp->waitingTime + temp->burstTime;

        cout << temp->processName << "\t"
             << temp->burstTime << "\t"
             << temp->waitingTime << "\t"
             << temp->turnaroundTime << "\n";

        currentTime += temp->burstTime;
        totalWaiting += temp->waitingTime;
        totalTurnaround += temp->turnaroundTime;
        count++;

        temp = temp->next;
    }

    cout << "\nAverage Waiting Time: "
         << (double)totalWaiting / count;

    cout << "\nAverage Turnaround Time: "
         << (double)totalTurnaround / count << endl;
}

// Function to search for a process
void searchProcess()
{
    int id;

    cout << "\nEnter Process ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->processID == id)
        {
            cout << "\nProcess Found!\n";
            cout << "ID: " << temp->processID << endl;
            cout << "Name: " << temp->processName << endl;
            cout << "Burst Time: " << temp->burstTime << endl;
            cout << "Waiting Time: " << temp->waitingTime << endl;
            cout << "Turnaround Time: "
                 << temp->turnaroundTime << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Process not found!\n";
}

// Function to delete a process
void deleteProcess()
{
    int id;

    cout << "\nEnter Process ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL && temp->processID != id)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Process not found!\n";
        return;
    }

    if (previous == NULL)
        head = temp->next;
    else
        previous->next = temp->next;

    delete temp;

    cout << "Process deleted successfully!\n";
}

// Function to free memory
void freeMemory()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << " COMPUTER PROCESS SCHEDULING SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Process\n";
        cout << "2. Display Processes\n";
        cout << "3. Schedule Processes (FCFS)\n";
        cout << "4. Search Process\n";
        cout << "5. Delete Process\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addProcess();
                break;

            case 2:
                displayProcesses();
                break;

            case 3:
                scheduleProcesses();
                break;

            case 4:
                searchProcess();
                break;

            case 5:
                deleteProcess();
                break;

            case 6:
                freeMemory();
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
