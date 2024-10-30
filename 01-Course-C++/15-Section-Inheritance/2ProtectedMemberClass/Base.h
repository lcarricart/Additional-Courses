#ifndef BASE_H
#define BASE_H

class Base
{
    //friends of Base have access to all.
public:
    int a{0};
    void display(){std::cout << a << ", " << b << ", " << c << endl;} //member methods have access to all.
    Base();
    ~Base();

protected:
    int b{0};
private:
    int c{0};
};

#endif // BASE_H
