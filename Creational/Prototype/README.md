# WHY DO WE NEED?
+ Prototyping &rarr; Creating/Copying cheaply with the help of an *already constructed* or *pre-initialzed* object. 
+ Prototype &rarr; Template of a before *actual* object is constructed.
+ Prototype &rarr; Partially/Fully initialized object that you make a *copy* of.
+ A prototype pattern is used in software development when the type of objects to create is determined by a `prototypical instance`, which is cloned to produce new objects.
+ Instantiate a class by **copying/cloning**, the properties of existing object, creating and independent clone.
    + The new object is exact copy of the prototype but *permits modification* **without altering the original**.
+ To control class instantiation and object generation.
+ To copy the object _state_

## WHEN DO WE NEED?
+ This pattern is used, for example, when the **inherent cost of creating a new object in the standard way (e.g., using the new keyword) is prohibitively expensive** for a given application.
+ Is generally used for `complex classes`/classes that are `costly to instantiate`.
+ Useful when there are _complex objects_ with __interesting state__ that needs to be replicated in some way.
+ Helpful in creating copy of an object _without even knowing its type_.

## Identification
+ Downside of copy c'tor &rarr; works only for **Concrete Classes**
+ If you offer only the **object API(Interface/Pure virtual)**, then you can not use a copy c'tor on client side, intended usage is cloning and item you can resolve that by _Clone_ method

# BUILD
```bash
g++ -Wall Creational/Prototype/prototype.cpp -o prototype ; ./prototype ; rm -rf ./prototype
cd build ; make prototype
```


# REFERENCES
+ [A base class destructor should be either (public && virtual) || (protected && nonvirtual)](https://necatiergin2019.medium.com/destructor-ya-public-virtual-ya-da-protected-non-virtual-olmal%C4%B1-9bade0adc886)
+ [wikibooks](https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Prototype)
+ [refactoring guru](https://refactoring.guru/design-patterns/prototype/cpp/example)
+ [sourcemaking](https://sourcemaking.com/design_patterns/prototype/cpp/1)
+ [blackwasp](http://www.blackwasp.co.uk/Prototype.aspx)
+ [Vishal Chovatiya](http://www.vishalchovatiya.com/prototype-design-pattern-in-modern-cpp/)