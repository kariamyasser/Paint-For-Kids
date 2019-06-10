#include "ChangeBckgndColorAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeBckgndColorAction::ChangeBckgndColorAction(ApplicationManager * pApp):Action(pApp)
{x=1;

}

void ChangeBckgndColorAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Choose the Bckgnd color");
	
	Sleep(1100);
	

	pOut->ClearStatusBar();
}

void ChangeBckgndColorAction::setBkGndcolor(color &newColor,ActionType newcolor)
{
	
		Output* pOut = pManager->GetOutput();
	switch (newcolor) //detects the new chosen color
			{
	case  GREENN:
		
		newColor = GREEN;
		pOut->PrintMessage("Green");
	
	Sleep(1100);
				break;
			case BLUEE:
		pOut->PrintMessage("Blue");
	
	Sleep(1100);				
		newColor = BLUE;
				
					 
				break;
			case BLACKK: 
						pOut->PrintMessage("Black");
	
	Sleep(1100);
		newColor = BLACK;
				
				break;
			case REDD:
						pOut->PrintMessage("Red");
	
	Sleep(1100);
				
		newColor = RED;
				
				
				break;
			case PURPLEE: 
						pOut->PrintMessage("Purple");
	
	Sleep(1100);
			newColor = PURPLE;
				
				break;
				case BACK:
							pOut->PrintMessage("Back to draw tool bar");
	

					x=0;
				pOut->CreateDrawToolBar();
				break;
			case  YELLOWW:
				
			newColor = YELLOW;
				
			break;
			
			
		}
}
//Execute the action
void ChangeBckgndColorAction::Execute() 
{
   Output* pOut = pManager->GetOutput();
	
   while(x!=0)
   {
	//This action needs to read some parameters first
	ReadActionParameters();
	
	 
		Input* pIn = pManager->GetInput();

		 ActionType newcolor=pIn->GetUserAction();
	setBkGndcolor(UI.BkGrndColor,newcolor); //sets the new background color
	if(pManager->nofill==true)  //changes the unfilled color with the new background color
	{
				
	

		UI.FillColor=UI.BkGrndColor;
	}
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
	
   }

pManager->saved=false;

}