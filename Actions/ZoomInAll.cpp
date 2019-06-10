#include "ZoomInAll.h"

#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ZoomInAll::ZoomInAll(ApplicationManager * pApp):Action(pApp)
{size=1;
}

void ZoomInAll::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input*pIn =pManager->GetInput();

	pOut->PrintMessage("Choose Zoom in  factor");
	ZoominType ReAct=pIn->GetUserZoominAction();
	switch(ReAct)
	{
	case Z_125 : size=1.25; pManager->zoom_mode=true; break;
	case Z_150 : size=1.5; pManager->zoom_mode=true;break;
	case Z_175 : size=1.75; pManager->zoom_mode=true; break;
	case Z_200 : size=2; pManager->zoom_mode=true;break;
	case ZI_NO: size=1; pManager->zoom_mode=false;break;
	case ZI_BACK: size=0;break;
	};
	

	pOut->ClearStatusBar();

}

//Execute the action
void ZoomInAll::Execute() 
{
		Output* pOut = pManager->GetOutput();
	
	while (size!=0)
	{

		ReadActionParameters();
		
		if (size ==0){
	
		pOut->ClearStatusBar();
		pOut->cleartoolbar();
		pOut->CreateZoomToolBar();
		
		pOut->ClearStatusBar();
		break;
	}
		else{
			pManager->zoom_factor=size;
				pOut->ClearDrawArea();
				pManager->UpdateInterface();
				pOut->ClearStatusBar();
	}
			pOut->PrintMessage("Graph zoomed in");
	
	Sleep(1100);
	}

	}
	