/*L-value's are those which have names and are addressable.
On int x {100}; x is an L-value and 100 is an R-value.
int y = x + 200; There (x + 200) is an R-value.
max(20,30) is an R-value because it returns a non adressable value.
 
int x{100}

int &l_ref = x;
l_ref = 10;

int &&r_ref = 200;
r_ref = 300;

int &&x_ref = x; Compiler error!
Trying to assing a non addressable value to an addressable one.
---------------------------------------

It's easy to visualize this example.

int x{100};
void func (int &num);
func(x);
func(200); Error!

---------------------------------------

The same can be restricted for r-values! Could be useful.

int x{100};
void func (int &&num);
func(200);
func(x); Error!

---------------------------------------

Overloading (no errors):

int x{100};

void func(int &num);
void func(int &&num);

func(x);
func(200);

*/