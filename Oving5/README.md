# Questions to the tasks (SOLVED)

1. Any other way to add all the keys from the enumerators in the enumerations Suit and Rank? Very time consuming to manually define all the keys in the map, when they already are defined in the enummartions Rank and Suit. This also makes it easy to forget some om the enumerators (Task 1d). 

> The did it the same way in LF. The map has to be built manually. 

2. Are classes/enums/structs etc usually declared and defined in the header files? Or declared in header files and defined i cpp files? 
> Seems like the second option is the most used: The class with all datatypes etc are declared in header files, but all the functionality is defined in cpp files (getters and setters). 

3. vector.erase() does not work with a regular index?

> It takes an iterator!

4. Wrong input-handling: Is it possible to get cin.fail() flag when asking for a char as input? I clearly changed my inputs to int to make them get flagged as fails when that is the case. However, I tried using chars earlier, and cin never got flagged as fail(). 

> I think it is safest to use integers. At least it works. 

5. More about input handling: for (char c; (cin >> c) && !isdigit(c); ){} --> why use char c there, instead of int c?? I don't really understand why!?

> Because of the mentioned problems in point 4. 


## Recommended theory (PPP):
```
PPP Chapter 9

```
