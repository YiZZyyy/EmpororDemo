#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6//����MAX��ʾϵͳҪ��������������

int main()
{
    int days;
    int i,j,temp;
    int count=5;                            //��ǰΪ�����乬����������
    int searchIndex = -1;                   //��Ų���Ԫ���±�
    int choice;                             //�ʵ۵�ѡ��
    char emperorName[50];                   //�ʵ�����
    char TempName[20];                      //��ʱ��������

    //��������
    char names[MAX][10] = {"����","槼�","��ʩ","����","����"};
    //��������
    char levelnames[5][10] = {"����","����","����","�ʹ���","�ʺ�"};
    //������ǰ����
    int levels[MAX] = {1 , 2 , 0 , 0 , 0 , -1};
    //�����øж�
    int loves[MAX] = {100,100,100,100,100,-1};

    printf ("�����뵱ǰ�ǻ��Ļʵ����ţ�");
    scanf ("%s",emperorName);                       //¼���ַ���ʱ������Ҫ&
    printf ("��ǰ�ʵ�Ϊ��%s���������������꣡\n",emperorName);
    printf ("*******************************\n");
    printf ("���Դ��룺�鿴��ǰ����״̬\n");
    printf ("����\t����\t�øж�\n");
    for (i = 0;i < count;i++)
    {
        printf ("%-6s\t%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);
    }

    for(days = 0;days < 10;days++)
    {

    printf ("*******************************\n");
    printf("1���ʵ���ּѡ����\t�����ӹ��ܣ�\n");
    printf("2�����Ƴ��ң�\t\t���޸�״̬���ܣ�\n");
    printf("3�������乬��\t\t��ɾ�����ܣ�\n");
    printf("4���ټ�������\t\t�����ҹ��ܣ�\n");
    printf("������ѡ��");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1://1���ʵ���ּѡ����\t\t�����ӹ��ܣ�
        //1���鿴��ǰ�����Ƿ��пռ�
        //2���������飬��names,loves,levels)
        if (count < MAX)//�����ǰ����������С��ϵͳ�����ֵ
        {
            //ִ����Ӳ���
            printf ("��������������䣺");
            scanf ("%s",names[count]);
            //����count��Ԫ�ص�״̬��ʼ��
            levels[count] = 0;      //�����ʼΪ0
            loves[count] = 100;       //�øжȳ�ʼΪ0
            for (i = 0;i < count;i++)
            {
                loves[i] -= 10;
            }
            count++;
        }
        else
        {
            printf ("���£�Ҫע�����尡����������Ϊ����\n");
        }
        break;
        case 2://2�����Ƴ��ң�\t\t���޸�״̬���ܣ�
        //1���ҵ�Ҫ�������ӵ��±ꣻ
        //2���޸�������ӵ�״̬��  �øж�+10��������һ������߼���������
        //3���޸��������ӵ�״̬��  ��������ÿ�˺øж�-10
        printf ("������������췭����������䣺");
        scanf ("%s",TempName);
        //�ַ����Ĳ���strcmp����Ҫ����<string.h>
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
        case 3://3�������乬��\t\t��ɾ�����ܣ�\n
            //strcpyʵ�����鸳ֵ
        printf ("���£�������Ҫ�����乬���������䣺");
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
            printf ("�龪һ�������˴����乬��");
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
        case 4://�����ټ�
            //1������
            //2�����Ӻøж�
            printf ("���£�������Ҫ�ټ���λ���\n");
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
                printf ("��ǰ���в�����λ���ﰡ��");
            }
            else
            {

                loves[i] += 10;
                levels[i] = levels[i] >=4 ? 4 : levels[i] + 1;
                break;
            }
            break;
        default:
        printf ("����Ϸ�ԣ�����ʵ۱���˼��������\n") ;

    }
    //����ӡ��������״̬ǰ���Լ����������ð������
    for (i = 0;i < count - 1;i++)
    {
        for (j = 0;j < count - i - 1;j++)
        {
            if (levels[j] < levels[j + 1])
            {
                //��Ҫ�������������𡢺øж�
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
    printf ("���Դ��룺�鿴��ǰ����״̬\n");
    printf ("����\t����\t�øж�\n");
    for (i = 0;i < count;i++)
    {
        printf ("%-6s\t%s\t%d\n",names[i],levelnames[levels[i]],loves[i]);
    }
    printf ("*******************************\n");
    days++;
    }
    return 0;
}
