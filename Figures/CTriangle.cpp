
#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3 , GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)  // non default ctor
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3= P3;

}
void CTriangle::SetCorner1(Point P)
{
	Corner1=P;
}

Point CTriangle :: getfigcenter()
{
	float x=(Corner1.x+Corner2.x)/2;	
	float y=(Corner1.y+Corner2.y)/2;
	
	float xnew= Corner3.x +(2*(x-Corner3.x))/3 ;
	float ynew= Corner3.y + (2*(y-Corner3.y))/3;
	Point p;
	p.x=xnew;
	p.y=ynew;
	return p;
}
  void CTriangle ::rotate(int angle)
	
  {
	 Point Center=getfigcenter();
	  if (angle==90)
	{
	  
	int Xp1=-(Corner1.y-Center.y)+Center.x;
	int Yp1=(Corner1.x-Center.x)+Center.y;
	int Xp2=-(Corner2.y-Center.y)+Center.x;
	int Yp2=(Corner2.x-Center.x)+Center.y;
	int Xp3=-(Corner3.y-Center.y)+Center.x;
	int Yp3=(Corner3.x-Center.x)+Center.y;
		if ( Yp1 >= UI.ToolBarHeight && Yp1 < UI.height - UI.StatusBarHeight && Yp2 >= UI.ToolBarHeight && Yp2 < UI.height - UI.StatusBarHeight
		&& Xp1>=0 && Xp1<=UI.width  && Xp2>=0 && Xp2<=UI.width   )  //check that the rotated 
	{
		
		Corner1.x=Xp1;
		Corner1.y=Yp1;
		Corner2.x=Xp2;
		Corner2.y=Yp2;
		Corner3.x=Xp3;
		Corner3.y=Yp3;
	  }
	  return;
	}
		else if (angle==180)
		{
	
		int Xp1=-(Corner1.x-Center.x)+Center.x;
		int Yp1=-(Corner1.y-Center.y)+Center.y;
	
		int Xp2=-(Corner2.x-Center.x)+Center.x;
		 int Yp2=-(Corner2.y-Center.y)+Center.y;
		int Xp3=-(Corner3.x-Center.x)+Center.x;
		 int Yp3=-(Corner3.y-Center.y)+Center.y;
	
		 if ( Yp1 >= UI.ToolBarHeight && Yp1 < UI.height - UI.StatusBarHeight && Yp2 >= UI.ToolBarHeight && Yp2 < UI.height - UI.StatusBarHeight
		&& Xp1>=0 && Xp1<=UI.width  && Xp2>=0 && Xp2<=UI.width   )  //check that the rotated 
	{
		
		Corner1.x=Xp1;
		Corner1.y=Yp1;
		Corner2.x=Xp2;
		Corner2.y=Yp2;
		
		Corner3.x=Xp3;
		Corner3.y=Yp3;
	}
	
	return;
  }
	  else if (angle==270)
	{
	
		int Xp1=(Corner1.y-Center.y)+Center.x;
	 int Yp1=-(Corner1.x-Center.x)+Center.y;
	
	int  Xp2=(Corner2.y-Center.y)+Center.x;
	int  Yp2=-(Corner2.x-Center.x)+Center.y;
		int  Xp3=(Corner3.y-Center.y)+Center.x;
	int  Yp3=-(Corner3.x-Center.x)+Center.y;
		if ( Yp1 >= UI.ToolBarHeight && Yp1 < UI.height - UI.StatusBarHeight && Yp2 >= UI.ToolBarHeight && Yp2 < UI.height - UI.StatusBarHeight
		&& Xp1>=0 && Xp1<=UI.width  && Xp2>=0 && Xp2<=UI.width   )  //check that the rotated 
	{
		
		Corner1.x=Xp1;
		Corner1.y=Yp1;
		Corner2.x=Xp2;
		Corner2.y=Yp2;
		
		Corner3.x=Xp3;
		Corner3.y=Yp3;
		}
	
		return;
		}
		
}	  

void CTriangle::Getdistance(Point P, int &dx, int &dy)
		{
			dx=P.x-Corner1.x;
			dy=P.y-Corner1.y;
		}
void CTriangle::Move( int dx, int dy)
		{
			Corner1.x=Corner1.x+dx;
			Corner1.y=Corner1.y+dy;
			Corner2.x=Corner2.x+dx;
			Corner2.y=Corner2.y+dy;
			Corner3.x=Corner3.x+dx;
			Corner3.y=Corner3.y+dy;
		}
void  CTriangle :: Load(ifstream& f)
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
		Corner3.x=z;
		f>>z;
		Corner3.y=z;
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
CFigure* CTriangle::Copy( )
	{
		
		CFigure *NewT= new CTriangle(Corner1,Corner2,Corner3,FigGfxInfo);
return NewT;	
}
 CFigure *CTriangle::Paste(int dx,int dy)
 {
	 Corner1.x=Corner1.x+dx;
	  Corner1.y=Corner1.y+dy;
	 Corner2.x=Corner2.x+dx;
	 Corner2.y=Corner2.y+dy;
	  Corner3.x=Corner3.x +dx;
	 Corner3.y=Corner3.y+dy;
	 if (Dimchecker()==true)
	 {
	 CFigure *NewT= new CTriangle(Corner1,Corner2,Corner3,FigGfxInfo);
return NewT;
	 }
	  else
		 {
			 return NULL;
		 }
 }
