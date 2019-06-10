#include "ResizeSelected.h"

#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ResizeSelected::ResizeSelected(ApplicationManager * pApp):Action(pApp)
{
	size=1;
}

void ResizeSelected::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input*pIn =pManager->GetInput();

	
	pOut->PrintMessage("Choose Resize factor");
	ResizeType ReAct=pIn->GetUserResizeAction();
	switch(ReAct)
	{
	case R_quarter : size=0.25; break;
	case R_half : size=0.5; break;
	case R_quad : size=4; break;
	case R_double : size=2; break;
	case RE_BACK: size=0; break;
	}
	

	pOut->ClearStatusBar();
}

//Execute the action
void ResizeSelected::Execute() 
{
	
		
	Output* pOut = pManager->GetOutput();
	
	while(size!=0)
	{
		
		ReadActionParameters();
		if (size ==0){
		
	
		pOut->ClearStatusBar();

		pOut->CreateDrawToolBar();
	}
		else{
			pOut->ClearDrawArea();
		
		pManager->ResizeSelectedFigure(size);
	}
			pOut->PrintMessage("Figures resized");
	
	Sleep(1100);
	}
		
	
pManager->saved=false;

	}
