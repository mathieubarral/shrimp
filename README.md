# shrimp 🦐
A basic compiler for custom compiled high-level language

## Requirements
- GCC/Clang
- CMake (version 3.0.0 minimum)
- Ninja
- Unix makefile (optionnal)
- CTest (optionnal)
- GCovr (optionnal)

## Build
To build the project you have multiples posibilities :
- Via makefile rules
- Manually
- Using an IDE that support CMake building

### Makefile
```
make release        build the project
make debug          build the project with debug logging and CTest files
make test           execute CTest and generate GCovr html coverage files
make cov            open GCovr index.html file in default browser
make clean          delete build folder
```

### Manually
```
mkdir build                                 create build folder
cmake -B build/ -DCMAKE_GENERATOR=Ninja     create the ninja files in build folder
cmake --build build/                        build the project
```

## Tests
To run unit test you have multiples posibilities :
- Via makefile rules
- Manually
- Using an IDE that support CTest

### Makefile
```
make test
```

### Manually
```
ninja -C build/ test
```

## Usage
```
shrimp <ashrmp file>
```
You can also print the help page by using :
```
shrimp -h
```