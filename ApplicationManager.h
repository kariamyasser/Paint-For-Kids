#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure *cut_copylist[MaxFigCount]; //clipboard
	int CountCut_Copy;		//counter for items in clipboard
	CFigure *ScrambleList[MaxFigCount]; //Scramble List
	int ScrambleCount; // Count of ScrambeList
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
public:	
	bool nofill;//to make the addedfigure filled 
	bool nofillselected;  //to make the selected figure filled 
	bool zoom_mode;		//checks whether we are in zoom mode or not
	float zoom_factor;		//the factor by which the graph is zoom
	color Changeselectclr; //for selected members only
	float ChangeselectBor; //for selected members only
	void AddFigureToList(CFigure *ptr);	//add figures to he list
	int getfigcount();//returns number of figs in figlist
	ofstream outfile;// the file to save the graph
	void Rotatefig(int angle);	//rotate figure
	ApplicationManager();		//constructor
	~ApplicationManager();		//destructor
	void setcountfig(int x);		//change no of figs in fig list
	void Move();		//move the figure
	void DrawMoved();		// drawing the moved figure after moving it	
	bool saved;			//checks whether the graph is saved or no
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	//Copy,Cut,Paste,Move Actions:
	void AddCopy();		//Add copies to the copy_cut list
	void DrawCut_Copy(); //draws the copied figs in the new coordinates
	void RemoveCut(); //remove the cut figs from fig list to cutcopy list
	void DeleteCut_copyList(); //deletes cutcopy list 
	void save();// saves the graph
	void AddFigureToFigList(CFigure *Fig);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void DeleteSelectedFigure(); //deletes selected figures
	void DeleteAll();//freeing all dynamic memories
	void SelectFigure(Point P); // select the figure
	bool Checkselectednumber(int &k,CFigure*&selected) const;// checks selected number
	CFigure *GetFigure(Point p) const; //Search for a figure given a point inside the figure
	void ResizeSelectedFigure(float ResizeFactor);		// resize selected figures
	void Bringtofront(CFigure*selectedfigure); // bring figure to front
    void Bringtoback(CFigure*selectedfigure);// send figure to back
	//////////////////////////////////////// PLay Mode Functions //////////////////////////////////////////////////////////////////////// 

	//--Pick And Hide 
	bool Typeoperation(CFigure *pointed,CFigure*specificfigure); //doing the operations specified to the Type mode 
	bool Type_Filloperation(CFigure *pointed,CFigure*specificfigure); //doing the operations specified to the Type &fill clr
	bool Filloperation(CFigure*pointed,CFigure*specificfigure); //doing the operations specified to the color mode 
	bool Areaoperation(CFigure*pointed,CFigure*specificfigure); //doing the operations specified to the area mode
	void TypeMode(Point P,CFigure*specificfigure);//Game mode of picking figure by type 
	void FillMode(Point P,CFigure *specificfigure); //Game mode of picking figure fill clr
	void Type_FillMode(Point P,CFigure *specificfigure);//Game mode of picking figure by type and fill clr
	void AreaMode(Point P,CFigure *specificfigure);//Game mode of picking figure by area 
	void ResetChoosen();// reset all choosen boolian flag for all figures
	int maxType(CFigure*specific) const;//gets the maximum number of the same type figures to the type specific figure also checks the validation of playing 
	int maxFill(CFigure*specific) const;//gets the maximum number of the same Filling figures to the fill of specific figurealso checks the validation of playing 
	int maxT_F(CFigure*specific) const;//gets the maximum number of the same Filling and type figures to the fill and type of specific figure also checks the validation of playing 
	bool DublicateArea() const;//checks the validation of playing if there more than one figure have the same area 
	/////////////////////////////////////////////////////
	//---Scramble and Find
	void Scramble(); //calls the game
	void AddToScrambleList(CFigure *ptr); //add a figure to scramble list
	void UpdateSInterface() const; //update the interface with respect to scramble list
	void SpreadFigs(); //puts the figs on the right and left of the screen 
	void ScramblePlay(); //the game
	CFigure *GetSFigure(Point p) const; // gets pointer to fig from scramblelist
	void DeleteHighlightedElement();//delete the highlighted elements 
	void DeleteScrambleList();// delete scramble list


	/////////////////////////////////////////////////////////////////////
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void ChangeSelectedborderFigure();//change selected figures border size
	bool Thereselected() const;	//check if there is any selected figs
	void ChangeSelectedcolorFigure();//changes the draw color for selected figs 
	void ChangeSelectedfillcolorFigure(); //changes fill color for selected figs

};

#endif