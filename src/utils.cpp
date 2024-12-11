#include "utils.h"

double utils::distance(Vertex v1, Vertex v2)
{
    return sqrt( (v2.x-v1.x) * (v2.x-v1.x) + (v2.y-v1.y) * (v2.y-v1.y));
}

double utils::distance(int x1, int x2, int y1, int y2)
{
    return sqrt( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) );
}


utils::Vertex::Vertex(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool utils::Vertex::operator==(const utils::Vertex& v) const
{
    return (v.x == this->x) && (v.y == this->y) ? 1 : 0;
}

