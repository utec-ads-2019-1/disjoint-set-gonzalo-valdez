#include <iostream>
#include "node.h"
#include <map>
using namespace std;

map<int, Node*> mapa;
map<int, Node*>::iterator it;

Node* find(int search){
    for(it = mapa.begin();it != mapa.end(); it++){
        if (it->second->data == search) {
            Node* nodo = it->second;
            while(nodo->parent!=nodo){
                nodo = nodo->parent;
            }
            it->second->parent = nodo;
            return nodo;
        }
    }
    return nullptr;
}

bool merge(int a, int b,string mode){
    Node* A = find(a);
    Node* B = find(b);
    if(A and B){
        if(mode=="Arbitrario"){
            B->parent=A;
            if(B->children!=0) {A->children+=B->children;}
            A->children++;
        } else if(mode=="Rank"){
            if(A->rank > B->rank){
                B->parent=A;
                if(B->children!=0) {A->children+=B->children;}
                A->children++;
            } else if(A->rank < B->rank){
                A->parent=B;
                if(A->children!=0) {B->children+=A->children;}
                B->children++;
            } else {
                A->rank++;
                B->parent=A;
                if(B->children!=0) {A->children+=B->children;}
                A->children++;
            }
        } else if(mode=="Size"){
            if(A->children > B->children){
                B->parent=A;
                if(B->children!=0) {A->children+=B->children;}
                A->children++;
            } else if(A->children < B->children){
                A->parent=B;
                if(A->children!=0) {B->children+=A->children;}
                B->children++;
            } else {
                A->rank++;
                B->parent=A;
                if(B->children!=0) {A->children+=B->children;}
                A->children++;
            }
        }
    }
}

Node* newNode(int data){
    Node* n = new Node(data);
    mapa.insert({data,n});
    return n;
}

int main() {

    for(int i=0;i<3;i++){
        mapa.clear();

        for(int j=1;j<17;j++){
            newNode(j);
        }
        string mode;
        switch(i){
            case 0 : mode = "Arbitrario";break;
            case 1 : mode = "Rank";break;
            case 2 : mode = "Size";break;
            default: break;
        }

        merge(1,2,mode);merge(3,4,mode);merge(3,5,mode);merge(1,7,mode);merge(3,6,mode);merge(8,9,mode);
        merge(1,8,mode);merge(3,10,mode);merge(3,11,mode);merge(3,12,mode);merge(3,13,mode);merge(14,15,mode);
        merge(16,1,mode);merge(14,16,mode);merge(1,3,mode);merge(1,14,mode);
        cout<<" -------------- MODO: "<<mode<<endl;
        for(it = mapa.begin(); it!=mapa.end();it++){
            cout<<"El nodo "<<it->first<<" pertenece a "<<find(it->second->data)->data<<endl;
        }
    }
}

