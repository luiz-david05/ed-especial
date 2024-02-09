# To compiler

- in windos and vscode: just run the debuger (F5) and the file will be compiled and executed.

- in linux: run the following command in the terminal:
```bash
gcc -o q1 q1.c
```

# Decimal and data types in C

```c	
printf("%.nf\n",a);
```

where n is the number of digits after the decimal point to be displayed. You can 

specify value of n
maximum value of n is 6 also is its default value
for e.g. printf("%.2f",a); will display decimal number upto two digits after the decimal place

You can know more about displaying data as

- %d: decimal value (int) 
- %c: character (char) 
- %s: string (const char *) 
- %u: unsigned decimal value (unsigned int) 
- %ld: long int (long) 
- %f: float value (float or double) 
- %x: decimal value in Hexadecimal format 
- %o: decimal value in octal format