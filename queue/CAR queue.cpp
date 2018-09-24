//Circular array represetation of queue

#include<iostream>
#include<stdio.h>

//use of std collection 
using namespace std;


//error handling 
enum Error_code { success , fail , overflow , undeflow };

//global variable
const int maxElement = 15;



//queue class skeleton 
template<class Type > class Queue{
	private: 	
		Type element[maxElement];
		int front, rear;
	public:	
		Queue();
		Error_code push(const Type &item);		//insertion in circular array represented queue
		Error_code pop();				//deletion in circular array represented queue
		Error_code empty()const;			//check whether queue is empty or not
		
};



//constructor definition
template<class Type > Queue<Type> :: Queue()
{	
	front=rear;
	rear=0;
	
}




//function definition 
	//function for insertion in queue
template<class Type> Error_code Queue<Type> :: push(const Type &item)
{	
	Error_code outcome=success;
	
	//cycling front and rear i.e., range is 0-maxElement 
	front%=maxElement;
	rear%=maxElement;
	
	//check whether queue is full or not
	if(rear+1==front)
	{
		cout<<"\n\n		Queue is full, Hence uanble to insert a element \n";	
		outcome=fail;	
		return outcome;
	}

	//if queue is empty
	if(front==rear&&element[rear]==0)
	{	
		element[rear]=item;
		return outcome;
	}
	else
	{
		
		element[++rear] = item;
		return outcome;

	}
	
	

}


	//function for deletion in queue
template<class Type> Error_code Queue<Type>::pop()
{	
	Error_code outcome = success;

	
	//to check whether queue is empty or not 
	if (rear==front&&element[rear]==0)
	{	
		cout<<"\n\n		Queue is empty Hence cannot serve element\n";
		outcome=fail;
		return outcome; 
	
	}
	else if(rear==front && element!= 0)
	{
		element[front]=0;
		return outcome;
	}
	else
	{
		++front;
		return outcome;
	}
	
}

	//function to check Queue is empty or not 
template<class Type> Error_code Queue<Type>::empty()const
{	
	bool outcome = false;
		
	if(rear==front&&element[rear]==0)
	{
		outcome== true;
		cout<< "\n\n		Queue is empty\n	";
		return outcome;
	}
	
	else {return outcome;}
}		




// exection time

int main ()
{
	//execute whatever you want singing off
}
