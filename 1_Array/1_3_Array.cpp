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



    // pointer -> memory addresa ko store krne
    //            memory address are hexa decimal number

    // why we use datatype before ponters??

    // arr( baseaddress + size_of_data_type*i ) // 2 // 4+2(4) = 12 address ka data nikalna h // address calculate
    // int 4 byte;

    // 4  8  12  16 
    // 15 21 54  22


    //insert
    //int arr[10] = {1,8,3,6,9}; 
    //int size = 5;

    //int pos = 3;
    // int data = 95;

    // for( int i=size; i>=pos; i--)
    // {
    //     arr[i+1] = arr[i];
    // }

    // arr[pos]=data;
    // size++;
    // int temp2;
    // int temp = arr[pos];
    // arr[pos] = data;

    // for(int i=pos+1; i<size+1; i++)
    // {   // temp2 = arr[i];
    //     // arr[i] = temp;
    //     // temp = temp2;

    //     arr[i] = arr[i] + temp;
    //     temp = arr[i] - temp;
    //     arr[i] = arr[i] - temp;
        
    // }

    // for( int i=0; i<size; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }


    // for(int i=pos; i<size; i++)
    // {
    //     arr[i] = arr[i+1];
    // }

    // int array[] = {10, 20, 30};
    // cout << -2[array];
    


    return 0;
}