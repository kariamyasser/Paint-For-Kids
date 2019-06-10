
#include "CCircle.h"

CCircle::CCircle(Point P1, int r, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)  //non default constructor
{
	Center = P1;
	radius = r;
	
	
}
void CCircle ::DeleteFig(Output* pOut, float zoom ) const
{
	Point z;
	int x;
	z.x=Center.x * zoom;
	z.y=Center.y * zoom;
	x=radius/zoom;
	pOut->DeleteCircle(z, x,FigGfxInfo);

}
void CCircle ::rotate(int angle)
	 {
		
	 }
Point CCircle ::getfigcenter()
	{
		return Center;
	}
int CCircle ::getarea() const
	{
		 float pi=3.1495;
	   float area=pi*radius*radius;
		return (int)area;

	}
void  CCircle :: Load(ifstream &f)
	{
		Selected=false;
		
		choosen=false;

		int z;
		f>>z;
		ID=count;
		
		f>>z;
		Center.x=z;
		f>>z;
		Center.y=z;
		f>>z;
		radius=z;
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
CFigure* CCircle::Copy()
	{
		
		CFigure *NewC= new CCircle(Center,radius,FigGfxInfo);
		return NewC;
	}
 CFigure * CCircle::Paste(int dx,int dy)
	 {
		
		 Center.x=Center.x+dx;
		 Center.y=Center.y+dy;
		 if (Dimchecker()==true)
		 {
		 CFigure*NewC= new CCircle(Center,radius,FigGfxInfo);
		 return NewC;
		 }
		 else
		 {
			
			 return NULL;
		 }
	 }
void CCircle::Getdistance(Point P, int &dx, int &dy)
	{
		dx=P.x-Center.x;
		dy=P.y-Center.y;
	}
void CCircle::Move( int dx, int dy)
	{
		Center.x=Center.x+dx;
		Center.y=Center.y+dy;
	}
bool CCircle :: Dimchecker()
   {
	   if(  Center.y>50 && Center.y-radius>50 && Center.y<650 && Center.y+radius<650 && Center.y-radius<650)
		   {return true;}
	   else{return false;}
   }
Point CCircle:: getpoint()
 {
	 return Center;
 }
Point CCircle::GetCenter()
	{
		return Center;
	}
int CCircle::GetRadias()
	{
		return radius;
	}
void CCircle::SetCenter(Point P)
	{
		Center=P;
	}
void CCircle::SetRadias(int P)
	{
		radius=P;
	}
ShapeType  CCircle::returntype() const
	{
		return CIRCLE;

	}
void CCircle::Draw(Output* pOut) const
{
	
		pOut->Drawcir(Center, radius, FigGfxInfo, Selected);
	
	
	//Call Output::DrawRect to draw a Circle on the screen	

}
bool CCircle::checkpoint(Point p) const
{
	
	
	if ((p.x-Center.x)*(p.x-Center.x)+(p.y-Center.y)*(p.y-Center.y)<radius*radius)
		
		return true;
	else 
		return false;
}
 void CCircle:: resize(float n)
 {
	 radius=n*radius;
 }
void CCircle:: zoom(float n,Output* pOut)
 {
	 Point z;
		z.x=(Center.x)*n;
	z.y=(Center.y)*n;
	
	 int x= n*radius;

	 pOut->Drawcir(z, x, FigGfxInfo, Selected);
 }
void CCircle::printinfo(Output* pOut) const
   {
	  
	  int area=getarea();
	     pOut->PrintMessage("Circle its",205);
	   pOut->PrintMessage("ID= ",280);
	   pOut->PrintNumber(ID,305);

	   pOut->PrintMessage("Center=(",330);
	   pOut->PrintNumber(Center.x,400);
	   pOut->PrintMessage(",",425);
	   pOut->PrintNumber(Center.y,430);
	   pOut->PrintMessage(")",455);
	     pOut->PrintMessage("Its radius= ",473);
		 pOut->PrintNumber(radius,560);
	   pOut->PrintMessage("Its area= ",593);
	   pOut->PrintNumber(area,665);
	
   }
void CCircle :: Save(ofstream &out)
	{
	
			out<<endl<<"Circle         " <<ID << "     "<<Center.x << "     "<<Center.y << "      " <<radius<<"      " <<FigGfxInfo.BorderWdth<< "      " <<ctos(FigGfxInfo.DrawClr) << "      " ;
		
			if(FigGfxInfo.isFilled== TRUE)
			{
			out<<ctos(FigGfxInfo.FillClr) ;
			}
			else
			{
			out<<"NO_FILL";
			}
   }