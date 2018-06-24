 ///////////////////////////////////////////////////////////////////////////////
 // Demo: CPP-08-D.01 - Unified Intializers and Lambda Expressions (C++11)    //
 ///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


struct employee
{
	string name;
	float salary;
};


int main() ///////////////////////////////////////////////////////////////////////
{
	vector <employee> staff{ {"John",3000.0}, {"Josh",2100.0}, {"Kate",2900.0}, {"Rose",1700.0}, {"Tomm",1500.0} };

	const auto lower_limit = 1600.0;
	const auto upper_limit = 2400.0;


	// report which employee has a salary that is within the specified range
	vector<employee>::iterator found = staff.begin();
	// auto found = staff.begin();

	while (found != staff.end())
	{
		found = std::find_if(found, staff.end(), 
			[&](const employee& e) -> bool {return e.salary >= lower_limit && e.salary < upper_limit;} );

		if (found != staff.end()) {
			cout << (*found).name << ":" << (*found).salary << endl; 
			found++;
		}
	}

	return 0;
}
