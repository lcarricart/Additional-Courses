#include <iostream>
#include <string>

using namespace std;

int main()
{
	string part1 {"C++"};
    string part2 {"is a powerful"};
    string sentence; //remember that in C++ this automatically inicializes.
    
    sentence = part1 + " " + part2 + " language";
    //NOT the same as | sentence = "C++" + " is powerful"; Because this operations doesn't work on C-style strings.
    cout << sentence << endl;
    
    //How to extract text from a variable:
    cout << sentence.substr(0, 12) << endl;
    
    //Find data in variables:
    cout << "Language was find on position " << sentence.find("language") << " on variable 'sentence'" << endl;
    
    //With sentence.erase(start_inex, lenght) we can remove words.
    
    /*//sentence.lenght() method, and concatenation
    string s1 {"Luciano"};
    s1 +=" Carriic";
    cout << s1 << endl;
    
    cout << "Give me your name: ";
    getline(cin, s1);
    //This getline is very usfeul because it let you store value separated by spaces. It finishes when receiving a /n ('Enter').
    cout << s1 << endl;
    cout << "Extracting first three characters from your name: " << s1.substr(0,3) << endl;*/
    
    /*Initializing ways:
    string s0; No garbage.
    string s1 {apple};
    string s5 {s1}; 'apple'
    string s6 {s1, 1, 4}; 'ppl' --> '1' meaning the initial character and '4' the lenght of the substring.
    string s7 (4, 'X'); Constructor way. 'XXXX'
    */
    
    cout << "-------------Secret section---------------" << endl;
    string secret {"Miranda Hidden Clue"};
    string answer;
    cout << "Introduce one secret word to access the files: ";
    getline (cin, answer);
    
    size_t position = secret.find(answer);
    if (position != string::npos) //'string::npos means there's no position'
        cout << "You're able to access." << endl;
    else
        cout << "Access not granted, please leave." << endl;
    
    cout << endl;
	return 0;
}
