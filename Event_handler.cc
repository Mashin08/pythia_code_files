#include <iostream>
#include "Pythia8/Pythia.h"

using namespace Pythia8;
 

void Particle_data_handler(Pythia* pythia, int number_of_iteration){
  /*This function output the list of particles with id, name and status*/ 
  cout << "Particle number: " << number_of_iteration << "     Particle name: " << pythia->event[number_of_iteration].name() <<
    "     Particle status: " << pythia->event[number_of_iteration].status() << "     Particle id: " << pythia->event[number_of_iteration].id() <<  "\n";

  return;
}

void Write_particle_list(Pythia* pythia, int number_of_iteration){  
  /*This function output the list with types of particles in event*/
  int current_particle_id;
  string  current_particle_name;
  int counter = 0;
  // cout << "Particle id:  2212" << "   Particle name:  p+" << "\n";
  for (int j = 0; j < number_of_iteration; j++) {

    if ( pythia->event[j].id() ==  pythia->event[number_of_iteration].id()) {
      continue;
    }

    else if ( pythia->event[j].id() !=  pythia->event[number_of_iteration].id()) {
      counter++;
      current_particle_id = pythia->event[number_of_iteration].id(); 
      current_particle_name = pythia->event[number_of_iteration].name();
    }
  }
  if (counter == number_of_iteration-1) {
    cout << "Particle id:  " << current_particle_id <<
       "   Particle name:  " << current_particle_name << "\n";
  }
  return;
}


void Write_mass_of_particles(Pythia* pythia, int number_of_iteration) {
  /*This function output mass of particles in event*/
  cout << "Particle name:   " << pythia->event[number_of_iteration].name() <<
       "   Particle mass:   " << pythia->event[number_of_iteration].m() <<  "\n";
  
  return;
}


void Write_momentum_of_particles(Pythia* pythia, int number_of_iteration) {
  /*This function output momentum of particles in event*/
  double particle_momentum = sqrt(pow(pythia->event[number_of_iteration].px(), 2) + 
			       pow(pythia->event[number_of_iteration].py(), 2) +
			       pow(pythia->event[number_of_iteration].pz(), 2));

  cout << "Particle name:   " << pythia->event[number_of_iteration].name() <<
  "        Particle momentum:   " << particle_momentum  <<  "\n";
  
  return;
}
