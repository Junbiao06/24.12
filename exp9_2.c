#include <stdio.h>

#define N 40

typedef struct Student
{
    char ID[20];
    char name[30];
    int age;
    double score;
} STU;

void CreateFile(char *filename, STU stu[], int n);
int ReadOut(char *filename, STU stu[], int n);
void Sort(STU stu[], int n);

int main(void)
{
    int n;
    char filename[50];
    STU stu[40];
    do
    {
        printf("The number of Students: ");
        scanf("%i", &n);
    } while (n < 1 || n > N);
    printf("Please input source file address(D://Info.dat): ");
    scanf("%s", filename);
    for (int i = 0; i < n; i++)
    {
        printf("ID, Name, Age, Score: ");
        scanf("%s%s%d%lf", stu[i].ID, stu[i].name, &stu[i].age, &stu[i].score);
    }
    CreateFile(filename, stu, n);
    n = ReadOut(filename, stu, n);
    printf("***************Read from Info.date***************\n");
    for (int i = 0; i < n; i++)
    {
        printf("%-15s %-15s %-10d %-10.2lf\n", stu[i].ID, stu[i].name, stu[i].age, stu[i].score);
    }
    printf("***********************Sorted***********************\n");
    Sort(stu, n);
    for (int i = 0; i < n; i++)
    {
        printf("%-15s %-15s %-10d %-10.2lf\n", stu[i].ID, stu[i].name, stu[i].age, stu[i].score);
    }
}

void CreateFile(char *filename, STU stu[], int n)
{
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Error.\n");
        exit(1);
    }
    fwrite(stu, sizeof(STU), n, fp);
    fclose(fp);
}

int ReadOut(char *filename, STU stu[], int n)
{
    FILE *fp;
    int i = 0;
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error.\n");
        exit(1);
    }
    while (fread(&stu[i], sizeof(STU), 1, fp) == 1)
        i++;
    fclose(fp);
    return i;
}

void Sort(STU stu[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (stu[i].score < stu[j].score)
            {
                STU t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }
        }
    }
}

// 附带名单
// S001 Alice 20 85.5
// S002 Bob 22 90.3
// S003 Charlie 21 88.7
// S004 David 23 75.4
// S005 Eva 20 92.1
// S006 Frank 22 80.0
// S007 Grace 21 95.6
// S008 Henry 22 67.8
// S009 Irene 23 91.2
// S010 Jack 21 84.3
// S011 Karen 20 78.6
// S012 Leo 22 89.4
// S013 Mona 23 77.1
// S014 Noah 21 93.8
// S015 Olivia 20 85.1
// S016 Peter 22 91.7
// S017 Quinn 23 76.4
// S018 Rachel 21 87.9
// S019 Steve 22 90.0
// S020 Tina 23 68.3
// S021 Uma 21 81.5
// S022 Victor 22 86.2
// S023 Wendy 20 92.5
// S024 Xander 22 84.8
// S025 Yvonne 23 79.3
// S026 Zack 21 82.0
// S027 Alice 20 88.9
// S028 Bob 22 76.0
// S029 Cindy 21 79.9
// S030 Daniel 22 94.5
// S031 Emily 23 70.2
// S032 Fiona 20 83.3
// S033 George 22 85.7
// S034 Hannah 21 91.0
// S035 Ian 22 78.1
// S036 James 17 99.2
// S037 Kobe 22 77.6
// S038 Durant 26 21.3
// S039 Curry 36 100
// S040 Edwards 25 88.4