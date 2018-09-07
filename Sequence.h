//
//  Sequence.h
//  Project2
//
//  Created by Maddy Westergaard on 4/20/18.
//  Copyright © 2018 Maddy Westergaard. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h

#include <stdio.h>
#include <string>

using ItemType = unsigned long;

class Sequence
{
public:
    Sequence();
    bool empty() const;
    int size() const;
    bool insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    ~Sequence();
    Sequence(const Sequence& other);
    Sequence& operator=(const Sequence& rhs);
private:
    //struct for the elements of the sequence
    struct Node
    {
        ItemType value;
        Node *next;
        Node *previous;
        int n;
    };
    Node *head;
    int num;
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */
