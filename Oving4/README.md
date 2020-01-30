# Questions to the tasks

1. Check out comments in code for testing printStudent() in main() (about cin.ignore and a new-line left in the input-stream!)

2. Still can't quite grasp how the lower and upper bounds are used to defines random numbers (with the modulo-operator). (randomizeString());

> Makes sense now! 
> The expression % (upper-lower) guarantees that the number is lower than the difference between the two numbers (from 0 to the difference). When the lower bound is added, all the numbers are shifted this amount. This way one gets random numbers between the lowerbounb and upperbound, not including the upper. Therefore you can add 1 to the modulo expression -> %(upper-lower+1) --> this way one more mumber can be chosen from when generating random numbers, and both upper and lower bounds are included in the range from where the random numbers can be picked!

3. More effective way of filling the gradeCount-vector with values in testString()? A bit like a homemade spaghetti as it is now. 

> Could define the vector to be 6 values long (since we already know that this is the desired length of the vector). This can be looped over in a regular for-loop, and the index could be used to cycle through the characters ('A', 'B', etc), while the countChar()-function is called + pushed to the vector. 

4. readInputToString(): Jeg skjønner ikke hvordan de mener at man skal se bort fra om bokstavene er store eller små? Det har jo alt å si for om bokstaven er innenfor det rette intervallet, da ASCII-verdiene til små og store bokstaver er veldig forskjellige! Jeg ser bort fra denne antagelsen per nå. 
--> I solved this task, but it seems sub-optimal. How else could it be solved?
--> Skal den klare å få input som strings også (slik jeg har tenkt)? Eller holder det med chars? Da blir den mye lettere!

> Check getInput in MastermindWindow-class in masterVisual-files. This is solved in another way!

5. How can i check if guesses <= 0 outside of the scope of the while-loop in playMastermind()? Now it writes "you lost" after the loop, not depending on wheher you lost or not. 

> Fixed! Remember that amountOfGuesses is not constant! Changes made to this variable applies in the playMastermind() scope!


### Take a look at the solution from the professors when that is published! I want to see some other solutions to the problems!

### Take a closer look at the graphics that are used towards the end of the course! 

## Recommended theory (PPP):
```
Appendix B.8.1 and B.8.2

```
