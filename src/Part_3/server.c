#include <stdio.h>
#include <fcgi_stdio.h>

int main(void) {
    while (FCGI_Accept() >= 0) {
        printf("Content-Type: text/html\n\n");
        printf("Hello World!\n");
    }
    return 0;
}