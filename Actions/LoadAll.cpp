#include "LoadAll.h"

#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
LoadAll::LoadAll(ApplicationManager * pApp):Action(pApp)
{
}
color LoadAll:: stoc(string s)
		{
			
			 if(s=="PURPLE") return PURPLE;
			  if(s=="RED") return RED;
			   if(s=="BLUE") return BLUE;
			    if(s=="BLACK") return BLACK;
				 if(s=="YELLOW") return YELLOW;
				  if(s=="GREEN") return GREEN;
		
			 if( s== "NO_CLR" || s=="NO_FILL") 
				{
					
					return WHITESMOKE;
				 }

		}
void LoadAll::ReadActionParameters() 
{	
	
	prepareloading();
	
	
	
	//Get a Pointer to the Input / Output Interfaces
	 Output* pOut = pManager->GetOutput();
	
	pOut->PrintMessage("Please enter file name >>> ");
	Input * pIn=pManager->GetInput();
	s = pIn->GetSrting(pOut);
	pOut->PrintMessage("File Name >>> " +s);
	
	Sleep(1100);
	

	pOut->ClearStatusBar();

}

//Execute the action
void LoadAll::Execute() 
{
   

	//This action needs to read some parameters first
	ReadActionParameters();
	
	 Output* pOut = pManager->GetOutput();
	infile.open(s+".txt");

	if(infile.is_open()==true)
	{
	string x;
	
	infile>>x;
	
	UI.DrawColor=stoc(x);
	string fill;
	infile>>fill;
	
	
	
	infile>>x;
	UI.BkGrndColor=stoc(x);
		int n;
		infile>>n;
		UI.PenWidth=n;
		infile>>n;
		Point P1,P2,P3;
		P1.x=P1.y=P3.x=P3.y=P2.x=P2.y=100;
		GfxInfo g;
		color c;
		c.ucBlue=0;c.ucGreen=0;c.ucRed=0;
		g.DrawClr=c;
		g.FillClr=c;
		g.isFilled=false;
		g.BorderWdth=pOut->getCrntPenWidth();
			
		while (!infile.eof())
		{
			infile>>x;
			if (x=="Rectangle")
			{
				CRectangle *Fig=new CRectangle(P1,P2,g);
				
				Fig->Load(infile);
				
				pManager->AddFigure(Fig);
				if(infile.eof()) break;
				
			}
			else if (x=="Circle")
			{

				CCircle *Fig =new CCircle(P1,1,g);
				
				Fig->Load(infile);
				pManager->AddFigure(Fig);
				if(infile.eof()) break;
				
			}
			else if (x=="Triangle")
			{
					CTriangle *Fig =new CTriangle(P1,P2,P3,g);
						
					Fig->Load(infile);
				pManager->AddFigure(Fig);
				if(infile.eof()) break;
				
			}
			else if (x=="Line")
			{
				CLine* Fig =new CLine(P1,P2,g);
							
					Fig->Load(infile);
				pManager->AddFigure(Fig);
				if(infile.eof()) break;
			}

		
			
		}
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		
		if(fill=="NO_CLR")
	{
		pManager->nofill=true;
	}
	else
	{
		pManager->nofill=false;
	}
		
		UI.FillColor=stoc(fill);

		infile.close();
		pOut->PrintMessage("File Loaded Successfully ");

	}
	else {
			pOut->PrintMessage("File not loaded ... you didn't enter a correct file name ");
	}
pManager->saved=false;

}

void LoadAll:: prepareloading()
{
	  Output* pOut = pManager->GetOutput();
		Input * pIn=pManager->GetInput();
		if(pManager->saved==false)
	{
	pOut->PrintMessage("Do You Want to Save Your graph?? Yes or No");
	Sleep(1200);
	
	string s;
		pOut->PrintMessage("Please enter your choice >>> ");
		Sleep(1200);
	
	s = pIn->GetSrting(pOut);
	if (s=="Yes" || s=="YES"|| s=="yes"|| s=="y"|| s=="Y")
	{
		pOut->PrintMessage("Please enter file name >>> ");
	Sleep(1200);
	
	
	s = pIn->GetSrting(pOut);
	pOut->PrintMessage("File Name >>> " +s);
	
	Sleep(1200);
	pOut->ClearStatusBar();

	pManager->outfile.open(s+".txt");

	color x =pOut->getCrntDrawColor();
	color y = pOut->getCrntFillColor();
	color z =pOut->getCrntBkColor();
	pManager->outfile<<ctos(x)<<"        "<<ctos(y)<<"        "<<ctos(z)<<"  \n"<<pManager->getfigcount()<<"  \n";
	
	pManager->save();
	pManager->outfile.close();
	pManager->saved=true;
	pOut->PrintMessage("File SAVED");
	Sleep(1200);
	
	}

		}
		pManager->nofill=true;
		
		pManager->saved=true;
	pManager->DeleteAll();

	pOut->ClearDrawArea();
	
}
	

string LoadAll:: ctos(color x)
		{
			string s;
			if (x .ucBlue== PURPLE.ucBlue && x.ucGreen== PURPLE.ucGreen && x.ucRed== PURPLE.ucRed) { s="PURPLE"; return s;}
			else if (x .ucBlue== RED.ucBlue && x.ucGreen== RED.ucGreen && x.ucRed== RED.ucRed ) { s="RED"; return s;}
			else if (x .ucBlue== YELLOW.ucBlue && x.ucGreen==YELLOW.ucGreen && x.ucRed== YELLOW.ucRed){ s="YELLOW"; return s;}
			else if (x .ucBlue== BLUE.ucBlue && x.ucGreen==BLUE.ucGreen && x.ucRed== BLUE.ucRed) {s="BLUE"; return s;}
			else if (x .ucBlue== GREEN.ucBlue && x.ucGreen==GREEN.ucGreen && x.ucRed== GREEN.ucRed) {s="GREEN"; return s;}
			else if (x .ucBlue== BLACK.ucBlue && x.ucGreen==BLACK.ucGreen && x.ucRed== BLACK.ucRed) {s="BLACK"; return s;}
			else { s= "NO_CLR"; return s;}

		}
	
	

