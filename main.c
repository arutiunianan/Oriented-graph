#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nodes
{
    
    int number_of_nodes;
    int* nodes_number;
    
};

struct Edges
{
    
    int number_of_edges;
    int* edges_nodes_number;
    
};



int* add_edge(int edge_out, int edge_in, struct Nodes nodes,struct Edges edges)
{
    
    int flag=0;
    
    for(int i = 0; i < nodes.number_of_nodes; i++)
    {
        
        if (edge_out == nodes.nodes_number[i])
        {
            
            flag = flag + 1;
            
        }
        
        if (edge_in == nodes.nodes_number[i])
        {
            
            flag = flag + 2;
            
        }
        
    }
    
    if (flag == 0)
    {
        
        printf("Nodes with num %d and %d are not exist" ,edge_out,edge_in);
        return edges.edges_nodes_number;
        
    }
    
    if (flag == 2 || (flag=0 && edge_out == edge_in))
    {
        
        printf("Node with num %d is not exist" ,edge_out);
        return edges.edges_nodes_number;
        
    }
    
    if (flag == 1)
    {
        
        printf("Node with num %d is not exist" ,edge_in);
        return edges.edges_nodes_number;
        
    }
    
    for(int i = 0; i<edges.number_of_edges; i = i + 2)
    {
        
        if(edges.edges_nodes_number[i] == edge_out && edges.edges_nodes_number[i+1] == edge_in)
        {
            printf("Edge between nodes %d and %d is already exist",edge_out,edge_in);
            return edges.edges_nodes_number;
        }
        
    }
    
    int* r = calloc(edges.number_of_edges+2, sizeof(int));
    
    for(int j = 0; j < edges.number_of_edges; j++){
            
        r[j] = edges.edges_nodes_number[j];
        
    }
    
    r[edges.number_of_edges] = edge_out;
    r[edges.number_of_edges+1] = edge_in;
    free(edges.edges_nodes_number);
    return r;
    
    
}


int* remove_edge(int edge_out, int edge_in, struct Nodes nodes,struct Edges edges, int k)
{
    
    int flag = 0;
    
    for(int i=0; i < nodes.number_of_nodes; i++)
    {
        
        if (edge_out == nodes.nodes_number[i])
        {
            
            flag = flag + 1;
            
        }
        
        if (edge_in == nodes.nodes_number[i])
        {
            
            flag = flag + 2;
            
        }
        
    }
    
    if (flag == 2)
    {
        
        if (k)
         printf("Node with num %d is not exist",edge_out);
        return edges.edges_nodes_number;
        
    }
    
    if (flag == 1)
    {
        
        if(k)
         printf("Node with num %d is not exist",edge_in);
        return edges.edges_nodes_number;
        
    }
    
    if (flag == 0)
    {
        
        if(k)
         printf("Nodes with num %d and %d are not exist",edge_out,edge_in);
        return edges.edges_nodes_number;
        
    }
    /*
    
    */
    for(int i = 0; i < edges.number_of_edges; i++)
    {
        
        if(edges.edges_nodes_number[i] == edge_out && edges.edges_nodes_number[i+1] == edge_in)
        {
            
            int* r = calloc(edges.number_of_edges-2,sizeof(int));
            
            for(int j = 0; j < i; j++)
            {
            
               r[j] = edges.edges_nodes_number[j];
        
            }
            
            for(int j = i; j < edges.number_of_edges; j++)
            {
                
                r[j] = edges.edges_nodes_number[j+2];
                
            }
            free(edges.edges_nodes_number);
            return r;
            
        }
        
    }
    
    printf("Edge between nodes %d and %d are not",edge_out,edge_in);
    return edges.edges_nodes_number;
    
}

int* add_node(int node_number, struct Nodes nodes)
{

    for(int i = 0 ; i < nodes.number_of_nodes; i++)
    {

        if(nodes.nodes_number[i] == node_number)
        {
            printf("Node with num %d is already exist",node);
            return nodes.nodes_number;
        }
        
    }
    
    int* r = calloc(nodes.number_of_nodes+1,sizeof(int));
    for(int j = 0 ; j < nodes.number_of_nodes; j++)
    {
            
        r[j] = nodes.nodes_number[j];
        
    }
    
    r[nodes.number_of_nodes] = node_number;
    free(nodes.nodes_number);
    return r;
}

