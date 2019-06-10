#include "CFigure.h"
int CFigure:: count=1;
 void CFigure:: setcount(int x)
{
	count =x;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	
	choosen=false;
	
}
color CFigure:: stoc(string s)
		{
			
			 if(s=="PURPLE") return PURPLE;
			  if(s=="RED") return RED;
			   if(s=="BLUE") return BLUE;
			    if(s=="BLACK") return BLACK;
				 if(s=="YELLOW") return YELLOW;
				  if(s=="GREEN") return GREEN;
		
			 if( s== "NO_CLR" || s=="NO_FILL") 
				{
					color x;
					x.ucBlue=0;x.ucGreen=0;x.ucRed=0;
					return x;
				 }

		}
GfxInfo CFigure::GetGfxInfo() //getter for gfxinfo
	{
		return FigGfxInfo;
	}
int CFigure::getarea() const
{
	return 0;
}
void CFigure::SetSelected(bool s)
{	Selected = s; }
void CFigure::SetGfx(GfxInfo G)
		{
			FigGfxInfo=G;
		}
string CFigure:: ctos(color x)
		{
			string s;
			if (x .ucBlue== PURPLE.ucBlue && x.ucGreen== PURPLE.ucGreen && x.ucRed== PURPLE.ucRed) { s="PURPLE"; return s;}
			else if (x .ucBlue== RED.ucBlue && x.ucGreen== RED.ucGreen && x.ucRed== RED.ucRed ) { s="RED"; return s;}
			else if (x .ucBlue== YELLOW.ucBlue && x.ucGreen==YELLOW.ucGreen && x.ucRed== YELLOW.ucRed){ s="YELLOW"; return s;}
			else if (x .ucBlue== BLUE.ucBlue && x.ucGreen==BLUE.ucGreen && x.ucRed== BLUE.ucRed) {s="BLUE"; return s;}
			else if (x .ucBlue== GREEN.ucBlue && x.ucGreen==GREEN.ucGreen && x.ucRed== GREEN.ucRed) {s="GREEN"; return s;}
			else if (x .ucBlue== BLACK.ucBlue && x.ucGreen==BLACK.ucGreen && x.ucRed== BLACK.ucRed) {s="BLACK"; return s;}
			else { s= "NO_CLR"; return s;}

		}
bool CFigure::IsSelected() const  //check selected or not
{	return Selected; }
bool CFigure::IsFilled() const    //check filled or not

{	return FigGfxInfo.isFilled  ; }
void CFigure:: incCount()
{
	count++;
}
int CFigure:: getCount() const
{
	return count;
}
void CFigure::ChngDrawClr(color Dclr)  //change draw color
{	FigGfxInfo.DrawClr = Dclr; }
void CFigure::ChngFillClr(color Fclr)  //change the fill color 
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::ChngNoFill()    // change to unfill again
{	
	
	FigGfxInfo.isFilled = false;
	
}
bool CFigure::CompareFilled(CFigure*Pointed) const
{
	if (FigGfxInfo.isFilled==false)
	{
		if (Pointed->FigGfxInfo.isFilled==false)
			return true;
	}
	else
	{
		if (Pointed->FigGfxInfo.isFilled==false)
			return false ;
		if(FigGfxInfo.FillClr.ucBlue==Pointed->FigGfxInfo.FillClr.ucBlue && FigGfxInfo.FillClr.ucGreen==Pointed->FigGfxInfo.FillClr.ucGreen && FigGfxInfo.FillClr.ucRed==Pointed->FigGfxInfo.FillClr.ucRed )
			return true;

	}
	return false;
}
void CFigure::SetHighlighted(bool s)
			{
				Highlighted=s;
			}
bool  CFigure::GetHighlighted()
			{
				return Highlighted;
			}
void CFigure::ChngBorderWidth(int width) //function changes border width for shapes
{
	FigGfxInfo.BorderWdth=width;
}
int CFigure::GetBorderWidth() const//function changes border width for shapes
{
	return FigGfxInfo.BorderWdth;
}
void CFigure::setid(int id)
{
	ID=id;
}
int CFigure::getid() const
{
	return ID;
}
bool CFigure::ischoosen()
{
	
	return choosen;

}
void CFigure::setchoosen(bool s)
{
	choosen=s;

}
