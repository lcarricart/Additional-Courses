#include <iostream>
#include <vector>
#include <iomanip> //Format manipulator.

using namespace std;

int main()
{
	/*
    
    int scores[] {10, 20, 30};
    for (auto variable : scores)
        cout << variable << endl;

    Mi variable recorre scores. Tengo que otorgarle el mismo tipo que al vector, pero también puedo pedirlo automático. 
     
    Another example: 
    for (auto val: {1, 2, 3, 4, 5})
        cout << val << endl;
    
    Another:
    for (auto characters: "This is a test")
        if (characters != ' ')
            cout << characters;
        else
            cout << '|';
    
    */
    vector<double> temperatures {87.9, 77.9, 80, 72.5};
    double average {}, total {};
    
    for (auto var : temperatures)
        total += var;
    
    if (temperatures.size() != 0) {
        average = total / temperatures.size();
        cout << fixed << setprecision(1); //Format manipulator.
        cout << "El promedio de temperaturas es " << average << endl;
    }    
    
    cout << "--------------------------------" << endl;
    
    vector<vector<int>> vector_2d {
        {1, 2, 3},
        {10, 20, 30, 40},
        {100, 200, 300, 400, 500}
    };
    
    for (auto count: vector_2d) { //auto deduces type vector.
        for (auto val: count) { //auto deduces type int.
            cout << val << " ";
        }
        cout << endl;
    }
    
	return 0;
}
