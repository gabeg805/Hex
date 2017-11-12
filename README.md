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

Running the *--hex* option, the output looks like:

```
$ ./hex --hex 0x1234
Decimal: 4660
Hex:	 0x1234
Binary:	 0001 0010 0011 0100
```

Note: The input value does not need to have "0x" preceeding it. The following
will also work.

```
$ ./hex --hex 1234
Decimal: 4660
Hex:	 0x1234
Binary:	 0001 0010 0011 0100
```

Running the *--bin* option, the output looks like:

```
$ ./hex -B "100010000"
Decimal : 272
Hex     : 0x110
Binary  : 0001 0001 0000
```

Note: The input value does not need to have "0x" preceeding it. The following
will also work.

```
$ ./hex -B "1 0001 0000"
Decimal : 272
Hex     : 0x110
Binary  : 0001 0001 0000
```

## Installation

To install, run the command:
```
make
```

## Uninstall

To uninstall, run the command:
```
make clean
```