//ex a->b->c->d->e->f
//delete c : a->b->d->e->f

// a->b->c->d->e->f

// a->b->d   e->f

struct node
{
    int data;
    node * next;
};

//delete corresponds to a datum
//delete[] corresponds to data

// implement an algorithm to delete a node in the middle (ie. any node but the first or last node)
// given only access to that node

void deleteMidNode(node * midNode)
{
    if (midNode == nullptr)
    {
        return;
    }
    node * temp = midNode->next;

    midNode->data = midNode->next->data;
    midNode->next = midNode->next->next;

    delete temp;

    return;
}
