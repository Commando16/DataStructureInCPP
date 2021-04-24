#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;


/* 

    Topic
    
      - array declaration and Initialisation
      
*/




int main(){

    // This is a way to declare and initialise the array and its elements.
    int arr[4];     // declaration of the integer variable of size 4

    arr[0] = 45;    // first index of array is initialised here
    arr[1] = 10;
    arr[2] = 87;
    arr[3] = 56;

    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;





    // This is another way to declare and initialise the array and its elements.
    // Here the arr2 is declared and its values are initialized in same variable.
    int arr2[] = {20,30,45,10};
    cout<<arr2[0]<<" "<<arr2[1]<<" "<<arr2[2]<<" "<<arr2[3]<<endl; 
    
    
    return 0;
}