#include<iostream>
#include<vector>

struct Node
{
    char name;
    Node* next;
    Node(char name,Node* n){
        this->name=name;
        this->next=n;
    }
};


struct Graph
{
    Node* from;
    Node* to;
    double weight;
    Graph(Node* from,Node* to,double w){
        this->from=from;
        this->to=to;
        this->weight=w;
    }
};


int main(){
    std::vector<Node*> myNode;
    for(char i='a';i<'g';++i){
        if(i=='a') myNode.push_back(new Node(i,nullptr));
        else myNode.push_back(new Node(i,myNode[i-'b']));
    }
    std::vector<Graph*> myGraph(8);
    myGraph[0]=new Graph(myNode['a'-'a'],myNode['b'-'a'],10);
    myGraph[1]=new Graph(myNode['a'-'a'],myNode['d'-'a'],11);
    myGraph[2]=new Graph(myNode['a'-'a'],myNode['c'-'a'],12);
    myGraph[3]=new Graph(myNode['b'-'a'],myNode['c'-'a'],13);
    myGraph[4]=new Graph(myNode['b'-'a'],myNode['e'-'a'],14);
    myGraph[5]=new Graph(myNode['c'-'a'],myNode['f'-'a'],15);
    myGraph[6]=new Graph(myNode['d'-'a'],myNode['f'-'a'],16);
    myGraph[7]=new Graph(myNode['e'-'a'],myNode['f'-'a'],17);
    for(const auto& i:myGraph){
        std::cout<<i->from->name<<' '<<i->to->name<<' '<<i->weight<<std::endl;
    }
}