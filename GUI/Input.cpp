#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
		{	if (Label.size()>0)
		{	Label.resize(Label.size() -1 );
		
		}
		}
		else
			Label+= Key;
		pO->PrintMessage(Label);
	}
}



ResizeType Input::GetUserResizeAction()
{
	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_RESIZE)	//GUI in the DRAW mode
	{
		while  ( y > UI.ToolBarHeight)
		{
				pWind->WaitMouseClick(x, y);
		}
		
			int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
			{
		case QUARTER: return R_quarter;	
		case DOUBLEE: return R_double;
		case QUAD: return R_quad;
		case HALF : return R_half;
		case BACK7: return RE_BACK;
		};
	
	}
}

RotateType   Input::GetUserRotateAction()
{
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_ROTATE)	//GUI in the DRAW mode
	{
		while  ( y > UI.ToolBarHeight)
		{
				pWind->WaitMouseClick(x, y);
		}
		
			int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
			{
		case BY90: return R_90;	
		case BY180: return R_180;
		case BY270: return R_270;
		case BACK7 : return R_BACK;
			};
	
	}
}

ZoominType Input::GetUserZoominAction()
{
	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_ZOOMIN)	//GUI in the DRAW mode
	{
		while  ( y > UI.ToolBarHeight)
		{
				pWind->WaitMouseClick(x, y);
		}
		
			int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
			{
		case BY125: return Z_125;	
		case BY150: return Z_150;
		case BY175: return Z_175;
		case BY200 : return Z_200;
		case NO_ZOOMIN: return ZI_NO;
		case BACK8: return ZI_BACK;	};
	
	}
}

ZoomoutType Input::GetUserZoomoutAction()
{
	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_ZOOMOUT)	//GUI in the DRAW mode
	{
		while  ( y > UI.ToolBarHeight)
		{
				pWind->WaitMouseClick(x, y);
		}
		
			int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
			{
		case BY25: return Z_25;	
		case BY50: return Z_50;
		case BY75: return Z_75;
		case NO_ZOOMOUT: return ZO_NO;

		case BACK9: return ZO_BACK;	};
	
	}
}









//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRIAN:  return DRAW_TRI ;
			case ITM_SELECT: return SELECT;
			case ITM_CHNGCOLOR: return CHNG_DRAW_CLR; 
			case ITM_RESIZE: return RESIZE;
			case ITM_BK_CLR: return CHNG_BK_CLR; 
			case ITM_LINE: return DRAW_LINE;
			case ITM_CHNG_BORDER: return CHNG_BORDER;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT; 
			case ITM_PASTE: return PASTE; 
			case ITM_ZOOM: return ZOOM ;
			case ITM_MOVE: return MOVE;
			case ITM_DELETE: return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_FILL_CLR: return FILL_CLR;
			case ITM_SWITCHMODE: return TO_PLAY;
			case ITM_ROTATE: return ROTATE;
			case ITM_EXIT: return EXIT;	 
			case ITM_BTF: return BTF;
			case ITM_STB: return STB;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if(UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
	
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
	//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_HIDE: return TO_HIDE;
			case ITM_SCRAMBLE: return TO_SCRAMB;
			case ITM_SWITCHMODE2: return TO_DRAW;	
			case ITM_EXIT2: return EXIT;	
		
			
			
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		
}	else if(UI.InterfaceMode == MODE_ZOOM)	//GUI is in zoom mode
	{
	
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
	//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ZOOMIN: return ZOOMIN;
			case ITM_ZOOMOUT: return ZOOMOUT;
			case ITM_BACK3: return BACK3;	
		
			
			
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		
}

else if(UI.InterfaceMode == MODE_ROTATE)	//GUI is in zoom mode
	{
	
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
	//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_90: return BY90;
			case ITM_180: return BY180;
					case ITM_270: return BY270;
			case ITM_BACK6: return BACK6;	
		
			
			
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		
}
	


	
	else if(UI.InterfaceMode == MODE_ZOOMIN)	//GUI is in zoom mode
	{
	
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
	//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_BY125: return BY125;
			case ITM_BY150: return BY150;
			case ITM_BY175: return BY175;
			case ITM_BY200: return BY200;
			case ITM_NOZOOMIN: return NO_ZOOMIN;
			case ITM_BACK8: return BACK8;	
			
			
		
			
			
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		
}
	
	else if(UI.InterfaceMode == MODE_ZOOMOUT)	//GUI is in zoom mode
	{
	
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
	//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				case ITM_BY25: return BY25;
			case ITM_BY50: return BY50;
			case ITM_BY75: return BY75;
				
			case ITM_NOZOOMOUT: return NO_ZOOMOUT;
				case ITM_BACK9: return BACK9;	
		
		
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		
}
	else if(UI.InterfaceMode == MODE_RESIZE)	//GUI is in zoom mode
	{
	
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
	//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_QUARTER: return QUARTER;
			case ITM_HALF: return HALF;
			case ITM_DOUBLE: return DOUBLEE;
					case ITM_QUAD: return QUAD;
				case ITM_BACK7: return BACK7;	
		
		
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		
}
		
	else if(UI.InterfaceMode == MODE_BORDERSIZE)	//GUI is in zoom mode
	{
	
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		
	//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_1: return FONT1;
			case ITM_2: return FONT2;
			case ITM_3: return FONT3;
			case ITM_4: return FONT4;
			case ITM_BACK5: return BACK5;
		
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		
}

	else if(UI.InterfaceMode == MODE_HP){
		
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			
			case ITM_TYPE:	return TYPE;
			case ITM_FILL: return FILL;
			case ITM_TYPEANDFILL: return TYPEANDFILL;
			case ITM_AREA: return AREA;
			case ITM_BACK2:	return BACK2; 
			default: return EMPTY;	//A click on empty place in desgin toolbar
		
		
		
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return TO_PLAY;	//just for now. This should be updated
	}	

 }

		else if(UI.InterfaceMode == MODE_SELECT){
		
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			
			case ITM_BACK4:	return BACK4; 
			default: return EMPTY;	//A click on empty place in desgin toolbar
		
		
		
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return TO_DRAW;	//just for now. This should be updated
	}	

 }

	else if(UI.InterfaceMode == MODE_COLOUR)
	{
		
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			
			case ITM_BLUE:	return BLUEE;
			case ITM_BLACK: return BLACKK;
			case ITM_RED: return REDD;
			case ITM_PURPLE: return PURPLEE;
			case ITM_BACK:	return BACK;
			case ITM_YELLOW: return YELLOWW;
			case ITM_GREEN: return GREENN;
			default: return EMPTY;	//A click on empty place in desgin toolbar
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return TO_DRAW;	//just for now. This should be updated
	}	

 }
		else if(UI.InterfaceMode == MODE_FillCOLOUR)
	{
		
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			
			case ITM_BLUEE:	return BLUEE;
			case ITM_BLACKK: return BLACKK;
			case ITM_REDD: return REDD;
			case ITM_PURPLEE: return PURPLEE;
			case ITM_BACKK:	return BACK;
			case ITM_YELLOWW: return YELLOWW;
			case ITM_GREENN: return GREENN;
			case ITM_NOFILL: return NO_FILL;
			default: return EMPTY;	//A click on empty place in desgin toolbar
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return TO_DRAW;	//just for now. This should be updated
	}	

 }
}


/////////////////////////////////
	
Input::~Input()
{
}
