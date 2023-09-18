
#include <iostream>
using namespace std;
class node
{
public:
    string data;
    node *next;
    node *prev;
    bool done;

    node(string val)
    {
        data = val;
        next = NULL;
        prev = NULL;
        done = false;
    }
};

class List
{
    node *head;
    int length;

public:
    List()
    {
        head = NULL;
        length = 0;
    }
    ~List()
    {
        node *curr = NULL;
        while (head != NULL)
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
            if (head != NULL)

                head->prev = n;

            head = n;
        }
        else
        {
            node *curr = head;

            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->prev = curr;
            n->next = curr->next;
            if (curr->next != NULL)
            {
                curr->next->prev = n;
            }
            curr->next = n;
        }
        length++;
    }
    void remove(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }
        node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete curr;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
            delete curr;
        }
        length--;
    }
  
    void print()
    {
        node *curr = head;
        cout<<"            TO-DO-LIST                    "<<endl;
        for(int i=1;i<=length;i++)
        {
            if(curr->done)
            {
            cout <<i <<" ::"<<curr->data << " :"<<"Task Completed "<<endl;
            curr = curr->next;
            }
            else
            {
                 cout <<i <<" ::"<<curr->data << " :  "<<"Task Not Completed "<<endl;
                curr = curr->next;

            }
        }
        cout << endl;
    }
    void mark(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }
        node *curr = head;
        for (int i = 1; i <= length; i++)
        {
            if (i == pos)
            {
                curr->done = true;
            }
            curr = curr->next;
        }
    }
    bool check(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return false;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return false;
        }
        node *curr = head;
        for (int i = 1; i <= length; i++)
        {
            if (pos == i && curr->done == true)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    int get_length()
    {
        return length;
    }
    void print_descending()
    {
        node *curr = head;
        while (curr->next!=NULL)
        {
            curr=curr->next;
        }
                   cout<<"            TO-DO-LIST                    "<<endl;
        for(int i=1;i<=length;i++)
        {
            if(curr->done)
            {
            cout <<i <<" ::"<<curr->data << " :"<<"Task Completed "<<endl;
            curr = curr->prev;
            }
            else
            {
                 cout <<i <<" ::"<<curr->data << " :  "<<"Task Not Completed "<<endl;
                curr = curr->prev;

            }
        }
        cout << endl;

    }
};

int main()
{
    int input;
    List l;
    while (1)
    {
        cout<<"                 MENU                "<<endl;
        cout << "1.Enter Data in list" << endl;
        cout << "2. Mark Completed" << endl;
        cout << "3. Remove Completed " << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice " << endl;
        cin >> input;
        if (input == 1)
        {
            cout << "Enter the Task to list" << endl;
            string task;
            cin.ignore();
            getline(cin,task);
            cout << "Choose piaorty" << endl;
            cout << "1. Top piaroity" << endl;
            cout << "2. least piarority" << endl;
            cout << "3. let me select" << endl;
            int piaority;
            cin>>piaority;
            if (piaority == 1)
            {
                l.insert(task, 1);
            }
            else if (piaority == 2)
            {
                l.insert(task, l.get_length() + 1);
            }
            else
            {
                cout << "Select a number between "
                     << " 1 and " << l.get_length() + 1 << endl;
                int n;
                cin >> n;
                l.insert(task, n);
            }

            l.print();
        }
        else if (input == 2)
        {
            cout << "Enter the task number you want to mark done" << endl;
            int n;
            cin >> n;
            l.mark(n);
        }
        else if (input == 3)
        {
            cout << "Press 1 to remove all completed tasks" << endl;
            cout << "Press 2 to remova a single completed task" << endl;
            int a;
            cin >> a;
            if (a == 1)
            {
                for (int i = 1; i <= l.get_length(); i++)
                {
                    if (l.check(i) == true)
                    {
                        l.remove(i);
                    }
                }
            }
            else
            {
                cout<<"Enter the position to delete"<<endl;
                int n;
                cin>>n;
                if(l.check(n))
                {
                    l.remove(n);
                }
                else
                cout<<"Task is not completed yet"<<endl;
            }
        l.print();
       }
       else if(input==4)
       {
        cout<<"Press 1 to print in asscending order"<<endl;
        cout<<"Press 2 to print in deascending order"<<endl;
        int a;
        cin>>a;
        if(a==1)
        l.print();
        else
        l.print_descending();
       }
       else
       break;
    }
}