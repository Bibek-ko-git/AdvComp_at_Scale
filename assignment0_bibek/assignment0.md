# Assignment 0

## Questions

### a) How did you test your code? What are the limitations of your testing?
#### For now I just took two 2 $$\times$$ 2 matrix and a 2 $$\times$$ 1 vector and hand calculated the multiplication to tally the results. When we learn more on testing or maybe after the code review I will be able to add a file to do the required testing. The currect limitations are:
- #### Trying that for a bigger matrix would take longer time and after certain value it would be impossible to calculate by hand.
- #### Using a standard testing methods would be a better method.

### b) What are the limitations of the matrix market format for dense matrices?

#### I think that for this format a dense matrix of 100by100 or even 10by10 would be a long stripe of numbers, which would be very hard to visualize without a programming language to convert it to proper form. 

### c) If you know the size of the matrices at compile time, how would you change your code to take advantage of this information?
#### Instead of allocating memory for unknown values of rows  and column, we could just assign some constants for them. This will take less memory and the code will run faster. 

### (d) Was your matrix representation row-major or column-major? How did you decide? Do you think this will have an impact on performance?
#### When creating the matrix rows are assigned first and they would have the unallocate memory untill it is stopped and next row is called to fill the column, so the matrix representation used is row-major. I think it is the standard way of creating the matrix for most programming languages and the only way I know how to do it. As ths method has been used as the standard way, I believe it has better performance then the column-major one. 

### (e) What approach did you take to document your functions and driver program?
#### Since the matrix.mtx files need to be in the build directory, I have used Readme.md file to include the information about it. Also, overall process to use cmake, make and execute are mentioned there.

### (f) Is your code robust to errors in the input files? How did you test this?
#### I don't think it is robust. It is able to read the required input files properly. I don't know how to test this. 

### (g) Are there any limitations in your implementation you are aware of? Do you have any ideas on how to address them? e.g., what is the maximum size of the matrices you can handle?
#### The current limitation that I know of is if I have three input files in the build folder (eg. matrix, matrix, vector), even if I try to execute just a matrix-vector multiplication it will execute another command as well and give result for matrix-matrix multiplication. I don't know why this is happening. 

### (h) If you wanted to optimize the performance of your code, what approach would you take?
#### I think I can use math libraries like BLAS or PETSc to call the multiplication function instead of having to define each and every steps. I could also use GCC and it's appropriate flag "-o3" as discussed in lecture-4 to enable optimization.
