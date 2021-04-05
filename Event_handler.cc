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
  //This function output the list with types of particles in event
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


/*void Write_particle_list(Pythia* pythia, int number_of_iteration){ 
  int *id_list = new int[pythia->event.size()];
  string *name_list = new string[pythia->event.size()];
  // This function output number or particles of each type in event
  int current_particle_id;
  string  current_particle_name;
  int counter = 0;
  int k = 0;
  id_list[number_of_iteration] = pythia->event[number_of_iteration].id();
  name_list[number_of_iteration] = pythia->event[number_of_iteration].name();
  //cout << id_list[number_of_iteration] << "      " << name_list[number_of_iteration] << "\n";
  return;
  }*/



/*int *id_list_types = new int[sizeof(id_list)];
string *name_list_types = new string[sizeof(id_list)];
int *number = new int[sizeof(id_list_types)];
int capacity = 0; 


void Choose_particle_one_type(Pythia* pythia, int number_of_iteration) {
  int  k = 0;
  int current_particle_id;
  string  current_particle_name;
  int counter = 0;
 
  for (int i = 0; i < sizeof(id_list_types); i++) { 
    number[i] = 0;
  }
 
  for (int j = 0; j < number_of_iteration; j++) {

    if (id_list[j]  ==  id_list[number_of_iteration]) {
	continue;
    }

    else if (id_list[j] != id_list[number_of_iteration]) {
        counter++;
	current_particle_id = id_list[number_of_iteration]; 
	current_particle_name = name_list[number_of_iteration];
      
    }
  }
  if (counter == number_of_iteration-1) {
    /* cout << "Particle id:  " << current_particle_id <<
       "   Particle name:  " << current_particle_name << "\n";*/
/* id_list_types[k] = current_particle_id;
     name_list_types[k] = current_particle_name;
     cout << "Particle id:  " << id_list_types[k]  <<
       "   Particle name:  " <<  name_list_types[k]  << capacity << "\n";

     capacity++;
     k++;
     
  }
  
  return;
}


void Choose_particle_one_type_with_number(Pythia* pythia) {
  /*for (int h = 0; h < sizeof(id_list); h++) {
    number[h] = 0;
  for (int k = 0; k < capacity; k++) {
    for (int number_of_iteration = 0; number_of_iteration < pythia->event.size(); number_of_iteration++) {
   
      if (pythia->event[number_of_iteration].id() ==  id_list_types[k]) {
	number[k]++;
      }
    }
  }
  for (int k = 0; k < capacity; k++) {
     cout << "Particle id:  " << id_list_types[k] <<
       "   Particle name:  " << name_list_types[k] << "    " << number[k] << "\n";
       }
  
  return;
}
*/
