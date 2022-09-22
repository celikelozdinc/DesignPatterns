# SUMMARY
&rarr; Reusable solutions to commonly occuring problems
&rarr; Includes brief explanations and code snippets for each of the design pattern. One can `cd` to regarding directory to see more details. <br>

+ *CREATIONAL DESIGN PATTERNS*
&rarr; Provides structure to _create objects easily_, reuse existent code.

<br>

+ *STRUCTURAL DESIGN PATTERNS*
&rarr; Provides structure that helps _assemble objects/classes_ into larger structures.

<br>

+ *BEHAVIORAL DESIGN PATTERNS*
&rarr; Deal with the `assignment of responsibilities` between objects.  <br>
&rarr; Make the interactions between the objects easy & `loosely coupled`. <br>
&rarr; Assign `responsibilities` between objects, take care of *communication*

# BUILD
[Generating multiple binaries](https://medium.com/@mfkhao2009/clion-one-project-multiple-executable-file-4091d07c3936)
```bash
cd build
cmake ..
make all
# Or, build individual targets
make prototype
make visitor
make adapter
make decorator
make factory
make virtualctor
make dynamictyperegistry
```