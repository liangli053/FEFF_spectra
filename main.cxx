/*
 * Take the FEFF output spectra of individual atoms,
 * interpolates all simulataed spectra over the same energy range,
 * and computes the averaged spectrum.
 * All spectra and averaged spectrum are written in 
 * files Combo.dat and ave.dat
 */
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// local includes
#include "spline.h"
#include "center_atom.h"
using namespace std;

int main() {
  vector<Center_Atom> all_atoms;
  vector<double> energy;
  vector<double> ave_spectrum;
  int st_atom, end_atom;
  int st_eng=0, end_eng=20000; // the lower and upper limits of energy will be determined later
  string tmp1="./";
  cout << "please input the starting and ending atoms:" << endl;
  cin >> st_atom >> end_atom;

// read in the calculated spectra and determine the x range of interpolation
  for (int i=st_atom; i<=end_atom; ++i) {
    Center_Atom curr_atom;
    string line;
    double x, y;
    // convert integer to string
    ostringstream ss;
    ss << i;
    string tmp3 = ss.str();
   // *****
    string xmu_location=tmp1 + tmp3 + "/xmu.dat";
    ifstream read_from(xmu_location.c_str());
    while (getline(read_from, line )) {
      if (line[0] != '#') {
        istringstream ss(line);
        ss >> x; ss >> y; ss >> y; ss >> y;
        curr_atom.x_old.push_back(x);
        curr_atom.y_old.push_back(y);
      }
    }
    read_from.close();
    // determine the energy limits for interpolation
    if (st_eng <= *curr_atom.x_old.begin())
       st_eng = (int) (*curr_atom.x_old.begin()+1);
    if (end_eng >= *(curr_atom.x_old.end()-1))
       end_eng = (int) (*(curr_atom.x_old.end()-1));

    all_atoms.push_back(curr_atom);
}
cout << "Interpolation starts at " << st_eng << " ev and ends at " << end_eng << " eV" <<endl;

for (double i=st_eng; i<= end_eng; i+=0.05) {energy.push_back(i);} // x-axis values

// interpolation using the calculated energy range
for (auto it=all_atoms.begin(); it!=all_atoms.end(); ++it) {
    tk::spline sss;
    sss.set_points(it -> x_old, it -> y_old);
    for (auto it2=energy.begin(); it2!=energy.end(); ++it2) {
      it -> y_intpl.push_back(sss(*it2));
    }
}
// print out the combo spectra and averaged spectrum
ofstream write_to_Combo("Combo.dat");
ofstream write_to_ave("ave.dat");
for (vector<double>:: size_type i=0; i<energy.size(); ++i) {
  write_to_Combo << setprecision(7) << energy[i] <<"   ";
  double sum=0;
  for (auto it=all_atoms.begin(); it!=all_atoms.end(); ++it) {
    write_to_Combo << setprecision(7) << it -> y_intpl[i] << "   ";
    sum += it->y_intpl[i];
  }
  write_to_Combo << endl;
  write_to_ave << setprecision(7) << energy[i] <<"   " << sum/all_atoms.size() << endl;
}
write_to_Combo.close();
write_to_ave.close();
return 0;
}
