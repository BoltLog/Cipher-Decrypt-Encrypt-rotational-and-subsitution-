#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*this code aims to achieve encryption and decrytion of any text into uppercase letters
this program however will only accept text not any special characters or numbers for encryption.
This code will allow encryyption and decryption in rotational and substitution ciphers
it will achieve this with file standard i/o with a basic but friendly user interface
 for program to work follow instructions when prompted to and restart for each instance of use.
Encryption and Decryption are given with separate text files make sure you fill in the text files correctly for
program to work also make sure to pick the correct option encryption, decryption and cipher type
*/

char* RotationCipherEncryption();
char* RoationCipherDecryption();
char* SubstitutionCipherEncryption();
char* SubstitutionCipherDecryption();
char* RotationBruteCrack();

int main()
{

    printf("Cipher Selection\n"); //visual input to help user navigate their options
    printf(" a) rotation cipher encryption\n");
    printf(" b) rotation cipher decryption\n");
    printf(" c) Substitution cipher enncryption\n");
    printf(" d) Substitution cipher decryption\n");
    printf(" e) Rotation Cipher brute attack\n");

    char c;
    scanf("%c", &c);
    while(c< 'a' || c> 'e') //this makes loop continue ntill correct input is entered
    {
        printf("an invalid output detected please enter a, b, c, d or e\n");
        scanf("%c", &c);
    }
        switch(c) //lets the user input actually decide on the selection
        {
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

    char str[10000], c;
    int a, b, i;
    printf("Your only UPPER CASE text file is about to be inputed:\n");
    printf("Enter your cipher key 1-26:");
    scanf("%d", &a);


    FILE *inputrotationEncryption= fopen("inputrotationEncryption.txt" , "r"); //opens and reads text.txt file
    FILE *inputrotationDecryption= fopen("inputrotationDecryption.txt" , "w"); //opens and sets file up to be written into
    while(fgets(str,10000,inputrotationEncryption))
    {

        printf("line of text is as follows:");
        puts(str); //this shows the


        for(b=0; str[b] != '\0'; b++) //this makes sure that nothing can exceed the limit of the the string as a limit in c with string is a \0
        {
            c=str[b];
            if(c>= 'A' && c<= 'Z' ) // this makes sure that the cipher is within its bounds so correct encrypted text comes out
            {

                c= c + a; //this gives each character its new value dependant by the key which is "a"
            }
            if(c>'Z')
            {

                c= c-26; //this makes characters that go over z go to the start of the alphabet again
            }
            str[b]=c;
        }
        printf("the encryption of the line is now: %s\n",str); //%s is used so the string is called if only %c was used only one character would be printed

        fputs(str,inputrotationDecryption); //writes the string into the file (as a line)
    }
    return 0;
}


char* RoationCipherDecryption()
{
    char str[10000], c;
    int a, b;

    printf("Your only UPPER CASE decrypted text file is about to be inputed:");
    printf("Enter your cipher key 1-26:");
    scanf("%d", &a);
    FILE *inputrotationDecryption= fopen("inputrotationDecryption.txt" , "r"); //opens and reads "text".txt file
    FILE *inputrotationEncryption= fopen("inputrotationEncryption.txt" , "w");
    while(fgets(str,10000,inputrotationDecryption))
    {
        printf("line of text is as follows:");
        puts(str); //displays stored info in console


        for(b=0; str[b] != '\0'; b++) //this makes sure that nothing can exceed the limit of the the string as a limit in c with string is a \0
        {
            c=str[b];
            if(c>= 'A' && c<='Z' )// this makes sure that the cipher is within its bounds so correct encrypted text comes out
            {
                c= c - a; //this gives each character its new value dependant by the key which is "a"
            }
                if(c<'A' && c+a>='A') //helps prevent other characters effecting outcome
            {
                c= c+26; //this makes characters that orginally went over z when being encrypted return to its orginal value
            }
            str[b]=c;
        }
            printf("the now decrypted line of text is: %s\n", str); //%s is used so the string is called if only %c was used only one character would be printed
            fputs(str,inputrotationEncryption); //writes the string into the file (as a line)
    }



    return 0;
}


char* SubstitutionCipherEncryption()
{
    char* key = "QWERTYUIOPASDFGHJKLZXCVBNM"; //this is the new cipher alphabet that works as an index for conversion from ASCII char* is a pointer
    int b; //this is just used as a standard int value to allow conversion of char to int then back to char

    char str[10000];
    FILE *inputSubstitutionEncryption= fopen("inputSubstitutionEncryption.txt" , "r");
    while(fgets(str,10000,inputSubstitutionEncryption))
    {
        printf("the line of text to be encrypted is as follows:");
        puts(str);
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

        printf(" The encrypted line of text is now:%s\n", cipher);
    }

    return 0;
}

char* SubstitutionCipherDecryption()
{
    char str[10000];
    char key[10000]="QWERTYUIOPASDFGHJKLZXCVBNM"; //the key used for encryption of message amd thus for decryption
    FILE *inputSubstitutionDecryption= fopen("inputSubstitutionDecryption.txt" , "r");
    while(fgets(str,10000,inputSubstitutionDecryption))
    {
        printf("the line of decrypted text is as follows:");
        puts(str);
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

        printf("the now decrypted line of text is:%s\n", str);
    }


    return 0;
}


char* RotationBruteCrack()
{

    char str[10000], c;
    int a, b,i=0,d;

    printf("Your only UPPER CASE decrypted text file is being inputed as follows:");

    FILE *inputrotationDecryption= fopen("inputrotationDecryption.txt" , "r"); //opens and reds "text".txt file
    fgets(str,10000,inputrotationDecryption);
    char tempo[10000];
    puts(str); //displays stored info in console
    int count = strlen(str);
    printf(" your cipher key 1-26 is being found wait for expected output:\n");

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
                        if(c<'A' && c+a>='A')
                        {
                            c= c+26; //this makes characters that orginally went over z when being encrypted return to its orginal value
                        }
                        tempo[b]=c; //this string is included so the orginal string keeps its orginal value
                        tempo[count]=0;

                }
                printf("the now decrypted message is attempt (key) %d: %s\n",a, tempo);

            }
    fclose(inputrotationDecryption);
    printf("Now with your gained cipher key use the rotational decryption method to write the code to a file\n");
    RoationCipherDecryption();

    return 0;
}
