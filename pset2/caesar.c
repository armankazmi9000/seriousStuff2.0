#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("NOOOOOOOOO\n");
        return 1;
    }

    int k = atoi(argv[1]);

    if (k < 0)
    {
        printf("NOOOOOOOOOO\n");
        return 1;
    }
    else
    {

        //edsfghj
        //asdfgh
        //sdfdg
        //edsfghj
        //asdfgh
        //sdfdg//edsfghj
        //asdfgh
        //sdfdg
        string plain = get_string("Plaintext: ");

        printf("ciphertext: ");

        for (int i = 0, n = strlen(plain); i < n; i++)
        {

            if (isupper(plain[i]))
            {
                printf("%c", ((((plain[i] + k) - 65) % 26) + 65));
            }
            else if (islower(plain[i]))
            {
                printf("%c", ((((plain[i] + k) - 97) % 26) + 97));
            }
            else
            {
                printf("%c", plain[i]);
            }

        }
        printf("\n");
        return 0;
    }

}