#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Queue
{
   struct Queue *next;
   int data;
};


struct Queue *front;
struct Queue *rear;
char fileName[255];


bool search(int);
void enQueue(int);
void DeleteQ();
void PrintQueue();
void saveFile();
void openFile();
void Sort();
void ReverseQ(); 

int main(){
   struct Queue *q;
   int ch,data,val;
   char title[255];
   
   
      printf("\n##############-Menu-########################");
      printf("\n1 - Insert an element into queue");
      printf("\n2 - Delete an element from queue");
      printf("\n3 - Display queue elements");
      printf("\n4 - Sort ascendent the queue");
      printf("\n5 - Search a value");
      printf("\n6 - Reverse the queue");
      printf("\n7 - Load from file ");
      printf("\n8 - Save a File ");
      printf("\n0 - Exit");
      printf("\n############-END of MENU-######################\n");

    while(1)
    {
      printf("\nSelect the Option: ");
      scanf("%d",&ch);  
   
      switch (ch)
      {
      case 1: 
         printf("\nValue to insert: ");
         scanf("%d",&data);
         enQueue(data);   
         break;

      case 2:
         DeleteQ();
         break;

      case 3:
         PrintQueue();
         break;

      case 4:
         Sort(q);
         printf("\nSorted queue: \n");
         PrintQueue();
         printf("\n"); 
         break;  

      case 5:
         printf("\nSearch For: ");
         scanf("%d", &val);
         search(val);
         if (search(val)==true)
         {
            printf("\nThe Element is in queue!\n");
         }
         else
         {
            printf("\nThe Element is missing from queue!\n");
         }
         break;

      case 6:
         ReverseQ();
         printf("\nThe reversed queue:\n");
         PrintQueue();
         printf("\n");
         
         break;

      case 7:
         printf("\nFile name to load from: ");
         scanf("%s",title); 
         openFile(title); 
         break;

      case 8:
         if (strlen(fileName)!=0)
         {
            saveFile(fileName);
            printf("\nChanges Saved\n");
         }
         else{
         printf("\nFile name to be saved: ");
         scanf("%s",title); 
         saveFile(title);
         }  
         break;  

      case 0:
         return 0; 

      default:
         printf("\nTry again =(\n");
         break;
      }
   }
   return 0;

}

void ReverseQ()
{
   struct Queue* current;
   struct Queue* nxt;
   struct Queue* prev = NULL;
   struct Queue* temp;
   current = front;
   while (current!=NULL)
   {
      temp=current->next;
      current->next=prev;
      prev=current;
      current=temp;
   }
   front=prev;
   
}

void PrintQueue()
{
   struct Queue *q;
   q=front;
         
         while (q!=NULL)
         {
            printf("%d ",q->data);
            q=q->next;

      
         }
}

int count()
{
   struct Queue *q;
   q = front;
   int co = 0;
   while (q!=NULL)
   {
      co++;
      q=q->next;
   }
   return co;
}


void Sort()
{
    struct Queue** q;
    int i, j, swapped;
    int countQ = count(front);
    for (i = 0; i <= countQ; i++) {
 
        q = &front;
        swapped = 0;
 
        for (j = 0; j < countQ - i - 1; j++) {
 
            struct Queue* p1 = *q;
            struct Queue* p2 = p1->next;
 
            if (p1->data > p2->data) {

                  struct Queue* tmp = p2->next;
                  p2->next = p1;
                  p1->next = tmp;
                  *q = p2;

                swapped = 1;
            }
 
            q = &(*q)->next;
        }

        if (swapped == 0)
            break;
    }
}


bool search(int val)
{
   struct Queue *curr;
   curr=front;
   while (curr!=NULL)
   {
      if (curr->data==val)
      {
         return true;
      }
      curr=curr->next;
   }
   return false;
};

void openFile(char title[])
{
   
   FILE *f = fopen(title, "r");
   int c;
   if (f == NULL)
   {
      printf("File is empty!\n");
      return;
   }
   front=NULL;
   rear=NULL;
   
    while (!feof(f))
    {
        fscanf(f ,"%d ", &c);
        enQueue(c);
    }
   printf("\n");
   fclose(f);
   strcpy(fileName, title);
}

void saveFile(char title[])
{
   struct Queue *q;
   q=front;
   FILE *f = fopen(title, "w");
   if (f == NULL)
   {
      printf("Error creating file!\n");
   }
   while (q!=NULL)
   {
      fprintf(f,"%d ",q->data);
      q=q->next;
   }
   fclose(f);
}


void enQueue(int data)
{
   struct Queue *temp;
   temp = malloc(sizeof(struct Queue));
   if(temp==NULL)
   {
      printf("\nMemory can't be allocated =(");
      return;
   }
   temp->data=data;
   temp->next=NULL;
   if(rear==NULL)
   {
      front=temp;
      rear=temp;
   }
   else
   {
      rear->next=temp;
      rear=rear->next;
   }
}

void DeleteQ()
{
   struct Queue *temp;
   temp=front;
   if(front==NULL)
   {
      printf("\nQueue is empty\n");
      return;
   }
   else
   {
      front=front->next;
      free(temp);
      
   }
   
}