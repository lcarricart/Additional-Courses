#include <iostream>
#include <fstream>

using namespace std;

/*The idea of this challenge is to create a copy of Shakespeare's play with number indications per line. The improved version of this program.
would only give numbers to lines with text, not blank lines.*/

int main()
{
	ifstream in_file("romeoandjuliet.txt");
    ofstream out_file("play_formatted.txt");
    string line;
    int line_counter {1};
    if(!in_file || !out_file) {
        cerr << "Problem opening input file, or creating output file" << endl;
        return 1;
    }
    
    while (getline(in_file, line)) {
        if (line == "") {
            out_file << endl;
        } else {
            out_file << line_counter << "\t" << line << endl;
            line_counter++;
        }
    }
    
    cout << "Formatted copy has been done succesfully." << endl;
    
    in_file.close();
    out_file.close();
	return 0;
}
