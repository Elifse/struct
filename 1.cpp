#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define M 155
void detail();   //��ʾ�������
void foreach (); //���ļ���ȡ���ݱ���������
void menu();     //�˵�
void product();  //�Բ�Ʒ����ͳ��
void readdata(); //���ļ���ȡ����
void total();    //�������
void choice();   //ѡ�������Ϣ
void seller();
struct ss
{
    int sid; //����Ա����
    int pid; //��Ʒ����
    int sn;  //���۶�
} ss[M];

int n;                                                                              //ֽ����Ŀ
int s[4][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}; //���ڱ���Ա���Ͳ�Ʒ��

int main() //��ں�����������
{
    readdata(); //��ȡ�ļ�����
    foreach ();   //�����ļ���ʼ���ݳ�ʼ�����ڲ���������
    menu(); //��ʾ���˵�
}

void readdata() //���ļ���ȡ����
{
    FILE *fp;
    if ((fp = fopen("list.txt", "r")) == NULL)
    {
        printf("Can't open the file!\n");
        exit(0);
    }
    else
        for (n = 0; !feof(fp); n++)
        {
            fscanf(fp, "%d %d %d\n", &ss[n].sid, &ss[n].pid, &ss[n].sn);
        } //�����ļ����ݵ��ṹ��
    fclose(fp);
}
void foreach () //��ֽ����ȡ���ݲ���������
{
    int i;
    for (i = 0; i < n; i++) //��������ֽ�� 
{ switch(ss[i].pid)//����Ʒ�ִ��࣬���ݴ��������ԱС�࣬�ۼӸ��˸���Ʒ��������
    {
    case 1:
        switch (ss[i].sid)
        {
        case 1:
            s[0][0] += ss[i].sn;
            break;
        case 2:
            s[1][0] += ss[i].sn;
            break;
        case 3:
            s[2][0] += ss[i].sn;
            break;
        case 4:
            s[3][0] += ss[i].sn;
            break;
        }
        break;
    case 2:
        switch (ss[i].sid)
        {
        case 1:
            s[0][1] += ss[i].sn;
            break;
        case 2:
            s[1][1] += ss[i].sn;
            break;
        case 3:
            s[2][1] += ss[i].sn;
            break;
        case 4:
            s[3][1] += ss[i].sn;
            break;
        }
        break;
    case 3:
        switch (ss[i].sid)
        {
        case 1:
            s[0][2] += ss[i].sn;
            break;
        case 2:
            s[1][2] += ss[i].sn;
            break;
        case 3:
            s[2][2] += ss[i].sn;
            break;
        case 4:
            s[3][2] += ss[i].sn;
            break;
        }
        break;
    case 4:
        switch (ss[i].sid)
        {
        case 1:
            s[0][3] += ss[i].sn;
            break;
        case 2:
            s[1][3] += ss[i].sn;
            break;
        case 3:
            s[2][3] += ss[i].sn;
            break;
        case 4:
            s[3][3] += ss[i].sn;
            break;
        }
        break;
    case 5:
        switch (ss[i].sid)
        {
            case 1 : s[0][4] += ss[i].sn;
            break;
        case 2:
            s[1][4] += ss[i].sn;
            break;
        case 3:
            s[2][4] += ss[i].sn;
            break;
        case 4:
            s[3][4] += ss[i].sn;
            break;
        };
        break;
    }
}
}
void menu()
{
    int w, c;
    do
    {
        puts("\t\t********************�˵�*********************\n\n");
        puts("\t\t 1.�鿴ÿ��ÿ�ֲ�Ʒ�����۶�\n");
        puts("\t\t 2.�����۶������Ա����(����Ա����)\n");
        puts("\t\t 3.��ÿ�ֲ�Ʒ�����۶�Ӹߵ�������(��Ʒ���ź����۶�)\n");
        puts("\t\t 4.���ͳ�Ʊ���\n");
        puts("\t\t 5.�˳�\n");
        puts("\n\n\t\t*********************************************\n");
        printf("��ѡ��(1-5):[ ]\b\b");
        scanf("%d", &c);
        if (c < 1 || c > 5) //�������������»�ȡ����
        {
            w = 1;
            getchar();
        }
        else
            w = 0;
    } while (w == 1);
    switch (c) //��������ʵ����Ӧ��������
    {
    case 1:
        detail();
        break; //ÿ������Աÿ�ֲ�Ʒ�����۶�ͳj��
    case 2:
        seller();
        break;
    case 3:
        product();
        break;
    case 4:
        total();
        break;
    case 5:
        exit(0);
    }
}
void detail() //��ʾ�������
{
    int i, j;
    for (i = 0; i < 4; i++) //��������Ա
    {
        printf("\n\t\t%d������Ա�������:\n", i + 1);
        for (j = 0; j < 5; j++) /*������Ա����������в�Ʒ����ʾ��Ϣ*/
            printf("\t\t%d�Ų�Ʒ��������:%d\n", j + 1, s[i][j]);
    }
    choice();
}
void seller()
{
    int i, j, k;
    int sp[4] = {0, 0, 0, 0};
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            sp[i] += s[i][j]; //����ÿ��������Ա���в�Ʒ�������
    for (i = 0; i < 4; i++)   //�Ƚ��ĴΣ�ÿ��ѡ�������
    {
        k = 0; //���ڱ�ǵ��������
        for (j = 0; j < 4; j++)
            if (sp[k] < sp[j])
                k = j; //��ȡ��������
        printf("\t\t��%d����%d������Ա!\n", i + 1, k + 1);
        sp[k] = -1; /*��������������������������Ϊ��*/
    }
    choice();
}
void product() //��seller()ԭ��һ�������ڶԲ�Ʒ����ͳ��
{
    int i, j, k;
    int p[5] = {0, 0, 0, 0, 0};
    for (j = 0; j < 5; j++)
        for (i = 0; i < 4; i++)
            p[j] += s[i][j];
    for (j = 0; j < 5; j++)
    {
        k = 0;
        for (i = 0; i < 5; i++)
            if (p[k] < p[i])
                k = i;
        printf("\t\t��%d����%d�Ų�Ʒ!\t����Ϊ%d!\n", j + 1, k + 1, p[k]);
        p[k] = -1;
    }
    choice();
}
void total() //�������
{
    int i, j;
    printf("\n\t����Ա\t��Ʒ\t����\n");
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            printf("\t %d\t %d\t %d\n", i + 1, j + 1, s[i][j]);
    choice();
}
void choice() //���������Ϣ����ѡ��
{
    int c;
    printf("��ѡ�����������ʲô\t1>���ز˵�\t2>�˳�ϵͳ[ ]\b\b");
    scanf("%d", &c);
    if (c == 1)
        menu();
    else
        exit(0);
    puts("\n");
}
