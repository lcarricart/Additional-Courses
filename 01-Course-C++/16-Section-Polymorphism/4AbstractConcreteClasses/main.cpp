#include <iostream>
#include <vector>

using namespace std;

/* Concrete classes are the ones I've been using all along. Abstract classes are used as parents and objects can't be created from them. They
contain at least one pure virtual function (recognized by "=0"). Conceptually a "shape" would be an abstract class, and "circle" a concrete
one.

If we don't override all the pure virtual functions in the Derived class, then this one is abstract as well.
*/

class Shape {
private:
    //attributes to all shapes.
public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    virtual ~Shape() {};
};

class Open_Shape: public Shape {
public:
    virtual ~Open_Shape() {};
};

class Closed_Shape: public Shape {
public:
    virtual ~Closed_Shape() {};
};

class Line: public Open_Shape {
public:
    virtual void draw() override {
        cout << "Drawing a line." << endl;
    }
    virtual void rotate() override {
        cout << "Rotating a line." << endl;
    }
    virtual ~Line() {};
};

class Circle: public Closed_Shape {
public:
    virtual void draw() override {
        cout << "Drawing a circle." << endl;
    }
    virtual void rotate() override {
        cout << "Rotating a circle." << endl;
    }
    virtual ~Circle() {};
};

class Square: public Closed_Shape {
public:
    virtual void draw() override {
        cout << "Drawing a square." << endl;
    }
    virtual void rotate() override {
        cout << "Rotating a square." << endl;
    }
    virtual ~Square() {};
};

void screen_refresh (const vector<Shape *> &shapes) {
    cout << "Refreshing." << endl;
    for (const auto p: shapes)
        p->draw();
};

int main()
{
	Circle c;
    c.draw(); 
    //Static bind.
    
    Shape *ptr = new Circle();
    ptr->draw();
    ptr->rotate();
    //Dynamic polymorphism.
    
    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    vector<Shape *> shapes{s1,s2,s3};
    screen_refresh(shapes);
    
    delete s1;
    delete s2;
    delete s3;
    
	return 0;
}
