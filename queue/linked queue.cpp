//linked queue


#include<iostream>
#include<stdio.h>


//use of std collection
using namespace std;


//error flags 
enum Error_code { success , fail, overflow , underflow };


//skeleton for queue
template<class Type> class Queue{
	private:
		typedef struct Node
		{
			Type data;
			Node *next;
			Node *previous;
			Node(const Type &item, Node * tail)
			{
				data = item;
				previous = tail;
				next= NULL;
			}
		}Node;
		
		Node *front, *rear;
		
	public:
		Queue();
		~Queue();
		Error_code append(const Type &item);
		Error_code serve();
		bool empty()const;
};



//functions definition 

	//constructor definition
template<class Type> Queue<Type>::Queue()
{
	front=rear;
	rear=NULL;
}

	//destructor definition
template<class Type> Queue<Type>::~Queue()
{
	while(!empty())
	serve();					//Queue is clear on closing hence removing
						//removing all dynamically allocated memory
}



	//mechanism for insertion 
template<class Type> Error_code Queue<Type>::append(const Type &item)
{
	//check whether front and rear  pointer is pointing to same address and having NULL or not 
	if(front==rear && rear == NULL)
	{	
		Node *new_node = new Node (item , rear);
		if(new_node == NULL)
		{
			cout<<"\n\n\tUnable to allocate new memory  hence  cannot insert  new element\n";
			return underflow;
		}
		rear = new_node;
		front = new_node;		//when queue is empty and front and rear are pointing to NULL then both  rear and 
						//front will point to first created node 
		
		return success;
	}
	else
	{
		Node *new_node = new Node (item ,rear);
		rear = new_node;
		rear->next = new_node;		
		rear = new_node;
		
		return success;
	}

}



	//mechanism for serve in queue
template<class Type> Error_code Queue<Type> :: serve()
{
		if(front==rear && rear== NULL)
		{	
			cout<<"\n\n\tQueue is empty hence cannot serve element \n";
			return underflow;
		}
		else 
		{
			if(rear==front && rear!= NULL)
			{
				Node *old_node;
				old_node = front;
				front=NULL;
				rear=front;	
				delete old_node;
				return success;
			}
			
			Node *old_node;
			old_node=front;
			front=front->next;
			delete old_node;
			return success;
		}
		
}




	//check whether queue is empty or not 

template<class Type > bool Queue<Type>:: empty()const
{
	if(front==rear && rear== NULL)
	{
		cout <<"\n\n\t Queue is empty \n";
		return true;
	}
	
	cout<< "\n\n\t Queue is not empty \n";
	return false;
}


//execution time

int main()
{
		//Do whatever you want to do  , just remember 	BE THE BEST 
}
