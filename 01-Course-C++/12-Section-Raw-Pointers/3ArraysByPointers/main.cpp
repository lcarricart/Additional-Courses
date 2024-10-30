#include <iostream>

using namespace std;

//You can establish how many values do you wanna store into an address, converting it into an array of that type.

int main()
{
	size_t size{0};
    double *temp_ptr {nullptr};
    
    cout << "How many temps? ";
    cin >> size;
    temp_ptr = new double[size]; //This 'new' modifier tells to store information into the Heap (dynamic memory).
    cout << temp_ptr << " is the address" << endl;
    
    delete [] temp_ptr; //Every time we store something into the Heap we should delete it (the address).
    
    //Then, despite of having multiple adresses followed by the first one, temp_pts's value is the address in front (first one).
    
    /*
    --------------------------------------------------
    int scores[] {100, 95, 89};
    int *score_ptr {scores};
    cout << score_ptr << endl; Address of first value (0x61ff10)
    cout << (score_ptr + 1) << endl; Goes to the next pointer, allocated 8 bits after (size of an integer in my computer). 0x61ff18
    cout << (score_ptr + 2) << endl; 0x61ff26. Si la variable necesitase más bits, obviamente el puntero usará mas bits.
    
    As we are able to see, we can use the 'offset notation': *(array_name + index) or 'subscript notation': array_name[index].
    On the notations we can find:
    - Array subscript notation: scores[0] --> 100
    - Pointer subscripto notation: score_ptr[0] --> 100
    - Array offset notation: *(scores + 0) --> 100
    - Pointer offset notation: *(score_ptr + 0) --> 100     
    */
    
    int scores[] {100, 95, 89, 68, -1};
    int *score_ptr {scores};
    
    cout << *score_ptr << " " << *(score_ptr + 0) << " " << *(score_ptr + 1) << endl;
    
    while (*score_ptr != -1)
        cout << *score_ptr++ << endl;
    //Be careful with the example of cout << (*score_ptr)++ << endl; which seems to be an infinite loop.
    
    /*CONSTANT pointers: if we declare *const score_ptr; then we can change the value stored on it but not the address.
    If we wanna lock both options, we should initialize this way: cont int *const score_ptr;*/
    
	return 0;
}
