#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*this code aims to achieve encryption and decrytion of any text into uppercase letters
this program however will only accept text not any special characters or numbers
this code will allow encryyption and decryption in rotstional and subsitution ciphers
it will achieve this with file and standard input and output with a user interface
 follow instructions when prompted to and the program should work
 input and output are given with separate c files make sure you feel in the input file correctly for
 program to work also make sure to pick the correct option encryption, decryption and cipher type
*/

char* RotationCipherEncryption();
char* RoationCipherDecryption();
char* SubstitutionCipherEncryption();
char* SubstitutionCipherDecryption();
char* RotationBruteCrack();

int main() {

    printf("Cipher Selection\n"); //visual input to help user navigate their options
    printf(" a) rotation cipher encryption\n");
    printf(" b) rotation cipher decryption\n");
    printf(" c) Substitution cipher enncryption\n");
    printf(" d) Substitution cipher decryption\n");
    printf(" e) Rotation Cipher brute attack\n");

    char c;
    scanf("%c", &c);
    while(c< 'a' || c> 'e') { //this makes loop continue ntill correct input is entered
        printf("an invalid output detected please enter a, b, c, d or e\n");
        scanf("%c", &c);
    }
    switch(c){ //lets the user input actually decide on the selection
        case 'a': RotationCipherEncryption();
        break;
        case 'b': RoationCipherDecryption();
        break;
        case 'c': SubstitutionCipherEncryption();
        break;
        case 'd': SubstitutionCipherDecryption();
        break;
        case 'e': RotationBruteCrack();
        break;

    }
    return 0;
}


char* RotationCipherEncryption()
{
    char str[100], c;
    int a, b;
    printf("Your only UPPER CASE text file is being inputed as follows:");

    FILE *inputrotationEncryption= fopen("inputrotationEncryption.txt" , "r"); //opens and reds text.txt file
    fgets(str,100,inputrotationEncryption);
    puts(str); //this
    fclose(inputrotationEncryption);
    printf("Enter your cipher key 1-26:");
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
        printf("the now encrypted message is: %s", str); //%s is used so the string is called if only %c was used only one character would be printed
        return 0;
}


char* RoationCipherDecryption()
{
    char str[100], c;
    int a, b;

    printf("Your only UPPER CASE decrypted text file is being inputed as follows:");

    FILE *inputrotationDecryption= fopen("inputrotationDecryption.txt" , "r"); //opens and reds "text".txt file
    fgets(str,100,inputrotationDecryption);
    puts(str); //displays stored info in console
    fclose(inputrotationDecryption);
    printf("Enter your cipher key 1-26:");
    scanf("%d", &a);

        for(b=0; str[b] != '\0'; b++) //this makes sure that nothing can exceed the limit of the the string as a limit in c with string is a \0
        {
            c=str[b];
            if(c>= 'A' && c<= 'Z' )// this makes sure that the cipher is within its bounds so correct encrypted text comes out
            {
                c= c - a; //this gives each character its new value dependant by the key which is "a"
            }
                if(c<'A' && c>' ')
            {
                c= c+26; //this makes characters that orginally went over z when being encrypted return to its orginal value
            }
            str[b]=c;
        }
            printf("the now decrypted message is: %s", str); //%s is used so the string is called if only %c was used only one character would be printed


        return 0;
}




char* SubstitutionCipherEncryption()
{
    char* key = "QWERTYUIOPASDFGHJKLZXCVBNM"; //this is the new cipher alphabet that works as an index for conversion from ASCII char* is a pointer
    int b; //this is just used as a standard int value to allow conversion of char to int then back to char

    char str[100];
     printf("Text to be encrypted by subsititution:\n");
    FILE *inputSubstitutionEncryption= fopen("inputSubstitutionEncryption.txt" , "r");
    fgets(str,100,inputSubstitutionEncryption);
    puts(str);
    fclose(inputSubstitutionEncryption);
    int count = strlen(str); //gets an integer value to the length of the string using string.h from standard c library
    char cipher[count];
   for(b=0; str[b] != '\0'; b++) //this allows the conversion of ASCII int values to be assigned to their new int values used for the ciper text
    {
        int index = ((int) str[b]) - 65; //this causes Q to take on the new value of A etc etc as it reassigns according to ASCII values done by conversion to int
        if(index < 0)
        {
            cipher[b] = ' ';//this helps stop other ascii values affecting input as it makes a whitespace
        }
        else
        {
            cipher[b] = key[index]; // this assigns the letters the pointer uses to the cipher with the newly calculated index
        }
    }
    cipher[count] = 0;// ends the string

    printf(" The encrypted message is:\n %s", cipher);
    return 0;
}

char* SubstitutionCipherDecryption()
{
   char str[100];
   char key[100]="QWERTYUIOPASDFGHJKLZXCVBNM";
    printf(" text to be decrypted by subsititution:\n");
    FILE *inputSubstitutionDecryption= fopen("inputSubstitutionDecryption.txt" , "r");
    fgets(str,100,inputSubstitutionDecryption);
    puts(str);
    fclose(inputSubstitutionDecryption);
    for(int b=0; str[b] != '\0'; b++) //this allows the conversion of ASCII int values to be assigned to their new int values used for the text conversion
    {
        for(int a=0; a<26; a++) //allows the conversion of ascii in the specified range
        {
            if(str[b]==key[a]) //Checks along the string until it matches with a value on the key
            {
                str[b]=a+65; //this makes the ASCII values fall in the expected range Q to A, W to B etc in the case of this key
                a=26; //this causes the value of "a" to normalise the string value to the specific conditions set and not disturb the expected result
            }
        }
    }

    printf("the now decrypted message is:\n%s", str);

    return 0;
}


char* RotationBruteCrack()
{

    char str[100], c;
    int a, b,i=0;

    printf("Your only UPPER CASE decrypted text file is being inputed as follows:");

    FILE *inputrotationDecryption= fopen("inputrotationDecryption.txt" , "r"); //opens and reds "text".txt file
    fgets(str,100,inputrotationDecryption);
    char tempo[100];
    puts(str); //displays stored info in console
    fclose(inputrotationDecryption);
    int count = strlen(str);
    printf(" your cipher key 1-26 please enter in order and wait for expected output:\n");

            while(i<26) //this causes a loop to happen until i=25 thus running 26 times as i=0
            {
                i++;
                a=i;

            for(b=0; str[b] != '\0'; b++) //this makes sure that nothing can exceed the limit of the the string as a limit in c with string is a \0
            {
                c=str[b];
                if(c>= 'A' && c<= 'Z' )// this makes sure that the cipher is within its bounds so correct encrypted text comes out
                {
                    c= c - a; //this gives each character its new value dependant by the key which is "a"
                }
                        if(c<'A' && c>' ')
                    {
                        c= c+26; //this makes characters that orginally went over z when being encrypted return to its orginal value
                    }
                tempo[b]=c; //this string is included so the orginal string keeps its orginal value
                tempo[count]=0;

            }
                printf("the now decrypted message is attempt %d: %s\n",a, tempo);
            }

        return 0;

    }