void CTriangle::SetCorner2(Point P)
{
	Corner2=P;
}
void CTriangle::SetCorner3(Point P)
{
	Corner3=P;
}
ShapeType CTriangle::returntype() const
	{
		return TRIANGLE;

	}
Point CTriangle:: GetCorner1()
	{
		return Corner1;
	}
Point CTriangle::GetCorner2()
	{
		return Corner2;
	}
Point CTriangle::GetCorner3()
	{
		return Corner3;
	}
void CTriangle::DeleteFig(Output* pOut,float zoom) const
{
	Point z,d,n;
	
	z.x=Corner1.x *zoom;
	z.y=Corner1.y * zoom;
	d.x=Corner2.x*zoom;
	d.y=Corner2.y*zoom;
	n.x=Corner3.x*zoom;
	n.y=Corner3.y*zoom;
	pOut->DeleteTriangle(z,d,n,FigGfxInfo);

}
void CTriangle::Draw(Output* pOut) const
{
	
	//Call Output::DrawRect to draw a rectangle on the screen
	pOut->DrawTria(Corner1, Corner2, Corner3, FigGfxInfo, Selected);

}
int CTriangle:: getarea(int x1,int y1,int x2,int y2,int x3,int y3) const
{
	int area=abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	
		return area;
	
}
bool CTriangle::checkpoint(Point p) const
{
	
	int x1=Corner1.x;
	int y1=Corner1.y;
	int x2=Corner2.x;
	int y2=Corner2.y;
	int x3=Corner3.x;
	int y3=Corner3.y;
	int x=p.x;
	int y=p.y;
		int areatotal=getarea(x1,y1,x2,y2,x3,y3);
		int area1=getarea(x,y,x2,y2,x3,y3);
		int area2=getarea(x1,y1,x,y,x3,y3);
		int area3=getarea(x1,y1,x2,y2,x,y);
	

	if (areatotal==area1+area2+area3)
	{return true;}
	else 
		{return false;}
}
void CTriangle::resize(float n)
{
	Corner2.x=(Corner2.x-Corner1.x)*n+Corner1.x;
	Corner2.y=(Corner2.y-Corner1.y)*n+Corner1.y;
	
	Corner3.x=(Corner3.x-Corner1.x)*n+Corner1.x;
	Corner3.y=(Corner3.y-Corner1.y)*n+Corner1.y;
}
void CTriangle::zoom(float n,Output* pOut)
{
	Point z,f,y;
	z.x=(Corner1.x)*n;
	z.y=(Corner1.y)*n;
	f.x=(Corner2.x)*n;
	f.y=(Corner2.y)*n;
	y.x=(Corner3.x)*n;
	y.y=(Corner3.y)*n;

	pOut->DrawTria(z, f,y,FigGfxInfo, Selected);
}
void CTriangle::printinfo(Output* pOut) const
   { 
	int base;
	int x1=Corner1.x;
	int y1=Corner1.y;
	int x2=Corner2.x;
	int y2=Corner2.y;
	int x3=Corner3.x;
	int y3=Corner3.y;
	int dist1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	int dist2=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
	int dist3=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
	if (dist1>dist2 && dist1>dist3)
	{
		base=sqrt(dist1);
	}
	else if (dist2>dist1 && dist2>dist3)
	{
		base=sqrt(dist2);
	}
	else
	{base=sqrt(dist3);}
	    
		 int area=(int)getarea(x1,y1,x2,y2,x3,y3)/2;
		   pOut->PrintMessage("Triangle its",205);
	     pOut->PrintMessage("ID= ",300);
	     pOut->PrintNumber(ID,325);
  
	     pOut->PrintMessage("height= ",350);
	     pOut->PrintNumber((area*2)/base,405);
	
	     pOut->PrintMessage("Its base= ",450);
		 pOut->PrintNumber(base,520);
	     pOut->PrintMessage("Its area= ",565);
	   pOut->PrintNumber(area,635);
	
	
   }
void CTriangle:: Save(ofstream &out)
		{
			out<< endl<<"Triangle       " <<ID << "     "<<Corner1.x << "     "<<Corner1.y << "      " <<Corner2.x << "     "<<Corner2.y << "      " <<Corner3.x << "     "<<Corner3.y <<"      " <<FigGfxInfo.BorderWdth <<"      " <<ctos(FigGfxInfo.DrawClr) << "      " ;
			
			if(FigGfxInfo.isFilled== TRUE)
			{
			out<<ctos(FigGfxInfo.FillClr);
			}
			else
			{
			out<<"NO_FILL";
			}
		}
int CTriangle:: getarea() const
	   {
		   int x1=Corner1.x;
	int y1=Corner1.y;
	int x2=Corner2.x;
	int y2=Corner2.y;
	int x3=Corner3.x;
	int y3=Corner3.y;
		 return getarea(x1,y1,x2,y2,x3,y3);
	   }
Point CTriangle:: getpoint()
	{
		return Corner1;
	}
bool CTriangle :: Dimchecker()
	   {
		   if(   Corner1.y<50 || Corner2.y<50 || Corner3.y<50 || Corner1.y>650 || Corner2.y>650 || Corner3.y>650)
		   {return false;}
		   else { return true;}
	   }