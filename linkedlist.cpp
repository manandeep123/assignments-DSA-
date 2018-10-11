#include<iostream>
using namespace std;

//Structure of linked list
struct node
{
  int data;
  node* next;
};

class linkedlist
{
  int size_linkedlist;
  node *head,*tail;
  public:
      linkedlist()
      {  //Default constructor
         head=NULL;
         tail=NULL;
      }
     void create(int);
     void display();
     void insertelement(int);
     void delete_element(int);
     void merge_linkedlist();
};


void linkedlist::create(int n)
{
   //Creating linked list
   int i=1;
   size_linkedlist=n;
   node *temp=new node;
   //Creating 1st node
  cout<<"Enter element of "<<i<<"th node:";
  cin>>temp->data;
  temp->next=NULL;
  head=temp;
  tail=temp;
  //Creating remaining nodes
  for(i=2;i<=n;i++)
 {
  temp=new node;
  cout<<"Enter element of "<<i<<"th node:";
  cin>>temp->data;
  temp->next=NULL;
  tail->next=temp;
  tail=tail->next;
 }
}


void linkedlist::display()
{
    //Displaying linked list
 node *temp;
 for(temp=head;temp!=NULL;temp=temp->next)
 {
  cout<<temp->data<<"\n";
 }
}



int main()
{
 linkedlist l1;
 int total;
 cout<<"Enter no of elements:";
 cin>>total;
 l1.create(total);
 l1.display();
 return 0;
}
