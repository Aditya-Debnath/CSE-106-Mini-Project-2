#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int adj_matrix[10000][10000];

int main()
{
    int n;
    clock_t start,end;
    printf("Enter n vertices: ");
    scanf("%d", &n);
    printf("\n");
    srand(time(0));//built in function to use time function

    start=clock(); //Counts the starting time

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int rand_num= rand()% 2;
            adj_matrix[i][j]= rand_num;
            adj_matrix[j][i]= rand_num;
        }
    }

///counting edges
    int edges_count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(adj_matrix[i][j]==1)
            {
                edges_count = edges_count + adj_matrix[i][j];
            }
        }
    }
    printf("Number of edges in the graph: %d\n", edges_count);

    ///Determine degrees of all vertices.
    int degree=0;
    int total_degree=0;
    for(int i=0;i<n;i++)
    {
        degree=0;

        for(int j=0;j<n;j++)
        {
            if(adj_matrix[i][j]==1)
            {
                if(i==j)
                {
                    degree=degree+2;
                }
                else
                {
                    degree=degree+1;
                }
            }
        }
        total_degree+=degree;
    }

    ///handshaking theory
    int handshaking = (total_degree)/2;

    printf("Total degree of the whole graph: %d\n", total_degree);

    end=clock(); //used count the end time
    double duration=(((double) end-start)/CLOCKS_PER_SEC)*1000; //formula to calculate computational time in millisecond


    if(edges_count==handshaking)
    {
        printf("Handshaking theory is proved\n");
    }
    printf("\nComputational time = %.2f ms\n", duration);

    return 0;

}
