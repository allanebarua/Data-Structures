#include <iostream>

struct node//structure representing a node
{
    int data;
    node* nextnode;
};
struct node* q=NULL;
struct node* p=NULL;

struct node* create_linear_list(int );//function that creates the linked list and returns the head pointer
void printelements(struct node* );//prints the elements in the linked list
int delete_element(struct node*&,int);//deletes specified element
int search_element(struct node*,int);//searching an element from the linked list
int length(struct node*);//calculates the number of elements in the linked list
int insert_element(struct node*&,int,int,int);//inserting an element in the list

using namespace std;

int main()
{
    int element;//number of elements to be stored in a linked list
    int action;//action to be performed by the program
    int position;//deletion position
    struct node* h=NULL;//head pointer
    int result;//return value to show state of the computations
    int number=0;

 //creating user interface
    cout<<"\tLINKED LIST\n";
    cout<<"______________________________________________________________________________\n";
    cout<<"Do you want to create the linked list first?\n\n";
    cout<<" 1          -------------YES\n";
    cout<<" Any integer-------------NO\n";
    cout<<" Option     -------------";
    cin>>action;
    cout<<"\n_______________________________________________________________________________\n";
    if(action==1)
    {
        cout<<"\nCREATE LINEAR LIST\n";
        cout<<"_________________________________________________________________________________\n";
        cout<<"Please enter the number of elements to store in the linear list:\n\n";
        cout<<"\tNo of Elements  ";
        cin>>element;
        h = create_linear_list(element);
    }
    cout<<"______________________________________________________________________________\n";
    cout<<"\n\tACTION ON THE LINKED LIST\n";
    cout<<"______________________________________________________________________________\n";
    cout<<"\nplease choose a number corresponding to an action you want to perform\n\n";
    cout<<"    1          insert element\n";
    cout<<"    2          delete element\n";
    cout<<"    3          display elements\n";
    cout<<"    Action------------------";

    cin>>action;

    switch(action)//switch statement to allow the program to perform the chosen action
    {
case 1://case for insertion of an element
    if(h==NULL)
    {
        cout<<"\nNo linked list exists!\n";
        break;
    }
    cout<<"______________________________________________________________________________\n";
    cout<<"\n\n\tINSERT ELEMENT\n";
    cout<<"______________________________________________________________________________\n";
    cout<<"enter the element to insert\n";
    cout<<"  Element--------------";
    cin>>element;
    cout<<"\nwhere do you want to insert the element as outlined below\n";
    cout<<"\n1 -------Start of the linked list\n2 --------End of the linked list\n3 --------After given element i\n";
    cout<<"  Position-----------";
    cin>>position;
    if(position==3)
    {
        cout<<"enter i(from the linked list)\n";
        cin>>number;
        result=insert_element(h,element,position,number);
    }
    else
    {
        if(position==1 || position==2)
        {
            result=insert_element(h,element,position,number);
        }
        else
        {
            cout<<"\ninvalid insertion position entered! \n";
            break;
        }
    }
    if(result==-1)
    {
        cout<<"\nelement not inserted\n";
        cout<<"\nelement i entered does not exist\n";
    }
    if(result==0)
    {
        cout<<"\nelement successively inserted\n";
    }
    cout<<"\nelements after insertion are as follows\n";
    printelements(h);



    break;

case 2://case for deleting an element
    if(h==NULL)
    {
        cout<<"\nNo linked list exists!\n";
        break;
    }
    cout<<"______________________________________________________________________________\n";
    cout<<"\n\tDELETE ELEMENT\n";
    cout<<"______________________________________________________________________________\n";
    cout<<"Enter element to be deleted\n";
    cout<<"   element-----------";
    cin>>element;
    result=delete_element(h,element);
    if(result==1)
    {
        cout<<"element deleted successively!\n";
    }
    if(result==0)
    {
        cout<<"element not found!\n";
    }
    cout<<"\nelements of the linked list after insertion\n";
    printelements(h);
    break;

case 3://case for printing element in the list
    if(h==NULL)
    {
        cout<<"\nNo linked list exists!\n";
        break;
    }
    cout<<"______________________________________________________________________________\n";
    cout<<"\n\tELEMENTS IN THE LINKED LIST\n";
    cout<<"______________________________________________________________________________\n";
    printelements(h);
    break;

default://default action taken when an invalid action is entered
    cout<<"\ninvalid option selected!\n";
    }

    return 0;
}//end of main function

