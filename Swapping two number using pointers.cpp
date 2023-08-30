/*. Write a program to swap two numbers using pointers. The pointers must be 
passed to the function.*/



#include<iostream>
using namespace std;
void swap(int *p1,int *p2)
{
     int temp;
    temp = *p1;
    *p1=*p2;//assigning value to first address
    *p2=temp;
}
int main()
{
    int a,b;
    int *ptr1,*ptr2;
    ptr1=&a;//address of variable is stored in pointer 1
    ptr2=&b;
    cout<<"Enter vlaues of a and b";
    cin>>*ptr1>>*ptr2;
    cout<<"Before swaping a= "<<*ptr1<<"  and value of b="<<*ptr2<<endl;
    //swap the values using pointers
    swap(*ptr1,*ptr2);
    cout<<"After swaping a= "<<*ptr1<<"  and value of b="<<*ptr2<<endl;

}