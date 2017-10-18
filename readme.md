Template for CS20 C++ Projects in VSCode
==
Place all .cpp files in the src directory
Place all .hpp files in the include directory

Follow these instructions to download CMake: https://cmake.org/install/
Once installed, run the following commands from the top level directory (Mac only):
```{r, engine='bash', count_lines}
mkdir Debug
cd Debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

Once you run the cmake command, cmake will generate all the necessary build files. Once completed the Debug
folder should now contain a tradition "make file"

Run:
```{r, engine='bash', count_lines}
make
```
to build your project. Then run:
```{r, engine='bash', count_lines}
./main
```
to run your project. 
