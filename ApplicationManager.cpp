#include "Allincludes.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	nofill=true;
	zoom_factor=1;
	ScrambleCount=0;
	zoom_mode=false;
	FigCount = 0;
		CountCut_Copy=0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	saved=true;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:         //draw rectangle
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			///AddLineAction here
			pAct= new AddlineAction(this);
			break;
		case DRAW_TRI: // draw triangle
			pAct= new AddTriaAction(this);
			break;
		case DRAW_CIRC:  // draw circle
			pAct= new AddcirAction(this);
			break;
		case BTF:
			pAct= new BringToFront(this);
			break;
		case STB:
			pAct= new SendToBack(this);
			break;
		
		case SELECT:
			pOut->cleartoolbar();
			pOut->CreateSelectToolBar();
			pAct=new SelectFigureAction(this);
			break;
		case DEL:
			if(Thereselected()==false)
         	{
	         	pOut->PrintMessage("No Selected Figures To Delete");
	         	Sleep(1100);
	         	pOut->ClearStatusBar();
		      return;
	        }
			pAct=new DeleteFigureAction(this);
			break;
		case EXIT:
			pAct=new ExitAction(this);
			
			break;
		case ZOOM:
			pOut->cleartoolbar();
			pOut->CreateZoomToolBar();
			break;
		case ZOOMIN:
			pOut->cleartoolbar();
			pOut->CreateZoominToolBar();
			pAct= new ZoomInAll(this);
			break;
		case LOAD:
			pAct=new LoadAll(this);
			break;
		case ZOOMOUT:
			pOut->cleartoolbar();
			pOut->CreateZoomoutToolBar();
			pAct= new ZoomOutAll(this);
			break;
		case RESIZE:

			if(Thereselected()==true)
			{
			pOut->cleartoolbar();
			pOut->CreateResizeBar();
			pAct=new ResizeSelected(this);
			}
			else
			{
				pOut->PrintMessage("No Figures Selected");
				Sleep(1100);
				pOut->ClearStatusBar();
			}

			
			break;
			
			case BACK3:
				
			
			pOut->cleartoolbar();
			pOut->CreateDrawToolBar();
			break;
				case CHNG_BORDER:    // Change Border width tool bar
					
			pOut->cleartoolbar();
			pOut->CreateBorderToolBar();
			pAct= new ChangeBorderWidth(this);
			break;
			case COPY:
			if (Thereselected()==false)  //no selected figures
	        {
	         	pOut->PrintMessage("No Selected Figure(s)");
		        Sleep(1100);
	            pOut->ClearStatusBar();
		        return;
	         }
			pAct=new CopyAction(this);
		
			break;
			case MOVE:
	 		if (Thereselected()==false)  //no selected figures 
             	{
	 	         pOut->PrintMessage("No Selected Figure(s)");
		         Sleep(1100);
	             pOut->ClearStatusBar();
		         return;
              	} 
				pAct=new MoveAction(this);
				break;
		case PASTE:
			if(CountCut_Copy==0)
			{
				pOut->PrintMessage("No Copied OR Cut Figure(s) in the Clipboard");
	         	Sleep(1100);
	            pOut->ClearStatusBar();
	           	return;
			}
			
			pAct=new PasteAction(this);
			break;
		case CUT:
			if (Thereselected()==false)  //no selected figures
	        {
	         	pOut->PrintMessage("No Selected Figure(s)");
		        Sleep(1100);
	            pOut->ClearStatusBar();
		        return;
	         }
			pAct= new CutAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
		case SAVE:
			pAct=new SaveAll(this);
			break; 

			case ITM_CHNGCOLOR:   //Change drawing color tool bar
		   pOut->cleartoolbar();
			pOut->CreateColorToolBar();
			pAct=new ChangeColorAction(this);
			break;
			case BACK:
				pOut->CreateDrawToolBar();
			break;
			case ITM_FILL_CLR:  // change fill color tool bar
				pOut->cleartoolbar();
			pOut->CreateFillColorToolBar();
			pAct=new ChangeFillColorAction(this);
			break;

			case ITM_BK_CLR:     //change back ground color tool bar
				pOut->cleartoolbar();
			pOut->CreateColorToolBar();
			pAct=new ChangeBckgndColorAction(this);

			break;


			case BACK5:  // return to tool bar
				pOut->cleartoolbar();
				pOut->CreateDrawToolBar();
				break;

			case TO_PLAY:
				pOut->cleartoolbar();
				pOut->CreatePlayToolBar();
				break;
			case TO_DRAW:
				pOut->cleartoolbar();
				pOut->CreateDrawToolBar();
				break;
			case BACK2:
				pOut->cleartoolbar();
				pOut->CreatePlayToolBar();
				break;
			case TO_HIDE:
				pOut->cleartoolbar();
				pOut->CreateHandPToolBar();
				pAct=new Pickandhideaction(this);
				break;
			case ROTATE:
			
				if(Thereselected()==true)
			{
				pOut->cleartoolbar();
				pOut->CreateRotateToolBar();
				pAct=new Rotate(this);
				}
				else
			{
				pOut->PrintMessage("No Figures Selected");
				Sleep(1100);
				pOut->ClearStatusBar();
			}
				
				break;
				case TO_SCRAMB:
				pAct=new ScrambleAction(this);
					break;
					
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
		if (nofill==false)
		{
			pFig->ChngFillClr( pOut->getCrntFillColor() );
		}
		FigList[FigCount++] = pFig;	
		FigList[FigCount-1]->setid(FigList[FigCount-1]->getCount());
		FigList[FigCount-1]->incCount();

		
}
}


