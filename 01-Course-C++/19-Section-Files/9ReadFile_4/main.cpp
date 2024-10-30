#include <iostream>
#include <fstream>

using namespace std;

/*
We're gonna use unformatted input this time over the same example. It gives you plenty of flexibility to read files disregarding end of
files, or fancy characters that may break the way you're processing.
*/

int main()
{
    ifstream in_file;
    char c;
    
    in_file.open("poem.txt");
    if(!in_file) {
        cerr << "Problem opening file" << endl;
        return 1;
    }
    
    while (in_file.get(c)) {
        cout << c;
    };
    //This while also displays the 'Enter' characters, dropping line to line as well.
    cout << endl;
    
    in_file.close();
	return 0;
}
