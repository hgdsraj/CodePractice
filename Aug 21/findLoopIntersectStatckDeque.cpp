bool MyQueue::isEmpty()
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
/*
Implement a MyQueue class that implements a Queue using two stacks
In other words, use two LIFO stacks to implement a FIFO queue
*/



// Interface
class MyQueue
{
public:
    // Stack has push(int data), pop(), and isEmpty() operations to use
    Stack * stack1;
    Stack * stack2;

private:
    void enqueue(int data);
    void dequeue();
    bool isEmpty();
};

//Implementation
void MyQueue::enqueue(int data)
{
    stack1->push(data);
}

void MyQueue::dequeue()
{
    if(stack2.isEmpty())
    {
        while (!stack1.isEmpty())
        {
            stack2.push(stack1.pop());
        }
    }

    stack2.pop()
}

bool MyQueue::isEmpty()
{
    return stack1.isEmpty() && stack2.isEmpty();
}


/*
Implement a MyQueue class that implements a Queue using two stacks
In other words, use two LIFO stacks to implement a FIFO queue
*/



// Interface
class MyQueue
{
public:
    // Stack has push(int data), pop(), and isEmpty() operations to use
    Stack * stack1;
    Stack * stack2;

private:
    void enqueue(int data);
    void dequeue();
    bool isEmpty();
};

//Implementation
void MyQueue::enqueue(int data)
{
    stack1->push(data);
}

void MyQueue::dequeue()
{
    if(stack2.isEmpty())
    {
        while (!stack1.isEmpty())
        {
            stack2.push(stack1.pop());
        }
    }

    stack2.pop()
}

bool MyQueue::isEmpty()
{
    return stack1.isEmpty() && stack2.isEmpty();
}


Position:	Ln 41, Ch 24	Total:	Ln 46, Ch 669
