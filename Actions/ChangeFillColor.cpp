#include "ChangeFillColor.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager * pApp):Action(pApp)
{x=1;}

void ChangeFillColorAction::setFillcolor(color &newColor,ActionType newcolor)
{
	
	Output* pOut = pManager->GetOutput();

	switch (newcolor)  //detects new fill color
			{
	case  GREENN:
		if (pManager->Thereselected()==true)
		{

	pManager->		Changeselectclr=GREEN;
	pManager->	nofillselected=false;
		}
		else 
		{newColor = GREEN;
		pManager->	nofill=false;}
				break;
			case BLUEE:
				if (pManager->Thereselected()==true)
				{

			pManager->Changeselectclr=BLUE;
			pManager->	nofillselected=false;
				}
		else 
		{newColor = BLUE;
				
				pManager->	nofill=false;}
				break;
			case BLACKK: 
				if (pManager->Thereselected()==true)
			pManager->Changeselectclr=BLACK;
		else 
		{newColor = BLACK;
				pManager->	nofill=false;}
				break;
			case REDD:

				if (pManager->Thereselected()==true)
				{

			pManager->Changeselectclr=RED;
			pManager->	nofillselected=false;
				}
		else 
		{      newColor = RED;
				
				pManager->nofill=false;}
				break;
			case PURPLEE: 
				if (pManager->Thereselected()==true)
				{
					pManager->Changeselectclr=PURPLE;
					pManager->	nofillselected=false;
				}

		else 
		{	newColor = PURPLE;
				pManager->	nofill=false;}
				break;
				case BACK:
					x=0;
				pOut->CreateDrawToolBar();
				break;
			case  YELLOWW:
				if (pManager->Thereselected()==true)
				{
			pManager->Changeselectclr=YELLOW;
			pManager->	nofillselected=false;
				
				}
		else 
			{newColor = YELLOW;
				pManager->	nofill=false;}
			break;
			case NO_FILL: 
				if (pManager->Thereselected()==true)
				{
					pManager->	nofillselected=true;
				}
				else 
				{
					pManager->	nofill=true;
				}
			
				
				break;
			
		}
}

void ChangeFillColorAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Choose the fill color");
	
	Sleep(1100);
	

	pOut->ClearStatusBar();
}

//Execute the action
void ChangeFillColorAction::Execute() 
{
   Output* pOut = pManager->GetOutput();
	
   while(x!=0)
   {
	//This action needs to read some parameters first
	ReadActionParameters();
	
	Input* pIn = pManager->GetInput();

	ActionType newcolor=pIn->GetUserAction();
	
		
	setFillcolor(UI.FillColor,newcolor);

	pManager->ChangeSelectedfillcolorFigure();	
	
	pOut->ClearDrawArea();
	pManager->UpdateInterface();

	
   }
   pManager->saved=false;

}