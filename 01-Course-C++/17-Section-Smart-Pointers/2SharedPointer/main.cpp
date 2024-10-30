#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
private:
    int data;
public:
    Test(): data{0} {};
    Test(int data): data{data} {};
    ~Test() {};
};

void func(shared_ptr<Test> p) {
    cout << "Use count: " << p.use_count() << endl;
};

int main()
{
	shared_ptr<int> p1 {new int{100}};
    cout << "p1 use count: " << p1.use_count() << endl;
    
    shared_ptr<int> p2 {p1}; //shared ownership.
    cout << "p1 use count: " << p1.use_count() << endl;
    
    p1.reset(); //p1 use count is nulled out.
    cout << "p1 use count: " << p1.use_count() << endl;
    cout << "p2 use count: " << p2.use_count() << endl;
    
    cout << "\n=======================" << endl;
    shared_ptr<Test> ptr = make_shared<Test>(100);
    func(ptr);
    //Here the count is 2 because I have an extra copy in the temporal scope of the function.
    cout << "Use count: " << ptr.use_count() << endl;
    
    cout << "//" << endl;
    shared_ptr<Test> ptr1 = ptr;
    cout << "Use count: " << ptr.use_count() << endl;
    shared_ptr<Test> ptr2 = ptr;
    cout << "Use count: " << ptr.use_count() << endl;
    ptr.reset();
    cout << "Use count: " << ptr.use_count() << endl;
    
    /*
    This last part requires the folders of Account class, Checking_Account but still we're gonna analize this conceptually:
    
    shared_ptr<Account> acc1 = make_shared<Trust_Account>{"Larry", 1000, 3.1};
    shared_ptr<Account> acc2 = make_shared<Checking_Account>{"Moe", 5000};
    shared_ptr<Account> acc3 = make_shared<Savings_Account>{"Curly", 6000};
    
    vector<shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    
    //The difference with the unique pointers, is that here I'm allowed to use copy constructors and I don't need to create the object
    in the push_back, I can have them defined from before.
    
    for (const auto &acc:accounts) {
        cout << *acc << endl;
        cout << "Use count: " << acc.use_count() << endl;
    };
    //I think that for this case, the function should work if I avoid using the reference "&acc".    
    */
    
    
    /*Comparing this vector of shared_ptr with the last example of unique_ptr, this vector is sharing ownerships with other variables,
    whereas in the previous one the vector owns the information it contains (is kinda more restrictive and protected). */
	return 0;
}
