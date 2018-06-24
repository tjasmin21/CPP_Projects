///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-02.06D - Operators                                              //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////////////
// class declaration and implementation of class point
///////////////////////////////////////////////////////////////////////////////
class CPoint
///////////////////////////////////////////////////////////////////////////////
{
private:
   int iX;
   int iY;

public:
   ~CPoint() { cout << "calling destructor" << endl; iX = -9999; iY = -9999; };
   CPoint() : iX(0), iY(0) { cout << "calling default constructor" << endl; };
   CPoint(int x, int y) : iX(x), iY(y) { cout << "calling constructor" << endl; };
   
   CPoint(const CPoint& aPoint);
   //CPoint(CPoint&& aPoint); // = delete;

   CPoint& operator=(const CPoint& aPoint);
   //CPoint& operator=(CPoint&& aPoint); // = delete;

   CPoint operator+(const CPoint& aPoint);
   void List() {cout << "iX=" << iX << ", iY=" << iY << endl;};
};



//* copy constructor ///////////////////////////////////////////////////////////
CPoint::CPoint(const CPoint& aPoint)
: iX(aPoint.iX), iY(aPoint.iY)
///////////////////////////////////////////////////////////////////////////////
{
	cout << "calling copy constructor" << endl;
}
/////////////////////////////////////////////////////////////////////////// */


/* move constructor ///////////////////////////////////////////////////////////
CPoint::CPoint(CPoint&& aPoint)
: iX(aPoint.iX), iY(aPoint.iY)
///////////////////////////////////////////////////////////////////////////////
{
	cout << "calling move constructor" << endl;
}
/////////////////////////////////////////////////////////////////////////// */



//* (copy)assignment operator //////////////////////////////////////////////////
CPoint& CPoint::operator=(const CPoint& aPoint)
///////////////////////////////////////////////////////////////////////////////
{
	cout << "calling (copy)assignment operator" << endl;
	iX = aPoint.iX;
	iY = aPoint.iY;
	return *this;
}
//////////////////////////////////////////////////////////////////////////// */



/* move assignment operator ///////////////////////////////////////////////////
CPoint& CPoint::operator=(CPoint&& aPoint)
///////////////////////////////////////////////////////////////////////////////
{
	cout << "calling move assignment operator" << endl;
	iX = aPoint.iX;
	iY = aPoint.iY;
	return *this;
}
//////////////////////////////////////////////////////////////////////////// */



// + operator /////////////////////////////////////////////////////////////////
CPoint CPoint::operator+(const CPoint& aPoint)
///////////////////////////////////////////////////////////////////////////////
{
   // create local point object
   CPoint tmpPoint;

   // calculate components of temporary point
   tmpPoint.iX = iX + aPoint.iX;
   tmpPoint.iY = iY + aPoint.iY;

   return tmpPoint;
}


int main()
///////////////////////////////////////////////////////////////////////////////
{
	CPoint    P1(10, 10);
	CPoint    P2(20, 20);
	CPoint    P3;

	cout << "Point P1: "; P1.List();
	cout << "Point P2: "; P2.List();
	cout << "Point P3: "; P3.List();

	// add point vectors
	P3 = P1 + P2;
	//P3.operator=(P1.operator+(P2));
	cout << endl << "Point P3: "; P3.List();

	return 0;
}