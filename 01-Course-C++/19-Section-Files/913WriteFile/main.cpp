#include <iostream>
#include <fstream>

using namespace std;

//After running this program, the compiler won't show us the text file in the IDE, but if we look into the containing folder, it's there.

int main()
{
	ofstream out_file ("output.txt");
    //ofstream out_file ("output.txt", std::ios::app);
    if(!out_file) {
        cerr << "Error creating file" << endl;
        return 1;
    }
    
    string line;
    cout << "Enter something to write into the file: ";
    getline(cin, line);
    
    out_file << line << endl;
    
    out_file.close();    
	return 0;
}
