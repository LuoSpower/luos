#include<stdio.h>
#include<fstream>
using namespace std;
int grsds(float a);
void menu();
struct zggz{
  int id;
  int gongh;
  char name[20];
  float gwgz,xinjgz,zwjt;
  float xiaojgz;
  float yfgz,sfgz;
  float grs;
};
zggz zggz0[50],*p;   //全局变量数组
int number,oup;      //全局变量统计人数
void read()     //读取函数
{
ifstream in("gz.dat",ios::binary);
if(!in)
{
printf("Cannot open output file.\n");
	abort();  //退出程序
}
in.read((char *)&::zggz0,sizeof(::zggz0));
in.close();//关闭文件
for(int n=0;n<50;n++)
	{ 
	if(zggz0[n].gongh!=NULL)
	   number=n+1;
	else
		break;
	}
};
void write(zggz *p,int k){   //保存函数
	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
	printf("Cannot open output file.\n");
	abort();//退出程序
	}
	for(int i=0;i<k;i++)
	{
		out.write((char *)&*p,sizeof(*p));
        p++;
	}
	out.close();
printf("保存成功");//cout<<"保存成功"<<endl;	
printf("即将返回菜单  ");//cout<<"即将返回菜单"<<"  ";
  system("pause");
  read();	
  menu();   //调用菜单
};
void find()     //查询函数
{
	      int k,i=0,w;
  loop:   printf("请输入你要查询的工号\n");
		  scanf("%d",&k);
		  for(int j=0;j<::number;j++)
		  {    
			  
				 if (k==::zggz0[j].gongh)
				 {
				 printf("职员信息如下：\n");
				 printf("工号\t姓名\t岗位工资\t薪级工资\t职务工资\t效绩工资\t应发工资\t实发工资\n");
		         printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",
					 ::zggz0[j].gongh,
					 ::zggz0[j].name,
					 ::zggz0[j].gwgz,
					 ::zggz0[j].xinjgz,
					 ::zggz0[j].zwjt,
					 ::zggz0[j].xiaojgz,
					 ::zggz0[j].yfgz,
					 ::zggz0[j].sfgz);
	              i=k;
				 printf("重新查询（1），菜单（任意键）\n");
				 scanf("%d",&w);
			     if(w==1)
				   goto loop;
			     else 
				   menu();
				 }
		  }
		  if(i!=k)
		  {
		  printf("没有这个职员的信息，重新查询（1），菜单（任意键）\n");
		  scanf("%d",&w);
		  if(w==1)
		   goto loop;
		  else 
		   menu();
		  }
	   
};//查询
void list(int k)      //浏览职员信息函数
{  

	printf("共有%d人,所有信息如下：\n",k);
	if(k!=0)
	{
	printf("工号\t姓名\t岗位工资\t薪级工资\t职务工资\t效绩工资\t应发工资\t实发工资\n");
	}
	for(int i=0;i<::number;i++)
	{
    printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",                  //输出职工信息
		::zggz0[i].gongh,
		::zggz0[i].name,
		::zggz0[i].gwgz,
		::zggz0[i].xinjgz,
		::zggz0[i].zwjt,
		::zggz0[i].xiaojgz,
		::zggz0[i].yfgz,
		::zggz0[i].sfgz);
	 }
    printf("即将返回菜单  ");
  	system("pause");
    menu();
};//浏览
void modify()
{ 
          int k,i=0,w,a1,a2,a3,a4;
		  zggz *q;
  loop:   printf("请输入你要修改的工号： \n");
		  scanf("%d",&k);//cin>>k;
		  for(int j=0;j<::number;j++)
		  {    
			  
		  if (k==::zggz0[j].gongh)
		  {
		  printf("职员信息如下：");
		  printf("工号\t姓名\t岗位工资\t薪级工资\t职务工资\t效绩工资\t应发工资\t实发工资\n");
          printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",                                             //输出即将修改的职工信息
			 ::zggz0[i].gongh,
			 ::zggz0[i].name,
			 ::zggz0[i].gwgz,
			 ::zggz0[i].xinjgz,
			 ::zggz0[i].zwjt,
			 ::zggz0[i].xiaojgz,
			 ::zggz0[i].yfgz,
			 ::zggz0[i].sfgz);
	     printf("修改后的岗位工资:   \n"); 
         scanf("%d",&a1);
		 printf("修改后的薪级工资：  \n");
		 scanf("%d",&a2);
		 printf("修改后的职务津贴：  \n");
		 scanf("%d",&a3);
		 printf("修改后的效绩工资：  \n");
		 scanf("%d",&a4);
		 ::zggz0[j].gwgz=a1;                                                               //给修改的职工信息重新赋值
		 ::zggz0[j].xinjgz=a2;
		 ::zggz0[j].zwjt=a3;
		 ::zggz0[j].xiaojgz=a4;
		 ::zggz0[j].yfgz=a1+a2+a3+a4;
		 ::zggz0[j].grs=grsds(::zggz0[j].sfgz);
		 ::zggz0[j].sfgz=::zggz0[j].yfgz-::zggz0[j].grs;
		 i=j;
		 q=::zggz0;
		 printf("修改成功，保存（1），放弃保存，返回菜单（任意键）\n");                     //修改成功确认是否保存
		  scanf("%d",&w);
		 if(w==1)
			 write(q,::oup);
		 else
		 menu();

		 }    
		 }
         if(i!=j)
		  {
		   printf("没有这个职员的信息，重新查询（1），菜单（任意键）\n");               //修改失败，未搜索到输入的职工号，询问是否重新输入或返回菜单
		   scanf("%d",&w);
		   if(w==1)
		   {
		    goto loop;
		   }
		   else 
		   {
			menu();
		   }
		  }
		  

};//修改
void del()
{
	::p=::zggz0;
	 int gonghao;
	 printf("请输入要删除的员工工号：\n");
	 scanf("%d",&gonghao);
	 for(int i=0;i<::number;i++)
	 {
	 if(gonghao==::zggz0[i].gongh)  //判断输入的工号是否存在
	 {  printf("工号\t姓名\t岗位工资\t薪级工资\t职务工资\t效绩工资\t应发工资\t实发工资\n");
          printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",
			 ::zggz0[i].gongh,
			 ::zggz0[i].name,
			 ::zggz0[i].gwgz,
			 ::zggz0[i].xinjgz,
			 ::zggz0[i].zwjt,
			 ::zggz0[i].xiaojgz,
			 ::zggz0[i].yfgz,
			 ::zggz0[i].sfgz);
		if(i!=::number)
		{
		for(;i<::number;i++)
		{
		 ::zggz0[i]=::zggz0[i+1];
		}
		 ::number=::number-1;
		}
		else
		{
		::number=::number-1;
		}
	}
	}
	 printf("是否确认删除，确定删除（Y）, 放弃删除,返回菜单（N）");       //确认是否删除，或者返回菜单
		char g;
	    scanf("%s",&g);
		if(g=='Y')
		{
			write(::p,::number);                                          //保存删除后的的数据到文件中
		}
		else
		{
			menu();
		}
};//删除*/
void add()
{   int i;
	zggz zggz1[50];
	::p=zggz1;
//	read();
	printf("现在已有职员人数为%d人\n",::number);
	for(int j=0;j<::number;j++)
	{
	 zggz1[j]=zggz0[j];
	}
	for(i=::number;i<100;i++)
	{
	int gongh1;
    char name1[20];
    float gwgz1,xinjgz1,zwjt1,xiaojgz1;
    printf("请依次输入工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资\n");
    scanf("%d%s%f%f%f%f",&gongh1,&name1,&gwgz1,&xinjgz1,&zwjt1,&xiaojgz1);
    zggz1[i].gongh=gongh1;                          //工号
    strcpy(zggz1[i].name,name1);                    //名字
    zggz1[i].gwgz=gwgz1;                            //岗位工资
    zggz1[i].xinjgz=xinjgz1;                        //薪级工资
    zggz1[i].zwjt=zwjt1;                            //计算职务津贴
    zggz1[i].xiaojgz=xiaojgz1;                      //计算效绩工资
    zggz1[i].yfgz=gwgz1+xinjgz1+zwjt1+xiaojgz1;     //计算应发工资
    zggz1[i].grs=grsds(zggz1[i].yfgz);              //计算个人所得税
    zggz1[i].sfgz=zggz1[i].yfgz-zggz1[i].grs;       //计算实发工资
    printf("是否继续添加，1/0\n");
	int k;
	scanf("%d",&k);
	if(k!=1)
	{
	break;
	}
	}
	::oup=i+1;
    printf("请返回菜单保存  \n");
    printf("即将返回菜单   \n");
    system("pause");
	menu();     //调用菜单

};//添加
int grsds(float a)   //计算个人所得税
{
	float i;
	if(a<500)
	{
		i=a-a*0.05;   
	}
	else if(a>500&&a<=2000)
	{
		i=(a-500)*0.1+25;
	}
	else if(a>2000&&a<=5000)
	{
		i=(a-2000)*0.15+150+25;
	}
	else if(a>5000&&a<=20000)
	{
		i=(a-5000)*0.2+450+150+25;
	}
	else if(a>20000&&a<=40000)
	{
		i=(a-20000)*0.25+3000+450+150+25;
	}
	else if(a>40000&&a<=60000)
	{
		i=(a-40000)*0.3+5000+3000+450+150+25;
	}
	else if(a>60000&&a<=80000)
	{
		i=(a-60000)*0.35+6000+5000+3000+450+150+25;
	}
	else if(a>80000&&a<=100000)
	{
		i=(a-80000)*0.4+7000+6000+5000+3000+450+150+25;
	}
	else if(a>100000)
	{
		i=(a-100000)*0.45+8000+7000+6000+5000+3000+450+150+25;
	}
	return i;
}

