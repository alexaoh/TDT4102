# Questions to the tasks (SOLVED)

1. Q about the constructor of CourseCatalog: Should i define one for it? Or should it just use a default constructor when I don't want to pass arguments when initializing an object of the class?

> I don't need to define one here, as the default one will suffice. 

2. How to readFromFile in to CourseCatalog? Does not work :(

```
I now have two different soultions for this (they have the same functionality): 
1. Uses the >> operator of a new class Course, where each object is a new entry (course) in the map CourseCatalog. 
2. Done only using readFromFile(), without making a class to instantiate new objects per new entry. 
```

3. Which header-files am I actually using when graphing in task 5? Not too clearly stated in the book, can't find it there :(

> Using <Window.h> and <Graph.h>, but not <GUI.h>

## Recommended theory (PPP):
```
PPP Chapter 10, 11, 21.6.1 and B.7

```
