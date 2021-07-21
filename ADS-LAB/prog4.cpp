#include<iostream>
#include<conio.h>
#define max 5
using namespace std;
int a[max],n;
class heap
{
  public:heap();
	 void insert();
	 void maxheap(int a[ ],int n);
	 void heapsort(int a[ ],int n);
	 void display();
};
heap::heap()
{
 n=0;
  for(int i=0;i<max;i++)
  {
    a[i]=0;
   }
}
void heap::insert()
{
 int num;
 cout<<"Enter the elements:\n";
 while(n<max)
 {
  cin>>num;
  a[n]=num;
  n++;
  }
}

void heap::maxheap(int a[],int n)
{
 int i,j,f,temp;
 for(i=1;i<n;i++)
 {
  temp=a[i];
   j=i;
  f=(j-1)/2;
    while(a[f]<temp && j>0)
    {
      a[j]=a[f];
       j=f;
      f=(j-1)/2;
     }
   a[j]=temp;
  }
}
void heap::heapsort(int a[],int n)
{
 int i,temp;
   for(i=1;i<=n;i++)
  {
    temp=a[n-i];
    a[n-i]=a[0];
    a[0]=temp;
    maxheap(a,n-i);
   }
}


void heap::display()
{
   for(int i=0;i<n;i++)
   {
     cout<<a[i]<<"   ";
   }
}
int main()
{
 heap h;
 h.insert();
 cout<<"\n The elements are:\n";
 h.display();
 h.maxheap(a,n);
 cout<<"\n The maxheap elements are:\n";
 h.display();
 h.heapsort(a,n);
 cout<<"\n The sorted maxheap elements are:\n";
 h.display();
 return 0;
 }
