# Questions to the tasks

1. Hvordan overlaste [] slik at den fungerer for 2-indeksering? Array[i][j] skal også fungere!

3. Take a closer look at the way the matrix (table-member) is defined. Really understand how it works!

4. Fix operator[]-overloading in Matrix-class! How can this be written so that i works twice? A[i][j]?

5. Copy-assignmment constructor: 
- Why return *this? (a dereferenced this-pointer)
- Should it be able to copy when the dimensions of the matrices are different? Because both the versions I made of the copy-assignment constructor only work when the dimensions are the same. 

6. How can I return an invalid matrix? Trying to do just that in task 5 (operator +=).

7. How to solve + without changing the left matrix that the operator is called on?!

***Check LF!!*** 

## Recommended theory (PPP):
```
PPP Chapter 17 and 18
