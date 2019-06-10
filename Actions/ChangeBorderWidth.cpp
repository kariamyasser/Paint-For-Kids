#include "ChangeBorderWidth.h"

#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeBorderWidth::ChangeBorderWidth(ApplicationManager * pApp):Action(pApp)
{x=1;}

void ChangeBorderWidth::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Choose the border width ");
	
	Sleep(1100);
	

	pOut->ClearStatusBar();
}

void ChangeBorderWidth::setwidth(int &width)
	{
		Output* pOut = pManager->GetOutput();
		
	Input* pIn = pManager->GetInput();
		ActionType newwidth=pIn->GetUserAction();
	switch (newwidth) //detects new font paramater
			{
	case FONT1 : 
		if (pManager->Thereselected()==true)
			pManager->ChangeselectBor=4;
		else 
		width*=4;
		

		break;
	case FONT2 : 
		if (pManager->Thereselected()==true)
			pManager->ChangeselectBor=2;
		else 
		width*=2;
					   
		break;
	case FONT3 : 

		if (pManager->Thereselected()==true)
			pManager->ChangeselectBor=0.5;
		else 
		width*=0.5;
		if (width<1) //to not convert the border to fractions 
			width=1;
		break;
	case FONT4:  
		if (pManager->Thereselected()==true)
			pManager->ChangeselectBor=0.25;
		else 
		width*=0.25;
		if (width<1) //to not convert the border to fractions 
			width=1;
			break;
	case BACK5: x=0;

				pOut->CreateDrawToolBar();
		break;
	}
	}


//Execute the action
void ChangeBorderWidth::Execute() 
{
   Output* pOut = pManager->GetOutput();

   while(x!=0){
	//This action needs to read some parameters first
	ReadActionParameters();
	
	
	
	setwidth(UI.PenWidth);
	if(x!=0)
	pManager->ChangeSelectedborderFigure();	
pOut->ClearDrawArea();
	pManager->UpdateInterface();
   }
   pManager->saved=false;

}