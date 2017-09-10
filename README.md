# HEX

## What is it?

Convert the input string into its decimal, hexadecimal, and binary interpretation.

## Example

Running the *--dec* option, the output looks like the following:
```
$ ./hex --dec 1234
Decimal: 1234
Hex:	 0x4d2
Binary:	 0100 1101 0010
```

Conversely, running the *--hex* option, the output looks like:
```
$ ./hex --hex 0x1234
Decimal: 4660
Hex:	 0x1234
Binary:	 0001 0010 0011 0100
```

## Installation

To install, run the command:
```
$ make
```

or:
```
$ make install
```

Now the program is ready to use!

## To-Do

```
- Add a --bin option to accept binary input
```
