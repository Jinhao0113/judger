#include<bits/stdc++.h>
using namespace std;
char bj1[50][200]=
{
    "    lj Online Judge                                           1 注册    2 登入",
    "--------------------------------------------------------------------------------",
    "                                   3  关于LJOJ                                ",
    "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
};
char bj2[50][200]=
{
    "    lj Online Judge                                        1 ",
    "--------------------------------------------------------------------------------",
    "   3 关于LJOJ  4 题库   5 个人信息   6 修改个人信息   7 新建题目   8 比赛    ",
    "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
};
int main()
{
    int asd=0;
    system("clear");
    while(1)
    {
        system("clear");
        if(asd==0)
        {
            for(int i=0;i<4;i++)
                printf("%s\n",bj1[i]);
            int cmd;
            scanf("%d",&cmd);
            if(cmd==1){system("./register");}
            else if(cmd==2){system("./Login");asd=1;continue;}
            else if(cmd==3){system("open help.pdf");}
            else continue;
        }
        else
        {
            char User[1000]=".User/",ID[1000];
            FILE * in=fopen("NowUserID.txt","r");
            fscanf(in,"%s",ID);
            fclose(in);
            strcat(User,ID);strcat(User,"/Username.txt");
            FILE * In=fopen(User,"r");fscanf(In,"%s",User);
            printf("%s%10s%s\n",bj2[0],User," 2 登出");
            for(int i=1;i<4;i++)
                printf("%s\n",bj2[i]);
            int cmd;
            scanf("%d",&cmd);
            if(cmd==2){asd=0;continue;}
            else if(cmd==3){system("open help.pdf");}
            else if(cmd==4){}
            else if(cmd==5){char Pro[1000]="open .User/";strcat(Pro,ID);strcat(Pro,"/Profile.txt");system(Pro);}
            else if(cmd==6){system("./change");}
            else if(cmd==4){}
            else if(cmd==8){}
            else continue;
        }
        
    }
    return 0;
}