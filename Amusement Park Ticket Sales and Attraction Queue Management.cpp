/*You are tasked with creating a queue management system for an amusement park that includes
ticket sales and multiple attractions. The system will use a simple queue data structure.
Ticket Sales Queue:
Implement a queue to manage the flow of visitors purchasing tickets at the amusement park
entrance.
Visitors arrive at the ticket booth and join the ticket sales queue.
The ticket salesperson serves visitors one by one from the queue in a first-come, first-served
manner. After selling tickets to a visitor, remove them from the queue, and add them to the
relevant attraction queue.
Phase 2 - Attraction Queues:
Once visitors have purchased their tickets, they can access various attractions in the park.
Create separate queues for each attraction in the park (e.g., Roller Coaster, Round Wheel, and
Motion ride). Each attraction has its own queue.
Implement a queue processing mechanism to manage the visitor flow to attractions. Process the
queues one by one, starting with the Roller Coaster queue, then motion ride, and then round
wheel’s queue.
For each attraction queue, serve visitors one by one in a first-come, first-served manner.
After a visitor has enjoyed an attraction, remove them from the respective attraction queue.
Create a menu driven program for the ticket’s sale’s person with the following choices:
Enter visitor in the tickets purchase queue: Enters a visitor’s name in the tickets purchase
queue.
Sell a ticket: Sell a ticket to the next person from the ticket purchase queue. Based on the
attraction’s ticket, now the person should be in the waiting queue for that attraction.
Process all queues: Process and serve all the visitors (starting from the roller coaster’s
attraction, then motion ride, and the round wheel in first come first serve basis.*/

#include <iostream>
using namespace std;
class node
{
public:
    string data;
    node *next;
    node(string val)
    {
        data = val;
        next = NULL;
    }
};

class list
{
private:
    node *head;
    int length;

public:
    list()
    {
        head = NULL;
        length = 0;
    }
    ~list()
    {
        node *curr = NULL;
        for (int i = 1; i < length; i++)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    void insert(string val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        node *n = new node(val);

        if (pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }

        length++;
    }

    void print()
    {
        if (length == 0)
            cout << "\nList is empty" << endl;
        else
        {
            node *curr = head;
            for (int i = 0; i < length; i++)
            {
                cout << curr->data << "  ";
                curr = curr->next;
            }
        }
    }
    bool is_empty()
    {
        if (length == 0)
            return true;
        else
            return false;
    }

    void remove(int pos)
    {
        if (is_empty())
        {
            cout << "list is empty" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
            return;
        node *temp = head;
        if (pos == 1)
        {
            head = head->next; // head ka next
            delete temp;
        }
        else
        {
            node *slow = NULL;
            for (int i = 1; i < pos; i++)
            {
                slow = temp;
                temp = temp->next;
            }
            slow->next = temp->next;
            delete temp;
        }
        length--;
    }

    string get(int pos)
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
        }

        node *arr = head;
        for (int i = 1; i <= length; i++)
        {
            if (i == pos)
            {
                return arr->data;
            }
            arr = arr->next;
        }
        return 0;
    }

    int glength()
    {
        return length;
    }
};

class queue : private list
{
    int front;
    int rare;

public:
    queue()
    {
        front = 1;
        rare = 1;
    }
    void enqeue(string val)
    {
        insert(val, rare);
        rare++;
    }
    string dequeue()
    {
        if (is_empty())
            return "String is empty";
        else
        {
            string s = get(front);
            remove(front);
            rare--;
            return s;
        }
    }

    void display()
    {
        if (is_empty())
        {
            return;
        }
        for (int i = front; i <= rare; i++)
        {
            cout << get(i) << "\t";
        }
        cout << endl;
    }

    string get_val()
    {
        return get(front);
    }
    int get_length()
    {
        int a = glength();
        return a;
    }
};

int main()
{
    queue ticket;
    queue roller;
    queue motion;
    queue round;

    int choice;
    while (1)
    {
        cout << "Enter your Choice" << endl;
        cout << " 1.Enter a vistor to the Ticket waiting  Queue" << endl;
        cout << " 2.Sell a ticket" << endl;
        cout << " 3. Process all queues" << endl;
        cin >> choice;
        if (choice == 1)
        {
            string name;
            cout << "Enter Visitor Name" << endl;
            cin.ignore();
            getline(cin, name);
            ticket.enqeue(name);
        }
        else if (choice == 2)
        {

            string a = ticket.dequeue();
            cout << "Now Sellingg ticket to " << a << "..............." << endl;

            cout << "Which Attraction ticket " << a << " want.........????" << endl;

            cout << "1.Roller coaster" << endl;
            cout << "2.Motion Ride " << endl;
            cout << "3.Roud Wheel" << endl;

            int input;
            cin >> input;
            if (input == 1)
            {
                roller.enqeue(a);
            }
            else if (input == 2)
            {
                motion.enqeue(a);
            }
            else if (input == 3)
            {
                round.enqeue(a);
            }
            else
            {
                cout << "Wrong Choice(- _ -)" << endl;
                continue;
            }
        }
        else if (choice == 3)
        {
            for (int i = 1; i <= roller.get_length(); i++)
            {
                if (roller.get_length() != 0)
                    cout << "Visitor " << roller.dequeue() << " now enjoying at roller coaster  " << endl;
                else
                    cout << "No one is waiting for Roller Coaster " << endl;
            }
            for (int i = 1; i <= motion.get_length(); i++)
            {
                if (motion.get_length() != 0)
                    cout << "Visitor " << motion.dequeue() << " now enjoying at Motion  Ride " << endl;
                else
                    cout << "No one is waiting for Roller Coaster " << endl;
            }
            for (int i = 1; i <= round.get_length(); i++)
            {
                if (round.get_length() != 0)
                    cout << "Visitor " << round.dequeue() << " now enjoying at Round Wheel  " << endl;
                else
                    cout << "No one is waiting for Roller Coaster " << endl;
            }
        }
        else
            break;
    }

    return 0;
}
