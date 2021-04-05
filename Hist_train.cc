// ROOT, for histogramming.
#include "TH1.h"
#include "TH2.h"

// ROOT, for saving file.
#include "TFile.h"

void hist_train() {
  double xmin = 0.;
  double xmax = 50.;
  int nbins_1 = 10;
  int nbins_2 = 100;
  int nbins_3 = 1000;

  TH1F* hist_ptr_1 = new TH1F("hist_ptr_1", "Header of our first simple histogram", nbins_1, xmin, xmax);
  //hist_ptr->Sumw2();

  TH1F* hist_ptr_2 = new TH1F("hist_ptr_2", "Header of our first simple histogram", nbins_2, xmin, xmax);
  TH1F* hist_ptr_3 = new TH1F("hist_ptr_3", "Header of our first simple histogram", nbins_3, xmin, xmax);
  TH1F* hist_ptr_4 = new TH1F("hist_ptr_4", "Header of our first simple histogram", nbins_2, xmin, xmax);

  for (int i = 0; i < 100;i++) {
    hist_ptr_1->Fill(((xmax/100)*i)*((xmax/100)*i));
    hist_ptr_2->Fill(((xmax/100)*i)*((xmax/100)*i));
    hist_ptr_3->Fill(((xmax/100)*i)*((xmax/100)*i));
  }

  for (int i = 0; i < 100;i++){
    for (int j = 0; j < ((xmax/100)*i)*((xmax/100)*i); j++){
      hist_ptr_4->Fill(((xmax/100)*i));
    }
  }

  char fn[1024];
  sprintf(fn, "%s", "first_our_ROOT_file.root");
  TFile* outfile = new TFile(fn, "RECREATE");
  
  hist_ptr_1->Write();
  hist_ptr_2->Write();
  hist_ptr_3->Write();
  hist_ptr_4->Write();


  outfile->Close();

  delete outfile;
  delete hist_ptr_1;
  delete hist_ptr_2;						  
  delete hist_ptr_3;
  delete hist_ptr_4;
}
