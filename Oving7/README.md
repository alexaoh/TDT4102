# Questions to the tasks

1. Question to the notion inheritance itself: Føles litt meningsløst å måtte skrive de private medlemsvariablene, som er helt like i alle klassene, i både EmptyFace, SadFace og AngryFace.etc. Kan dette unngås? Eller arver de to andre kun public-delen av EmptyFace?

2. Example: SadFace : EmptyFace : Face (just to show how the inheritance works.). Does SadFace::attach_to() override EmptyFace::attach_to() or Face::attach_to() as it is now (with no virtual keyword in front of Emptyface::attach_to())? How about when the virtual keyword is there? Does it change? I can't really find the answer my self. 
```
Answer from https://www.geeksforgeeks.org/g-fact-36/:
In C++, once a member function is declared as a virtual function in a base class, it becomes virtual in every class derived from that base class. In other words, it is not necessary to use the keyword virtual in the derived class while declaring redefined versions of the virtual base class function.
```
Is this correct? Seems logical to me!

3. [SOLVED] Range-based for loop for Vector_ref? Don't understand why auto does not give class type? (in function testAnimal())
--> Fungerte heller ikke i den siste oppgaven med Emojis! (i attachAllEmojis()). Skjønner ikke hvorfor auto gir en pointer (virker det som?)!? Hjelp!
```
Yes, det stemmer, auto gir en pointer til hvert objekt av typen i vektoren. Dette skyldes at Vector_ref lagrer hvert element som pushes til det som en pointer til elementet av den typen som Vector_ref er definert for. Dermed fungerer range-based for loop helt fint i begge tilfellene jeg har beskrevet ovenfor --> så lenge man dereferencer pointeren inne i løkka! 
```

4. [SOLVED] Task 1: Override keyword makes no difference when defining (and calling) the toString() functions in Cat and Dog? Works without the override keyword!?
```
This is correct! The keyword override explicitly declares to the compiler that a function is meant to override another function (a virtual function). This way we can get the compiler to help check that it works as it should. 
```



***Check LF!!*** 

## Recommended theory (PPP):
```
PPP Chapter 12, 13 and 14

```