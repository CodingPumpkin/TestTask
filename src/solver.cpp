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
        for (int j = 0; j < NUMBER_OF_POINTS; j++)
            cost_matrix[i][j] = 0.0;
    }
}

void Solver::calculate_cost_matrix()
{
    float distance = 0.0;
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        for(int connection : graph.vertices[i].connections)
        {
           cost_matrix[i][connection] = utils::distance(graph.vertices[i],
                                                        graph.vertices[connection]);
        }
    }
}

void Solver::solve(int start)
{
    start_node = start;
    int mask = 1;
    cost = tsp(start_node);
    printf("%f\n", cost);
}

int Solver::tsp(int pos)
{
    if (order == 100) {
        return cost_matrix[pos][start_node];
    }
    order ++;
    visited[pos] = order;
    float res = MY_MAX_FLOAT;
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        if ((visited[i] < 0) && (cost_matrix[i][pos] > 0))
        {
            res = std::min(res, cost_matrix[pos][i] + tsp(i));
        }
    }
    return res;
}

void Solver::print_path()
{
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
        printf("%d\t", visited[i]);
    printf("\n");
}
