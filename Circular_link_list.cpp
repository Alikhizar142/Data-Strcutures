#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    // node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        //  prev=NULL;
    }
};

class Circular_link_list
{
public:
    node *head;
    int length;
    Circular_link_list()
    {
        head = NULL;
        length = 0;
    }
    ~Circular_link_list()
    {
    }
    void insert(int val, int pos)
    {

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        node *n = new node(val);
        node *curr = head;
        if (head == NULL)
        {
            head = n;
            head->next = head;
        }
        else if (pos == 1)
        {
            n->next = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = n;
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
        // if(length==0)
        // cout<<"\nList is empty"<<endl;
        // else
        // {
        //  node *curr =head;
        // for (int i = 0; i < length; i++)
        // {
        //     cout << curr -> data <<"  ";
        //     curr=curr->next;
        // }
        // }

        node *curr = NULL;
        while (curr != head)
        {
            if (curr == NULL)
            {
                curr = head;
            }
            cout << curr->data << "  ";
            curr = curr->next;
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
        node *tail = head;

        if (pos == 1)
        {
            while (tail->next != head)
            {

                tail = tail->next;
            }
            head = head->next;
            tail->next = head;

            if (head == head->next)
            {
                head = NULL;
            }
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
    int find(int val)
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
        }

        node *arr = head;
        for (int i = 1; i <= length; i++)
        {
            if (arr->data == val)
            {
                return i;
            }
            arr = arr->next;
        }

        return 0;
    }
};

int main()
{
    Circular_link_list l;
    for (int i = 1; i <= 10; i++)
    {
        l.insert(i, i);
    }
    l.print();
    cout << "After removing" << endl;
    int i = 1;
    while (i != 10)
    {
        cout << i;
        int pos = l.find(i);
        cout << "pos is" << pos << endl;
        l.remove(pos);
        i = i + 1;
    }
    l.insert(10,1);
    l.print();
}
