
# Day 1 — Strings & Input/Output

## 📚 Topics Covered

* Strings and character arrays in C
* Null character `'\0'`
* `NULL` vs `'\0'`
* Modifiable character arrays
* String literals
* Character pointers and string literals
* `sizeof` operator
* String input/output
* Format specifiers

## 🧵 Strings & Character Arrays

A C string is a sequence of characters terminated by the null character `'\0'`.

Example:

```c
char str[] = "hello";
```

Memory representation:

```text
h  e  l  l  o  \0
```

The compiler automatically adds `'\0'` when a string literal is used to initialize a character array.

### Important

```c
'\0'  → null character, value 0
NULL  → null pointer constant
```

They are different and should not be confused.

## 🔍 Character Array vs String

```c
char str[5] = "hello";
```

This creates an array of 5 characters:

```text
h  e  l  l  o
```

There is no space for `'\0'`, so this is a character array but **not a C string**.

Whereas:

```c
char str[] = "hello";
```

creates:

```text
h  e  l  l  o  \0
```

Therefore:

```c
sizeof(str)   // 6
```

### Empty string

```c
char arr[] = "";
```

The array contains only:

```text
\0
```

Therefore:

```c
sizeof(arr)   // 1
```

## 📝 String Literals and Pointers

```c
char str1[] = "hello";
char str2[] = "hello";
```

These create two separate character arrays, so their addresses are different.

But:

```c
char *ptr1 = "hello";
char *ptr2 = "hello";
```

The implementation may store identical string literals at the same address, or at different addresses.

Therefore:

```c
ptr1 == ptr2
```

compares the **addresses**, not the string contents.

It may be true or false.

To compare string contents, use:

```c
strcmp(ptr1, ptr2)
```

A string literal should not be modified through a pointer:

```c
char *ptr = "hello";

ptr[0] = 'H';   // Undefined behavior
```

## 🔢 sizeof()

`sizeof` gives the size in **bytes**.

Examples:

```c
sizeof("hello")  // 6
sizeof('a')      // sizeof(int), commonly 4
```

Important distinction:

```c
char ch = 'a';

sizeof(ch)       // 1
```

In C, a character constant such as `'a'` has type `int`, while a variable declared as `char` has type `char`.

## 🖨️ `%s` and Strings

With:

```c
printf("%s", str);
```

`%s` starts at the first character and continues printing until it encounters `'\0'`.

Example:

```c
char str1[10] = "hello";

str1[5] = 'x';

printf("%s", str1);
```

Initially:

```text
h e l l o \0 \0 \0 \0 \0
```

After:

```c
str1[5] = 'x';
```

it becomes:

```text
h e l l o x \0 \0 \0 \0
```

So the output is:

```text
hellox
```

The next `'\0'` terminates the string.

## ⌨️ String Input

### `scanf("%s", str)`

Reads characters until whitespace is encountered.

For input:

```text
hello world
```

`%s` reads:

```text
hello
```

### `gets()`

`gets()` is unsafe because it does not know the size of the destination buffer.

It can cause buffer overflow and stack corruption.

It should not be used in modern C programming.

### `fgets()`

Syntax:

```c
fgets(str, sizeof(str), stdin);
```

`fgets()` can read spaces and limits how much data is placed into the buffer.

For:

```c
char str[5];

fgets(str, sizeof(str), stdin);
```

it can store up to 4 characters plus the terminating `'\0'`.

If there is enough room, `fgets()` also stores the newline `'\n'`.

### `scanf("%[^\n]")`

A scanset can read spaces until a newline:

```c
scanf("%[^\n]", str);
```

A field width should be used to prevent buffer overflow.

Example:

```c
char str[6];

scanf("%5[^\n]", str);
```

This can read up to 5 characters, leaving one byte for `'\0'`.

## 🔤 Format Specifiers

| Specifier | Purpose                       |
| --------- | ----------------------------- |
| `%d`      | `int`                         |
| `%c`      | `char`                        |
| `%f`      | floating-point output         |
| `%g`      | general floating-point format |
| `%zu`     | `size_t`                      |
| `%x`      | hexadecimal                   |
| `%o`      | octal                         |
| `%hd`     | `short int`                   |
| `%u`      | `unsigned int`                |
| `%lu`     | `unsigned long int`           |

### Important: `%f`, `float`, and `double`

For `printf()`:

```c
float a = 5.5f;
double b = 5.5;

printf("%f", a);
printf("%f", b);
```

Both work with `%f` because `float` is promoted to `double` when passed through the variadic arguments of `printf()`.

For `scanf()`:

```c
scanf("%f", &a);    // float
scanf("%lf", &b);   // double
```

`scanf()` receives addresses, so the format specifier must correspond to the type of variable being stored.

### Key rule

```text
printf → receives values
scanf  → receives addresses
```

For example:

```c
printf("%d", num);
scanf("%d", &num);
```

and:

```c
printf("%c", ch);
scanf("%c", &ch);
```

For floating-point values:

```c
printf("%f", float_value);
printf("%f", double_value);

scanf("%f", &float_value);
scanf("%lf", &double_value);
```

## 🧠 Key Takeaways

* A C string must end with `'\0'`.
* `'\0'` and `NULL` are different.
* `char str[5] = "hello";` is not a null-terminated C string.
* `sizeof` gives size in bytes.
* Identical string literals may or may not have the same address.
* Pointer comparison compares addresses, not string contents.
* `strcmp()` compares string contents.
* `%s` prints until `'\0'`.
* `%s` input stops at whitespace.
* `fgets()` can read spaces and protects the buffer size.
* `gets()` should not be used.
* `printf()` receives values; `scanf()` receives addresses.
* `float` is promoted to `double` when passed to `printf()`.
* `scanf()` uses `%f` for `float` and `%lf` for `double`.

## ⚠️ Doubts / Things to Revise

* String literal storage and address sharing
* Difference between character arrays and C strings
* `printf()` vs `scanf()` format specifiers
* `fgets()` newline behavior
* Scansets and field width


