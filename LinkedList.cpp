
#include <iostream>

using namespace std;

int main()
{
    int list[100];
    int element;//the element you will insert
    int position;//the position to put the element

    int n;//gives size of the list

    cout << "How many elements do you want to store"<<endl;
    cin >>n;

         for(int i = 0; i < n;i++)
        {
            cout << "Enter element: ";
            cin >>list[i];
        }

        cout <<"\nThe array is:" <<endl;
        //this loop prints out the elements in the array
        for(int i = 0;i < n;i++)
        {
            cout << list[i];
            cout <<" ";
        }
    cout<<endl;


    cout <<"Enter element to be deleted: ";
    cin >>element;

    cout <<"Enter the postion: ";
    cin >>position;

    int i = position + 1;//i takes the position right after the one thats supposed to be deleted
    while(i<=n-1)//n-1 is the upper bound of array
    {
        list[i-1] = list[i];
        i = i + 1;
    }
    n=n-1;//decrement size of array by one

    cout<<"\nThe new array after deletion is: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<" "<<list[i];
    }
    return 0;
}
