# Questions to the tasks (SOLVED)

1. "Utskrift av tid": The modulo operator does not work with other than integers. Any suggestions? (I brute forced it, writing the modulo operation manually. There exists a modulo operator for floats also: fmod() from \<cmath\>, see page 231 in PPP. 

> I now have two different solutions in the code that give the same result. One where i "brute-forced" the modulo-operator (wrote the functionality of it myself) and another where the seconds are static-casted to int, so that the operator itself could be used. Both are completely fine. LF uses a mix of both these solutions. 

> It gives an error when i declare the variable like this: int hours{sec/3600}; (cannot squeeze/fit double into int), but not when I do it like this: int hours = sec/3600;. WHY?
(Possible) explanation: https://stackoverflow.com/questions/21150067/initialization-difference-with-or-without-curly-braces-in-c11/21169201
Check out page 83 in PPP: universal and uniform initialization prevents narrowing conversions!

2. What should I use as Pi in calculations? Do I have to define one my self? What is recommended in this course?

> Found M_PI, which is a part of \<cmath\>. 

3. I don't think the way to set upper and lower limit in the rand() function makes sense. Why can I use modulo etc to do this? Find out! 

> Wrote a detailed description of how it works in the README of Oving4!
