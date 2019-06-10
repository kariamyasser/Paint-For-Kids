#include"Scramble.h"

#include "..\ApplicationManager.h"
ScrambleAction::ScrambleAction(ApplicationManager * pApp):Action(pApp)
{
}
void ScrambleAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->Scramble();
	pOut->ClearDrawArea();
		pManager->UpdateInterface();

	}
void ScrambleAction::Execute() 
{ 
					

	ReadActionParameters();
	
	 
	}