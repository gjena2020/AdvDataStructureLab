#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#define size 20
#define infinity 32767
using namespace std;
class mst
{
 private: int g[size][size],nodes;
 public: mst();
             void prim();
             void getdata();
};
mst::mst()
{
 for(int i=0;i<size;i++)
  for(int j=0;j<size;j++)
   g[i][j]=g[j][i]=0;
}
void mst::prim()
{
 int i,j,k,select[size];
 int v1,v2,mindist=0,total=0;
 for(i=0;i<nodes;i++)
  select[i]=0;
  cout<<"\n Minimum Spanning Tree is:\n";
  select[0]=1;
  for(k=1;k<nodes;k++)
  {
   mindist=infinity;
   for(i=0;i<nodes;i++)
   {
    for(j=0;j<nodes;j++)
    {
     if(g[i][j] && ((select[i]&&!select[j])||(!select[i]&&select[j])))
     {
      if(g[i][j]<mindist)
      {
       mindist=g[i][j];
       v1=i;
       v2=j;
      }
     }
    }
   }
   cout<<"\n Edges are:"<<v1<<" "<<v2<<"and weight is:"<<mindist<<"\n";
  select[v1]=select[v2]=1;
  total=total+mindist;
 }
 cout<<"\n Total Path lenth cost is:"<<total;
}
void mst::getdata()
{
 int v1,v2,length,edges;
 cout<<"\n Enter no.of nodes in the graph:";
 cin>>nodes;
 cout<<"\n Enter no.of edges in the graph:";
 cin>>edges;
 cout<<"\n Enter Edges and Weights\n";
 for(int i=0;i<edges;i++)
 {
  cout<<"\n Enter Edge connections:\n";
  cin>>v1>>v2;
  cout<<"\n Enter the Edge Weights:\n";
  cin>>length;
  g[v1][v2]=g[v2][v1]=length;
 }
}
int main()
{
 mst m;
 cout<<"\n PRIM'S ALGORITHM \n";
 m.getdata();
 cout<<"\n\t";
m.prim();
 return 0;
}
