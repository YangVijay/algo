#include <vector>

struct Vec2d{float x,y};

struct Point2d{float x,y};

inline float Dot(Vec2d v1, Vec2d v2){
    return v1.x*v2.x + v1.y*v2.y;
}

inline Vec2d Sub(Point2d p1, Point2d p2){
    return {p1.x - p2.x, p1.y - p2.y};
}

inline bool HasIntersection(std::vector<Point2d> polygon1, std::vector<Point2d> polygon2){
    int m = polygon1.size();
    int n = polygon2.size();

    std::vector<Vec2d> axises;
    for(int i = 0; i < m; i++)
    {
        Vec2d edge = Sub(polygon1[(i+1)%m], polygon1[i]);
        axises.push_back({-edge.y, edge.x});
    }
    for(int i = 0; i < n; i++)
    {
        Vec2d edge = Sub(polygon2[(i+1)%n], polygon2[i]);
        axises.push_back({-edge.y, edge.x});
    }

    for(auto axis : axises)
    {
        float min1 = std::numeric_limits<float>::max();
        float max1 = std::numeric_limits<float>::min();
        for(auto point : polygon1)
        {
            float projection = Dot(point, axis);
            min1 = std::min(min1, projection);
            max1 = std::max(max1, projection);
        }
        float min2 = std::numeric_limits<float>::max();
        float max2 = std::numeric_limits<float>::min();
        for(auto point : polygon2)
        {
            float projection = Dot(point, axis);
            min2 = std::min(min2, projection);
            max2 = std::max(max2, projection);
        }
        if(max1 < min2 || max2 < min1)
        {
            return false;
        }
            
        return true;
    }
}