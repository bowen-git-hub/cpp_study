#include <iostream>
#include <iomanip>
using namespace std;

double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);

int main() {
    int selected  = 0;
    double temperature = 0;
    double changed = 0;



    cout<<"Select conversion: "<<endl;
    cout<<"1. Celsius to Fahrenheit"<<endl;
    cout<<"2. Fahrenheit to Celsius"<<endl;
    cout<<"Enter choice: ";
    cin>>selected;

    cout<<"Enter temperature:";
    cin>>temperature;

    if (selected == 1) {
        cout<<fixed<<setprecision(2)<<"Temperature in Fahrenheit: "<<celsiusToFahrenheit(temperature)<<endl;
    } else if (selected == 2) {
        cout<<fixed<<setprecision(2)<<"Temperature in Celsius: "<<fahrenheitToCelsius(temperature)<<endl;
    }
    
    return 0;
}

double celsiusToFahrenheit(double celsius) {
    double fahrenheit = 0;
    fahrenheit = celsius * 180.0 / 100.0 + 32;

    return fahrenheit;
}
 
 
 
 
 
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = 0;
    celsius = (fahrenheit - 32) * 100.0 / 180.0;

    return celsius;

 }