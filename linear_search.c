// linear search funcntion implemented on interger data

int LS(int arr[] , int x , int s)                  // where arr][] is integer array  stored  the data on which the search will be performed and  x is the integer element to be the search on the arr[] , int s is size of the array
{ 
  for(int i = 0 , i<=n ,i++)                      // i is being used as the index 
  {
      if(arr[i]==x)
       return i;                                  //return the index on succesfull found
      else
       return -1;                                 //return -1 as the notifer of unsuccesful search
  }
   
}                         
