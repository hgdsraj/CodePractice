//given two straight line segments represented as a start point adn and end point, computer the point of intersection, if any /
#include <iostream>
#include <exception>
#include <limits>

class EXCEPTION_NO_INTERSECT: public exception
{
  virtual const char* what() const throw()
  {
    return "NO INTERSECTION";
  }
} EXCEPTION_NO_INTERSECT;


class Point
{
public:
    float x;
    float y;
    Point();
    Point(float givenX, float givenY);
};

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(float givenX, float givenY)
{
    x = givenX;
    y = givenY;
}

class Line
{
public:
    Point start;
    Point end;
    Line();
    Line(Point givenStart, Point givenEnd);
    float intersect(Line secondLine);
};

Line::Line()
{
}

Line::Line(Point givenStart, Point givenEnd)
{
    start = givenStart;
    end = givenEnd;
}

float Line::intersect(Line secondLine)
{
    float runThis = (end.x - start.x);
    float slopeThis = run == 0? std::numeric_limits<float>::max() : (end.y-start.y)/runThis ;

    float runSecondLine = (secondLine.end.x - secondLine.start.x);
    float slopeSecondLine = runSecondLine == 0? std::numeric_limits<float>::max() : (secondLine.end.y - secondLine.start.y)/runSecondLine ;

    float slopeDifference = slopeThis - slopeSecondLine
    float intersectPoint = slopeDifference == 0 ? std::numeric_limits<float>::max() : ((secondLine.start.y - start.y)/(slopeDifference);

    if(intersectPoint == std::numeric_limits<float>::max())
    {
    }
    else if(intersectPoint
    {
    }

    throw(EXCEPTION_NO_INTERSECT);


}


int main()
{
    Point firstLineStart(0,0);
    Point firstLineEnd(10,10);
    Point secondLineStart(5,5);
    Point secondLineEnd(0,7);
    Point thirdLineStart(-10,-10.4);
    Point thirdLineEnd(-16.51,-12.3);

    Line firstLine(firstLineStart,firstLineEnd);
    Line secondLine(secondLineStart, secondLineEnd);
    Line thirdLine(thirdLineStart, thirdLineEnd);

    try() //should be true
    {
        firstLine.intersect(secondLine);
        std::cout << "Intersection Successful" << std::endl;
    }
    catch(EXCEPTION_NO_INTERSECT& e)
    {
        std::cout << e.what() << std::endl;
    }

    try() //should be false
    {
        thirdLine.intersect(firstLine);
        std::cout << "Intersection Successful" << std::endl;
    }
    catch(EXCEPTION_NO_INTERSECT& e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
