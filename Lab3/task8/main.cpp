#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long calculatePower(int base, int exp);
double getCircleArea(double radius);
bool isPrime(int n);

int main() {
    int selected  = 0;

    cout<<"Menu: "<<endl;
    cout<<"1. Power Calculation"<<endl;
    cout<<"2. Circle Area"<<endl;
    cout<<"3. Prime Check"<<endl;
    cout<<"Enter choice: ";
    cin>>selected;

    if (selected == 1) {
        int num = 0;
        cout<<"Enter number: ";
        cin>>num;

        cout<<"Square: "<<calculatePower(num,2)<<endl;
        cout<<"Cube: "<<calculatePower(num,3)<<endl;
    } else if (selected == 2) {
        double radius = 0;
        cout<<"Enter radius: ";
        cin>>radius;

        cout<<fixed<<setprecision(2)<<"Circle area: "<<getCircleArea(radius)<<endl;
    } else if (selected == 3) {
        int num = 0;
        cout<<"Enter number: ";
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
    } else cout<<"Invalid choice."<<endl;
    
    return 0;
}

long calculatePower(int base, int exp) {
    long result = 0;
    result = pow(base,exp);
    return result;
}

double getCircleArea(double radius) {
    double area = 0;
    const double PI = 3.14159;

    area = PI * radius * radius;
    
    return area;
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