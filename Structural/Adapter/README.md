# WHY DO WE NEED?
+ Callback via *`interfaces`*
+ I was working on implementing an adapter design pattern `to utilize the existing classes`
+ Can you imagine an situation when you have some class expecting some type of object and you have an object offering the same features, but exposing a different interface? 
    + Of course, you want to use both of them so you don't to implement again one of them, and you don't want to change existing classes, so why not create an `adapter`?
+ In some cases, a single program entity may need to signal multiple events to whoever is interested.
+ C++ polymorphism can be used to call arbitrary methods from any instance through a pointer to a base class. 
    + However, when implementing a callback strategy, it’s preferable to use the `adapter idiom`.
+ This idiom consists in writing an `abstract base class` with only virtual const methods. 
    + From that, an adapter class is derived; it’s task is that of taking one or more target instances, where the actual callbacks reside.

## WHEN DO WE NEED? 
The **Adapter Pattern** is pretty common in C++ code. It’s very often used in systems based on some legacy code. In such cases, **Adapters** make legacy code work with modern classes.

## Identification
Adapter is recognizable by a `constructor which takes an instance of a different abstract/interface type`. When the adapter receives a call to any of its methods, it translates parameters to the appropriate format and then directs the call to one or several methods of the `wrapped object`.

# BUILD
```bash
g++ -Wall Structural/Adapter/adapter_via_callbacks.cpp -o adapter ; ./adapter ; rm -rf ./adapter
cd build ; make adapter
```

# REFERENCES
+ [Callback Types](https://medium.com/@jonnymind/ill-call-you-back-better-part-i-843869152599)
+ [Adapter Idiom](https://refactoring.guru/design-patterns/adapter/cpp/example#example-1)