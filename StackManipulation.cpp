#include <iostream>
#define MAX_STACK_SIZE 20

int create_stack(int* stack_array);
int stack_push(int * stack_array);
int stack_pop(int * stack_array);
void display_stack(int * stack_array);
int top=0;


using namespace std;

int main()
{
    int counter;
    int element_no;
    int stack_array[MAX_STACK_SIZE];
    int choice , create_status , pop_status , push_status;
    int termination_status=1;

    while(termination_status==1)
    {
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout<<"\t\tSTACK MANIPULATION\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout<<"  please choose the action to perform\n\n";
        cout<<"    1         Create stack\n";
        cout<<"    2         Push to stack\n";
        cout<<"    3         Pop from stack\n\n";
        cout<<"\n  Enter your choice here----   ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            create_status=create_stack(stack_array);
            if(create_status==0)
            {
                cout<<"stack created successively\n";
                display_stack(stack_array);
            }
            else
            {
                cout<<"stack not created\n";
            }
            break;

        case 2:
            push_status=stack_push( stack_array);
            if(push_status==0)
            {
                cout<<"element entered successively\n";
                display_stack(stack_array);
            }
            else
            {
                cout<<"element couldn't be added to the stack\n";
            }
            break;

        case 3:
            pop_status=stack_pop( stack_array);
            if(pop_status==0)
            {
                cout<<"element deleted successively\n";
                display_stack(stack_array);
            }
            else
            {
                cout<<"element can't be deleted\n";
            }
            break;

        default:
            cout<<"invalid choice entered please try again\n";
        }
        cout<<"--------------------------------------------------------------------------------\n";
        cout<<"\t\tANOTHER STACK OPERATION\n";
        cout<<"--------------------------------------------------------------------------------\n";
        cout<<"    Do you want to perform another operation?\n";
        cout<<"      1      YES\n";
        cout<<"      2       NO\n";
        cout<<"\n      choice         ";
        cin>>termination_status;
    }


    return 0;


}
int create_stack(int* stack_array )
{
    char option;
    int counter=0;
    int element_no;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<"\t\tCREATE STACK\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout<<"  please enter the number of elements for the stack\n";
    cout<<"  Number of elements-------";
    cin>>element_no;
    cout<<"\n";
    while(element_no==MAX_STACK_SIZE ||element_no<=0)
    {
        cout<<"\n    elements entered exceed the maximum stack size\n";
        cout<<"   attempt to create the stack again? 'Y' or 'N'\n";
        cout<<"   option\t";
        cin>>option;
        if(option=='Y')
        {
            cout<<"\n    please enter the number of elements for the stack\n";
            cout<<"    Number of elements\t";
            cin>>element_no;
            continue;
        }
        else
        {
            return 1;
        }
    }

    while(counter!=element_no)
    {
        cout<<"++++++++++++++++++++++++++++\n";
        cout<<"+  Element    "<<counter+1<<"\t";
        cin>>stack_array[counter];
        cout<<"+\n";
        counter++;
        top=top + 1;
    }
    cout<<"++++++++++++++++++++++++++++";


    return 0;
}



int stack_push(int* stack_array)
{
    int element;
    cout<<"--------------------------------------------------------------------------------\n";
    cout<<"\t\tPUSH INTO STACK\n";
    cout<<"--------------------------------------------------------------------------------\n";
    if(top==MAX_STACK_SIZE)
    {
        cout<<"    Stack overflow!\n";
        return 1;
    }
    else
    {
        cout<<"    please enter the element to push into the stack\n";
        cout<<"    Element \t";
        cin>>element;
        stack_array[top]=element;
        top = top + 1;
    }
    return 0;
}



int stack_pop(int * stack_array)
{
    if(top==0)
    {
        return 1;
    }
    else
    {
        top=top - 1;
    }
    return 0;
}


void display_stack(int * stack_array)
{
    cout<<"--------------------------------------------------------------------------------\n";
    cout<<"\t\tDISPLAY STACK\n";
    cout<<"--------------------------------------------------------------------------------\n";
    int counter=0;
    cout<<"    ___________________ <--- Top\n";
    for(counter=top-1;counter>=0;counter--)
    {
        cout<<"            "<<stack_array[counter]<<"         \n";
        cout<<"    ___________________\n";
    }


}






