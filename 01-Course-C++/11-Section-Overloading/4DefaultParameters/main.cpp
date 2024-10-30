#include <iostream>

using namespace std;

double calc_cost(double base_cost, double tax_rate = 0.06); //I'm setting the second parameter as default, unless I specify something different.
//Remember that default argument values that do not change should be placed at the tail end of the parameter list.

double calc_cost(double base_cost, double tax_rate) {
    return base_cost += (base_cost * tax_rate);
}

int main()
{
	double cost {0};
    cost = calc_cost(200.0); //Will use 0.06
    cost = calc_cost (100.0, 0.08); //Will use 0.08
    
	return 0;
}
