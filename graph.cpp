#include <iostream>
#include <vector>

struct Vertex;

struct Edge
{
    double value;
    Vertex *begin;
    Vertex *end;

    Edge(Vertex *begin, Vertex *end, double value) : begin(begin), end(end), value(value) {}

    void print();
};

struct Vertex
{
    int indice;
    std::vector<Edge *> v;

    Vertex(int i) : indice(i)
    {
        std::vector<Edge *> v;
    }

    void addEdge(Vertex *e, double b)
    {
        Edge *pa;
        pa = new Edge(this, e, b);
        v.push_back(pa);
    }

    void print()
    {
        std::cout<<indice<<":";
        
    }
};

inline void Edge::print()
{
    std::cout << end->indice, value;
}

struct Graph
{
    std::vector<Vertex *> v;

    void addEdge(int i, int j, double b)
    {
        for (int a = v.size(); ((a <= i) or (a <= j)); a++)
        {
            addVertex(a);
            Vertex *pj = &v[j];
            v[i]->addEdge(pj, b);
        }
    }

    void addVertex(int i)
    {
        Vertex *pv = new Vertex(i);
        v.push_back(pv);
    }
};