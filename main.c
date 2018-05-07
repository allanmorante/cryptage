#include <stdlib.h>
#include <stdio.h>

int main()
{
    void controleSaisi(char [], int *);
    void ecriture(char []);
    void cryptage(char []);
    void decryptage(char []);
    char string[26];
    int booleen;
    do
    {
        ecriture(string);
        controleSaisi(string, &booleen);
        fflush(stdin);
    }
    while(booleen == 0);
    cryptage(string);
    decryptage(string);
    return 0;
}

void ecriture(char message3[26])
{
    printf("Entrez un message a crypter : \n");
    //fflush(stdin);
    scanf("%[^\n]", message3);
    printf("Message a crypter  :  '%s'\n", message3);
}

void controleSaisi(char message2[26], int *booleen1)
{
    int i=0;
    int booleen2 = 1;
    while(message2[i] != '\0' && booleen2 == 1)
    {
        if((message2[i]<'a' || message2[i]>'z') && (message2[i]<'A' || message2[i]>'Z') && (message2[i]!=' '))
        {
            printf("Vous avez saisi un caractere incorrect\n");
            printf("Vous ne pouvez saisir uniquement des minuscules, majuscules ou des espaces\n");
            printf("Veuillez recommencer\n");
            //fflush(stdin);
            *booleen1 = 0;
            booleen2 = 0;
        }
        else if(i>25)
        {
            printf("Vous avez saisi trop de caracteres\n");
            printf("Vous disposez de 26 caracteres au maximum\n");
            printf("Veuillez recommencer\n");
            //fflush(stdin);
            *booleen1 = 0;
            booleen2 = 0;
        }
        else
        {
            booleen2 = 1;
            *booleen1 = 1;
        }
        i=i+1;
    }
}
void cryptage(char message1[26])
{
    int i,w;
    char tabCodage[52] = {'h','y','l','u','j','p','v','r','e','a','k','b','n','d','o','f','s','q','z','c','w','m','g','i','t','x','H','Y','L','U','J','P','V','R','E','A','K','B','N','D','O','F','S','Q','Z','C','W','M','G','I','T','X'};
    char alphabet[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    i = 0;
while (message1[i] != '\0')
    {
        w = 0;
//remplace de % pas des espaces
        if(message1[i] == ' ')
            message1[i] = '%';
//cryptage
        else if ((message1[i]>='a' && message1[i]<='z') || (message1[i]>='A' && message1[i]<='Z'))
        {
            while(message1[i] != alphabet[w])
                w++;
            message1[i] = tabCodage[w];
        }
        i = i + 1;
    }
    printf("Message crypte : '%s'\n", message1);
}
void decryptage(char message4[26])
{
    int i,w;
    char tabCodage[52] = {'h','y','l','u','j','p','v','r','e','a','k','b','n','d','o','f','s','q','z','c','w','m','g','i','t','x','H','Y','L','U','J','P','V','R','E','A','K','B','N','D','O','F','S','Q','Z','C','W','M','G','I','T','X'};
    char alphabet[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    i = 0;
    while (message4[i] != '\0')
    {
        w = 0;
        //remplace de % pas des espaces
        if(message4[i] == '%')
            message4[i] = ' ';
        //cryptage
        else//if ((message4[i]>='a' && message4[i]<='z') || (message4[i]>='A' && message4[i]<='Z'))
        {
            while(message4[i] != tabCodage[w])
                w++;
            message4[i] = alphabet[w];
        }
        i = i + 1;
    }
    printf("Message decrypte : '%s'\n", message4);
}
