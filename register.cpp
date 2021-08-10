#include<bits/stdc++.h>
using namespace std;
string name[100000],nm,mm,amm;
char xb;
struct node
{
    char a[1000];
    void pw()
    {
        char s2[1000]="1";
        int ans[2000];
        int as1[2000],bs1[2000];
        int lena=strlen(a),lenb=1;
        for(int i=lena-1;i>=0;i--)as1[lena-i]=a[i]-'0';
        for(int i=lenb-1;i>=0;i--)bs1[lenb-i]=s2[i]-'0';
        int x=0,j=max(lena,lenb);
        for(int i=1;i<=j;i++)
            ans[i]=as1[i]+bs1[i]+x,x=ans[i]/10,ans[i]=ans[i]%10;
        if(x!=0) j++,ans[j]=x;
        while(ans[j]==0)j--;
        for(int i=j;i>=1;i--)
            a[j-i]=ans[i]+'0';
    }
}tsum;
int sum;
int main()
{
    strcpy(tsum.a,"0");
    srand(time(0));
    system("clear");
    printf("正在初始化...\n");
    ifstream ls(".User/list.txt");
    while(sum++,tsum.pw(),getline(ls,name[sum]));
    ls.close();
    system("clear");
    printf("初始化成功(回车以继续)!");
    getchar();
    int asd=0;
    while(1)
    {
        asd=0;
        system("clear");
        puts("注册:");
        printf("用户名:");getline(cin,nm);
        if(nm.length()<3)continue;
        if(nm.length()>15)continue;
        for(int i=1;i<=sum;i++)
            if(nm==name[i])
            {
                asd=1;
                break;
            }
        if(asd==1)continue;
        for(int i=0;i<nm.length();i++)
        {
            if(!((nm[i]>='0'&&nm[i]<='9')||(nm[i]>='a'&&nm[i]<='z')||(nm[i]>='A'&&nm[i]<='Z')||(nm[i]=='_')))
            {
                asd=1;
                break;
            }
        }
        if(asd==1)continue;
        else break;
    }
    while(1)
    {
        asd=0;
        system("clear");
        puts("注册:");
        printf("用户名:");cout<<nm<<endl;
        printf("密码:");getline(cin,mm);
        if(nm.length()<4)continue;
        if(nm.length()>10)continue;
        for(int i=0;i<nm.length();i++)
        {
            if(!((nm[i]>='0'&&nm[i]<='9')||(nm[i]>='a'&&nm[i]<='z')||(nm[i]>='A'&&nm[i]<='Z')||(nm[i]=='_')))
            {
                asd=1;
                break;
            }
        }
        if(asd==1)continue;
        system("clear");
        puts("注册:");
        printf("用户名:");cout<<nm<<endl;
        printf("密码:");for(int i=0;i<mm.length();i++)printf("X");puts("");
        printf("请再次输入密码:");getline(cin,amm);
        if(amm==mm)break;
    }
    char yzm[10],yz[10];
    int w;
    while(1)
    {
        w=0;
        asd=0;
        system("clear");
        puts("注册:");
        printf("用户名:");cout<<nm<<endl;
        printf("密码:");for(int i=0;i<mm.length();i++)printf("X");puts("");
        int len=rand()%5+3;
        printf("+");for(int i=1;i<=len;i++)printf("-");puts("+");
        printf("|");
        for(int i=1;i<=len;i++)
        {
            int rd=rand()%2;
            if(!rd)
            {
                yzm[w]=char(rand()%26+'a');
                printf("%c",yzm[w]);
            }
            else
            {
                yzm[w]=char(rand()%26+'A');
                printf("%c",yzm[w]);
            }
            w++;
        }
        puts("|");
        printf("+");for(int i=1;i<=len;i++)printf("-");puts("+");
        printf("验证码(上方框内字母):");scanf("%s",yz);
        if(!strcmp(yzm,yz))break;
        else continue;
    }
    while(1)
    {
        asd=0;
        system("clear");
        puts("注册:");
        printf("用户名:");cout<<nm<<endl;
        printf("密码:");for(int i=0;i<mm.length();i++)printf("X");puts("");
        printf("性别(b(boy)或g(girl)或n(不方便透露)):");cin>>xb;
        if(xb=='b'||xb=='g'||xb=='n')break;
    }
    printf("注册成功(回车以继续)!");
    getchar();
    getchar();
    system("clear");
    printf("正在保存设置...\n");
    char dir[1000],yhm[1000];
    for(int i=0;i<nm.length();i++)yhm[i]=nm[i];
    strcpy(dir,"mkdir .User/U");strcat(dir,tsum.a);system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/Username.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/Password.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/Motto.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/ACproblem.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/ACproblems.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/Raiting.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/Profile.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/Gender.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/Nickname.txt");system(dir);
    strcpy(dir,"touch .User/U");strcat(dir,tsum.a);strcat(dir,"/ID.txt");system(dir);
    strcpy(dir,".User/U");strcat(dir,tsum.a);strcat(dir,"/ID.txt");ofstream lg5(dir);lg5<<sum<<endl;lg5.close();
    strcpy(dir,".User/U");strcat(dir,tsum.a);strcat(dir,"/Username.txt");ofstream lg(dir);lg<<nm<<endl;lg.close();
    strcpy(dir,".User/U");strcat(dir,tsum.a);strcat(dir,"/Gender.txt");ofstream lg0(dir);lg0<<xb<<endl;lg0.close();
    strcpy(dir,".User/U");strcat(dir,tsum.a);strcat(dir,"/Password.txt");ofstream lg1(dir);lg1<<mm<<endl;lg1.close();
    strcpy(dir,".User/U");strcat(dir,tsum.a);strcat(dir,"/ACproblem.txt");ofstream lg2(dir);lg2<<0<<endl;lg2.close();
    strcpy(dir,".User/U");strcat(dir,tsum.a);strcat(dir,"/Raiting.txt");ofstream lg3(dir);lg3<<1500<<endl;lg3.close();
    strcpy(dir,".User/U");strcat(dir,tsum.a);strcat(dir,"/Profile.txt");ofstream lg4(dir);
    lg4<<"用户信息"<<endl;
    lg4<<nm<<" "<<(xb=='b'?"♂":(xb=='g'?"♀":" "))<<endl;
    lg4<<"Raiting"<<endl<<1500<<endl;
    lg4<<"格言"<<endl<<endl;
    lg4<<"AC 过的题目：共 "<<0<<" 道题"<<endl;
    strcpy(dir,"open .User/U");strcat(dir,tsum.a);strcat(dir,"/Profile.txt");system(dir);
    ofstream out(".User/sum.txt");out<<tsum.a;out.close();
    ofstream out1(".User/list.txt");
    name[sum]=nm;
    for(int i=1;i<=sum;i++)
    {
        out1<<name[i]<<endl;
    }
    getchar();
    getchar();
    // system("clear");
    return 0;
}