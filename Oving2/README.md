# Questions to the tasks

1. How can i set precision when returning a double from a function? E.G. in inputDouble(), task 2d). Seems like the precision of the returned double is random. 

> Check Appenix in PPP. **setprecision** and **fixed** are mentioned in the task. Chapters that are mentioned in the task are: B.7.6, 11.2.3 and 11.2.4. 
> Solution to my problems: when setprecision() is used by itself, it gives the maximum amount of decimals that can be used by the double. When fixed is used alongside setprecision(), the decimal precision of the double is set to the precision specified (not equal or less, as when specifying precision by itself). 

2. Why do the answers in 6 rely on whether I use rate/100, rate\*0.01 or rate\*(1/100)?! (E.G in 6b: calculateAnnuity) I would quess it has to do with memory, but I have no clear idea!
> The answer to this question is: Remember that if both operands in a division are **integers**, C++ performs **integer division**! To get **regular division** one needs to define at least one of the operands as a double!
The answer is therefore correct if it is calculated as: rate/100.0, rate\*0.01 or rate\*(1/100.0)!
