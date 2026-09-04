

## What is a Structure?

A structure (`struct`) in C is a **user-defined data type** used to group a collection of elements (members) of different data types under one name.

Example:

```c
struct Student {
    int id;
    char name[20];
    float marks;
};
```

Here:

* `struct Student` → user-defined structure type
* `id`, `name`, `marks` → structure members
* Members can have different data types.

### Important

The structure definition itself does **not create a structure variable/object or allocate storage for an individual object**.

Memory is allocated when we create a structure variable:

```c
struct Student s1;
```

Here, `s1` is a structure variable and storage is allocated for it.

---

## Where do we normally define a Structure?

The structure definition is usually written **before `main()`** so that it can be used by `main()` and other functions.

```c
#include <stdio.h>

struct Student {
    int id;
    float marks;
};

int main() {
    struct Student s1;

    return 0;
}
```

---

## What can we write inside a Structure?

Inside a structure, we declare **members** with their data types.

```c
struct Student {
    int id;
    float marks;
    char grade;
};
```

We cannot execute normal statements inside the structure definition.

For example, this is not a valid way to initialize a member:

```c
struct Student {
    int id = 10;       // ❌
    float marks = 90;  // ❌
};
```

Initialization is done when creating the structure variable or later.

---

# Accessing Structure Members

For a normal structure variable, use the **dot (`.`) operator**.

```c
struct Student s1;

s1.id = 101;
s1.marks = 85.5;
```

---

# Passing Structure to a Function — Pass by Value

A structure can be passed to a function by value.

```c
void display(struct Student s)
{
    printf("%d", s.id);
}
```

Calling:

```c
struct Student s1 = {101, 85.5};

display(s1);
```

A **copy of the structure** is passed to the function.

Therefore, changing `s` inside the function does not change the original `s1`.

---

# Passing Structure Using a Pointer

We can pass the **address of a structure variable** to a function.

```c
void update(struct Student *s)
{
    s->id = 200;
}
```

Calling:

```c
struct Student s1 = {101, 85.5};

update(&s1);
```

Here:

```c
&s1
```

passes the address of `s1`.

The parameter:

```c
struct Student *s
```

stores that address.

---

## Accessing Members Through a Structure Pointer

There are two ways.

### Method 1 — Dereference and Dot

```c
(*s).id = 200;
```

### Method 2 — Arrow Operator

```c
s->id = 200;
```

Both mean the same thing:

```c
(*s).id
```

and

```c
s->id
```

The `->` operator is specifically used when accessing a structure member through a pointer.

---

# Copying a Structure

One structure variable can be assigned to another structure variable of the **same structure type**.

```c
struct Student s1 = {101, 85.5};
struct Student s2;

s2 = s1;
```

Now `s2` receives a copy of the members of `s1`.

This is called **structure assignment**.

---

# Structure and Type Casting

A structure is **not automatically convertible to an unrelated structure type** using normal C type casting.

For example:

```c
struct Student s1;
struct Employee e1;

e1 = (struct Employee)s1;   // ❌ Not valid
```

Even if the structures contain similar members, they are different structure types.

However, **pointers** have different type-conversion rules, so structure pointers should be treated separately from structure objects.

---

# Important Points

1. `struct` is used to create a user-defined structure type.
2. A structure can contain members of different data types.
3. A structure definition does not create a structure object or allocate storage for an individual variable.
4. Storage for a structure object is allocated when we create a variable such as:

```c
struct Student s1;
```

5. Structure members are declared inside the structure definition.
6. The `.` operator accesses members through a normal structure variable.
7. A structure can be passed to a function **by value**.
8. When passed by value, the function receives a **copy** of the structure.
9. A structure can also be passed using a pointer.
10. `&s1` gives the address of the structure variable.
11. `struct Student *s` is a pointer to a `struct Student`.
12. `(*s).id` and `s->id` are equivalent ways to access a member through a structure pointer.
13. Structures of the same type can be copied using assignment:

```c
s2 = s1;
```

14. Unrelated structure types cannot simply be type-cast into each other.
