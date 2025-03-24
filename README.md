# SR05 - Activity Programming

This project is part of my computer engineering studies at the Université de Technologie de Compiègne.

## Objective

The goal of this activity is to develop a minimalist distributed program using a Linux shell pipeline. The program writes a message to `stdout` while receiving messages from `stdin`.

---

## Functionality

The main program runs in an infinite `while` loop that performs two tasks:

1. **Emit Messages**  
    It emits a message to `stdout`, which can be redirected using a Linux pipe.

2. **Receive Messages**  
    It checks for incoming messages using the `listener` function. If data is available, the program reads it from `stdin`.

### Write Function

The `write` function outputs the message directly to `stdout`. Alternatively, functions like `printf` or `sprintf` could also be used.

### Read Function

The `read` function first checks `stdin` using the `select` function to verify if there is data to read. If data is available, it reads the bytes from the file descriptor into a buffer and prints it to `stderr` to avoid passing it to the next program in the pipeline.

---

## Compilation

To build the project, execute the following commands:

```sh
mkdir build && cd build
cmake ..
make
```

After successful compilation, the project is ready to use.

---

## Formatting

To format the project (once you have compiled), execute the following command:

```sh
make format
```

> **Note:** Ensure `clang-format` is installed before running the command.

---

# Simple Network Setup and Atomicity Test

## Network Verification

To verify communication between different instances of the program, you can build a simple network in the shell.

### Link Between Two Sites

```bash
./prog | ./prog
```

This command establishes a straightforward connection where one site’s output is directly piped into another site’s input.

### Ring Configuration

```bash
mkfifo /tmp/f
./prog < /tmp/f | ./prog | ./prog > /tmp/f
```

This setup creates a named pipe (`/tmp/f`) and forms a ring connection among three instances of the program.

---

## Atomicity Verification

To test if the send and receive operations behave atomically (i.e., they complete entirely without interruption), add a loop that artificially prolongs these operations.

### Example in Pseudocode

```pseudo
for i in 1..N:
     write "." to stderr
     sleep(10 seconds)
```

This ensures each send/receive step takes noticeable time, allowing you to observe whether partial operations occur.

---

## Debug Mode

To further test atomicity, run the programs in debug mode:

```bash
./prog test -d | ./prog -d | ./prog -d
```

Enabling the debug mode (`-d`) provides detailed logs to confirm whether operations are indeed atomic.


> README generated using ai (prompt :  `please rephrase my README.md and format it to enhance lisibilty`)