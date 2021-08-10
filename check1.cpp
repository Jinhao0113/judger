#include<bits/stdc++.h>
using namespace std;
void check(int x)
{
    // FILE*ch=fopen(FL,"w");
    printf("#include<bits/stdc++.h>\n");
    printf("using namespace std;\n");
    printf("string nd[1000001],bz[1000001];\n");
    printf("int fen[1000001],n,zfen;\n");
    printf("int lnd,lbz,ans;\n");
    // printf("string RE[100];");
    printf("int test[100],len;\n");
    // printf("int check2(string a)\n");
    // printf("{\n");
    // printf("    int x=0,asd=0,len=a.length();\n");
    // printf("    int tr;\n");
    // printf("    for(int i=0;i<=len;i++)\n");
    // printf("    {\n");
    // printf("        if(a[i]>='0'&&a[i]<='9')\n");
    // printf("        {\n");
    // printf("            if(asd==1)x=x*10+a[i]-'0';\n");
    // printf("            else x=a[i]-'0',asd=1;\n");
    // printf("        }\n");
    // printf("        else\n");
    // printf("        {\n");
    // printf("            if(asd==1)\n");
    // printf("            {\n");
    // printf("                tr=x;\n");
    // printf("                asd=0,x=0;\n");
    // printf("            }\n");
    // printf("        }\n");
    // printf("    }\n");
    // printf("    return tr;\n");
    // printf("}\n");
    printf("void check(int x)\n");
    printf("{\n");
    // printf("    for(int i=1;i<=lbz;i++)\n");
    // printf("    {\n");
    // printf("        int lena=bz[i].length(),lenb=nd[i].length();\n");
    // printf("        if(bz[i][lena-1]==' ')lena--;\n");
    // printf("        if(nd[i][lenb-1]==' ')lenb--;\n");
    // printf("        if(lena!=lenb){return ;}\n");
    // printf("        for(int j=0;j<lena;j++)\n");
    // printf("            if(bz[i][j]!=nd[i][j]){return ;}\n");
    // printf("    }\n");
    // printf("    printf(\"AC\\n\");\n");
    printf("    for(int i=1;i<=lbz;i++)\n");
    printf("        if(nd[i]!=bz[i])return ;\n");
    printf("    zfen+=fen[x];\n");
    printf("    return ;\n");
    printf("}\n");
    printf("int main()\n");
    printf("{\n");
    // printf("    ifstream CE(\"%s/CE2.txt\");\n",ID);
    // printf("    while(len++,getline(CE,RE[len]));\n");
    // printf("    for(int i=1;i<=len;i++)\n");
    // printf("    {\n");
    // printf("        test[check2(RE[i])]=1;\n");
    // printf("    }\n");
    printf("    ifstream fn(\"%s/fen.txt\");\n","asdasdasda");
    printf("    fn>>n;\n");
    printf("    for(int i=1;i<=n;i++)\n");
    printf("        fn>>fen[i],ans+=fen[i];\n");
    printf("    fn.close();\n");
    for(int i=1;i<=10;i++)
    {
        printf("    lbz=lnd=1;\n");
        // printf("    memset(nd,\"\",sizeof(nd));\n");
        // printf("    memset(bz,\"\",sizeof(bz));\n");
        // printf("    if(test[%d]==1);\n",i);
        // printf("    else\n");
        // printf("    {\n");
        printf("    ifstream bzsc%d(\"%s/ans/t%d.out\");\n",i,"edv",i);
        printf("    ifstream ndsc%d(\"%s/out/t%d.out\");\n",i,"sdv",i);
        printf("    while(ndsc%d>>nd[lnd],lbz++);\n",i);
        printf("    while(bzsc%d>>bz[lbz],lnd++);\n",i);
        printf("    bzsc%d.close();\n",i);
        printf("    ndsc%d.close();\n",i);
        // printf("        if(bz[lbz]==\"\\n\")\n");
        // printf("            lbz--;\n");
        // printf("        if(nd[lnd]==\"\\n\")\n");
        // printf("            lnd--;\n");
        printf("    if(!(lnd-lbz))check(%d);\n",i); 
        // printf("    }\n");
    }
    // printf("    printf(\"总得分:%%d\\n\",zfen);\n");
    // printf("    if(zfen==ans){puts(\"你通过了此题!\");}\n");
    printf("    printf(\"%%d\\n\",zfen);\n");
    printf("    return 0;\n");
    printf("}\n");
}
int main()
{
    check(10);
    return 0;
}