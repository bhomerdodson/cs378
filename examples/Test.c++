// ----------------------------
// projects/graph/TestGraph.c++
// Copyright (C) 2012
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp" // adjacency_list

// ----
// main
// ----

int main () {
    using namespace std;
    using namespace boost;
    cout << boolalpha;

    typedef adjacency_list<setS, vecS, directedS> graph_type;

    typedef graph_type::vertex_descriptor         vertex_descriptor;
    typedef graph_type::edge_descriptor           edge_descriptor;

    typedef graph_type::vertex_iterator           vertex_iterator;
    typedef graph_type::edge_iterator             edge_iterator;
    typedef graph_type::adjacency_iterator        adjacency_iterator;

    typedef graph_type::vertices_size_type        vertices_size_type;
    typedef graph_type::edges_size_type           edges_size_type;

    graph_type        g;
    vertex_descriptor v;
    edge_descriptor   e;
    bool              b;

    v = add_vertex(g);
    assert(v == 0);
    v = add_vertex(g);
    assert(v == 1);
    v = add_vertex(g);
    assert(v == 2);

    tie(e, b) = add_edge(0, 1, g);
    cout << e << endl;
    cout << b << endl;

    cout << "Done." << endl;
    return 0;}
