#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Countries;
struct Cities;

struct Tour {
    string title;
    vector<Countries> vec1;
};

struct Countries {
    string countries;
    vector<Cities> vec_city;
};

struct Cities {
    string cities;
    long population;
    double cost;
};

int main()
{
    Cities Bogota {"Bogota", 8778000, 400.98 };
    Cities Cali {"Cali", 2401000, 424.12 };
    Cities Medellin {"Medellin", 2464000, 350.98 };
    Cities Cartagena {"Cartagena", 972000, 345.34 };
    Countries Colombia {"Colombia", {Bogota, Cali, Medellin, Cartagena}};
    
    Cities Rio {"Rio De Janiero", 13500000, 567.45 };
    Cities Sao {"Sao Paulo", 11310000, 975.45 };
    Cities Salvador {"Salvador", 18234000, 855.99 };
    Countries Brazil {"Brazil", {Rio, Sao, Salvador}};
    
    Cities Valdivia {"Valdivia", 260000, 569.12 };
    Cities Santiago {"Santiago", 7040000, 520.00 };
    Countries Chile {"Chile", {Valdivia, Santiago}};
    
    Cities Baires {"Buenos Aires", 3010000, 723.77 };
    Countries Argentina {"Argentina", {Baires}};
    
    Tour tour {"Tour Ticket Prices from Miami:", {Colombia, Brazil, Chile, Argentina}};
    
//    cout << tour.title << endl << endl;
//    for (auto a:(tour.vec1)) {
//        cout << setw(7) << "[" << a.countries << "]" << endl;
//        for (auto b:(a.vec_city)) {
//            cout << setw(11) << ">" << b.cities << ": " << b.population << ", $" << fixed << setprecision(2) << b.cost << "." << endl;
//            //'fixed' fixes the integer part, and therefore setprecision now modifies the precision of the decimal part.
//        };
//    };

    const int field1_width {20};
    const int field2_width {20};
    const int field3_width {15};
    const int field4_width {15};
    const int total_width {field1_width + field2_width + field3_width + field4_width};
    
    for (size_t i=0; i < (total_width/10); i++)
        cout << "1234567890";
    cout << endl << endl;
    
    cout << setw(((total_width - sizeof(tour.title)) / 2)) << "" << tour.title << endl << endl;
    //That extra "" is very important, as the compiler gets very confused otherwise.
    cout << setw(field1_width) << left << "Country"
         << setw(field2_width) << left << "City"
         << setw(field3_width) << right << "Population"
         << setw(field4_width) << right << "Price" << endl;
    cout << setfill('-') << setw(total_width) << "" << endl << endl << setfill('\0');
    //That last argument sets the 'fill' to its default value.
    
    for (auto a:(tour.vec1)) {
        for (size_t i=0; i<(a.vec_city.size()) ; i++) {
            cout << setw(field1_width) << left << ((i == 0)? a.countries : "")
                 //This line has an 'if' statement in which I will display 'a.countries' if true, or "" if negative.
                 << setw(field2_width) << left << a.vec_city.at(i).cities
                 << setw(field3_width) << right << a.vec_city.at(i).population
                 << setw(field4_width) << right << fixed << setprecision(2) << a.vec_city.at(i).cost << endl;
        };
        cout << endl;
    };
    
    /* What's ruining the organization in this sample is displaying 'a.countries' in a separate instance. Dont exactly understand why.
       That's why it's necessary to use one ranged 'for' loop, and one basic. I tried to avoid basic ones.*/
       
//    for (auto a:(tour.vec1)) {
//        cout << setw(field1_width)  << a.countries;
//        for (auto b:(a.vec_city)) {
//            cout << setw(field2_width)  << b.cities 
//                 << setw(field3_width)  << b.population 
//                 << setw(field4_width)  <<"$" << fixed << setprecision(2) << b.cost << endl;
//        };
//        cout << endl;
//    };
    
    return 0;
}