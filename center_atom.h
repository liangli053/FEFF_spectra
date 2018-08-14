#ifndef CENTER_ATOM_H
#define CENTER_ATOM_H

#include <vector>
// store the original energy(x_old), intensity (y_old)
// and intensity after interpolaton (y_intpl)
struct Center_Atom {
   std::vector<double> x_old;
   std::vector<double> y_old;
   std::vector<double> y_intpl;
};
#endif
