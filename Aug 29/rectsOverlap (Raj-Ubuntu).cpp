//rect helper
//finds if two rectangles in the cartesian plane defined by an upperleft and lowerright corner overlap
#include <iostream>

class Point
{
public:
    int x;
    int y;
    Point();
    Point( int givenX, int givenY );
};

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point( int givenX, int givenY )
{
    x = givenX;
    y = givenY;
}

class Rect
{
public:
    Point upperLeft;
    Point lowerRight;
    Rect();
    Rect( Point givenUpperLeft, Point givenLowerRight);
};

Rect::Rect()
{
}

Rect::Rect( Point givenUpperLeft, Point givenLowerRight)
{
    upperLeft = givenUpperLeft;
    lowerRight = givenLowerRight;
}

bool rectsOverlap(Rect rect1, Rect rect2)
{
    return( rect1.upperLeft.x    <=   rect2.lowerRight.x &&
            rect1.upperLeft.y    >=   rect2.lowerRight.y &&
            rect1.lowerRight.x   >=   rect2.upperLeft.x &&
            rect1.lowerRight.y   <=   rect2.upperLeft.y );
}


int main()
{
    Point ul(0,10);
    Point lr(10,0);
    Rect rect1(ul,lr);
    Rect rect2(ul,lr);

    if(rectsOverlap(rect1,rect2))
    {
        std::cout << "It worked." << std::endl;
    }
}
