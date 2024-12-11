#ifndef GRAPH_H
#define GRAPH_H

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <iostream>

#include "constants.h"
#include "utils.h"

class Graph
{
public:
    Graph();
    std::vector<utils::Vertex> vertices;

private:
    bool is_connected(int , int);
    bool is_possible_to_connect(int, utils::Vertex);
    void connect_verticies();
    void generate_verticies();
};

#endif // GRAPH_H