/*int grsds(float a)  //计算个人所得税
{
	float i;
if(a<500)
  i=a*0.05;
else if(500<a&&a<2000)
 i=a*0.1;
else if(2000<a&&a<5000)
 i=a*0.15;
else if(5000<a&&a<20000)
 i=a*0.2;
else if(20000<a&&a<40000)
 i=a*0.25;
else if(40000<a&&a<60000)
 i=a*0.3;
else if(60000<a&&a<80000)
 i=a*0.35;
else if(80000<a&&a<10000)
 i=a*0.4;
else
 i=a*0.45;
return i;

};*/
void tuichu()
{
exit(0);
};//退出程序
void menu(){                              //菜单
  int i;
    printf("\t\t\t\t###   欢迎使用广西民族大学软件与信息安全学院职工工资管理系统   ###\n\n");
	printf("\t\t\t\t=================================================================|\n");
	printf("\t\t\t\t请选择 <1~7>:                                                    |\n");
  	printf("\t\t\t\t|                                                                |\n");
	printf("\t\t\t\t|                     1.查询职工工资记录                         |\n");
	printf("\t\t\t\t|                     2.修改职工工资记录                         |\n");
	printf("\t\t\t\t|                     3.添加职工工资记录                         |\n");
	printf("\t\t\t\t|                     4.删除职工工资记录                         |\n");
	printf("\t\t\t\t|                     5.保存数据到文件                           |\n");
	printf("\t\t\t\t|                     6.浏览职工数据                             |\n");
	printf("\t\t\t\t|                     7.退出系统                                 |\n");
	printf("\t\t\t\t|                                                                |\n");
    printf("\t\t\t\t==================================================================\n");
	do
	{
	printf("\n\t你的选择是：");
	scanf("%d", &i);
	} while (i <= 0 || i>7);
switch(i)       //调用函数
{ 
            case 1:find();break;               //查询函数
			case 2:modify();break;             //修改函数
			case 3:add();break;                //添加函数
			case 4:del();break;                //删除函数
			case 5:write(::p,::oup);break;     //保存函数
			case 6: list(::number);break;      //浏览函数
			case 7:tuichu();break;//退出
	}
}
int main()
{  
	read();
	menu();
	return 0;

}
