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
    char U;
    char V;

    FILE *file;
    file=fopen("map.txt", "r");

    while(!feof(file))
    {
    ch = fgetc(file);
    if(ch == '\n')
    {
        n++;
    }
    }
    fclose(file);
    file=fopen("map.txt", "r");

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
    printf("\nEnter the source node:");
    scanf(" %c",&U);
    if (U =='a')
        u=0;
    else if (U =='b')
        u=1;
    else if (U =='c')
        u=2;
    else if (U =='d')
        u=3;
    else if (U =='e')
        u=4;
    else if (U =='f')
        u=5;
    else if (U =='g')
        u=6;
    else if (U =='h')
        u=7;
    printf("\nEnter the destination node:");
    scanf(" %c",&V);
    if(V =='a')
        v=0;
    else if (V =='b')
        v=1;
    else if (V =='c')
        v=2;
    else if (V =='d')
        v=3;
    else if (V =='e')
        v=4;
    else if (V =='f')
        v=5;
    else if (V =='g')
        v=6;
    else if (V =='h')
        v=7;
    dijkstraalg(G,n,u,v);
    }

    return 0;
}

void dijkstraalg (int** G,int n,int startnode,int destination)
{

    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

/*
pred[] stores the previous value of each node
count gives the number of nodes visited
create the cost matrix
*/

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

// pred[],distance[] and visited[]
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

//gives the node at shortest distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

//check if a better path exists

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

//prints the path and distance of each node


        if(destination!=startnode)
        {
            printf("\nDistance of node%d=%d",destination,distance[destination]);
            printf("\nPath=%c",destination+97);
            j=destination;
            do
            {
                j=pred[j];
                printf("<-%c",j+97);
            }
            while(j!=startnode);
        }
}
