#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "include_pub.h"
int course_system()
{
    int x,i,n,k;
    FILE *fp;
    char dataname[100]={"\0"};
    FILE *fq;
    if((fq=fopen("student.txt","r"))==NULL)
        exit(0);
    while(!feof(fq))
    {
        fscanf(fp,"%s %s %s %d",stu[i].stu_num,stu[i].stu_name,stu[i].stu_C_al,&stu[i].stu_credit);
        i++;
    }
    k=i;
    fclose(fq);
    px(k);
    system("clear");
    printf("++++++++++课程信息管理模块++++++++++\n");
    printf("+        1、初始化课程信息         +\n");
    printf("+        2、新增课程信息           +\n");
    printf("+        3、修改课程信息           +\n");
    printf("+        4、删除课程信息           +\n");
    printf("+        5、查看课程信息           +\n");
    printf("+        6、保存并返回             +\n");
    printf("+        7、返回上一级             +\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("进入选项：");
    scanf("%d",&x);
    if(x==7)
    {
	fprintf(fs,"%s\n","返回上一级");
        system("clear");
        return 0;
    }
    while(x<6)
    {
        switch(x)
        {
            case 1:
		fprintf(fs,"%s\n\t","初始化信息:");
                n=INIT();//初始化信息
                break;
            case 2:
		fprintf(fs,"%s\n\t","新增信息:");
                n=AND(n);//新增信息
                break;
            case 3:
		fprintf(fs,"%s\n\t","修改信息:");
                CHAN(n,k);//修改信息
                break;
            case 4:
		fprintf(fs,"%s\n\t","删除信息:");
                n=DELE(n,k);//删除信息
                break;
            case 5:
		fprintf(fs,"%s\t","查看信息:");
                FIN(n);//查看信息
                break;
            default :
		fprintf(fs,"%s\n","返回上一级");
                break;
        }

        printf("++++++++++课程信息管理模块++++++++++\n");
        printf("+        1、初始化课程信息         +\n");
        printf("+        2、新增课程信息           +\n");
        printf("+        3、修改课程信息           +\n");
        printf("+        4、删除课程信息           +\n");
        printf("+        5、查看课程信息           +\n");
        printf("+        6、保存并返回             +\n");
        printf("+        7、返回上一级             +\n");
        printf("++++++++++++++++++++++++++++++++++++\n");
        printf("进入选项：");
        scanf("%d",&x);

    }
    if(x==6)
    {
	fprintf(fs,"%s\t","保存并返回:");
        system("clear");
        printf("请输入保存路径/文件名：");
        scanf("%s",dataname);
	fprintf(fs,"%s\n",dataname);
        if((fp=fopen(dataname,"w"))==NULL)
            exit(0);
        fprintf(fp,"编号 课程名   课程性质（必修/选修） 所占学时  所占学分  已选人数  人数上限");
        for(i=0;i<n;i++)
        {
            fprintf(fp,"\n%s %s %s %d %d %d %d",cou[i].cou_num,cou[i].cou_name,cou[i].cou_nature,cou[i].cou_time,cou[i].cou_credit,cou[i].cou_stu_num_al,cou[i].cou_num_limit);
        }
        fclose(fp);
        system("clear");
    }
    if(x==7)
    {
	fprintf(fs,"%s\n","返回上一级");
        system("clear");
    }
    return 0;
}

