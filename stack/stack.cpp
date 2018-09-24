//stack


//header files



#include<stdio.h>
#include<iostream>

using namespace std;


//global variable
const int maxElement =15;

enum Error_code {success , fail , underflow , overflow};

//stack class definition

template<class Type> class Stack {
	
	public :
		Stack();
		bool empty()const ;
		Error_code pop();
		Error_code top(Type &item)const;
		Error_code push(const Type &item);
	private:
		int count;
		Type entry [maxElement];
};



//stack constructor definition

template<class Type> Stack<Type>:: Stack()
{
	count = 0;

}




//stack class member function definiton

	//push function definition 
template<class Type> Error_code Stack<Type>::push(const Type &item)
{	
	
	Error_code outcome =success;
	
	if(count >= maxElement)
	{
		outcome=overflow;
		
	}
	
	else 
		entry[count++] = item;
		
		
	return outcome;	
	
}
 
 
 
	//pop function definition
template<class Type> Error_code Stack<Type>::pop()
{
	Error_code outcome = success;
	
	if(count == 0)
		outcome = underflow;
	else 
		--count;
	
	return outcome;
		 


}


	//top function definition
template<class Type> Error_code Stack<Type> :: top (Type &item)const
{
	Error_code outcome = success;
	
	if(count == 0)
		outcome = underflow;
	
	else 
		{ item = entry[count-1];
	      	  cout<< item;
	       	}
		
	return outcome;
			

}

	//empty function definition
template<class Type> bool Stack<Type> :: empty()const
{
	bool outcome = true;
	if(count > 0)
		outcome = false;
	
	return outcome;	


}


