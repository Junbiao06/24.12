#include <stdio.h>
#include <string.h>

int readfile(char *filename, char text[]);
int tocheck(char text[], char love[], int n);
void writefile(char *filename, int count);

int main(void)
{
    char filename[50];
    char text[1000];
    char love[] = "love";
    printf("Please input source file address (D://f1.txt): ");
    scanf("%s", filename);
    int n = readfile(filename, text);
    int count = tocheck(text, love, n);
    printf("Please input target file address (D://f2.txt): ");
    scanf("%s", filename);
    writefile(filename, count);
    printf("Finished.\n");
    return 0;
}

int readfile(char *filename, char text[])
{
    FILE *fp;
    char ch;
    int i = 0;
    fp = fopen(filename, "r");
    if (fp==0)
    {
        printf("Error.\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        text[i++] = ch;
    }
    text[i] = '\0';
    fclose(fp);
    return i;
}

int tocheck(char text[], char love[], int n)
{
    int count = 0;
    for (int i = 0; i < n-strlen(love); i++)
    {
        strlwr(text);
        char array[5];
        for(int j=0;j<4;j++)
        {
            array[j]=text[i+j];
        }
        array[4]='\0';
        if (strcmp(array,love)==0)
        {
            count++;
        }
    }
    return count;
}

void writefile(char *filename, int count)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp==0)
    {
        printf("Error.");
        exit(1);
    }
    fprintf(fp,"'love' appears %i times.\n", count);
    fclose(fp);
}
