#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;

int partial_width1{15};
int partial_width2{15};
int total_width{partial_width1 + partial_width2};
//Global variables.

void display(vector<string> students, vector<int> students_results, double average) {
    cout << left << setw(partial_width1) << "Students" << right << setw(partial_width2) << "Scores" << endl;
    cout << setfill('-') << setw(total_width) << "" << endl << setfill('\0');
    for (size_t i=0; i < students.size(); i++)
        cout << left << setw(partial_width1) << students.at(i) << right << setw(partial_width2) << students_results.at(i) << endl;
    cout << setfill('-') << setw(total_width) << "" << endl << setfill('\0');
    cout << fixed << setprecision(1);
    cout << left << setw(partial_width1) << "Average score" << right << setw(partial_width2) << average << endl;
};


int main()
{
	ifstream in_file;
    string key;
    string answer;
    int result;
    vector<int> students_results;
    string name;
    vector<string> students;
    double average{0};
    
    in_file.open("Responses.txt");
    if (!in_file) {
        cerr << "Problem opening the results file" << endl;
        return 1;
    };
    
    getline(in_file, key);
    while (in_file >> name >> answer) {
        result = 0;

        for (size_t i=0; i < key.size(); i++) {
        //Sizeof works only for showing sizes of character types. Otherwise it shows the size of the type. sizeof(string) = 32.
            if (answer[i] == key[i])
                result++;
        };
        
        students.push_back(name);
        students_results.push_back(result);
        average += result;
    };
    if (!(students_results.size() == 0))
        average = average / students_results.size();
    
    //Display
    display(students, students_results, average);
    
    in_file.close();
	return 0;
}
