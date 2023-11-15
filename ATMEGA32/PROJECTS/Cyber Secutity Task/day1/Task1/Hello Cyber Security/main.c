#include <stdio.h>
#include <stdlib.h>


#define     MAX     200

static char Plain[MAX]      = {'\0'};
static char Encrypted[MAX]  = {'\0'};

/* Function Prototypes */
void Encription();
void Decription();
void Clear_cmd();
void Exit();



int main()
{
    int Choice = 0;
    while(1)
    {
        printf("1- Encription \n");
        printf("2- Decription \n");
        printf("3- Clear The cmd \n");
        printf("4- Exit\n");


        scanf("%d", &Choice);

        switch(Choice)
        {
            case 1 :    Encription();       break;
            case 2 :    Decription();       break;
            case 3 :    Clear_cmd();        break;
            case 4 :    Exit();             break;
            default:                        break;
        }
    }


    return 0;
}





/* Don't forget to handle the space */
void Encription()
{
    printf("Please Enter The  key value\n");
    int Key;
    scanf("%d", &Key);

    printf("Please Enter The Plain Text\n");
    scanf(" %[^\n]s", Plain);

    int i = MAX;
    while(Plain[i] != '\0')
    {
        printf("%s \n", Plain);
        i++;
    }

    Key %= 26;
    for (int i = 0; i < MAX; i++)
    {
        if(Plain[i] == 32)
        {
            // Do Nothing
        }
        else if(Plain[i] >= 'A' && Plain[i] <= 'Z')      // Capital letters
        {
            if ((Plain[i] + Key) <= 'Z')
            {
                Plain[i]+= Key;
            }
            else if(Plain[i] + Key > ('Z'))
            {
                Plain[i] = (Plain[i] + Key) - 26;
            }
        }

        else if(Plain[i] >= 'a' && Plain[i] <= 'z')      // Small letters
        {
            if (Plain[i] + Key <= ('z'))
            {
                Plain[i]+= Key;
            }
            else if(Plain[i] + Key > ('z'))
            {
                Plain[i] = (Plain[i] + Key) - 26;
            }
        }
    }

    puts(Plain);
    printf("\n");
}



void Decription()
{
    printf("Please Enter The  key value\n");
    int Key;
    scanf("%d", &Key);

    printf("Please Enter The Encrypted Text\n");
    scanf(" %[^\n]s", Encrypted);

    int i = MAX;
    while(Encrypted[i] != '\0')
    {
        printf("%s \n", Encrypted);
        i++;
    }


    Key %= 26;
    for (int i = 0; i < MAX; i++)
    {
        if(Encrypted[i] == 32)
        {
            // Do Nothing
        }
        else if(Encrypted[i] >= 'A' && Encrypted[i] <= 'Z')      // Capital letters
        {
            if ((Encrypted[i] - Key) >= 'A')
            {
                Encrypted[i]-= Key;
            }
            else if(Encrypted[i] - Key < ('A'))
            {
                Encrypted[i] = (Encrypted[i] - Key) + 26;
            }
        }

        else if(Encrypted[i] >= 'a' && Encrypted[i] <= 'z')      // Small letters
        {
            if (Encrypted[i] - Key >= ('a'))
            {
                Encrypted[i]-= Key;
            }
            else if(Encrypted[i] - Key < ('a'))
            {
                Encrypted[i] = (Encrypted[i] - Key) + 26;
            }
        }
    }

    puts(Encrypted);
    printf("\n");

}



void Clear_cmd()
{
    system("cls");  // clear the cmd
}


void Exit()
{
    //return 0;
    Exit(EXIT_SUCCESS); //Exit(0);
}
