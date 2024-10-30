#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in_file;
    string line;
    string search {""};
    int counter {0};
    int total_words{0};
    in_file.open("romeoandjuliet.txt");
    
    if (!in_file) {
        cerr << "Problem opening the file";
        return 1;
    };
    
    cout << "Word seeker - write your value: ";
    cin >> search; //Try a get line and allow blank spaces. I think it doesn't work as I expected.
    
    while (in_file >> line) {
        total_words++;
        if (line.find(search) != string::npos) {
            counter++;
            cout << line << " ";
        }
    }
    cout << "\nAmong " << total_words << " words, yours have been found " << counter << " times." << endl;
    
    in_file.close();
	return 0;
}
