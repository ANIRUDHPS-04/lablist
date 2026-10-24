/*
NAME: ANIRUDH P S
Roll No: CS03
EX NO: 14
DATE: 25-09-2026

**********Implementation  of  graphs  and  graph  traversals**********

AIM: Create a program that allows Implementation  of  graphs  and  graph  traversals.
*/

/* **********ALGORITHM**********

Step 1: Start.

Step 2: Read the number of vertices \(n\).

Step 3: Read the adjacency matrix of the graph.

Step 4: Display the menu:
1. Display Graph
2. BFS Traversal
3. DFS Traversal
4. Exit
Step 5: Read the user's choice.

Step 6: Perform the selected operation.
      - Display Graph: Display the adjacency matrix.
      - BFS Traversal:
           1. Initialize all vertices as unvisited.
           2. Insert the starting vertex into the queue and mark it as visited.
           3. Remove a vertex from the queue and display it.
           4. Insert all its unvisited adjacent vertices into the queue and mark them as visited.
           5. Repeat until the queue becomes empty.
      - DFS Traversal:
           1. Initialize all vertices as unvisited.
           2. Mark the starting vertex as visited and display it.
           3. Visit an unvisited adjacent vertex recursively.
           4. Repeat until no unvisited adjacent vertices remain.
Step 7: Return to the menu if the choice is not Exit.

Step 8: Stop.
*/

/* **********SOURCE CODE********** */

#include <stdio.h>

int graph[20][20], visited[20];
int n, queue[20], front, rear;

void createGraph()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

void displayGraph()
{
    int i, j;

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    front = rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int choice, start, i;

    createGraph();

    do
    {
        printf("\n\n--- GRAPH MENU ---\n");
        printf("1. Display Graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayGraph();
                break;

            case 2:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);

                if (start < 0 || start >= n)
                {
                    printf("Invalid vertex!");
                    break;
                }

                BFS(start);
                break;

            case 3:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);

                if (start < 0 || start >= n)
                {
                    printf("Invalid vertex!");
                    break;
                }

                for (i = 0; i < n; i++)
                    visited[i] = 0;

                printf("DFS Traversal: ");
                DFS(start);
                break;

            case 4:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }

    } while (choice != 4);

    return 0;
}

/*  OUTPUT

Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0


--- GRAPH MENU ---
1. Display Graph
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 1

Adjacency Matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

--- GRAPH MENU ---
1. Display Graph
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 2
Enter starting vertex (0 to 3): 0
0 1 2 3

--- GRAPH MENU ---
1. Display Graph
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 3
Enter starting vertex (0 to 3): 0
DFS Traversal: 0 1 3 2

--- GRAPH MENU ---
1. Display Graph
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 4
Exiting...

*/
