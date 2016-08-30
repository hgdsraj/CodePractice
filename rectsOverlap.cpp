//rect helper

class Point
{
public:
    int x;
    int y;
    Point( int givenX, int givenY )
    {
        x = givenX;
        y = givenY;
    }
};

class Rect
{
public:
    Point upperLeft;
    Point lowerRight;
    Rect( Point givenUpperLeft, Point givenLowerRight)
    {
        upperLeft = givenUpperLeft;
        lowerRight = givenlowerRight;
    }
};

bool rectsOverlap(Rect rect1, Rect rect2)
{
    return( rect1.upperLeft.x    <=   rect2.lowerRight.x &&
            rect1.upperLeft.y    >=   rect2.lowerRight.y &&
            rect1.lowerRight.x   >=   rect2.upperLeft.x &&
            rect1.lowerRight.y   <=   rect2.upperLeft.y );
  return false;
}

int main()
{
    Point ul(0,10);
    point lr(10,0);
    Rect rect1(ul,lr);
    Rect rect2(ul,lr);

    if(rectsOverLap(rect1,rect2))
    {
        std::cout << "It worked." << std::endl;
    }
}
