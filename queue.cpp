#include <iostream>
#define MAX_QUEUE_SIZE 10

int dequeing(int *,int *,int);
int enqueing(int *,int *,int,int *);
void display_queue(int *,int,int);

using namespace std;

int main(void)
{
    int queue_front=-1;
    int queue_rear=-1;
    int queue_array[MAX_QUEUE_SIZE];
    int elements;
    int status;
    int counter=0;
    int number;
    int option;
    int delete_status=0,insert_status=0,continue_status=1;

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<"MAXIMUM QUEUE SIZE=10\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<"please enter the number of elements you wish to enter to the queue\n";
    cout<<"\nElements\t";
    cin>>elements;

    while(elements>MAX_QUEUE_SIZE)
    {
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout<<"elements are more than the queue can handle please enter\n";
        cout<<"1 ------->to create the queue again\n2 --------->to skip creation of the queue\n";
        cout<<"option\t";
        cin>>status;
        if(status==1)
        {
           cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
           cout<<"\nplease enter the number of elements you wish to enter to the queue\n";
           cout<<"Elements\t";
           cin>>elements;
           continue;
        }
        if(status==2)
        {
            cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout<<"NB no queue was created\n";
            break;
        }
        else
        {
            cout<<"invalid choice entered please try again\n";
        }
    }
    if(elements<=MAX_QUEUE_SIZE)
    {
        cout<<"\tCREATING QUEUE\n";
        cout<<"\t--------------\n";

        while(counter!=elements)
        {
            cout<<"Element "<<counter+1<<"\t";
            cin>>queue_array[counter];
            counter++;
            queue_rear++;
        }
    }
    while(continue_status==1)
    {
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout<<"please enter the action to be performed\n";
        cout<<"1 ------>  dequeue\n2 ------->  enqueue\n3 ------->  display queue\n";
        cout<<"option\t";
        cin>>option;

        switch(option)
        {
        case 1:
            cout<<"\n\tDEQUEING\n";
            cout<<"\t--------\n";
            delete_status=dequeing(queue_array ,&queue_front,queue_rear);
            if(delete_status==1)
            {
                display_queue(queue_array,elements,queue_front);
            }
            break;

        case 2:
            cout<<"\n\tENQUEING\n";
            cout<<"\t--------\n";
            insert_status=enqueing(queue_array ,&queue_rear,queue_front,&elements);
            if(insert_status==1)
            {
                display_queue(queue_array,elements,queue_front);
            }

            break;

        case 3:
            display_queue(queue_array,elements,queue_front);
            break;
        }
        continue_status--;
        cout<<"To perform another operation please enter 1 else enter any number to close the program\n";
        cout<<"continue status\t";
        cin>>continue_status;
    }

    return 0;
}


int dequeing(int *queue_array,int *queue_front,int queue_rear)
{
    int delete_status;

    if(queue_rear==*queue_front)
    {
        cout<<"the queue is empty!";
    }
    else
    {
        *queue_front=*queue_front+1;
        delete_status=1;
    }
    return delete_status;
}


int enqueing(int *queue_array,int *queue_rear,int queue_front,int *element)
{
    int insert_status=0;
    int value;
    if(*queue_rear==(MAX_QUEUE_SIZE -1))
    {
        cout<<"the queue is full!\n";
        return insert_status;
    }
    if(*queue_rear==queue_front)
    {
        cout<<"the queue doest exist\n";
        return insert_status;
    }
    cout<<"please enter the element you want to enter to the queue\n";
    cout<<"element\t";
    *queue_rear=*queue_rear + 1;
    cin>>queue_array[*queue_rear];
    *element=*element + 1;
    return insert_status+1;

}


void display_queue(int *queue_array,int elements,int queue_front)
{
    int counter=queue_front +1;
    int element_no=1;
    if(elements==0)
    {
        cout<<"No element in the list\n";
    }
    else
    {
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout<<"\tELEMENTS IN THE QUEUE\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        while(counter!=elements)
        {
            cout<<"\nElement "<<element_no<<"\t"<<queue_array[counter];
            element_no++;
            counter++;

        }
        cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    }
}
