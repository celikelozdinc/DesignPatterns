# WHY DO WE NEED?
+ C++ does not support `virtual c'tor` and `virtual copy c'tor`
+ Unlike c'tor, factory method `-aka virtual c'tor-`, may return _an instance of subclass_

## WHEN DO WE NEED?
+ Single point for different object creation.
+ Creating objects using `separate methods/polymorphic classes`
+ We create objects `without exposing the creation logic to the client`, client uses same *common interface* to create new type of object
+ Mitigate c'tor limitiation by __moving initialization process from c'tor to other structure__, we'll use `Factory Method`, which means *private c'tor + static method*

# BUILD
```bash
cd build ; make factory
cd build ; make virtualctor
```

# REFERENCES
+ [Vishal Chovatiya](http://www.vishalchovatiya.com/factory-design-pattern-in-modern-cpp/)
+ [Hands-On Design Patterns with C++/Chapter 13](https://www.amazon.com.tr/Hands-Design-Patterns-problems-applications/dp/1788832566)