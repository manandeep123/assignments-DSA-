//string length,concatenation,copy,compare,reverse
#include<iostream>
using namespace std;
#include<cstring>
   int i;
  int str_length(string s)
  { 
    int count=0;
    for(i=0;s[i]!='\0';i++)
    {
     count++;
    }
    return count;
  }
  
  void str_cat(string &s1,string s2)
  {
    int j=0,k=0;
    string temp=s1+s2;
   for(i=0;s1[j]!='\0'||s2[k]!='\0';i++)
   {
     if(s1[j]!='\0')
      {
      temp[i]=s1[j];
      j++;
      }
     else
      {
       temp[i]=s2[k];
       k++;
      }   
   }
   s1=temp;
  }
  
  void str_cpy(string &s1,string s2)
  { 
    /*for(i=0;s2[i]!='\0';i++)
    {
     s1[i]=s2[i];
    }
    s1[i]='\0';*/
    s1=s2;
  }
  
  void str_cmp(string s1,string s2)
  {
    int a=0;
    int s1_length=str_length(s1);
    int s2_length=str_length(s2);
    
      for(i=0; s1[i]!='\0'||s2[i]!='\0' ;i++)
      {
        a=a+s1[i]-s2[i];
      }
      if(a>0)
      {
       cout<<"\n"<<s1<<" is greater than "<<s2<<endl;
      } 
      else if(a==0)
      {
       cout<<"\n"<<s1<<" is equal to "<<s2<<endl;
      }
      else
      {
       cout<<"\n"<<s2<<" is greater than "<<s1<<endl;
      }
  }
  
  void str_reverse(string &s)
  {
    string temp=s;
    int j=0;
    for(i=str_length(s);i>=0;--i)
    {
      temp[j]=s[i-1];
      j++;
    }
    temp[j+1]='\0';
   s=temp; 
  }
  
int main()
{
 int length;
 char choice;
 string str1,str2;
 do
 {
  cout<<"\nEnter your choice of string operation:";
  cout<<"\nFor calculating string length type: 1";
  cout<<"\nFor performing string concatenation type: 2";
  cout<<"\nFor performing string copy type: 3";
  cout<<"\nFor performing string compare type: 4";
  cout<<"\nFor performing string reverse type: 5";
  cout<<"\nTo Exit type: E";
  cout<<"\nEnter your choice:";
  cin>>choice;
  switch(choice)
  {
   case '1':  {
               cout<<"\nEnter string:";
               cin>>str1;
               length=str_length(str1);
               cout<<"Length of string "<<str1<<" is:"<<length<<endl;
              break;
              }
   
   case '2':  {
               cout<<"\nEnter string s1:";
               cin>>str1;
               cout<<"\nEnter string s2:";
               cin>>str2;
               cout<<"\nBefore string concatenation:";
               cout<<"\ns1="<<str1;
               cout<<"\ns2="<<str2;
               str_cat(str1,str2);
               cout<<"\nAfter string concatenation:";
               cout<<"\ns1="<<str1;
               cout<<"\ns2="<<str2;
               break;   
              }
   
   case '3':  {
               cout<<"\nEnter string s1:";
               cin>>str1;
               cout<<"\nEnter string s2:";
               cin>>str2;
               cout<<"\nBefore string copy:";
               cout<<"\ns1="<<str1;
               cout<<"\ns2="<<str2;
               str_cpy(str1,str2);
               cout<<"\nAfter string copy:";
               cout<<"\ns1="<<str1;
               cout<<"\ns2="<<str2;
               break;
              }
   
   case '4':  {
               cout<<"\nEnter string s1:";
               cin>>str1;
               cout<<"\nEnter string s2:";
               cin>>str2;
               str_cmp(str1,str2);
               break;
              } 
   
   case '5':  {
               cout<<"\nEnter string s:";
               cin>>str1;
               cout<<"\nBefore string reverse:\ns="<<str1;
               str_reverse(str1);
               cout<<"\nAfter string reverse:\ns="<<str1;
               break;
              }
              
   case 'E':  {break;}
              
   default:   {
               cout<<"\nEnter valid choice"<<endl;
              }
              
  }
  
 }while(choice!='E');
 return 0;
}























