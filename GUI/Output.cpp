#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1700;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 58;
	
	UI.DrawColor = BLUE;	//Drawing color
	
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = WHITESMOKE; //LIGHTGOLDENRODYELLOW;	//Background color
	UI.FillColor = UI.BkGrndColor ;//Filling color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 2;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Team 7 ");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
// given functions to generate the new colours
void setCrntDrawColor(color x) 
{
	UI.DrawColor.ucBlue=x.ucBlue;
	UI.DrawColor.ucGreen=x.ucGreen;
	UI.DrawColor.ucRed=x.ucRed;
}	
	 void setCrntFillColor(color x) 
	 {
		 
	UI.FillColor.ucBlue=x.ucBlue;
	UI.FillColor.ucGreen=x.ucGreen;
	UI.FillColor.ucRed=x.ucRed;
		
	 }
	void setCrntBkColor(color x) 
	{
		
		UI.BkGrndColor.ucBlue=x.ucBlue;
		UI.BkGrndColor.ucGreen=x.ucGreen;
		UI.BkGrndColor.ucRed=x.ucRed;
	}

void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateResizeBar() const
{
	UI.InterfaceMode = MODE_RESIZE;

	
	string MenuItemImages[5];
	MenuItemImages[ITM_QUARTER] = "images\\MenuItems\\quarter.jpg";
	MenuItemImages[ITM_HALF] = "images\\MenuItems\\half.jpg";
	MenuItemImages[ITM_DOUBLE] = "images\\MenuItems\\double.jpg";
	MenuItemImages[ITM_QUAD]="images\\MenuItems\\forth.jpg";
	MenuItemImages[ITM_BACK7] = "images\\MenuItems\\return.jpg";


	//Draw menu item one image at a time
	for(int i=0; i<5; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
void Output:: CreateRotateToolBar() const
{
		UI.InterfaceMode = MODE_ROTATE;

	
	string MenuItemImages[4];
	MenuItemImages[ITM_90] = "images\\MenuItems\\90.jpg";
	MenuItemImages[ITM_180] = "images\\MenuItems\\180.jpg";
	MenuItemImages[ITM_270] = "images\\MenuItems\\270.jpg";
	MenuItemImages[ITM_BACK6]="images\\MenuItems\\return.jpg";
	

	//Draw menu item one image at a time
	for(int i=0; i<4; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output::CreateZoominToolBar() const
{
	UI.InterfaceMode = MODE_ZOOMIN;

	string MenuItemImages[6];
	MenuItemImages[ITM_BY125] = "images\\MenuItems\\25.jpg";
	MenuItemImages[ITM_BY150] = "images\\MenuItems\\50.jpg";
	MenuItemImages[ITM_BY175] = "images\\MenuItems\\75.jpg";
	MenuItemImages[ITM_BY200] = "images\\MenuItems\\100.jpg";
	MenuItemImages[ITM_NOZOOMIN] = "images\\MenuItems\\nozoom.jpg";

	MenuItemImages[ITM_BACK8] = "images\\MenuItems\\return.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<6; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}


void Output::CreateBorderToolBar() const
{
	UI.InterfaceMode = MODE_BORDERSIZE;

	string MenuItemImages[5];
	MenuItemImages[ITM_1] = "images\\MenuItems\\forth.jpg";
	MenuItemImages[ITM_2] = "images\\MenuItems\\double.jpg";
	MenuItemImages[ITM_3] = "images\\MenuItems\\half.jpg";
	MenuItemImages[ITM_4] = "images\\MenuItems\\quarter.jpg";
	MenuItemImages[ITM_BACK5] = "images\\MenuItems\\return.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<5;i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateZoomoutToolBar() const
{
	UI.InterfaceMode = MODE_ZOOMOUT;

	string MenuItemImages[5];
	MenuItemImages[ITM_BY25] = "images\\MenuItems\\25.jpg";
	MenuItemImages[ITM_BY50] = "images\\MenuItems\\50.jpg";
	MenuItemImages[ITM_BY75] = "images\\MenuItems\\75.jpg";
	
	MenuItemImages[ITM_NOZOOMOUT] = "images\\MenuItems\\nozoom.jpg";
	MenuItemImages[ITM_BACK9] = "images\\MenuItems\\return.jpg";

	

	//Draw menu item one image at a time
	for(int i=0; i<5; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////







void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_TRIAN] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_LINE]="images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_FILL_CLR]="images\\MenuItems\\fillcolor.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_CHNGCOLOR] = "images\\MenuItems\\drawcolor.jpg";
    MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\rotate.jpg";
	MenuItemImages[ITM_BK_CLR] = "images\\MenuItems\\backgroundcolor.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_ZOOM] = "images\\MenuItems\\zoom.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SWITCHMODE] = "images\\MenuItems\\playmode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";
	MenuItemImages[ITM_CHNG_BORDER]= "images\\MenuItems\\resizeborder.jpg";
	MenuItemImages[ITM_STB]= "images\\MenuItems\\send.jpg";
	MenuItemImages[ITM_BTF]= "images\\MenuItems\\bring.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateFillColorToolBar() const
{
	UI.InterfaceMode = MODE_FillCOLOUR;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[8];
	MenuItemImages[ITM_REDD] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_BLUEE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_BLACKK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_GREENN]="images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_YELLOWW]="images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_PURPLEE] ="images\\MenuItems\\purple.jpg";
	MenuItemImages[ITM_BACKK] = "images\\MenuItems\\return.jpg";
	MenuItemImages[ITM_NOFILL] = "images\\MenuItems\\no fill.jpg";
   
	//Draw menu item one image at a time
	for(int i=0; i<8; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
void Output::CreateColorToolBar() const
{
	UI.InterfaceMode = MODE_COLOUR;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[7];
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_GREEN]="images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_YELLOW]="images\\MenuItems\\yellow.jpg";
	MenuItemImages[ITM_PURPLE] ="images\\MenuItems\\purple.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\return.jpg";
	
   
	//Draw menu item one image at a time
	for(int i=0; i<7; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateHandPToolBar() const
{
	UI.InterfaceMode = MODE_HP;

	string MenuItemImages[5];
	MenuItemImages[ITM_TYPE] = "images\\MenuItems\\type.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\color.jpg";
	MenuItemImages[ITM_TYPEANDFILL] = "images\\MenuItems\\area.jpg";
	MenuItemImages[ITM_AREA]="images\\MenuItems\\areaa.jpg";
	MenuItemImages[ITM_BACK2]="images\\MenuItems\\return.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<5; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateSelectToolBar() const
{
	UI.InterfaceMode = MODE_SELECT;

	string MenuItemImages[1];

	MenuItemImages[ITM_BACK4]="images\\MenuItems\\ok.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<1; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}



void Output::CreateZoomToolBar() const
{
	UI.InterfaceMode = MODE_ZOOM;

	string MenuItemImages[5];
	MenuItemImages[ITM_ZOOMIN] = "images\\MenuItems\\zoomin.jpg";
	MenuItemImages[ITM_ZOOMOUT] = "images\\MenuItems\\zoomout.jpg";
	MenuItemImages[ITM_BACK3]="images\\MenuItems\\return.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<3; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[PLAY_ITM_COUNT];

	MenuItemImages[ITM_HIDE]="images\\MenuItems\\pick.jpg";
	MenuItemImages[ITM_SCRAMBLE]="images\\MenuItems\\scramble.jpg";
	MenuItemImages[ITM_SWITCHMODE2] = "images\\MenuItems\\drawmode.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth-2,0,UI.MenuItemWidth-2, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg,int size) const	//Prints a message on status bar
{
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(size, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
void Output::PrintMessage(string msg) const	//Prints a integar on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}

void Output::Drawint(const int x,const int y,const long lNumber )
{
	pWind->SetPen(GRAY, 50);
	pWind->SetFont(30, BOLD , BY_NAME, "Arial");   
	pWind->DrawInteger(x,y,lNumber);
}
void Output ::PrintNumber(int k,int size) const
{
	
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawInteger(size, UI.height - (int)(UI.StatusBarHeight/1.5), k);

}
void Output::Drawstring(const int x,const int y,string msg)
{
	pWind->SetPen(GRAY, 50);
	pWind->SetFont(30, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(x,y,msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
color Output:: getCrntBkColor() const
{
	return UI.BkGrndColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DeleteRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	
	RectGfxInfo.DrawClr = getCrntBkColor();
		DrawingClr=getCrntBkColor();
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(getCrntBkColor());
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DeleteLine(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	
		RectGfxInfo.DrawClr = getCrntBkColor();
		DrawingClr=getCrntBkColor();
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(getCrntBkColor());
	}
	else	
		style = FRAME;

	
	 pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
	
}
void Output::DeleteCircle(Point P, int radius, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	
		RectGfxInfo.DrawClr = getCrntBkColor();
		DrawingClr=getCrntBkColor();
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(getCrntBkColor());
	}
	else	
		style = FRAME;

	
	pWind->DrawCircle(P.x, P.y,radius, style);
	
}
void Output::DeleteTriangle(Point P1, Point P2, Point P3,GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	
		RectGfxInfo.DrawClr = getCrntBkColor();
		DrawingClr=getCrntBkColor();
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(getCrntBkColor());
	}
	else	
		style = FRAME;


	
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y,P3.x,P3.y, style);
	
}
void Output::cleartoolbar() const // function to empty the tool bar
{
	Point P1; Point P2; GfxInfo RectGfxInfo; 
	P1.x=0;
				P1.y=0;
				P2.x=1700;
				P2.y=50;
				RectGfxInfo.BorderWdth = 0;
				RectGfxInfo.DrawClr = WHITE;	//any color for border
				RectGfxInfo.isFilled = true;	//Figure is filled
	color DrawingClr;
	
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(WHITE);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawTria(Point P1, Point P2,Point P3, GfxInfo trianGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = trianGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, trianGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (trianGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(trianGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y,P3.x,P3.y, style);
	
}
void Output::Drawline(Point P1,Point P2,GfxInfo lineGfxInfo,bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = lineGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, lineGfxInfo.BorderWdth);	//Set Drawing color & width

   pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}
void Output::Drawcir(Point P,int radius, GfxInfo circGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = circGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, circGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (circGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(circGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawCircle(P.x, P.y,radius, style);
	
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

