#include <iostream>

using namespace std;


class Circle {
    private:
        double radius;
    public:
        Circle()
        :radius(5.0)
        {
            if(radius < 0){
                cout << "Radius cannot be negative" << endl;
            }
            cout << "Circle constructor called" << endl;
        };
        ~Circle(){
            cout << "Circle destructor called" << endl;
        };
        double getradius() const;
        void setradius(double value);
};

int main() {
    Circle circle;
    cout << "The radius of the circle is: " << circle.getradius() << endl;
    circle.setradius(-5.12);
    cout << "The radius of the circle is: " << circle.getradius() << endl;
    cout << "the end of the program" << endl;
}





double Circle::getradius() const {
    return radius;
}

void Circle::setradius(double value) {
    radius = value;
}