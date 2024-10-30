// Section 17
// Challenge 1
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes

unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>> &vec, int num);
void display(const vector<shared_ptr<Test>>&vec);
//I use a const reference in the display because I wanna be efficient and not copy that vector around, just use its values.

unique_ptr<vector<shared_ptr<Test>>> make() {
//Definition 'auto make() {}' also works, as it realizes Im returning that pointer.
    return make_unique<vector<shared_ptr<Test>>>();    
};

void fill(vector<shared_ptr<Test>> &vec, int num) {
    int temp;
    for (int i=0; i<num; i++) {
        cout << "Enter data point [" << i+1 << "] : ";
        cin >> temp;
        vec.push_back(make_shared<Test>(temp));
        //If I'd use the same variable for the whole vector, once I delete one, all of them are deleted. Using make_shared all are different.
        //Using 'vec.at(i) = make_shared<Test>(temp)' the compiler never changes the lenght of the vector, it just runs out of scope.
    };
};

void display(const vector<shared_ptr<Test>>&vec) {
    cout << "Displaying vector data" << "\n====================" << endl;
    for (const auto &v:vec)
        cout << v->get_data() << endl;
        //Somehow I need to dereference this addresses. The way to do it is with the get_data() method. Damn it.
    cout << "====================" << endl;
};

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}