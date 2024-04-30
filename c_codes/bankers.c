#include <stdio.h>
#include <stdbool.h>

#define MAXP 10
#define MAXR 10

int m, n, safesequence[MAXP], available[MAXR], max[MAXP][MAXR],allocation[MAXP][MAXR], need[MAXP][MAXR], finish[MAXP];

void needcal()
{
        int i, j;
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        need[i][j]=max[i][j]-allocation[i][j];
                }
        }
}

bool safe()
{
        int work[MAXR];
        int i, j;
        for(i=0;i<n;i++)
        {
                work[i]=available[i];
        }
        for(j=0;j<m;j++)
        {
                finish[j]=false;
        }
        int count =0;
        while(count<m)
        {
                bool found = false;
                for(i=0;i<m;i++)
                {
                        if(!finish[i])
                        {
                                bool alloc = true;
                                for(j=0;j<n;j++)
                                {
                                        if(need[i][j] >work[j])
                                        {
                                                alloc=false;
                                                break;
                                        }
                                }
                                if(alloc)
                                {
                                        int k;
                                        for(k=0;k<n;k++)
                                        {
                                                work[k]+=allocation[i][k];
                                        }
                                        finish[i]=true;
                                        safesequence[count++]=i;
                                        found=true;
                                }
                        }
                }
                if(!found)
                {
                        return false;
                }
int main()
{
        int i, j;
        printf("Enter the number of processes: ");
        scanf(" %d", &m);
        printf("Enter the number of resources: ");
        scanf(" %d", &n);
        printf("Enter the allocation matrix for the %d processes and %d resources: ", m, n);
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf(" %d", &allocation[i][j]);
                }
        }
        printf("Enter the maximum matrix for the %d processes and %d resources: ", m, n);
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {
                        scanf(" %d", &max[i][j]);
                }
        }
        printf("Enter the available resources: ");
        for(i=0;i<n;i++)
        {
                scanf(" %d", &available[i]);
        }
        needcal();
        if(safe())
        {
                printf("Safe sequence exists!!");
                for(i=0;i<m;i++)
                {
                        printf("%d->", safesequence[i]);
                }
                printf("\n");
        }
        else
        {
                printf("Safe sequence does not exists!!! UNSAFE!!");
        }
        return 0;

}


        }
        return true;
}

