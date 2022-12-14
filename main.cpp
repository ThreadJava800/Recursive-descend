#include "stdio.h"
#include "string.h"
#include "assert.h"

char* string = nullptr;

int getN();
int getP();
int getT();
int getE();
int getG();

int getN() {
    int val = 0;
    const char* oldS = string;

    while ('0' <= *string && '9' >= *string) {
        val = val * 10 + (*string - '0');
        string++;
    }

    assert(string != oldS);

    return val;
}

int getP() {
    int val = 0;
    if (*string == '(') {
        string++;
        val = getE();
        assert(*string == ')');
        string++;
    } else {
        return getN();
    }

    return val;

}

int getT() {
    int val1 = getP();
    if (!(*string == '*' || *string == '/')) return val1;

    int val2 = 0;
    while (*string == '*' || *string == '/') {
        char oper = *string;
        string++;

        val2 = getP();

        if (oper == '*') {
            val1 *= val2;
        } else {
            val1 /= val2;
        }
    }

    return val1;
}

int getE() {
    int val1 = getT();
    if (!(*string == '+' || *string == '-')) return val1;

    int val2 = 0;
    while (*string == '+' || *string == '-') {
        char oper = *string;
        string++;

        int val2 = getT();

        if (oper == '+') {
            val1 += val2;
        } else {
            val1 -= val2;
        }
    }

    return val1;
}

int getG() {
    int val = getE();

    assert(*string == '\0');

    return val;
}

int main() {
    char buffer[4096] = "";
    scanf("%s", buffer);
    string = strdup(buffer);
    printf("%d", getG());

    return 0;
}