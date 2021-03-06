#include "Pythia8/Pythia.h"
#include "TRandom.h"
#include <iostream>
using namespace Pythia8;


void Init_pythia_generator(Pythia* generator){
  
  TRandom rndm;

  // Установка "зерна" рандома

  rndm.SetSeed(0);
  int pythiaSeed = rndm.Integer(1000000);
  char processLine[80];
  sprintf(processLine, "Random:Seed = %d",pythiaSeed);

  generator->readString("Random:setSeed = on");
  generator->readString(processLine); 

  //Set process type and collision energy
  generator->readString("Onia:all(3PJ) = on");
  generator->readString("Beams:eCM = 13000.");

  generator->init();
 

  //альтернативный метод:
  //*(genarator).readString("");
  
  /*
    оператор "->" vs "."

    Доступ к полям объекта:                   Pythia_obj.readString("");
    Доступ к полям объекта через указатель:   Pythia_ptr->readString("");

   */

  cout << "\n\n Generator was succesfully initied\n\n";
  

  return;
}
