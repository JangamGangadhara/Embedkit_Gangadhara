# EmbedKit_Gangadhara

**Author:** Jangam Gangadhara

## Module: Ring Buffer

A fixed-size circular buffer implemented in C using head, tail, and count management.

### Features

- Circular buffer implementation
- Buffer full detection
- Buffer empty detection
- FIFO data handling
- Wrap-around using bit masking
- Standalone demonstration in main()

## Build

```bash
gcc -Wall -std=c99 ring_buffer.c -o ring_buffer
```

## Run

```bash
./ring_buffer
```

## Description

This program demonstrates a circular buffer of size 8. It performs:

1. Buffer fill operation
2. Write attempt on full buffer
3. Multiple read operations
4. Buffer wrap-around
5. Buffer empty condition handling
