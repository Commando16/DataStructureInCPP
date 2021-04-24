#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;


/*

    Topic
    
      - array addressing

*/




int main(){    
    
    int arr[] = {20,30,45,10};
    
    // The name of array gives the base address if the array.
    // The following line will prove the above statement by printing 
    // a hexadecimal memory address.
    cout<< "The base address of the array is "<< arr << endl << endl;






    // accessing the value of array elements by index.
    // The value of array can be printed as bellow code.

    cout<<"Print values of elements using indices.";
    for(int i=0; i<4;i++){
        cout<<arr[i]<<" "<<endl;
    }

    cout<<endl;



    // accessing the value of array elements by address.
    // The value of array can also be printed as bellow code.
    
    cout<<"Print values of elements using addresses.";
    for(int i=0; i<4;i++){
        // * is used to fetch the value at any address. 
        // it is called dereference operator.
        cout<< *(arr+i)<<" "<<endl;
    }

    cout<<endl;


    // If you add a number in the base address of array the following formula 
    // is working under the hood.

    // (base address + i x (sizeof( datatype of array )) )
    // the above formula results in the next memory address
    // where the next value is stored.
    // once u get the address you can fetch the value by 
    // dereference operator ' * '

       return 0;
}