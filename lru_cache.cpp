#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class Node
{
public:
    string key;
    int value;
    
    Node(string key, int value)
    {
        this->key=key;
        this->value=value;
    }
};

class LRUCache
{
private:
    int maxSize;
    unordered_map<string, list<Node>::iterator > m;
    list<Node> l;
    
public:
    LRUCache(int maxSize)
    {
        this->maxSize=maxSize>1 ? maxSize :1;
    }
    
    void insertKeyValue(string key, int value)
    {

        if(m.count(key)!=0)
        {
            auto c = m[key];
            c->value = value;
        }
        else
        {
            int current_size = l.size();
            
            if(current_size < maxSize)
            {
                Node n(key, value);
                l.push_front(n);
                m[key] = l.begin();
            }
            else
            {
                Node last = l.back();
                m.erase(last.key);
                l.pop_back();
            }   
        }
    }
    
    int* getValue(string key)
    {
        if(m.count(key)!=0)
        {
            auto it = m[key];
            
            int value = it->value;
            l.push_front(*it);
            l.erase(it);
            m[key] = l.begin();
            return &l.begin()->value;
        }
        return NULL;
        
    }
    
    string mostRecentKey()
    {
        return l.front().key;
    }
    
};


int main()
{
    LRUCache lru(3);
    
    lru.insertKeyValue("mango",10);
    lru.insertKeyValue("apple",20);
    lru.insertKeyValue("guava",30);
    
    cout<<lru.mostRecentKey()<<endl;
    
    lru.insertKeyValue("mango",40);
    cout<<lru.mostRecentKey()<<endl;
    
    int* orders = lru.getValue("mango");
    if(orders!=NULL)
    {
        cout<<"Order of Mango"<<*orders<<endl;
    }
    
    lru.insertKeyValue("banana",20);
    
    if(lru.getValue("apple")==NULL)
    {
        cout<<"apple does not exist"<<endl;
    }
    
    if(lru.getValue("guava")==NULL)
    {
        cout<<"guava does not exist"<<endl;
    }
        
    if(lru.getValue("banana")==NULL)
    {
        cout<<"banana does not exist"<<endl;
    }
    
    if(lru.getValue("mango")==NULL)
    {
        cout<<"mango does not exist"<<endl;
    }
       
    
    return 0;
}
