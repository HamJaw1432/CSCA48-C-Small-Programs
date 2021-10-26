// CSC A48 - Exercise 10 - Breaking Caesar Cipher+
// Complete where indicated below.
//
// Do not add any additional functions
// and do not leave any print statements
// in your final submission for testing!
//
// Updated by F. Estrada, March 2020.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>		// Yes, you can use functions from the string library!

#define MAX_STR_LEN 2048

void caesar_cipher(unsigned char plaintext[MAX_STR_LEN], unsigned char password[MAX_STR_LEN])
{
 // This function encodes the input text in plaintext[] using the caesar
 // cipher process with the specified password (please see the exercise
 // description to see how that works).
 //
 // The function must ensure that the 'end-of-string' delimiter is preserved,
 // and that no other character can become the 'end-of-string'.
 //
 // You want to make sure you understand what values can be stored in each
 // entry of the plaintext[] string, and you'll want to look at an ASCII table
 // to check that your function does the right thing.
 //
 // *** TEST your code with multiple input strings, using different passwords,
 //     and verify it works in
 //     every case! if you get incomplete because your function failed our
 //     tests it means you did not test carefully enough.
 //
 // You should re-use your solution from Ex9, if you did not complete Ex9, here's
 // your chance to complete it.
 
 
 char *t_plaintext = (char *)plaintext;
	char *t_password = (char *)password;
	
	int l1 = 0;
	int l2 =0;
	//printf("1\n");
	while (t_plaintext[l1] + '\0')
	{
		l1++;
		//printf("\n%d\n", l1);
	}
	
	//printf("here2\n");
	while (t_password[l2] + '\0')
	{
		l2++;
		//printf("\n%d\n", l2);
	}
	
	//printf("3\n");
	int i = 0;
	while(i < l1 && t_plaintext[i] != '\0')
	{
		if(((int)(t_plaintext[i] + (t_password[i % l2])) % 256) != '\0')
		{
			//printf("\n%d ---- %d\n", i ,i % l2);
			//printf("\n\n%c(%d) + %c(%d) ----", plaintext[i], plaintext[i], password[i % l2], password[i % l2]);
			
			//printf("%d\n", ((int)t_plaintext[i] + (int)(t_password[i % l2]))%256);
			t_plaintext[i] = (t_plaintext[i] + t_password[i % l2]) % 256;
			
			//printf("%c(%d)", plaintext[i],plaintext[i]);
			//printf("%d\n", ((int)t_plaintext[i] - (int)(t_password[i % l2])*2));
		}
		else
		{
			t_plaintext[i] = ((t_plaintext[i] + t_password[i % l2]) % 256) + t_password[i % l2];
		}
		i++;
	}
 
}

void caesar_decipher(unsigned char cryptotext[MAX_STR_LEN], unsigned char password[MAX_STR_LEN])
{
 // This function reverses the encryption process and returns the original
 // text given the encrypted string and the password used to encrypt it.
 //
 // The function has the same constraints as 'caesar_cipher()', that is, it
 // must respect the 'end-of-string' delimiter, and ensure no other
 // character becomes 'end-of-string' after decoding.
 //
 // Be smart about how you implement this function!
 //
 // Re-use your solution for Ex9, or complete this function if you did not
 // do so last week.
 //
 
	char *t_cryptotext = (char *)cryptotext;
	char *t_password = (char *)password;
	
	int l1 = 0;
	int l2 =0;
	while (t_cryptotext[l1] + '\0')
	{
		l1++;
	}
	while (t_password[l2] + '\0')
	{
		l2++;
	}
	
	int i = 0;
	while(i < l1 && t_cryptotext[i] != '\0')
	{
		if(((int)(t_cryptotext[i] - (t_password[i % l2])) % 256) != '\0')
		{
			t_cryptotext[i] = t_cryptotext[i] - ((t_password[i % l2])) % 256;
		}
		else
		{
			t_cryptotext[i] = 256 - t_password[i % l2];
		}
		i++;
	}
    
}

