# ft_printf
This is a homemade printf, with all its options.

There isn't much .exe to try here. The project will compile a library using a homemade printf.

This printf include options from the real printf. It also remoove the buffer problem that the real printf has.

You can compile the library by using :

```bash
$ make
```
To create a libftprintf.a.

The ft_printf should be used like this :

```
ft_prinf("This is a sentence\n");
```

It has option to display variable, like this :

```
ft_printf("This is an int : %d. This is a char %c. This is a string %s.\n", 10, 'A', "Test");
```

**SHORT VERSION**

Variable are : sSpdDioOuUxXcC
%% is handled.
Flags #0-+ and space are handled.
Field width is handled.
Precision is handled.
Length modifier hh h l ll j z are handled.

For details look at the officiel usage of those options : http://man7.org/linux/man-pages/man3/printf.3.html.


**LONG VERSION**

The variables options are :

s : string.
S : Unicod string.
p : printing the address of a pointer.
d : printing an integer.
D : d, with option 'l' included.
i : integer.
o : unsigned int, octal number.
O : o, with option 'l' included.
u : unsigned int, decimal number.
U : u, with option 'l' included.
x : unsigned int, base 16 number.
X : x, with option 'l' included.
c : char.
C : Unicod char.

The flags are included, you can add them :

#: The value should be converted to an "alternate form".  For o
       conversions, the first character of the output string is made
       zero. For x andX conversions, a nonzero result has the string "0x".
       For a, A, e, E, f, F, g,
       and G conversions, the result will always contain a decimal
       point, even if no digits follow it.
       For g and G conversions, trailing zeros are not
       removed from the result as they would otherwise be.
       
0: The value should be zero padded. For d, i, o, u, x, X, a, A,
       e, E, f, F, g, and G conversions, the converted value is
       padded on the left with zeros rather than blanks.
       If the 0 and - flags both appear, the 0 flag is ignored.
       If a preci‐sion is given with a numeric conversion (d, i, o, u, x, andX), the 0 flag is ignored
              
-: The converted value is to be left adjusted on the field boundary
              The converted value is padded on the right with blanks.
              
+: A sign (+ or -) should always be placed before a number pro‐
              duced by a signed conversion.  By default, a sign is used only
              for negative numbers.  A + overrides a space if both are used.   
              
' ': (a space) A blank should be left before a positive number (or
              empty string) produced by a signed conversion.         


For more informations you can look at the pdf included to the project.
