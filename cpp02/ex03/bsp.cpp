# include "Point.hpp"

static float area (Point const x, Point const y, Point const z){

    float triArea =  ((x.getX().toFloat() * (y.getY().toFloat() - z.getY().toFloat()))
                    + (y.getX().toFloat() * (z.getY().toFloat() - x.getY().toFloat()))
                    + (z.getX().toFloat() * (x.getY().toFloat() - y.getY().toFloat()))) / 2.0f;
    if (triArea < 0)
        triArea = -triArea;
    return triArea;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){

    float A = area(a, b, c);
    float A1 = area(point, b, c);
    float A2 = area(a, point, c);
    float A3 = area(a, b, point);

    if (A == 0 || A1 == 0 || A2 == 0 || A3 == 0)
        return false;

    return (A == A1 + A2 + A3);
}
