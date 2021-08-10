#include <bits/stdc++.h>
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
        if(x!=0)
            j++,ans[j]=x;
        while(ans[j]==0)
            j--;
        for(int i=j;i>=1;i--)
            a[j-i]=ans[i]+'0';
    }
}tsum,ID;
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
    int id;
    while(1)
    {
        strcpy(ID.a,"1");
        asd=0;
        system("clear");
        puts("登入:");
        printf("用户名:");
        getline(cin,nm);
        for(int i=1;i<=sum;i++)
            if(nm==name[i])
            {
                asd=1,id=i;
                for(int j=1;j<i;j++)
                    ID.pw();
                break;
            }
        if(asd==1)break;
        else continue;
    }
    string MM;
    char Mm[1000];
    strcpy(Mm,".User/U");strcat(Mm,ID.a);strcat(Mm,"/Password.txt");
    ifstream pw(Mm);getline(pw,MM);pw.close();
    while(1)
    {
        asd=0;
        system("clear");
        puts("登入:");
        printf("用户名:");cout<<nm<<endl;
        printf("密码:");getline(cin,mm);
        if(mm!=MM)continue;
        system("clear");
        puts("登入:");
        printf("用户名:");cout<<nm<<endl;
        printf("密码:");
        for(int i=0;i<mm.length();i++)printf("X");
        puts("");
        printf("请再次输入密码:");
        getline(cin,amm);
        if(amm==MM)break;
    }
    char yz[1000];
    int w;
    while(1)
    {
        char yzm[10]="";
        w=0;
        asd=0;
        system("clear");
        puts("登入:");
        printf("用户名:");cout<<nm<<endl;
        printf("密码:");for(int i=0;i<mm.length();i++)printf("X");puts("");
        int len=rand()%5+3;
        printf("+");
        for(int i=1;i<=len;i++)printf("-");
        puts("+");
        printf("|");
        for(int i=1;i<=len;i++)
        {
            int rd=rand()%2;
            if(!rd)
                yzm[w]=char(rand()%26+'a'),printf("%c",yzm[w]);
            else
                yzm[w]=char(rand()%26+'A'),printf("%c",yzm[w]);
            w++;
        }
        puts("|");
        printf("+");
        for(int i=1;i<=len;i++)printf("-");
        puts("+");
        printf("验证码(上方框内字母):");scanf("%s",yz);
        if(!strcmp(yzm,yz))break;
        else continue;
    }
    system("clear");
    printf("登入成功(回车以继续)!");
    getchar();
    getchar();
    system("clear");
    printf("正在保存设置...\n");
    ofstream IDID("NowUserID.txt");IDID<<"U"<<ID.a<<endl;IDID.close();
    char dir[1000],yhm[1000];
    for(int i=0;i<nm.length();i++)yhm[i]=nm[i];
    ofstream out(".User/sum.txt");out<<tsum.a;out.close();
    system("clear");
    return 0;
}