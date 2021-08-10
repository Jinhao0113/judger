#include<bits/stdc++.h>
using namespace std;
int main()
{
    system("clear");
    puts("欢迎使用 ojshell !\n\n命令指南:\nnp 新建题目 \nnc 新建比赛\nst 提交\nli 登入\nrg 注册\nCLS 清屏\not 退出\n注意:请在输入命令时在前面打一个空格!");
    getchar();
    string cd;
    while(1)
    {
        printf("@oj2.0>");
        char c=getchar();
        if(c=='\n')continue;
        string cmd;
        cin>>cmd;
        if(cmd=="np")
        {
            system("g++ newproblem.cpp -o newproblem");
            system("./newproblem");
        }
        else if(cmd=="nc")
        {
            system("g++ newcontest.cpp -o newcontest");
            system("./newcontest");
        }
        else if(cmd=="st")
        {
            system("g++ ceping.cpp -o ceping");
            system("./ceping");
        }
        else if(cmd=="li")
        {
            system("g++ Login.cpp -o Login");
            system("./Login");
        }
        else if(cmd=="rg")
        {
            system("g++ register.cpp -o register");
            system("./register");
        }
        else if(cmd=="CLS")
        {
            system("clear");
        }
        else if(cmd=="ot")
        {
            system("clear");
            return 0;
        }
        else
        {
            cout<<cmd<<endl;
        }
        
    }
    return 0;
}
