/*Develop a patient appointment system that organizes appointments based on the
urgency of medical conditions using a min heap.
Schedule Appointment:
Prompt the user to enter the patient's name and urgency level of their medical
condition. Here the min urgency level means the most urgent appointment. Insert the
appointment into the min heap based on urgency.
Send next Patient to the Doctor:
Display and remove the details of the appointment with the highest urgency from the
min heap.
Update Urgency:
Prompt the user to enter the patient's name whose urgency level needs to be updated.
Update the urgency level of the specified appointment.
View Appointments:
Display the names and urgency levels of all appointments in the min heap.
Ensure the min heap property is maintained after the update.
Note: In this task you have to make a patient class with the data members: Name,
and Urgency level. Then in the heap class use vector of patient to easily add and
delete patients without worrying about adjusting the size again and again manually
after each insertion and deletion.*/


#include <iostream>
#include <vector>
using namespace std;

class Patient
{
public:
    string name;
    int urgency;

    Patient(string name, int urgency)
    {
        this->name = name;
        this->urgency = urgency;
    }
};

class Heap
{
public:
    vector<Patient> htree;

    int getParent(int child)
    {

        int a = (child - 1) / 2;
        if (a < htree.size())
        {
            return a;
        }
        else
            return -1;
    }

    int getLeft(int parent)
    {
        int a = 2 * parent + 1;
        if (a < htree.size())
        {
            return a;
        }
        else
            return -1;
    }

    int getRight(int parent)
    {
        int a = 2 * parent + 2;
        if (a < htree.size())
        {
            return a;
        }
        else
            return -1;
    }

    void swap(Patient *a, Patient *b)
    {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        int parent = getParent(node);
        if (node && parent != -1 && htree[parent].urgency > htree[node].urgency)
        {
            swap(&htree[getParent(node)], &htree[node]);
            heapifyUp(getParent(node));
        }
    }

    void heapifyDown(int node)
    {
        int left = getLeft(node);
        int right = getRight(node);
        int smallest = node;
        if (left != -1 && htree[left].urgency < htree[node].urgency)
        {
            smallest = left;
        }
        if (right != -1 && htree[right].urgency < htree[smallest].urgency)
        {
            smallest = right;
        }

        if (smallest != node)
        {
            swap(&htree[node], &htree[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(Patient patient)
    {
        int size = htree.size();
        if (size == 0)
            htree.push_back(patient);
        else
        {
            htree.push_back(patient);
            heapifyUp(htree.size() - 1);
        }
    }

    void del()
    {
        int size = htree.size();
        if (size == 0)
            return;
        // cout << htree[0].urgency << "   " << htree[size - 1].urgency << endl;
        swap(&htree[0], &htree[size - 1]);
        // cout << htree[0].urgency << "   " << htree[size - 1].urgency << endl;
        htree.pop_back();
        heapifyDown(0);
    }

    void updateUrgency(string patientName, int newUrgency)
    {
        int size = htree.size();
        for (int i = 0; i < size; i++)
        {
            if (htree[i].name == patientName)
            {
                int old = htree[i].urgency;
                htree[i].urgency = newUrgency;

                // cout << "old=" << old << endl;

                if (newUrgency < old)
                {
                    // cout<<"here";
                    heapifyUp(i);
                }
                if (newUrgency > old)
                {
                    // cout<<"here1"<<endl;
                    heapifyDown(i);
                }
                exit;
            }
        }
    }

    void display()
    {
        if (htree.empty())
        {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++)
        {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
};

int main()
{
    Heap priorityQueue;

    // // Schedule appointments
    // Patient p1("Ali", 3);
    // Patient p2("Bilal", 1);
    // Patient p3("Alina", 2);
    // Patient p4("Hashir", 4);

    // priorityQueue.insert(p1);
    // priorityQueue.insert(p2);
    // priorityQueue.insert(p3);
    // priorityQueue.insert(p4);

    // // Display appointments
    // priorityQueue.display();

    // // Send next patient to the doctor
    // cout << "Sending next patient to the doctor:" << endl;
    // priorityQueue.del();
    // priorityQueue.display();

    // // Update urgency level
    // priorityQueue.updateUrgency("Ali", 5);
    // priorityQueue.display();
    //  priorityQueue.del();
    // priorityQueue.display();
    //    priorityQueue.del();
    // priorityQueue.display();
    //    priorityQueue.del();
    // priorityQueue.display();

    while (true)
    {
        cout << "1.Schedule Appointment:" << endl;
        cout << "2.Send next Patient to the Doctor:" << endl;
        cout << "3.Update Urgency:" << endl;
        cout << "4.Display all Appointments:" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Patient Name" << endl;
            string name;
            cin >> name;
            cout << "Enter Urgency Level" << endl;
            int urgency;
            cin >> urgency;
            priorityQueue.insert(Patient(name, urgency));
        }
        else if (choice == 2)
        {
            cout << "Sending next patient to the doctor:" << endl;
            priorityQueue.del();
            priorityQueue.display();
        }
        else if (choice == 3)
        {
            cout << "Enter the Patient Name" << endl;
            string name;
            cin >> name;
            cout << "Enter the new Urgency Level" << endl;
            int urgency;
            cin >> urgency;
            priorityQueue.updateUrgency(name, urgency);
        }
        else if (choice == 4)
        {
            priorityQueue.display();
        }
        else
            break;
    }

    return 0;
}
