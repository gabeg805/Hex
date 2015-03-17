===========
What is it?
===========

Convert the input string into its decimal, hexadecimal, and binary interpretation.



=============
Documentation
=============

This program works in the following way:
    
    $ ./hex -h 1234
    Decimal: 4660
    Hex:	 0x1234
    Binary:	 0001 0010 0011 0100
    
    $ ./hex -d 1234
    Decimal: 1234
    Hex:	 0x4d2
    Binary:	 0100 1101 0010

If the input method is hexadecimal, the input string is converted into literal 
hexadecimal. On the other hand, if the input method is decimal, the input string is
converted into decimal.

Further, program documentation can be found in the header of the program.



============
Installation
============

Recompile the binary and update your PATH environment variable in your shell rc file
with:
    
    $ rm hex
    $ gcc hex.c -o hex
    $ export PATH="${PATH}":"/PATH/TO/PROGRAM/hex"

Now the program is ready for use!



========
Contacts
========

If you have any problems, feel free to email me at 'gabeg@bu.edu'.



==================
Potential Problems
==================

- TBD



=====
To-Do
=====

- Add a "-b" option for binary input.
