/*/////////////////////////////////////////////////////////////////////////////
module:  implementation of geom classes (CPP-A.07S_GLDraw2D)
purpose: implements all geometrical classes used in the draw application

written: U.Kuenzler
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/



// system includes ////////////////////////////////////////////////////////////
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;



// OpenGL helper includes /////////////////////////////////////////////////////
#include <GL/glew.h>
#include <FL/glut.H>



// application includes ///////////////////////////////////////////////////////
#include "../inc/Drawing.h"
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
// class:    CPoint
// function: draw()
// purpose:  draw point as cross using OpenGL commands
///////////////////////////////////////////////////////////////////////////////
void CPoint::draw( void )
///////////////////////////////////////////////////////////////////////////////
{
	// cout << "DEBUG: CPoint::draw() x=" << x << " y=" << y << endl;

	// define the size of cross
	static const float crosslength = 5;

	// draw the cross using two lines
	glBegin(GL_LINES);
	glVertex2f(x - crosslength, y);
	glVertex2f(x + crosslength+1, y );
	glVertex2f(x, y - (crosslength+1));
	glVertex2f(x, y + crosslength);
	glEnd();
}


///////////////////////////////////////////////////////////////////////////////
// class:    CPoint
// function: save()
// purpose:  saves data of a point object
///////////////////////////////////////////////////////////////////////////////
void CPoint::save( ofstream& fs )
///////////////////////////////////////////////////////////////////////////////
{
	fs << CDrawing::FIG_POINT << endl;
	fs << x << endl;
	fs << y << endl;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CPoint
// function: load()
// purpose:  loads data for a point object
///////////////////////////////////////////////////////////////////////////////
void CPoint::load( ifstream& fs )
///////////////////////////////////////////////////////////////////////////////
{
	fs >> x;
	fs >> y;
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
// function: assignment operator
// purpose:  constructs an object using another object of the same class
///////////////////////////////////////////////////////////////////////////////
CLine& CLine::operator=( const CLine& source )
///////////////////////////////////////////////////////////////////////////////
{
	_P1 = source._P1;
	_P2 = source._P2;
	return *this;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: operator+()
// purpose:  constructs a line object by adding two lines
///////////////////////////////////////////////////////////////////////////////
CLine CLine::operator+( const CLine& addline )
///////////////////////////////////////////////////////////////////////////////
{
	// define temporary local object
	CLine lineTemp;

	// calculate components of temporary line
	lineTemp._P1 = _P1;
	lineTemp._P2 = _P2 + addline._P2 - addline._P1;
	return lineTemp;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: set()
// purpose:  sets coordinates of line
///////////////////////////////////////////////////////////////////////////////
void CLine::set( float x1, float y1, float x2, float y2 )
///////////////////////////////////////////////////////////////////////////////
{
	_P1.x = x1;
	_P1.y = y1;
	_P2.x = x2;
	_P2.y = y2;
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
// class:    CLine
// function: draw()
// purpose:  draw line using OpenGL commands
///////////////////////////////////////////////////////////////////////////////
void CLine::draw( void )
///////////////////////////////////////////////////////////////////////////////
{
	glBegin(GL_LINES);
	glVertex2f(_P1.x, _P1.y);
	glVertex2f(_P2.x, _P2.y);
	glEnd();
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: save()
// purpose:  save data of line object
///////////////////////////////////////////////////////////////////////////////
void CLine::save( ofstream& fs )
///////////////////////////////////////////////////////////////////////////////
{
	fs << CDrawing::FIG_LINE << endl;
	fs << _P1.x << endl;
	fs << _P1.y << endl;
	fs << _P2.x << endl;
	fs << _P2.y << endl;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CLine
// function: load()
// purpose:  loads data for a line object
///////////////////////////////////////////////////////////////////////////////
void CLine::load( ifstream& fs )
///////////////////////////////////////////////////////////////////////////////
{
	fs >> _P1.x;
	fs >> _P1.y;
	fs >> _P2.x;
	fs >> _P2.y;
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
// function: operator+()
// purpose:  constructs a rectangle object by adding two rectangles
///////////////////////////////////////////////////////////////////////////////
CRect CRect::operator+( const CRect& addrect )
///////////////////////////////////////////////////////////////////////////////
{
	float x1 = _P1.x;
	float x2 = _P1.x;
	float y1 = _P1.y;
	float y2 = _P1.y;

	if (_P2.x < x1) x1 = _P2.x;
	if (addrect._P1.x < x1) x1 = addrect._P1.x;
	if (addrect._P2.x < x1) x1 = addrect._P2.x;

	if (_P2.y < y1) y1 = _P2.y;
	if (addrect._P1.y < y1) y1 = addrect._P1.y;
	if (addrect._P2.y < y1) y1 = addrect._P2.y;

	if (_P2.x > x2) x2 = _P2.x;
	if (addrect._P1.x > x2) x2 = addrect._P1.x;
	if (addrect._P2.x > x2) x2 = addrect._P2.x;

	if (_P2.y > y2) y2 = _P2.y;
	if (addrect._P1.y > y2) y2 = addrect._P1.y;
	if (addrect._P2.y > y2) y2 = addrect._P2.y;

	return CRect(x1, y1, x2, y2);
}

///////////////////////////////////////////////////////////////////////////////
// class:    CRect
// function: set()
// purpose:  sets the coordinates of the line
///////////////////////////////////////////////////////////////////////////////
void CRect::set( float x1, float y1, float x2, float y2 )
///////////////////////////////////////////////////////////////////////////////
{
	_P1.x = x1;
	_P1.y = y1;
	_P2.x = x2;
	_P2.y = y2;
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
// class:    CRect
// function: draw()
// purpose:  draw rectangle using OpenGL commands
///////////////////////////////////////////////////////////////////////////////
void CRect::draw( void )
///////////////////////////////////////////////////////////////////////////////
{
	glRectf(_P1.x, _P1.y, _P2.x, _P2.y);
}


///////////////////////////////////////////////////////////////////////////////
// class:    CRect
// function: save()
// purpose:  saves data from a rectangle object
///////////////////////////////////////////////////////////////////////////////
void CRect::save( ofstream& fs )
///////////////////////////////////////////////////////////////////////////////
{
	fs << CDrawing::FIG_RECT << endl;
	fs << _P1.x << endl;
	fs << _P1.y << endl;
	fs << _P2.x << endl;
	fs << _P2.y << endl;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CRect
// function: load()
// purpose:  loads data for a rectangle object
///////////////////////////////////////////////////////////////////////////////
void CRect::load( ifstream& fs )
///////////////////////////////////////////////////////////////////////////////
{
	fs >> _P1.x;
	fs >> _P1.y;
	fs >> _P2.x;
	fs >> _P2.y;
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
// function: constructor
// purpose:  constructs an object using two points
///////////////////////////////////////////////////////////////////////////////
CCircle::CCircle( const CPoint& ptP1, const CPoint& ptP2 )
///////////////////////////////////////////////////////////////////////////////
{
	_Radius = sqrtf( (float)(-ptP1.x + ptP2.x)*(-ptP1.x + ptP2.x) +
	                       (-ptP1.y + ptP2.y)*(-ptP1.y + ptP2.y) );
	_P1 = ptP1;
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
// function: operator+()
// purpose:  constructs a circle object by adding two circles
///////////////////////////////////////////////////////////////////////////////
CCircle CCircle::operator+( const CCircle& addcircle )
///////////////////////////////////////////////////////////////////////////////
{
	float radius  = 0;
	CPoint center = _P1;
	CPoint direction = addcircle._P1 - _P1;

	float delta = sqrtf( (float) 
		(-_P1.x + addcircle._P1.x)*(-_P1.x + addcircle._P1.x) +
		(-_P1.y + addcircle._P1.y)*(-_P1.y + addcircle._P1.y) );


	if (delta < min(_Radius, addcircle._Radius))
	{
		// circles delta smaller than minimal radius, use existing circle 
		if (_Radius < addcircle._Radius)
		{
			radius = addcircle._Radius;
			center = addcircle._P1;
		}
		else
		{
			radius = _Radius;
			center = _P1;
		}
	} 
	else
	{
		// circles delta greater than minimum radius, calculate new circle 
		radius = (delta + _Radius + addcircle._Radius) / 2.0F;
		direction.x = (direction.x / delta) * (radius - _Radius);
		direction.y = (direction.y / delta) * (radius - _Radius);
		center = _P1 + direction;
	}

	return CCircle(center, radius);
}

///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: set()
// purpose:  sets the coordinates of the line
///////////////////////////////////////////////////////////////////////////////
void CCircle::set( float x1, float y1, float radius )
///////////////////////////////////////////////////////////////////////////////
{
	_P1.x = x1;
	_P1.y = y1;
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


///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: draw()
// purpose:  draw circle using OpenGL commands
///////////////////////////////////////////////////////////////////////////////
void CCircle::draw( void )
///////////////////////////////////////////////////////////////////////////////
{
	glPushMatrix();
	glTranslatef((GLfloat)_P1.x, (GLfloat)_P1.y, 0.0);
	gluDisk(gluNewQuadric(), _Radius, _Radius, 100, 1);
	glPopMatrix();
}


///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: save()
// purpose:  save data as a circle object
///////////////////////////////////////////////////////////////////////////////
void CCircle::save( ofstream& fs )
///////////////////////////////////////////////////////////////////////////////
{
	fs << CDrawing::FIG_CIRCLE << endl;
	fs << _P1.x << endl;
	fs << _P1.y << endl;
	fs << _Radius << endl;
}


///////////////////////////////////////////////////////////////////////////////
// class:    CCircle
// function: load()
// purpose:  loads data for an circle object
///////////////////////////////////////////////////////////////////////////////
void CCircle::load( ifstream& fs )
///////////////////////////////////////////////////////////////////////////////
{
	fs >> _P1.x;
	fs >> _P1.y;
	fs >> _Radius;
}
