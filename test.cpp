#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SJD 6 /*宏定义定义SJD Z NULL D(r)*/
#define Z 20
#define D(s) (s - 8) / 2 /*将输入的时间划分时间段；分别为0,1,2,3,4,5时间段*/

struct Student_xinxi 
{
    int jihao;
    char xuehao[20];
    struct Student_xinxi *next;
}; /*结构函数包含学生信息：机位，学号，还有下名学生信息*/
struct cell
{
    int RS;               /*RS表示总人数*/
    struct Student_xinxi *first;  /*第一个预订者记录*/
    struct Student_xinxi *middle; /*等待队列列表*/
    struct Student_xinxi *last;   /*最后预订者记录*/
} Student_shunxu[SJD];            /*学生时间（SJD）段顺序：人数，第一名学生，排队的学生，最后一名学生*/
/***************************预定模块******************************/
void yuding()
{
    int n;
    char m[20]; /*学号*/
    struct Student_xinxi *R;/*机号*/
    struct Student_xinxi *p;
    printf("输入想要预定的时间(8:00-20:00)\n");
    scanf("%d", &n);/*n为用户所输入的时间段*/
    if (n >= 8 && n < 20)
    {
        n = D(n);             /*将输入的时间划分时间段*/
        if (Student_shunxu[n].RS < Z) /*还有机位可供预订*/
        {
            printf("请输入你的学号\n");
            scanf("%s", m);/*m为用户所输入的学号*/
            if (Student_shunxu[n].first == NULL) /*还没有人预订(栈顶为空)*/
            {
                R = (struct Student_xinxi *)malloc(sizeof(struct Student_xinxi)); /*给R划分适当的内存*/
                R->jihao = 1;/*机号从1开始分配*/
                strcpy(R->xuehao, m); /*将输入的学号复制到R->xuehao */
                R->next = NULL;
                Student_shunxu[n].first = R;
                Student_shunxu[n].last = R;
                Student_shunxu[n].RS++;
                printf("成功预定\n");
            }
            else/*已有人预定的条件下,其他用户预定*/
            {
                R = (struct Student_xinxi *)malloc(sizeof(struct Student_xinxi));
                strcpy(R->xuehao, m); /*将输入的学号复制到R->xuehao */
                R->next = NULL;
                p = Student_shunxu[n].last; /*将最后预订记录赋值给p*/
                R->jihao = Student_shunxu[n].RS + 1;
                printf("%d", R->jihao); /*表示该时间段第几位预订*/
                Student_shunxu[n].last = R;     /*将当前的记录做为最后记录以便形成链表形式指向下一个*/
                p->next = R;
                Student_shunxu[n].RS++; /*记录人数*/
                printf("预定成功\n");
            }
        }
        else
            printf("没有空余机位!\n");
    }
    else
        printf("错误.请输入8~19，再次输入.\n");
}

