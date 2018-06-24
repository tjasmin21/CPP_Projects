/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of drawing class
purpose: this class provides the interface to manage the geometric figures
         of a drawing. This includes functions to display, append, remove
         and the functionality to save/load figures from a file.

written: U.Kuenzler
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/



// system includes ////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;



// application includes ///////////////////////////////////////////////////////
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Drawing.h"
#include "../inc/Geom.h"



// static data definitions ////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: displayDrawing()
// purpose:  This function is called, if the GLUT window handler decides to
//           draw or redraw the window. This happens for instance if the user
//           draws a new figure or resizes or min/maximizes the window.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::displayDrawing( EViewMode mode )
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: insert code to draw and list figures

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

	// check for viewing mode
	if ( mode == VIEW_DRAWING )
	{
		// TODO: add code here to draw objects
		P1.draw();
		L1.draw();
		R1.draw();
		C1.draw();

		pP2->draw();
		pL2->draw();
		pR2->draw();
		pC2->draw();

		L2.draw();
		L3.draw();
		L4.draw();

		R2.draw();
		R3.draw();
		R4.draw();

		C2.draw();
		C3.draw();
		C4.draw();

	}
	else // VIEW_LISTING
	{
		// TODO: add code here to list objects

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
	}

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

	// write out counters for testing
	CPoint::listCount();
	CLine::listCount();
	CRect::listCount();
	CCircle::listCount();
	cout << endl;

}
// CDrawing::displayDrawing() /////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: clearDrawing()
// purpose:  This function is called, if the user exits the application or
//           if the user clears the window or opens an existing drawing from
//           a file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::clearDrawing( void )
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: insert code to clear drawing data
}
// CDrawing::clearDrawing() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: appendFigure()
// purpose:  This function is called, if the user starts drawing a new
//           figure in the window. For lines, rectangles and circles this
//           function is constantly called, until the user stops drawing by
//           releasing the left mouse button.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::appendFigure(EFigType figtype, const CPoint& p1, const CPoint& p2)
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: add code to append figure to list
}
// CDrawing::appendFigure() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: removeFigure()
// purpose:  This function is called, to remove temporary figures while the
//           user is interactively drawing lines, rectangles or circles.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::removeFigure( void )
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: add code to remove figure from list
}
// CDrawing::removeFigure() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: loadDrawingFile()
// purpose:  This function is called, if the user loads a figure drawing
//           file from external storage. The read data will be used to re-
//           instantiate the corresponding figure objects.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::loadDrawingFile(const string& filename)
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: add drawing file reading code here
}
// CDrawing::loadDrawingFile() ////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: saveDrawingFile()
// purpose:  This function is called, if the user saves a figure drawing
//           file to external storage. The filename parameter contains the
//           user selected file path of the drawing file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::saveDrawingFile(const string& filename)
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: add drawing file writing code here
}
// CDrawing::saveDrawingFile() ////////////////////////////////////////////////
