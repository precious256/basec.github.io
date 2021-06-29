#include<iostream>
#include<string>
using namespace std;
#include<string.h>
void test_constructor()
{
    //1.无参构造
    string s1;
    //2参数为char*构造
    string s2("hello Srting");
    //3.拷贝构造
    string s3(s2);
    //4.区间构造
    string s4(s2,0,5);
    //5.字符构造
    string s5(10,'c');
    const char*str="hello world";
    //6.迭代器构造
    string s6(s2.begin(),s2.begin()+5);
    //7.参数为char* size_t n的构造
    string s7(str,5);
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    cout<<s6<<endl;
    cout<<s7<<endl;
}
// 2.测试赋值运算符
void test_fuzhi()
{
    //1.参数为const string &t的
    string s1("hello Linux");
    string s2=s1;
    //参数为const char*的
    string s3="hello ubuntu";
    //3.参数为字符类的
    string s4;
    s4='g';
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
}
//3.迭代器测试
void test_Iterator()
{
    string s1="hello Linux";
    //1.正向迭代器 begin(),end() 左闭右开，
    int i=0;
    string::iterator it =s1.begin();
    while(it!=s1.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    // 反向迭代器遍历 rbegin(),rend();
    string::reverse_iterator rit=s1.rbegin();
    while(rit!=s1.rend())
    {
        cout<<*rit<<" ";
        ++rit;
    }
    cout<<endl;
}
// 测试容量与大小
void test_size()
{
    string s1("hello Linux");
    cout<<s1<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.capacity()<<endl;
    //cout<<s1<<endl;
    //cout<<s1.size()<<endl;
    //cout<<s1.capacity()<<endl;
    //string s2;
    //s2.resize(11);
    //cout<<s2;
    //cout<<s2.size()<<endl;
    //cout<<s2.capacity()<<endl;
    //s2.reserve(15);
    //cout<<s2.size()<<endl;
    //cout<<s2.capacity()<<endl;
    //s2.reserve(32);
    //cout<<s2.size()<<endl;
    //cout<<s2.capacity()<<endl;
    //s2.reserve(10);

    //cout<<s2.size()<<endl;
    //cout<<s2.capacity()<<endl;
    //s2.reserve(1);
    //cout<<s2.size()<<endl;
    //cout<<s2.capacity()<<endl;
    // s1.reserve(20);
    // cout<<s1.capacity()<<endl;
    // s1.reserve(30);
    // cout<<s1.capacity()<<endl;
    // 
    // s1.reserve(50);
    // cout<<s1.capacity()<<endl;;
}
void test_reserve()
{
    int i=0;
    string s1;
    int oldsize=s1.capacity();
    for(;i<100;i++)

    {
        s1.push_back('c');
        if(oldsize!=s1.capacity())
        {
            cout<<s1.capacity()<<endl;
            oldsize=s1.capacity();
        }
    }
}
//测试clear empty
void test_clear_empty()
{
    string s1="hello world";
    cout<<s1.size()<<endl;
    cout<<s1.capacity()<<endl;
    if(s1.empty())
    {
        cout<<"空"<<endl;
    }
    else
    {
        cout<<"非空"<<endl;
    }
    s1.clear();

    cout<<s1.size()<<endl;
    cout<<s1.capacity()<<endl;
    if(s1.empty())
    {
        cout<<"空"<<endl;
    }
    else
    {
        cout<<"非空"<<endl;
    }
}
// 测试[] and at
void test_at()
{
    int i=0;
    string s("hello Linux");
   for(;i<s.size();i++)
   {
      cout<<s[i]<<"  ";

   }
   cout<<endl;
   i=0;
   for(;i<s.size();i++)
   {
       cout<<s.at(i)<<"  ";

   }
   cout<<endl;
}
void test_typdeerr()
{
    string str("hello Linux");
    cout<<str[20]<<endl;
    cout<<str.size()<<endl;
    cout<<str.capacity()<<endl;
}
//测试+=
void test_modify()
{
   //第一种 string& operator+= ( const string& str  );
   string s1="hello ";
   string s2="world";
   s1+=s2;
   cout<<s1<<endl;
   //第二中 string& operator+= ( const char* s  );
   string s3="hello";
   s3+=" world";
   cout<<s3<<endl;
   //第三种 string& operator+= ( char c  );
   string s4="hell";
   s4+='o';
   cout<<s4<<endl;
}
void test_append()
{
   //第一种 string& append ( const string& str  );
   string s1("hello");
   string s2(" world");
   s1.append(s2);

   cout<<s1<<endl;
   //第二种string& append ( const string& str, size_t pos, size_t n  );
   string s3;
   s3.append(s2,1,5);
   cout<<s3<<endl;
  //第三种 string& append ( const char* s, size_t n  );
   const char*str="precious";
   string s5;
   s5.append(str,5);
   cout<<s5<<endl;
   //第四种string& append ( const char* s  );
   string s6("hello");
   s6.append(" world");
   cout<<s6<<endl;
   //第五种 string& append ( size_t n, char c  );
   string s7;
   s7.append(10,'c');
   cout<<s7<<endl;
   //第六种，迭代器方式
   string s8("hello Linux");
   string s9;
   s9.append(s8.begin(),s8.begin()+5);
   cout<<s9<<endl;
}
void test_erase()
{
    //第一种 string& erase ( size_t pos = 0, size_t n = npos  );
    string s1("hello Linux");
    s1.erase(0,5);
    cout<<s1<<endl;
    //第二种 iterator erase ( iterator position  );
    string s2("hello Linix");
    string::iterator it=s2.begin();
    while(it!=s2.end())
    {
        it=s2.erase(s2.begin());
    }
    cout<<s2<<endl;
    cout<<s2.size()<<endl;
    cout<<s2.capacity()<<endl;
    //第三种： iterator erase ( iterator first, iterator last  );
    string s3("hello Linux");
    string::iterator rit=s3.erase(s3.begin(),s3.begin()+5);
    while(rit!=s3.end())
    {
        cout<<*rit;
        rit++;
    }
    cout<<endl;
}
void test_swap()
{
   // void swap ( string& str  );
    string s1("hello");
    string s2("Linux");
    cout<<"before swap"<<endl;
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    swap(s1,s2);
    cout<<"after swap"<<endl;
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;

}
void test_c_str()
{
    //const char* c_str (  ) const;
    string s1("hello Linux");
    const char*s2=s1.c_str();
    cout<<s2<<endl;
}
void test_data()
{
    //const char* data() const;返回指向与字符串相同内容的字符数组的指针。
    string s1("hello Linux");
    char*str=new char[s1.size()+1];
    strcpy(str,s1.data());
   cout<<str<<endl; 
    
}
void test_find()
{
   //1. size_t find ( const string& str, size_t pos = 0  ) const;
   string s1("hello world");
   string s2("world");
   int len1=s1.find(s2);
   cout<<len1<<endl;
   //size_t find ( const char* s, size_t pos, size_t n  ) const;从当前char*的第pos开始，向后n个字符，作为匹配原则
   //字符串中第一个字符的位置，以考虑可能的匹配。值为0表示考虑整个字符串
   int len2=s1.find("world",4,3);
   cout<<len2<<endl;
   // size_t find ( const char* s, size_t pos = 0  ) const;
   int len3=s1.find("world");
   cout<<len3<<endl;
   //size_t find ( char c, size_t pos = 0  ) const;
   int len4=s1.find('w');
   cout<<len4<<endl;

}
void test_substr()
{
    //string substr ( size_t pos = 0, size_t n = npos  ) const;
    string s1("1.txt");
    string s2=s1.substr(s1.find('.')+1);
    cout<<s2<<endl;
    //获取文件名字
    string s3("G:\\day8\\String\\myString.cpp");
    size_t pos1=s3.rfind('\\')+1;
    size_t pos2=s3.rfind('.')-1;
    string s4=s3.substr(pos1,pos2-pos1+1);
    cout<<"文件名:"<<s4<<endl;
}
int main()
{
    // test_constructor();
    // test_fuzhi();
    // test_Iterator();
    // test_size();
    // cout<<sizeof(string)<<endl;
    // test_reserve();
   // test_clear_empty();
   // test_at();
// test_typdeerr();
  // test_modify();
 // test_append();
 // test_erase();
 
   // test_swap();
// test_c_str();
  //test_data();
 // test_find();
 test_substr();
    return 0;
}
