# Authentication Overflow

This lab explores a classic buffer overflow vulnerability in C. You will investigate how improper input handling can lead to unauthorized access.

## Learning Outcomes

After completing this experience, learners will be able to:

1. Identify vulnerable functions in C source code
2. Explain how memory layout affects program execution
3. Exploit a buffer overflow to bypass authentication

## Usage

Compile the program using the provided makefile:

```
make
```

Run the program and try different inputs:

```
./auth
```

## Testing

Verify the basic functionality of the login system:

```
make test
```

## Tasks

1. Analyze `auth.c` to craft a set of inputs that allow you to successfully authenticate without a correct password.
2. Document your findings, including the exact payload used and why it works.

## Resources

- [Buffer Overflow (Wikipedia)](https://en.wikipedia.org/wiki/Buffer_overflow)
- [C Memory Layout](https://en.wikibooks.org/wiki/C_Programming/Memory_management)
- [The gets() Function](https://linux.die.net/man/3/gets)

## Security Note

Modern compilers and operating systems include protections against these attacks (like stack canaries and address space layout randomization). This lab disables those protections for educational purposes using specific compiler flags in the `makefile`.
