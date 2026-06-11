#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    int x = 0;
    bool y= 0;
    cout<<"type is : "<<typeid(x * y).name() << endl;//发生了隐式类型转换，利用typeid().name工具查看类型
    return 0;
}

