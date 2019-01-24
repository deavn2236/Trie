# Trie
字典树
## 1.需求描述 
### 1.1 问题描述
哈夫曼算法输出的结果就是一个二元Trie，在二元Trie中，每个左子树分支用0表示，右子树分支用1表示，如下图就是一个二元Trie的示例图。   
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/1.png)  

可以将二元Trie扩展到N-ary Trie中，每个节点都有0-N之间任何个子节点，其中每个分支都用一个对应的符号表示（在N-ary Trie中有N个不同的符号）。例如一个电话本可以用一个N-ary Trie表示，其中N=10，分别表示0-9的是个数字，具体情况如下图所示：  
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/2.png) 
### 1.2 基本要求
1.设计并实现N-ary Trie的ADT（N=26，建立在英语上的Trie）该ADT包括Trie的组织存储一机器上的基本操作：包括初始化，查找，插入，删除等。  
2.应用Trie结构实现文本文档的索引化，首扫描文本文档（存放在TXT文件 中），然后在此基础上用Trie登记单词出现的位置（行号），最后在Trie中实现查询。   
3.用户输入的查询可以是针对一个单词的，也可以针对一个字符序列  
  
### 1.3输入要求
输入形式  
文档，或数据（单词或电话号码）  
用户在文本框的内容根据用户提示填写。   
通过复选框，按钮文本框提示等方式确定用户输入类型，以及需求   
输入数据例子  
1.  
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/3.png)   
2.  
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/4.png)   
### 1.4输出要求

输出形式  
1.对于文件查询来说，输出文本所在的行  
2.对于数据查询来说，输出是否存在该单词  
    输出数据例子  


## 2.设计 
### 2.1 结构设计
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/5.png) 

程序主要功能模块  
  -- 欢迎模块  
开始显示欢迎界面，显示两秒后自动关闭  
  -- 用户输入模块  
用户根据自己的实际需要选择要建立的字典树类型，分为电话号码和单词类型。  
  -- 文件查找模块  
用户从系统中选取txt文件，作为查找文档。  
  -- 字典树模块   
     根据前两种用户输入的类型建立字典树，实现对单词或电话号码的查找，查找有无，查找位置   
    

  欢迎模块----WelcomeDialog类  
用户输入查找模块---CreateTrieDialog类  
文件查找模块---FileForm类  
字典树模块---Trie及TrieNode类  

各模块详解  
1.欢迎模块  
用文字和动画的形式，上方是welcome的欢迎文字，下方是三个萌球跳动的动画。  
同时该欢迎界面显示时间为两秒，显示两秒后自动跳转到主页。  
主要界面如图所示：  
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/6.png) 

2.用户输入查找模块  
图形界面+鼠标点击方式，  
该页面主要有两个功能，  
一是输入并建立单词类型的字典树，并查找自己所建树中有无该单词或该单词为 前缀的电话。  
二是输入并建立电话号码类型的字典树，并查找自己所建树中有无该号码或以该号码为前缀的电话。  
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/7.png) 
特殊设计：  
复选框中选择是否精确查询会决定查询内容为精确单词（电话号码）或以该单词（电话）为前缀的数据。  
当选择电话号码却输入单词时会进行警告弹窗，提示用户点击单词模式  
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/8.png) 

3.文件查找模块  
图形界面+鼠标点击方式  
从本地中选择文件或直接输入路径获得txt文档的地址并输入单词与是否精确查询即可得到所查询单词的行所在位置。  
主要界面：  
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/9.png) 
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/10.png) 
4.字典树模块  
     该模块为对字典树的插入，删除，查询等操作以及对于输入字符串的处理，对应单词的查找，对电话号码的处理。  
    主要方法  
类内部：  
插入Trie_insert()   
查找Trie_search()     
非精确查找Trie_samesearch()   
删除Trie_delete()   
类外部：   
查找单词Findword()    
处理字符串stringhandle()    
处理电话号码phonehandle()    
是否有该单词haveword()  

### 2.2 数据及数据类(型)定义
   1.基本方式：链表树形方式  
以node为基本存储单元，node中selfcnt与cnt区别精确与不精确查找，每个节点有26个指针指向子节点，bool类型的exist用于标志是否有该单词。Vector类型的line和preline主要存储该节点表示单词的行号以及以该节点代表单词为前缀的行号。  
//建立字典树节点的结构体   
struct TrieNode{  
    int selfcnt;//该单词个数  
    int cnt;//字符序列个数  
    struct TrieNode * next[26];//子树指针对应26个字母  
    bool exist;//标志该处是否存在单词  
    vector<int> line;//存储该节点所表示的单词的行数有哪些  
    vector<int> preline;//表示以该节点所表示的字符串为前缀的单词的行数有哪些。  
};  
//字典树类  
class Trie{  
private:  
    TrieNode* root;//根节点，根节点始终为空  
   
};  



