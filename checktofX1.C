{
  bool Mg24_NoCol = false;
  bool Mg24_Col = true;
  bool Mg26 = false;
  bool C12 = false;
  bool Sm154 = false;
  bool Sn116_NoCol = false;

 // char pause;
  c1 = new TCanvas("c1","Checks X1pos",10,10,900,600);
  

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
  if(Mg24_Col)
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
  else if(Mg26)
    {
      ifstream input;
      input.open("26Mg_runs.dat");
      
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


  for(int i=0;i<(int)runlist.size()-1;i++)
    {
      char buffer[256], histo[256];
      sprintf(buffer,"sorted0%d.root",runlist[i]);
      cout << buffer << endl;
      TFile *f = TFile::Open(buffer);
      sprintf(histo,"histo%d",i);
      cout << histo << endl;

      if(f){
	      // ******* Plot graph to check X1 position 
            TH2F *htofvsX1posCTOF = new TH2F("htofvsX1posCTOF","Check tof vs X1posCTOF",700,100,800,100,1910,2010);              
	    
            if(Mg24_NoCol)
              {
		DATA->Draw("tof:X1posO>>htofvsX1posCTOF","Alphas_24Mg_NoCol && Cut_pad1X1_24Mg_NoCol","colz");//NON CORRECTED
	        //DATA->Draw("tof:X1posCTOF>>htofvsX1posCTOF","Alphas_24Mg_NoCol && Cut_pad1X1_24Mg_NoCol","colz");//CORRECTED
                //cout << "24Mg No Collimator cuts" << endl;
              }
	     else if (Mg24_Col)
	      {
	        DATA->Draw("tof:X1posO>>htofvsX1posCTOF","Alphas_24Mg_Col && Cut_pad1X1_24Mg_Col","colz");//NON CORRECTED
	      //  DATA->Draw("tof:X1posCTOF>>htofvsX1posCTOF","Alphas_24Mg_Col && Cut_pad1X1_24Mg_Col","colz");//CORRECTED
		//cout << "24Mg Collimator cuts" << endl;
	      }
	      
              int entries = htofvsX1posCTOF->GetEntries();
	      cout << "ENTRIES in histo = " <<entries<<endl;
	      if(entries==0) cout << "------------> Run number " << runlist[i] << " IS EMPTY "<<endl;
              
	      
              TLine *line1 = new TLine(633,1910,633,2010);
              line1->SetLineColor(2);
	      line1->SetLineWidth(2);
	      line1->SetLineStyle(2);
              line1->Draw();

              TLine *line2 = new TLine(255,1910,255,2010);
              line2->SetLineColor(2);
	      line2->SetLineWidth(2);
	      line2->SetLineStyle(2);
              line2->Draw();

                c1->Modified();	
                c1->Update();        
	        c1->WaitPrimitive();
	        if(i<(int)runlist.size()-1-1)c1->Clear();


       	    }
		

      }



}

