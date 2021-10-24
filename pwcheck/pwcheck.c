#include <stdio.h>

int main(int argc, char const *argv[]){
    char pw[20];
    fgets(pw, 20, stdin);

    printf("%s", pw);
    
    return 0;
}
