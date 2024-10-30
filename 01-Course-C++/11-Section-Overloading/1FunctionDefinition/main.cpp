#include <iostream>

//This program works without using prototypes because all the functions are carefully used.
//The problem would come if I would have defined the function below the main function, which should be the same.

//A return statement inmediately terminates a function. Even though we're able to
//have multiple return values in a function, it's not best practice.

using namespace std;

const double pi {3.14159};

double calc_area_circle(double radius) {
    return pi * radius * radius;
}

void area_circle() {
    double radius {};
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;
    cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

int main()
{    
    area_circle();
    
	return 0;
}