int* remove_node(int node_number, struct Nodes nodes,struct Edges* edges)
{
    
    for(int i = 0 ; i < nodes.number_of_nodes; i++){
        
        if(nodes.nodes_number[i] == node_number)
        {
            for(int j = 0; j < (*edges).number_of_edges; j++)
            {
                
                if((*edges).edges_nodes_number[j] == node_number)
                {

                    if(j % 2 != 0)
                        j = j - 1;
                    (*edges).edges_nodes_number =  remove_edge((*edges).edges_nodes_number[j],(*edges).edges_nodes_number[j+1],nodes,*edges,0);
                    (*edges).number_of_edges = (*edges).number_of_edges - 2;
                    j = j-1;
                    
                }
            }
            
            int* r = calloc(nodes.number_of_nodes+1,sizeof(int));
            for(int j = 0; j < i; j++)
            {
                
                r[j] = nodes.nodes_number[j];
                
            }
            
            for(int j = i; j < nodes.number_of_nodes; j++)
            {
                
               r[j] = nodes.nodes_number[j+1];
                
            }
            
            
            free(nodes.nodes_number);
            return r;
            
        }
    }
    printf("Node with num %d is not exist",node_number);
    return nodes.nodes_number;
}


int main(void)
{
    
    char command[11];
    int node_number;
    int edge_out,edge_in;
    int root = -1;
    
    //struct Edge* edges = (struct Edge*)malloc(sizeof(struct Edge)*0);
    //struct Node* nodes = (struct Node*)malloc(sizeof(struct Node)*0);
    struct Edges edges;
    struct Nodes nodes;
    nodes.number_of_nodes = 0;
    edges.number_of_edges = 0;
    
    nodes.nodes_number = (int*)malloc(sizeof(int)*0);
    
    edges.edges_nodes_number = (int*)malloc(sizeof(int)*0);
    
    
    do{
        scanf("%s",command);
        if(!strcmp(command,"ADD_NODE"))
        {
            
            int* node_memory = nodes.nodes_number;

            scanf("%d", &node_number);
            nodes.nodes_number = add_node(node_number, nodes);
            if(nodes.nodes_number != node_memory)
                nodes.number_of_nodes = nodes.number_of_nodes + 1;
            
        }
        else
        {
            if(!strcmp(command,"ADD_EDGE"))
            {
                
                int* edge_memory = edges.edges_nodes_number;
                
                scanf("%d %d", &edge_out, &edge_in);
                edges.edges_nodes_number =  add_edge(edge_out,edge_in,nodes,edges);
                if(edges.edges_nodes_number != edge_memory)
                    edges.number_of_edges = edges.number_of_edges + 2;
                
            }
            else
            {
                if(!strcmp(command,"REMOVE_NODE"))
                {
                    
                    int* node_memory = nodes.nodes_number;
                    
                    scanf("%d", &node_number);
                    nodes.nodes_number = remove_node(node_number, nodes, &edges);
                    if(nodes.nodes_number != node_memory)
                        nodes.number_of_nodes = nodes.number_of_nodes - 1;
            
                }
                else
                {
                    if(!strcmp(command,"REMOVE_EDGE"))
                    {
                        int* edge_memory = edges.edges_nodes_number;
                        
                        int edge_out,edge_in;
                        scanf("%d %d", &edge_out, &edge_in);
                        edges.edges_nodes_number =  remove_edge(edge_out,edge_in,nodes,edges,1);
                        
                        if(edges.edges_nodes_number != edge_memory){
                            edges.number_of_edges = edges.number_of_edges - 2;
                        }
                    }
                    else
                    {
                        if(!strcmp(command,"ROOT"))
                        {
                            
                            scanf("%d",&root);
                            
                        }
                        else
                        {
                            if(!strcmp(command,"PRINT"))
                            {
                                
                                for(int i = 0; i < nodes.number_of_nodes; i = i + 1)

                                    printf("%d ",nodes.nodes_number[i]);
                                
                                for(int i = 0; i < edges.number_of_edges; i = i + 2)

                                    printf("%d|%d ",edges.edges_nodes_number[i],edges.edges_nodes_number[i+1]);

                            }
                        }
                    }
                }
            }
        }
        
    }while(strcmp(command,"END"));
    
}