void ApplicationManager::setcountfig(int x)
{
	FigCount=x;
}

void ApplicationManager::DeleteSelectedFigure()
{
	
	for (int i=0;i<FigCount;i++)
	{
		
		CFigure*deleted=NULL;
		if (FigList[i]->IsSelected()==true)
		{
		 if(FigCount==1)
		{
			deleted=FigList[i];
			
				CFigure::setcount(1);
			
			delete deleted;
			deleted=NULL;
			FigCount--;
			break;
		}
		
			deleted=FigList[i];
			FigList[i]=FigList[FigCount-1];
			delete deleted;
			FigCount--;
			int j=i;
			if (FigList[i]->IsSelected()==true)
			{
				i=j-1;
			}
			
		}
		
		pOut->ClearDrawArea();
		UpdateInterface();
	
	}
	
}
void ApplicationManager::DrawMoved()
{
	
	Point P;
	int dx,dy;
			pIn->GetPointClicked(P.x,P.y);
			for(int i=0 ; i<FigCount ; i++)
			{

				if(FigList[i]->IsSelected())
			{
					
				FigList[i]->Getdistance(P,dx,dy);
				break;
			}
			}

			for(int i=0 ; i<FigCount;i++)  //Loops on list of figures for cut
	{
		if(FigList[i]->IsSelected())
		{
			FigList[i]->Move(dx,dy);
		}
	}
			pOut->ClearDrawArea();
		UpdateInterface();
		
}
void ApplicationManager::DrawCut_Copy()
{
	
	Point P;
	int dx,dy;
			pIn->GetPointClicked(P.x,P.y);
			if(CountCut_Copy>0)
			{
					cut_copylist[0]->Getdistance(P,dx,dy);	
			}

			
	for(int i=0 ; i<CountCut_Copy;i++)  //Loops on list of figures for cut
	{
		CFigure*New=cut_copylist[i]->Paste(dx,dy);
		if (New!=NULL)
		AddFigure(New);
		else 
		{
			 pOut->PrintMessage("Invalid place to paste in it");
			 Sleep(500);
			 pOut->ClearStatusBar();
		}
	}
	
	

}
void ApplicationManager::AddFigureToFigList(CFigure *Fig)
{
	int C=CountCut_Copy;
	for (int i=0;i<C;i++)
	{
		
		CFigure*deleted=NULL;
	
			if(C==1)
		{
			deleted=cut_copylist[i];
			cut_copylist[i]->DeleteFig(pOut,zoom_factor);
			FigList[FigCount]=cut_copylist[i];
						FigCount++;
						C--;
			break;
		}
		
			deleted=cut_copylist[i];
			cut_copylist[i]->DeleteFig(pOut,zoom_factor);
			FigList[FigCount]=cut_copylist[i];
			FigCount++;
						cut_copylist[i]=cut_copylist[C-1];
			
						C--;
			int j=i;
			if (cut_copylist[i]->IsSelected()==true)
			{
				i=j-1;
			}
			
		}
	

	


	pOut->ClearDrawArea();
		UpdateInterface();
}

