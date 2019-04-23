/* Caesar Cipher project by Mitchell Greenan.
   
   Project will be designed to (hopefully) take in a message that is
   input from user and then be encrypted. Then decrypt given message.
 */
#include<stdio.h> 

void encryptRotationCi (void); // function prototype for rotation cipher encryption.

void decryptRotationCi (void); // function prototype for rotation cipher decryption.

void encryptSubCi (void); // function prototype for substitution cipher encryption.

void decryptSubCi (void); // function prototype for substitution cipher decryption.

int main()
{
    FILE *fp;
    char option; //= 'b'; // initialising type 'char' variable so user is able to type readable characters for menu selection.
    
    fp = fopen("menuselect.txt", "r");
    
    
    if (fp == NULL) {
        printf("Error: file not found.");
        return 0;
    }
    
    // create task menu for user.
    printf("\nWassup'?! Select a task to operate below by entering 'a', 'b','c' or 'd' followed by the 'Enter' key.\n\n");
    printf("(a) Encrypt a word with rotation cipher!\n");
    printf("(b) Decrypt a word with rotation cypher!\n");          
    printf("(c) Encrypt a word with substitution cipher!\n");
    printf("(d) Decrypt a word with substitution cipher!\n\n");  // menu selection corresponds to each task. 
    
    fscanf(fp, "%c", &option);
    
    switch (option) {
        case 'a': encryptRotationCi ();  // switch() case used for menu selection, followed 
                  break;                 // by function prototype for each case.
        case 'b': decryptRotationCi ();
                  break;
        case 'c': encryptSubCi ();
                  break;
        case 'd': decryptSubCi ();
                  break;
        default: printf("Invalid selection...\n\nTry again.");
    }
    
    fclose(fp);
}

// The following function will be used to encrypt using the rotation cipher.

void encryptRotationCi (void) {
    
    FILE *fp;
    char alph[100];
    int i; // counter
    int k = 1; // key value
    int m; // will be used in loop to rotate through 'alph[]' array.
    
    fp = fopen("encrypt.txt", "r");
    
    if (fp == NULL) {
        printf("Error: file not found.");
        return;
    }
    
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%c", &alph[i]);
    }
    
    printf("%s\n\n", alph);

    // creating loop to apply algorithm that encrypts the phrase.
    for (i = 0; i < alph[i]; i++) {
        if ((alph[i] > 64) && (alph[i] < 91)) {
            m = alph[i]; // allocates variable 'm' to first value of alpharray[] (G), then increments to following letter.
            alph[i] = (((m - 65) + k) % 26) + 65; //caesar algorithm for encryption
            printf("%c", alph[i]);
        }
    }
    
    fclose(fp);
    
    return;
}

// The following function will be used to decrypt using the rotation cipher.

void decryptRotationCi (void) {
    
    FILE *fp;
    char alph[100];
    int i; // counter
    int k = 7; // key value
    int m; // will be used for storing initial value of array
    
    fp = fopen("RoDecrypt.txt", "r");
    
    if (fp == NULL) {
        printf("Error: file not found.");
        return;
    }
    
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%c", &alph[i]);
    }
    
    printf("%s\n\n", alph);
    
    // creating loop to apply algorithm that decrypts the phrase.
    for (i = 0; i < alph[i]; i++) {
        m = alph[i]; // allocates variable 'm' to first value of alpharray[] (H), then increments to following letter.
        alph[i] = (((m - 65) - k) % 26) + 65; //caesar algorithm for decryption
        if (alph[i] < 65) { // to save code from breaking (hopefully)
            alph[i] = alph[i] + 26;
        }
        printf("%c", alph[i]);
    }
    return;
}

// The following function will be used to encrypt using the substitution cipher.

void encryptSubCi (void) {
    
    char oldAlph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // array to store initial alphabet.
    char newAlph[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // array to store the "new alphabet" which will be used to scramble he given word.
    char subCi[100]; // array that will store the word to encrypt.
    int i, j; // will be used as counter for "oldAlph[]" and "newAlph[]".
    
    sprintf(subCi, "GETLIT"); // encrypted code should read "UTZSOZ"
    printf("%s\n", subCi); // printing given word before being encrypted for comparison.
    
    /* the following loop will be used to search through each array index of both
       "oldAlph[]" and "newAlph[]". When location is found that matches the 0th 
       index of "subCi[]" array in the "oldAlph[]" array, that letter will then be
       swapped with the letter of the same index value in "newAlph[]". Loop should
       continue this beahaviour until every letter in "subCi[]" has been swapped.
       
       e.g subCi[0] = G, this letter corresponds with 'U' in the "newAlph[]"
       i.e G will encrypt to U and so on. */
      
    for (i = 0; i < subCi[i]; i++) {
        for (j = 0; j < 26; j++) {
            if (subCi[i] == oldAlph[j]) {
                subCi[i] = newAlph[j];
                break;
            }          
        }
    } 
    printf("%s", subCi);
    return;
}

// The following function will be used to decrypt using the substitution cipher.

void decryptSubCi (void) {
    
    char oldAlph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // array to store initial alphabet.
    char newAlph[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // array to store the "new alphabet" which will be used to scramble he given word.
    char subCi[100]; // array that will store the word to encrypt.
    int i, j; // will be used as counter for "oldAlph[]" and "newAlph[]".
    
    sprintf(subCi, "UTZSOZ"); // encrypted code should read "UTZSOZ"
    printf("%s\n", subCi); // printing given word before being encrypted for comparison.
    
    /* the following loop will be used to search through each array index of both
       "oldAlph[]" and "newAlph[]". When location is found that matches the 0th 
       index of "subCi[]" array in the "oldAlph[]" array, that letter will then be
       swapped with the letter of the same index value in "newAlph[]". Loop should
       continue this beahaviour until every letter in "subCi[]" has been swapped.
       
       e.g subCi[0] = G, this letter corresponds with 'U' in the "newAlph[]"
       i.e G will encrypt to U and so on. */
      
    for (i = 0; i < subCi[i]; i++) {
        for (j = 0; j < 26; j++) {
            if (subCi[i] == newAlph[j]) {
                subCi[i] = oldAlph[j];
                break;
            }          
        }
    } 
    printf("%s", subCi);
    return;
}
