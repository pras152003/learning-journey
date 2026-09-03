
# Important & Tricky Concepts

## 1. `'\0'` vs `NULL`

```c
'\0'   // null character, value 0
NULL   // null pointer constant
```

They are **not the same thing**.

A C string must end with `'\0'`.

---

## 2. `char str[5] = "hello";`

```c
char str[5] = "hello";
```

Creates:

```text
h  e  l  l  o
```

There is no room for `'\0'`.

Therefore, it is a **character array but not a C string**.

Compare:

```c
char str[] = "hello";
```

which creates:

```text
h  e  l  l  o  \0
```

---

## 3. `sizeof()` Gives Bytes

```c
char arr[] = "hello";

sizeof(arr);    // 6
```

Because:

```text
h e l l o \0
```

contains 6 `char` elements, and each `char` occupies 1 byte.

Important:

```c
sizeof('a')     // sizeof(int), commonly 4
```

because a character constant such as `'a'` has type `int` in C.

But:

```c
char ch = 'a';

sizeof(ch);     // 1
```

because `ch` is a `char`.

---

## 4. Identical String Literals May Share an Address

```c
char *ptr1 = "hello";
char *ptr2 = "hello";
```

`ptr1 == ptr2` compares their **addresses**, not their contents.

The implementation may store the two `"hello"` literals at:

```text
same address
```

or:

```text
different addresses
```

Therefore, do not assume `ptr1 == ptr2` will always be true.

To compare string contents:

```c
strcmp(ptr1, ptr2) == 0
```

---

## 5. String Literal Through Pointer Is Not Modifiable

```c
char *ptr = "hello";

ptr[0] = 'H';   // Undefined behavior
```

A string literal should not be modified.

But:

```c
char str[] = "hello";

str[0] = 'H';   // Valid
```

because `str` is a modifiable character array.

---

## 6. `%s` Stops at `'\0'`

```c
printf("%s", str);
```

`%s` prints characters starting from the given address until it encounters `'\0'`.

Example:

```c
char str[10] = "hello";

str[5] = 'x';

printf("%s", str);
```

Initially:

```text
h e l l o \0 \0 \0 \0 \0
```

After changing index 5:

```text
h e l l o x \0 \0 \0 \0
```

Output:

```text
hellox
```

The next `'\0'` terminates the string.

---

## 7. `%s` Input vs `%s` Output

```c
scanf("%s", str);
```

For input:

```text
hello world
```

`scanf("%s")` reads only:

```text
hello
```

because `%s` input stops at whitespace.

But:

```c
printf("%s", str);
```

prints until `'\0'`.

So the stopping conditions are different:

```text
scanf("%s")  → stops at whitespace
printf("%s") → stops at '\0'
```

---

## 8. `gets()` Is Unsafe

```c
char arr[10];

gets(arr);
```

`gets()` does not know the size of the destination buffer.

It can write beyond the array and cause buffer overflow.

`gets()` should **not** be used.

Use `fgets()` instead:

```c
fgets(arr, sizeof(arr), stdin);
```

---

## 9. `fgets()` and Buffer Size

```c
char str[5];

fgets(str, sizeof(str), stdin);
```

At most 4 characters can be stored, leaving one byte for:

```text
'\0'
```

If there is enough space, `fgets()` can also store the newline:

```text
h i \n \0
```

---

## 10. `scanf("%[^\n]")`

A scanset can read spaces:

```c
scanf("%[^\n]", str);
```

It reads until newline.

Use a field width to limit input:

```c
char str[6];

scanf("%5[^\n]", str);
```

Maximum:

```text
5 characters + '\0'
```

Therefore the array needs at least 6 bytes.

---

## 11. `printf()` vs `scanf()`

### `printf()`

Receives **values**:

```c
printf("%d", num);
printf("%c", ch);
```

### `scanf()`

Receives **addresses**:

```c
scanf("%d", &num);
scanf("%c", &ch);
```

Think:

```text
printf → value
scanf  → address
```

---

## 12. `float` and `double`

For `printf()`:

```c
float a = 5.5f;
double b = 5.5;

printf("%f", a);
printf("%f", b);
```

Both use `%f`.

A `float` is promoted to `double` when passed through the variadic arguments of `printf()`.

For `scanf()`:

```c
scanf("%f", &a);     // float
scanf("%lf", &b);    // double
```

`scanf()` receives addresses, so the format specifier must match the type of variable being stored.

---

## 13. Format Specifier Quick Reference

```text
%d    → int
%c    → char
%f    → floating-point output
%g    → general floating-point format
%zu   → size_t
%x    → hexadecimal
%o    → octal
%hd   → short int
%u    → unsigned int
%lu   → unsigned long int
```

### Important

```text
printf("%f", float_value);    → works
printf("%f", double_value);   → works

scanf("%f", &float_value);    → correct
scanf("%lf", &double_value);  → correct
```
