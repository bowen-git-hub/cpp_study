#include <iostream>
using namespace std;


int findMax(int n1, int n2, int n3);

int main() {
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    cout<<"Enter three numbers: ";
    cin>>num1>>num2>>num3;
    cout<<"Maximum value: "<<findMax(num1, num2, num3)<<endl;
    
    return 0;
}

int findMax(int n1, int n2, int n3) {
    int temp = n1;
    if (n2 > temp) {
        temp = n2;
    }
    if (n3 > temp) {
        temp = n3;
    }
    
    return temp;
}