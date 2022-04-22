#include <bits/stdc++.h>
using namespace std;

// create an stack s that should:
//   * add elements on top;
//   * remove elements of top;
//   * answer the value of some function f(s1,s2,...,sn) in O(1)

// f(x, y) could be a not reversible binary operation
// since it's easy to do that stack problem with a reversible binary operation, like addition

stack < pair< int, int > > s;//(element, f until element)

int f(int x, int y){
    return min(x, y);
}

void add(int x){
    if(s.empty()) s.push(make_pair(x, x));
    else s.push(make_pair(x, f(x, s.top().second)));
}

void remove(){
    s.pop();
}

int calc(){//return f(x) of all elements inside stack
    return s.top().second;
}