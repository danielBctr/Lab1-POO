
    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 5

    void insert_by_priority(int);
    void delete_by_priority(int);
    void create();
    void check(int);
    void display_pqueue();
    void reverse_queue();
    void sort();
    void saveAfile();

    int pri_que[MAX];
    int front, rear;

    void main()

    {
        int n, ch;
        printf("\n1 - Insert an element into queue");
        printf("\n2 - Delete an element from queue");
        printf("\n3 - Display queue elements");
        printf("\n4 - Exit");
        printf("\n5 - Reverse the queue");
        printf("\n6 - Sort ascendent the queue");
        printf("\n7 - Save a file");

        create();

        while (1)
        {
            printf("\nEnter your choice : ");    
            scanf("%d", &ch);

            switch (ch)
            {

            case 1: 
                printf("\nEnter value to be inserted : ");
                scanf("%d",&n);
                insert_by_priority(n);
                break;

            case 2:
                printf("\nEnter value to delete : ");
                scanf("%d",&n);
                delete_by_priority(n);
                break;

            case 3: 
                display_pqueue();
                break;

            case 4: 
                exit(0);
            
            case 5:
                reverse_queue();
                break;

            case 6:
                sort();
                break;
            
            case 7:
                saveAfile();
                break;


            default: 
                printf("\nChoice is incorrect, Enter a correct choice");

            }

           
        }

 

    }


    void create()

    {

        front = rear = -1;

    }


    void insert_by_priority(int data)
    {
        if (rear >= MAX - 1)
        {
            printf("\nQueue overflow no more elements can be inserted");
            return;
        }
        if ((front == -1) && (rear == -1))
        {
            front++;
            rear++;
            pri_que[rear] = data;
            return;
        }    

        else
            check(data);
        rear++;
    }

    void check(int data)
    {
        int i,j;
        for (i = 0; i <= rear; i++)
        {
            if (data >= pri_que[i])
            {
                for (j = rear + 1; j > i; j--)
                {
                    pri_que[j] = pri_que[j - 1];
                }
                pri_que[i] = data;
                return;
            }
        }
        pri_que[i] = data;
    }

    void delete_by_priority(int data)
    {
        int i;
        if ((front==-1) && (rear==-1))
        {
            printf("\nQueue is empty no elements to delete");
            return;
        }

        for (i = 0; i <= rear; i++)
        {
            if (data == pri_que[i])
            {
                for (; i < rear; i++)
                {
                    pri_que[i] = pri_que[i + 1];
                }

            pri_que[i] = -99;
            rear--;

            if (rear == -1) 
                front = -1;
            return;
            }
        }
        printf("\n%d not found in queue to delete", data);
    }

    void display_pqueue()

    {
        if ((front == -1) && (rear == -1))
        {
            printf("\nQueue is empty");
            return;
        }

        for (; front <= rear; front++)
        {
            printf(" %d ", pri_que[front]);
        }
        front = 0;
    }

    void reverse_queue()
    {
        int i, j, t;
        for(i=front,j=rear;i<j;i++,j--)
        {
            t = pri_que[i];
            pri_que[i] = pri_que[j];
            pri_que[j] = t;

        }
        display_pqueue();

    }

    void sort()
    {
        int k, l, final;
        for(k=front,l=rear;k<l;k++,l--)
        {
            final = pri_que[k];
            pri_que[k] = pri_que[l];
            pri_que[l] = final;

        }
        display_pqueue();

    }

    void saveAfile()
    {
        int num;
   FILE *fptr;

   
   fptr = fopen("program.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   printf("Enter num: ");
   scanf("%d",&num);

   fprintf(fptr,"%d",num);
   fclose(fptr);
 
    }