# String
My realisation of String class

It allows to work with c-style strings (arrays of chars) via easy and convinient interface avoiding all the troubles with pointers and memory leaks.

It has two fields: a pointer to a C-style string _const char* str_ and unsigned size of it (without \0) size_t __size_.

There are three constructors, one creates a string, copying a given string, and another creates a string with given amount of elements equal to a given symbol. And also there is a copy constructor.

By default it creates an empty string.

It has all the instruments to safely copy it, change and redirect to another String.

There is a bunch of overloaded operators: summ operator (works like append() ), assignment operator, outpot operator, input operator (it automatically allocates memory for 100 elements, and if the information doesn't fit, increases the size in 1.5 times.

Append and + operator work also with c-style string literals (thanks to constructor).
