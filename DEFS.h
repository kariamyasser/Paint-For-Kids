#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"
#include <fstream>

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,		//Draw Circle
	DRAW_TRI,		//Draw Triangle
	SELECT,			//select figs
	
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_BK_CLR,	//Change background color
	FILL_CLR,	//Change the filling color
	
	RESIZE,			//Resize a figure(s)

		CHNG_BORDER, //change border of shapes
	MOVE,			//Move a figsure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	DEL,			//Delete a figure(s)
	COPY,			//copy figures
	ZOOM,			//zoom in or out graph
	CUT,			//cut figs
	PASTE,			//paste figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	TO_HIDE,		//switches to pick and hide
	TO_SCRAMB,		//scramble and find
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	TO_COLOR,		//Switch to color toolbar
	REDD,
	BLUEE,
	BLACKK,
	GREENN,
	YELLOWW,
	PURPLEE,
	BACK,
	TYPE,			//pick and hide by type
	FILL,			//pick and hide by fill color
	TYPEANDFILL,	//pick and hide by fill color and type
	AREA,			////pick and hide by area
	BACK2,				// return to previous toolbar
	ZOOMIN,				//zoom in
	ZOOMOUT,				//zoom out	
	BACK3,		// return to previous toolbar
	BACK4,		// return to previous toolbar
	BACK5,		// return to previous toolbar
	BY125,		//zoom in by 25 percent
	BY150,			//zoom in by 50 percent
	BY175,		//	zoom in by 75 percent
	BY200,		// zoom in by 100 percent
	
	BY75,			// zoom out by 75 percent	
	BY50,			//zoom out by 50 percent
	BY25,		//zoom out by 25 percent
	QUARTER,		//resize by 0.25
	HALF,				//resize by 0.5
	DOUBLEE,			//resize by 2
	QUAD,				//resize by 4
	FONT1,				//border resize by 4
	FONT2,				//border resize by 2
	FONT3,			//border resize by 0.5
	FONT4,			//border resize by 0.25
	NO_FILL,		// no fill color for the figs
	BACK6,			// return to previous toolbar
	BY90,				//rotate by 90
	BY180,				//rotate by 180
	BY270,				//rotate by 270
	BACK7,				//// return to previous toolbar
	BACK8,				// return to previous toolbar
	BACK9,				// return to previous toolbar
	STB,				//send to back
	BTF,				//bring to front
	NO_ZOOMIN,				// cancel zoom in
	NO_ZOOMOUT			//cancel zoom out
	
};
enum ResizeType // returns action to resize factor
{
	R_quarter,
	R_half,
	R_double,
	R_quad,
	RE_BACK
};
enum RotateType // returns action to rotate angle
{
	R_90,
	R_180,
	R_270,
	R_BACK
};
enum ZoominType // returns action to zoom in factor
{
	Z_125,
	Z_150,
	Z_175,
	Z_200,
	ZI_NO,
	ZI_BACK
};
enum ZoomoutType // returns action to zoom out factor
{
	Z_25,
	Z_50,
	Z_75,
	ZO_NO,
	ZO_BACK
};
struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif