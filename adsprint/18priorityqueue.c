
#include <stdio.h>
#define MAX 100

typedef struct Item {
  int data;
  int priority;
}it;

it pq[MAX];
int size = 0;

void swap(it *a,it *b) {
  it temp = *a;
  *a = *b;
  *b = temp;
}

int higherPriority(it a, it b) {
  if (a.priority == b.priority)
    return a.data > b.data;

  return a.priority > b.priority;
}

void enqueue(int data, int priority) {
  if (size == MAX) {
    printf("Priority Queue Overflow!\n");
    return;
  }

  int i = size;

  pq[i].data = data;
  pq[i].priority = priority;
  size++;

  while (i > 0) {
    int parent = (i - 1) / 2;

    if (higherPriority(pq[i], pq[parent])) {
      swap(&pq[i], &pq[parent]);
      i = parent;
    } else {
      break;
    }
  }
}

void dequeue() {
  if (size == 0) {
    printf("Priority Queue Underflow!\n");
    return;
  }

  printf("Deleted element: %d\n", pq[0].data);

  pq[0] = pq[size - 1];
  size--;

  int i = 0;

  while (1) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < size &&
        higherPriority(pq[left], pq[largest])) {
      largest = left;
    }

    if (right < size &&
        higherPriority(pq[right], pq[largest])) {
      largest = right;
    }

    if (largest != i) {
      swap(&pq[i], &pq[largest]);
      i = largest;
    } else {
      break;
    }
  }
}

void display() {
  if (size == 0) {
    printf("Priority Queue is empty!\n");
    return;
  }

  printf("Value\tPriority\n");

  for (int i = 0; i < size; i++) {
    printf("%d\t%d\n", pq[i].data, pq[i].priority);
  }
}

int main() {
  int choice, val, pri;

  while (1) {
    printf("\n1. Enqueue\n2. Dequeue\n");
    printf("3. Display\n4. Exit\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1)
      break;

    switch (choice) {
      case 1:
        printf("Enter value and priority: ");
        if (scanf("%d %d", &val, &pri) != 2)
          return 0;
        enqueue(val, pri);
        break;

      case 2:
        dequeue();
        break;

      case 3:
        display();
        break;

      case 4:
        return 0;

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}

/*  OUTPUT

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 3
   Priority Queue is empty!

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 1
   Enter value and priority: 10 1

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 1
   Enter value and priority: 20 3

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 1
   Enter value and priority: 15 2

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 1
   Enter value and priority: 30 3

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 3
   Value Priority
   30 3
   20 3
   15 2
   10 1

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 2
   Deleted element: 30

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 3
   Value Priority
   20 3
   10 1
   15 2

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 2
   Deleted element: 20

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 2
   Deleted element: 15

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 2
   Deleted element: 10

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 2
   Priority Queue Underflow!

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 3
   Priority Queue is empty!

   1. Enqueue
   2. Dequeue
   3. Display
   4. Exit
   Enter choice: 4
  */
