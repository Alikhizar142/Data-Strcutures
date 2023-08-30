/*You're given an initial sequence of characters in a dynamic array (shuffled
string e.g efabir). Your goal is to arrange these characters to perfectly match 
a given target string (fariba). You have access to a set of operations—insert
and remove—that allow you to manipulate the arrangement of characters 
within the array. With each operation, you'll transform the array, getting closer 
to the final arrangement.
Instructions:
• You have a sequence of characters already present in the dynamic array
(insert the 6 characters hard coded by calling the insert method).
• Implement the ArrayList class methods, insert, delete, search, printList, 
get. However, we will use make use of only three methods, rest are for 
practice only.
• After each operation, you'll observe the array changing, and you should 
keep track of the steps taken.
• Your arrangement should eventually match the provided target string.
• Let’s see who arranges my name with the minimum number of steps. I 
have done myself using 6 steps 
Note that the task must be performed using dynamic array, and all the 
operations must be performed using pointers. Plus, you can use any built in function/ easy method to match the strings.
*/

#include<iostream>
#include<cstring>
using namespace std;
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

class list{
    private:
    char *arr;
    char *curr;
    int length;
    int capacity;
     void next()
    {
        curr++;
    }
    void back()
    {
        curr--;
    }
    void start()
    {
        curr=arr;
    }
    void tail()
    {
        curr=arr+length-1;
    }


    public :

    char* pointer (){
        start();

        
        return curr;
        }
    
    list(int size=0){
        capacity=size;
        arr = new char[size];
        length=0;
        curr=arr;
    }

    ~list() {
        delete []arr ;
    }
   
    void insert(char V,int I)
    {
        if(length==capacity)
        {
                       cout<<"Overflow"<<endl;
                       return;
        }
        if(1>I || I>length+1)
        cout<<"\nInvalid index\n";
        tail();
        for(int i=length;i>=I;i--)
        {
            *(curr+1)=*curr;
            back();
        }
        *(curr+1)=V;
        length++;
    }


    void remove(int pos)
    {
         if(length==0)
        {
                       cout<<"Empty"<<endl;
                       return;
        }
        if(pos<1 || pos>length)
        cout<<"\nInvalid index\n";
        start();
        curr=arr+pos-1;
        for(int i=pos;i<length;i++)
        {
            *(curr)=*(curr+1);
            next();
        }
        length--;

    }
    bool is_empty()
    {
        if(length==0)
        {
            return false;
        }
        else 
        return true;
    }
    int search(char val)
    {
        start();
        for ( int i = 1; i <=length ; i++ )
        {
            if(val==*curr)
            {
                return i;
            }
            next();
        }

    }

    void print()
    {
        for(int i=0;i<length;i++)
        {
            cout<<*(arr+i);
        }
        cout<<endl;
    }


};

int main()
{
    list l1(6);
    l1.insert('e',1);
    l1.insert('f',2);
    l1.insert('a',3);
    l1.insert('b',4);
    l1.insert('i',5);
    l1.insert('r',6);
    int count=0;
    string name="fariba";
    l1.print();
    cout<<endl;
    while(1)
    {   
        cout<<"choose an option"<<endl;
        cout<<"1.remove"<<endl;
        cout<<"2.Insert "<<endl;
        int input;
        cin>>input;
        if (input==1)
        {
            cout<<"ENter the location u want to remove";
            int a;
            cin>>a;
            l1.remove(a);
            count++;
            l1.print();
        }
        else    if (input == 2){
            cout<<"ENter the position on which u want to enter character";
            int a;
            cin>>a;
            cout<<"ENter the charcter u want to add"<<endl;
            char c=' ';
            cin>>c;
            l1.insert(c,a);
            count++;
            l1.print();
        }
       char* arr=l1.pointer();
    
        
         string s=convertToString(arr,6);
         if (s==name)
        {
            cout<<"Word MAtched  you winnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn"<<endl;
            cout<<"You matched in"<<count<<"  tries"<<endl;
            break;
        }
        
    }
}

