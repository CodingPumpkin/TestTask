#include "graph.h"

Graph::Graph()
{
    generate_verticies();
}

void Graph::generate_verticies()
{
    std::srand(std::time(nullptr));
    int x = 0, y = 0;
    int i = 0;
    while(i < NUMBER_OF_POINTS)
    {
        x = std::rand() % FIELD_W;
        y = std::rand() % FIELD_H;
        if ((x-R)*(x-R) + (y-R)*(y-R) < R*R) //checks ith point is in circle
            {
                vertices.push_back(utils::Vertex(x, y));
                i++;
            }
    }
    connect_verticies();
}

void Graph::connect_verticies()
{
    std::srand(std::time(nullptr));
    int num_of_connections = 0;
    int i = 0;
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        if (vertices[i].connections.size() < 6)
        {
            num_of_connections = MIN_NUM_CONNECTIONS +
                                 std::rand() % (MAX_NUM_CONNECTIONS - MIN_NUM_CONNECTIONS);
            int cs = 0;
            while (cs < num_of_connections)
            {
                //find closest point
                int potential_connection = -1;
                double min_distance = 999999999.0;
                for (int j = 0; j < NUMBER_OF_POINTS; j++)
                {
                    if ( (i !=j ) && !is_connected(i, j))
                    {
                        double d = utils::distance(vertices[i], vertices[j]);
                        if (d < min_distance)
                        {
                            min_distance = d;
                            potential_connection = j;
                        }
                    }
                }
                if (potential_connection >= 0)
                {
                    vertices[i].connections.push_back(potential_connection);
                    vertices[potential_connection].connections.push_back(i);
                    cs++;
                }
            }
        }
    }
}

bool Graph::is_connected(int i, int j)
{
    return std::find(vertices[i].connections.begin(),
                     vertices[i].connections.end(), j) != vertices[i].connections.end();
}
