#include "ChangeColorAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeColorAction::ChangeColorAction(ApplicationManager * pApp):Action(pApp)
{
x=1;}
void ChangeColorAction::setDrawcolor(color &newColor,ActionType newcolor)
{
	
	Output* pOut = pManager->GetOutput();

	switch (newcolor) //detects new color
			{
	case  GREENN:
		if (pManager->Thereselected()==true)
			pManager->Changeselectclr=GREEN;
		else 
		newColor = GREEN;
		
				break;
			case BLUEE:
				if (pManager->Thereselected()==true)
		pManager->	Changeselectclr=BLUE;
		else 
		newColor = BLUE;
				
			pManager->	UpdateInterface();	 
				break;
			case BLACKK: 
				if (pManager->Thereselected()==true)
			pManager->Changeselectclr=BLACK;
		else 
		newColor = BLACK;
				
				break;
			case REDD:

				if (pManager->Thereselected()==true)
			pManager->Changeselectclr=RED;
		else 
		newColor = RED;
				
				
				break;
			case PURPLEE: 
				if (pManager->Thereselected()==true)
					pManager->Changeselectclr=PURPLE;
		else 
			newColor = PURPLE;
				
				break;
				case BACK:
					x=0;
				pOut->CreateDrawToolBar();
				break;
			case  YELLOWW:
				if (pManager->Thereselected()==true)
		pManager->	Changeselectclr=YELLOW;
		else 
			newColor = YELLOW;
				
			break;
			
			
		}
}
void ChangeColorAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Choose the color");
	
	Sleep(1100);
	

	pOut->ClearStatusBar();
}

//Execute the action
void ChangeColorAction::Execute() 
{
   Output* pOut = pManager->GetOutput();
	
  while (x !=0)
	{//This action needs to read some parameters first
	ReadActionParameters();
		Input* pIn = pManager->GetInput();

	ActionType newcolor=pIn->GetUserAction();
	setDrawcolor(UI.DrawColor,newcolor);
	
	pManager->ChangeSelectedcolorFigure();
	
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
  }
  pManager->saved=false;

}