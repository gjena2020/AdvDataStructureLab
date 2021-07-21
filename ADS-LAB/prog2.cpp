# include <iostream>
# include <stdlib.h>
# include <conio.h>
using namespace std;
struct node
{
   int element;
   node *left;
   node *right;
   int height;
};
typedef struct node *nodeptr;

class bstree
{
   public:
	void insert(int,nodeptr &);
	void del(int, nodeptr &);
	int deletemin(nodeptr &);
	void find(int,nodeptr &);
	void preorder(nodeptr);
	void inorder(nodeptr);
	void postorder(nodeptr);
	int bsheight(nodeptr);
	nodeptr srl(nodeptr &);
	nodeptr drl(nodeptr &);
	nodeptr srr(nodeptr &);
	nodeptr drr(nodeptr &);
};
//		Inserting a node
void bstree::insert(int x,nodeptr &p)
{
   if (p == NULL)
   {
	p = new node;
	p->element = x;
	p->left=NULL;
	p->right = NULL;
	p->height=0;
	if (p==NULL)
		cout<<"\n Out of Space \n";
   }
   else
   {
	if (x<p->element)
	{
	   insert(x,p->left);
	   if ((bsheight(p->left) - bsheight(p->right))==2)
	   {
	      if (x < p->left->element)
		p=srl(p);
	      else
		p = drl(p);
	   }
	}
	else if (x>p->element)
	{
	      insert(x,p->right);
	      if ((bsheight(p->right) - bsheight(p->left))==2)
	      {
		if (x > p->right->element)
			p=srr(p);
		else
			p = drr(p);
	     }
	}
	else
		cout<<"\n Element Exists \n";
	}
	int m,n,d;
	m=bsheight(p->left);
	n=bsheight(p->right);
	d=max(m,n);
	p->height = d + 1;

}

//		Finding an element
void bstree::find(int x,nodeptr &p)
{
	if (p==NULL)
	   cout<<"\n Element not found \n";
	else
	if (x < p->element)
	   find(x,p->left);
	else
	if (x>p->element)
	   find(x,p->right);
	else
	   cout<<" \n Element found ! \n";
}
//		Deleting a node
void bstree::del(int x,nodeptr &p)
{
	nodeptr d;
	if (p==NULL)
	   cout<<" \n Element not found \n";
	else if ( x < p->element)
	   del(x,p->left);
	else if (x > p->element)
	   del(x,p->right);
	else if ((p->left == NULL) && (p->right == NULL))
	{
	   d=p;
	   free(d);
	   p=NULL;
	   cout<<"\n Element deleted !\n";
	}
	else if (p->left == NULL)
	{
	  d=p;
	  free(d);
	  p=p->right;
	  cout<<"\n Element deleted !\n";
	}
	else if (p->right == NULL)
	{
	  d=p;
	  p=p->left;
	  free(d);
	  cout<<"\nElement deleted !\n";
	}
	else
	   p->element = deletemin(p->right);
}
int bstree::deletemin(nodeptr &p)
{
	int c;
	cout<<"inside deltemin";
	if (p->left == NULL)
	{
	  c=p->element;
	  p=p->right;
	  return c;
	}
	else
	{
	  c=deletemin(p->left);
	  return c;
	}
}

//		preorder Printing
void bstree::preorder(nodeptr p)
{
	if (p!=NULL)
	{
	  cout<<p->element<<"-->";
	  preorder(p->left);
	  preorder(p->right);
	}
}

//		Inorder Printing
void bstree::inorder(nodeptr p)
{
	if (p!=NULL)
	{
	   inorder(p->left);
	   cout<<p->element<<"-->";
	   inorder(p->right);
        }
}

//		PostOrder Printing
void bstree::postorder(nodeptr p)
{
        if (p!=NULL)
        {
	   postorder(p->left);
	   postorder(p->right);
	   cout<<p->element<<"-->";
	}
}
int bstree::bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
		return -1;
	else
	{
		t = p->height;
		return t;
	}
}
nodeptr bstree:: srl(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(bsheight(p2->left),p1->height) + 1;
	return p2;
}
nodeptr bstree:: srr(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = max(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = max(p1->height,bsheight(p2->right)) + 1;
	return p2;
}
nodeptr bstree:: drl(nodeptr &p1)
{
	p1->left=srr(p1->left);
	return srl(p1);
}
nodeptr bstree::drr(nodeptr &p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}

int main()
{

	nodeptr root,root1,min,max;//,flag;
	int a,choice,findele,delele,leftele,rightele,flag;
	char ch='y';
	bstree bst;
	//system("clear");
	root = NULL;
	root1=NULL;
	cout<<"AVL Tree\n";
	cout<<"========";
	do
	{
		cout<<"\n 1.insert \n 2.find \n 3.del \n 4.preorder \n 5.inorder \n 6.postorder \n 7.height \n";
		cout<<"Enter the choice:\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"New node's value ?";
			cin>>a;
			bst.insert(a,root);
			break;
		case 2:
			cout<<"Search node : ";
			cin>>findele;
			if (root != NULL)
				bst.find(findele,root);
			break;
		case 3:
			cout<<"Delete Node ?";
			cin>>delele;
			bst.del(delele,root);
			bst.inorder(root);
			break;
		case 4:
			cout<<" Preorder Printing... :\t";
			bst.preorder(root);
			break;
		case 5:
            			cout<<"Inorder Printing.... :\t";
          			 bst.inorder(root);
            			break;

		case 6:
            			cout<<"Postorder Printing... :\t";
            			bst.postorder(root);
            			break;
		case 7:
			cout<<"Height and Depth is...:\t ";
			cout<<bst.bsheight(root);
			break;
		}
		cout<<"\n Do u want to continue (y/n) ?";
		cin>>ch;
	}while(ch=='y');
return 0;
}
