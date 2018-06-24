/*/////////////////////////////////////////////////////////////////////////////
   module:  main test program (CPP-A.03S_GLDraw2D)

   purpose: test program for geometric classes

   written: U.Kuenzler

   version: 1.01
/////////////////////////////////////////////////////////////////////////////*/


// includes ///////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

#include "../inc/Geom.h"


///////////////////////////////////////////////////////////////////////////////
// function: main
//
// purpose: test program to test classes
///////////////////////////////////////////////////////////////////////////////
int main(void)
{
	// write out initial counters
	cout << "initial object counters ..." << endl << endl;
	CPoint::listCount();
	CLine::listCount();
	CRect::listCount();
	CCircle::listCount();
	cout << endl;

	// static objects instantiation
	CPoint  P1( 1, 2 );
	CLine   L1( 10, 10, 20, 20 );
	CRect   R1( 100, 100, 200, 200 );
	CCircle C1( 400, 400, 60 );

	// dynamic objects instantiation
	CPoint*  pP2 = new CPoint( CPoint(3, 4 ));
	CLine*   pL2 = new CLine( CPoint( 30, 30 ), CPoint( 40, 40 ));
	CRect*   pR2 = new CRect( CPoint( 300, 300 ), CPoint( 400, 400 ));
	CCircle* pC2 = new CCircle( CPoint( 300, 300 ), 40 );

	// static objects instantiation using copy constructors
	CPoint  cP1 = P1;
	CLine   cL1 = L1;
	CRect   cR1 = R1;
	CCircle cC1 = C1;

	// dynamic objects instantiation using copy constructors
	CPoint*  pcP2 = new CPoint(*pP2);
	CLine*   pcL2 = new CLine(*pL2);
	CRect*   pcR2 = new CRect(*pR2);
	CCircle* pcC2 = new CCircle(*pC2);

	// call copy constructor only
	CLine L2 = L1;
	CRect R2 = R1;
	CCircle C2 = C1;

	// make true assignment
	L2 = CLine( 10, 10, 200, 20);

	// prepare vector addition
	CLine L3( 10, 10, 20, 80);
	CLine L4;
	CRect R3( 250, 250, 300, 300);
	CRect R4;
	CCircle C3( 580, 400, 120);
	CCircle C4;

	// add figure objects geometrically
	L4 = L2 + L3;
	R4 = R2 + R3;
	C4 = C2 + C3;

	// list coordinates of objects
	cout << "point objects, defined with P1" << endl;
	P1.list();
	cP1.list(); cout << endl;

	cout << "point objects, defined with P2" << endl;
	pP2->list();
	pcP2->list(); cout << endl;

	cout << "line objects, defined with P1,P2" << endl;
	L1.list();
	cL1.list(); cout << endl;

	cout << "line objects, defined with P1,P2" << endl;
	pL2->list();
	pcL2->list(); cout << endl;

	cout << "rectangle objects, defined with P1,P2" << endl;
	R1.list();
	cR1.list(); cout << endl;

	cout << "rectangle objects, defined with P1,P2" << endl;
	pR2->list();
	pcR2->list(); cout << endl;

	cout << "circle objects, defined with P1, Radius" << endl;
	C1.list();
	cC1.list(); cout << endl;

	cout << "circle objects, defined with P1, Radius" << endl;
	pC2->list();
	pcC2->list(); cout << endl;

	// list addition results
	cout << "line addition with L2,L3" << endl;
	L2.list();
	L3.list();
	L4.list(); cout << endl;

	cout << "rectangle addition with R2,R3" << endl;
	R2.list();
	R3.list();
	R4.list(); cout << endl;

	cout << "circle addition with C2,C3" << endl;
	C2.list();
	C3.list();
	C4.list(); cout << endl;

	// write out counters
	CPoint::listCount();
	CLine::listCount();
	CRect::listCount();
	CCircle::listCount();
	cout << endl;

	// explicit destroy of dynamic objects
	cout << "Deleting dynamic objects ..." << endl << endl;
	delete pP2;
	delete pL2;
	delete pR2;
	delete pC2;
	delete pcP2;
	delete pcL2;
	delete pcR2;
	delete pcC2;

	// write out counters
	CPoint::listCount();
	CLine::listCount();
	CRect::listCount();
	CCircle::listCount();
	cout << endl;

	return 0;
}
