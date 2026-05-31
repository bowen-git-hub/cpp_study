#include <iostream>
using namespace std;

int main() {
    char ascii_a = 65;
    char a = 'A';
    cout<<"hello"<< endl;
    cout<<"size of int is "<< sizeof(int) <<" bypes\n";
    cout<<"w is "<< ascii_a << endl;
    cout<<"w is "<< a << endl;

    cout<<"size of l is "<< sizeof(111.1f) <<" bypes\n";

    cout<<"size of double is "<< sizeof(111.1) <<" bypes\n";//default double

    cout<<"size of long double is "<< sizeof(111.1l) <<" bypes\n";

    cout<<"size of long int is "<< sizeof(111l) <<" bypes\n";

    

    bool x = false; //true == 1
    cout<<"bool is "<< x << endl;


    int b = 0;
    cin >>b;
    cout<< b;

    return 0;
}
