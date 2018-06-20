#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int grsds(float a);
int v=0;
int menu(){
  int i;
    cout<<"\t\t\t"<<"<-----------课程设计--------->"<<endl;
	cout<<"\t\t\t"<<"|           1.读取           |"<<endl;
	cout<<"\t\t\t"<<"|           2.保存           |"<<endl;
	cout<<"\t\t\t"<<"|           3.查询           |"<<endl;
	cout<<"\t\t\t"<<"|           4.浏览           |"<<endl;
	cout<<"\t\t\t"<<"|           5.修改           |"<<endl;
	cout<<"\t\t\t"<<"|           6.删除           |"<<endl;
	cout<<"\t\t\t"<<"|           7.添加           |"<<endl;
	cout<<"\t\t\t"<<"|           8.退出           |"<<endl;
	cout<<"\t\t\t"<<"<---------------------------->"<<"\n\n"<<endl;
	cout<<"请输入你想要选择操作的相应数字"<<endl;
	do
	{
		printf("\n\t请输入你的选择：");
		scanf("%d", &i);
	} while (i <= 0 || i>7);
	return i;

}
struct zggz{
  int id;
  int gongh;
  char name[20];
  float gwgz,xinjgz,zwjt;
  float xiaojgz;
  float yfgz,sfgz;
  float grs;
};
void read()
{
zggz zggz0;
ifstream in("gz.dat",ios::binary);
if(!in)
{
cout<<"Cannot open output file.\n";
	abort();//退出程序
}


	in.read((char *)&zggz0,sizeof(zggz0));
cout<<zggz0.gongh<<" "<<zggz0.name<<" "<<zggz0.gwgz<<" "<<zggz0.xinjgz<<" "<<zggz0.zwjt<<" "<<zggz0.xiaojgz<<" "<<zggz0.yfgz<<" "<<zggz0.sfgz<<endl;
	
	in.close();
};//读取
void write(zggz zggz0){

	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
	cout<<"Cannot open output file.\n";
	abort();//退出程序
	}
		out.write((char *)&zggz0,sizeof(zggz0));
	out.close();
	

};//保存
/*void find();//查询
void list();//浏览
void modify();//修改
void del();//删除*/
void add()
{
	zggz zggz1;
	int gongh1;
  char name1[20];
  float gwgz1,xinjgz1,zwjt1,xiaojgz1;
  cout<<"请依次输入工号、姓名、岗位工资、薪级工资、职务津贴、绩效工资"<<endl;
  cin>>gongh1>>name1>>gwgz1>>xinjgz1>>zwjt1>>xiaojgz1;
  zggz1.gongh=gongh1;
  strcpy(zggz1.name,name1);
  zggz1.gwgz=gwgz1;
  zggz1.xinjgz=xinjgz1;
  zggz1.zwjt=zwjt1;
  zggz1.xiaojgz=xiaojgz1;
  zggz1.yfgz=gwgz1+xinjgz1+zwjt1+xiaojgz1;
  zggz1.grs=grsds(zggz1.yfgz);
  zggz1.sfgz=zggz1.yfgz-zggz1.grs;
  write(zggz1);
	

};//添加
int grsds(float a)
{
	float i;
if(a<500)
  i=a-a*0.05;
else if(500<a&&a<2000)
 i=a-a*0.1;
else if(2000<a&&a<5000)
 i=a-a*0.15;
else if(5000<a&&a<20000)
 i=a-a*0.2;
else if(20000<a&&a<40000)
 i=a-a*0.25;
else if(40000<a&&a<60000)
 i=a-a*0.3;
else if(60000<a&&a<80000)
 i=a-a*0.35;
else if(80000<a&&a<10000)
 i=a-a*0.4;
else
 i=a-a*0.45;
return i;

};//计算个人所得税
//void tuichu();//退出程序
int main()
{  
	switch(menu())
	{
			/*case 1:find();break;
			case 2:list();break;
			case 3:modify();break;*/
			case 4:add();break;
			//case 5:del();break;
			case 6: read();break;
		//	case 7:tuichu();break;
	}
	return 0;

}