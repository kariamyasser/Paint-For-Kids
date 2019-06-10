#include "ChangeNoFill.h"
#include "Figures\CFigure.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

ChangeNoFill::ChangeNoFill(ApplicationManager * pApp):Action(pApp)
{}

void ChangeNoFill::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Choose the fill color");
	
	Sleep(1100);
	

	pOut->ClearStatusBar();
}

//Execute the action
void ChangeNoFill::Execute() 
{
   Output* pOut = pManager->GetOutput();
	

	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	
	//Add the rectangle to the list of figures
	pManager->setcolor(UI.FillColor);

	pManager->ChangeSelectedfillcolorFigure();	

    //FigGfxInfo.isFilled = true;
}