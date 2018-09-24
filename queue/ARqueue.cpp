//Queue -  array representation 


//including header file 
#include<iostream>
#include<stdio.h>

using namespace std;

//global variable 

const int maxElement = 15;


//Error flags

enum Error_code { success , fail , overflow , underflow };

//Queue class

template<class Type> class  Queue{
	
	private:
		int front,rear;
		Type element[maxElement];
	

	public:
		Queue();
		Error_code append(const Type &x);
		bool empty()const;	
		Error_code serve();
	
};

//constructor definition 

template<class Type> Queue <Type> :: Queue ()
{
	front =0 ;
	front=rear;
}


//function definition
	//append  : function to add element in queue

template<class Type> Error_code Queue<Type> :: append (const  Type &x)
{
	Error_code outcome = success;

	if(rear >= maxElement )
		outcome = overflow;
	else 
		element[rear++] = x;

	return outcome;


}

	//serve  : function to serve (delete element at rear side )  in queue
template<class Type> Error_code Queue<Type> :: serve()
{
	Error_code outcome=success;

	if(rear = 0)
		outcome = underflow;
	else
		cout << '\n' << "  "<<element[front++] << " is served" ; 
		      	

	return overflow;

}


	// empty : whether queue is empty or not 
template<class Type> bool Queue<Type> :: empty()const
{
	bool outcome = false;
	if (front == rear )
		outcome = true;

	return outcome;
}
