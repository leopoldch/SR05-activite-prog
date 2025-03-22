# SR05 - Activity programmation

This project is part of my computer engineering studies at the Université de Technologie de Compiègne.

## Objective

The goal of this activity is to develop a minimalist distributed program using a Linux shell pipeline. The program writes a message to `stdout` while receiving messages to `sdin`.

### Compilation

To build the project, execute the following commands:

```sh
mkdir build && cd build
cmake ..
make
```

After successful compilation, the project is ready to use.

### Misc

To format the project (once you have compiled), execute the following commands:
>Make sure to have clang-format installed before running

```sh
make format
```

## Usage Example

Run multiple instances of the program in a pipeline:

```sh
./prog test | ./prog | ./prog
```

Each instance will process and forward the message accordingly.

Enjoy experimenting with inter-process communication!
