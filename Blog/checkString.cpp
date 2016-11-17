//There are three types of edits that can be performed on strings, insert a char
// remove a char, or replac ea char/ given two strings, write a function to check
// if they are one edit (or zero edits ) away
//ex
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

#include <string>
#include <iostream>


bool oneEditAway (std::string first, std::string second)
{
    int firstLength = first.length();
    int secondLength = second.length();

    if (abs(firstLength - secondLength) > 1)
    {
      return false;
    }


    std::string longString;
    std::string shortString;
    int longLength;
    int shortLength;

    if (firstLength > secondLength)
    {
        longString = first;
        shortLength = secondLength;
        longLength = firstLength;
        shortString = second;
    }
    else
    {
        longLength = secondLength;
        shortLength = firstLength;
        longString = second;
        shortString = first;
    }

    int shortIndex = 0;
    int longIndex = 0;
    bool foundDifference = false;

    while (shortIndex < shortLength && longIndex < longLength)
    {
        if (shortString[shortIndex] != longString[longIndex])
        {
            if(foundDifference)
            {
                return false;
            }
            foundDifference = true;
            if(shortLength == longLength)
            {
                shortIndex++;
            }
        }
        else
        {
            shortIndex++;
        }
        longIndex++;
    }
    return true;
}

int main()
{
    std::string pale = "pale";
    std::string ple = "ple";
    std::string pales = "pales";
    std::string bale = "bale";
    std::string bake = "bake";
    if (oneEditAway(pale,ple) )
    {
        std::cout << "chedked1" << std::endl;
    }
    if (oneEditAway(pales,pale))
    {
        std::cout << "checked2" << std::endl;
    }
    if (oneEditAway(bale,pale))
    {
        std::cout << "checked3" << std::endl;
    }
    if (oneEditAway(pale,bake))
    {
        std::cout << "shudbefalse" << std::endl;
    }
    else
    {
        std::cout << "checke3" << std::endl;
    }
    return 0;

}
// Description: This public method is a wrapper method,
  //              which calls the recursive heightR(Node *current) defined below.
  //              It returns the height of the tree.
int height(bNode<T> root) 
{
  return root == NULL ? 0 : heightR(root); // if root is null, height is 0, else find the height and return it
}

// Description: Computes the height of each node in the tree
//              and stores the height of the node in the node's
//              attribute "height" (see Node.h).
  //              For example, if current is a leaf, its height is 1.
  //              If current has a leaf as a left and as a right subtree,
  //              its height is 2, etc... If current is NULL, its height is 0.
int BST::heightR(Node *current) const
{
    int currHeight = 0;

    if (current != NULL)
    {
    int leftH = heightR( current->getLeft() ); //get left height
    int rightH = heightR( current->getRight() ); //gwt right height
    int maxHeight = leftH > rightH ? leftH : rightH; //real height is the max of the two heights
    currHeight = maxHeight + 1; // add one to height to include current
    current->setHeight( currHeight ); //set it :)
    }

    return currHeight; //returns the height
}
