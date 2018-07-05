/*****************************************************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
File name: Employee salary manageement system // �ļ���
Author: �޶� Version: 1.0 Date: 2018.7.1 // ���ߡ��汾���������
Description: 
���ж�ְ����Ϣ��1.��ѯ 2.�޸� 3.���� 4.ɾ�� 5.���� 6.����Ȳ�����
//������ϸ˵���˳����ļ���ɵ���Ҫ���ܣ�������ģ������Ľӿڣ�
//���ֵ��ȡֵ��Χ�����弰������Ŀ��ơ�˳�򡢶����������ȹ�ϵ
menu()�˵���read()��ȡ���ݡ�find()��ѯ��modify()�޸ġ�add()���ӡ�del()ɾ����write()���桢list()���
Others: �ó�����Ҫ�����ڱ����Ͻ���gz.dat�ļ�// �������ݵ�˵��
Function List: // ��Ҫ�����б���ÿ����¼Ӧ���������������ܼ�Ҫ˵��
1. read()��ȡ���� 2. find()��ѯ 3. modify()�޸� 4. add()���� 5. del()ɾ�� 6. write()���� 7. list()���
History: // �޸���ʷ��¼�б���ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ���
1. Date:2018.7.1
Author:�޶�
Modification:���г����Ű�
*******************************************************************************************************/
#include<stdio.h>
#include<fstream>
using namespace std;
int grsds(float a);
void menu();                        //��������
struct zggz
{
  int gongh;
  char name[20];
  float gwgz,xinjgz,zwjt;
  float xiaojgz;
  float yfgz,sfgz;
  float grs;
};
zggz zggz0[100],*p;   //ȫ�ֱ�������
int number,oup;      //ȫ�ֱ���ͳ������

/**********************************************************
Function:  read                  //��������
Description:  ��ȡ�ļ��е�����   //�������ܣ����ܵ�����
Calls:                           // �����������õĺ����嵥
Called By:  main(),write()       //���øú����ĺ����嵥
Output:                          // �����������˵��
**********************************************************/
void read()     //��ȡ����
{
FILE *fp;
    if((fp=fopen("gz.dat","rb"))==NULL) //�ж��ļ��Ƿ����
    {
      fp=fopen("gz.dat","wb");          //����ļ������ڣ��½�һ���ļ�
    }
    fclose(fp);                         //�ر��ļ�
ifstream in("gz.dat",ios::binary);
if(!in)
{
printf("Cannot open output file.\n");
	abort();  //�˳�����
}
in.read((char *)&::zggz0,sizeof(::zggz0));
in.close();//�ر��ļ�
for(int n=0;n<100;n++)
	{ 
	if(zggz0[n].gongh!=NULL)
	   number=n+1;           //�����ļ���ְ����������
	else
		break;
	}
};
/**********************************************************
Function:  write                 //��������
Description:  �������ݵ��ļ���   //�������ܣ����ܵ�����
Calls:      menu()               // �����������õĺ����嵥
Called By: menu()                //���øú����ĺ����嵥
Output:                          // �����������˵��
**********************************************************/
void write(zggz *p,int k){   //���溯��
	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
	printf("Cannot open output file.\n");
	abort();//�˳�����
	}
	for(int i=0;i<k;i++)
	{
		out.write((char *)&*p,sizeof(*p));
        p++;
	}
	out.close();
