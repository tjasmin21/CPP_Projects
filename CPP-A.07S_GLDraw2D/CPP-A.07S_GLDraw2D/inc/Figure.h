/*/////////////////////////////////////////////////////////////////////////////
module:  CFigure abstract base class
purpose: interface base class for all geometrical figure classes

written: U.Kuenzler
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/



#ifndef _FIGURE_H_
#define _FIGURE_H_

// system includes ////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;



class CFigure
///////////////////////////////////////////////////////////////////////////////
{
public: // functions
   virtual void draw( void ) = 0;
   virtual void list( void ) = 0;
   virtual void save( ofstream& fs ) = 0;
   virtual void load( ifstream& fs ) = 0;

   virtual ~CFigure() = 0;
};

inline CFigure::~CFigure() {};

#endif // _FIGURE_H_ //////////////////////////////////////////////////////////
