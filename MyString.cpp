#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

    String(const char* str = "") {
        this->size = strlen(str);
        char* temp = new char[size + 1];
        strcpy(temp, str);
        this->str = temp;
    }

    String(size_t n, char c) :size(n), str(new char[n + 1]) {
        for (int i = 0; i < n; i++)str[i] = c;
        str[n + 1] = '\0';
    }

    ~String() {
        delete[] str;
    }

    void append(String& other) {
        size_t new_size = size + other.size;
        char* temp = new char[new_size + 1];
        strcpy(temp, str);
        for (int i = size, j = 0; i < new_size + 1; i++, j++)temp[i] = other.str[j];
        size = new_size;
        delete[] str;
        str = temp;
    }

    String(const String& other)
        :size(other.size), str(new char[size + 1]) {
        strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (&other == this)return *this;
        size = other.size;
        delete[] str;
        str = new char[size + 1];
        strcpy(str, other.str);
        return *this;
    }

private:
    size_t size;
    char* str;
};