#include <iostream>

struct node
{
    int data;
    struct node* nextnode;
    struct node* prevnode;
};

struct node* create_list(int);
void print_elements(struct node*);
int insert_element(struct node*&);
int delete_element(struct node*&);


using namespace std;

int main()
{
    struct node* h=NULL;
    int element;
    int option;
    int insert_status,delete_status,continue_status;
    cout<<"+------------------------------------------------------------------------------+\n";
    cout<<"\tDouble Linked List\n";
    cout<<"+------------------------------------------------------------------------------+\n\n";
    cout<<"\nCREATE DOUBLE LINKED LIST::\n\n";
    cout<<"Please enter the number of elements\n";
    cout<<"Elements --> ";
    cin>>element;

    h=create_list(element);
    cout<<"\nELEMENTS IN THE LINKED LIST::\n\n";
    print_elements(h);

    do
    {
        cout<<"\nACTION TO PERFOME ON LINKED LIST ::\n\n";
        cout<<" 1:    Insert element\n";
        cout<<" 2:    Delete element\n";
        cout<<" 3:    Display elements\n";
        cout<<" Option chosen :: ";
        cin>>option;


        switch(option)
        {

        case 1:
            cout<<"\nINSER ELEMENT::\n\n";
            insert_status=insert_element(h);
            if(insert_status==1)
            {
                cout<<"Element successively inserted\n";
                cout<<"Elements after insertion::\n\n";
                print_elements(h);
            }
            else
            {
                cout<<"Element not inserted\n";
            }
            break;


        case 2:
            cout<<"\nDELETE ELEMENT::\n\n";
            delete_status=delete_element(h);
            if(delete_status==1)
            {
                cout<<"Element successively deleted\n\n";
                cout<<"Elements after deletion::\n";
                print_elements(h);
            }
            else
            {
                cout<<"Element not deleted\n";
            }
            break;


        case 3:
            cout<<"\nDISPLAY ELEMENTS::\n\n";
            print_elements(h);
            break;


        default:
            cout<<"invalid option entered please try again later!\n";

        }
        cout<<"\n Wish to perform another action?\n";
        cout<<" 1:   Yes\n";
        cout<<" 2:   NO\n";
        cout<<"Enter your choice here ::   ";
        cin>>continue_status;
    }
    while(continue_status==1);

    return 0;

}


struct node* create_list(int element)
{
    struct node* h=NULL;
    struct node* q=NULL;
    struct node* p=NULL;
    int counter=0;
    int number;

    cout<<"\nenter the elements as below\n\n";

    while(counter!=element)
    {
        cout<<"Node "<<counter+1<<" element: ";
        cin>>number;


        if(counter==0)
        {
            q=new node;
            q->data=number;
            q->prevnode=NULL;
            h=q;
            p=q;
        }
        if(counter==(element-1))
        {
            q->data=number;
            q->nextnode=NULL;
            counter++;
            continue;
        }
        else
        {
            p=q;
            q->data=number;
        }
        q=new node;
        q->prevnode=p;
        p->nextnode=q;


        counter++;
    }
    p=q=NULL;

    return h;
}


void print_elements(struct node* h)
{
    struct node* q;
    int counter=1;
    q=h;

    while(q!=NULL)
    {
        cout<<" Node "<<counter<<" Element\t"<<(q->data)<<"\n";
        q=q->nextnode;
        counter++;

    }
}

int insert_element(struct node*& h)
{
    struct node* q=h;
    struct node* p;
    int value;
    int position;
    int element;

    if(q==NULL)
    {
        return 0;
    }

    cout<<"please enter the element to insert\n";
    cout<<" Element  ";
    cin>>value;

    p=new node;
    p->data=value;

    cout<<"\nWhich position do you wish to insert\n";
    cout<<" 1:     After certain element(NOT LAST ELEMENT)\n";
    cout<<" 2:     Before certain element(NOT SECOND ELEMENT)\n";
    cout<<" 3:     As first element\n";
    cout<<" 4:     As last element\n";
    cin>>position;

    if(position!=1 && position!=2 && position!=3 && position!=4)
    {
        cout<<"\ninvalid entry position entered\n";
        return 0;
    }

    if(position==3)
    {
        p->prevnode=NULL;
        p->nextnode=q;
        q->prevnode=p;
        h=p;
        return 1;
    }

    if(position==4)
    {
        while(q!=NULL)
        {
            if(q->nextnode==NULL)
            {
                p->nextnode=NULL;
                p->prevnode=q;
                q->nextnode=p;
                return 1;
            }
            q=q->nextnode;
        }
    }


    cout<<"\nPlease enter the element i from the list\n";
    cin>>element;


    while(q!=NULL)
    {
        if(q->data==element)
        {
            if(position==1)
            {
                p->nextnode=q->nextnode;
                p->prevnode=(q->nextnode)->prevnode;
                (q->nextnode)->prevnode=p;
                q->nextnode=p;
                return 1;
            }
            if(position==2)
            {
                p->nextnode=q;
                p->prevnode=q->prevnode;
                (q->prevnode)->nextnode=p;
                q->prevnode=p;
                return 1;
            }
        }
        q=q->nextnode;
    }
    cout<<"\nelement i entered was not found\n";
    return 0;
}


    int delete_element(struct node*& h)
    {
        struct node* q=h;
        struct node* p;
        int counter=0;
        int element;

        if(h==NULL)
        {
            cout<<"Linked list doest'n exist\n";
            return 0;
        }
        cout<<"please enter the element to delete\n";
        cout<<" Element   ";
        cin>>element;

        while(q!=NULL)
        {

            if(q->data==element)
            {
                if(counter==0)
                {
                    q=q->nextnode;
                    q->prevnode=NULL;
                    h=q;
                    return 1;
                }

                if(q->nextnode==NULL)
                {
                    (q->prevnode)->nextnode=NULL;
                }

                else
                {
                    (q->prevnode)->nextnode=q->nextnode;
                    (q->nextnode)->prevnode=q->prevnode;
                }

            }
            counter++;
            q=q->nextnode;
        }
        cout<<"Element not found\n";
        return 0;
}
