
#ifndef CCIR_H
#define CCIR_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;	
	int radius;
	
public:
	Point GetCenter();
	int GetRadias(); 
	void SetCenter(Point P);
	void SetRadias(int P);
	CCircle(Point , int , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual	bool checkpoint(Point p) const;
	virtual void resize(float n);
	virtual void zoom(float n,Output* pOut) ;

	ShapeType  returntype() const;//fucntion return integer indicatiing type of figure test
	virtual void Load(ifstream &f);
	virtual void DeleteFig(Output* pOut,float x) const;
	virtual CFigure * Copy( );
	virtual CFigure* Paste(int dx,int dy);
	virtual void Save(ofstream &OutFile);
	virtual void printinfo(Output* pOut) const;
	virtual bool Dimchecker();
	virtual Point getpoint();
	virtual void Getdistance(Point P, int &dx, int &dy);
	virtual void Move( int dx, int dy);
	virtual void rotate(int angle);
	Point getfigcenter();
	virtual int getarea() const ;
};

#endif