void caesar_breaker(unsigned char crypto_message[MAX_STR_LEN], unsigned char password[MAX_STR_LEN], unsigned char dictionary[10][MAX_STR_LEN])
{
 // This function takes as input
 // - One line of text encrypted using Caesar Cipher+
 // - An array to hold the password that cracks the cipher
 // - A dictionary to be used for a dictionary-attack (here it only has 10 entries, each is a string)
 //
 // The function determines which is the word in the dictionary that cracks the cipher, and returns it
 // by updating the 'password' string with the correct password.
 //
 // TO DO: Complete this function
 //
 // Constraints: You can assume the input message contains only valid text characters (letters, numbers,
 //              and punctuation signs)
 //              The message is somehow related to A48, it was written by Paco
 //              That's it, you should think about how to use this information to solve your task.
 //              there are many ways to approach this problem, some better than others. Think carefully!
 
	char *t_crypto_message = (char *)crypto_message;
	
	char temp_crack[MAX_STR_LEN];
	char temp_password[MAX_STR_LEN];
 
	int valid;
	
	int best_valid = 0;
	char best_crack[MAX_STR_LEN];
	char best_password[MAX_STR_LEN];
	
	
	
	int i = 0;
	
	
	//printf("\n\n\n\n\n\n");
	
	
	while (i < 10)
	{
		//printf("%s", t_crypto_message);
		strcpy(temp_crack, t_crypto_message);
		//printf("\ntemp_crack = %s", temp_crack);
		caesar_decipher((unsigned char *)temp_crack, dictionary[i]);
		//printf("\ntemp_crack_uncode = %s", temp_crack);
		strcpy(temp_password, (char *)dictionary[i]);
		
		
		valid = 0;
		
		int j = 0;
		while (temp_crack[j] != '\0')
		{
			if(temp_crack[j] >= 32 && temp_crack[j] <= 122 )
			{
				valid = valid + 100;
			}
			if((temp_crack[j] == 33 || temp_crack[j] == 46 || temp_crack[j] == 58 || temp_crack[j] == 59 || temp_crack[j] == 63) && (temp_crack[j + 1] == 32 || temp_crack[j + 1] == '\0'))
			{
				valid = valid + 1;
			}
			j++;
			
		}
		if(strstr(temp_crack, "A48"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "graphs"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "recursion"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "lecture"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "sorting"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "assignment"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "notes"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "code"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "nodes"))
		{
			valid = valid + 10;
		}
		if(strstr(temp_crack, "the"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "Hello"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "this"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "that"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "read"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "of"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "and"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "read"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "was"))
		{
			valid = valid + 1;
		}
		if(strstr(temp_crack, "to"))
		{
			valid = valid + 1;
		}
			
			
		if(valid > best_valid)
		{
			best_valid = valid;
			
			strcpy(best_crack, temp_crack);
			strcpy(best_password, temp_password);
			
		}
		
		
		i++;
	}
	
	strcpy((char *)password, best_password); 
 
 
    
}

#ifndef __testing

int main()
{

    unsigned char a_passage[5][MAX_STR_LEN]={"Hello All A48 people! this is a reminder that the on-line lecture\n",
                                    "will be on recursion, please make sure you've read the notes,\n",
                                    "before you watch the lecture!\n",
                                    "Also, don't forget to complete your BST assignment. We hope you've\n",
                                    "learned lots about complexity and sorting!\n"};

    unsigned char dictionary[10][MAX_STR_LEN]={"Zucchini",
				      "Carrot",
                                      "Radish",
				      "Broccoli",
				      "Eggplant",
				      "Cilantro",
				      "Sweet Potato",
				      "Tomatoes",
				      "Garlic",
				      "Arugula"};

    unsigned char password[MAX_STR_LEN];

    printf("**** Original input text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);

    // Encode the input test lines
    caesar_cipher(a_passage[0],dictionary[0]);
    caesar_cipher(a_passage[1],dictionary[3]);
    caesar_cipher(a_passage[2],dictionary[5]);
    caesar_cipher(a_passage[3],dictionary[8]);
    caesar_cipher(a_passage[4],dictionary[9]);

    // VERY IMPORTANTLY
    // It should be clear to you, we will test your code with a DIFFERENT message,
    // encoded using DIFFERENT entries in the dictionary, and also a DIFFERENT
    // dictionary! so be sure to test very well!
    
    printf("\n**** Encrypted text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);

    // Crack the passwords for each text line, and use them to decrypt the text
    printf("\n\n***** Decoding message! *****\n\n");
    for (int i=0; i<5; i++)
    {
        memset(&password[0],0,MAX_STR_LEN*sizeof(unsigned char));   // Clear out password
        caesar_breaker(a_passage[i],password,dictionary);           // Try to get the password for this message
	caesar_decipher(a_passage[i],password);                     // Use the password to decrypt
	// You should check here that your code retrieved the correct password!
	printf("Password=%s, decoded message=%s",password,a_passage[i]);
    }

    return 0;
}

#endif
