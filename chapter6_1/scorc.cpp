#include "scorc.h"
#include <iostream>
using namespace std;
Score::Score()
:score(0)
{
    if(score < 0){
        cout << "Score cannot be negative" << endl;
    }
    cout << "Score constructor called" << endl;
}

Score::~Score()
{
    cout << "Score destructor called" << endl;
}

double Score::getscore() const {
    return score;
}

void Score::setscore(double value) {
    score = value;
}
