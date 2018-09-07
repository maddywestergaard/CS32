#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Sequence s;
    assert(s.insert(0, 10));
    assert(s.insert(0, 20));
    assert(s.size() == 2);
    ItemType x = 999;
    assert(s.get(0, x)  &&  x == 20);
    assert(s.get(1, x)  &&  x == 10);
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}
//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Sequence s;
//    assert(s.insert(0, 10));
//    assert(s.insert(0, 20));
//    assert(s.insert(1, 30));
//    assert(!s.insert(5, 60));
//    assert(s.size() == 3);
//
//    ItemType x = 999;
//    assert(s.get(0, x)  &&  x == 20);
//    assert(s.get(1, x)  &&  x == 30);
//    assert(s.get(2, x)  &&  x == 10);
//
//    assert (s.erase(1));
//    assert (s.size() ==2);
//    assert(s.get(0, x)  &&  x == 20);
//    assert(s.get(1, x)  &&  x == 10);
//    assert(!s.get(2, x));
//
//    assert (s.insert(2, 40));
//    assert (s.erase(0));
//    assert (s.get(0,x) && x ==10);
//    assert (s.get(1,x) && x ==40);
//
//    assert (s.erase(1));
//    assert (s.get(0,x) && x ==10);
//    assert (s.size()==1);
//
//    assert (s.erase(0));
//    assert (s.empty());
//
//    assert(s.insert(0, 10));
//    assert(s.insert(0, 20));
//    assert(s.insert(1, 30));
//    assert (s.insert(25) == 1);
//    assert (s.insert(5) == 0);
//    assert (s.insert(5) == 0);
//    assert(s.get(0, x)  &&  x == 5);
//    assert(s.get(1, x)  &&  x == 5);
//    assert(s.get(2, x)  &&  x == 20);
//    assert(s.get(3, x)  &&  x == 25);
//    assert(s.get(4, x)  &&  x == 30);
//    assert(s.get(5, x)  &&  x == 10);
//
//    assert (s.remove(5) == 2);
//    assert (s.remove(100)==0);
//    assert(s.get(0, x)  &&  x == 20);
//    assert(s.get(1, x)  &&  x == 25);
//    assert(s.get(2, x)  &&  x == 30);
//    assert(s.get(3, x)  &&  x == 10);
//
//    assert (s.set(0, 50));
//    assert (s.set(3, 40));
//    assert (!s.set(5, 50));
//    assert(s.get(0, x)  &&  x == 50);
//    assert(s.get(1, x)  &&  x == 25);
//    assert(s.get(2, x)  &&  x == 30);
//    assert(s.get(3, x)  &&  x == 40);
//
//    assert (s.find(50) ==0);
//    assert (s.find(25) == 1);
//    assert (s.find(30) == 2);
//    assert (s.find(40)==3);
//    assert (s.find(70) ==-1);
//
//    Sequence s1;
//    assert(s1.insert(0, 10));
//    assert(s1.insert(1, 20));
//    assert(s1.insert(2, 30));
//
//    s.swap(s1);
//
//    assert(s.get(0, x) && x == 10);
//    assert(s.get(1, x) && x == 20);
//    assert(s.get(2, x) && x == 30);
//
//    assert(s1.get(0, x) && x == 50);
//    assert(s1.get(1, x) && x == 25);
//    assert(s1.get(2, x) && x == 30);
//    assert(s1.get(3, x) && x == 40);
//
//    Sequence s2;
//
//    Sequence s5;
//    assert(s5.insert(0, 10));
//    assert(s5.insert(0, 20));
//    assert(s5.insert(0, 30));
//
//    Sequence s6;
//    assert(s6.insert(0, 50));
//    assert(s6.insert(0, 25));
//    assert(s6.insert(0, 30));
//    assert(s6.insert(0, 40));
//
//    interleave(s5, s6, s2);
//
//    assert(s2.get(0, x) && x == 30);
//    assert(s2.get(1, x) && x == 40);
//    assert(s2.get(2, x) && x == 20);
//    assert(s2.get(3, x) && x == 30);
//    assert(s2.get(4, x) && x == 10);
//    assert(s2.get(5, x) && x == 25);
//    assert(s2.get(6, x) && x == 50);
//
//    interleave(s6,s5,s2);
//
//    assert(s2.get(0, x) && x == 40);
//    assert(s2.get(1, x) && x == 30);
//    assert(s2.get(2, x) && x == 30);
//    assert(s2.get(3, x) && x == 20);
//    assert(s2.get(4, x) && x == 25);
//    assert(s2.get(5, x) && x == 10);
//    assert(s2.get(6, x) && x == 50);
//
//    Sequence s7;
//    assert(s7.insert(0, 50));
//    assert(s7.insert(0, 25));
//    assert(s7.insert(0, 30));
//    assert(s7.insert(0, 40));
//
//    interleave(s7, s6, s2);
//
//    assert(s2.get(0, x) && x == 40);
//    assert(s2.get(1, x) && x == 40);
//    assert(s2.get(2, x) && x == 30);
//    assert(s2.get(3, x) && x == 30);
//    assert(s2.get(4, x) && x == 25);
//    assert(s2.get(5, x) && x == 25);
//    assert(s2.get(6, x) && x == 50);
//    assert(s2.get(7, x) && x == 50);
//
//    Sequence s8;
//    assert(s8.insert(0, 30));
//    assert(s8.insert(1, 25));
//    assert(s8.insert(2, 50));
//
//    assert (subsequence(s7, s8) == 1);
//
//    Sequence s9;
//    assert(s9.insert(0, 30));
//    assert(s9.insert(1, 75));
//    assert(s9.insert(2, 6));
//    assert(s9.insert(3, 30));
//    assert(s9.insert(4, 25));
//    assert(s9.insert(5, 50));
//
//    assert (subsequence(s9, s8) == 3);
//
//    Sequence s10;
//    assert (subsequence(s9, s10)==-1);
//
//    s9 = s8;
//
//    assert(s9.get(0, x) && x == 30);
//    assert(s9.get(1, x) && x == 25);
//    assert(s9.get(2, x) && x == 50);
//
//    Sequence s11(s8);
//    assert(s11.get(0, x) && x == 30);
//    assert(s11.get(1, x) && x == 25);
//    assert(s11.get(2, x) && x == 50);
//
//    Sequence s13;
//    assert (s13.insert(0, 20));
//    assert (s13.erase(0));
//    assert (s13.empty());
//}
//
//int main()
//{
//    test();
//    cerr << "Passed all tests" << endl;
//}