printf("����ɹ�");//cout<<"����ɹ�"<<endl;	
printf("�������ز˵�  ");//cout<<"�������ز˵�"<<"  ";
  system("pause");
  read();	
  menu();   //���ò˵�
};
/***********************************************************
Function:  find                  //��������
Description:  ��������           //�������ܣ����ܵ�����
Calls:      menu()               // �����������õĺ����嵥
Called By: menu()                //���øú����ĺ����嵥
Output:                          // �����������˵��
***********************************************************/
void find()     //��ѯ����
{
	      int k,i=101,w;
  loop:   printf("��������Ҫ��ѯ�Ĺ���\n");
		  scanf("%d",&k);
		  for(int j=0;j<::number;j++)
		  {    
			  
				 if (k==::zggz0[j].gongh)                                                                        //�жϲ�ѯ����
				 {
				 printf("ְԱ��Ϣ���£�\n");
				 printf("����\t����\t��λ����\tн������\tְ����\tЧ������\tӦ������\tʵ������\n");             //���ְ����Ϣ
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
				 printf("���²�ѯ��1�����˵����������\n");
				 scanf("%d",&w);
			     if(w==1)
				   goto loop;
			     else 
				   menu();
				 }
		  }
		  if(i!=k)
		  {
		  printf("û�����ְԱ����Ϣ�����²�ѯ��1�����˵����������\n");
		  scanf("%d",&w);
		  if(w==1)
		   goto loop;
		  else 
		   menu();
		  }
	   
};//��ѯ
/**********************************************************
Function:  list()                 //��������
Description:  �������            //�������ܣ����ܵ�����
Calls:      menu()                // �����������õĺ����嵥
Called By: menu()                 //���øú����ĺ����嵥
**********************************************************/
void list(int k)      //���ְԱ��Ϣ����
{  

	printf("����%d��,������Ϣ���£�\n",k);
	if(k!=0)
	{
	printf("����\t����\t��λ����\tн������\tְ����\tЧ������\tӦ������\tʵ������\n");
	}
	for(int i=0;i<::number;i++)
	{
    printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",                  //���ְ����Ϣ
		::zggz0[i].gongh,
		::zggz0[i].name,
		::zggz0[i].gwgz,
		::zggz0[i].xinjgz,
		::zggz0[i].zwjt,
		::zggz0[i].xiaojgz,
		::zggz0[i].yfgz,
		::zggz0[i].sfgz);
	 }
    printf("�������ز˵�  ");
  	system("pause");
    menu();
};//���
/**********************************************************
Function:  modify                 //��������
Description:  �޸�����            //�������ܣ����ܵ�����
Calls:      menu()                // �����������õĺ����嵥
Called By: menu()                 //���øú����ĺ����嵥
**********************************************************/
void modify()
{ 
          int k,i=0,w,a1,a2,a3,a4;
		  zggz *q;
  loop:   printf("��������Ҫ�޸ĵĹ��ţ� \n");
		  scanf("%d",&k);
		  for(int j=0;j<::number;j++)
		  {    
			  
		  if (k==::zggz0[j].gongh)
		  {
		  printf("ְԱ��Ϣ���£�");
		  printf("����\t����\t��λ����\tн������\tְ����\tЧ������\tӦ������\tʵ������\n");
          printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",                                             //��������޸ĵ�ְ����Ϣ
			 ::zggz0[i].gongh,
			 ::zggz0[i].name,
			 ::zggz0[i].gwgz,
			 ::zggz0[i].xinjgz,
			 ::zggz0[i].zwjt,
			 ::zggz0[i].xiaojgz,
			 ::zggz0[i].yfgz,
			 ::zggz0[i].sfgz);
	     printf("�޸ĺ�ĸ�λ����:   \n"); 
         scanf("%d",&a1);
		 printf("�޸ĺ��н�����ʣ�  \n");
		 scanf("%d",&a2);
		 printf("�޸ĺ��ְ�������  \n");
		 scanf("%d",&a3);
		 printf("�޸ĺ��Ч�����ʣ�  \n");
		 scanf("%d",&a4);
		 ::zggz0[j].gwgz=a1;                                                               //���޸ĵ�ְ����Ϣ���¸�ֵ
		 ::zggz0[j].xinjgz=a2;
		 ::zggz0[j].zwjt=a3;
		 ::zggz0[j].xiaojgz=a4;
		 ::zggz0[j].yfgz=a1+a2+a3+a4;
		 ::zggz0[j].grs=grsds(::zggz0[j].sfgz);
		 ::zggz0[j].sfgz=::zggz0[j].yfgz-::zggz0[j].grs;
		 i=j;
		 q=::zggz0;
		 printf("�޸ĳɹ������棨1�����������棬���ز˵����������\n");                     //�޸ĳɹ�ȷ���Ƿ񱣴�
		  scanf("%d",&w);
		 if(w==1)
			 write(q,::oup);
		 else
		 menu();

		 }    
		 }
         if(i!=j)
		  {
		   printf("û�����ְԱ����Ϣ�����²�ѯ��1�����˵����������\n");               //�޸�ʧ�ܣ�δ�����������ְ���ţ�ѯ���Ƿ���������򷵻ز˵�
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
		  

};//�޸�
/**********************************************************
Function:  del                 //��������
Description:  ɾ������   //�������ܣ����ܵ�����
Calls:      menu()               // �����������õĺ����嵥
Called By: menu()               //���øú����ĺ����嵥
Output:                          // �����������˵��
**********************************************************/
void del()
{
	::p=::zggz0;
	 int gonghao;
	 printf("������Ҫɾ����Ա�����ţ�\n");
	 scanf("%d",&gonghao);
	 for(int i=0;i<::number;i++)
	 {
	 if(gonghao==::zggz0[i].gongh)  //�ж�����Ĺ����Ƿ����
	 {  printf("����\t����\t��λ����\tн������\tְ����\tЧ������\tӦ������\tʵ������\n");             //�������ɾ����ְԱ��Ϣ
          printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",
			 ::zggz0[i].gongh,
			 ::zggz0[i].name,
			 ::zggz0[i].gwgz,
			 ::zggz0[i].xinjgz,
			 ::zggz0[i].zwjt,
			 ::zggz0[i].xiaojgz,
			 ::zggz0[i].yfgz,
			 ::zggz0[i].sfgz);
        printf("�������Ҫɾ������Ϣ"); 
		if(i!=::number)                //�ж�����Ĺ����Ƿ������һ��
		{
		for(;i<::number;i++)
		{
		 ::zggz0[i]=::zggz0[i+1];       //����һ����ǰ����
		}
		 ::number=::number-1;           //������һ
		}
		else
		{
		::number=::number-1;             //������һ
		}
	}
	}
	 printf("�Ƿ�ȷ��ɾ����ȷ��ɾ����Y��, ����ɾ��,���ز˵���N��");       //ȷ���Ƿ�ɾ�������߷��ز˵�
		char g;
	    scanf("%s",&g);
		if(g=='Y')
		{
			write(::p,::number);                                          //����ɾ����ĵ����ݵ��ļ���
		}
		else
		{   
			read();
			menu();
		}
};//ɾ��*/
/**********************************************************
Function:  add                   //��������
Description:  ��������           //�������ܣ����ܵ�����
Calls:      menu(),grsds()       // �����������õĺ����嵥
Called By:  menu()               //���øú����ĺ����嵥
Output:                          // �����������˵��
**********************************************************/
void add()
{   int i;
	zggz zggz1[100];
	::p=zggz1;
	printf("��������ְԱ����Ϊ%d��\n",::number);
	for(int j=0;j<::number;j++)
	{
	 zggz1[j]=zggz0[j];
	}
	for(i=::number;i<100;i++)
	{
	int gongh1;
    char name1[20];
    float gwgz1,xinjgz1,zwjt1,xiaojgz1;
    printf("���������빤�š���������λ���ʡ�н�����ʡ�ְ���������Ч����\n");
    scanf("%d%s%f%f%f%f",&gongh1,&name1,&gwgz1,&xinjgz1,&zwjt1,&xiaojgz1);            //����ְԱ��Ϣ
    zggz1[i].gongh=gongh1;                          //����
    strcpy(zggz1[i].name,name1);                    //����
    zggz1[i].gwgz=gwgz1;                            //��λ����
    zggz1[i].xinjgz=xinjgz1;                        //н������
    zggz1[i].zwjt=zwjt1;                            //����ְ�����
    zggz1[i].xiaojgz=xiaojgz1;                      //����Ч������
    zggz1[i].yfgz=gwgz1+xinjgz1+zwjt1+xiaojgz1;     //����Ӧ������
    zggz1[i].grs=grsds(zggz1[i].yfgz);              //�����������˰
    zggz1[i].sfgz=zggz1[i].yfgz-zggz1[i].grs;       //����ʵ������
    printf("�Ƿ�������ӣ�1/0\n");
	int k;
	scanf("%d",&k);
	if(k!=1)
	{
	break;
	}
	}
	::oup=i+1;
    printf("�뷵�ز˵�����  \n");
    printf("�������ز˵�        \n");
    system("pause");
	menu();     //���ò˵�

};//����
/*****************************************************************
Function:  grsds                         //��������
Description:  �����������˰             //�������ܣ����ܵ�����
Calls:    *                              // �����������õĺ����嵥
Called By:    add(),modify()             //���øú����ĺ����嵥
******************************************************************/
int grsds(float a)   //�����������˰
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
void tuichu()       //�˳�����
{
exit(0);
};  
/**************************************************************************************************************
Function:  menu()                                                                   //��������
Description:  �˵�ѡ��                                                              //�������ܣ����ܵ�����
Calls:   find(),modify(),add(),del(),write(),list(),tuichu()                        // �����������õĺ����嵥
Called By:  main(),write(), find(),modify(),add(),del(),list(),                     //���øú����ĺ����嵥
Output:                                                                             // �����������˵��
***************************************************************************************************************/ 
void menu(){    //�˵�
  int i;
    printf("\t\t\t\t###   ��ӭʹ�ù��������ѧ��������Ϣ��ȫѧԺְ�����ʹ���ϵͳ   ###\n\n");
	printf("\t\t\t\t=================================================================|\n");
	printf("\t\t\t\t��ѡ�� <1~7>:                                                    |\n");
  	printf("\t\t\t\t|                                                                |\n");
	printf("\t\t\t\t|                     1.��ѯְ�����ʼ�¼                         |\n");
	printf("\t\t\t\t|                     2.�޸�ְ�����ʼ�¼                         |\n");
	printf("\t\t\t\t|                     3.����ְ�����ʼ�¼                         |\n");
	printf("\t\t\t\t|                     4.ɾ��ְ�����ʼ�¼                         |\n");
	printf("\t\t\t\t|                     5.�������ݵ��ļ�                           |\n");
	printf("\t\t\t\t|                     6.���ְ������                             |\n");
	printf("\t\t\t\t|                     7.�˳�ϵͳ                                 |\n");
	printf("\t\t\t\t|                                                                |\n");
    printf("\t\t\t\t==================================================================\n");
	do
	{
	printf("\n\t���ѡ���ǣ�");
	scanf("%d", &i);
	} while (i <= 0 || i>7);
switch(i)       //���ú���
{ 
            case 1:system("cls");find();break;               //��ѯ����
			case 2:system("cls");modify();break;             //�޸ĺ���
			case 3:system("cls");add();break;                //���Ӻ���
			case 4:system("cls");del();break;                //ɾ������
			case 5:system("cls");write(::p,::oup);break;     //���溯��
			case 6:system("cls");list(::number);break;      //�������
			case 7:system("cls");tuichu();break;             //�˳�����
	}
}
int main()
{  
	read();
	menu();
	return 0;

}