#include <iostream>
#define MAX_LIST_SIZE 100

int insert_element(int * linear_list);
int delete_element(int * linear_list);
void display_list(int * linear_list);
int search_list(int * linear_list,int element);

int elements;

using namespace std;

int main()
{
    int linear_list[MAX_LIST_SIZE];
    int counter=0;
    int action;
    int status;
    int continue_status;

    cout<<"--------------------------------------------------------------------------------\n";
    cout<<"\t\tLINEAR LIST\n";
    cout<<"--------------------------------------------------------------------------------\n";
    cout<<"\t CREATE LINEAR LIST\n";
    cout<<"\t____________________\n";
    cout<<"please give the number of elements to enter into your list\n";
    cout<<"elements\t";
    cin>>elements;

    while(elements<=0)
    {
        cout<<"Invalid number elements entered\n";
        cout<<"please enter correct number of elements\n";
        cout<<"elements\t";
        cin>>elements;
    }

    cout<<"enter the elements as follows\n";
    while(counter!=elements)
    {
        cout<<"\n    element "<<counter + 1<<"\t-----";
        cin>>linear_list[counter];
        counter++;
    }

    do
    {
        cout<<"--------------------------------------------------------------------------------\n";
        cout<<"\t\tSELECT ACTION\n";
        cout<<"--------------------------------------------------------------------------------\n";
        cout<<"enter the number corresponding to an action you want to perform\n";
        cout<<"  1         delete from list\n";
        cout<<"  2         insert into list\n";
        cout<<"  3         display list\n";
        cout<<"\n  Action   ";
        cin>>action;

        switch(action)
        {
        case 1:
            status=delete_element(linear_list);
            if(status==1)
            {
                cout<<"\nelement successively deleted from list\n\n";
                display_list(linear_list);
            }
            else
            {
                cout<<"element couldn't be deleted\n";
            }
            break;

        case 2:
            status=insert_element(linear_list);
            if(status==1)
            {
                cout<<"\nelement successively inserted into list\n\n";
                display_list(linear_list);
            }
            else
            {
                cout<<"\nelement couldn't be inserted\n";
            }
            break;

        case 3:
            display_list(linear_list);
            break;

        default:
            cout<<"\ninvalid choice entered\n";
        }
        cout<<"\nchoose\n";
        cout<<" 1    Another action\n";
        cout<<" 2    Exist the program\n";
        cin>>continue_status;


    }
    while(continue_status==1);

    return 0;
}


    int insert_element(int * linear_list)
    {
        int position;
        int value;
        int counter;

        cout<<"please enter the position you want to insert your element\n";
        cout<<"position\t";
        cin>>position;
        if(position<0 || position>elements+1)
        {
            cout<<"element can't be entered in that position\n";
            return 0;
        }
        cout<<"please enter the element to be inserted\n";
        cin>>value;

        if(position==elements+1)
        {
            linear_list[elements-1]=value;
        }
        else
        {
            for(counter=elements-1;counter>=position;counter--)
            {
                linear_list[counter+1]=linear_list[counter];
            }
            linear_list[position]=value;
        }
        elements++;
        return 1;

    }


    int delete_element(int * linear_list)
    {
        int element;
        int counter;
        int position;

        cout<<"please enter the element you want to delete from the list\n";
        cout<<"Element \t";
        cin>>element;

        position=search_list(linear_list,element);
        if(position!=-1)
        {
            cout<<"Element found at position "<<position;
            if(position==elements)
            {
                elements--;

            }
            else
            {
                for(counter=position;counter<elements;counter++)
                {
                    linear_list[counter]=linear_list[counter+1];
                }
                elements--;
            }
            return 1;

        }
        else
        {
            cout<<"Element not found in the linear list\n";
        }
        return 0;
    }


    int search_list(int*linear_list,int element)
    {
        int i;
        for(i=0;i<elements;i++)
        {
            if(linear_list[i]==element)
            {
                return i;
            }

        }
        return -1;
    }


    void display_list(int * linear_list)
    {
        int counter;
        cout<<"+++++++++++++++++++++++++++++++++++++++\n";
        for(counter=0;counter<elements;counter++)
        {
            cout<<" element "<<counter+1<<"\t"<<linear_list[counter]<<"\n";

        }
        cout<<"+++++++++++++++++++++++++++++++++++++++\n";

    }


