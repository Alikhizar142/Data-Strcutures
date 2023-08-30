/*Write a program that simulates a simple collision detection game. Create a 2D 
grid of 3x3 that represents the game world. Each cell can contain either a 
reward or a collision object. Randomly populate the array with either – or x, 
where – represents a safe place, and x represents a collision object. However, 
at the start of the game, the player must be located in the middle of the grid. 
So, the character at the middle the grid should be o. If the player moves to a 
cell containing a reward, he won, so display the message “Yayy, you won, it 
was a reward”. But if that cell contained a collision object, the player will die, 
so display the message “You lost, it was a collision object”. Implement 
movement of a player within the grid using pointers. The valid moves for 
a player are either top, bottom, left, and right.*/

#include<iostream>
using namespace std;
void print(char *pos,int n,int m)
{
     for(int i=0;i<n;i++)
      {
    
    
            for(int i=0;i<m;i++)
            {
              cout<<*pos<<" ";
              pos++;
            }
        cout<<endl;
      }

}
int main() {
     int n,m;
     n=3;m=3;
      char arr[n][m];
      char *pos=&arr[0][0];
       char *curr=NULL;

      for(int i=0;i<n*m;i++)
      {
         if(i==((n*m)-1)/2)
            {
                *(pos+i)='o';
                 continue;
            }
        int a=rand()%2+1;
            
            if(a==1)
            {
                *(pos+i)='x';
            }
            else
            *(pos+i)='-';
      }
      pos=&arr[0][0];
      //print(pos,n,m);
      curr=(pos+((n*m)-1)/2);
      cout<<"current postion is "<<*curr<<endl;

      cout<<"ENter the Postion u want to move you r in the middle of the grid"<<endl;
      cout<<"1.Top"<<endl;
      cout<<"2.Bottom"<<endl;
      cout<<"3.Left"<<endl;
      cout<<"4.Right"<<endl;
      int input;
      cin>>input;

      while(1)
      {
      if(input==1)
      {
        print(pos,n,m);
        curr=curr-n;
          cout<<"Current position after moving top is "<<*(curr)<<endl;
          if(*curr=='x')
          {
            cout<<"You lose Collide "<<endl;
          }
          else
          {
                      cout<<"Hurrrayyyy    you won"<<endl;
          }

      }
      else if(input==2)
      {
        print(pos,n,m);
        curr=curr+n;
          cout<<"Current position after moving top is "<<*(curr)<<endl;
          if(*curr=='x')
          {
            cout<<"You lose Collide "<<endl;
          }
          else
          {
                      cout<<"Hurrrayyyy    you won"<<endl;
          }

      }
      else if(input==3)
      {
        print(pos,n,m);
        curr=curr-1;
          cout<<"Current position after moving top is "<<*(curr)<<endl;
          if(*curr=='x')
          {
            cout<<"You lose Collide "<<endl;
          }
          else
          {
                      cout<<"Hurrrayyyy    you won"<<endl;
          }

      }
      else if(input==4)
      {
        print(pos,n,m);
        curr=curr+1;
          cout<<"Current position after moving top is "<<*(curr)<<endl;
          if(*curr=='x')
          {
            cout<<"You lose Collide "<<endl;
          }
          else
          {
                      cout<<"Hurrrayyyy    you won"<<endl;
          }


      }
      else
      cout<<"BY BY U Enter wrong number"<<endl;
      break;
      }

}