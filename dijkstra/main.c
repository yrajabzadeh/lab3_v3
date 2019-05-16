#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX 10
#define MAX_SIZE 1000

void dijkstra(int** G,int n,int startnode,int destination);

int main()
{
    int i,j,n=0,u,v;

    char ch;

    FILE *file;
    file=fopen("costmat.txt", "r");

    while(!feof(file))
    {
    ch = fgetc(file);
    if(ch == '\n')
    {
        n++;
    }
    }
    fclose(file);
    file=fopen("costmat.txt", "r");

    int** G = (int **) malloc(10 * sizeof (int));
    for(i=0;i<10;++i)
    G[i]=malloc(8*sizeof(int));
    for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {

                if (!fscanf(file, "%d", &G[i][j]))
                break;
            }

        }
    fclose(file);
    while(1)
    {

    char testU;
    char testV;

    printf("\nEnter the source node:");
    scanf("%c",&testU);
    if(testU=='a'){
        u=0;
    }
    printf("\nEnter the destination node:");
    scanf("%c",&testV);
    if(testV=='b'){
        v=1;
    }

    dijkstra(G,n,u,v);
    }

    return 0;
}

void dijkstra(int** G,int n,int startnode, int destination)
{

    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,v,j;


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];


    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;

        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

            visited[nextnode]=1;
        for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;

                    }

        count++;
    }



        if(destination!=startnode)
        {
            printf("\nDistance of node%d=%d",destination,distance[destination]);
            printf("\nPath=%d",destination);

            j=destination;
            do
            {
                j=pred[j];
                printf("<--%d",j);
            }while(j!=startnode);
    }
}
