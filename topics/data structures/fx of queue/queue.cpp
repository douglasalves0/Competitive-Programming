#include <bits/stdc++.h>
using namespace std;

// create an queue q that should:
//   * add elements on back;
//   * remove elements of front;
//   * answer the value of some function f(q1,q2,...,qn) in average O(1)

// f(x, y) could be a not reversible binary operation
// and should be a comutative associative binary operation
// since it's easy to do that stack problem with a reversible binary operation, like addition

// we'll represent the queue as two stacks joined back to back

stack < pair<int,int> > s1;
stack < pair<int,int> > s2;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int f(int x, int y){
    return gcd(x, y);
}

void add(int x){
    if(s1.empty()) s1.push({x, x});
    else s1.push({x, f(s1.top().second, x)});
}

void remove(){
    if(s2.empty()){
        if(s1.empty()) return;
        while(1){
            if(s1.empty()) break;
            int top = s1.top().first;
            if(s2.empty()) s2.push({top, top});
            else s2.push({top, f(top, s2.top().second)});
            s1.pop();
        }
    }
    s2.pop();
}

int getFunctionValue(){//return f(x) of all elements inside queue
    int r1 = 0;//here, you should use the neutral element of your binary operation.
    int r2 = 0;
    if(!s1.empty()) r1 = s1.top().second;
    if(!s2.empty()) r2 = s2.top().second;
    return f(r1, r2);
}