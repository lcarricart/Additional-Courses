#include <iostream>

#include <vector>

using namespace std;

int main()
{
	vector <int> vector1{};
    vector <int> vector2{};
    
    vector1.push_back(10);
    vector1.push_back(20);
    cout << "This are the values stored in vector 1: \n";
    cout << vector1.at(0) << " " << vector1.at(1) << endl;
    cout << "Size of vector 1 is: " << vector1.size() << endl << endl;
            
    vector2.push_back(100);
    vector2.push_back(200);
    cout << "This are the values stored in vector 2: \n";
    cout << vector2.at(0) << " " << vector2.at(1) << endl;
    cout << "Size of vector 2 is: " << vector2.size() << endl << endl;
    
    vector <vector<int>> vector_2d{};
    
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << "Content of two dimensional vector: \n";
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl << endl;
    
    vector1.at(0) = 1000;
    
    cout << "NEW content of two dimensional vector: \n";
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl << endl;
    
    cout << "NEW values stored in vector 1: \n";
    cout << vector1.at(0) << " " << vector1.at(1) << endl;
        
	return 0;
}
