/* Caesar Cipher project by Mitchell Greenan.
   
   Project will be designed to (hopefully) take in a message that is
   input from user and then be encrypted.
 */
#include<stdio.h> 

void encryptRotationCi (void);

int main()
{
    // create task menu for user.
    char option = 'a';
    
    printf("\nWassup'?! Select a task to operate below by entering 'a', 'b','c' or 'd' followed by the 'Enter' key.\n\n");
    printf("(a) Encrypt a word with rotation cipher!\n");
    printf("(b) Decrypt a word with rotation cypher!\n");
    printf("(c) Encrypt a word with substitution cipher!\n");
    printf("(d) Decrypt a word with substitution cipher!\n\n");
    
    //scanf("%c", &option);
    
    switch (option) {
        case 'a': encryptRotationCi ();
                  break;
        //case 'b': decryptRotationCi ();
        //          break;
        //case 'c': encryptSubCi ();
        //          break;
        //case 'd': decryptSubCi ();
        //          break;
    }
}

    
void encryptRotationCi (void) {
    
    char alph[100] /*= "GETLIT"*/;
    int i; // counter
    int k = 1; // key value
    int m = 71; // ASCII value of letter 'G'
    
    sprintf(alph,"GETLIT"); /* storing 'GETLIT' into array.
                               With a key shift of +1, "HFUMJU" 
                               should be displayed. */
    
    // creating loop to apply algorithm that encrypts the phrase.
    for (i = 0; i < 6; i++) {
        m = alph[i];
        alph[i] = (((m - 65) + k) % 26) + 65; //caesar algorithm
        printf("%c", alph[i]);
    }
    return;
}
