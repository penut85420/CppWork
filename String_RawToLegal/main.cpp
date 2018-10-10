#include <stdio.h>
#include <string.h>

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char s[1024];

    while (gets(s)) {
        int len = strlen(s);
        putchar('\"');
        for (int i = 0; i < len; i++) {
            if (s[i] == '\"')
                putchar('\\');
            putchar(s[i]);
        }
        printf("\" + \n");
    }

    return 0;
}
