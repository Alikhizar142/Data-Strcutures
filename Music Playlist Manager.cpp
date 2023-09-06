/*Create a menu-driven music playlist manager program using a singly linked list to manage your
favorite songs. Each song in the playlist will have a name.
The program should offer the following options:

Add a Song: When the user adds a song, the program should ask the name of the song,
after that the user will be prompted to specify its "favorite level." They can choose from
the following options:
1. (Top Favorite): The song will be inserted at the beginning of the playlist.
2. (Lease Favorite): The song will be inserted at the end of the playlist.
3. Somewhere between (let me specify the number): If the user selects a custom
favorite level (e.g., 2 to 4), the program will display valid priority levels based
on the current number of songs in the playlist (e.g., 2 to 5 for a playlist of 5
songs). The song will be inserted at the specified custom priority position.
Delete a Song: Users can remove a song from the playlist by entering its name/ position
(depends on you).
Search for a Song: Users can search for a song by its name and display the name and
level of how much favorite it is.
Update a song name: Thie function will take the song number, and the new name, and
update the song name on that position.
Print Playlist: This option will display the entire playlist with song names.
Play Song: Users can start playing songs from the beginning of the playlist. When the
user clicks on Play Song, play the first song in the list. After that the user can select the
option of play next song, so the program will play the next song from the list (just a
simulation by displaying the song name.
Exit: Exit the program.
Note: After each insertion, update, or removal operation, print the playlist. Your program
should have all the checks for invalid input. The update song option is not showed in the
sample output, but you must implement it in your code, and display the menu accordingly.*/
#include <iostream>
using namespace std;
class node
{ public:
    string data;
    node *next;
    node(string val)
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
        for(int i=1;i<=length;i++)
        {
            curr=head;
            head=head->next;
            delete curr;
        }
    }
    
    void insert(string val,int pos)
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
        if(is_empty())
        cout<<"List is empty"<<endl;
        else
        {
            cout<<"            Songs list      "<<endl;
         node *curr =head;
        for (int i = 1; i <=length; i++)
        {
            cout<< i <<"  -- " << curr -> data<<endl;
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

    int find(string val)
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
    void play()
    {
        if(is_empty())
        cout<<"List is empty"<<endl;
        else
        {
            
         node *curr =head;
        for (int i = 1; i <=length; i++)
        {
            cout<<("            Currently playing        ");
            cout<< "        "    <<curr -> data<<endl;
            cout<<"do you want to play next song(y/n)"<<endl;
            char a;
            cin>>a;
            if(a=='n')
            {
                break;
            }
            else
            curr=curr->next;
        }

         }
    }

    void update(string val,int pos)
    {
        if(is_empty())
        {
            cout<<"List is empty"<<endl;
        }


        node *arr=head;
        for(int i=1;i<=length;i++)
        {
            if(i==pos)
            
            {
                 arr->data=val;
            }
            arr = arr -> next ;
        }

    }

    int get_length()
    {
        return length;
    }
    string get_song(int pos)
    {
        if(is_empty())
        {
            cout<<"List is empty"<<endl;
        }


        node *arr=head;
        for(int i=1;i<=length;i++)
        {
            if(i==pos)
            
            {
                 return arr->data;
            }
            else
            arr = arr -> next ;
        }

    }
};

int main()
{
    list l;
    while(1)
    {
        cout<<"             MENU        "<<endl;
        cout<<"1.Add song"<<endl;
        cout<<"2.Delete a Song "<<endl;
        cout<<"3.Search songs in List"<<endl;
        cout<<"4.Update Songs"<<endl;
        cout<<"5.print "<<endl;
        cout<<"6.play song"<<endl;
        cout<<"7.exit"<<endl;
        int input;
        cin>>input;
        if(input==1)
        {
            cout<<"Enter the song name you want to insert"<<endl;
            string name;
            cin.ignore();
            getline(cin,name);
            cout<<"Choose where u want to store it"<<endl;
            cout<<"1.Top favourit"<<endl;
            cout<<"2.least favourit"<<endl;
            cout<<"3.let me descide"<<endl;
            int n;
            cin>>n;
            if(n==1)
            {
                l.insert(name,1);
            }
            else if(n==2)
            {
                l.insert(name,l.get_length()+1);
            }
            else if(n==3)
            {
                cout<<"Enter the postion on which u want to add song"<<endl;
                              int pos;
                              cin>>pos;
                l.insert(name,pos);              
            }
            else
            cout<<"In valid choice"<<endl;

            l.print();

        }
        else if(input==2)
        {
            cout<<"Enter the position of the song u want to remove"<<endl;
               int pos = 0 ; 
               cin >> pos;
               l.remove(pos);
               l.print();
        }
        else if(input==3)
        {
            cout<<"Enter the song name you want to search "<<endl;
            string s;
            cin.ignore();
            getline (cin ,s );
           int pos= l.find(s);
           string song=l.get_song(pos);
           cout<<"Favourite at "<<pos<<"  "<<song<<endl;

        }
        else if(input==4)
        {
            cout<<"Enter the song number you want to update"<<endl;
            int pos;
            cin>>pos;
            cout<<"Enter the new song name"<<endl;
            string s;
            cin.ignore();
            getline (cin ,s );
            l.update(s,pos);
            cout<<"List updated"<<endl;
            l.print();
        }
        else if(input==5)
        {
            l.print();

        }
        else if(input==6)
        {
            l.play();

        }
        else if(input==7)
        {
            break;

        }
    
    }
   
}
