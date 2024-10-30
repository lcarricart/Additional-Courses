#include <iostream>

using namespace std;

/*int *largest_int(int *int_ptr1, int *int_ptr2);

int main()
{
	int a{100}, b{200};
    int *largest_ptr{nullptr};
    
    largest_ptr = largest_int(&a, &b);
    cout << *largest_ptr << endl;
    
	return 0;
}

int *largest_int(int *int_ptr1, int *int_ptr2) {
    if (*int_ptr1 > *int_ptr2)
        return int_ptr1;
    else
        return int_ptr2;
}*/

//Let's do it more complicated.

int *create_array(size_t size, int init_value = 0) {
    int *new_storage{nullptr};
    new_storage = new int[size];
    for (size_t i{0}; i < size; ++i)
        *(new_storage + i) = init_value;
    return new_storage;
}

void display (const int *const array, size_t size) { //We use all constant to not be able to mess with the array.
    for (size_t i{0}; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    int *my_array{nullptr};
    size_t size;
    int init_value {};
    
    cout << "\nHow many values do you wanna allocate? ";
    cin >> size;
    cout << "What value would you like them initialized to? ";
    cin >> init_value;
    
    my_array = create_array(size, init_value);
    /*While calling this function we're creating a space in the heap for the variable named 'new_storage'. When the function finishes it's
    process, the name will dissapear (as the function is temporal), but the data will remain in the heap. In conclussion, we're losing the
    pointer; that's why we return the value at the end of the function. The heap is a temporal space useful to interact between functions
    and main(). What's cool to undertand is that we're not gonna be storing lot of variables into the main memory, it's all temporal info,
    which will make the program easier to run.
    Be careful no to lose the pointers referencing those memory heaps because you're not gonna be able to clear that memory and eventually
    you'll run out of space.*/
    
    display(my_array, size);
    delete[] my_array; //After the data is used, as it is stored into the dynamic memory, we should delete it from there.
    return 0;
}

/*L-value's are those which have names and are addressable.
On int x {100}; x is an L-value and 100 is an R-value.
int y = x + 200; There (x + 200) is an R-value.
max(20,30) is an R-value because it returns a non adressable value.*/