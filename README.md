# _printf Function README

## ALX Software Engineering Program Group Project

This project is part of the ALX Software Engineering Program, a rigorous and comprehensive program that equips students with the skills and knowledge needed to excel in software engineering.

## Overview

This project is a collaborative approach to create a custom `printf` function that extends the functionality of the standard `printf` from `stdio.h`. The custom `printf` function, denoted as `_printf`, has been designed to provide versatile formatting capabilities and handle various conversion specifiers, flags, length modifiers, and custom options.

## Functionality

**Function Prototype:** `int _printf(const char *format, ...);`

The `_printf` function returns the number of printed characters, excluding the null byte used to terminate strings.

**Output Destination**

The output produced by `_printf` is written to the standard output stream, typically the terminal.

**Format String**

The format string passed to `_printf` is a character string comprised of zero or more directives. It follows the conventions and syntax described in "man 3 printf" for more details on formatting.

**Supported Conversion Specifiers**

The `_printf` function supports the following conversion specifiers:

- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%%`: Prints a percent sign.
- `%d` and `%i`: Prints signed integers.
- `%b`: Converts an unsigned integer to binary.
- `%u`: Prints unsigned integers.
- `%o`: Prints octal integers.
- `%x`: Prints hexadecimal integers (lowercase).
- `%X`: Prints hexadecimal integers (uppercase).
- `%S`: Prints strings with special handling for non-printable characters.
- `%p`: Print pointers in hexadecimal format.
- `%R`: Prints the ROT13-encrypted string.

**Flags, Length Modifiers, Field Width, and Precision**

The `_printf` function also supports various formatting options, including:

- Flags: +, space, #.
- Length modifiers: l and h.
- Field width and precision: e.g., `%10s`, `%.2f`.
- The 0 flag character for zero-padding.
- The - flag character for left-justifying output.

**Output Buffer**

To optimize performance and minimize system calls, `_printf` employs a local buffer of 1024 characters for output. This buffer accumulates formatted data before being written to the standard output.

**Special Handling for Non-Printable Characters**

For the `%S` specifier, non-printable characters (with ASCII values less than 32 or greater than or equal to 127) are printed as `\x`, followed by the ASCII code value in hexadecimal (uppercase), always consisting of two characters.

## Contributions

This project was a collaborative effort between Queendarlin Nnamani and Okanlawon Martins. Each contributor played a vital role in implementing specific features and ensuring the correct integration of all components.

Thank you for your interest in our project! We hope it is a valuable addition to your C programming toolkit.
