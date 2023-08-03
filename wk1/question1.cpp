#include <iostream>
using std::cout;
using std::cin;
// using namespace std;

int main(){
    int a,b;
    cout << "Formula: ax + b = 0\n";

    cout << "please enter a and b : ";
    cin >> a >> b;

    cout << "x is: " << (float) -b / (float) a;
    return 0;
}