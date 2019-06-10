
#ifndef CTRIA_H
#define CTRIA_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	Point getfigcenter(); 
	Point GetCorner1();
	Point GetCorner2();
	Point GetCorner3();
	virtual void rotate(int angle);
	virtual void DeleteFig(Output* pOut,float x) const;
	void SetCorner1(Point P);
	void SetCorner2(Point P);
	void SetCorner3(Point P);
	ShapeType  returntype() const;
	virtual void Load(ifstream &f);
	CTriangle(Point , Point, Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual CFigure * Copy( );
	virtual CFigure* Paste(int dx,int dy);
	virtual	bool checkpoint(Point p) const;
	virtual int getarea() const;
	int getarea(int x1,int y1,int x2,int y2,int x3,int y3) const;
	virtual void resize(float n);
	virtual void zoom(float n,Output* pOut) ;
	virtual void printinfo(Output* pOut) const;
	void Save(ofstream &out);
	virtual bool Dimchecker();
	virtual void Getdistance(Point P, int &dx, int &dy);
	void Move( int dx, int dy);								
	 virtual Point getpoint();

};

#endif