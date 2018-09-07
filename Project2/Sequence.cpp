//
//  Sequence.cpp
//  Project2
//
//  Created by Maddy Westergaard on 4/20/18.
//  Copyright © 2018 Maddy Westergaard. All rights reserved.
//

#include "Sequence.h"

//sets an empty sequence
Sequence::Sequence()
{
    head = nullptr;
    num = 0;
}

bool Sequence::empty() const
{
    if (head == nullptr)
        return true;
    
    return false;
}

int Sequence::size() const
{
    return num;
}

bool Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0 || pos > num)
        return false;
    
    //sets the n and value for the newly inserted element
    Node *newNode = new Node;
    newNode->n = pos;
    newNode->value = value;
    
    //increments the total num for the sequence
    num++;
    
    // if sequence is empty, it sets the new node as the head and the last element
    if (empty())
    {
        newNode->next = nullptr;
        newNode->previous = nullptr;
        head = newNode;
        newNode->n = 0;
    }
    else
    {
        //adds to beginning of sequence
        if (pos==0)
        {
            newNode->next = head;
            head->previous = newNode;
            newNode->previous = nullptr;
            newNode->n = 0;
            head = newNode;
            Node *d = head;
            
            //increments all following n values for the elements after the inserted one
            for (int i = 1; i < num; i++)
            {
                d->next->n = i;
                d=d->next;
            }
        }
        else
        {
            Node *p = head;
            
            //for inserting at the end of the sequence, sets next to null
            if (pos == (num-1))
            {
                while (p->next != nullptr)
                {
                    p = p->next;
                }
                p->next = newNode;
                newNode->next = nullptr;
                newNode->previous = p;
                newNode->n = (num-1);
            }
            else
            {
                // for inserting any of the middle elements
                while (p->next != nullptr && p->n < pos)
                {
                    p = p->next;
                }
                newNode->next = p;
                newNode->previous = p->previous;
                newNode->n = p->n;
                
                p->previous->next = newNode;

                p->previous = newNode;
                
                while (p!= nullptr)
                {
                    p->n = p->n + 1;
                    p = p->next;
                }
            }
        }
    }
    return true;
}

int Sequence::insert(const ItemType& value)
{
    Node *newNode = new Node;
    newNode->value = value;
    int result = 0;
    
    //inserts in empty sequence
    if (empty())
    {
        head = newNode;
        newNode->n = 0;
    }
    else
    {
        Node *p = head;
        
        //finds the position to insert the element
        while (p->next !=nullptr)
        {
            if (value <= p->value)
                break;
            p = p->next;
        }
        result = p->n;
        insert (p->n, value);
    }
    return (result);
}

bool Sequence::erase(int pos)
{
    Node *p = head;
    if (pos<0 || pos>=num || empty())
        return false;
    
    if (pos == 0)
    {
        if (num==1)
        {
            //empties the sequence if only one element
            delete p;
            head = nullptr;
        }
        else
        {
            //erases first element
            head->next->previous = nullptr;
            head = head->next;
            Node *d = p;
            
            while (d != nullptr)
            {
                d->n = d->n - 1;
                d = d->next;
            }
            delete p;
        }
    }
    else if (pos == (size()-1))
    {
        //erases last element
        while (p->next!= nullptr)
        {
            p = p->next;
        }
        p->previous->next = nullptr;
        delete p;
    }
    else
    {
        //erases any middle element
        while (p!=nullptr)
        {
            if  (p->n == pos)
                break;
            p = p->next;
        }
        
        Node *d = p;
        d = d->next;
        while (d != nullptr)
        {
            d->n = d->n - 1;
            d = d->next;
        }
        
        p->next->previous = p->previous;
        p->previous->next = p->next;
        
        delete p;
    }
    
    //decrements num
    num--;
    return true;
}

int Sequence::remove(const ItemType& value)
{
    Node *p = head;
    int amount = 0;

    // finds the value to erase, then calls erase function
    while (p->next !=nullptr)
    {
        if (value == p->value)
        {
            int position = p->n;
            p = p->next;
            erase(position);
            // keeps track of how many elements were removed
            amount++;
        }
        else
        p = p->next;
    }
    return amount;
}

bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0 || pos >= num)
        return false;
    
    // finds the position of the element
    Node *p = head;
    while (p!= nullptr)
    {
        if (p->n == pos)
            break;
        p = p->next;
    }
    
    //sets the value
    if (p!= nullptr)
    {
        value = p->value;
        return true;
    }
    else
        return false;
}

bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0 || pos >= num)
        return false;
    
    // finds the position of the element
    Node *p = head;
    while (p!= nullptr)
    {
        if (p->n == pos)
            break;
        p = p->next;
    }
    
    //sets the value in the sequence
    if (p!= nullptr)
    {
        p->value = value;
        return true;
    }
    else
        return false;
}

int Sequence::find(const ItemType& value) const
{
    // traverses through sequence to find element that matches the value
    Node *p = head;
    while (p!= nullptr)
    {
        if (p->value == value)
            break;
        p = p->next;
    }
    
    //returns the position
    if (p!= nullptr)
    {
        return p->n;
    }
    else
        return (-1);
}

void Sequence::swap(Sequence& other)
{
    // swaps the num and the head variables of the sequences using temp variables
    int tempnum = num;
    num = other.num;
    other.num = tempnum;
    
    Node *p = head;
    head = other.head;
    other.head = p;
}

//destructor
Sequence::~Sequence()
{
    // deletes every element of the linked list
    if (head!=nullptr)
    {
        Node *p = head;
        
        while (p != nullptr)
        {
            Node* w = p;
            p = p->next;
            delete w;
        }
    }
}

// copy constructor
Sequence::Sequence (const Sequence& other)
{
    Node *o = other.head;
    this->head = new Node;
    num = 0;
    
    if (o == nullptr)
        head = nullptr;
    else
    {
        // copies every element of other into current sequence
        while (o!=nullptr)
        {
            int index = o->n;
            ItemType val = o->value;
            this->insert(index, val);
            o = o->next;
        }
    }
    
    this->num = other.num;
}

//assignment operator
Sequence& Sequence::operator=(const Sequence& rhs)
{
    if (this != &rhs)
    {
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}

int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    ItemType val;
    ItemType val2;
    
    //traverses through seq1
    for (int i=0; i < seq1.size(); i++)
    {
        seq1.get(i, val);
        seq2.get(0, val2);
        
        //checks if the values are equal
        if (val == val2)
        {
            int j = i;
            int count = 0;
            
            //finds the longest sequence where the respective consecutive values are equal, within the scope of seq1
            while (val == val2 && j < seq1.size())
            {
                //keeps track of amount of values
                count++;
                j++;
                //goes to next value in each list
                seq1.get(j, val);
                seq2.get(count, val2);
            }
            // if the sequence is 3 values or longer, than it is valid and returns the inition position;
            if (count>=3)
                return i;
        }
    }
    
    return (-1);
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    ItemType val, val2;
    int j=0;
    
    // for if seq1 is bigger than seq2
    if (seq1.size() >= seq2.size())
    {
        for (int i=0; i < seq2.size(); i++)
        {
            // gets the two values in the current position in both lists
            seq2.get(i, val2);
            seq1.get(i, val);
            
            // inserts seq1 value first, than seq2 value after that one
            result.insert(j, val);
            result.insert((j+1), val2);
            
            // increment j by 2 to keep track of the position of the result array
            j+=2;
        }
        // adds the remaining values of seq1 to the end of result
        for (int i = seq2.size(); i < seq1.size(); i++)
        {
            seq1.get(i,val);
            result.insert(j, val);
            j++;
        }
    }
    // if seq2 is bigger than seq1
    else
    {
        for (int i=0; i < seq1.size(); i++)
        {
            //gets both values for i position
            seq2.get(i, val2);
            seq1.get(i, val);
            // inserts seq1 value then seq2 value in the position after
            result.insert(j, val);
            result.insert((j+1), val2);
            // keeps track of the position of the result list
            j+=2;
        }
        //adds the remaining values of seq2 to the end of result
        for (int i = seq1.size(); i < seq2.size(); i++)
        {
            seq2.get(i,val);
            result.insert(j, val);
            j++;
        }
    }
}















