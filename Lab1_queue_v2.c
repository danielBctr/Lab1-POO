
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
    void search();
    void LoadFile();


    int pri_que[MAX];
    int front, rear;

    void main()

    {
        int n, ch;
        printf("##############-Menu-########################");
        printf("\n1 - Insert an element into queue");
        printf("\n2 - Delete an element from queue");
        printf("\n3 - Display queue elements");
        printf("\n4 - Exit");
        printf("\n5 - Reverse the queue");
        printf("\n6 - Sort ascendent the queue");
        printf("\n7 - Save a file");
        printf("\n8 - Search for a file");
        printf("\n9 - Load from File");
        printf("\n############-END of MENU-######################");


        create();

        while (1)
        {
            printf("\nSelect the Option(1 to 9): ");    
            scanf("%d", &ch);

            switch (ch)
            {

            case 1: 
                printf("\nValue to insert: ");
                scanf("%d",&n);
                insert_by_priority(n);
                break;

            case 2:
                printf("\nValue to delete: ");
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
            
            case 8:
                search();
                break;

            case 9:
                LoadFile();
                break;


            default: 
                printf("\nEnter a suitable choice!");

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
      
    int i;
    FILE *saveFIle  = fopen("saveFIle.txt", "w");
    freopen(NULL, "w+", saveFIle);

    if(front == - 1)
        printf("Queue is empty \n");
    else
    {
        for (i = front; i != rear; i = (i + 1) % MAX)
            fprintf(saveFIle, "%d ", pri_que[i]);

        fprintf(saveFIle, "%d ", pri_que[i]);
    }

    fclose(saveFIle);
    }

    void LoadFile()
    {
        FILE* ptr;
        int i;
        front = 0; // with this the zero in front won't appear.
        rear = -1;

        ptr = fopen("LoadFromIt.txt", "r");

        if (NULL == ptr) 
        {
        printf("file can't be opened \n");
        }
        else
        {
            printf("File had been opened!");
            while(fscanf(ptr, "%d ", &pri_que[i]) != EOF)
              {
                i++;
                rear++;
              }
        }
    fclose(ptr);

    }
   

    
    void search() 
    {
    int s;
    int find = 0;
    printf("Search for: ");
    scanf("%d", &s);

    if(front == - 1)
        printf("There is no element in queue! \n");
    else{
        for (int i = 0; i <= rear; i++) {
            if (pri_que[i] == s) 
                find = 1;
        }
        if (find == 1) {
            printf("The element is %p in queue!\n", (void *) &s);
        }
        else 
            printf("Element is missing from queue!\n");
    }
}