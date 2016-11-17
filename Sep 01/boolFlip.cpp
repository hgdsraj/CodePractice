
void FlipColor(int x, int y, bool A[][], int m, int n)
{
    if(x>m || y > n)
    {
        return;
    }
    void FlipColor(int x, int y, A[][], A[x][y]);
}
void FlipColor(int x, int y, bool A[][], bool whichOne, int m, int n)
{
    if(x > m || y > n)
    {
        return;
    }
    if(A[x][y] == whichOne)
    {
      A[x][y] = !A[x][y];
    }
    if (A[x+1][y])
    {
        A[x+1][y]
    }

    if ()
    {

    }

    if ()
    {

    }

    if ()
    {

    }
}
