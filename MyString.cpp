#define _CRT_SECURE_NO_WARNINGS //allowing us to use strcpy

#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>


struct String {

    String(const char* str = "") { //creates a string from const char* (also constructor by default)
        _size = strlen(str);
        char* temp = new char[_size + 1];
        strcpy(temp, str);
        this->str = temp;
    }

    String(size_t n, char c) :_size(n), str(new char[n + 1]) { //creates a string with n elements of char c
        for (int i = 0; i < n; i++)str[i] = c;
        str[n + 1] = '\0';
    }

    String(const String& other) // copy constructor, helps safely create a copy of a string (also allows to correctly call a function
        :_size(other._size), str(new char[_size + 1]) { //from a string object by value
        strcpy(str, other.str);
    }

    ~String() { //destructor
        delete[] str;
    }

    size_t size() const {
        return _size;
    }

    char& operator[](size_t i) { //returns chat at position i 
        return str[i];
    }
    
    char operator[](size_t i) const { //constant variation of operator[]
        return str[i];
    }
    
    String& operator=(const String& other) { //helps to safely redirect object to another string
        if (&other == this)return *this;
        _size = other._size;
        delete[] str;
        str = new char[_size + 1];
        strcpy(str, other.str);
        return *this;
    }

    std::istream& operator>>(std::istream &is) { //helps to safely redirect object to another string
        delete[] str;
        char c = 0;
        size_t i = 0;
        resize(100);
        while (c != ' ' && c != '\n' && c != '\0') {
            is >> c;
            str[i] = c;
            ++i;
            if (i >= _size) resize(_size * 1.5);
        }
        resize(i);
        str[i] = '\0';
    }

    std::istream& operator<<(std::istream& is) const { //helps to safely redirect object to another string
        char c = 0;
        char* answ = new char[100];
        while (c != ' ' && c != '\n' && c != '\0') {
            is >> c;

        }
    }

    void append(const String& other) { //append another String at the end (works with const char* via corresponding construcor)
        size_t old_size = _size;
        resize(_size + other._size);
        for (int i = old_size, j = 0; i < _size + 1; i++, j++)str[i] = other.str[j];
    }

private:
    size_t _size;
    char* str;

    void resize(size_t new_size) {
        char* new_string = new char[new_size + 1];
        for (int i = 0; i <= new_size; ++i) {
            if (i < _size)new_string[i] = str[i];
            else new_string[i] = '\0';
        }
        _size = new_size;
        delete[] str;
        str = new_string;
    }
};
