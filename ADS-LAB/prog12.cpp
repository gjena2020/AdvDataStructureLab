#include<iostream>
#include<conio.h>
#include<string.h>


using namespace std;
class kmp
{
public:int f[];
            void failure(char p[ ]);
            int km(char t[ ],char p[ ],int m,int n);
};
void kmp::failure(char p[ ])
{
 int i,j,m,n;
 f[0]=0;
 j=0;
 i=1;
 while(i<n)
 {
  if(p[i]==p[j])
  {
   f[i]=j+1;
   i++;
   j++;
  }
  else
   if(j>0)
   j=f[j-1];
   else
   {
    f[i]=0;
    i++;
   }
  }
 }
 int kmp::km(char t[ ],char p[ ],int n,int m)
 {
  int i,j;
  failure(p);
  j=0;i=0;
  while(i<n)
  {
   if(t[i]==p[j])
   {
    if(j==m-1)
    {
     return(i-m+1);
    }
    i++;
    j++;
   }
   else
   if(j>0)
    j=f[j-1];
    else
    i++;
   }
   return(-1);
 }
 main()
 {
  kmp x;
  char t[20],p[20];
  int n,m,l;
  system("cls");
  cout<<"\n Enter the Text:\n";
  cin>>t;
  cout<<"\n Enter the Pattern:\n";
  cin>>p;
  n=strlen(t);
  m=strlen(p);
  l=x.km(t,p,n,m);
  if(l!=1)
  cout<<" Pattern is a substring of Text and its location is:"<<l;
  else
  cout<<" Pattern is not a substring of Text";
  getch();
  return 0;
}
