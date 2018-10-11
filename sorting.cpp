//============================================================================
// Name        : sorting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Sort
{
public:
   int *a;
   int size;
   void read();
   void display();
   void bubble_sort();
   void selection_sort();
   void insertion_sort();
   void quick_sort(int,int);
   int partition(int,int);
};

void Sort::read()
{
	cout<<"\nEnter size of array";
	cin>>size;
	a=new int[size];
	cout<<"\nEnter elements of array:";
	for(int i=0;i<size;i++)
	{
		cout<<"\nEnter element a["<<i<<"]:";
		cin>>a[i];
	}
}

void Sort::display()
{
	cout<<"\nElements in array are: ("<<a[0];
	for(int i=1;i<size;i++)
	{
		cout<<","<<a[i];
	}
	cout<<")"<<endl;
}

void Sort::bubble_sort()
{
	for(int i=1;i<=size-1;i++)
	{
		cout<<"Pass "<<i<<":\n";
		for(int j=0;j<size-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			cout<<"For i="<<i<<" j="<<j<<" :";
			display();
		}
	}
}

void Sort::selection_sort()
{
	int min,temp;
	for(int i=0;i<size;i++)
	{
		min=i;
		for(int j=i;j<size;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

void Sort::insertion_sort()
{
	int hole,value;
	for(int i=1;i<size;i++)
	{
		hole=i;
		value=a[hole];
		while(hole>0 && a[hole-1]>a[hole])
		{
			a[hole]=a[hole-1];
			hole--;
			a[hole]=value;
		}
	}
}

int Sort::partition(int low,int high)
{
   	int pivot=a[high];
   	int i,j,temp;
   	i=low-1;
   	for(j=low;j<high;j++)
   	{
   		if(a[j]<=pivot)
   		{
   			i++;
   			temp=a[i];
   			a[i]=a[j];
   			a[j]=temp;
   		}
   	}
   	temp=a[i+1];
   	a[i+1]=a[high];
   	a[high]=temp;
   	return (i+1);
}

void Sort::quick_sort(int low,int high)
{
    if(low<high)
    {
    	int pi=partition(low,high);
    	quick_sort(low,pi-1);
    	quick_sort(pi+1,high);
    }
}

int main()
{
    int choice;
    do
    {
    	cout<<"\n1.Bubble sort";
    	cout<<"\n2.Selection sort";
    	cout<<"\n3.Insertion sort";
    	cout<<"\n4.Quick sort";
    	cout<<"\n5.Exit";
    	cout<<"\nEnter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    	  case 1: {
    		         Sort a;
    	             a.read();
    	             a.bubble_sort();
    	             break;
    	          }

    	  case 2: {
    		         Sort a;
    	             a.read();
    	             a.selection_sort();
    	             a.display();
    	             break;
    	          }

    	  case 3: {
    		         Sort a;
    	             a.read();
    	             a.insertion_sort();
    	             a.display();
    	             break;
    	          }

    	  case 4: {
    		          Sort a;
    		          a.read();
    		          a.quick_sort(0,a.size-1);
    		          a.display();
    		          break;
    	          }

    	  case 5: break;

    	  default : cout<<"\nEnter valid choice.";
    	}
    }while(choice!=5);
	return 0;
}
