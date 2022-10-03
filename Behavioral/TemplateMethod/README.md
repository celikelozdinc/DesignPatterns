# WHY DO NE NEED?
+ A common way to implement an `algorithm` whose overall structure is predetermined, but some of the details of the implementation need to be _customized_
+ In order to control _what can and cannot be customized_
    + The base class determines _what can and cannot be overriden_
+ In order to avoid **code duplication**
    + Highly repetitive code is a strong hint that *Template Method* may be called for.

## WHEN DO WE NEED?
- Allows the behavior of the program to change __dynamically__
- Lets us _customize_ specific parts of the algorithm
- Serves a basic _algorithm/skeleton_ method/methods
    - This method is `public but not virtual`
    - Any subclass derived from parent class has it `as a part of its interface` but can not override what it does

## Identification

# BUILD
cd build ; make templatemethod

# REFERENCES