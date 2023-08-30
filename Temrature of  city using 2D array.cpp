/*Write a program in which using a 2D array store the weekly temperatures of 
a month. Each row represents a week. 
• Populate the array using a pointer variable with random numbers (make 
use of rand() function) between 10-30 degree Centigrade. 
• Display the temperature of the whole month using a pointer.
• Find the hottest day of each week using a pointer, and also show the 
temperature on that day.
*/

#include<iostream>
#include<algorithm>

using namespace std;
string findday(int a)
{
    if(a==1)
    {
        return "monday";
    }
    else if(a==2){
        return "tuesday";
    }
    else if(a==3){
        return "wednesday";
    }
    else if(a==4)
    {
        return "thursday";
    }
     else if(a==5)
    {
        return "Friday";
    } else if(a==6)
    {
        return "Saturday";
    } else if(a==7)
    {
        return "Sunday";
    }


}
int main() {
    int temprature[4][7];
    int (*ptr1)[7];
    ptr1 = temprature;

    for (int i = 0; i < 4; ++i) {
        
        for (int j = 0; j < 7; j++) {

            *(*(ptr1 + i) + j) = rand() % 20 + 10; 
        }
    }

    cout << "Temperature of each week" << endl;
    for (int i = 0; i < 4; ++i) {

        for (int j = 0; j < 7; j++) {

            cout << *(*(ptr1 + i) + j) << "  ";
        }
        cout << endl;
    }





   
    

    for (int i = 0; i < 4; i++) {
        // int *max = std::max_element(*(ptr1 + i), *(ptr1 + i) + 7); // Find the max element in the week's array
        // int day = max - *(ptr1 + i) + 1; // Calculate the day index
         int max=0;
                  int day=0;
         int M=0;
      for(int j=0;j<7;j++)
      {
        if(*(*(ptr1+i)+j)>(max))
        {
            max=*(*(ptr1+i)+j);
            day=j+1;
            M=max;
        }
         
      }
      string a = findday(day);
        cout << "Hottest day of week " << i + 1 << " is " << a << " having a temperature " << max << endl;
       
    }


    return 0;
}
