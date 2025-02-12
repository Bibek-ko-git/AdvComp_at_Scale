# Numerical Integration
This file consist of instructions on how to compile and execute the codes.

## 1. Create build and make file
Run this command on the directory with all the other files:
\> cmake -S . -B build

#### Note : The version I am using is 3.28.3 for cmake. So, you might need to adjust and make changes as per your system's requirement. 

## 2. Change the directory to build and compile
\> cd build
\> make

## 3. Running the executables
\> ./num_int_test
#### It is a test executable and runs test cases to see the correctness of the code implemented in int_rule.hpp. Currently a couple of cases are still failing and comments regarding how to make them effective and pass the test would be highly appreciated.

\> ./num_int_poly 
#### It is the user executable file which anyone can run to do the integration calculations. It will ask for all the required constants and variables required to conduct the integrations. 
#### Note: Click Return (Enter) on your keyboard after entering each variable or coefficient value. 

