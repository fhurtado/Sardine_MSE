Pacific sardine operating model and management strategy evaluation
==========================================================================================

This repository stores the most up-to-date code for the operating model used for the Pacific sardine MSE. The model is available under MIT License. The model was developed by F. Hurtado-Ferro and A.E. Punt. Please reference the authors and this repository if you use this model.

Using the model
-----------------
The model is provided as an executable file (`sardine.exe`). To use the model, two input files are required: `sardine.SPEC`, and `sardine.DAT`. `sardine.SPEC` controls the model, harvest control rule and sensitivity scenarios. `sardine.DAT` stores the parameters relevant to the stock. To run the model, both input files and the executable need to be in the same folder.

The model produces an output file called `SUMMARY.OUT`. Rows are simulation years, columns are the different output quantities, organized by simulation. The first column gives the simulation year. Output quantities are organized in groups of nine columns: Biomass 1+, SSB, Recruitment, Catch, True harvest rate, Observed harvest rate, Environmental variable, Mean age of the population, and Mean age of the catch. 

Note that only a Windows version of the model is currently available. If you need a different version, the source code for the model is provided, which you can compile using your favorite Fortran compiler. If you have compiled a Mac or Linux version of the model, please let me know about it, as I'd be interested for it to be uploaded to this repository. 

Compiling the model
---------------------
If you need to make changes to the source file, or want to compile the model to be used on a different operating system, you will need three files: `sardine.FOR`, `sardine.INC`, and `COMMON.FOR`. `sardine.FOR` is the main source file for the model. `sardine.INC` stores the variable declarations. `COMMON.FOR` stores many functions for random number generation used in the main code. 

The current version of the model was compiled using [GFortran] (http://gcc.gnu.org/wiki/GFortran), part of [GCC] (http://gcc.gnu.org/) (GNU Compiler Collection).

