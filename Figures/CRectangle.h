#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	
public:
	Point getfigcenter();
	Point GetCorner1();
	Point GetCorner2();
	void SetCorner1(Point P);
	void SetCorner2(Point P);
	virtual void rotate(int angle);
	void SetGfxInfo(GfxInfo G);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual	bool checkpoint(Point p) const;
	virtual void DeleteFig(Output* pOut,float x) const;
	void Save(ofstream &out);
	virtual void Getdistance(Point P, int &dx, int &dy);
	void Move( int dx, int dy);
	virtual CFigure * Copy( );
	virtual CFigure * Paste(int dx,int dy);
	virtual void Load(ifstream& f);
	virtual bool Dimchecker();
	virtual Point getpoint();
	virtual void resize(float n);
	virtual void zoom(float n,Output* pOut) ;
	virtual void printinfo(Output* pOut) const;
	ShapeType  returntype() const;
	virtual int getarea() const;
};
#endif