void ApplicationManager::RemoveCut()
{
		
	CountCut_Copy=0;
	
	for (int i=0;i<FigCount;i++)
	{

		
		CFigure*deleted=NULL;
		if (FigList[i]->IsSelected()==true)
		{
		 if(FigCount==1)
		{
			deleted=FigList[i];
			FigList[i]->DeleteFig(pOut,zoom_factor);
						cut_copylist[CountCut_Copy]=FigList[i];
						CountCut_Copy++;
			FigCount--;
			break;
		}
		
			deleted=FigList[i];
			FigList[i]->DeleteFig(pOut,zoom_factor);
			cut_copylist[CountCut_Copy]=FigList[i];
						CountCut_Copy++;
			FigList[i]=FigList[FigCount-1];
			
			FigCount--;
			int j=i;
			if (FigList[i]->IsSelected()==true)
			{
				i=j-1;
			}
			
		}
	}


	pOut->ClearDrawArea();
		UpdateInterface();
}
void ApplicationManager::AddCopy()
{
	
	
	CountCut_Copy=0;
	
	for (int i=0;i<FigCount;i++)
	{
		
		if (FigList[i]->IsSelected()==true)
		{
			CFigure *NewFig=FigList[i]->Copy();
			AddFigureToList(NewFig);
		
	}
	}
	
	pOut->ClearDrawArea();
		UpdateInterface();
}
	
void ApplicationManager::AddFigureToList(CFigure *ptr)
{
	if(CountCut_Copy<200)
	{
		cut_copylist[CountCut_Copy]=ptr;
		CountCut_Copy++;
	}
}

void ApplicationManager::DeleteCut_copyList()
{
	for(int i=0 ; i<CountCut_Copy;i++)
	{
		delete	cut_copylist[i];
		cut_copylist[i]=NULL;
		
		CountCut_Copy--;
	}
}
CFigure *ApplicationManager::GetFigure(Point p) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	///Add your code here to search for a figure given a point x,y
	
	
	for (int i=0;i<FigCount;i++)
	{
		
		bool flag;
		
		flag=FigList[i]->checkpoint(p);
		if(FigList[i]->ischoosen()==true)
			flag=false;
		if (flag==true)
		{return FigList[i];}
	
	}
	

	return NULL;
}
int ApplicationManager::getfigcount()
{
	return FigCount;
}
void ApplicationManager::save()
{
	for(int i=0; i<FigCount; i++)
		FigList[i]->Save(outfile);
}

void ApplicationManager::SelectFigure(Point P)
{
	CFigure*selectedfigure;
	bool flag;
	if (GetFigure(P)!=NULL)
	{
		selectedfigure=GetFigure(P);
	flag=selectedfigure->checkpoint(P);
			
		if (flag==true)
		{
			
		if (selectedfigure->IsSelected()==false)
		{selectedfigure->SetSelected(true);
		Bringtofront(selectedfigure);
		}
		else
			{selectedfigure->SetSelected(false);
		Bringtoback(selectedfigure);
		}
		
	}
		UpdateInterface();
	}

}
bool ApplicationManager:: Checkselectednumber(int &k,CFigure*&selected) const
{
	int firstone=0;

	for(int i=0; i<FigCount; i++)
	{
		
		if (FigList[i]->IsSelected()==true)
		{
			
			k++;
		}
		if (FigList[i]->IsSelected()==true && firstone==0)
		{
			selected=FigList[i];
			firstone=1; //not zero;
		}
		
	}
	if(k==1)
		{
			return true;
		}
		else
		{

			return false;
		}


}
bool ApplicationManager::Thereselected() const
{
	for(int i=0; i<FigCount; i++)
	{
		
		if (FigList[i]->IsSelected()==true)
		{
			return true;
		}
	}
	return false;

}

void ApplicationManager::DeleteAll()
{
	for (int i=0;i<FigCount;i++)
	{
		FigList[i]->SetSelected(true);
	}
	DeleteSelectedFigure();
	DeleteCut_copyList();
}

