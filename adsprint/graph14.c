
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
