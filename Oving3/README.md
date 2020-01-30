# Questions to the tasks

1. "Utskrift av tid": The modulo operator does not work with other than integers. Any suggestions? (I brute forced it, writing the modulo operation manually. How does LF solve this?

> I now have two different solutions in the code that give the same result. One where i "brute-forced" the modulo-operator (wrote the functionality of it myself) and another where the seconds are static-casted to int, so that the operator itself could be used.  

*Check LF for this one later*

> It gives an error when i declare the variable like this: int hours{sec/3600}; (cannot squeeze/fit double into int), but not when I do it like this: int hours = sec/3600;. WHY?
Possible explanation: https://stackoverflow.com/questions/21150067/initialization-difference-with-or-without-curly-braces-in-c11/21169201
Check out page 83 in PPP: universal and uniform initialization prevents narrowing --> This is the reason behind the error!? 
--> I will probably learn more about this type of initialization later!


2. What should I use as Pi in calculations? Do I have to define one my self? What is recommended in this course?

> Found M_PI, which is a part of <cmath>. 

3. I don't think the way to set upper and lower limit in the rand() function makes sense. Why can I use modulo etc to do this? Find out! 

> Makes sense now! Wrote a detailed description of how it works in the README of Oving4!

# Note on task 5: 

* PPP 24.7 presents randint (a newer and better method for generating random numbers, compared to the method used in this task.) --> try solving the task with this method also!
