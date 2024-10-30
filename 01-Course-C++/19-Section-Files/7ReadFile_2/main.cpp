#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	fstream in_file;
    string line;
    int num;
    double total;
    
    in_file.open("test.txt");
    if(!in_file) {
        cerr << "Problem opening file" << endl;
        return 1;
    };
    
    while (!in_file.eof()) {
    //If it's not the 'end of file'
        in_file >> line >> num >> total;    
        cout << setw(10) << left << line
             << setw(10) << num
             << setw(10) << total << endl;
    };
    /*
    We could also write the following while loop:
    
        while (in_file >> line >> num >> total) {
            cout << .......
        };
        
    If the code given as an argument fails for any reason, the while loop will end.
    */
    in_file.close();
    
	return 0;
}
