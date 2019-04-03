#include <stdio.h>
#include <stdlib.h>

//this code aims to achieve encryption and decrytion of any text into uppercase letters
//this program however will only accept text not any special characters or numbers
//this code will allow encryyption and decryption in rotstional and subsitution ciphers
//it will achieve this with file and standard input and output with a user interface
// follow instructions when prompted to and the program should work
int main() {
 
    printf("Cipher Selection\n");
    printf(" a) rotation cipher\n");
    printf(" b) subsitution cipher\n");

    char c;
    scanf("%c", &c);
    while(c< 'a' || c> 'b') {
        scanf("%c", &c);
        switch(c){

        case 'a': printf(" a) rotation cipher\n");
        break;
        case 'b': printf(" b) subsitution cipher\n");
        break;
        default: printf("an invalid output '%c' detected\n please enter a or b\n", c);
    }

    }
    return 0;
}


