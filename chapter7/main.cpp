#include "scorc.h"
#include <iostream>
using namespace std;

int main() {
    Score score;
    cout << "The score is: " << score.getscore() << endl;
    score.setscore(-5.12);
    cout << "The score is: " << score.getscore() << endl;
    cout << "the end of the program" << endl;
}