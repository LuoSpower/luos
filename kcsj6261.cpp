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
zggz zggz0[50],*p;   //ȫ�ֱ�������
int number,oup;      //ȫ�ֱ���ͳ������
void read()     //��ȡ����
{
ifstream in("gz.dat",ios::binary);
if(!in)
{
cout<<"Cannot open output file.\n";
	abort();  //�˳�����
}
in.read((char *)&::zggz0,sizeof(::zggz0));
in.close();//�ر��ļ�
for(int n=0;n<50;n++)
	{ 
	if(::zggz0[n].gongh!=NULL)
		::number=n+1;
	else
		break;
	}
menu();
};
void write(zggz *p,int k){   //���溯��

	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
	cout<<"Cannot open output file.\n";
	abort();//�˳�����
	}
	for(int i=0;i<k+1;i++)
	{
		out.write((char *)&*p,sizeof(*p));
        p++;
}
	out.close();
cout<<"����ɹ�"<<endl;	
cout<<"�������ز˵�"<<"  ";
  system("pause");
	read();     //���ò˵�
};
void find()     //��ѯ����
{
      //read();
	      int k,i=0,w;
          loop:cout<<"��������Ҫ��ѯ�Ĺ��ţ�"<<endl;
		  cin>>k;
		  for(int j=0;j<::number;j++)
		  {    
			  
				 if (k==::zggz0[j].gongh)
				 {
				 cout<<"ְԱ��Ϣ���£�"<<endl;
				 cout<<"����"<<"\t"<<"����"<<"\t"<<"��λ����"<<"\t"<<"н������"<<"\t"<<"ְ����"<<"\t"<<"Ч������"<<"\t"<<"Ӧ������"<<"\t"<<"ʵ������"<<endl;
		         cout<<::zggz0[j].gongh<<"\t"<<::zggz0[j].name<<"\t"<<::zggz0[j].gwgz<<"\t\t"<<::zggz0[j].xinjgz<<"\t\t"<<::zggz0[j].zwjt<<"\t\t"<<::zggz0[j].xiaojgz<<"\t\t"<<::zggz0[j].yfgz<<"\t\t"<<zggz0[j].sfgz<<endl;
	             i=k;
				 cout<<"���²�ѯ��1�����˵����������"<<endl;
				 cin>>w;
			     if(w==1)
				   goto loop;
			     else 
				   menu();
				 }
		  }
		  if(i!=k)
		  {
		   cout<<"û�����ְԱ����Ϣ�����²�ѯ��1�����˵����������"<<endl;
		   cin>>w;
			   if(w==1)
				   goto loop;
			   else 
				   menu();
		  }
	   
};//��ѯ
void list()      //���ְԱ��Ϣ����
{   
	//read();
	cout<<"����"<<::number<<"�ˣ����е�ְԱ��Ϣ���£�"<<endl;
	cout<<"����"<<"\t"<<"����"<<"\t"<<"��λ����"<<"\t"<<"н������"<<"\t"<<"ְ����"<<"\t"<<"Ч������"<<"\t"<<"Ӧ������"<<"\t"<<"ʵ������"<<endl;
	for(int i=0;i<::number;i++)
	{
	cout<<::zggz0[i].gongh<<"\t"<<::zggz0[i].name<<"\t"<<::zggz0[i].gwgz<<"\t\t"<<::zggz0[i].xinjgz<<"\t\t"<<::zggz0[i].zwjt<<"\t\t"<<::zggz0[i].xiaojgz<<"\t\t"<<::zggz0[i].yfgz<<"\t\t"<<zggz0[i].sfgz<<endl;
	}
	cout<<"�������ز˵�"<<"  ";
	system("pause");
menu();
};//���
void modify()
{ 
          int k,i=0,w,a1,a2,a3,a4;
		  zggz zggz1,*q;
          loop:cout<<"��������Ҫ�޸ĵĹ��ţ�"<<endl;
		  cin>>k;
		  for(int j=0;j<::number;j++)
		  {    
			  
		 if (k==::zggz0[j].gongh)
		 {
		 cout<<"ְԱ��Ϣ���£�"<<endl;
		 cout<<"����"<<"\t"<<"����"<<"\t"<<"��λ����"<<"\t"<<"н������"<<"\t"<<"ְ����"<<"\t"<<"Ч������"<<"\t"<<"Ӧ������"<<"\t"<<"ʵ������"<<endl;
		 cout<<::zggz0[j].gongh<<"\t"<<::zggz0[j].name<<"\t"<<::zggz0[j].gwgz<<"\t\t"<<::zggz0[j].xinjgz<<"\t\t"<<::zggz0[j].zwjt<<"\t\t"<<::zggz0[j].xiaojgz<<"\t\t"<<::zggz0[j].yfgz<<"\t\t"<<zggz0[j].sfgz<<endl;
	     cout<<"�޸ĺ�ĸ�λ���ʣ�"<<"  "; 
         cin>>a1;
		 cout<<"�޸ĺ��н�����ʣ�"<<"  ";
		 cin>>a2;
		 cout<<"�޸ĺ��ְ�������"<<"  ";
		 cin>>a3;
		 cout<<"�޸ĺ��Ч�����ʣ�"<<"  ";
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
		 cout<<"�޸ĳɹ������棨1�����˵����������"<<endl;
		 cin>>w;
		 if(w==1)
			 write(q,::oup);
		 else
		 menu();

};//�޸�
//void del();//ɾ��
void add()
{  int i;
	zggz zggz1[50];
	::p=zggz1;
//	read();
	cout<<"��������ְԱ����Ϊ"<<::number<<"��"<<endl;
	for(int j=0;j<::number;j++)
	{
	 zggz1[j]=zggz0[j];
	
	}
	for(i=::number;i<100;i++)
	{
	int gongh1;
  char name1[20];
  float gwgz1,xinjgz1,zwjt1,xiaojgz1;
  cout<<"���������빤�š���������λ���ʡ�н�����ʡ�ְ���������Ч����"<<endl;
  cin>>gongh1>>name1>>gwgz1>>xinjgz1>>zwjt1>>xiaojgz1;
  zggz1[i].gongh=gongh1;
  strcpy(zggz1[i].name,name1);
  zggz1[i].gwgz=gwgz1;
  zggz1[i].xinjgz=xinjgz1;
  zggz1[i].zwjt=zwjt1;
  zggz1[i].xiaojgz=xiaojgz1;
  zggz1[i].yfgz=gwgz1+xinjgz1+zwjt1+xiaojgz1;     //����Ӧ������
  zggz1[i].grs=grsds(zggz1[i].yfgz);              //�����������˰
  zggz1[i].sfgz=zggz1[i].yfgz-zggz1[i].grs;       //����ʵ������
  cout<<"�Ƿ������ӣ�1/0"<<endl;
	int k;
	cin>>k;
	if(k==0)
	{
	break;
	}
	}
	::oup=i;
  cout<<"�뷵�ز˵�����"<<endl;
  cout<<"�������ز˵�"<<"  ";
  system("pause");
	menu();     //���ò˵�

};//���
int grsds(float a)  //�����������˰
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
};//�˳�����
void menu(){                              //�˵�
  int i;
    cout<<"\t\t\t"<<"<-----------�γ����--------->"<<endl;
	cout<<"\t\t\t"<<"|           1.��ѯ           |"<<endl;
	cout<<"\t\t\t"<<"|           2.�޸�           |"<<endl;
	cout<<"\t\t\t"<<"|           3.���           |"<<endl;
	cout<<"\t\t\t"<<"|           4.ɾ��           |"<<endl;
	cout<<"\t\t\t"<<"|           5.����           |"<<endl;
	cout<<"\t\t\t"<<"|           6.���           |"<<endl;
	cout<<"\t\t\t"<<"|           7.�˳�           |"<<endl;
	cout<<"\t\t\t"<<"<---------------------------->"<<"\n\n"<<endl;
	cout<<"����������Ҫѡ���������Ӧ����"<<endl;
	do
	{
		printf("\n\t���������ѡ��");
		scanf("%d", &i);
	} while (i <= 0 || i>7);
	
switch(i)       //���ú���
	{
            case 1:find();break;//��ѯ
			case 2:modify();break;//�޸�
			case 3:add();break;//���
		//	case 4:del();break;//ɾ��
			case 5:write(::p,::oup);break;//����
			case 6: list();break;//���
			case 7:tuichu();break;//�˳�
	}
read();
}
int main()
{  
	read();
	return 0;

}
