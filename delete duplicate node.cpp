#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
		
	Node()
	{
	  data=0;
	  next=0;
	}
	Node(int data)
	{
		this->data=data;
		next=0;
	}
};

class LinkedList
{
   public:
   	
    Node *head, *tail;
	LinkedList()
	{
		head=0;
		tail=0;
	}
	
	void push(int data)
	{
		Node *nn= new Node(data);
		if(head==0)
		{
			head=tail=nn;
		}
		else
		{
		    tail->next=nn;
			tail=nn;
			tail->next=0;	
		}
    }
    
    void print()
    {
    	Node *iterator=head;
    	while(iterator!=0)
    	{
    		cout<<iterator->data<<" ";
    		iterator=iterator->next;
    	}
    }
    
    void delete_dup()
    {
    	Node *iterator=head, *prev, *del;
    	while(iterator!=0)
    	{
    		prev=iterator;
    		Node *temp=iterator->next;
    		while(temp->next!=0)
    		{
    			if(iterator->data==temp->data)
    			{
    				prev->next=temp->next;
    				del=temp;
    				delete del;
    				del=0;
    			}
    		    else
    			temp=temp->next;
    			prev=temp;
    		}
    		
    		iterator=iterator->next;
    	}
    }
};

int main()
{
	LinkedList LL;
	LL.push(1);
	LL.push(2);
	LL.push(2);
	LL.push(4);
	LL.push(2);
	LL.push(1);
	LL.push(4);
	
	LL.print();
	LL.delete_dup();
	LL.print();
}
