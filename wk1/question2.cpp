#include <iostream>
using namespace std;

int main(){
    int array[5];

    for(int i = 0; i < 5; i++){
        if(i == 0){
            cout << "please enter 1st number: ";
        }
        else if(i == 1){
            cout << "please enter 2nd number: ";
        }
        else if(i == 2){
            cout << "please enter 3rd number: ";
        }
        else{
            cout << "please enter " << i + 1 << "th number: ";
        }
        cin >> array[i];
    }

    int tmp = array[0];
    for(int i = 0; i < 5; i++){
        if(tmp < array[i]){
            tmp = array[i];
        }
        else continue;
    }

    int sum = 0;
    for(int i = 0; i < 5; i++){
        sum += array[i];
    }    

    cout << "Highest number is " << tmp << "\n";
    cout << "Average number is " << (float) sum/5;

    return 0;
}