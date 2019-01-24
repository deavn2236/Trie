#ifndef TRIE_H
#define TRIE_H
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include<vector>
using namespace std;

//建立字典树节点的结构体
struct TrieNode{
    int selfcnt;//该单词个数
    int cnt;//字符序列个数
    struct TrieNode * next[26];//子树指针
    bool exist;//该出是否存在单词
    vector<int> line;
    vector<int> preline;
};
//字典树类
class Trie{
   // friend void file(char* filename,char* findword);
public:
    Trie(){root=createTrieNode();}
    TrieNode* createTrieNode();
    void Trie_insert( char* word,int lin);
    TrieNode* Trie_search( char* word);
    TrieNode* Trie_samesearch( char* word);
    void Trie_delete( char* word);
    ~Trie(){delete_Trie(root);}
private:
    TrieNode* root;//根节点
    void delete_Trie(TrieNode* root);

};
//查找文本中的单词
void findword(string filename, char* findword);
//匹配一行字符串
void stringhandle(string s);
//匹配电话号码
void phonehandle(string s);
//查询树中是否有该单词
bool haveword(string s,char* findword);
#endif // TRIE_H
