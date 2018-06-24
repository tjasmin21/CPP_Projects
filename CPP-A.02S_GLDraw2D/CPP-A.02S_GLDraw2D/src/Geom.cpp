/*/////////////////////////////////////////////////////////////////////////////
module:  implementation of geom classes (CPP-A.02S_GLDraw2D)
purpose: implements all geometrical classes used in the draw application

written: U.Kuenzler
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/



// system includes ////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;


// application includes ///////////////////////////////////////////////////////
#include "../inc/Geom.h"


// static data definitions ////////////////////////////////////////////////////
unsigned long CPoint::ulCount = 0;
unsigned long CLine::ulCount = 0;
unsigned long CRect::ulCount = 0;
unsigned long CCircle::ulCount = 0;


///////////////////////////////////////////////////////////////////////////////
// class:    CPoint
// function: copy constructor
// purpose:  constructs an object using another object of the same class
///////////////////////////////////////////////////////////////////////////////
CPoint::CPoint(const CPoint& source)
///////////////////////////////////////////////////////////////////////////////
{
	x = source.x;
	y = source.y;
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CPoint
// function: list()
// purpose:  list coordinates on standard console
///////////////////////////////////////////////////////////////////////////////
void CPoint::list( void )
///////////////////////////////////////////////////////////////////////////////
{
	cout << "CPoint : " << "Px=" << x << " Py=" << y << endl;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: constructor
// purpose:  constructs a object using two coordinate pairs
///////////////////////////////////////////////////////////////////////////////
CLine::CLine( float x1, float y1, float x2, float y2 )
///////////////////////////////////////////////////////////////////////////////
{
	set( x1, y1, x2, y2 );
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: constructor
// purpose:  constructs an object using two points
///////////////////////////////////////////////////////////////////////////////
CLine::CLine( const CPoint& ptP1, const CPoint& ptP2 )
///////////////////////////////////////////////////////////////////////////////
{
	_P1 = ptP1;
	_P2 = ptP2;
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: copy constructor
// purpose:  constructs an object using another object of the same class
///////////////////////////////////////////////////////////////////////////////
CLine::CLine( const CLine& source )
///////////////////////////////////////////////////////////////////////////////
{
	_P1 = source._P1;
	_P2 = source._P2;
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: set()
// purpose:  sets coordinates of line
///////////////////////////////////////////////////////////////////////////////
void CLine::set( float x1, float y1, float x2, float y2 )
///////////////////////////////////////////////////////////////////////////////
{
	_P1.set(x1, y1);
	_P2.set(x2, y2);
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: list()
// purpose:  list coordinates on standard console
///////////////////////////////////////////////////////////////////////////////
void CLine::list( void )
///////////////////////////////////////////////////////////////////////////////
{
	cout << "CLine  :" << endl; _P1.list(); _P2.list(); cout << endl;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CRect
// function: constructor
// purpose:  constructs a object using two coordinate pairs
///////////////////////////////////////////////////////////////////////////////
CRect::CRect( float x1, float y1, float x2, float y2 )
///////////////////////////////////////////////////////////////////////////////
{
	set( x1, y1, x2, y2 );
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CRect
// function: constructor
// purpose:  constructs an object using two points
///////////////////////////////////////////////////////////////////////////////
CRect::CRect( const CPoint& ptP1, const CPoint& ptP2 )
///////////////////////////////////////////////////////////////////////////////
{
	_P1 = ptP1;
	_P2 = ptP2;
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CRect
// function: copy constructor
// purpose:  constructs an object using another object of the same class
///////////////////////////////////////////////////////////////////////////////
CRect::CRect( const CRect& source )
///////////////////////////////////////////////////////////////////////////////
{
	_P1 = source._P1;
	_P2 = source._P2;
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CRect
// function: set()
// purpose:  sets the coordinates of the line
///////////////////////////////////////////////////////////////////////////////
void CRect::set( float x1, float y1, float x2, float y2 )
///////////////////////////////////////////////////////////////////////////////
{
	_P1.set(x1, y1);
	_P2.set(x2, y2);
}


///////////////////////////////////////////////////////////////////////////////
// class:    CRect
// function: list()
// purpose:  list coordinates on standard console
///////////////////////////////////////////////////////////////////////////////
void CRect::list( void )
///////////////////////////////////////////////////////////////////////////////
{
	cout << "CRect  :" << endl; _P1.list(); _P2.list(); cout << endl;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: constructor
// purpose:  constructs a object using two coordinate pairs
///////////////////////////////////////////////////////////////////////////////
CCircle::CCircle( float x1, float y1, float radius )
///////////////////////////////////////////////////////////////////////////////
{
	set( x1, y1, radius );
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: constructor
// purpose:  constructs an object using two points
///////////////////////////////////////////////////////////////////////////////
CCircle::CCircle( const CPoint& ptP1, float radius )
///////////////////////////////////////////////////////////////////////////////
{
	_P1 = ptP1;
	_Radius = radius;
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: copy constructor
// purpose:  constructs an object using another object of the same class
///////////////////////////////////////////////////////////////////////////////
CCircle::CCircle( const CCircle& source )
///////////////////////////////////////////////////////////////////////////////
{
	_P1 = source._P1;
	_Radius = source._Radius;
	ulCount++;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: set()
// purpose:  sets the coordinates of the line
///////////////////////////////////////////////////////////////////////////////
void CCircle::set( float x1, float y1, float radius )
///////////////////////////////////////////////////////////////////////////////
{
	_P1.set(x1, y1);
	_Radius = radius;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: list()
// purpose:  list coordinates on standard console
///////////////////////////////////////////////////////////////////////////////
void CCircle::list( void )
///////////////////////////////////////////////////////////////////////////////
{
	cout << "CCircle: " << endl; _P1.list();
	cout << "Radius : " << _Radius << endl << endl;
}
