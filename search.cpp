//============================================================================
// Name        : search.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void fibonacci_search(int *arr,int size,int key)
{
    int f = size,a,b;
    int *fibo=new int[size];
    fibo[0]=0;
    fibo[1]=1;
    for(int i=2;i<size;i++)
    {
    	fibo[i]=fibo[i-1]+fibo[i-2];
    }
    b=fibo[f-2];
    a=fibo[f-3];
    int flag=0;
    int k=1;
    while(f>0 && (f-1)<size)
    {
    	cout<<"Pass:"<<k<<" f="<<f<<" a="<<a<<" b="<<b<<endl;
    	k++;
      	if(key<arr[f-1])
      	{
      		f=f-a;
      		a=b-a;
      		b=b-a;
      	}
      	else if(key>arr[f-1])
      	{
      		f=f+a;
      		b=b-a;
      		a=a-b;
      	}
      	else if(key==arr[f-1])
      	{
      		flag=1;
      		cout<<"\nElement found at position "<<f;
      		break;
      	}
    }
    if(flag==0)
    {
    	cout<<"\nElement not present in list.";
    }
}

void binary_search(int *a,int size,int key)
{
	int u=size-1;
	int l=0,m;
	while(l!=u)
	{
		m=(l+u)/2;
		if(key<m)
		{
			u=m-1;
		}
		else if(key>m)
		{
			l=m+1;
		}
	}
	if(a[m]==key)
	{
		cout<<"\nElement found at position "<<l;
	}
	else
	{
		cout<<"\nElement not present in list.";
	}
}
int main()
{
	int n;
	cout<<"\nEnter no. of elements:";
	cin>>n;
    int *a=new int[n];
    cout<<"\nEnter elements:";
    for(int i=0;i<n;i++)
    {
    	cout<<"\nElement "<<i+1<<":";
    	cin>>a[i];
    }
    int search;
    cout<<"\nEnter no to be searched:";
    cin>>search;
    //fibonacci_search(a,n,search);
    binary_search(a,n,search);
	return 0;
}

/*test case
 * 65
 * arr=10 20 30 40 50 60 70
 * 1-
 * f=7 65<70
 * f=4
 * b=3
 * a=2
 * 2-
 * f=4 65>40
 * f=6
 * b=1
 * a=1
 * 3-
 * f=6 65>60
 * f=7
 * b=0
 * a=1
 * not present
 */
