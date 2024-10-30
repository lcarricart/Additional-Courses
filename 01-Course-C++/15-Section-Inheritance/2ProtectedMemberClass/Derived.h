#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"

class Derived: public Base
{
public:
    Derived();
    ~Derived();
    void access_base_members() {
        a = 100; //This is possible to assign.
        b = 200; //This is also possible, cause this is a member function.
        //c = 300; //Not possible.
    }

};

#endif // DERIVED_H
