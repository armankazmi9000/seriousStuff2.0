#include <cs50.h>
#include <stdio.h>

int height;

int main(void)
{
    do {
    height = get_int("Height: ");
    

    if (height == 1)
    {
        printf("#\n");
    }
   
    else if (height == 2)
    {
        printf(" #\n");
        printf("##\n");
    }
      
    else if (height == 3)
    {
        printf("  #\n");
        printf(" ##\n");
        printf("###\n");
    } 
    else if (height == 4)/*ya yeet*/
    {
        printf("   #\n");
        printf("  ##\n");
        printf(" ###\n");
        printf("####\n");
    } 
    else if (height == 5)
    {
        printf("    #\n");
        printf("   ##\n");
        printf("  ###\n");
        printf(" ####\n");
        printf("#####\n");
    } 
    else if (height == 6)
    {
        printf("     #\n");
        printf("    ##\n");
        printf("   ###\n");
        printf("  ####\n");
        printf(" #####\n");
        printf("######\n");
    } 
    else if (height == 7)
    {
        printf("      #\n");
        printf("     ##\n");
        printf("    ###\n");
        printf("   ####\n");
        printf("  #####\n");
        printf(" ######\n");
        printf("#######\n");
    } 
    else if (height == 8)
    {
        printf("       #\n");
        printf("      ##\n");
        printf("     ###\n");
        printf("    ####\n");
        printf("   #####\n");
        printf("  ######\n");
        printf(" #######\n");
        printf("########\n");
    }
    } while (height < 1 || height > 8);
}