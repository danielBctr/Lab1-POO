#include <stdio.h>
#include<stdlib.h>
#define limit 50

int queue_priority[limit];
int rear = - 1;
int front = - 1;

void circular_insert();
void circular_delete();
void reverse();
void display();
void check();


int main()
{
	int choice, e;

	
		printf("\n###################-Circular Queue-#########################3");
		printf("\n1 - Insert an element into Circular Queue");
		printf("\n2 - Delete an element from Circular Queue");
		printf("\n3 - Display CircularQueue elements");
		printf("\n4 - Reverse the Circular Queue");
		printf("\n0 -Quit CircualrQueue");
		printf("\n#################################################################");

    while(1)
    {
		printf("\nSelect the Option: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Value to insert: ");
				scanf("%d", &e);
				circular_insert(e);
				break;
			case 2:
				circular_delete();
				break;
			case 3:
				display();
				break;
			case 4:
				reverse();
				int i, j, t;
				for (i = front, j = rear; i < j; i++,j--)
				{
					t = queue_priority[i];
					queue_priority[i] = queue_priority[j];
					queue_priority[j] = t;
				}
				break;	

			case 0:
				exit(0);
	
			default:
				printf("\nTry again=(");
		}
	}		
}

void circular_insert(int element)
{
    if ((front == rear + 1) || (front == 0 && rear == limit - 1))
        printf("\nQueue Overflow!");
    else 
	{
        if (front == -1) 
            front = 0;
            rear = (rear + 1) % limit;
            queue_priority[rear] = element;
    }
}

void circular_delete()
{
    if (front == -1) 
	{
        printf("\nQueue is empty!");
    } 
    else 
	{
        if (front == rear) 
		{
            front = -1;
            rear = -1;
        } 
        else 
		{
            printf("Deleted from CircularQueue: %d \n", queue_priority[front]);
            front = (front + 1) % limit;
        }
    }
}

void reverse()
{
    int i, j, t;
	for (i = front, j = rear; i < j; i++,j--)
    {
		t = queue_priority[i];
		queue_priority[i] = queue_priority[j];
		queue_priority[j] = t;
	}
	printf("\nReversed CircularQueue: ");
	for (i = front; i <= rear; i++)
			printf("%d ", queue_priority[i]);
}

void display()
{
	int i;
	if ((front == -1) && (rear == -1))
	{
		printf("\nQueue is empty=(");
		return;
	}	
	else
	{
		printf("\nCircularQueue: ");
		for (i = front; i <= rear; i++)
			printf("%d ", queue_priority[i]);
	}

	front = 0;
}

void check(int element)
{
	int i;
    for (i = 0; i <= rear; i++)
    {
        if (element >= queue_priority[i])
        {
            for (int j = rear+1; j > i; j--)
            {
                queue_priority[j] = queue_priority[j - 1];
            }
            queue_priority[i] = element;
            return;
        }
    }

    queue_priority[i] = element;
}
