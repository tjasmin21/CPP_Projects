///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-02.02D - Function Overloading                                   //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// typedef oder using declaration
//typedef char* PSTR;
using PSTR = char*;

/* Ung�ltige Funktions�berladungen - R�ckgabewert
int print(char* str)
{
	cout << "Print string   : " << str << endl;
	return 0;
};
// */

/* Ung�ltige Funktions�berladungen - typedef bzw. using nicht ausreichend
void print(PSTR str)
{
	cout << "Print typedef or using string: " << str << endl;
};
// */

/* Ung�ltige Funktions�berladungen - int& bzw. const int
void print( int& value)
{
	cout << "Print integer  : " << value << endl;
};
// */


// G�ltige Funktions�berladungen
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
