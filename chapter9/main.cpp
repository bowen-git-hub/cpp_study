#include "iostream";
#include <ostream>
#include <algorithm>
using namespace std;

int main(){
    int a = 1;
    int* b = &a;
    int& rA = a;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<b<<endl;
    cout<<&rA<<endl;//ra和a是一个memory location
    rA = 20;
    cout<<a<<endl;//相当于使用a





    return 0;
}