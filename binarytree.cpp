#include<iostream>
using namespace std;

class Node 
{
	public:	
	int data;
	Node *right, *left;
	Node (int val)
	{data=val;right=NULL; left=NULL;}
};

class Btree
{
	Node *root;
	public:
	
	Btree()
	{root=NULL;}
	void insert(int value);
	void inserthelp(Node *curr, int value);
	void display();void displayhelp(Node *curr,int space);
	Node *search(int val);
};

void Btree::insert(int value)
{
	inserthelp(root,value);
}

void Btree::inserthelp(Node *curr,int value)
{
	if(root==NULL)
	root= new Node(value);
	
	else if(value<curr->data)
	{
		if(curr->left==NULL)
		curr->left=new Node(value);
		
		else	
		inserthelp(curr->left,value);
	}
	
	else if(value>curr->data)
	{
		if(curr->right==NULL)
		curr->right=new Node(value);
		
		else	
		inserthelp(curr->right,value);
	}

	else
	return;
}

void Btree::display()
{
	displayhelp(root,0);
}
void Btree::displayhelp(Node *curr , int space)
{
	if(curr->right!=NULL)
	{displayhelp(curr->right,space+1);}

	for(int i=space; i>0;i--)
	cout<<"   ";
	
	cout<<curr->data<<"\n";	
	
	if(curr->left!=NULL)
	{displayhelp(curr->left,space+1);}
}	

Node *Btree::search(int val)
{
	Node *ptr=root;	
	while(ptr!=NULL)
	{
		if(ptr->data==val)
		return ptr;
		
		else if(ptr->data > val)
		ptr=ptr->left;
		
		else
		ptr=ptr->right;
	 }
	return ptr;
}

int main()
{
	Btree b;
	b.insert(10);b.insert(14);b.insert(12);b.insert(16);b.insert(6);b.insert(8);b.insert(4);
	b.display();
	
	if(b.search(12)!=NULL)
	cout<<"Found"<<endl;
	
	return 0;
}














