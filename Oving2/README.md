# Questions to the tasks

1. How can i set precision when returning a double from a function? E.G. in inputDouble(), task 2d). Seems like the precision of the returned double is random. 

> Check Appenix in PPP. **setprecision** and **fixed** are mentioned in the task. Chapters that are mentioned in the task are: B.7.6, 11.2.3 and 11.2.4. 
**I don't understand what fixed does? Seems different every time!? I don't understand the usage? Check comments in the code in 2d and 2e!**

Har du noe eksempel på hvordan du hadde gjort det i oppgave 2e? Oppgaven sier at de kan brukes sammen, men jeg skjønner ikke hvordan? 

Setprecision() gir heller ikke mening i oppgaven om solveQuadraticEquations!

2. Har du et annet forslag til hvordan jeg kan ta a, b og c som input i solveQuadraticEquations?

3. Tips for better formatting on last task? (table)

4. Why do the answers in 6 rely on whether I use rate/100, rate\*0.01 or rate\*(1/100)?! (E.G in 6b: calculateAnnuity) I would quess it has to do with memory, but I have no clear idea!
> The answer to this question is: Remember that if both operands in a division are **integers**, C++ performs **integer division**! To get **regular division** one needs to define at least one of the operands as a double!
The answer is therefore correct if it is calculated as: rate/100.0, rate\*0.01 or rate\*(1/100.0)!
