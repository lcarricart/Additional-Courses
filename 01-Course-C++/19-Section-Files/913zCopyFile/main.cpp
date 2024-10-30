#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in_file;
    ofstream out_file;
    char c;
    
    in_file.open("poem.txt");
    if(!in_file) {
        cerr << "There was a problem opening the file" << endl;
        return 1;
    }
    out_file.open("poem_copy.txt");
    if(!out_file) {
        cerr << "There was a problem creating the file" << endl;
        return 1;
    }
    
    while (in_file.get(c)) { 
    //With in_file >> c it doesn't copy the blank spaces. We could also use getline for this case (formatted operator). Mine works as unformatted as well.
        out_file.put(c);
        //out_file << c; Was the version of a formatted IOS (getline).
    }
    
    cout << "File copied" << endl;
    
    in_file.close();
    out_file.close();
	return 0;
}
