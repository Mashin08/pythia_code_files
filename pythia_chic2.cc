// Stdlib header file for input and output.
#include <iostream>

// Header file to access Pythia 8 program elements.
// #include "Pythia8/Pythia.h"
#include "Pythia8/Pythia.h"

// ROOT, for histogramming.
#include "TH1.h"
#include "TH2.h"

// ROOT, for interactive graphics.
#include "TVirtualPad.h"
#include "TApplication.h"

// ROOT, to set random seed (Pythia random seed based on tume does not work!)
#include "TRandom.h"
#include "TMath.h"

// ROOT, for saving file.
#include "TFile.h"

//#include "TParticle.h"

using namespace Pythia8;


/* принцип декомпозиции:

   Необходимо "разбить" программу на как можно более простые составляющие части.
   Реализовать каждую из частей в виде отдельного класса/функции... и вызывать в теле 
   основной программы

   Пример: Инициализация генератора Pythia будет происходить при помощи функции 
   "Init_pythia_generator". Сама функция реализована в отдельном файле :
   "Init_pythia_generator.cc" и принимает на вход указатель на объект класса генертора.
 
*/

// инцииализация функции из "стороннего" файла проекта
void Init_pythia_generator(Pythia*);
void Particle_data_handler(Pythia*, int);
void Write_particle_list(Pythia*, int);
void Write_mass_of_particles(Pythia*, int);
void Write_momentum_of_particles(Pythia*, int);
void Choose_particle_one_type(Pythia*, int);
void Choose_particle_one_type_with_number(Pythia*);

void hist_train();

int main(int argc, char* argv[]) {

  // read input parameters
  printf("argc = %d, argv[0] = %s\n",argc,argv[0]);
  if (argc != 2) {
    printf("Usage: %s <nEvents>\n",argv[0]);
    printf("       <nEvents>=0 is the number of events to generate.\n");
    return 1;
  }
  int nEvents = atoi(argv[1]);
  cout << "nEvents = " << nEvents << endl;

  // Create the ROOT application environment. 
  TApplication theApp("hist", &argc, argv);



  /*Создание объекта и указателя на объект класса Pythia :
  
  объект:       Pythia8::Pythia pythia_obj
  указатель:    Pythia8::Pythia* pythia_ptr
  */

  cout << "\n\n Try to init generator:\n\n";

  Pythia pythia;

  Init_pythia_generator(&(pythia));


   int nEvent2Print = 1;

  // Начало цикла по событиям. Генерация событий.

  int iEvent2Print = 0;

  for (int iEvent = 0; iEvent < nEvents; ++iEvent) {
    if (!pythia.next()) continue;

    // Печать нескольких первых событий.
    if (iEvent2Print < nEvent2Print) pythia.event.list();
    iEvent2Print++;


    // Цикл по частицам в данном событии!
    for (int i = 0; i < pythia.event.size(); ++i) {

      /*
	1. Метод .size() -- "размер события" (количество частиц в данном событии
	2. pythia.event[i], где i -- итератор -- i-ая частица в событии.
       */

      // Particle_data_handler(&(pythia), i);
      // Write_particle_list(&(pythia), i);
      // Write_mass_of_particles(&(pythia), i);
      // Write_momentum_of_particles(&(pythia), i);
      // Choose_particle_one_type(&(pythia), i);
      // Choose_particle_one_type_with_number(&(pythia), i);

      
    } // Конец цикла по частицам в данном событии
    cout << "Number of particles: " <<  pythia.event.size() << "\n" << "\n";
    // Choose_particle_one_type_with_number(&(pythia), i);
    // Choose_particle_one_type_with_number(&(pythia));

  } // Конец цикла по событиям


  hist_train();

  cout << "\n\n Program was fineshed it's work correctly!\n\n";
 

  return 0;
}

