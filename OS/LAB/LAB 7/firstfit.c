#include<stdio.h>
int p,b,block[10],process[10],b_copy[10],remain[10];
void first_fit();
void best_fit();
void worst_fit();
void main() {
	int i;
	printf("How many process & blocks ? ");
	scanf("%d%d",&p,&b);
	printf("\nProcess sizes ?\n");
	for(i=0;i<p;i++) {
		printf("P%d: ",i+1);
		scanf("%d",&process[i]);
	}
	printf("\nBlock sizes ?\n");
	for(i=0;i<b;i++) {
		printf("B%d: ",i+1);
		scanf("%d",&block[i]);
	}
	printf("\nFIRST FIT:\n");
	first_fit();
	printf("\nBEST FIT:\n");
	best_fit();
	printf("\nWORST FIT:\n");
	worst_fit();
}
void first_fit() {
	int i,j,p_flg[10]={0},b_flg[10]={0};#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void exit(int status);
int i, j, no, res;
int safety(int[][10], int[], int[][10], int[]);
void output(int[][10]);
void request(int[][10], int[][10], int[], int[], int);
void main() {
    int ans, id, seq[10], R[10], A[10][10], C[10][10], N[10][10], W[10] = {0}, req[10], AV[10];
    printf("\nEnter the number of Processes (less than 10): ");
    scanf("%d", &no);
    printf("Enter the number of resources (less than 10): ");
    scanf("%d", &res);
    printf("Enter the max available instances of each resource : \n");
    for (i = 0; i < res; i++) {
        printf("R%d:", i);
        scanf("%d", &R[i]);
    }
    printf("\nEnter the Allocated Resource Table : \n");
    for (i = 0; i < no; i++)
        for (j = 0; j < res; j++)
            scanf("%d", &A[i][j]);
    printf("\nEnter the Maximum Claim Table : \n");
    for (i = 0; i < no; i++)
        for (j = 0; j < res; j++)
            scanf("%d", &C[i][j]);
    for (i = 0; i < no; i++)
        for (j = 0; j < res; j++)
            N[i][j] = C[i][j] - A[i][j];
    printf("\nAllocated Resource Table:\n\t");
    output(A);
    printf("\n\nMaximum Claim Table:\n\t");
    output(C);
    printf("\n\nNeed Matrix:\n\t");
    output(N);
    for (j = 0; j < res; j++) {
        for (i = 0; i < no; i++)
            W[j] += A[i][j];
        W[j] = R[j] - W[j];
    }
    for (j = 0; j < res; j++)
        AV[j] = W[j];
    int ch = safety(A, W, N, seq);
    if (ch == 1) {
        printf("\n\nThe System is in SAFE STATE :)\n");
        printf("\nThe Safe Sequence : ");
        for (i = 0; i < no; i++)
            printf("|P%d|", seq[i]);
        printf("\nResource Request for a Process Needed? (1=YES,0=NO): ");
        scanf("%d", &ans);
        if (ans == 1) {
            printf("Enter the Process ID for initiating request: ");
            scanf("%d", &id);
            printf("Enter the Request Vector for P%d : ", id);
            for (j = 0; j < res; j++)
                scanf("%d", &req[j]);
            request(A, N, req, AV, id);
        }
    }
}
void output(int arr[][10]) {
    for (i = 0; i < res; i++)
        printf("R%d\t", i);
    for (i = 0; i < no; i++) {
        printf("\nP%d\t", i);
        for (j = 0; j < res; j++)
            printf("%d\t", arr[i][j]);
    }
}
int safety(int A[10][10], int W[10], int N[10][10], int seq[]) {
    int x = 0, flg = 0, target = 0;
    int finish[10];
    for (i = 0; i < no; i++)
        finish[i] = 0;
    for (int w = 0; w < no; w++) {
        label:
        for (int i = 0; i < no; i++) {
            flg = 0;
            for (int j = 0; j < res; j++)
                if (N[i][j] > W[j])
                    flg++;
            if (flg == 0 && finish[i] == 0) {
                for (j = 0; j < res; j++)
                    W[j] += A[i][j];
                finish[i] = 1;
                target++;
                seq[x++] = i;
                goto label;
            }
            continue;
        }
    }
    if (target == no)
        return 1;
    else
        printf("\nThe System is in UNSAFE STATE :(\n");
    return 0; //added return 0 for unsafe state.
}
void request(int A[10][10], int N[10][10], int req[10], int AV[10], int ID) {
    int seq[10];
    for (i = 0; i < res; i++)
        if (req[i] > N[ID][i]) {
            printf("\nNOT POSSIBLE as the process P%d has exceeded its max claim !!", ID);
            exit(0);
        }
    for (i = 0; i < res; i++)
        if (req[i] > AV[i]) {
            printf("\nThe process P%d has to wait since resouces are not available yet!!", ID);
            exit(0);
        }
    for (j = 0; j < res; j++) {
        AV[j] -= req[j];
        A[ID][j] += req[j];
        N[ID][j] -= req[j];
    }
    int ch = safety(A, AV, N, seq);
    if (ch == 1) {
        printf("\nThe System is in SAFE state. Hence, the resources can be allocated\n");
        printf("\nThe Safe Sequence : ");
        for (i = 0; i < no; i++)
            printf("|P%d|", seq[i]);
    }
    printf("\n"); 
}
	for(i=0;i<b;i++)
		remain[i]=b_copy[i]=block[i];
	printf("Process Name\tProcess Size\tBlock name\tTotal Space\tWastage Space\n");
	for(i=0;i<p;i++) {
	for(j=0;j<b;j++)
		if(process[i]<=block[j] && b_flg[j]==0) {
		remain[j]=block[j]-process[i]; 
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i],j+1,block[j],remain[j]);
		p_flg[i]=b_flg[j]=1;break;
		}
		if(p_flg[i]==0)
		printf("%d\t\t%d\t\t-\t\t-\t\t-\n",i+1,process[i]);
	}
}
void best_fit() {
	int i,j,p_flg[10]={0},b_flg[10]={0},b_index[10];
	for(i=0;i<b;i++) {
	b_index[i]=i+1;
	remain[i]=b_copy[i]=block[i];
	}
	for(i=1;i<b;i++)
	for(j=0;j<b-i;j++)
		if(block[j]>block[j+1]) {
			int temp=block[j];
			block[j]=block[j+1];
			block[j+1]=temp;
			temp=b_index[j];
			b_index[j]=b_index[j+1];
			b_index[j+1]=temp;
			}
	printf("Process Name\tProcess Size\tBlock name\tTotal Space\tWastage Space\n");
	for(i=0;i<p;i++) {
	for(j=0;j<b;j++)
		if(process[i]<=block[j] && b_flg[j]==0) {
			remain[j]=block[j]-process[i]; 
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i],b_index[j],block[j],remain[j]);
			p_flg[i]=b_flg[j]=1;break;
			}
	if(p_flg[i]==0)
		printf("%d\t\t%d\t\t-\t\t-\t\t-\n",i+1,process[i]);
	}
}
void worst_fit() {
	int i,j,p_flg[10]={0},b_flg[10]={0},b_index[10];
	for(i=0;i<b;i++) {
		b_index[i]=i+1;
		remain[i]=b_copy[i];
	}
	for(i=1;i<b;i++)
		for(j=0;j<b-i;j++)
			if(b_copy[j]<b_copy[j+1]) {
			int temp=b_copy[j];
			b_copy[j]=b_copy[j+1];
		         b_copy[j+1]=temp;
			temp=b_index[j];
			b_index[j]=b_index[j+1];
			b_index[j+1]=temp;
			}
	printf("Process Name\tProcess Size\tBlock name\tTotal Space\tWastage Space\n");
	for(i=0;i<p;i++) {
	for(j=0;j<b;j++)
		if(process[i]<=b_copy[j] && b_flg[j]==0) {
			remain[j]=b_copy[j]-process[i]; 
			printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i],b_index[j],b_copy[j],remain[j]);
			p_flg[i]=b_flg[j]=1;break;
			}
		if(p_flg[i]==0)
			printf("%d\t\t%d\t\t-\t\t-\t\t-\n",i+1,process[i]);
	}
}
	
