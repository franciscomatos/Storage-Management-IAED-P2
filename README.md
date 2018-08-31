# Message Board

This project consists on a program for managing the inventory of a warehouse. Each product contains an **id code** (**key**) and a its **current stock**. The user interaction with the program occurs through a set of lines composed by a letter (the command itself) and eventually one or two arguments.

## Commands Available

Command | Description
------------ | -------------
a | Increments or reduces the number of units associated with the product with the given code. If the given code doesn't exist, a new product is created.
l | Lists every product alphabetically.
m | Displays the product with the biggest number of units in stock.
r | Removes the product with the given code.
x | Closes the program.

## Getting Started

### Prerequisites

You will need the gcc compiler installed in your machine.

### Compiling

Download the .zip and compile the files using the following command:

```
$ gcc -Wall -o proj2 *.c

```
which should create the executable file 'proj2'.


## Running the Tests

Make sure the executable file is in the same directory as the input files contained in 'p2_exemplos_enunciado'.
The program should be executed in the following way:

```
$ ./proj2 < exemplo01.in > exemplo01.myout
```

Afterwards you can compare your output with the foressen output using:

```
$ diff exemplo01.out exemplo01.myout
```

## Authors

* Francisco Matos

## Acknowledgments

Some code used in the 'link.c' and 'link.h' was given by the teachers of the course to help the students implement the chosen data structure in the project.

## Evaluation

17/20
