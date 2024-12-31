#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct student
{
    int id;
    char name[50];
    double score;
    int rank;
} STU;

int readfile(char *filename, STU stu[]);
void torank(STU stu[], int count);
void writefile(char *filename, STU stu[], int count);

int main(void)
{
    STU stu[N];
    char filename[50];
    int count = 0;
    printf("Please input source file address: \n");
    scanf("%s", filename);
    count = readfile(filename, stu);
    torank(stu, count);
    printf("Please input target file address: \n");
    scanf("%s", filename);
    writefile(filename, stu, count);
}

int readfile(char *filename, STU stu[])
{
    int i = 0;
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == 0)
    {
        printf("source file error.");
        exit(1);
    }
    fscanf(fp, "%i%s%lf%i", &stu[i].id, stu[i].name, &stu[i].score, &stu[i].rank);
    while (!feof(fp))
    {
        i++;
        fscanf(fp, "%i%s%lf%i", &stu[i].id, stu[i].name, &stu[i].score, &stu[i].rank);
    }
    fclose(fp);
    return i;
}

void torank(STU stu[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (stu[j].score < stu[j + 1].score)
            {
                STU t = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = t;
            }
            stu[0].rank = 1;
            for (int i = 1; i < count; i++)
            {
                if (stu[i].score == stu[i - 1].score)
                    stu[i].rank = stu[i - 1].rank;
                else
                    stu[i].rank = i + 1;
            }
        }
    }
}

void writefile(char *filename, STU stu[], int count)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == 0)
    {
        printf("source file error.");
        exit(1);
    }
    for (int i = 0; i < count; i++)
    {
        printf("%i  %s  %.2lf  %i\n", stu[i].id, stu[i].name, stu[i].score, stu[i].rank);
        fprintf(fp, "%i  %s  %.2lf  %i\n", stu[i].id, stu[i].name, stu[i].score, stu[i].rank);
    }
    fclose(fp);
}