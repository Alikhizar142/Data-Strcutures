/*Write a menu driven program in which you should input a string without space 
from the user, and the program should perform the following operations using 
pointers:
• Check if the string is palindrome.
• Count the frequency of a certain character.*/


#include<iostream>
using namespace std;

int Count_character(char a,string str)
{int count=0;
    int p=str.size();
    char *char1=&str[0];
    for(int i =0 ;i<p;i++){
        char b= *(char1+i);
        if(a==b)
          count++;


    }
    return count;
}

bool Palandrome(string str)
{
    char *start=&str[0];
    char *end=&str[str.size()-1];

    while (start  < end)
    {
        if(*start == *end)
        {
            return true;
        }
        else
        return false;

        start++;
        end--;
    }


}
int main()
{
    string input;
    cin>>input;
        int in;
    while(in!=3)
    {
        cout<<"1.Check if the string is palindrome."<<endl;
        cout<<"2.Count the frequency of a certain character."<<endl;
        cout<<"3.exit"<<endl;
        cout<<"\nEnter your choice:";
        cin>>in;
        if(in==1)
        {
            bool a=Palandrome(input);
            if(a)
            {
                    cout<<"String is palandrome"<<endl;
            }
            else
            {   
                cout<<"Not a palindrom"<<endl;
            }
        }
        else if(in==2)
        {
            cout<<"Enter the character u want to count"<<endl;
            char ch;cin>>ch;
            int a= Count_character(ch,input);
            cout<<"The character "<<ch<<"is     "<<a<<" time in string"<<endl;

        }
        else
        break;
    }

}