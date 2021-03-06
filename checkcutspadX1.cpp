{
  bool Mg24_NoCol = false;
  bool Mg24_Col = false;
  bool Mg26_NoCol = false;
  bool Mg26_Col = false;
  bool C12 = false;
  bool Sm154 = false;
  bool Sn116_NoCol = false;
  bool Sm154_Col = true;
  bool Sm154_NoCol = false;



 // char pause;
  c1 = new TCanvas("c1","Checks on Cut PadvsToF",10,10,900,600);
  

  vector<int> runlist;
  if(Mg24_NoCol)
    {
      ifstream input;
      input.open("24Mg_runs_NoCol.dat");
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }  
  else if(Mg24_Col)
    {
      ifstream input;
      input.open("24Mg_runs_Col.dat");
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }
  else if(Mg26_NoCol)
    {
      ifstream input;
      input.open("26Mg_runs_NoCol.dat");
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }
  else if(Mg26_Col)
    {
      ifstream input;
      input.open("26Mg_runs_Col.dat");
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }
  else if(C12)
    {
      ifstream input;
      input.open("12C_runs.dat");
      
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }
  else if(Sm154)
    {
      ifstream input;
      input.open("154Sm_runs.dat");
      
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }
  else if(Sn116_NoCol)
    {
      ifstream input;
      input.open("116Sn_runs_NoCol.dat");
      
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }
   else if(Sm154_Col)
    {
      ifstream input;
      input.open("154Sm_runs_Col.dat");
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }
  else if(Sm154_NoCol)
    {
      ifstream input;
      input.open("154Sm_runs_NoCol.dat");
      
      while(!input.eof())
		{
		  int dummy = 0;
		  input >> dummy;
		  runlist.push_back(dummy);
		}
    }    
    
    
    
    
  cout << "number of runs: " << runlist.size()-1 << endl;
  
 if(Mg24_NoCol)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_24Mg_NoCol.C");
      cout << "----------------> using cuts for 24Mg No Collimator data" << endl;
    }
  else if(Mg24_Col)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_24Mg_Col.C");
      cout << "----------------> using cuts for 24Mg Collimator data" << endl;
    }
  else if(Mg26_NoCol)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_26Mg_NoCol.C");
      cout << "----------------> using cuts for 26Mg No Collimator data" << endl;
    }
  else if(Mg26_Col)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_26Mg_Col.C");
      cout << "----------------> using cuts for 26Mg Collimator data" << endl;
    }
  else if(Sm154_NoCol)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_154Sm_NoCol.C");
      cout << "----------------> using cuts for 154Sm No Collimator data" << endl;
    }
  else if(Sm154_Col)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_154Sm_Col.C");
      cout << "----------------> using cuts for 154Sm Collimator data" << endl;
    }    


  for(int i=0;i<(int)runlist.size()-1;i++)
    {
      char buffer[256];
      sprintf(buffer,"sorted0%d.root",runlist[i]);
      cout << buffer << endl;
      TFile *f = TFile::Open(buffer);


      if(f){
	      // ******* Plot graph to check the cut on padvsX1                
	    
	     TH2F *pad1vsX1_check = new TH2F("h2pad1vsX1","Check of the cut in padvstof",800,0,800,3000,0,3000);
             
	     DATA->Draw("pad1:X1posO>>h2pad1vsX1","","col"); //CORRECTED
	    // DATA->Draw("pad1raw:X1pos>>h2pad1vsX1","","col"); //NON CORRECTED

              int entries = h2pad1vsX1->GetEntries();
	      cout << "ENTRIES in histo = " <<entries<<endl;
	      if(entries==0) cout << "------------> Run number " << runlist[i] << " IS EMPTY "<<endl;
              
	      cutg->SetLineColor(2);
              cutg->SetLineWidth(2);
              cutg->Draw("same");

  	      c1->Modified();
	      c1->Update();
	      c1->WaitPrimitive();
	      if(i<(int)runlist.size()-1-1)c1->Clear();


       	    }
	 
  //   cout << "Press any key to continue...";
  //    cin >> pause;		

      }



	  


}


