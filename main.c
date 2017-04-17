#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6//常量MAX表示系统要求的最大妃子数量

int main()
{
    int days;
    int i,j,temp;
    int count=5;                            //当前为打入冷宫的嫔妃个数
    int searchIndex = -1;                   //存放查找元素下标
    int choice;                             //皇帝的选择
    char emperorName[50];                   //皇帝姓名
    char TempName[20];                      //临时姓名变量

    //嫔妃姓名
    char names[MAX][10] = {"貂蝉","妲己","西施","芈月","杨玉环"};
    //级别数组
    char levelnames[5][10] = {"贵人","嫔妃","贵妃","皇贵妃","皇后"};
    //嫔妃当前级别
    int levels[MAX] = {1 , 2 , 0 , 0 , 0 , -1};
    //嫔妃好感度
    int loves[MAX] = {100,100,100,100,100,-1};

    printf ("请输入当前登基的皇帝名号：");
    scanf ("%s",emperorName);                       //录入字符串时，不需要&
    printf ("当前皇帝为：%s，万岁万岁万万岁！\n",emperorName);
    printf ("*******************************\n");
    printf ("测试代码：查看当前嫔妃状态\n");
    printf ("姓名\t级别\t好感度\n");
    for (i = 0;i < count;i++)
    {
        printf ("%-6s\t%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);
    }

    for(days = 0;days < 10;days++)
    {

    printf ("*******************************\n");
    printf("1、皇帝下旨选妃！\t（增加功能）\n");
    printf("2、翻牌宠幸！\t\t（修改状态功能）\n");
    printf("3、打入冷宫！\t\t（删除功能）\n");
    printf("4、召见爱妃！\t\t（查找功能）\n");
    printf("陛下请选择：");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1://1、皇帝下旨选妃：\t\t（增加功能）
        //1、查看当前数组是否有空间
        //2、增加数组，（names,loves,levels)
        if (count < MAX)//如果当前的妃子数量小于系统的最大值
        {
            //执行添加操作
            printf ("请输入娘娘的名讳：");
            scanf ("%s",names[count]);
            //将第count个元素的状态初始化
            levels[count] = 0;      //级别初始为0
            loves[count] = 100;       //好感度初始为0
            for (i = 0;i < count;i++)
            {
                loves[i] -= 10;
            }
            count++;
        }
        else
        {
            printf ("陛下，要注意龙体啊！后宫已人满为患！\n");
        }
        break;
        case 2://2、翻牌宠幸：\t\t（修改状态功能）
        //1、找到要宠幸妃子的下标；
        //2、修改这个妃子的状态；  好感度+10，级别升一级，最高级不再升级
        //3、修改其他妃子的状态；  其他妃子每人好感度-10
        printf ("陛下请输入今天翻牌娘娘的名讳：");
        scanf ("%s",TempName);
        //字符串的查找strcmp，需要引入<string.h>
        for (i = 0;i < count;i++)
        {
            if (strcmp(TempName,names[i]) == 0 )
            {
                loves[i] += 10;
                levels[i] = levels[i] >=4 ? 4 : levels[i] + 1;
            }
            else
            {
                loves[i] -= 10;
            }
        }
        break;
        case 3://3、打入冷宫！\t\t（删除功能）\n
            //strcpy实现数组赋值
        printf ("陛下，请输入要打入冷宫的娘娘名讳：");
        scanf ("%s",TempName);
        for (i = 0;i < count;i++)
        {
            if (strcmp(TempName,names[i]) == 0)
            {
                searchIndex = i;
                break;
            }
        }
        if (-1 == searchIndex)
        {
            printf ("虚惊一场！无人打入冷宫！");
        }
        else
        {
            for (i = searchIndex;i < count;i++)
            {
                strcpy(names[i],names[i + 1]);
                loves[i] = loves[i + 1];
                levels[i] = levels[i + 1];
            }
            count--;
        }
        for (i = 0;i < count ;i++)
        {
            loves[i] += 10;
            levels[i] += 1;
        }
        break;
        case 4://单独召见
            //1、查找
            //2、增加好感度
            printf ("陛下，请输入要召见哪位娘娘？\n");
            scanf ("%s",TempName);
            for (i = 0;i < count;i++)
            {
                if (strcmp(TempName,names[i]) == 0)
                {
                    searchIndex = i;
                    break;
                }
            }
            if (searchIndex == -1)
            {
                printf ("当前宫中并无这位娘娘啊！");
            }
            else
            {

                loves[i] += 10;
                levels[i] = levels[i] >=4 ? 4 : levels[i] + 1;
                break;
            }
            break;
        default:
        printf ("君无戏言，还请皇帝陛下思虑再三！\n") ;

    }
    //最后打印所有妃子状态前，以级别进行排序，冒泡排序
    for (i = 0;i < count - 1;i++)
    {
        for (j = 0;j < count - i - 1;j++)
        {
            if (levels[j] < levels[j + 1])
            {
                //需要交换姓名、级别、好感度
                temp = levels[j];
                levels[j] = levels[j + 1];
                levels[j + 1] = temp;
                temp = loves[j];
                loves[j] = loves[j + 1];
                loves[j + 1] = temp;
                strcpy(TempName,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],TempName);
            }
        }
    }
    printf ("*******************************\n");
    printf ("测试代码：查看当前嫔妃状态\n");
    printf ("姓名\t级别\t好感度\n");
    for (i = 0;i < count;i++)
    {
        printf ("%-6s\t%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);
    }
    printf ("*******************************\n");
    days++;
    }
    return 0;
}
