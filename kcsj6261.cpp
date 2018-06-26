#include<iostream>
#include<string>
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
cout<<"Cannot open output file.\n";
	abort();  //退出程序
}
in.read((char *)&::zggz0,sizeof(::zggz0));
in.close();//关闭文件
for(int n=0;n<50;n++)
	{ 
	if(::zggz0[n].gongh!=NULL)
		::number=n+1;
	else
		break;
	}
menu();
};
void write(zggz *p,int k){   //保存函数

	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
	cout<<"Cannot open output file.\n";
	abort();//退出程序
	}
	for(int i=0;i<k+1;i++)
	{
		out.write((char *)&*p,sizeof(*p));
        p++;
}
	out.close();
cout<<"保存成功"<<endl;	
cout<<"即将返回菜单"<<"  ";
  system("pause");
	read();     //调用菜单
};
void find()     //查询函数
{
      //read();
	      int k,i=0,w;
          loop:cout<<"请输入你要查询的工号："<<endl;
		  cin>>k;
		  for(int j=0;j<::number;j++)
		  {    
			  
				 if (k==::zggz0[j].gongh)
				 {
				 cout<<"职员信息如下："<<endl;
				 cout<<"工号"<<"\t"<<"姓名"<<"\t"<<"岗位工资"<<"\t"<<"薪级工资"<<"\t"<<"职务工资"<<"\t"<<"效绩工资"<<"\t"<<"应发工资"<<"\t"<<"实发工资"<<endl;
		         cout<<::zggz0[j].gongh<<"\t"<<::zggz0[j].name<<"\t"<<::zggz0[j].gwgz<<"\t\t"<<::zggz0[j].xinjgz<<"\t\t"<<::zggz0[j].zwjt<<"\t\t"<<::zggz0[j].xiaojgz<<"\t\t"<<::zggz0[j].yfgz<<"\t\t"<<zggz0[j].sfgz<<endl;
	             i=k;
				 cout<<"重新查询（1），菜单（任意键）"<<endl;
				 cin>>w;
			     if(w==1)
				   goto loop;
			     else 
				   menu();
				 }
		  }
		  if(i!=k)
		  {
		   cout<<"没有这个职员的信息，重新查询（1），菜单（任意键）"<<endl;
		   cin>>w;
			   if(w==1)
				   goto loop;
			   else 
				   menu();
		  }
	   
};//查询
void list()      //浏览职员信息函数
{   
	//read();
	cout<<"共有"<<::number<<"人，所有的职员信息如下："<<endl;
	cout<<"工号"<<"\t"<<"姓名"<<"\t"<<"岗位工资"<<"\t"<<"薪级工资"<<"\t"<<"职务工资"<<"\t"<<"效绩工资"<<"\t"<<"应发工资"<<"\t"<<"实发工资"<<endl;
	for(int i=0;i<::number;i++)
	{
	cout<<::zggz0[i].gongh<<"\t"<<::zggz0[i].name<<"\t"<<::zggz0[i].gwgz<<"\t\t"<<::zggz0[i].xinjgz<<"\t\t"<<::zggz0[i].zwjt<<"\t\t"<<::zggz0[i].xiaojgz<<"\t\t"<<::zggz0[i].yfgz<<"\t\t"<<zggz0[i].sfgz<<endl;
	}
	cout<<"即将返回菜单"<<"  ";
	system("pause");
menu();
};//浏览
void modify()
{ 
          int k,i=0,w,a1,a2,a3,a4;
		  zggz zggz1,*q;
          loop:cout<<"请输入你要修改的工号："<<endl;
		  cin>>k;
		  for(int j=0;j<::number;j++)
		  {    
			  
		 if (k==::zggz0[j].gongh)
		 {
		 cout<<"职员信息如下："<<endl;
		 cout<<"工号"<<"\t"<<"姓名"<<"\t"<<"岗位工资"<<"\t"<<"薪级工资"<<"\t"<<"职务工资"<<"\t"<<"效绩工资"<<"\t"<<"应发工资"<<"\t"<<"实发工资"<<endl;
		 cout<<::zggz0[j].gongh<<"\t"<<::zggz0[j].name<<"\t"<<::zggz0[j].gwgz<<"\t\t"<<::zggz0[j].xinjgz<<"\t\t"<<::zggz0[j].zwjt<<"\t\t"<<::zggz0[j].xiaojgz<<"\t\t"<<::zggz0[j].yfgz<<"\t\t"<<zggz0[j].sfgz<<endl;
	     cout<<"修改后的岗位工资："<<"  "; 
         cin>>a1;
		 cout<<"修改后的薪级工资："<<"  ";
		 cin>>a2;
		 cout<<"修改后的职务津贴："<<"  ";
		 cin>>a3;
		 cout<<"修改后的效绩工资："<<"  ";
		 cin>>a4;
		 ::zggz0[j].gwgz=a1;
		 ::zggz0[j].xinjgz=a1;
		 ::zggz0[j].zwjt=a1;
		 ::zggz0[j].xiaojgz=a1;
		 ::zggz0[j].yfgz=a1+a2+a3+a4;
		 ::zggz0[j].grs=grsds(::zggz0[j].sfgz);
		 ::zggz0[j].sfgz=::zggz0[j].yfgz-::zggz0[j].grs;;
		 }    
		 }
		  q=::zggz0;
		 cout<<"修改成功，保存（1），菜单（任意键）"<<endl;
		 cin>>w;
		 if(w==1)
			 write(q,::oup);
		 else
		 menu();

};//修改
//void del();//删除
void add()
{  int i;
	zggz zggz1[50];
	::p=zggz1;
//	read();
	cout<<"现在已有职员人数为"<<::number<<"人"<<endl;
	for(int j=0;j<::number;j++)
	{
	 zggz1[j]=zggz0[j];
	
	}
	for(i=::number;i<100;i++)
	{
	int gongh1;
  char name1[20];
  float gwgz1,xinjgz1,zwjt1,xiaojgz1;
  cout<<"请依次输入工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资"<<endl;
  cin>>gongh1>>name1>>gwgz1>>xinjgz1>>zwjt1>>xiaojgz1;
  zggz1[i].gongh=gongh1;
  strcpy(zggz1[i].name,name1);
  zggz1[i].gwgz=gwgz1;
  zggz1[i].xinjgz=xinjgz1;
  zggz1[i].zwjt=zwjt1;
  zggz1[i].xiaojgz=xiaojgz1;
  zggz1[i].yfgz=gwgz1+xinjgz1+zwjt1+xiaojgz1;     //计算应发工资
  zggz1[i].grs=grsds(zggz1[i].yfgz);              //计算个人所得税
  zggz1[i].sfgz=zggz1[i].yfgz-zggz1[i].grs;       //计算实发工资
  cout<<"是否继续添加，1/0"<<endl;
	int k;
	cin>>k;
	if(k==0)
	{
	break;
	}
	}
	::oup=i;
  cout<<"请返回菜单保存"<<endl;
  cout<<"即将返回菜单"<<"  ";
  system("pause");
	menu();     //调用菜单

};//添加
int grsds(float a)  //计算个人所得税
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

};
void tuichu()
{
exit(0);
};//退出程序
void menu(){                              //菜单
  int i;
    cout<<"\t\t\t"<<"<-----------课程设计--------->"<<endl;
	cout<<"\t\t\t"<<"|           1.查询           |"<<endl;
	cout<<"\t\t\t"<<"|           2.修改           |"<<endl;
	cout<<"\t\t\t"<<"|           3.添加           |"<<endl;
	cout<<"\t\t\t"<<"|           4.删除           |"<<endl;
	cout<<"\t\t\t"<<"|           5.保存           |"<<endl;
	cout<<"\t\t\t"<<"|           6.浏览           |"<<endl;
	cout<<"\t\t\t"<<"|           7.退出           |"<<endl;
	cout<<"\t\t\t"<<"<---------------------------->"<<"\n\n"<<endl;
	cout<<"请输入你想要选择操作的相应数字"<<endl;
	do
	{
		printf("\n\t请输入你的选择：");
		scanf("%d", &i);
	} while (i <= 0 || i>7);
	
switch(i)       //调用函数
	{
            case 1:find();break;//查询
			case 2:modify();break;//修改
			case 3:add();break;//添加
		//	case 4:del();break;//删除
			case 5:write(::p,::oup);break;//保存
			case 6: list();break;//浏览
			case 7:tuichu();break;//退出
	}
read();
}
int main()
{  
	read();
	return 0;

}
