# Assignment 1

## Questions

### a)How did you test your code? What are the limitations of your testing?
#### This time created a separate file with bunch of test cases for each of the method. I solved for the easier functions like $f(x) = 1$,  $f(x) = x$, $f(x) = x^2$, $\frac{f(x)}{\sqrt{1-x^2}}$  and $f(x)\sqrt{1-x^2}$, which are easier to solve by had or a calculator. The current limitations are:
- #### Does not have a test case for a complex function. 
- #### Creating such case before-hand would require the hand calculation or mathematica according to the difficulty of the problem.

### b) What approach did you take to document your functions and driver program?
#### I used documentation format called Doxygen for the assumptions and parameters of function. I have placed comments on most part of the code to understand what is happening there. I have also included the README.md file for the user to easily integrate my code into their system. 

### c)  How did you handle errors? How did you test your error handling strategy?
#### I have compared the result from the code implementation with the actual result we get after integration. I used ternary operator we learnt in the lecture the other day to see if the required condition in fulfilled and get results based on that. I have not tested the error handling strategy. 

### d)  Is your code robust to errors in the input files? How did you test this?
#### I don't have a input files for this case. I have made sure the user will input their values their values in the terminal and have provided required instructions for proper result.

### e) Are there any limitations in your implementation you are aware of? Do you have any ideas on how to address them?
- #### The main limitation is the proper working of each of the cases which is not finished. For that I might need to look deeper into the theory part of the integration and figure out where the implementation is breaking. 
- #### It cannot take a file with parameters as a input. There should be a certain type of file format with parameters which I could take a look and integrate into the code.

### f) If you wanted to optimize the performance of your code, what approach would you take?
#### I think there are multiple libraries which have inbuilt quadrature schemes to solve the integrations. With more research I might be able to utilize them instead of having to type each weights and points as well as the function solvers. 

### g) How would you extend your code to two or more dimensions?
#### I don't have a clear idea about this but maybe we can use multi-dimentional function where we store the coefficents, weight and points in matrices of higher order instead of just vectors.

### h) Explain how you would handle a user defined function that takes additional parameters.
#### I am not particularly sure, but I have heard about lambda functions or something like that which can take additional parameters. However, I think my code is sufficient for a polynomial user defined function. If we want to integrate a trigonometric funtion we just need to add a separate class to create such funtions in the Num_int_poly.cpp file.

### i) ) Are there any ways you could handle arbitrary functions that are defined at runtime by the user for example in an input file?
#### I currently don't know the way to do this. 
