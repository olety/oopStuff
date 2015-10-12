//
//  main.cpp
//  Primes
//
//  Created by Oleksii Kyrylchuk on 10/12/15.
//  Copyright © 2015 olety. All rights reserved.
//

#include <iostream>

struct Element{
    int val;
    Element *next, *prev;
};

class List2W{
public: Element *head, *tail;
};

void init(List2W& l){
    List2W *temp = new List2W;
    temp->head = NULL;
    temp->tail = NULL;
    l = *temp;
}
bool isEmpty (List2W& l){
    return (l.head == NULL && l.tail == NULL);
}

void insertHead(List2W& l, int x){
    Element *newHead = new Element;
    newHead->val = x;
    if ( isEmpty(l) ){
        l.tail = newHead;
    } else {
        l.head->prev = newHead;
    }
    //cycled
    newHead->prev = l.tail;
    newHead->next = l.head;
    l.head = newHead;
}

bool deleteHead(List2W& l, int &oldHead){
    if ( isEmpty(l) ){
        return false;
    }
    
    Element *temp = l.head;
    oldHead = temp->val;
    
    if ( l.head == l.tail )
    {
        l.head = NULL;
        l.tail = NULL;
    } else {
        temp->next->prev = l.tail;
        l.head = temp->next;
    }
    
    delete temp;
    
    return true;
}

void insertTail(List2W& l, int x){
    if ( isEmpty(l) ){
        insertHead( l, x );
        return;
    }
    
    Element *temp = new Element;
    temp->val = x;
    temp->next = NULL;
    temp->prev = l.tail;
    l.tail->next = temp;
    l.tail = temp;
}

bool deleteTail(List2W& l, int &oldTail){
    if ( l.head == l.tail ){
        return deleteHead(l, oldTail);
    }
    
    Element *temp = l.tail;
    oldTail = temp->val;
    temp->prev->next = NULL;
    l.tail = temp->prev;
    
    delete temp;
    
    return true;
}

int findValue(List2W& l, int value){
    if ( isEmpty(l) ){
        return -1;
    }
    
    Element *temp = l.head;
    int i = 0;
    
    while ( temp!= NULL) {
        if ( temp->val == value ){
            return i;
        }
        temp = temp->next;
        i++;
    }
    
    return -1;
}


void removeAllValue(List2W & l,int value){
    if ( isEmpty(l) ){
        return;
    }
    
    Element *temp = l.head, *del;
    int i;
    
    if ( l.head->val == value ){
        temp = temp->next;
        deleteHead(l, i);
    }
    
    while ( temp!= NULL) {
        if ( temp->val == value ){
            
            if ( l.tail == temp ) {
                temp = temp->next;
                deleteTail(l, i);
                return;
            }
            
            del = temp;
            temp = temp->next;
            del->next->prev = del->prev;
            del->prev->next = del->next;
            
            delete del;
            
        } else {
            temp = temp->next;
        }
    }
}

void showListFromHead(List2W& l){
    Element *temp = l.head;
    while ( temp!= NULL ) {
        std::cout << temp->val << ",";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void showListFromTail(List2W& l){
    Element *temp = l.tail;
    while ( temp!= NULL ) {
        std::cout << temp->val << ",";
        temp = temp->prev;
    }
    std::cout << std::endl;
}

void clearList(List2W& l){
    int i;
    while ( l.head != NULL ){
        deleteHead(l, i);
    }
}

void addList(List2W& l1, List2W& l2){
    if ( l1.head == l2.head ){
        return;
    }
    int i;
    while ( !isEmpty(l2) ){
        insertTail(l1, l2.head->val);
        deleteHead(l2, i);
    }
    
}

int main(int argc, const char * argv[]) {
    float upperLim;
    std::cout << "Promes up to : \n";
    std::cin >> upperLim;
    return 0;
}
