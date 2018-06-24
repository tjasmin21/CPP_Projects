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
#include <ctime>
#include <cstdlib>
#include <vector>
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

	// some definitions
	CPoint aPoints[ 40 ];
	CPoint *paPoints = new CPoint[ 40 ];

	vector<CPoint*>  PointVec;
	vector<CLine*>   LineVec;
	vector<CRect*>   RectVec;
	vector<CCircle*> CircleVec;

	// init seed of random function
	srand((unsigned)time(NULL));

	// init points by using random numbers
	for ( int iCount = 0; iCount < 40; iCount++ ) {
		 aPoints[ iCount ].set( (float)(rand() % 800), (float)(rand() % 600) );
		paPoints[ iCount ].set( (float)(rand() % 800), (float)(rand() % 600) );
		PointVec.push_back( new CPoint( (float)(rand() % 800), (float)(rand() % 600) ));

		LineVec.push_back( new CLine(
			CPoint( (float)(rand() % 800), (float)(rand() % 600) ),
			CPoint( (float)(rand() % 800), (float)(rand() % 600) )));

		RectVec.push_back( new CRect(
			CPoint( (float)(rand() % 800), (float)(rand() % 600) ),
			CPoint( (float)(rand() % 800), (float)(rand() % 600) )));

		CircleVec.push_back( new CCircle(
			CPoint( (float)(rand() % 800 ), (float)(rand() % 600) ), (float)(rand() % 80 + 10) ));
	}

	// check for viewing mode
	if ( mode == VIEW_DRAWING )
	{
		// TODO: add code here to draw objects

		// loop the arrays to draw the content
		for ( int iCount = 0; iCount < 40; iCount++ )
		{
			aPoints[ iCount ].draw();
			paPoints[ iCount ].draw();
		}

		// draw objects in vectors
		for (unsigned int i=0; i<PointVec.size(); i++)
		{
			PointVec[i]->draw();
			LineVec[i]->draw();
			RectVec[i]->draw();
			CircleVec[i]->draw();
		}

	}
	else // VIEW_LISTING
	{
		// TODO: add code here to list objects

		for ( int iCount = 0; iCount < 40; iCount++ )
		{
			aPoints[ iCount ].list();
			paPoints[ iCount ].list();
		}

		// list objects in vectors
		for (unsigned int i=0; i<PointVec.size(); i++)
		{
			PointVec[i]->list();
			LineVec[i]->list();
			RectVec[i]->list();
			CircleVec[i]->list();
		}

	}

	// delete dynamic allocated objects
	delete[] paPoints;

	// delete objects in vectors --> calls object destructors
	for (unsigned int i=0; i<PointVec.size(); i++)
	{
		delete PointVec[i];
		delete LineVec[i];
		delete RectVec[i];
		delete CircleVec[i];
	}

	// clear elements from vectors --> removes elements with object pointer
	PointVec.clear();
	LineVec.clear();
	RectVec.clear();
	CircleVec.clear();

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
