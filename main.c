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
    FILE *fp; // initialising fp as file pointer
    char option; // initialising type 'char' variable so user is able to type readable characters for menu selection.
    
    fp = fopen("menuselect.txt", "r+"); // opening file to be read
    
    // incase file is missing.
    if (fp == NULL) {
        printf("Error: file not found.");
        return 0;
    }
    
    // create task menu for user.
    printf("\nWassup'?! Select a task to operate below by entering:\n\n'a', 'b','c' or 'd' in the file to be read.\n\n");
    printf("(a) Encrypt a word with rotation cipher!\n");
    printf("(b) Decrypt a word with rotation cypher!\n");          
    printf("(c) Encrypt a word with substitution cipher!\n");
    printf("(d) Decrypt a word with substitution cipher!\n\n");  // menu selection corresponds to each task. 
    
    fscanf(fp, "%c", &option); // scans the file and stores vaiable into "option".
    
    switch (option) {
        case 'a': printf("Task 1 selected. Enter word to be encrypted in given file, along with the key in another.\n\n");
                  encryptRotationCi ();  // switch() case used for menu selection, followed
                  break;                 // by function prototype for each case.
        case 'b': printf("Task 2 selected. Enter word to be decrypted in given file, plus key in the other.\n\n");
                  decryptRotationCi ();
                  break;
        case 'c': printf("Task 3 selected. Enter word to be encrypted in given file.\n\n");
                  encryptSubCi ();
                  break;
        case 'd': printf("Task 4 selected. Enter word to be decrypted in given file.\n\n");
                  decryptSubCi ();
                  break;
        default: printf("Invalid selection...\n\nTry again.");
    }
    
    fclose(fp); // closes file
}

// The following function will be used to encrypt using the rotation cipher.

void encryptRotationCi (void) {
    
    FILE *fp, *keyInput; // initialising file pointers.
    char alph[100]; // array will be used to store the word to be encrypted.
    char SPACE = 32; // this will be used in stdout incase of spaces.
    int i; // counter
    int k; // will be used for key.
    int m; // will be used in loop to rotate through 'alph[]' array.
    
    fp = fopen("encrypt.txt", "r"); // opening and reading file.
    keyInput = fopen("key.txt", "r"); 
    
    // the following loop will let us know if file does not exist.
    if (fp == NULL) {
        printf("Error: file not found.");
        return;
    }
    
    // this loop to scan file then store message into array.
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%c", &alph[i]);
    }
    
    printf("%s\n\n", alph); // this will print message before encryption.
    
    fscanf(keyInput, "%d", &k); // scanning file for integer, then using input integer as the key.

    // creating loop to apply algorithm that encrypts the phrase.
    for (i = 0; i < alph[i]; i++) {
        if (alph[i] == 32) {
            printf("%c", SPACE); // will print a space if found from the input.
        } else if ((alph[i] > 64) && (alph[i] < 91)) {
            m = alph[i]; // allocates variable 'm' to first value of alpharray[] (G), then increments to following letter.
            alph[i] = (((m - 65) + k) % 26) + 65; //caesar algorithm for encryption
            printf("%c", alph[i]);
        } else if ((alph[i] > 96) && (alph[i] < 123)) {
            m = alph[i]; // allocates variable 'm' to first value of alpharray[] (G), then increments to following letter.
            alph[i] = (((m - 97) + k) % 26) + 65; //caesar algorithm for encryption
            printf("%c", alph[i]);
        }
    }
    
    fclose(fp); // closes the file.
    fclose(keyInput);
    
    return;
}

// The following function will be used to decrypt using the rotation cipher.

