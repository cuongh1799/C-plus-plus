#include <iostream>
#include <string>
using namespace std;

int main(){
    int NumInput;
    cout << "Sample Input: ";
    cin >> NumInput;

    string ConvertNum = to_string(NumInput);

    cout << "Sample Output: ";

    for(int i = ConvertNum.length(); i >= 0 ; i--){
        cout << ConvertNum[i];
    }
    

    return 0;
}