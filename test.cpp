#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SJD 6 /*�궨�嶨��SJD Z NULL D(r)*/
#define Z 20
#define D(s) (s - 8) / 2 /*�������ʱ�仮��ʱ��Σ��ֱ�Ϊ0,1,2,3,4,5ʱ���*/

struct Student_xinxi 
{
    int jihao;
    char xuehao[20];
    struct Student_xinxi *next;
}; /*�ṹ��������ѧ����Ϣ����λ��ѧ�ţ���������ѧ����Ϣ*/
struct cell
{
    int RS;               /*RS��ʾ������*/
    struct Student_xinxi *first;  /*��һ��Ԥ���߼�¼*/
    struct Student_xinxi *middle; /*�ȴ������б�*/
    struct Student_xinxi *last;   /*���Ԥ���߼�¼*/
} Student_shunxu[SJD];            /*ѧ��ʱ�䣨SJD����˳����������һ��ѧ�����Ŷӵ�ѧ�������һ��ѧ��*/
/***************************Ԥ��ģ��******************************/
void yuding()
{
    int n;
    char m[20]; /*ѧ��*/
    struct Student_xinxi *R;/*����*/
    struct Student_xinxi *p;
    printf("������ҪԤ����ʱ��(8:00-20:00)\n");
    scanf("%d", &n);/*nΪ�û��������ʱ���*/
    if (n >= 8 && n < 20)
    {
        n = D(n);             /*�������ʱ�仮��ʱ���*/
        if (Student_shunxu[n].RS < Z) /*���л�λ�ɹ�Ԥ��*/
        {
            printf("���������ѧ��\n");
            scanf("%s", m);/*mΪ�û��������ѧ��*/
            if (Student_shunxu[n].first == NULL) /*��û����Ԥ��(ջ��Ϊ��)*/
            {
                R = (struct Student_xinxi *)malloc(sizeof(struct Student_xinxi)); /*��R�����ʵ����ڴ�*/
                R->jihao = 1;/*���Ŵ�1��ʼ����*/
                strcpy(R->xuehao, m); /*�������ѧ�Ÿ��Ƶ�R->xuehao */
                R->next = NULL;
                Student_shunxu[n].first = R;
                Student_shunxu[n].last = R;
                Student_shunxu[n].RS++;
                printf("�ɹ�Ԥ��\n");
            }
            else/*������Ԥ����������,�����û�Ԥ��*/
            {
                R = (struct Student_xinxi *)malloc(sizeof(struct Student_xinxi));
                strcpy(R->xuehao, m); /*�������ѧ�Ÿ��Ƶ�R->xuehao */
                R->next = NULL;
                p = Student_shunxu[n].last; /*�����Ԥ����¼��ֵ��p*/
                R->jihao = Student_shunxu[n].RS + 1;
                printf("%d", R->jihao); /*��ʾ��ʱ��εڼ�λԤ��*/
                Student_shunxu[n].last = R;     /*����ǰ�ļ�¼��Ϊ����¼�Ա��γ�������ʽָ����һ��*/
                p->next = R;
                Student_shunxu[n].RS++; /*��¼����*/
                printf("Ԥ���ɹ�\n");
            }
        }
        else
            printf("û�п����λ!\n");
    }
    else
        printf("����.������8~19���ٴ�����.\n");
}

