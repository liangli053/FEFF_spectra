# FEFF_spectra
This code reads the output spectra of FEFF code (http://monalisa.phys.washington.edu/feffproject-feff.html),\
interpolates all simulataed spectra over the same energy range, and computes the averaged spectrum.\
In FEFF run, the spectra of each centered atoms were computed in the folders named by atom indices (see example folder).\

To compile:\
g++ -std=c++11 -o Average_FEFF_spectra.exe main.cxx\ 

Go to examples folder and execute the following commands. Input the starting and ending indices of atoms:\
../Average_FEFF_spectra.exe\
please input the starting and ending atoms:\
5 16\
Interpolation starts at 526 ev and ends at 611 eV\

The individual and average spectra will be written in Combo.dat ave.dat, respectively.\
