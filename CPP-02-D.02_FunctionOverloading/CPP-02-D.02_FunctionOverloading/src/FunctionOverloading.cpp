///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-02.02D - Function Overloading                                   //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// typedef oder using declaration
//typedef char* PSTR;
using PSTR = char*;

/* Ungültige Funktionsüberladungen - Rückgabewert
int print(char* str)
{
	cout << "Print string   : " << str << endl;
	return 0;
};
// */

/* Ungültige Funktionsüberladungen - typedef bzw. using nicht ausreichend
void print(PSTR str)
{
	cout << "Print typedef or using string: " << str << endl;
};
// */

/* Ungültige Funktionsüberladungen - int& bzw. const int
void print( int& value)
{
	cout << "Print integer  : " << value << endl;
};
// */


// Gültige Funktionsüberladungen
void print(char* str)
{
	cout << "Print string   : " << str << endl;
};

void print(int value)
{
	cout << "Print integer  : " << value << endl;
};

void print(double value)
{
	cout << "Print double   : " << value << endl;
};

void print(float value)
{
	cout << "Print float    : " << value << endl;
};

int main()
{
	char*   str = "str";
	int       i = 100;
	double    d = 12.34;	
	float     f = 56.78f;

	// use overloaded print functions
	print(str);
	print(i);
	print(d);	
	print(f);

	return 0;
}
