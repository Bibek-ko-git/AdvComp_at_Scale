# Matrix-Matrix or Matrix-Vector Multiplication
This file consist of instruction on how to compile and execute the codes. Also some references and git links that I used.

## 1. Create build and make file
Run this command on the directory with all the other files:
\> cmake -S . -B build

###### note : The version I am using is 3.28.3 for cmake. So, you might need to adjust and make changes as per your system's requirement. 

## 2. Change the directory to build and compile
\> cd build

\> make

## 3. Execute the main executable
\> ./main <file1.mtx> <file2.mtx> variable
###### note : here file1.mtx is a matrix file while file2.mtx can be both matrix or vector. For matrix-matrix multiplication choose variable = 1 amd for matrix-vector multiplication choose variable = 0. To run the executable you will need to add the .mtx files in build directory.


### References used
1. https://github.com/Sh0g0-1758/TheWizardofOS/blob/8e5d8a8cabb865e6d68d8645773234db8f6307ab/Benchmarks/CPU/matmul.cpp#L34-L36
2. https://stackoverflow.com/questions/57075834/how-to-convert-matrix-market-file-to-matrix-in-c
3. https://math.nist.gov/MatrixMarket/mmio/c/example_read.c
