#ifndef UTILS_H
#define UTILS_H


#include <math.h>

#include <vector>

namespace utils {

    class Vertex
    {
    public:
        Vertex(int x, int y);
        bool operator==(const Vertex& v) const;
        int x;
        int y;
        std::vector<int> connections;
    };

    double distance(utils::Vertex, utils::Vertex);
    double distance(int, int, int, int);
}



#endif
