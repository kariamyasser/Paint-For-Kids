#include "CLine.h"
#include <iostream>
using namespace std;
CLine::CLine(Point P1, Point P2,GfxInfo FigureGfxInfo ):CFigure(FigureGfxInfo)  //non default ctor
{
	Corner1 = P1;
	Corner2 = P2;
	
}
Point CLine:: getpoint()
 {
	 return Corner1;
 }
Point CLine ::getfigcenter()
	{
		Point p;
	float x=abs((Corner1.x+Corner2.x))/2;	
	 float y=abs((Corner1.y+Corner2.y))/2;
	p.x=x;
	p.y=y;
	 return p;
	}
bool CLine :: Dimchecker()
 {
	 if(   Corner1.y<50 || Corner2.y<50 || Corner1.y>650 || Corner2.y>650)
	 {return false;}
	 else { return true;}
 }
void CLine ::rotate(int angle)
	 {
		
	  Point Center=getfigcenter();
	  if (angle==90)
	{
	  
	int Xp1=-(Corner1.y-Center.y)+Center.x;
	int Yp1=(Corner1.x-Center.x)+Center.y;
	int Xp2=-(Corner2.y-Center.y)+Center.x;
	int Yp2=(Corner2.x-Center.x)+Center.y;
		if ( Yp1 >= UI.ToolBarHeight && Yp1 < UI.height - UI.StatusBarHeight && Yp2 >= UI.ToolBarHeight && Yp2 < UI.height - UI.StatusBarHeight
		&& Xp1>=0 && Xp1<=UI.width  && Xp2>=0 && Xp2<=UI.width   )  //check that the rotated 
	{
		
		Corner1.x=Xp1;
		Corner1.y=Yp1;
		Corner2.x=Xp2;
		Corner2.y=Yp2;
	
	  }
	  return;
	}
		else if (angle==180)
		{
	
		int Xp1=-(Corner1.x-Center.x)+Center.x;
		int Yp1=-(Corner1.y-Center.y)+Center.y;
	
		int Xp2=-(Corner2.x-Center.x)+Center.x;
		 int Yp2=-(Corner2.y-Center.y)+Center.y;
	
		 if ( Yp1 >= UI.ToolBarHeight && Yp1 < UI.height - UI.StatusBarHeight && Yp2 >= UI.ToolBarHeight && Yp2 < UI.height - UI.StatusBarHeight
		&& Xp1>=0 && Xp1<=UI.width  && Xp2>=0 && Xp2<=UI.width   )  //check that the rotated 
	{
		
		Corner1.x=Xp1;
		Corner1.y=Yp1;
		Corner2.x=Xp2;
		Corner2.y=Yp2;
	}
	
	return;
  }
	  else if (angle==270)
	{
	
		int Xp1=(Corner1.y-Center.y)+Center.x;
	 int Yp1=-(Corner1.x-Center.x)+Center.y;
	
	int  Xp2=(Corner2.y-Center.y)+Center.x;
	int  Yp2=-(Corner2.x-Center.x)+Center.y;
		if ( Yp1 >= UI.ToolBarHeight && Yp1 < UI.height - UI.StatusBarHeight && Yp2 >= UI.ToolBarHeight && Yp2 < UI.height - UI.StatusBarHeight
		&& Xp1>=0 && Xp1<=UI.width  && Xp2>=0 && Xp2<=UI.width   )  //check that the rotated 
	{
		
		Corner1.x=Xp1;
		Corner1.y=Yp1;
		Corner2.x=Xp2;
		Corner2.y=Yp2;
	}
	
		return;
		}
		
		 }
CFigure * CLine::Paste(int dx,int dy)
 {
	 Corner1.x=Corner1.x+dx;
	  Corner1.y=Corner1.y+dy;
	 Corner2.x=Corner2.x+dx;
	 Corner2.y=Corner2.y+dy;
	 if (Dimchecker()==true)
	 {
	 CFigure* NewL=new CLine(Corner1,Corner2,FigGfxInfo);
	 return NewL;
	 }
	  else
		 {
			 
			 return NULL;
		 }
 }
