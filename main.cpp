#include "stdio.h"
#include "string.h"
#include "assert.h"

char* string = nullptr;

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

int getE() {
    int val1 = 0;
    val1 = getN();

    if (!(*string == '+' || *string == '-')) return val1;

    char oper = *string;
    string++;

    int val2 = getN();

    if (oper == '+') {
        val1 += val2;
    } else {
        val1 -= val2;
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