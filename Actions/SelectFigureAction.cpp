#include "SelectFigureaction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <iostream>
using namespace std;
SelectFigureAction::SelectFigureAction(ApplicationManager * pApp):Action(pApp)
{}

void SelectFigureAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Point to the shape you want to select");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	pOut->ClearStatusBar();

}

//Execute the action
void SelectFigureAction::Execute() 
{
   Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Point to the shape you want to select");
	while(true)
	{

	//This action needs to read some parameters first
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

     	int numberofseleced=0;
		CFigure*selected=NULL;
		bool flag;
	    pOut->ClearStatusBar();
	
	if (P1.y<50)
		{
			pOut->CreateDrawToolBar();
			break;
		}

	else
	{
		if (pManager->zoom_mode==true)
		{
			Point z;
			z.x = P1.x /pManager->zoom_factor;
			z.y = P1.y /pManager->zoom_factor;
			pManager->SelectFigure(z);
		}
		else{pManager->SelectFigure(P1);}
	flag=pManager->Checkselectednumber(numberofseleced,selected);
	if (flag)
	{
		pOut->PrintMessage("The type of this figure is");
		selected->printinfo(pOut);
	}
	else if (numberofseleced==0)
	{
		pOut->PrintMessage("Point to the shape you want to select");
		
	}
	else 
	{
		pOut->PrintMessage("Number of selected figure is");
		pOut->PrintNumber(numberofseleced,240);
	
	}
	}
	
	}
}