/*********************************��ѯ��λģ��***********************************/
void chaxunkongwei()
{
    int n;
    printf("������Ҫ��ѯ��ʱ��(8~19�㣬����8��)\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        n = D(n);
        if (Student_shunxu[n].RS < Z)
            printf("���ﻹ��%d̨�յ���!\n", Z - Student_shunxu[n].RS);
        else
            printf("�Բ���.û�п����λ!\n");
    }
    else
        printf("����,������8~20���ٴ�����.\n");
}
/*********************��ѯԤ����λģ��*************************************/
void chaxunyuding()
{
    int n;
    char m[20];
    struct Student_xinxi *R;
    printf("�����ѯʱ��(8~19�㣬����8��)\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        n = D(n);
        printf("������ѧ��\n");
        scanf("%s", m);
        R = Student_shunxu[n].first; /*����һ��ѧ������Ϣ����R*/
        if (Student_shunxu[n].first == 0)
            printf(" ��û����Ԥ��\n"); /*�ж���û����Ԥ���������û����Ԥ�����������û����Ԥ��*/
        else
        {
            for (; R->next != NULL; R = R->next) /*�ӵ�һ��ѧ����ʼ��ѯֱ���ҵ����ϵ�ѧ�ţ��Ա�ȷ���Ƿ�Ԥ��*/
                if (strcmp(R->xuehao, m) == 0)
                    break;
            if (R->jihao != 0) /*��Ԥ���������Ӧ����Ϣ*/
                printf("��Ļ�λ��%d\n", R->jihao);
            else
                printf("�Բ���.�������ڵȴ��б��л���û��Ԥ��");
        }
    }
    else
        printf("�������ٴ�����.\n");
}
/*****************************�Ŷ�ϵͳģ��**************************************/
void paiduixitong()
{
    int n;
    char m[20];
    struct Student_xinxi *R;
    struct Student_xinxi *p;
    printf("��������Ҫ�Ŷӵ�ʱ��\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        n = D(n);
        if (Student_shunxu[n].RS >= Z) /*��ʱ���û�п�λ������ҪԤ���ȴ�*/
        {
            printf("���������ѧ��\n");
            scanf("%s", m);
            if ((Student_shunxu[n].RS) == Z)
            {
                R = (struct Student_xinxi *)malloc(sizeof(struct Student_xinxi));
                strcpy(R->xuehao, m);
                R->next = NULL;
                R->jihao = 0;
                p = Student_shunxu[n].last;
                Student_shunxu[n].last = R;
                p->next = R;
                Student_shunxu[n].middle = R; /*�ȴ�Ԥ���б�*/
                Student_shunxu[n].RS++;
                printf("�ɹ��Ŷ�\n");
            } /*��������ѧ����Ϣ�ĵ����һ���󣬳����һ��*/
            else
            {
                R = (struct Student_xinxi *)malloc(sizeof(struct Student_xinxi));
                strcpy(R->xuehao, m);
                R->next = NULL;
                R->jihao = 0;
                p = Student_shunxu[n].last;
                Student_shunxu[n].last = R;
                p->next = R;
                Student_shunxu[n].RS++;
                printf("�ɹ��Ŷ�\n");
            }
        }
        else
            printf("�п����λ������ȴ�\n");
    }
    else
        printf("����.�ٴ�����.\n");
}
/******************************ȡ��Ԥ��ģ��****************************************/
void cancel()
{
    int n;
    int i;
    char m[20];
    struct Student_xinxi *R;
    struct Student_xinxi *q;
    struct Student_xinxi *p;
    printf("������Ԥ����ʱ��\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        printf("���������ѧ��!\n");
        scanf("%s", m);
        n = D(n);
        R = Student_shunxu[n].first;
        q = R;
        for (i = 1;; q = R, R = R->next, i++) /*���ҷ�����Ϣ*/
            if (strcmp(R->xuehao, m) == 0)
                break;
        if (i > Z) /*i>z��ʾ�ڵȴ��б���*/
        {
            if (R->next == NULL)
            {
                q->next = NULL;
                Student_shunxu[n].last = q;
                free(R);
                Student_shunxu[n].RS--;
                printf("ȡ���ɹ�!\n"); /*���������20�����������һ��*/
            }
            else
            {
                q->next = R->next;
                free(R);
                Student_shunxu[n].RS--;
                printf("ȡ���ɹ�!\n"); /*�������20���󣬵��������*/
            }
        }
        else /*�����ϻ���ȡ��Ԥ��*/
        {
            if (Student_shunxu[n].RS > Z)
            {
                Student_shunxu[n].middle->jihao = R->jihao;
                Student_shunxu[n].middle = Student_shunxu[n].middle->next;
            } /*�������20���ڣ����������������ȴ��б�����������20 */
            if (i == 1)
                Student_shunxu[n].first = R->next;
            else
                q->next = R->next;
            free(R);
            Student_shunxu[n].RS--;
            printf("�ɹ�ȡ��Ԥ��!\n");
        }
    }
    else
        printf("�������ٴ�����.\n");
}
/********************************�ȴ���λ�б�ģ��****************************/
void dengdaijiwei()
{
    int n;
    struct Student_xinxi *q;
    printf("��ѯ�����ȴ��ߵ�Ԥ��ʱ��\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        n = D(n);
        if (Student_shunxu[n].RS > Z) /*��ʾ�еȴ��ϻ���*/
        {
            printf("�ȴ��б�:\n");
            q = Student_shunxu[n].middle;
            for (; q->next != NULL; q = q->next)
                printf("%s\n", q->xuehao); /*�������ȴ��б�����Ϣ*/
            printf("%s\n", Student_shunxu[n].last->xuehao);
        }
        else
            printf("���ʱ���û��Ԥ����\n");
    }
    else
        printf("�������ٴ�����.\n");
}

int main()
{
    int i;
    for (i = 0; i < SJD; i++)
    {
        Student_shunxu[i].RS = 0;
        Student_shunxu[i].first = NULL;
        Student_shunxu[i].middle = NULL;
        Student_shunxu[i].last = NULL;
    }
    while (1)
    {
        printf(" **************************************\n");
        printf(" ************������λԤ��ϵͳ************\n");
        printf(" **************************************\n");
        printf(" *** 1 ��ѯ�ջ�λ         2 Ԥ��ϵͳ ****\n");
        printf(" *** 3 ȡ��Ԥ��         4 ��ѯ��Ԥ����λ *\n");
        printf(" *** 5 �Ŷ�ϵͳ           6 �Ȼ����б� ***\n");
        printf(" ************* 0 �˳�ϵͳ ***************\n");
        printf(" ***************************************\n");
        printf(" * ��������ţ�0--6����ѡ��������Ҫ�Ĺ��� *\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            chaxunkongwei();
            break;
        case 2:
            yuding();
            break;
        case 3:
            cancel();
            break;
        case 4:
            chaxunyuding();
            break;
        case 5:
            paiduixitong();
            break;
        case 6:
            dengdaijiwei();
            break;
        case 0:
            exit(0);
        default:
            printf("����\n");
        }
    }
    return 0;
}
