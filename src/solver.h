#ifndef SOLVER_H
#define SOLVER_H

#include "constants.h"
#include "graph.h"
#include "utils.h"

class Solver
{
public:
    Solver(Graph);
    void solve(int );
    double get_cost();
    void print_visited();
    void clear();

private:
    int start_node;
    int order;
    double cost;
    double cost_matrix[NUMBER_OF_POINTS][NUMBER_OF_POINTS];
    int visited[NUMBER_OF_POINTS];
    void calculate_cost_matrix();
    double tsp(int);
    Graph graph;

};

#endif
