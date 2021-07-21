#include<iostream>
#include<conio.h>
using namespace std;
int cost[10][10],i,j,k,n,m,v,top,stk[10],visit[10],visited[10];
int main()
{
 cout<<"Enter no.of vertices:\n";
 cin>>n;
 cout<<"Enter no.of edges:\n";
 cin>>m;
 cout<<"Edge connections:\n";
 for(k=1;k<=m;k++)
 {
  cin>>i>>j;
  cost[i][j]=1;
  cost[j][i]=1;
 }
 cout<<"Enter initial vertex:\n";
 cin>>v;
 cout<<"\n Visited vertices:\n";
 cout<<v<<"  ";
 visited[v]=1;
 k=1;

 while(k<n)
 {
  for(j=n;j>=1;j--)
  {
   if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
   {
    visit[j]=1;
    stk[top++]=j;
   }
  }
  v=stk[--top];
  cout<<v<<"  ";
  k++;
  visit[v]=0;
  visited[v]=1;
 }
}
