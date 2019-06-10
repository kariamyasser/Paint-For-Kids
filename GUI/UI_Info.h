#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum Border_MODE		//border resize menu icons
{
	ITM_1,
	ITM_2,
	ITM_3,
	ITM_4,
	ITM_BACK5
};
enum ShapeType			//shape types
{
	RECTANGLE,
	TRIANGLE,
	CIRCLE,
	LINE

};
enum Zoomout_MODE //zoom out menu icons
{
	ITM_BY25,
	ITM_BY50,
	ITM_BY75,
	ITM_NOZOOMOUT,
	ITM_BACK9
};
enum Zoomin_MODE	//zoom in menu icons
{
	ITM_BY125,
	ITM_BY150,
	ITM_BY175,
	ITM_BY200,
	ITM_NOZOOMIN,
	ITM_BACK8
};
enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOUR, //list of items for color
	MODE_FillCOLOUR, //list of items for color + icon for return the fill
	MODE_HP, //list of items for pick and hand 
	MODE_ZOOM, //zoom toolbar
	MODE_SELECT,//select mode
	MODE_ZOOMIN,//zoomin factors toolbar
	MODE_ZOOMOUT,//zoom out factors toolbar
	MODE_RESIZE,//resize factors  toolbar
	MODE_BORDERSIZE,//bordersize factors toolbar
	MODE_ROTATE //rotate angles toolbar
};
enum ResizeMenuItem //The items of the Play menu 
{

	ITM_QUARTER,
	ITM_HALF,
	ITM_DOUBLE,
	ITM_QUAD,
	ITM_BACK7
	
	
};
enum RotateMenuItem //items for rotate menu
{
	ITM_90,
	ITM_180,
	ITM_270,
	ITM_BACK6
};
enum Select_MODE //to get out of select mode
{
	ITM_BACK4
};
enum ColorMenuItem //color lists
{

	ITM_RED,
	ITM_BLUE,
	ITM_BLACK,
	ITM_GREEN,
	ITM_YELLOW,
	ITM_PURPLE,

	ITM_BACK
	
};
enum FillColorMenuItem //color lists
{

	ITM_REDD,
	ITM_BLUEE,
	ITM_BLACKK,
	ITM_GREENN,
	ITM_YELLOWW,
	ITM_PURPLEE,
	ITM_NOFILL,
	ITM_BACKK
	
};
enum ZoomMenuItem // zoom menu items
{
	ITM_ZOOMIN,
	ITM_ZOOMOUT,
	ITM_BACK3
};
enum DrawMenuItem //The items of the Draw menu 
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_TRIAN, // TRIANGLE IN MENU
	ITM_LINE, // line
	ITM_SELECT,//select mode
	ITM_CHNGCOLOR,//change color 
	ITM_BK_CLR,//change background color
	ITM_FILL_CLR,//change fill color
	ITM_RESIZE,//resize toolbar
	ITM_CHNG_BORDER,//change border size menu
	ITM_ROTATE,//rotate figure
	ITM_STB,//send to back 
	ITM_BTF,//bring to front
	ITM_COPY,//copy menu item
	ITM_CUT,//cut menu item
	ITM_PASTE,//paste menu item
	ITM_ZOOM,//zoom menu item
	ITM_MOVE,// move 
	ITM_DELETE,//delete menu item
	ITM_SAVE,//save menu item
	ITM_LOAD,//load menu item
	ITM_SWITCHMODE,//switch to play mode
	
	//TODO: Add more items names here

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu 
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	ITM_HIDE,//pick and hide
	ITM_SCRAMBLE,//scramble and find
	ITM_SWITCHMODE2,//switch to draw mode
	ITM_EXIT2,		//Exit item
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PandHMenuItem //The items of the Pick and hide menu 
{

	ITM_TYPE,//type mode
	ITM_FILL,//fillcolor mode
	ITM_TYPEANDFILL,//fill and type mode
	ITM_AREA,		//area mode
	ITM_BACK2		//back to play mode
	
};

struct lastxcoord
{
	int x;

};

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif