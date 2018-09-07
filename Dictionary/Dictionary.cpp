// Dictionary.cpp

// This is a correct but horribly inefficient implementation of Dictionary
// functionality.  Your job is to change DictionaryImpl to a more efficient
// correct implementation.  You can change it any way you like, subject to
// restrictions in the spec (e.g., that the only C++ library container you
// are allowed to use are vector, list, stack, and queue (and string); if you
// want anything fancier, implement it yourself).

#include "Dictionary.h"
#include <string>
#include <list>
#include <cctype>
#include <stdlib.h>
#include <functional>
#include <algorithm>
#include <utility>  // for swap
using namespace std;

const int NUM = 49999;

void removeNonLetters(string& s);
void generateNextPermutation(string& permutation);

// This class does the real work of the implementation.

class DictionaryImpl
{
public:
    DictionaryImpl();
    ~DictionaryImpl();
    void insert(string word);
    void lookup(string letters, void callback(string)) const;
    bool isAnagram(string word1, string word2) const;
    static int cmpfunc( const void *a, const void *b);
private:
    struct BUCKET
    {
        list <string> m_words;
    };
    BUCKET* m_hash[NUM];
    unsigned int hashFunc(string word1) const;
};

DictionaryImpl::DictionaryImpl()
{
    for (int i = 0; i< NUM; i++)
    {
        m_hash[i] = nullptr;
    }
}

DictionaryImpl::~DictionaryImpl()
{
    for (int i = 0; i < NUM; i++)
    {
        delete m_hash[i];
    }
}

unsigned int DictionaryImpl::hashFunc(string word1) const
{
    hash<string> str_hash;
    unsigned long hashValue = str_hash(word1);
    
    unsigned int bucketNum = hashValue % NUM;
    return bucketNum;
}

void DictionaryImpl::insert(string word)
{
    removeNonLetters(word);
    string sortedWord = word;
    sort(sortedWord.begin(), sortedWord.end());
    int sortedBucketNum = hashFunc(sortedWord);
    
    if (m_hash[sortedBucketNum] == nullptr)
    {
        m_hash[sortedBucketNum] = new BUCKET;
        m_hash[sortedBucketNum]->m_words.push_front(word);
    }
    else
    {
        m_hash[sortedBucketNum]->m_words.push_back(word);
        m_hash[sortedBucketNum]->m_words.sort();
    }
}

bool DictionaryImpl::isAnagram(string word1, string word2) const
{
    size_t l1 = word1.length();
    size_t l2 = word2.length();
    
    if (l1 != l2)
        return false;
    
    string word1sort = word1;
    string word2sort = word2;
    
    sort(word1sort.begin(), word1sort.end());
    sort(word2sort.begin(), word2sort.end());
    
    if (word1sort == word2sort)
        return true;
    
    return false;
}

void DictionaryImpl::lookup(string letters, void callback(string)) const
{
    removeNonLetters(letters);
    if (callback != nullptr && !letters.empty())
    {
        string sortedWord = letters;
        sort(sortedWord.begin(), sortedWord.end());
        int sortedBucketNum = hashFunc(sortedWord);
        
        if (m_hash[sortedBucketNum] != nullptr)
        {
            for (list<string>::iterator it = m_hash[sortedBucketNum]->m_words.begin(); it!=m_hash[sortedBucketNum]->m_words.end(); it++)
            {
                if (isAnagram(*it, letters))
                    callback(*it);
            }
        }
    }
}

void removeNonLetters(string& s)
{
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++)
    {
        if (isalpha(*from))
        {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop everything off from "to" to end.
}

//******************** Dictionary functions ********************************

// These functions simply delegate to DictionaryImpl's functions.
// You probably don't want to change any of this code

Dictionary::Dictionary()
{
    m_impl = new DictionaryImpl;
}

Dictionary::~Dictionary()
{
    delete m_impl;
}

void Dictionary::insert(string word)
{
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const
{
    m_impl->lookup(letters,callback);
}
