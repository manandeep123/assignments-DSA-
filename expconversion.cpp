//============================================================================
// Name        : expconversion.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*write a c++ program
 * write a expression conversion as infix to postfix and its evaluation on
 * using stack based on given condition
 * 1)operands and operators both must be single char
 * 2)input postfix must be in desired format
 * 3)only +,-,*,/ are expected
 */
#include<iostream>
#include<cstring>
using namespace std;

struct node
{
  string data;
  struct node *next;
};

class Stack
{
  int top;
  node *head;
  public:
  Stack()
  {
    head=NULL;
    top=-1;
  }
  void push(string);
  string pop();
  bool isEmpty();
  ~Stack(){}
};

void Stack::push(string str)
{
  if(isEmpty())
  {
     node *temp=new node;
     temp->data=str;
     temp->next=NULL;
     head=temp;
     top++;
  }
  else
  {
    node *p;
    for(p=head;p->next!=NULL;p=p->next);
    node *temp=new node;
    temp->data=str;
    temp->next=NULL;
    p->next=temp;
    top++;
  }
}

string Stack::pop()
{
   string temp;
   if(top==0)
   {
	 temp=head->data;
	 node *p=head;
	 top--;
	 delete(p);
	 head=NULL;
     return temp;
   }
   else
   {	node *p,*q;
     for(p=head;p->next!=NULL;p=p->next)
     {
       q=p;
     }
     top--;
     temp=p->data;
     delete(p);
     q->next=NULL;
     return temp;
   }
}


bool Stack::isEmpty()
{
  if(top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void postfix_to_infix(string str)
{
	int length=0;
	for(int i=0;str[i]!='\0';i++)
	{
		length++;
	}
	Stack s;
	string res;
	for(int i=0;i<length;i++)
	{
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			string temp1 = s.pop();
			string temp2 = s.pop();
			res="("+temp2+str[i]+temp1+")";
            s.push(res);
		}
		else
		{
		    res=str[i];
            s.push(res);
		}
	}
    res=s.pop();
	cout<<"\nINFIX: "<<res;
}

int main()
{
  char s[20];
  cout<<"\nEnter expression :";
  cin>>s;
  postfix_to_infix(s);
  cout<<"\nCode finished.";
  return 0;
}
