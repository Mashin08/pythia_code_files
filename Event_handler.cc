#include <iostream>
#include "Pythia8/Pythia.h"

using namespace Pythia8;
 

void Event_handler(Pythia* pythia){


  cout << pythia->event.size() << "\n";

  return;
}