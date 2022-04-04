
// Stack - Array based implementation

#include <bits/stdc++.h>
#define max_size 101

using namespace std;

int a[max_size];
int top = -1;

void Push(int x){
    if (top == max_size - 1){
        cout << "Error: stack overflow" << endl;
        return;
    }
    a[++top] = x;
}

void Pop(){
    if (top == -1){
        cout << "Error: No element to Pop" << endl;
        return;
    }
    top--;
}

int Top(){
    return a[top];
}

void Print(){
    int i;
    cout << "Stack: ";
    for (i=0; i<=top; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){

    Push(2);Print();
    Push(3);Print();
    Push(4);Print();
    Pop();Print();
    Push(5);Print();

}
