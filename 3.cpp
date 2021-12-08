#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    int *arr;

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

/* Function to create Circular queue */
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1)))
    {
        cout<<"\nQueue is Full"<<endl;
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return INT_MIN;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return;
    }
    cout<<endl;
    cout<<"Front -> "<<arr[front]<<endl;
    cout<<"Rear -> "<<arr[rear]<<endl;
    cout<<"\nElements in Circular Queue are: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i]<<" ";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<<arr[i]<<" ";

        for (int i = 0; i <= rear; i++)
            cout<<arr[i]<<" ";
    }
    cout << endl;
}

/* Driver of the program */
int main()
{
    int size;
    cout<<"Enter the size of Queue : ";
    cin>>size;
    Queue q(size);
    bool flag = true;
    int ch;
    int n;
    while (flag)
    {
        cout << "-----------------------------------------" << endl;
        cout << "1. ENQUEUE " << endl;
        cout << "2. DEQUEUE  " << endl;
        cout << "3. DISPLAY " << endl;
        cout << "0. FOR EXIT " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter the choice : ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            flag = false;
            cout << "EXITING..." << endl;
            break;

        case 1:
            cout << "Enter the element to insert in circular queue  : ";
            cin >> n;
            q.enQueue(n);
            q.displayQueue();
            break;

        case 2:
            cout << "Deleted Value : " << q.deQueue() << endl;
            q.displayQueue();
            break;

        case 3:
            q.displayQueue();
            break;

        default:
            cout << "Wrong Choice" << endl;
            break;
        }
    }
    return 0;
}



/*

Enter the size of Queue : 5
-----------------------------------------
1. ENQUEUE 
2. DEQUEUE  
3. DISPLAY 
0. FOR EXIT 
-----------------------------------------
Enter the choice : 1
Enter the element to insert in circular queue  : 4

Front -> 4
Rear -> 4

Elements in Circular Queue are: 4        
-----------------------------------------
1. ENQUEUE 
2. DEQUEUE  
3. DISPLAY 
0. FOR EXIT 
-----------------------------------------
Enter the choice : 1
Enter the element to insert in circular queue  : 7

Front -> 4
Rear -> 7

Elements in Circular Queue are: 4 7
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 1
Enter the element to insert in circular queue  : 8

Front -> 4
Rear -> 8

Elements in Circular Queue are: 4 7 8
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 1
Enter the element to insert in circular queue  : 3

Front -> 4
Rear -> 3

Elements in Circular Queue are: 4 7 8 3
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 1
Enter the element to insert in circular queue  : 77

Front -> 4
Rear -> 77

Elements in Circular Queue are: 4 7 8 3 77
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 1
Enter the element to insert in circular queue  : 22

Queue is Full

Front -> 4
Rear -> 77

Elements in Circular Queue are: 4 7 8 3 77
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 2
Deleted Value : 4

Front -> 7
Rear -> 77

Elements in Circular Queue are: 7 8 3 77
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 2
Deleted Value : 7

Front -> 8
Rear -> 77

Elements in Circular Queue are: 8 3 77
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 1
Enter the element to insert in circular queue  : 54

Front -> 8
Rear -> 54

Elements in Circular Queue are: 8 3 77 54
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 1
Enter the element to insert in circular queue  : 23

Front -> 8
Rear -> 23

Elements in Circular Queue are: 8 3 77 54 23
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 3

Front -> 8
Rear -> 23

Elements in Circular Queue are: 8 3 77 54 23
-----------------------------------------
1. ENQUEUE
2. DEQUEUE
3. DISPLAY
0. FOR EXIT
-----------------------------------------
Enter the choice : 0
EXITING...



*/
