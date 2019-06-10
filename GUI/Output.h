#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreateSelectToolBar() const;	//creates select mode toolbar & menu
	void PrintNumber(int k,int size) const;		//prints number on screen
	void PrintMessage(string msg,int size) const;	//Prints a message on status bar
	void CreateZoomToolBar() const;	//creates Zoom mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
		void CreateRotateToolBar() const;	//creates rotate mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void cleartoolbar() const;		//draws white rectangle on toolbar
	void Drawint(const int x,const int y,const long lNumber );		
	void Drawstring(const int x,const int y,string msg);	//tp print a string on the draw or play area
	void CreateResizeBar() const;	//create the resize tool bar
	void CreateZoominToolBar() const;	//creates Zoomin mode toolbar & menu
	void CreateZoomoutToolBar() const;	//creates Zoomout  mode toolbar & menu
	void Output::CreateBorderToolBar() const;	//creates border width mode toolbar & menu

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void CreateColorToolBar() const;	//creates color toolbar
	void CreateFillColorToolBar() const;	//creates fill color toolbar
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void Drawline(Point P1,Point P2,GfxInfo lineGfxInfo,bool selected) const;//Draw a Line
	void DrawTria(Point P1, Point P2,Point P3, GfxInfo circGfxInfo, bool selected=false) const;  //Draw a Triangle
	void Drawcir(Point P, int radius, GfxInfo circGfxInfo, bool selected) const; //Draw a circle
	void Output::CreateHandPToolBar() const;
	///Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar
	
	void DeleteRect(Point P1, Point P2, GfxInfo RectGfxInfo) const; // deletes a rect from the screen only	
	void DeleteLine(Point P1, Point P2, GfxInfo RectGfxInfo) const; // deletes a line from the screen only
	void DeleteCircle(Point P, int radius, GfxInfo RectGfxInfo) const; // deletes a circle from the screen only
	void DeleteTriangle(Point P1, Point P2,Point P3, GfxInfo RectGfxInfo) const; // deletes a triangle from the screen only
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	color getCrntBkColor() const;		// get current back ground color
	void setCrntDrawColor(color x) ;	//get current drwawing color
	void setCrntFillColor(color x) ;	//get current filling color
	void setCrntBkColor(color x) ;		//set background color
	~Output();
};

#endif