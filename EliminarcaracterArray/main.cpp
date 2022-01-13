#include <stdio.h>

void c_remove(char *n, char *s, char c) {   // renamed because remove() is predefined
    while (*s) {                            // no need for strlen()
        if (*s != c)                        // test if char is to be removed
            *n++ = *s;                      // copy if not
        s++;                                // advance source pointer
    }
    *n = '\0';                              // terminate new string
}

int main(void) {                            // correct signature
    char s[16], c, n[16];
    printf("Please enter string: ");
    scanf("%s", s);
    printf("Which character do you want to remove? ");
    scanf(" %c", &c);
    c_remove(n, s, c);                      // pass target string pointer too
    printf("The new string is %s", n);
    return 0;
}
