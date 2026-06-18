#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float num = 0;

    cout<<"Enter a number: ";
    cin>>num;

    cout<<fixed<<setprecision(2)<<"Floor: "<<floor(num)<<endl;
    cout<<fixed<<setprecision(2)<<"Ceil: "<<ceil(num)<<endl;
    cout<<fixed<<setprecision(2)<<"Absolute value: "<<abs(num)<<endl;
    cout<<fixed<<setprecision(2)<<"Log10: "<<log10(num)<<endl;

    return 0;
}