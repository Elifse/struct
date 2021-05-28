#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define M 155
void detail();   //显示销售情况
void foreach (); //从文件读取数据兵分类整理
void menu();     //菜单
void product();  //对产品进行统计
void readdata(); //从文件读取数据
void total();    //输出报表
void choice();   //选择输出信息
void seller();
struct ss
{
    int sid; //销售员代号
    int pid; //产品代号
    int sn;  //销售额
} ss[M];

int n;                                                                              //纸条数目
int s[4][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}; //用于保存员工和产品信

int main() //入口函数即主函数
{
    readdata(); //读取文件数据
    foreach ();   //根据文件初始数据初始化便于操作的数组
    menu(); //显示主菜单
}

void readdata() //从文件读取数据
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
        } //保存文件数据到结构体
    fclose(fp);
}
void foreach () //从纸条读取数据并分类整理
{
    int i;
    for (i = 0; i < n; i++) //遍历所有纸条 
{ switch(ss[i].pid)//按产品分大类，根据大类分销售员小类，累加个人各产品销售数量
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
        puts("\t\t********************菜单*********************\n\n");
        puts("\t\t 1.查看每人每种产品的销售额\n");
        puts("\t\t 2.按销售额对销售员排序(销售员代号)\n");
        puts("\t\t 3.对每种产品总销售额从高到低排序(产品代号和销售额)\n");
        puts("\t\t 4.输出统计报表\n");
        puts("\t\t 5.退出\n");
        puts("\n\n\t\t*********************************************\n");
        printf("请选择(1-5):[ ]\b\b");
        scanf("%d", &c);
        if (c < 1 || c > 5) //错误输入则重新获取输如
        {
            w = 1;
            getchar();
        }
        else
            w = 0;
    } while (w == 1);
    switch (c) //根据输入实现相应函数调用
    {
    case 1:
        detail();
        break; //每个销售员每种产品的销售额统j计
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
void detail() //显示销售情况
{
    int i, j;
    for (i = 0; i < 4; i++) //遍历销售员
    {
        printf("\n\t\t%d号销售员销售情况:\n", i + 1);
        for (j = 0; j < 5; j++) /*按销售员分类遍历所有产品并显示信息*/
            printf("\t\t%d号产品销售数量:%d\n", j + 1, s[i][j]);
    }
    choice();
}
void seller()
{
    int i, j, k;
    int sp[4] = {0, 0, 0, 0};
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            sp[i] += s[i][j]; //计算每单个销售员所有产品销售情况
    for (i = 0; i < 4; i++)   //比较四次，每次选出最大数
    {
        k = 0; //用于标记单轮最大数
        for (j = 0; j < 4; j++)
            if (sp[k] < sp[j])
                k = j; //获取最大数标号
        printf("\t\t第%d名是%d号销售员!\n", i + 1, k + 1);
        sp[k] = -1; /*输出最大数和排名，将最大数标记为负*/
    }
    choice();
}
void product() //与seller()原理一样，用于对产品进行统计
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
        printf("\t\t第%d名是%d号产品!\t销量为%d!\n", j + 1, k + 1, p[k]);
        p[k] = -1;
    }
    choice();
}
void total() //输出报表
{
    int i, j;
    printf("\n\t销售员\t产品\t销量\n");
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            printf("\t %d\t %d\t %d\n", i + 1, j + 1, s[i][j]);
    choice();
}
void choice() //用于输出信息功能选择
{
    int c;
    printf("请选择接下来想做什么\t1>返回菜单\t2>退出系统[ ]\b\b");
    scanf("%d", &c);
    if (c == 1)
        menu();
    else
        exit(0);
    puts("\n");
}
