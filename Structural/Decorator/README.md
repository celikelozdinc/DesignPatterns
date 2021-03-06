# WHY DO WE NEED?
+ Stick to `Open-Closed Principle` &rarr; Augment the functionality of existing objects without altering/rewriting existing code
+ Helps to attach additional behavior/responsibilities to an object __dynamically__.
+ Add new characteristics to objects by adding a wrapper
+ Extends functionality of existing classes __at runtime__
+ Uses composition, chaining __decorators__ together

## WHEN DO WE NEED?
+ Once the class has `final` keyword which means the class is not further inheritable.
    + Provides a flexible alternative to *subclassing* for extending functionality.
+ Once you need to able to assign extra behaviours to object *at runtime* without breaking the code that uses these objects

## Identification
+ Also known as _Wrapper_
+ Dynamic Decorator &rarr; Aggregate the decorator object by __reference/pointer__
    + We are instantiating the *ColoredShape at runtime* by providing needed arguments.
    + We can decide at runtime which *Shape*-*Circle* or *Square*- is going to be colored.
    + class ISocket {virtual void Send(...) const = 0;} &uarr; 
        + class ISocketDecorator : public ISocket{_ISocket* sock*_} &uarr; 
            + class CompressedSocketDecorator : public ISocketDecorator{virtual void Send(...) const override{}}

# BUILD
```bash
g++ -Wall Structural/Decorator/wrapper.cpp -o wrapper ; ./wrapper ; rm -rf wrapper
cd build ; make wrapper
```


# REFERENCES
+ [wikibooks](https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Decorator)
+ [Vishal Chovatiya](http://www.vishalchovatiya.com/decorator-design-pattern-in-modern-cpp/)
+ [c++ patterns](https://cpppatterns.com/patterns/decorator.html)
+ [Martin Vorbrodt](https://vorbrodt.blog/2022/04/27/decorator-pattern-explained/)