/*********************************查询空位模块***********************************/
void chaxunkongwei()
{
    int n;
    printf("输入想要查询的时间(8~19点，包括8点)\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        n = D(n);
        if (Student_shunxu[n].RS < Z)
            printf("这里还有%d台空电脑!\n", Z - Student_shunxu[n].RS);
        else
            printf("对不起.没有空余机位!\n");
    }
    else
        printf("错误,请输入8~20，再次输入.\n");
}
/*********************查询预定机位模块*************************************/
void chaxunyuding()
{
    int n;
    char m[20];
    struct Student_xinxi *R;
    printf("输入查询时间(8~19点，包括8点)\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        n = D(n);
        printf("请输入学号\n");
        scanf("%s", m);
        R = Student_shunxu[n].first; /*将第一名学生的信息赋予R*/
        if (Student_shunxu[n].first == 0)
            printf(" 还没有人预定\n"); /*判断有没有人预订，如果还没有人预订，则输出还没有人预定*/
        else
        {
            for (; R->next != NULL; R = R->next) /*从第一名学生开始查询直到找到符合的学号，以便确认是否预订*/
                if (strcmp(R->xuehao, m) == 0)
                    break;
            if (R->jihao != 0) /*已预订，输出相应的信息*/
                printf("你的机位是%d\n", R->jihao);
            else
                printf("对不起.你依旧在等待列表中或者没有预定");
        }
    }
    else
        printf("错误，请再次输入.\n");
}
/*****************************排队系统模块**************************************/
void paiduixitong()
{
    int n;
    char m[20];
    struct Student_xinxi *R;
    struct Student_xinxi *p;
    printf("请输入想要排队的时间\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        n = D(n);
        if (Student_shunxu[n].RS >= Z) /*该时间段没有空位机，需要预订等待*/
        {
            printf("请输入你的学号\n");
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
                Student_shunxu[n].middle = R; /*等待预订列表*/
                Student_shunxu[n].RS++;
                printf("成功排队\n");
            } /*将刚输入学生信息拍到最后一名后，成最后一名*/
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
                printf("成功排队\n");
            }
        }
        else
            printf("有空余机位，无须等待\n");
    }
    else
        printf("错误.再次输入.\n");
}
/******************************取消预订模块****************************************/
void cancel()
{
    int n;
    int i;
    char m[20];
    struct Student_xinxi *R;
    struct Student_xinxi *q;
    struct Student_xinxi *p;
    printf("请输入预定的时间\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        printf("请输入你的学号!\n");
        scanf("%s", m);
        n = D(n);
        R = Student_shunxu[n].first;
        q = R;
        for (i = 1;; q = R, R = R->next, i++) /*查找符合信息*/
            if (strcmp(R->xuehao, m) == 0)
                break;
        if (i > Z) /*i>z表示在等待列表中*/
        {
            if (R->next == NULL)
            {
                q->next = NULL;
                Student_shunxu[n].last = q;
                free(R);
                Student_shunxu[n].RS--;
                printf("取消成功!\n"); /*如果是排在20名后，且是最后一名*/
            }
            else
            {
                q->next = R->next;
                free(R);
                Student_shunxu[n].RS--;
                printf("取消成功!\n"); /*如果排在20名后，但不是最后*/
            }
        }
        else /*正在上机者取消预订*/
        {
            if (Student_shunxu[n].RS > Z)
            {
                Student_shunxu[n].middle->jihao = R->jihao;
                Student_shunxu[n].middle = Student_shunxu[n].middle->next;
            } /*如果排在20名内，但总人数（包括等待列表人数）大于20 */
            if (i == 1)
                Student_shunxu[n].first = R->next;
            else
                q->next = R->next;
            free(R);
            Student_shunxu[n].RS--;
            printf("成功取消预定!\n");
        }
    }
    else
        printf("错误，请再次输入.\n");
}
/********************************等待机位列表模块****************************/
void dengdaijiwei()
{
    int n;
    struct Student_xinxi *q;
    printf("查询其他等待者的预定时间\n");
    scanf("%d", &n);
    if (n >= 8 && n < 20)
    {
        n = D(n);
        if (Student_shunxu[n].RS > Z) /*表示有等待上机者*/
        {
            printf("等待列表:\n");
            q = Student_shunxu[n].middle;
            for (; q->next != NULL; q = q->next)
                printf("%s\n", q->xuehao); /*逐个输出等待列表者信息*/
            printf("%s\n", Student_shunxu[n].last->xuehao);
        }
        else
            printf("这个时间段没有预定者\n");
    }
    else
        printf("错误。请再次输入.\n");
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
        printf(" ************机房机位预定系统************\n");
        printf(" **************************************\n");
        printf(" *** 1 查询空机位         2 预定系统 ****\n");
        printf(" *** 3 取消预定         4 查询所预定机位 *\n");
        printf(" *** 5 排队系统           6 等机者列表 ***\n");
        printf(" ************* 0 退出系统 ***************\n");
        printf(" ***************************************\n");
        printf(" * 请输入序号（0--6）来选择您所需要的功能 *\n");
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
            printf("错误\n");
        }
    }
    return 0;
}