CFigure * CLine::Copy( )
	{
		
		CFigure *NewL= new CLine(Corner1,Corner2,FigGfxInfo);
return NewL;	}
void CLine::Getdistance(Point P, int &dx, int &dy)
	 {
		 dx=P.x-Corner1.x;
		 dy=P.y-Corner1.y;
	 }
void CLine::Move(int dx, int dy)
				{
					Corner1.x=Corner1.x+dx;
										Corner1.y=Corner1.y+dy;
										Corner2.x=Corner2.x+dx;
										Corner2.y=Corner2.y+dy;
										
				}
void CLine ::DeleteFig(Output* pOut,float zoom) const
{
	Point z,d;
	
	z.x=Corner1.x * zoom;
	z.y=Corner1.y * zoom;
	d.x=Corner2.x*zoom;
	d.y=Corner2.y*zoom;
	pOut->DeleteLine(z, d,FigGfxInfo);

}
Point CLine::GetCorner1()
	{
		return Corner1;
	}
Point CLine::GetCorner2()
	{
		return Corner2;
	}
void CLine::SetCorner1(Point P)
	{
		Corner1=P;
	}
void CLine::SetCorner2(Point P)
	{
		Corner2=P;
	}
void CLine::Draw(Output* pOut) const
{
	
	//Call Output::DrawLine to draw a Line on the screen	
	pOut->Drawline(Corner1, Corner2,FigGfxInfo, Selected);
}
bool CLine::checkpoint(Point p) const
{
	int xc=p.x-Corner1.x;
	int yc=p.y-Corner1.y;
	int xl=Corner2.x-Corner1.x;
	int yl=Corner2.y-Corner1.y;
	int cross=xc*yl-yc*xl;	
	if (-300<cross && cross<300)
	return true;
	else 
		return false;
}
void CLine::resize(float n)
{
	Corner2.x=(Corner2.x-Corner1.x)*n+Corner1.x;
	Corner2.y=(Corner2.y-Corner1.y)*n+Corner1.y;
}
void CLine::zoom(float n,Output* pOut)
{
	Point z,f;
		z.x=(Corner1.x)*n;
	z.y=(Corner1.y)*n;
	f.x=(Corner2.x)*n;
	f.y=(Corner2.y)*n;

	pOut->Drawline(z, f,FigGfxInfo, Selected);
}
void CLine::printinfo(Output* pOut) const
   {
	   pOut->PrintMessage("Line its",205);
	   	   pOut->PrintMessage("ID= ",270);
	   pOut->PrintNumber(ID,295);

	   pOut->PrintMessage("it starts at=(",320);
	   pOut->PrintNumber(Corner1.x,415);
	   pOut->PrintMessage(",",445);
	   pOut->PrintNumber(Corner2.y,455);
	   pOut->PrintMessage(")",480);
	   pOut->PrintMessage("it ends at=(",495);
	   pOut->PrintNumber(Corner2.x,583);
	   pOut->PrintMessage(",",615);
	   pOut->PrintNumber(Corner2.y,620);
	   pOut->PrintMessage(")",645);
	  
	
	
   }
ShapeType  CLine::returntype() const
	{
		return LINE;

	}
void CLine:: Save(ofstream &out)
		{
	out<<endl<<"Line          " <<ID << "     "<<Corner1.x << "     "<<Corner1.y << "      " <<Corner2.x << "     "<<Corner2.y<<"      " <<FigGfxInfo.BorderWdth << "      " <<ctos(FigGfxInfo.DrawClr);
		}
void  CLine :: Load(ifstream &f)
	{
		
		Selected=false;
		
		choosen=false;
		int z;
		f>>z;
		ID=count;
		
		f>>z;
		Corner1.x=z;
		f>>z;
		Corner1.y=z;
		f>>z;
		Corner2.x=z;
		f>>z;
		Corner2.y=z;
		f>>z;
		FigGfxInfo.BorderWdth=z;
		string s;
		f>>s;
		FigGfxInfo.DrawClr=stoc(s);

	}