void ApplicationManager::ChangeSelectedcolorFigure()  // function change the border color for the selected drawn figures only
{
	for (int i=0;i<FigCount;i++)
		if (FigList[i]->IsSelected()==true)   //check wether selected or not
			FigList[i]->ChngDrawClr(Changeselectclr );  
}
void ApplicationManager::ChangeSelectedborderFigure()  // function change the border width for the selected drawn figures only
{
	int NewBorder;
	for (int i=0;i<FigCount;i++)
		if (FigList[i]->IsSelected()==true)
		{
			NewBorder=(int)FigList[i]->GetBorderWidth()* ChangeselectBor;
			if(NewBorder<1)//to not convert the border to fractions 
				NewBorder=1;
	       FigList[i]->ChngBorderWidth(NewBorder);
		}
}
void ApplicationManager::ChangeSelectedfillcolorFigure()   // function change the fill color for the selected drawn figures only
{
	for (int i=0;i<FigCount;i++)
	{
		if (FigList[i]->IsSelected()==true && nofillselected==false) //if nofill is not choosen -> change fill color
			FigList[i]->ChngFillClr( Changeselectclr );
	else if (FigList[i]->IsSelected()==true && nofillselected==true)  // if nofill is chosen -> change to no fill 
		FigList[i]->ChngNoFill();
	}
}
void ApplicationManager::Rotatefig(int angle)
{
	{
	for (int i=0;i<FigCount;i++)
	{
	
		if (FigList[i]->IsSelected()==true)
		{
			FigList[i]->rotate(angle);
		}
	}
	UpdateInterface();
	}
}
//////////////////////// play mode functions /////////////////////////////////////////////////////////////


//--Pick and hide

