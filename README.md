# FEFF_spectra
This code reads the output spectra of FEFF code (http://monalisa.phys.washington.edu/feffproject-feff.html),<br/> 
interpolates all simulataed spectra over the same energy range, and computes the averaged spectrum.<br/> 
In FEFF run, the spectra of each centered atoms were computed in the folders named by atom indices (see the example folder).<br/> 

To compile:<br/> 
g++ -std=c++11 -o Average_FEFF_spectra.exe main.cxx<br/> 

Go to examples folder and execute the following commands. Input the starting and ending indices of atoms:<br/> 
../Average_FEFF_spectra.exe<br/> 
please input the starting and ending atoms:<br/> 
5 16<br/> 
Interpolation starts at 526 ev and ends at 611 eV<br/> 

The individual and average spectra will be written in Combo.dat ave.dat, respectively.<br/> 
