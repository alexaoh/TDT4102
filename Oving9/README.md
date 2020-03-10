# Questions to the tasks

1. Take a closer look at the way the matrix (table-member) is defined. Really understand how it works!

2. Fix operator[]-overloading in Matrix-class! How can this be written so that i works twice? A[i][j]?
```
The overloaded operator now returns a pointer. Therefore, when it is used one time, the row's pointer is returned. The second time the [] is used, the column pointer that the row pointer points to is dereference, and therefore the correct value can be found using the [][]. 
```

3. Copy-assignmment constructor: 
- Why return *this? (a dereferenced this-pointer)
```
Returns *this because the operator has a Matrix-reference as return value. Therefore the dereferenced pointer can be used as a reference for later use. 
```

4. How to solve + without changing the left matrix that the operator is called on?!
```
My solution is correct now!

```

***Check LF!!*** 

## Recommended theory (PPP):
```
PPP Chapter 17 and 18
