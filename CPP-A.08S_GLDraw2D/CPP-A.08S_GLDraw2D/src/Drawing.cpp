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
#include <vector>
#include <iostream>
using namespace std;



// application includes ///////////////////////////////////////////////////////
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Exceptions.h"
#include "../inc/Drawing.h"
#include "../inc/Geom.h"



// static data definitions ////////////////////////////////////////////////////
vector<CFigure*> CDrawing::_FigVec;
const string CDrawing::file_id = "GLDraw2DFileID";  // GLDraw2D file format ID



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

	// check for viewing mode
	if ( mode == VIEW_DRAWING )
	{
		// TODO: add code here to draw objects

		// draw all elements
		for (vector<CFigure*>::iterator pos = _FigVec.begin(); pos != _FigVec.end(); ++pos)
		{
			(*pos)->draw( );
		}
	}
	else // VIEW_LISTING
	{
		// TODO: add code here to list objects

		// list all elements
		for (vector<CFigure*>::iterator pos = _FigVec.begin(); pos != _FigVec.end(); ++pos)
		{
			(*pos)->list( );
		}

		// write out counters for testing
		CPoint::listCount();
		CLine::listCount();
		CRect::listCount();
		CCircle::listCount();
		cout << endl;
	}
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

	// delete all figure objects from list
	for (vector<CFigure*>::iterator pos = _FigVec.begin(); pos != _FigVec.end(); ++pos)
	{
		delete *pos;
	}

	// delete all figure pointers from list
	_FigVec.clear();
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

   CFigure *pNewFigure = 0;

   switch ( figtype ) {
	  case FIG_POINT:
		  pNewFigure = new CPoint(p1);
		  break;

	  case FIG_LINE:
		  pNewFigure = new CLine(p1, p2);
		  break;

      case FIG_RECT:
         pNewFigure = new CRect(p1, p2);
         break;

      case FIG_CIRCLE:
         pNewFigure = new CCircle(p1, p2);
         break;
   }

   // add figure to list
   _FigVec.push_back( pNewFigure );
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

	// test for non empty figure list
	if (!_FigVec.empty() )
	{
		// delete figure object
		delete _FigVec.back( );

		// remove figure pointer from list
		_FigVec.pop_back( );
	}
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

	try // opening drawing file
	{
		// load data and re-instantiate figure objects

		// local variables
		int         iFigureTyp = 0;
		CFigure*	pNewFigure = 0;
		ifstream	drawing_file(filename.c_str());
		string		file_header;

		// set input stream to throw exceptions
		drawing_file.exceptions(ios::badbit);

		// check for file format id
		drawing_file >> file_header;
		if ( file_header != file_id  )
		{
			// throw file id error exception
			throw CErrorFileID("Invalid File Type!");
		}

		// read type ahead
		drawing_file >> iFigureTyp;

		while ( drawing_file.good() )
		{
			// check for figure type
			switch ( iFigureTyp )
			{
			case FIG_POINT:
				pNewFigure = new CPoint;
				break;
			case FIG_LINE:
				pNewFigure = new CLine;
				break;
			case FIG_RECT:
				pNewFigure = new CRect;
				break;
			case FIG_CIRCLE:
				pNewFigure = new CCircle;
				break;
			default:
				// no valid figure type found
				pNewFigure = NULL;
				// throw figure type error exception
				throw CErrorFigureType("Invalid Figure Type - Opening of file canceled!");
			}

			// check for valid figure type
			if (pNewFigure != NULL)
			{
				// load data
				pNewFigure->load( drawing_file );

				// add figure to list
				_FigVec.push_back( pNewFigure );
			}

			// read next figure type
			// (separator line is skipped, because of "skipws" flag)
			drawing_file >> iFigureTyp;
		}
	}
    // exception handlers for file opening
    catch ( CErrorFigureType& err)
	{
        // handle figure type error exceptions
		UtilFLTK::showMessageBox(err.GetMessage());
    }
    catch ( CErrorFileID& err)
	{
        // handle file id error exceptions
		UtilFLTK::showMessageBox(err.GetMessage());
    }
    catch (...)
	{
		// handle all other exceptions
		UtilFLTK::showMessageBox( "Unknown File Opening Error" );
		throw;	// re-throw exception
    }
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

	try // saving drawing
	{
		// save all figure objects persistent data

		// create file output stream
		ofstream drawing_file(filename.c_str());

		// set output stream to throw exceptions
		drawing_file.exceptions(ios::badbit | ios::failbit);

		// store file format header
		drawing_file << file_id << endl;

		// save all elements
		for (vector<CFigure*>::iterator pos = _FigVec.begin(); pos != _FigVec.end(); ++pos)
		{
			(*pos)->save( drawing_file );

			// add figure separator line to data file
			drawing_file << endl;
		}

	}
	// exception handlers for file saving
	catch (...)
	{
		// handle all other exceptions
		UtilFLTK::showMessageBox( "Unknown File Saving Error" );
		throw;	// re-throw exception
	}
}
// CDrawing::saveDrawingFile() ////////////////////////////////////////////////
