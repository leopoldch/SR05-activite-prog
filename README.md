# SR05 - Activity 2

This project is part of my computer engineering studies at the Université de Technologie de Compiègne.

## Objective

The goal of this activity is to develop a minimalist distributed program using a Linux shell pipeline. The first program instance writes a message to `stdout`, which is then redirected through a Linux pipe to the next instance.

## Build Instructions

### Dependencies

This project relies on ASIO for asynchronous I/O operations (specifically, file descriptors in this case). Ensure that ASIO is installed on your system before compiling.

#### Installation per OS:

- **Debian-based distributions (Ubuntu, Debian, etc.)**
  ```sh
  sudo apt install libboost-dev libboost-system-dev
  ```
- **Fedora**
  ```sh
  sudo dnf install boost-devel
  ```
- **Windows (via vcpkg)**
  ```sh
  vcpkg install boost-asio
  ```

### Compilation

To build the project, execute the following commands:

```sh
mkdir build && cd build
cmake ..
make
```

After successful compilation, the project is ready to use.

## Usage Example

Run multiple instances of the program in a pipeline:

```sh
./prog test | ./prog | ./prog
```

Each instance will process and forward the message accordingly.

Enjoy experimenting with inter-process communication!