int ApplicationManager::maxType(CFigure*specific) const
{
	int max=0;
	for (int i=0;i<FigCount;i++)
	{
		if(FigList[i]->returntype()==specific->returntype())
		{
			max++;
		}

	}
	return max-1;
}
int ApplicationManager::maxFill(CFigure*specific) const
{
	int max=0;
	for (int i=0;i<FigCount;i++)
	{
		if (FigList[i]->returntype()==LINE) //no play with fillclr in lines
		{
			FigList[i]->DeleteFig(pOut,zoom_factor);
			FigList[i]->setchoosen(true);
			pOut->ClearDrawArea();
			UpdateInterface();
			 
			continue;
		}
		if(specific->CompareFilled(FigList[i])==true)
		{
			max++;
		}
		

	}
	return max-1;
}
int ApplicationManager::maxT_F(CFigure*specific) const
{
	int max=0;
	for (int i=0;i<FigCount;i++)
	{
		if (FigList[i]->returntype()==LINE) //no play with fillclr in lines
		{
			FigList[i]->DeleteFig(pOut,zoom_factor);
			FigList[i]->setchoosen(true);
			pOut->ClearDrawArea();
			UpdateInterface();
			continue;
		}
		if(specific->CompareFilled(FigList[i])==true && specific->returntype()==FigList[i]->returntype())
		{
			max++;
		}

	}
	return max-1;
}
bool ApplicationManager::DublicateArea()const
{
	
	for (int i=0;i<FigCount;i++)
	{
		for (int j=i+1;j<FigCount;j++)
		{
			if(FigList[i]->returntype()==FigList[j]->returntype() )
		{

			if(FigList[i]->getarea()==FigList[j]->getarea())  //if there shapes have same area  then invalid playing with area 
			{
			return true;
			}
		}
		
	}

	}
	return false;
}
void ApplicationManager:: ResetChoosen()
{
	for (int i=0;i<FigCount;i++)
	{
		FigList[i]->setchoosen(false);
	}
}
bool ApplicationManager::Typeoperation(CFigure*pointed,CFigure*specificfigure)
{

	if (pointed->returntype()==specificfigure->returntype())
				{
					if (pointed->ischoosen()!=true)
					{
						pointed->DeleteFig(pOut,zoom_factor);
						pointed->setchoosen(true);
						UpdateInterface();
						return true;
					}
					
				}
	
	return false ;
}
bool ApplicationManager::Filloperation(CFigure*pointed,CFigure*specificfigure)
{
	
	if (specificfigure->CompareFilled(pointed)==true)
				{
					if (pointed->ischoosen()!=true)
					{
						pointed->DeleteFig(pOut,zoom_factor);
						
						pointed->setchoosen(true);
						UpdateInterface();
						return true;
					}
	             }
	
	return false ;
					
	
}
bool ApplicationManager::Areaoperation(CFigure*pointed,CFigure*specificfigure)
{
	CFigure*nextchoosen;
		int smallest=0;
	bool flag=false ;//true is smallest and false if largest 
	for (int i=0;i<FigCount;i++)
	{
		
		if(FigList[i]->returntype()==specificfigure->returntype())
		{

			if (FigList[i]->getarea()>specificfigure->getarea() && FigList[i]->ischoosen()==false)
			{
				nextchoosen=FigList[i];
				flag=true;//figure was smallest
				 smallest=1;
			}

			if (FigList[i]->getarea()<specificfigure->getarea() && FigList[i]->ischoosen()==false)
			{
				nextchoosen=FigList[i];
			}
	    }
	}
		if (flag==true) //case if choosen was the smallest
		{
			
			for (int i=0;i<FigCount;i++)
	{
		
		if(FigList[i]->returntype()==specificfigure->returntype())
		{
			if (FigList[i]->getarea()<=nextchoosen->getarea() && FigList[i]->ischoosen()==false)
				nextchoosen=FigList[i];
	    }


		}

	}
		else 
		{

			
			for (int i=0;i<FigCount;i++)
	{
		
		if(FigList[i]->returntype()==specificfigure->returntype())
		{
			if (FigList[i]->getarea()>=nextchoosen->getarea() && FigList[i]->ischoosen()==false)
				nextchoosen=FigList[i];


		}
			}
		}
		if (pointed==nextchoosen)
				{
					if (pointed->ischoosen()!=true)
					{
						pointed->DeleteFig(pOut,zoom_factor);
						pointed->setchoosen(true);
						UpdateInterface();
						return true;
					}
					
				}
	
	return false ;
	
}
bool ApplicationManager::Type_Filloperation(CFigure*pointed,CFigure*specificfigure)
{

	if (pointed->returntype()==specificfigure->returntype() && specificfigure->CompareFilled(pointed)==true )
				{
					if (pointed->ischoosen()!=true)
					{
						pointed->DeleteFig(pOut,zoom_factor);
						pointed->setchoosen(true);
						UpdateInterface();
						return true;
					}
					
				}
	
	return false ;
}
void ApplicationManager::TypeMode(Point P,CFigure *specificfigure)
{
		CFigure*pointed;
		int valid=0;
		int invalid=0;
		int checkvalid=0;
		bool checker;
		checkvalid=maxType(specificfigure);
				if(checkvalid==0)
				{
					ResetChoosen();
					pOut->PrintMessage("Error There is no any Figure have the same type of the specific figure try choosing another type,click any where to back again ");
					pIn->GetPointClicked(P.x, P.y);
					return;
				}
	while (true)
			{
			
				
			pIn->GetPointClicked(P.x, P.y);
				if (zoom_mode==true)
		{
			Point z;
			z.x = P.x /zoom_factor;
			z.y = P.y /zoom_factor;
			pointed=GetFigure(z);
		}
		else{pointed=GetFigure(P);}
			
			if (pointed!=NULL && pointed!=specificfigure)
			{
					Beep (900,200);
			Sleep(125);
				checker=Typeoperation(pointed,specificfigure);
				if (checker==true)
				{
					valid++;
				}
				else
				{ 
					invalid++;
				}
				pOut->PrintMessage("Number of valid picks is");
				pOut->PrintNumber(valid,200);
				pOut->PrintMessage("Number of invalid picks is",230);
				pOut->PrintNumber(invalid,430);
				
				if(checkvalid==valid)
				{
					UpdateInterface();
					pOut->Drawstring(600,50,"your grade is");
					int grade=100*checkvalid;
					pOut->Drawint(770,50,(grade/(valid+invalid)));
					pOut->Drawstring(815,50,"/100");
			
					
					if (grade/(valid+invalid) > 60 )
					{
						mciSendString("open \"cheer.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					else
					{
						mciSendString("open \"boo.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					
					pOut->PrintMessage("Click any where to Restart to Pick & Hide Mode",460);
					pIn->GetPointClicked(P.x, P.y);
					
					break;
					
					
				}
			}
			if (P.y<50)
				break;
		UpdateInterface();
	
			}

}
void ApplicationManager::FillMode(Point P,CFigure *specificfigure)
{
		CFigure*pointed;
		int valid=0;
		int invalid=0;
		int checkvalid=0;
		bool checker;
		checkvalid=maxFill(specificfigure);
				if(checkvalid==0)
				{
					pOut->PrintMessage("Error There is no any Figure have the same Fill colour of the specific figure try choosing another Figure,click any where to back again ");
					pIn->GetPointClicked(P.x, P.y);
					return;
				}
	while (true)
			{
			
					
			pIn->GetPointClicked(P.x, P.y);
			if (zoom_mode==true)
		{
			Point z;
			z.x = P.x /zoom_factor;
			z.y = P.y /zoom_factor;
			pointed=GetFigure(z);
		}
		else{pointed=GetFigure(P);}
			if (pointed!=NULL)
			{
					Beep (900,200);
			Sleep(125);
				checker=Filloperation(pointed,specificfigure);
				if (checker==true)
				{
					valid++;
				}
				else
				{ 
					invalid++;
				}
				pOut->PrintMessage("Number of valid picks is");
				pOut->PrintNumber(valid,200);
				pOut->PrintMessage("Number of invalid picks is",230);
				pOut->PrintNumber(invalid,430);
				
				if(checkvalid==valid)
				{
					UpdateInterface();
					pOut->Drawstring(600,50,"your grade is");
					int grade=100*checkvalid;
					pOut->Drawint(770,50,(grade/(valid+invalid)));
					pOut->Drawstring(815,50,"/100");
					
					
					if (grade/(valid+invalid) > 60 )
					{
						mciSendString("open \"cheer.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					else
					{
						mciSendString("open \"boo.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					
					pOut->PrintMessage("Click any where to Restart to Pick & Hide Mode",460);
					pIn->GetPointClicked(P.x, P.y);
					
					break;
					
					
				}
			}
			if (P.y<50)
				break;
	
			}

}
void ApplicationManager::Type_FillMode(Point P,CFigure *specificfigure)
{
		CFigure*pointed;
		int valid=0;
		int invalid=0;
		int checkvalid=0;
		bool checker;
		checkvalid=maxT_F(specificfigure);
				if(checkvalid==0)
				{
					ResetChoosen();
					pOut->PrintMessage("Error There is no any Figure have the same type and fill clr of the specific figure try choosing another type,click any where to back again ");
					pIn->GetPointClicked(P.x, P.y);
					return;
				}
	while (true)
			{
				
				
			pIn->GetPointClicked(P.x, P.y);
			if (zoom_mode==true)
		{
			Point z;
			z.x = P.x /zoom_factor;
			z.y = P.y /zoom_factor;
			pointed=GetFigure(z);
		}
		else{pointed=GetFigure(P);}
			if (pointed!=NULL && pointed!=specificfigure)
			{
					Beep (900,200);
			Sleep(125);
				checker=Type_Filloperation(pointed,specificfigure);
				if (checker==true)
				{
					valid++;
				}
				else
				{ 
					invalid++;
				}
				pOut->PrintMessage("Number of valid picks is");
				pOut->PrintNumber(valid,200);
				pOut->PrintMessage("Number of invalid picks is",230);
				pOut->PrintNumber(invalid,430);
				
				if(checkvalid==valid)
				{
					UpdateInterface();
					pOut->Drawstring(600,50,"your grade is");
					int grade=100*checkvalid;
					pOut->Drawint(770,50,(grade/(valid+invalid)));
					pOut->Drawstring(815,50,"/100");
					
					
					if (grade/(valid+invalid) > 60 )
					{
						mciSendString("open \"cheer.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					else
					{
						mciSendString("open \"boo.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					
					pOut->PrintMessage("Click any where to Restart to Pick & Hide Mode",460);
					pIn->GetPointClicked(P.x, P.y);
					
					break;
					
					
				}
			}
			if (P.y<50)
				break;
		UpdateInterface();
	
			}

}
void ApplicationManager::AreaMode(Point P,CFigure *specificfigure)
{
		CFigure*pointed;
		int valid=0;
		int invalid=0;
		int checkvalid=0;
		bool checker;  
		checkvalid=maxType(specificfigure);
				if(checkvalid==0)
				{

					ResetChoosen();
					pOut->PrintMessage("Error There is no any Figure have the same type of the specific figure in order to compare area,Click any where to choose another mode  ");
					pIn->GetPointClicked(P.x, P.y);
					return;
				}
				if (DublicateArea()==true)
				{
					ResetChoosen();
					pOut->PrintMessage("Error There are figures have the same area invalid playing with area mode,Click any where to choose another mode  ");
					pIn->GetPointClicked(P.x, P.y);
					return;
				}
	while (true)
			{
			
			pIn->GetPointClicked(P.x, P.y);
			if (zoom_mode==true)
		{
			Point z;
			z.x = P.x /zoom_factor;
			z.y = P.y /zoom_factor;
			pointed=GetFigure(z);
		}
		else{pointed=GetFigure(P);}
			if (pointed!=NULL && pointed!=specificfigure)
			{
						Beep (900,200);
			Sleep(125);				
				checker=Areaoperation(pointed,specificfigure);
				if (checker==true)
				{
					valid++;
				}
				else
				{ 
					invalid++;
				}
				pOut->PrintMessage("Number of valid picks is");
				pOut->PrintNumber(valid,200);
				pOut->PrintMessage("Number of invalid picks is",230);
				pOut->PrintNumber(invalid,430);
				
				if(checkvalid==valid)
				{
					UpdateInterface();
					pOut->Drawstring(600,50,"your grade is");
					int grade=100*checkvalid;
					pOut->Drawint(770,50,(grade/(valid+invalid)));
					pOut->Drawstring(815,50,"/100");
					
					if (grade/(valid+invalid) > 60 )
					{
						mciSendString("open \"cheer.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					else
					{
						mciSendString("open \"boo.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					
					
					pOut->PrintMessage("Click any where to Restart to Pick & Hide Mode",460);
					pIn->GetPointClicked(P.x, P.y);
					
					break;
					
					
				}
			}
			if (P.y<50)
				break;
		UpdateInterface();
	
			}

}
////////////////////////////////////////////////////////////////////////////////////

//--Scrumbe and Find

void ApplicationManager::Scramble()
{
	SpreadFigs();
	ScramblePlay();
}
void ApplicationManager::ScramblePlay()
	try 
{
	
	int i=0;
	Point P;
	int Fail=0; int Succ=0;
	CFigure *fig;
	int C=ScrambleCount;
	if(ScrambleCount!=0)
	{
	int Turn=0+ rand()%ScrambleCount/2;
	
	ScrambleList[Turn]->ChngDrawClr(TURQUOISE); 
	ScrambleList[Turn]->SetHighlighted(true);
	UpdateSInterface();
	while(i<C/2)
		
	{
		
		pIn->GetPointClicked(P.x,P.y);

		if (zoom_mode==true)
		{
			
			P.x = P.x /zoom_factor;
			P.y = P.y /zoom_factor;
		
		}
		Beep (900,200);
			Sleep(125);
		
		if(P.y<50) throw(P);
		fig=GetSFigure(P);
		if(fig==ScrambleList[Turn+ScrambleCount/2])
		{
			Succ++;
						i++;

			DeleteHighlightedElement();
						ScrambleList[Turn+(C/2)-i]->SetHighlighted(true);
									DeleteHighlightedElement();

			if(ScrambleCount!=0)
			{
			Turn=0+rand()%ScrambleCount/2;
			}
			else
			{
				Turn=-1;
			}
			if(Turn!=-1)
			{
			ScrambleList[Turn]->ChngDrawClr(TURQUOISE); 
	ScrambleList[Turn]->SetHighlighted(true);
		UpdateSInterface();
			}
		}
		else
		{
			Fail++;
		}
		
				pOut->PrintMessage("Number of valid picks is");
				pOut->PrintNumber(Succ,200);
				pOut->PrintMessage("Number of invalid picks is ",230);
				pOut->PrintNumber(Fail,430);
		
	
	} 

					pOut->Drawstring(600,50,"your grade is");
					int grade=100*(Succ);
					
					pOut->Drawint(770,50,(grade/(Succ+Fail)));
					
					pOut->Drawstring(815,50,"/100");

					


		if (grade/(Succ+Fail) > 60 )
					{
						mciSendString("open \"cheer.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
					else
					{
						mciSendString("open \"boo.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
						mciSendString("play mp3 wait", NULL, 0, NULL);
						mciSendString("close mp3", NULL, 0, NULL);
					}
		DeleteScrambleList();
		pOut->ClearStatusBar();
		UpdateInterface();
		UpdateSInterface();
	}
} catch(Point P)
	{
		DeleteScrambleList();
		pOut->ClearDrawArea();
		UpdateInterface();
			ActionType ActType;
		ActType=pIn->GetUserAction();
		ExecuteAction(ActType);
	}

void ApplicationManager::DeleteScrambleList()
{
	for(int i=0; i<ScrambleCount; i++)
	{
		delete ScrambleList[i];
		ScrambleList[i]=NULL;
		ScrambleCount--;
	}
	ScrambleCount=0;
}
void ApplicationManager::DeleteHighlightedElement()
{		
	for (int i=0;i<ScrambleCount;i++)
	{
		
		if (ScrambleList[i]->GetHighlighted()==true)
		{
						delete ScrambleList[i];

			for(int j=i; j<ScrambleCount ; j++)
			{
			ScrambleList[j]=ScrambleList[j+1];
			}
	
		ScrambleCount--;
	
		}		
}
	pOut->ClearDrawArea();
		UpdateSInterface();

	}
void ApplicationManager::SpreadFigs() //Spread the figures along ScrambleList
{
		int dx,dy;
	float Factor=0.5;
	Point P,P2;
	P.x=0;
	P.y=0;
	P2.x=1521;
	P2.y=123;
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
	{
		CFigure *New=FigList[i]->Copy();
		AddToScrambleList(New);
	}
	for(int i=0; i<ScrambleCount ; i++)
	{
		ScrambleList[i]->Getdistance(P,dx,dy);
		ScrambleList[i]->Move(dx/2,0);
		ScrambleList[i]->resize(Factor);
	}
	for(int i=0; i<FigCount; i++)
	{
		CFigure *New=FigList[i]->Copy();
		AddToScrambleList(New);
	}
	for(int i=ScrambleCount/2; i<ScrambleCount ; i++)
	{
	
		ScrambleList[i]->Getdistance(P2,dx,dy);
	if(dx/2>100)
	{
		int rx=0+rand()%100;
		int ry=0+rand()%200;
			ScrambleList[i]->Move((dx/2)+rx,(dy/2)+ry);
		ScrambleList[i]->resize(Factor);
	}
	else
	{
		int rx=0+rand()%50;
		int ry=0+rand()%20;
			ScrambleList[i]->Move((dx/2)+rx,(dy/2)+ry);
		ScrambleList[i]->resize(Factor);
	}
	}

	

	UpdateSInterface();
}
void ApplicationManager::AddToScrambleList(CFigure *ptr)
{
	ScrambleList[ScrambleCount]=ptr;
	ScrambleCount++;
}
void ApplicationManager::UpdateSInterface() const
{	
	
	for(int i=0; i<ScrambleCount; i++)
	{	
		if(ScrambleList[i]->ischoosen()==false)
		{

			if(zoom_mode==true)
		{
			ScrambleList[i]->zoom(zoom_factor,pOut);
			
		pOut->ClearStatusBar();
			
		}
				else
				{
		if(ScrambleList[i]->Dimchecker()==true)
		ScrambleList[i]->Draw(pOut);		//Call Draw function (virtual member fn)

				}

		}
	}

}
	CFigure *ApplicationManager::GetSFigure(Point p) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	///Add your code here to search for a figure given a point x,y
	
	
	for (int i=0;i<ScrambleCount;i++)
	{
		
		bool flag;
		
		flag=ScrambleList[i]->checkpoint(p);
			
		if (flag==true)
		{return ScrambleList[i];}
	
	}
	

	return NULL;
}


////////////////////////////////////////////////////////////////////
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//
void ApplicationManager::ResizeSelectedFigure(float ResizeFactor)
{
	for (int i=0;i<FigCount;i++)
	{
	
		if (FigList[i]->IsSelected()==true)
		{
			FigList[i]->resize(ResizeFactor);
		}
	}
	UpdateInterface();
	}
void ApplicationManager::Bringtoback(CFigure*selectedfigure)
{
	for (int i=0;i<FigCount;i++)
	{
		if(FigList[i]==selectedfigure)
		{
			FigList[i]=FigList[0];
			FigList[0]=selectedfigure;
			return;
		}
	}
}
void ApplicationManager::Bringtofront(CFigure*selectedfigure)
{
	for (int i=0;i<FigCount;i++)
	{
		if(FigList[i]==selectedfigure)
		{
			FigList[i]=FigList[FigCount-1];
			FigList[FigCount-1]=selectedfigure;
			return;
		}
	}
}


//______________________________________________________________




//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	
	for(int i=0; i<FigCount; i++)
	{	
		if( FigList[i]->ischoosen()==false)
		{
				if(zoom_mode==true)
		{
			FigList[i]->zoom(zoom_factor,pOut);
			
		pOut->ClearStatusBar();
			
		}
				else
				{
		if(FigList[i]->Dimchecker()==true)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)

				}
		}	
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
	delete FigList[i];
	delete pIn;
	delete pOut;
	
}
