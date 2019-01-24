#include<iostream>
#include <fstream>
#include<cstring>
#include <stdlib.h>
#include<sstream>
#include<queue>
#include<QDebug>
#include"trie.h"
#include<exception>
#include"createtriedialog.h"
using namespace std;
int N=26;
extern int N0;
bool bb=true;
vector<string>v;
QString lines;
bool ifer=false;
bool ifword;
extern bool ischeck;
//创建一个空的字典树节点
int a='a';
TrieNode* Trie::createTrieNode(){
    TrieNode* node =new TrieNode();
    node->cnt=0;
    node->selfcnt=0;
    node->exist=false;
    memset(node->next,0,sizeof(node->next));
    return node;
}
//向字典树中插入一个单词
void Trie::Trie_insert( char* word,int lin){
    if(N0==10)a='1';else a='a';
    TrieNode* node=root;
    const char* p=word;
    while(*p){
        int i=*p-a;
        if(node->next[i]==0){
            node->next[i]=createTrieNode();
        }
        node=node->next[i];
        p++;
        node->cnt+=1;
        node->preline.push_back(lin);
    }
    node->exist=true;
    node->selfcnt+=1;
    node->line.push_back(lin);
    //qDebug()<<lin<<endl;
}
//查找是否有相同的单词或以此为前缀的
TrieNode* Trie::Trie_search(char* word){
    if(N0==10)a='1';else a='a';
    TrieNode * node=root;
    const char* p=word;
    int i;
    while(*p){
        i=*p-a;
        try{
        node=node->next[i];
        }catch(exception e){
            ifer=true;
            return NULL;
        }
        if(node==NULL)return NULL;
        p++;
    }
    return node;
}
TrieNode* Trie::Trie_samesearch(char* word){
    if(N0==10)a='1';else a='a';
    TrieNode * node=root;
    const char* p=word;
    int i;
    while(*p){
        i=*p-a;
        try{
        node=node->next[i];
        }catch(exception e){
            ifer=true;
            return NULL;
        }
        if(node==NULL)return NULL;
        p++;
    }
    if(node->selfcnt!=0) return node;
    else return NULL;
}
/*
//删除对应单词
void Trie::Trie_delete( char* word){
    if(N0==10)a='1';else a='a';
    bool b=Trie_search(word);
    if(b){
        TrieNode * node=root;
        const char *p=word;
        int i;
        while(*p){
            TrieNode* t=node;
            i=*p-a;
            node=node->next[i];
            if(t->cnt==0){
                delete t;
            }
            node->cnt-=1;
        }
        node->selfcnt-=1;
        if(node->cnt==0){
            delete node;
        }else
        if(node->selfcnt==0){
            node->exist=false;
        }
    }
    else{
        qDebug()<<"无对应单词"<<endl;
    }
}*/
void Trie::delete_Trie(TrieNode* root){
    if(root==0){delete root ;return;}
    for(int i=0;i<N;i++){
        delete_Trie(root->next[i]);
    }
    delete root;
    root=0;
}
//读取一行单词
//void readfile(char* filename,vector<string>&v){


//}
//处理一行电话号码
 void phonehandle(string s){
     //v.clear();
     ifer=false;
     string word;
     // qDebug()<<"ssssswwwssseeee"<<endl;
     istringstream istr(s);
    // qDebug()<<"ssssseeee"<<endl;
     // qDebug()<<QString::fromStdString(s)<<endl;
     while(istr>>word){
 //qDebug()<<QString::fromStdString(word)<<endl;
//对得到的每个单词进行处理
        for(int i=0;i<word.length();i++){

           if(word[i]<'0'||word[i]>'9'){
                ifer=true;
                return;
            }
        }

        v.push_back(word);
        // qDebug()<<QString::fromStdString(word)<<endl;

    }
}
//每一行字符串的处理
void stringhandle(string s){
//cout<<"stringhandle"<<endl;

     string word;
     istringstream istr(s);
     while(istr>>word){
//cout<<word<<endl;
        bool b=false;
        int stdis=0;
        string temp;
//对得到的每个单词进行处理
        for(int i=0;i<word.length();i++){
           if(word[i]>'A'&&word[i]<'Z')word[i]=word[i]+'a'-'A';//处理大写字母
           if(word[i]<'a'||word[i]>'z'){
                if(stdis!=i){//可以避免插入为空
                    temp=word.substr(stdis,i-stdis);
                    v.push_back(temp);

                }
                stdis=i+1;
                b=true;
            }
        }
        if(b){
            if(stdis!=word.length())
            v.push_back(word.substr(stdis,word.length()));
            continue;
        }
//cout<<word<<endl;
        v.push_back(word);

    }
//for(int i=0;i<v.size();i++)cout<<v[i]<<endl;

}
//
bool haveword(string s,char* findword){
   // qDebug()<<"ssssss";

    if(N0==10){
        phonehandle(s);
        //qDebug()<<"ssssss"<<endl;
    }
    else stringhandle(s);
    qDebug()<<"aaaaaaaa"<<endl;
   // for(int i=0;i<v.size();i++)qDebug()<<QString::fromStdString(v[i]);
    Trie* tt=new Trie();
    for(int i=0;i<v.size();i++){
        int len=v[i].length();
        char *c=new char[len+1];
        strcpy(c,v[i].c_str());
        tt->Trie_insert(c,0);
    }
     qDebug()<<"ssssss"<<endl;
    TrieNode* howsearch;
    if(ischeck)howsearch=tt->Trie_samesearch(findword);
    else{
        howsearch=tt->Trie_search(findword);
    }
    qDebug()<<"ssssss"<<endl;
    v.clear();
    if(howsearch!=NULL)return true;
    else return false;

}
//字典树的建立并查找
void findword(string filename, char* findword){
    int lin=1;
    ifstream in(filename);
    string s;

    if(!in){
        qDebug()<<"无法打开";return;
    }
    Trie* t=new Trie();

    while(!in.eof()){
    getline(in,s);
    stringhandle(s);
    for(int i=0;i<v.size();i++){
        int len=v[i].length();
        char *c=new char[len+1];
        strcpy(c,v[i].c_str());
        t->Trie_insert(c,lin);
    }
    //cout<<"  okkoko";

    lin++;
//for(int i=0;i<v.size();i++)cout<<v[i]<<endl;
    v.clear();
    }
    TrieNode* howsearch;
    if(ischeck)howsearch=t->Trie_samesearch(findword);
    else{
        howsearch=t->Trie_search(findword);
    }
    if(howsearch!=NULL){
        qDebug()<<howsearch->line.size()<<endl;

        if(ischeck)
        for(int i=0;i<howsearch->line.size();i++){

        lines += QString::fromStdString(to_string(howsearch->line[i])) + " ";
        //qDebug()<<howsearch->line[i]<<"   ";
        }
        else{
            for(int i=0;i<howsearch->preline.size();i++){

            lines += QString::fromStdString(to_string(howsearch->preline[i])) + " ";
            }
        }
    };
}

/*int main(){

    findword("D:\\c++\\ok.txt","i");



}*/
