//singly linked list 


#include<iostream>
#include<stdio.h>

//use of std collection
using namespace std;


//Error flags
enum Error_code { success, fail, overflow ,underflow};

//macro to give keyword START AND LAST For simplicity

#define START 1
#define LAST (-1)

//singly linked list class definition
template<class Type>class SList{
	private:
		typedef struct Node
		{
			Type data;
			Node *next;
			Node(const Type &entry, Node *tail)
			{
				data = entry;
				next = tail;
			};
		}Node;

		Node *position_node;
		Node *last_node;
		int num_of_element;
	public:
		SList();
		~SList();
		Error_code insert_at_pos(const int pos , Type &entry);	//insert node at position at pos
		Error_code delete_at_pos(const int pos);		//delete node at position at pos
		Error_code delete_at_data(const Type &entry);		//delete node at data entry
		Error_code insert_at_data(const Type &entry,const Type & Sentry);		//insert node at data entry
		bool empty()const;
		
};



//functions definition
	
	//constructor 
template<class Type> SList<Type>::SList()
{
	position_node = last_node;
	last_node = NULL;
	num_of_element=0;
}


	//destructor
template<class Type> SList<Type>::~SList()
{
	while(!empty()) delete_at_pos(LAST);
}

	
	//insert mechanism
template<class Type> Error_code SList<Type>::insert_at_pos(const int pos, Type &entry)
{

	if(pos>num_of_element||pos<-1)return fail;		//fail on accessing 
								//wrong position
	if(pos==0)
	{
			cout<<"\n\n\tUse Natural number for accounting for example * position 1 denotes for begining of the list\n";

			return fail;
		}
		
							
		if((pos==1)&&num_of_element=0)				//insert to begining of nodes
		{
			Node *new_node = new Node(entry,NULL);
			if(new_node== NULL)
			{
				cout<<"\n\n\tUnable to create new memory for new node  Unable to insert\n";
				return overflow;
			}
			
			last_node=new_node;			//last node is now fist node 
			position_node=last_node;
			++num_of_element;
		
			return success;
		}
		
		
		if(pos==num_of_element||pos==-1)
		{
			Node *new_node= new Node(entry,last_node);
			last_node=new_node;
			++num_of_element;
			return success;
		}
			
		
			
		//mechanism for normal case
		for(int i=1;i<=num_of_element-pos;i++)
		{
			position_node= position_node->next;
		}
		
		Node *new_node= new Node(entry, position_node->next);
		position_node->next=new_node;
		
		position_node=last_node;
		++num_of_element;
		return success;

	}


		//mechanism for delete at specific position
	template<class Type> Error_code SList<Type>::delete_at_pos(const int pos)
	{

		if(pos<=0||pos>num_of_element)
		{
			cout<<"\n\n\tList is counted in natural number i.e., 1 for begining of list\n";
			return fail;
		}
		
		//if list is empty

		if(last_node==NULL)	
		{
			cout<<"\n\n\tList is empty \n";
			return fail;
		}
		
		//deletion for last node

		if(pos==-1||pos==num_of_element)
		{
			Node *old_node = last_node;
			last_node=last_node->next;
			delete old_node;
			--num_of_element;
			return success;
			
		}
		
		//mechanism for deletion of normal position
		
		for(int i=1;i<num_of_element-pos;i++)
		{
			position_node=position_node->next;
		}
		Node *old_node=position_node->next;
		position_node->next=position_node->next->next;
		
		delete old_node;	
		--num_of_element;
		
		position_node=last_node;
		
		return success;
		
		
	}



	template<class Type> bool SList<Type>::empty()const
	{
		if(last_node==NULL)
		{
			cout<<"\n\n\tlist is empty\n";
			return true;
		}

		return false;
	}




	//mechanism for delete at data

	template<class Type> Error_code SList<Type>::delete_at_data(const Type &entry)
	{
		//checking for last node
		if(last_node->data==entry)
		{
			Node *old_node=last_node;
			last_node=last_node->next;
			delete old_node;
			--num_of_element;
			return success;
		}

		//this algo do not check the last element
		while(!position_node==NULL)
		{
			if(position_node->next->data==entry)	//it find occuring of entry
		break;

		position_node=position_node->next;	
	}
	
	Node *old_node=position_node->next;
	position_node->next=position_node->next->next;
	delete old_node;
	--num_of_element;
	position_node=last_node;
	return success;
	
}



//mechanism for insertion at specific data
template<class Type> Error_code SList<Type>::insert_at_data(const Type &entry,const Type & Sentry)
{
	if(last_node->data==Sentry)	
	{
		Node *new_node= new Node(entry,last_node->next);
		last_node->next=new_node;
		++num_of_element;
		return success;
	}
		
	while(position_node!=NULL)
	{	
		if(position_node->next->data==Sentry)
		break;
		
		position_node->next=position_node;
	}
	
	Node *new_node=  new Node(entry, position_node->next);
	position_node->next=new_node;
	++num_of_element;
	position_node=last_node;
	
	return success;
}

//execution time
	
int main()
{
	//Do whatever you want to do , just remember BE THE BEST
}
