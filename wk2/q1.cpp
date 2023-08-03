#include <iostream>
using namespace std;
#define SIZE 5

int min(int array[SIZE]){
    int minimum = array[0];
    for(int i = 0; i < SIZE; i++){
        if(minimum > array[i]){
            minimum = array[i];
        }
        else continue;
    }
    return minimum;
}

int main(){
    int arr[SIZE];
    
    for(int i = 0; i < SIZE; i++){
        cout << "please enter the numbers: ";
        cin >> arr[i];
    }

    cout << "minimum is " << min(arr);

    return 0;
}