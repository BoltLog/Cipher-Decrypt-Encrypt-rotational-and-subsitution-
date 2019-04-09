#include <stdio.h>
#include <stdlib.h>

/*this code aims to achieve encryption and decrytion of any text into uppercase letters
this program however will only accept text not any special characters or numbers
this code will allow encryyption and decryption in rotstional and subsitution ciphers
it will achieve this with file and standard input and output with a user interface
 follow instructions when prompted to and the program should work
 input and output are given with separate c files make sure you feel in the input file correctly for
 program to work also make sure to pick the correct option encryption, decryption and cipher type
*/

char* RotationCipherEncryption();


int main() {

    printf("Cipher Selection\n");
    printf(" a) rotation cipher encryption\n");
    printf(" b) subsitution cipher\n");

    char c;
    scanf("%c", &c);
    while(c< 'a' || c> 'b') { //this makes loop continue ntill correct input is entered
        printf("an invalid output detected please enter a, b, c or d\n");
        scanf("%c", &c);
    }
    switch(c){
        case 'a': RotationCipherEncryption();
        break;
        case 'b': printf(" b) subsitution cipher\n");
        break;

    }
    return 0;
}


char* RotationCipherEncryption()
{
    char str[100], c;
    int a, b;
    printf("Your only UPPER CASE text file is being inputed as follows:");

    FILE *input= fopen("input.txt" , "r");
    fgets(str,100,input);
    puts(str);
    fclose(input);
    printf("Enter your cipher key:");
    scanf("%d", &a);

        for(b=0; str[b] != '\0'; b++) //this makes sure that nothing can exceed the limit of the the string as a limit in c with string is a \0
    {
        c=str[b];
        if(c>= 'A' && c<= 'Z' )// this makes sure that the cipher is within its bounds so correct encrypted text comes out
        {
            c= c + a; //this gives each character its new value dependant by the key which is "a"
        }
            if(c>'Z')
        {
            c= c-26; //this makes characters that go over z go to the start of the alphabet again
        }
        str[b]=c;
    }
        printf("the now encrypted message is %s", str); //%s is used so the string is called if only %c was used only one character would be printed
        return str;
}
