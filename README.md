# SUMMARY
Includes brief explanations and code snippets for each of the design pattern. One can `cd` to regarding directory to see more details.

+ *BEHAVIORAL DESIGN PATTERNS*  &rarr; Deal with the `assignment of responsibilities` between objects.  <br>
                                &rarr; Make the interactions between the objects easy & `loosely coupled`.

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
```