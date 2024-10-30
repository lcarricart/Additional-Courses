#include <iostream>
#include <iomanip>

using namespace std;

void ruler() {
    cout << "\n1234567890123456789012345678901234567890" << endl;
    //this functions helps me understanding identations and justifications at displaying.
}

int main()
{
    int num1 {1234};
	double num2 {1234.5678};
    std::string hello {"Hello"};
    
    //Defaults
    cout << "\n Defaults-------------------------" << endl;
    ruler();
    cout << num1 
         << num2
         << hello
         << endl;
    //Defaults - one per line
    cout << "\n Defaults- one per line-----------------" << endl;
    ruler();
    cout << num1 << endl;
    cout << num2 << endl;
    cout << hello << endl;
    
    cout << "\n width 10 for num1----------------------------" << endl;
    ruler();
    cout << setw(10) << num1
                     << num2
                     << hello
                     << endl;
    cout << "\n width 10 for num1 and num2 ------------------------" << endl;
    ruler();
    cout << setw(10) << num1
         << setw(10) << num2
                     << hello
                     << endl;
    cout << "\n width 10 for num1, num2, hello. Left for all setfill to dash-----" << endl;
    ruler();
    cout << setfill('-');
    cout << setw(10) << left << num1
         << setw(10) << left << num2
         << setw(10) << left << hello
         << endl;
         
    cout << "\n width 10 for num1, num2, hello. Setfill varies-------------" << endl;
    ruler();
    cout << setw(10) << left << setfill('*') << num1
         << setw(10) << left << setfill('+') << num2
         << setw(10) << left << setfill('-') << hello
         << endl;
         
    cout << endl << endl;
	return 0;
}
