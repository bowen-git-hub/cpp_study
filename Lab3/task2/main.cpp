#include <iostream>
#include <cmath>
using namespace std;

long calculatePower(int base, int exp);

int main() {
    int a = 0;
    cout<<"Enter a number: ";
    cin>>a;

    cout<<"Square: "<<calculatePower(a,2)<<endl;
    cout<<"Cube: "<<calculatePower(a,3)<<endl;
    return 0;
}


long calculatePower(int base, int exp) {
    long result = 0;
    result = pow(base,exp);
    return result;
}