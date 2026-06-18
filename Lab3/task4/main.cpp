#include <iostream>
#include <iomanip>   //！！！
using namespace std;

double getCircleArea(double radius);

int main() {
    double radius = 0;
    cout<<"Enter radius: ";
    cin>>radius;

    cout<<fixed<<setprecision(2)<<"Circle area: "<<getCircleArea(radius)<<endl;

    return 0;
}

double getCircleArea(double radius) {
    double area = 0;
    const double PI = 3.14159;

    area = PI * radius * radius;
    
    return area;
}