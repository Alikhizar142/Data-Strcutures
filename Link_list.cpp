#include <iostream>
using namespace std;
class node
{ public:
    int data;
    node *next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

class list
{
    private:
    node* head;
    int length;
    public:
    list()
    {
        head=NULL;
        length = 0;
    }
    ~list()
    {
        node *curr=NULL;
        for(int i=1;i<length;i++)
        {
            curr=head;
            head=head->next;
            delete curr;
        }
    }
    void update(int val,int pos)
    {
        node *arr=head;
        for(int i=1;i<=length;i++)
        {
            if(i==pos)
            {
                arr->data=val;
            }
            arr=arr->next;

        }
    }
    void insert(int val,int pos)
    {
        if (pos<1 || pos >length+1){
            cout<<"Invalid position"<<endl;
            return;
            }
            node* n=new node(val);

        if(pos==1)
        {
            n->next=head;
            head=n;
        }
        else
        {
            node *curr=head;
            for(int i=1;i<pos-1;i++)
            {
                curr=curr->next;
            }
            n->next=curr->next;
            curr->next=n;
        }

        length++;
    }

    void print()
    {    
        if(length==0)
        cout<<"\nList is empty"<<endl;
        else
        {
         node *curr =head;
        for (int i = 0; i < length; i++)
        {
            cout << curr -> data <<"  ";
            curr=curr->next;
        }
        }
    }
    bool is_empty()
    {
        if(length==0)
        return true;
        else
        return false;

    }

    void remove(int pos)
    {
        if(is_empty())
        {
            cout<<"list is empty"<<endl;
            return;
        }

        if(pos<1 || pos>length+1)
        return;
        node *temp=head;
        if(pos==1)
        {
            head=head->next; // head ka next 
            delete temp;
        }
        else
        {
            node *slow=NULL;
            for(int i=1;i<pos;i++)
            {
                slow=temp;
                temp=temp->next;
            }
            slow->next=temp->next;
            delete temp;
        }
        length--;
    }

    int find(int val)
    {
        if(is_empty())
        {
            cout<<"List is empty"<<endl;
        }


        node *arr=head;
        for(int i=1;i<=length;i++)
        {
            if(arr->data==val)
            {
                return i;
            }
            arr = arr -> next ;
        }

        return 0;
    }
};

int main()
{
    list l;
    l.print();// list is empty 
    l.insert(10,1);
    l.insert(30,1);
    l.insert(25,2);
    l.insert(50,4);
    l.print();
    return 0;
}