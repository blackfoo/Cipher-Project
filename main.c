/* Caesar Cipher project by Mitchell Greenan.
   
   Project will be designed to (hopefully) take in a message that is
   input from user and then be encrypted.
 */
#include<stdio.h> 

int main()
{
    char alph[100];
    int i; // counter
    int k = 1; // key value
    int m = 72; // ASCII value of letter 'G'
    
    sprintf(alph,"GETLIT"); // storing 'GETLIT' into array.
                            /* with a key shift of +1, "HFUMJU" 
                               should be displayed. */
    for (i = 0; i < 6; i++) {
        alph[i] = (m - 65 + k) % 26 + 65;
    }
    printf("%s\n", alph);
    
    
}
