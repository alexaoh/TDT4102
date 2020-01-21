# Questions to the tasks

1. "Utskrift av tid": The modulo operator does not work with other than integers. Any suggestions? (I brute forced it, writing the modulo operation manually. This is probably not the best way to solve the problem!) Need guidance when it comes to the function printTime()! Probably not optimal to static_cast the doubles to ints. How can this task be solved in another way?

> This is obviously not the correct way to do it, because it gives 0 hours, 0 mins and 0 secs in the last task. Find another way to make it correct!!

> It gives an error when i declare the variable like this: int hours{sec/3600}; (cannot squeeze/fit double into int), but not when I do it like this: int hours = sec/3600;. WHY?
Possible explanation: https://stackoverflow.com/questions/21150067/initialization-difference-with-or-without-curly-braces-in-c11/21169201
Check out page 83 in PPP: universal and uniform initialization prevents narrowing --> This is the reason behind the error!? 

> How could I solve this problem in another manner?

2. What should I use as Pi in calculations? Do I have to define one my self? What is recommended in this course?

> Found M_PI, which is a part of <cmath>. 

3. I don't think the way to set upper and lower limit in the rand() function makes sense. Why can I use modulo etc to do this? Find out! 

# Note on task 5: 

* PPP 24.7 presents randint (a newer and better method for generating random numbers, compared to the method used in this task.) --> try solving the task with this method also!
