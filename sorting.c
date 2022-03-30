#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define TAM 6
void sort(int *arr,int n);
void printArr(const int *arr,int n);

void sort(int *arr,int n)
{
	int temp,i=0,j;
	int top,seek;
printf("sorting background : \n");
	for(top=0;top<n-1;top++)
	{
		
		for(seek=top+1;seek<n;seek++)
		
			if(arr[seek]>arr[top])
			{
				temp=arr[top];
				arr[top]=arr[seek];
				arr[seek]=temp;
			for(i=0;i<n;i++)
			{
		
			printf("%d \t ",arr[i]);
		}
		printf("\n");		
			}	
		
				
		}
	
}
void printArr(const int *arr,int n)
{
	int index;
	for(index=0;index<n;index++)
	{
		printf("%5d",arr[index]);
		if (index % 10 == 9)
            putchar('\n');
	}
	if (index % 10 != 0) // if last line not complete
        putchar('\n');
}


int v[TAM] = {10, 7, 8, 9, 1, 5}; 



int partitionRandom(int v[], int begin, int end){
	int i, temp; 
	int k;
	double d; 
	
	d = (double) rand () / ((double) RAND_MAX + 1);
	k = d * (end - begin + 1);
	int randomIndex = begin + k; 
	
	temp = v[randomIndex];
	v[randomIndex] = v[end];
	v[end] = temp; 
	
	int pivot = v[end]; 
	i = begin - 1; 
	int j; 
	
	for (j = begin;  j <=  end - 1; j++){
			
			if(v[j] <= pivot){
				i = i + 1; 
				temp = v[i];
				v[i] = v[j];
				v[j] = temp; 
			}
	}
		
	temp = v[i + 1];
	v[i + 1] = v[end];
	v[end] = temp; 
	
	return i + 1;  	
	
}

int partitionBegin(int v[], int begin, int end){
	
	int pivot = v[begin];
	int p1 = begin + 1; 
	int i, temp; 
	
	for (i = begin + 1; i <= end; i++){
		
		if (v[i] < pivot){
			if (i != p1){
				temp = v[p1];
				v[p1] = v[i];
				v[i] = temp;
			}
			p1++;
		}
	}
	v[begin] = v[p1-1];
	v[p1-1] = pivot;
	
	return p1 - 1; 
	
}

int partitionEnd(int v[], int begin, int end){
	
	int pivot = v[end];
	int p1 = begin; 
	int i, temp; 
	
	for (i = begin; i < end ; i++){
		
		if (v[i] < pivot){
			
			if(i != p1){
				temp = v[p1];
				v[p1] = v[i];
				v[i] = temp;
			}	
			p1++;			
		}
		
	}
	
		temp = v[p1];
		v[p1] = v[end];
		v[end] = temp;
	
		return p1;
	
}



void quickSortBegin(int v[], int begin, int end){
	
	
		if (begin < end) {
			int middle = partitionBegin(v,begin,end);
			quickSortBegin(v,begin, middle - 1);
			quickSortBegin(v, middle + 1, end);	
    	}
    
    
		
	
	
}

void quickSortEnd(int v[], int begin, int end){

	
	if (begin < end) {
		int middle = partitionEnd(v,begin,end);
		quickSortEnd(v,begin, middle - 1);
		quickSortEnd(v, middle + 1, end);	
    }
    
    

}

void quickSortMiddle(int v[], int esq, int dir) {

      int i = esq, j = dir;

      int tmp;

      int pivot = v[(esq + dir) / 2];

       while (i <= j) {

            while (v[i] < pivot)
                i++;

            while (v[j] > pivot)
                j--;

            if (i <= j) {
                  tmp = v[i];
                  v[i] = v[j];
                  v[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (esq < j)
            quickSortMiddle(v, esq, j);

      if (i < dir)
            quickSortMiddle(v, i, dir);

}

void quickSortRandom(int v[], int begin, int end){
	if (begin < end) {
		int middle = partitionRandom(v,begin,end);
		quickSortRandom(v,begin, middle - 1);
		quickSortRandom(v, middle + 1, end);	
    }
	
}

void listar(){
	int i;
	
	
	for (i = 0; i < TAM; i++)
		printf("%d ", v[i]);
	
}

int main(){
	
	int op; 
	
	int i;
	int arr[SIZE];	
	int range;
do{
	
	printf("\n\n~~~~~~~~~~~~~~~~~~\n\n");	
	printf("~~ Quick sort ~~ "); 	
	printf("\n\n1. first pivot\n");
	printf("2. middle pivot \n");
	printf("3. last pivot \n");
	printf("4. random pivot \n");
	printf("0. bye \n\n");
	printf("Choose one: "); 
	
	scanf("%d", &op);
	
		
	
	switch(op){
		
		case 1: 
		printf("\n\n~~~~ first pivot ~~~~ \n\n");
		printf("nao ordenado:\n");
			listar(v);
			quickSortBegin(v, 0, TAM -1);
		printf("\n\nordenado: \n");
			listar(v);
			printf("\n\n");
			break;
			
		case 2: 
		printf("\n\n~~~~ middle pivot ~~~~ \n\n");
	
			listar(v);
			quickSortMiddle(v, 0, TAM -1);
			listar(v);
			printf("\n\n");
			break;
		case 3: 
		printf("\n\n~~~~ last pivot ~~~~ \n\n");
			listar(v);
			quickSortEnd(v, 0, TAM -1);
		printf("\n\nordenado:\n");
			listar(v);
			printf("\n\n");
			break;
		case 4: 
		printf("\n\n~~~~ random pivot ~~~~ \n\n");
			listar(v);
			quickSortRandom(v, 0, TAM -1);
		printf("\n\nordenado: \n");
			listar(v);
			break;
		case 5:
				printf("Enter number range: ");
	scanf("%d",&range);

	srand((unsigned)time(NULL));

	for(i=0;i<SIZE;i++)
	{
		arr[i]=rand()%range+1;
		
	}
	puts("Initial Array\n");
	printArr(arr,SIZE);
	sort(arr,SIZE);
	puts("Sorted array\n");
	printArr(arr,SIZE);
		case 0:
			break;
	}

}while(op != 5);
//	return 0;
}
