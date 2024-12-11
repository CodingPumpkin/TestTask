#include "solver.h"

Solver::Solver(Graph g)
{
    clear();
    graph = g;
    calculate_cost_matrix();}

void Solver::clear()
{
    cost = 0.0;
    order = 0;
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        visited[i] = -1;
    }
}

void Solver::calculate_cost_matrix()
{
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        for(int connection : graph.vertices[i].connections)
        {
           cost_matrix[i][connection] = utils::distance(graph.vertices[i],
                                                        graph.vertices[connection]);
        }
    }
}

float Solver::get_cost()
{
    return cost;
}

void Solver::solve(int start)
{
    start_node = start;

    cost = tsp(start_node);

    printf("%f\n", cost);
}

float Solver::tsp(int pos)
{
    visited[pos] = order;
    order++;
    if (order == 100) {
        return cost_matrix[pos][start_node];
    }
//    float res = MY_MAX_FLOAT;
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        if ((visited[i] < 0) && (cost_matrix[i][pos] > 0))
        {
            res = std::min(res, cost_matrix[pos][i] + tsp(i));
        }
    }
    return res;
}

void Solver::print_visited()
{
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
        printf("%d\t", visited[i]);
    printf("\n");
}
