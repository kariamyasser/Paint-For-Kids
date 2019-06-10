#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	bool Highlighted;
	bool choosen;//checks if the figures choosen before or no and perform its action
	static int count; // counts number of figures in the graph
	GfxInfo FigGfxInfo;// graphics info of the figure
	
	/// Add more parameters if needed.

public:
		//Figure graphis info
	static void setcount(int x);//sets the static counter which determines the id
	CFigure(GfxInfo FigureGfxInfo); //constructor
	void SetSelected(bool s);	//select/unselect the figure
	virtual void rotate(int angle)=0;// rotate he figure by 90,180,270 degrees
	virtual void Move( int dx, int dy) =0;// move shape to a specific point
	virtual Point getfigcenter()=0; // returns center of the figure
	void SetGfx(GfxInfo G);// to set the gfx of the figure
	friend void AddFigureToList(CFigure *Ptr); 
	GfxInfo GetGfxInfo();// returns the gfx info
	virtual void Save(ofstream &out) = 0;	//Save the figure parameters to the file
	string ctos(color x); // transforms the color to string
	bool IsSelected() const;	//check whether fig is selected
	bool IsFilled() const;//check whether fig is filled
    virtual bool checkpoint(Point p) const =0;  //checks whether the point inside the figure or not
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void resize(float n)   = 0 ;	//resize the figure
	virtual void zoom(float n,Output* pOut)   = 0 ;	//zoom the figure in or out
	virtual void Load(ifstream &f)= 0 ;	//load graph
	color stoc (string s);// string to color
	virtual void Getdistance(Point P, int &dx, int &dy) =0;// returns distance with respect to  a specific point
	 bool ischoosen() ;//check whether fig is choosen for the play mode
	 void ChngDrawClr(color Dclr);	//changes the figure's drawing color
     void ChngFillClr(color Fclr);	//changes the figure's filling color
	 void ChngBorderWidth(int width);//changes the figure's border width
	 int GetBorderWidth() const;//function changes border width for shapes
	 void ChngNoFill();////changes the figure's filling color to no fill
     int getid() const ;// returns id of fig
	 void setid(int id) ;// set id of fig
	 virtual int getarea()const ;//get area of fig
	 void incCount(); //increamenting the count
	 int getCount()const;//get count 
	 bool CFigure::CompareFilled(CFigure*Pointed) const; //Compares the calling figure with the pointed figre with their filledclr
	 virtual CFigure* Copy() =0;//cpy figure to clipboard
	 virtual CFigure* Paste(int dx,int dy) =0; // return figures from clipboard to figlist
	virtual void printinfo(Output* pOut) const =0;//print figure information
	virtual Point getpoint()=0;// returns a specific point of the fig
	virtual bool Dimchecker() =0;// checks whether the dimensions is valid or not
	void setchoosen(bool s);// sets choosen boolean
	void SetHighlighted(bool s);
	bool  GetHighlighted();
	virtual void DeleteFig(Output* pOut, float x) const = 0;//delete fig from the graph by drawing a fig on it
	virtual ShapeType  returntype() const =0;// returns type of shape
};



#endif