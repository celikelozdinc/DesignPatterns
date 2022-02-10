# WHY DO WE NEED?
+ To define/perform __an operation__ on a group of similar kind of __objects/hieararchy__
+ Represents __an operation__ to be performed on a __object structure__ by letting you define a new operation without changing the objects on which it operates.

## WHEN DO WE NEED?
+ While working on a hierarchy of classes where you want to run different method based on the concrete type, but trying to avoid `dynamic_cast<>()` operator

## Identification
+ `visit()` and `accept()` methods 
+ Sepearates __objects__ from __operations__ &rarr; HIGH COHESION DESIGN PRINCIPLE
+ *Runtime* *double dispatch* &rarr; we can resolve one polymorpic interface at a time, we can only resolve virtual calls on one type at the same time.
    + If you would have *compile time* **multiple-dispatch** &rarr; FUNCTION OVERLOADING

# BUILD
```bash

```


# REFERENCES
+ [FluentCpp](https://www.fluentcpp.com/2022/02/09/design-patterns-vs-design-principles-visitor/)
+ [Double Dispatch by Vishal Chovatiya](https://dzone.com/articles/double-dispatch-in-c)
+ [Visitor Design Pattern by Vishal Chovatiya](http://www.vishalchovatiya.com/double-dispatch-visitor-design-pattern-in-modern-cpp/)
