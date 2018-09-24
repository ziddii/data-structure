//linked stack 

#include<iostream>
#include<stdio.h>



//use of std collection 
using namespace std;

//Error flags
enum Error_code {success , fail ,overflow ,underflow};


//skeleton for linked stack
template <class Type>  class Stack
{	
	private:
		//skeleton for node 
		typedef struct Node 
		{	
			Type data;
			Node *next;
			Node(const Type &entry, Node tail)
			{	
				data = entry;
				next=tail;
			};

		}Node;

		//To make notion of top element
		Node *top_node;
	public:
		Stack();
		~Stack();
		Error_code push(const Type  &item);		// to insert the element 
		Error_code pop();					// to delete the element
		bool empty()const;					// check whether stack is empty or not
		Error_code top()const;					// to see top element
};






//functions definition 

	//constructor
template<class Type> Stack<Type>:: Stack()
{
	top_node = NULL;	
};


	//destructor 
template<class Type> Stack<Type> :: ~Stack()
{
	while(!empty()) pop(); 			//stack is clear on closing
}




	//machanism for insertion 
template<class Type> Error_code Stack<Type>::push(const Type  &item)
{
	Node *new_node = new Node(item,top_node);	
	if (new_node == NULL)
	{
		 cout<<"\n\n\tUnable to allocate the new node Hence cannot push any element\n";
		
		 return overflow;
	}
	top_node = new_node;
	return success;
}




	//mechanism for delete
template<class Type> Error_code Stack<Type>:: pop()
{
	//check whether stack is empty or not
	if(top_node==NULL)
	{
		cout<<"\n\n\tStack is empty hence cannot to delete\n";
	
		return underflow;
	}
	
	Node *old_node;
	old_node = top_node;
	top_node=old_node ->next;
	delete old_node;
	return success;
	
}




	//mechanism for check whether is or not 
template<class Type> bool Stack<Type>::empty()const
{
	if(top_node==NULL)
	{	
		cout<<"\n\n\tstack is empty \n";
		return true;
	}
	else 
	{
		cout<<"\n\n\tstack is not empty\n";
		return false;
	}
}




	//mechanism for see top element
template<class Type> Error_code Stack<Type>:: top()const
{
	if (top_node == NULL)
	{
		cout<<"\n\n\tstack is empty \n";
		return fail;
	}
	else
	{
		cout<<"\n\n  data = "<<top->data; 		//showing data but not returning it , it  does not make sense ,
								// i know   but this code is just for fun ;)
		return success;
	}
}




//execution time
int main()
{	//DO WHATEVER YOU WANT TO DO just remember BE THE BEST

}



