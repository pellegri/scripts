{
  bool Mg24_NoCol = false;
  bool Mg24_Col = true;
  bool Mg26_NoCol = false;
  bool Mg26_Col = false;
  bool C12 = false;
  bool Sm154_Col = false;
  bool Sm154_NoCol = false;
  bool Sn116_NoCol = false;

 // char pause;
  c1 = new TCanvas("c1","Checks lineshape",10,10,900,600);
  

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
  cout << "number of runs: " << runlist.size()-1 << endl;
  
 if(Mg24_NoCol)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Alphas_24Mg_NoCol.C");
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_24Mg_NoCol.C");
      cout << "----------------> using cuts for 24Mg No Collimator data" << endl;
    }

  else if(Mg24_Col)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Alphas_24Mg_Col.C");
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_24Mg_Col.C");
      cout << "----------------> using cuts for 24Mg Collimator data" << endl;
    }
  else if(Mg26_NoCol)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Alphas_26Mg_NoCol.C");
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_26Mg_NoCol.C");
      cout << "----------------> using cuts for 26Mg No Collimator data" << endl;
    }

  else if(Mg26_Col)
    {
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Alphas_26Mg_Col.C");
      gROOT->ProcessLine(".x /home/luna/codes/PR251-analysis/sortedfiles/gates/Cut_pad1X1_26Mg_Col.C");
      cout << "----------------> using cuts for 26Mg Collimator data" << endl;
    }


  for(int i=0;i<(int)runlist.size()-1;i++)
    {
      char buffer[256];
      sprintf(buffer,"sorted0%d.root",runlist[i]);
      cout << buffer << endl;
      TFile *f = TFile::Open(buffer);


      if(f){
	      // ******* Plot graph to check the cut on padvstof               


  	      TH2F *htofvsX1posCTOF = new TH2F("htofvsX1posCTOF","tof vs X1posCTOF",2100,100,800,100,1910,2010);
              DATA->Draw("tof:X1posCTOF>>htofvsX1posCTOF","X1flag==0 && U1flag==0 && Alphas_24Mg_Col && Cut_pad1X1_24Mg_Col","col");// CORRECTED
	     //DATA->Draw("tof:X1posO>>htofvsX1posCTOF","X1flag==0 && U1flag==0 && Alphas_24Mg_Col && Cut_pad1X1_24Mg_Col","col");//NON CORRECTED


              int entries = htofvsX1posCTOF->GetEntries();
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


