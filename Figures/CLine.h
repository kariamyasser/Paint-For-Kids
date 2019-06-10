#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Point getfigcenter();
	CLine(Point , Point ,GfxInfo FigureGfxInfo );
	Point GetCorner1();
	Point GetCorner2();
	void SetCorner1(Point P);
	void SetCorner2(Point P);
	ShapeType  returntype() const;
	virtual void rotate(int angle);
	virtual void Load(ifstream &f);
	virtual void Draw(Output* pOut) const;
	virtual	bool checkpoint(Point p) const;
	virtual void resize(float n);
	virtual bool Dimchecker();
	virtual void Getdistance(Point P, int &dx, int &dy);
	void Move(int dx, int dy);			
	virtual CFigure * Copy( );
	virtual CFigure* Paste(int dx,int dy);
	virtual Point getpoint();
	void zoom(float n,Output* pOut);
	virtual void printinfo(Output* pOut) const;
 	virtual void DeleteFig(Output* pOut,float x) const;
	void Save(ofstream &out);
	
};

#endif
