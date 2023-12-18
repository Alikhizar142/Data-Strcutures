/*You are tasked with creating a menu-driven queue management system for a doctor's office. The
system should allow the doctor's attendant to add patients to a queue, process them one by one,
see who’s next, and display the patient queue. Here's a detailed breakdown of the task:
Implement a simple queue data structure to manage the flow of patients waiting to see the doctor.
Your program should first as how many seats are available in the waiting area, it means the max
no of patients that can wait in the queue.
Create a menu-driven system with the following options:
1. Add Patient to Queue: The attendant can add a patient's name to the end of the queue.
2. Send next patient to the doctor: The attendant can process the next patient in the queue
and send them to the doctor for examination. Remove the patient from the queue at this
stage.
3. See who’s next: The program should only display the name of the next patient.
4. Display Patient Queue: Display the current queue of patients waiting to see the doctor.*/

#include <iostream>
using namespace std;

class Queue
{
    int capacity;
    int length;
    string *arr;
    int front;
    int rare;

public:
    int size()
    {
        return capacity - length;
    }
    Queue(int size)
    {
        capacity = size;
        arr = new string[capacity];
        length = 0;
        front = 0, rare = -1;
    }
    ~Queue()
    {
        delete [] arr;
    }
    bool full()
    {
        if (length == capacity)
        {
            return true;
        }
        else
            return false;
    }
    bool empty()
    {
        if(length==0)
        {
            return true;
        }
        else
        return false;
    }

    void enqueue(string val) // enqueue function to add element at the end of queue
    {
        if (full())
        {
            cout << "Overflow" << endl;
            return;
        }

        if (rare == capacity - 1)
            rare = 0;
        else
            rare++;
        arr[rare] = val;
        length++;
    }

    string dequeue()
    {
        if (length == 0)
        {
            cout << "Underflow" << endl;
            return 0;
        }
        string val = arr[front];
        if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        length--;
        return val;
    }

    void display()

    {
        if(empty())
        {
            cout<<"No patinet in waiting list"<<endl;
            return;
        }
        int index=front;
        for (int i = 0; i <length; i++)
        {
            cout << arr[index] <<"\t" ;
            if(index==length-1)
            {
                index=0;
            }
            else
            index++;
        }
        cout << endl;
    }

    string next()
    {
        int a=front;
        return arr[a++];
    }
};

int main()
{
    Queue q(2);
    int choice;
    while (1)
    {
        cout << "Number of seats in waiting area are  " << q.size() << "  " << endl<<endl;
        cout << "Select an Option" << endl;
        cout << "1. Enter a patient in waiting queue" << endl;
        cout << "2. Send next  patient to doctor" << endl;
        cout << "3. See who is next" << endl;
        cout << "4. Display All patients in queue" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            if(!q.full())
            {
            cout << "Enter name of patients " << endl;
            string s;
            cin.ignore();
            getline(cin, s);
            q.enqueue(s);

            cout << "Patient " << s <<" now  waiting in the queue " << endl;
            }
            else 
            cout<<"Cant addd more patient bcz queue is full"<<endl;
        }
        else if (choice == 2)
        {
            if(q.empty())
            {
                cout<<"Queue is empty !!!!! NO Patient is waiting list"<<endl;
                continue;
            }
            string s =q.dequeue();

            cout<<"Patient "<<s<<" now with  the Doctor "<<endl;
        }
        else if (choice == 3)
        {
             if(q.empty())
            {
                cout<<"Queue is empty !!!!! NO Patient in waiting list"<<endl;
                continue;
            }
             string s = q.next();
             cout<<"Next Patient :\t"<<s<<endl;
        }
        else if (choice == 4)
        {
            q.display();
        }
        else
            break;
    }
}
