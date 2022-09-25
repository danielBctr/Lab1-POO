#include <stdio.h>
#include<stdlib.h>
#define limit 50

int queue_priority[limit];
int rear = - 1;
int front = - 1;

void priority_insert();
void deletePQ();
void display();
void reverse();
void check();


int main()
{
	int choice, e;

		printf("\n###############Priority Queue##################");
		printf("\n1 - Insert an element into PriorityQueue");
		printf("\n2 - Delete an element from PriorityQueue");
		printf("\n3 - Display PriorityQueue elements");
		printf("\n4 - Reverse the Priority Queue");
		//printf("\n5 - Load From a file");
		//printf("\n6 - Save the PriorityQueue File");
		printf("\n0 - Exit PriorityQueue");
		printf("\n#####################################################");

    while(1)
    {
		printf("\nSelect the Option: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Value to insert: ");
				scanf("%d", &e);
				priority_insert(e);
				break;
			case 2:
				deletePQ();
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
			/*case 5:
				load_file();
				break;		
			case 6:
				save_file();
				break;	*/
			case 0:
				exit(0);

			default:
				printf("\nTry again =(");
		}
		
	}		
}

void priority_insert(int element)
{
	if (rear >= limit - 1)
	{
		printf("\nQueue Overflow!");
		return;
	}

	if ((front == -1) && (rear == -1))
	{
		front++;
		rear++;
		queue_priority[rear] = element;
		return;
	}    
	else
		check(element);
	rear++;
}

void deletePQ()
{
    if (front == -1) 
	{
        printf("\nQueue is empty=(");
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
            printf("Element deleted is: %d \n", queue_priority[front]);
            front = (front + 1) % limit;
        }
    }
}

void display()
{
	int i;
	if ((front == -1) && (rear == -1))
	{
		printf("\nQueue is empty!");
		return;
	}	
	else
	{
		printf("\nThe Queue: ");
		for (i = front; i <= rear; i++)
			printf("%d ", queue_priority[i]);
	}

	front = 0;
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
	printf("\nReversed PriorityQueue: ");
	for (i = front; i <= rear; i++)
			printf("%d ", queue_priority[i]);
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
