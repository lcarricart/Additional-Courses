#include <iostream>
#include <fstream>

using namespace std;

/*
!IMPORTANT!
    The opening file process depends on each compiler, and there's not a single way of doing it. If I just create the "text.txt" file normally
    where it should go (along with the .cpp files), some compilers won't be able to read it. So I gotta check where's the ".exe" first, which
    sometimes is in the "Debugger" folder, and in that case change the following line and write: "in_file("../text.txt")". This is gonna tell
    the compiler to look for the file one folder above the current location, making the program work.
*/

int main()
{
	ifstream in_file;
    string line;
    int num;
    double total;
    in_file.open("text.txt"); 
    
    /* This line is operative_system-specific. Varies through Windows, Mac OS, or Unix.
    Imagine I have to open the directory "C:\dir\dir2\text.txt", well then the compiler will understand '/d' and '/t' as special characters.
    Therefore, we should write it the following way "C:\\dir\\dir2\\text.txt". However, this is not a good practice, as that file will only
    open in my computer; in order to make it more general we can say in_file.open("text.txt") and it will look through the current directory,
    regardless of any operative system as well.*/
    
    if (!in_file) {
    //If I can open he file, then:
        cerr << "Problem opening file" << endl;
        return 1;
        //Dont return a 0 because that's the main.
    }
    cout << "File is good to go" << endl;
    in_file >> line >> num >> total;
    //Read variables from 'in_file'.
    cout << line << endl << num << endl << total;
    
    in_file.close();    
	return 0;
}
