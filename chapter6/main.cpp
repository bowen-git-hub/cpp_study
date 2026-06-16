#include "iostream"
using namespace std;

void swapValues(int &x, int &y);

int main() {
    int a = 5;
    int b = 10;

    cout << "before swap: a=" << a << ", b=" << b << endl;
    swapValues(a, b);
    cout << "after  swap: a=" << a << ", b=" << b << endl;

    return 0;
}


//default parameter value
double calc(double a, double b = 1.0){
    return a * b;
}

//function overloading
int max(int a, int b){
    return (a > b) ? a : b;
}

int max(int a, int b, int c){
    return max(max(a, b), c);
}

double max(double a, double b){
    return (a > b) ? a : b;
}

//pass by reference
void swapValues(int &x, int &y) {//&可以改变传入的值
    int temp = x;
    x = y;
    y = temp;
}