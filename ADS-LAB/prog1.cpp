#include<iostream>
#include<conio.h>
#include<process.h>
#include<math.h>
#define max 10
using namespace std;
class hash
{
 private:
	 struct dct
	 {
	  int k;
	  int val;
	 }a[max];
 public:
	 void init();
	 void insert(int,int,int);
	 int divmethod(int);
	 int mulmethod(int);
	 void size();
	 void display();
};
void ::hash::init()
{
 for(int i=0;i<max;i++)
 {
  a[i].k= -1;
  a[i].val= -1;
 }
}
void ::hash::insert(int index,int key,int value)
{
 int i,count=0,flag=0;
 if(a[index].k== -1)
 {
  a[index].k=key;
  a[index].val=value;
 }
 else
 {
  i=0;
  while(i<max)
  {
   if(a[i].k!= -1)
    count++;
   i++;
  }
  if(count==max)
  {
   cout<<"\n Hash table is full";
  }
  for(i=index+1;i<max;i++)
  if(a[i].k== -1)
  {
   a[i].k=key;
   a[i].val=value;
   flag=1;
   break;
  }
for(i=0;i<index && flag==0;i++)
 if(a[i].k== -1)
  {
   a[i].k=key;
   a[i].val=value;
   flag=1;
   break;
  }
 }
}

int ::hash::divmethod(int num)
{
 int record;
 record=num%10;
 return record;
}
int ::hash::mulmethod(int num)
{
 int record;
 int p=1;
 double a=0.6180;
 record=floor(num*p*a);
 return record;
}
void ::hash::size()
{
 int i,len=0;
 for(i=0;i<max;i++)
 {
   if(a[i].k!= -1)
       len++;
 }
 cout<<"\n The Size of the HashTable is:"<<len;
}
void ::hash::display()
{
 int i;
 cout<<"\n The HashTable is....\n";
 cout<<"\n......";
 for(i=0;i<max;i++)
 {
  cout<<"\n"<<i<<  "  "<<a[i].k<<  "  "<<a[i].val;
 }
 cout<<"\n....";
}
int main()
{
 int index,key,value,choice;
 ::hash h;
 cout<<"\n Static Hashing (Use Linear probing for collision resolution):";
cout<<"\n ==========================================\n";
 h.init();
 while(1)
 {
  cout<<"\n 1.insertion(divmethod) \n 2.insertion(mulmethod) \n 3.size \n 4.display \n 5.exit";
  cout<<"\n Enter your choice:";
  cin>>choice;
  switch(choice)
  {
   case 1:cout<<"\n Enter the key:";
	  cin>>key;
	  cout<<"\n Enter the value:";
	  cin>>value;
	  index=h.divmethod(value);
	  h.insert(index,key,value);
	  break;
    case 2:cout<<"\n Enter the key:";
	  cin>>key;
	  cout<<"\n Enter the value:";
	  cin>>value;
	  index=h.mulmethod(key);
	  h.insert(index,key,value);
	  break;
    case 3:h.size();
	   break;
    case 4:h.display();
	   break;
    case 5:exit(1);
   }
  }
  return 0;
}
