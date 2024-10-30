#include <iostream>

using namespace std;

void print(int *array, size_t);
int *apply_all(int *array1, size_t, int *array2, size_t);
//I don't totally get to understand why the function carries a '*'. Is it because of the line '*results = apply_all' ?

int main()
{
	int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: ";
    print(array1, 5);
    //By passing 'array1', the function is receiving the address of the first value on the array 1.
    cout << "Array 2: ";
    print(array2, 3);
    
    int *results = apply_all(array1, 5, array2, 3);
    //This function is written to return a reference (which indicates I must use the heap).
    cout << "Result: ";
    print(results, 15);
    delete results;
    
	return 0;
}

void print(int *array, size_t size) {
//As I was passing the address of the first value, I use a pointer to reffer to the content of it.
    for (size_t i{0}; i < size ; i++) {
        cout << array[i] << " ";
        //cout << *(array + i) << " "; Another way of writing the statement; more explicit and clear, they way I wrote it.
    }
    cout << endl;
}

int *apply_all(int *array1, size_t size1, int *array2, size_t size2) {
    int *new_array {nullptr};
    new_array = new int[size1*size2];
    int position {};
    for (size_t i{0} ; i < size1 ; i++) {
        for (size_t j{0} ; j < size2 ; j++) {
            new_array[position] = array1[i] * array2[j];
            position++;
        }
    }
    return new_array;
}