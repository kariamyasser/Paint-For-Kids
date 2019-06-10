#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) //non default ctor
{
	Corner1 = P1;
	Corner2 = P2;
	
	
}
Point CRectangle ::getfigcenter()
	{
		Point p;

	float x=(Corner1.x+Corner2.x)/2;

	float y=(Corner1.y+Corner2.y)/2;
	p.x=x;
	p.y=y;
	return p;
	}
void CRectangle ::rotate(int angle)
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
void CRectangle::Getdistance(Point P, int &dx, int &dy)
	{
		dx=P.x-Corner1.x;
		dy=P.y-Corner1.y;
	}
void CRectangle::Move( int dx, int dy)
	{
		Corner1.x=Corner1.x+dx;
		Corner1.y=Corner1.y+dy;
		Corner2.x=Corner2.x+dx;
		Corner2.y=Corner2.y+dy;					
	}
CFigure* CRectangle::Copy( )
	 {
			CFigure *NewR= new CRectangle(Corner1,Corner2,FigGfxInfo);
		return NewR;	
	 }
 CFigure* CRectangle::Paste(int dx,int dy)
 {
	 Corner1.x=Corner1.x+dx;
	  Corner1.y=Corner1.y+dy;
	 Corner2.x=Corner2.x+dx;
	 Corner2.y=Corner2.y+dy;
	 if (Dimchecker()==true)
	 {

	 CFigure *NewR= new CRectangle(Corner1,Corner2,FigGfxInfo);
return NewR;	
	 }
	  else
		 {
			 
			 return NULL;
		 }
 }
void  CRectangle :: Load(ifstream &f)
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
		f>>s;
		if (s=="NO_FILL" ||s=="NO_CLR")
		{
			FigGfxInfo.isFilled=false;
		}
		else
		{
			FigGfxInfo.isFilled=true;
			FigGfxInfo.FillClr=stoc(s);
		}

	}
ShapeType  CRectangle::returntype() const
	{
		return RECTANGLE;
	}
int CRectangle:: getarea() const 
{
	int height;
		   int width;
		   if(Corner1.y>Corner2.y)
	       { 
			   height=Corner1.y-Corner2.y;
		   }
		   else 
		   { 
			   height=Corner2.y-Corner1.y;
		   } 
		    if(Corner1.x>Corner2.x)
	       { 
			  width=Corner1.x-Corner2.x;
		   }
		   else 
		   { 
			   width=Corner2.x-Corner1.x;
		   } 
				
			return height*width;

}
bool CRectangle :: Dimchecker()
	 {
		 if(   Corner1.y<50 || Corner2.y<50 ||  Corner1.y>650 || Corner2.y>650)
	{ return false;}
		 else {return true;}
	 }
Point CRectangle:: getpoint()
	{
		return Corner1;
	}
Point CRectangle::GetCorner1()
	{
		return Corner1;
	}
Point CRectangle::GetCorner2()
	{
		return Corner2;
	}
void CRectangle::SetCorner1(Point P)
	{
		Corner1=P;
	}
void CRectangle::SetCorner2(Point P)
	{
		Corner2=P;
	}
void CRectangle ::DeleteFig(Output* pOut,float zoom) const
{
	Point z,d;
	
	z.x=Corner1.x * zoom;
	z.y=Corner1.y * zoom;
	d.x=Corner2.x*zoom;
	d.y=Corner2.y*zoom;
	
	pOut->DeleteRect(z, d,FigGfxInfo);

}
void CRectangle::Draw(Output* pOut) const
{
	
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::checkpoint(Point p) const
{
	
	if(Corner1.y>Corner2.y && Corner2.y<p.y  && p.y<Corner1.y)
			{
				
				if(Corner1.x>Corner2.x && Corner2.x<p.x && p.x<Corner1.x)

					 	{  return true;}


				else if (Corner1.x<Corner2.x && Corner2.x>p.x   && p.x>Corner1.x)
						{   return true;}



			}
			else if (Corner1.y<Corner2.y && Corner2.y>p.y && p.y>Corner1.y)
			{
			if(Corner1.x>Corner2.x && Corner2.x<p.x && p.x<Corner1.x)

			{  return true;}

				else if (Corner1.x<Corner2.x && Corner2.x>p.x &&  p.x >Corner1.x)
					{   return true;}


			} 
	return false;

}
void CRectangle::resize(float n)
{
	Corner2.x=(Corner2.x-Corner1.x)*n+Corner1.x;
	Corner2.y=(Corner2.y-Corner1.y)*n+Corner1.y;
}
void CRectangle::zoom(float n,Output* pOut)
{
	Point z,f;
		z.x=(Corner1.x)*n;
	z.y=(Corner1.y)*n;
	f.x=(Corner2.x)*n;
	f.y=(Corner2.y)*n;
	pOut->DrawRect(z, f,FigGfxInfo, Selected);
}
void CRectangle::printinfo(Output* pOut) const
   {
	   
		   int height;
		   int width;
		   if(Corner1.y>Corner2.y)
	       { 
			   height=Corner1.y-Corner2.y;
		   }
		   else 
		   { 
			   height=Corner2.y-Corner1.y;
		   } 
		    if(Corner1.x>Corner2.x)
	       { 
			  width=Corner1.x-Corner2.x;
		   }
		   else 
		   { 
			   width=Corner2.x-Corner1.x;
		   } 
				
	  
			int area=height*width;
	     pOut->PrintMessage("Rectangle its",205);
	      pOut->PrintMessage("ID= ",323);
	     pOut->PrintNumber(ID,347);
  
	     pOut->PrintMessage("height= ",380);
		 pOut->PrintNumber(height,442);
	
	     pOut->PrintMessage("width= ",490);
		 pOut->PrintNumber(width,545);
	     pOut->PrintMessage("area= ",585);
	   pOut->PrintNumber(area,635);
	
   }
void CRectangle::Save(ofstream &out)
		{
	
			out<<endl<<"Rectangle      " <<ID << "     "<<Corner1.x << "     "<<Corner1.y << "      " <<Corner2.x << "     "<<Corner2.y<<"      " <<FigGfxInfo.BorderWdth << "      " <<ctos( FigGfxInfo.DrawClr) << "      " ;
			
			if(FigGfxInfo.isFilled== TRUE)
			{
			out<<ctos(FigGfxInfo.FillClr);
			}
			else
			{
			out<<"NO_FILL";
			}
		}