void decryptRotationCi (void) {
    
    FILE *fp, *keyInput;
    char SPACE = 32;
    char alph[100];
    int i; // counter
    int k; // key value
    int m; // will be used for storing initial value of array
    
    fp = fopen("RoDecrypt.txt", "r"); // open and reads file.
    keyInput = fopen("key.txt", "r");
    
    // following loop implemented incase file not found.
    if (fp == NULL) {
        printf("Error: file not found.");
        return;
    }
    
    // this loop is to store message into array.
    for (i = 0; i < 100; i++) {      
        fscanf(fp, "%c", &alph[i]);
    }
    
    // prints message before decryption.
    printf("%s\n\n", alph);
    
    fscanf(keyInput, "%d", &k); // scans file for key selection
    
    // creating loop to apply algorithm that decrypts the phrase.
    for (i = 0; i < alph[i]; i++) {
        if (alph[i] == 32) {
            printf("%c", SPACE);
        } else if ((alph[i] > 64) && (alph[i] < 91)) {
            m = alph[i]; // allocates variable 'm' to first value of alpharray[], then increments to following letter.
            alph[i] = (((m - 65) - k) % 26) + 65; //caesar algorithm for decryption
            if (alph[i] < 65) {
                alph[i] += 26; // this control statement stops code from breaking
            }
            printf("%c", alph[i]);
        }else if ((alph[i] > 96) && (alph[i] < 123)) {
            m = alph[i]; // allocates variable 'm' to first value of alpharray[], then increments to following letter.
            alph[i] = (((m - 96) - k) % 26) + 64; //caesar algorithm for decryption
            if (alph[i] < 65) {
                alph[i] += 26; // this control statement stops code from breaking
            }
            printf("%c", alph[i]);
        } 
    }
    
    fclose(fp);
    fclose(keyInput);
    
    return;
}

// The following function will be used to encrypt using the substitution cipher.

void encryptSubCi (void) {
    
    FILE *fp;
    char oldAlphCap[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // array to store initial alphabet.
    char oldAlphLow[] = "abcdefghijklmnopqrstuvwxyz"; // this array initialised in case of lower case letters
    char newAlph[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // array to store the "new alphabet" which will be used to scramble he given word.
    char subCi[100]; // array that will store the word to encrypt.
    int i, j; // will be used as counter for "oldAlph[]" and "newAlph[]".
    
    fp = fopen("SubEncrypt.txt", "r"); // opens file for reading
    
    if (fp == NULL) {
        printf("Error: file not found.");
        return;
    }
    
    // loop to scan file then store in array
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%c", &subCi[i]);
    }
    
    printf("%s\n\n", subCi); // printing given word before being encrypted for comparison.
    
    /* the following loop will be used to search through each array index of both
       "oldAlph[]" and "newAlph[]". When location is found that matches the 0th 
       index of "subCi[]" array in the "oldAlph[]" array, that letter will then be
       swapped with the letter of the same index value in "newAlph[]". Loop should
       continue this beahaviour until every letter in "subCi[]" has been swapped.
       
       e.g oldAlph[0] = 'A', this letter corresponds with 'Q' in the "newAlph[]"
       i.e A will encrypt to Q and so on. */
      
    for (i = 0; i < subCi[i]; i++) {
        for (j = 0; j < 26; j++) {
             if (subCi[i] == oldAlphCap[j]) {
                subCi[i] = newAlph[j];
                break;
            } else if (subCi[i] == oldAlphLow[j]) {
                subCi[i] = newAlph[j];
                break;
            }         
        }
    } 
    printf("%s", subCi);
    
    fclose(fp);
    
    return;
}

// The following function will be used to decrypt using the substitution cipher.

void decryptSubCi (void) {
    
    FILE *fp;
    char oldAlph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // array to store initial alphabet.
    char newAlphCap[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // array to store the "new alphabet" which will be used to scramble he given word.
    char newAlphLow[] = "qwertyuiopasdfghjklzxcvbnm"; // created in case of lower case letters.
    char subCi[100]; // array that will store the word to decrypt.
    int i, j; // will be used as counter for "oldAlph[]" and "newAlph[]".
    
    fp = fopen("SubDecrypt.txt", "r"); // opens file for reading
    
    if (fp == NULL) {
        printf("Error: file not found.");
        return;
    }
    
    // loop to scan file then store in array
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%c", &subCi[i]);
    }
    
    printf("%s\n\n", subCi); // printing given word before being encrypted for comparison.
    
    /* the following loop will be used to search through each array index of both
       "oldAlph[]" and "newAlph[]". When location is found that matches the 0th 
       index of "subCi[]" array in the "newAlph[]" array, that letter will then be
       swapped with the letter of the same index value in "oldAlph[]". Loop should
       continue this beahaviour until every letter in "subCi[]" has been swapped.
       
       e.g subCi[0] = Q, this letter corresponds with 'A' in the "oldAlph[]"
       i.e 'Q' will decrypt to 'A' and so on. */
      
    for (i = 0; i < subCi[i]; i++) {
        for (j = 0; j < 26; j++) {
            if (subCi[i] == newAlphCap[j]) {
                subCi[i] = oldAlph[j];
                break;
            } else if (subCi[i] == newAlphLow[j]) {
                subCi[i] = oldAlph[j];
                break;
            }    
        }
    } 
    printf("%s", subCi);
    fclose(fp);
    return;
}
