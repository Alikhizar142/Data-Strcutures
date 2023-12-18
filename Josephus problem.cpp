#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
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
         node *curr=NULL;
        for(int i=1;i<=length;i++)
        {
            curr=head;
            head=head->next;
            delete curr;
        }
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
        node *curr = NULL;
        while (curr != head)
        {
            if (curr == NULL)
                curr = head;
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

    int josephus(int n, int m)
    {
        for (int i = 1; i <= n; i++)
        {
            insert(i, i);
        }
        node *curr = head;
        node *slow = head;
        int pos = 0;
        if (m < 0)
        {
            cout << "invalid" << endl;
            return 0;
        }
        else
        {
            while (length > 1)
            {
                for (int i = 1; i <= m; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }

                pos = find(curr->data);
                remove(pos);
                curr = slow->next;
            }
            return curr->data;
        }
    }
};

int main()
{
    Circular_link_list l;
    int M;
    int N;
    cout << "the number of people in the circle" << endl;
    cin >> N;
    cout << "the step size for counting." << endl;
    cin >> M;

    int a = l.josephus(N, M);

    cout << "The last person which remian in list is " << a << endl;
}