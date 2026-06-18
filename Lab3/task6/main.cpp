#include <iostream>
using namespace std;

bool isPrime(int n);

int main() {
    int num = 0;
    cout<<"Enter a number: ";
    cin>>num;

    if (num <= 1) {
        cout<<"Invalid input."<<endl;
        return 0;
    }

    if (isPrime(num)) {
        cout<<num<<" is not a prime number."<<endl;
    } else {
        cout<<num<<" is a prime number."<<endl;
    }
    
    return 0;
}

bool isPrime(int n) {
    bool result = 0;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            result = 1;
            return result;
        }
    }

    return result;
}