//**************************************************************************************************************
struct node* create_linear_list(int x)//creating the linked list
{
    node* h=NULL;//head pointer
    node* p=NULL;//trailing pointer
    node* q=NULL;
    int i;//counter variable
    int element;//variable for element to be stored in a node data section

    cout<<"enter elements for each node as shown below\n";
    for(i=0;i<x;i++)
    {
       cout<<"Node "<<(i+1)<<"\t";
       cin>>element;

       q=new node;//create new node pointed to by pointer q
       q->data=element;//store element in the data field
       if(i==0)//test if element stored is the first one
        {
            h=q;
            p=q;
        }
       if(i==(x-1))//test if element stored is the last one
        {
            q->nextnode=NULL;//assign the link field of the last node to null
        }
       p->nextnode=q;
       p=q;

    }

    q=NULL;
    p=NULL;
    cout<<"\nthe elements have been stored\n";

    return h;
    }
    //************************************************************************************************************

    void printelements(struct node* h)//print function
    {
        int element;
        node* q=h;
        int counter=1;
        while(q!=NULL)
        {
            element=q->data;
            cout<<"Element in node "<<counter<<" --- "<<element<<"\n";
            q=q->nextnode;
            counter++;
        }

    }
    //************************************************************************************************************

     int delete_element(struct node*& h,int element)//delete function
    {
        node* q;
        int list_length=length(h);
        node* p;
        int num=1;
        int element_no=search_element(h,element);
        q=h;
        if(element_no==-1)
        {
            return 0;
        }
        if(element_no==1)
        {
            q=q->nextnode;
            h=q;
            q=NULL;
            return 1;

        }
        if(element_no>0 && element_no<list_length)
        {
            while(q->data!=element)
            {
                p=q;
                q=q->nextnode;
            }
            p->nextnode=q->nextnode;
        }
        if(element==list_length)
        {
            while(q!=NULL)
            {
                p=q;
                q=q->nextnode;
            }
            p->nextnode=NULL;

        }
        p=NULL;
        q=NULL;
        return 1;

    }
    //**********************************************************************************************************
    int search_element(struct node* h,int element)//search function
    {
        struct node*q;
        q=h;
        int element_no=1;
        while(q!=NULL)
        {
            if((q->data)==element)
            {
                return element_no;
            }
            q=q->nextnode;
            element_no++;

        }
        return -1;
    }
    //********************************************************************************************************
    int length(struct node*h)//compute length of the linked list
    {
        struct node* q=h;
        int counter=1;
        while(q->nextnode!=NULL)
        {
            counter++;
            q=q->nextnode;
        }
        return counter;

    }
    //**********************************************************************************************************
    int insert_element(struct node*& h,int element,int position,int number)//insert function
    {
        node* q=NULL;
        node* p=NULL;
        q=h;
        p=new node;
        p->data=element;

        if(position==1)
        {
            p->nextnode=q;
            h=p;
        }
        if(position==2)
        {
            while(q->nextnode!=NULL)
            {
                q=q->nextnode;
            }
            q->nextnode=p;
        }
        if(position==3)
        {
            if(search_element(h,number)!=-1)
            {
                while(q->data!=number)
                {
                    q=q->nextnode;
                }
                p->nextnode=q->nextnode;
                q->nextnode=p;

            }
            else
            {
                return -1;
            }

        }
        return 0;

    }

