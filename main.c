/* Caesar Cipher project by Mitchell Greenan.
   
   Project will be designed to (hopefully) take in a message that is
   input from user and then be encrypted.
 */
#include<stdio.h> 

void encryptRotationCi (void);

void decryptRotationCi (void);

void encryptSubCi (void);

int main()
{
    // create task menu for user.
    char option = 'c';
    
    printf("\nWassup'?! Select a task to operate below by entering 'a', 'b','c' or 'd' followed by the 'Enter' key.\n\n");
    printf("(a) Encrypt a word with rotation cipher!\n");
    printf("(b) Decrypt a word with rotation cypher!\n");
    printf("(c) Encrypt a word with substitution cipher!\n");
    printf("(d) Decrypt a word with substitution cipher!\n\n");
    
    //scanf("%c", &option);
    
    switch (option) {
        case 'a': encryptRotationCi ();
                  break;
        case 'b': decryptRotationCi ();
                  break;
        case 'c': encryptSubCi ();
                  break;
        //case 'd': decryptSubCi ();
        //          break;
    }
}

void encryptRotationCi (void) {
    
    char alph[100] /*= "GETLIT"*/;
    int i; // counter
    int k = 1; // key value
    int m; // ASCII value of letter 'G'
    
    sprintf(alph, "GETLIT"); /* storing 'GETLIT' into array.
                              // With a key shift of +1, "HFUMJU" 
                              // should be displayed. */
    
    // creating loop to apply algorithm that encrypts the phrase.
    for (i = 0; i < alph[i]; i++) {
        if ((alph[i] > 64) && (alph[i] < 91)) {
            m = alph[i]; // allocates variable 'm' to first value of alpharray[] (G), then increments to following letter.
            alph[i] = (((m - 65) + k) % 26) + 65; //caesar algorithm for encryption
            printf("%c", alph[i]);
        }
    }
    return;
}

void decryptRotationCi (void) {
    
    char alph[100];
    int i; // counter
    int k = 1; // key value
    int m; // will be used for storing initial value of array
    
    sprintf(alph, "HFUMJU");//"HFUMJU"); /* storing 'HFUMJU' into array.
                             //  With a key shift of -1, "GETLIT" 
                              // should be displayed. */
    
    // creating loop to apply algorithm that encrypts the phrase.
    for (i = 0; i < alph[i]; i++) {
        m = alph[i]; // allocates variable 'm' to first value of alpharray[] (H), then increments to following letter.
        alph[i] = (((m - 65) - k) % 26) + 65; //caesar algorithm for decryption
        if (alph[i] < 65) { // to save code from breaking (hopefully)
            alph[i] = 90;
        }
        printf("%c", alph[i]);
    }
    return;
}

void encryptSubCi (void) {
    
    char oldAlph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char newAlph[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char subCi[100];
    int i, j;
    
    sprintf(subCi, "GETLIT"); // encrypted code should read "UTZSOZ"
    printf("%s\n", subCi);
    
    for (i = 0; i < oldAlph[i]; i++) {
        printf("%c", oldAlph[i]);
    }
    printf("\n");
    
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 26; j++) {
            if (subCi[i] == oldAlph[j]) {
                subCi[i] = newAlph[j];
                break;
            }
            
        }
        
    } printf("%s", subCi);
    return;
}