2.3.算法设计及分析
    （各模块算法及类内函数的算法伪码表示）
1.字典树插入  
插入单词时，首先判断第一个字母，将其值减‘a’作为其所在数组的位置，然后在该指针出新建节点，同时处理路径节点及该节点的数据，cnt加一，同时指向下一个字母，最后单词遍历完毕后，则对该node处selfcnt与exist进行更新  
以bab为例，如图  

a	b	c	d	....  

a	b	c	d	....  

a	b	c	d	....  
  

void Trie::Trie_insert( char* word,int lin){ 
    if(N0==10)a='1';else a='a';  
    TrieNode* node=root;  
    const char* p=word;  
    while(字符串没有结束){  
        int i=*p-a;  
        if(不存在以其为前缀的节点){  
            在该出创建新节点  
        }  
        进入对应字母的下一个节点   ;  
        插入字符串的下一个字符  
node->cnt+=1;  
        node->preline.push_back(lin);  
    }  
    标记该处存在完整单词  
    该处所在位置的单词数加一  
将行数放入该单词的队列  
  }   

2.前缀查询  
与插入类似，现展示主要伪代码  
while(未到单词末尾){  
        i=*p-a;  
        node=node的next[i]指针;  
        if(node为空)说明没有该种节点;  
        p++;  
    }  
    return 找到了;  

3.字符串处理  

1.对于单词来说：  
    1）当单词中有标点符号分割等情况，除单词之外的字符全部舍弃，即其ascll码只要在‘a’-‘z’之间或者在‘A’-‘Z’之间即可。  
for(int i=0;i<word.length();i++)  
if(属于字母){   
                if(stdis!=i){//可以避免插入为空 
                    将该字符串剪切出来  
                    将该字符串放入队列   
                }  
                stdis=i+1;  
                b=true;  
            }  
if(b){  
            if(最后一个分割后面仍然有字符串) 
            将其剪切并放入队列  
            continue;  
        }  
          v.push_back(word);  

      用于截取每一个正确的单词，当两单词之前有，或.等其他字符时，则将两个单词分别放入数组中，进行后面的操作。  
   
2）大写字母与小写字母之间的转化。  
   当文件或输入为大写字母时，小写字母的查询同样可以查询得到。  
if(word[i]>'A'&&word[i]<'Z')word[i]=word[i]+'a'-'A';//处理大写字母  
在以上for循环中加入上述语句，如果为大写字母，则先转化成小写字母再进行插入自典树操作。  

2.对电话号码来说  
   只需要判断所有字符是否是纯数字即可  
     for(每一个输入){  
 if(输入中有字符小于1大于9){  
                标记有错误;  
                return;  
            }  
        }  
根据标记判断是否要弹出警告框。 
  
4.文件的读写  
   由于要确定行号，所以文章按行读写对行进行计数与字典树的插入   
 while(!in.eof()){//如果未读到文章末尾  
    getline(in,s);//得到一行数据  
    stringhandle(s);/字符串处理  
    for(循环v数组中的每个单词){  
        往总字典树中添加单词  
    }  
       lin++;  
       v.clear();//清空vector  
    }  


                

## 3.测试结果
本实验主要效果有两个   
第一，选定输入类型，输入所需数据，以及查询数据，选择是否精确查询，最后输出所输入的数据中是否有该单词或者电话号码或以查询数据为前缀的电话号码或单词。 
 
 ![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/11.png)   
第二，选定或输入文件路径，并且输入查询单词，选择是否精确查询即可输出所查询的单词的行数，或者以其为前缀的单词的行数。  
![image](https://github.com/deavn2236/Trie/blob/master/picture_readme/12.png)   
## 4. 分析与探讨 
 本实验主要是对已存在的数据进行处理，根据数据类型构建字典树，并且实现前缀查找和具体查找的功能。字典树的本质其实也是以空间换时间的思想。  
字典树的构建一及其行数的储存需要的空间较大，而且数据越多，相同数据越少所需的储存空间越大，但是，一旦建立起字典树，对于其查询一及插入删除等操作所需的时间复杂度则较为优化，查询操作可以达到O（logn）的水平，插入操作也可以达到O（logn）的水平。  
其他想法：  
字典树在后缀查找反面的应用。  
对于字典树寻找前缀是十分方便的，类似的，字典树也可以进行一系列的操作，进行后缀操作，只需在输入数据时，将一组数据倒叙输入构建字典树即可完成倒叙字典树的构建，对数据的查询只需将所需查询的单词也按照倒序的方式进行输入查询即可，对于空间复杂性和时间复杂性来说，与纯字典树一般无二，对于其查询等操作仍然只需O（logn）即可。  
