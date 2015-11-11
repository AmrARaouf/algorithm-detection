//Language: GNU C++


#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Vertex {
    set<Vertex*> amigos;
    unsigned color;
public:
    Vertex (unsigned color){
        this->color = color;
    }
    void setAmigo(Vertex* amigo){
        this->amigos.insert(amigo);
        amigo->amigos.insert(this);
    }
    set<unsigned>* getColors(){
        set<unsigned>* s = new set<unsigned>;
        s->insert(this->color);
        set<Vertex*>::iterator it, iend=this->amigos.end();
        for (it=amigos.begin(); it!=iend;++it){
            s->insert((*it)->color);
        }
        return s;
    }
    unsigned getColor() {return this->color;}
};

typedef vector<Vertex*> Vertices;
typedef map<unsigned, set<unsigned>* > Cardinality;
typedef set<unsigned>* Colors;

int main()
{
    Vertices v;    // vertex
    Cardinality q; // map
    unsigned input, input2, i=0, verticles;

    while(cin >> input){
        if (i==0)
            verticles = input;
        if (i>1 && i<=verticles+1 )
            v.push_back(new Vertex(input)); // colors
        if (i>verticles+1){
            cin >> input2;
            v.at(input-1)->setAmigo(v.at(input2-1));
        }
        i++;
    }

    Vertices::iterator it, ibegin=v.begin(), iend=v.end();
    for (it=ibegin; it!=iend; ++it){
        Colors colors = (*it)->getColors();
        try{
            q.at((*it)->getColor())->insert(colors->begin(), colors->end());
        }catch (...){
            q[(*it)->getColor()] = colors;
        }
    }

    Cardinality::iterator qit, qit_max;
    qit_max = q.begin();

    for (qit=q.begin(); qit!=q.end(); ++qit){
        if ( qit->second->size() > qit_max->second->size() ) { // ->second: set of neighbour colors
            qit_max = qit;
        }
        if ( qit->second->size() == qit_max->second->size() ){
            if ( qit_max->first > qit->first ){ // ->first: dictionary key with color number
                qit_max = qit; // pick color with lower number
            }
        }
    }
    cout << qit_max->first << endl;
    return 0;
}

