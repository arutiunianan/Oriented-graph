#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nodes{
    
    int number_of_nodes;
    int* nodes_number; 
    
};

struct Edges {
    
    int number_of_edges;
    int* edges_nodes_number;
    
};



int* add_edge(int edge1, int edge2, struct Nodes nodes,struct Edges edges){
    
    int flag=0;
    
    for(int i=0;i<nodes.number_of_nodes;i++){
        
        if (edge1 == nodes.nodes_number[i]){
            
            flag = flag + 1;
            
        }
        
        if (edge2 == nodes.nodes_number[i]){
            
            flag = flag + 2;
            
        }
        
    }
    
    if (flag == 0){
        
        printf("%d, %d",-edge1,-edge2);
        return edges.edges_nodes_number;
        
    }
    
    if (flag == 2 || (flag=0 && edge1 == edge2)){
        
        printf("%d ",-edge1);
        return edges.edges_nodes_number;
        
    }
    
    if (flag == 1){
        
        printf("%d ",-edge2);
        return edges.edges_nodes_number;
        
    }
    
    for(int i=0; i<edges.number_of_edges;i=i+2){
        
        if(edges.edges_nodes_number[i] == edge1 && edges.edges_nodes_number[i+1] == edge2)
        {
            printf("%d ",0);
            return edges.edges_nodes_number;
        }
        
    }
    
    int* r = calloc(edges.number_of_edges+2,sizeof(int));
    
    for(int j=0;j<edges.number_of_edges;j++){
            
        r[j] = edges.edges_nodes_number[j];
        
    }
    
    r[edges.number_of_edges] = edge1;
    r[edges.number_of_edges+1] = edge2;
    free(edges.edges_nodes_number);
    return r;
    
    
}


int* remove_edge(int edge1, int edge2, struct Nodes nodes,struct Edges edges){
    
    int flag=0;
    
    for(int i=0;i<nodes.number_of_nodes;i++){
        
        if (edge1 == nodes.nodes_number[i]){
            
            flag = flag + 1;
            
        }
        
        if (edge2 == nodes.nodes_number[i]){
            
            flag = flag + 2;
            
        }
        
    }
    
    if (flag == 2){
        
        //printf("%d ",-edge1);
        return edges.edges_nodes_number;
        
    }
    
    if (flag == 1){
        
        //printf("%d ",-edge2);
        return edges.edges_nodes_number;
        
    }
    
    if (flag == 0){
        
        //printf("%d, %d",-edge1,-edge2);
        return edges.edges_nodes_number;
        
    }
    /*
    
    */
    for(int i=0; i<edges.number_of_edges;i++){
        
        if(edges.edges_nodes_number[i] == edge1 && edges.edges_nodes_number[i+1] == edge2)
        {
            
            int* r = calloc(edges.number_of_edges-2,sizeof(int));
            
            for(int j=0;j<i;j++){
            
               r[j] = edges.edges_nodes_number[j];
        
            }
            for(int j=i;j<edges.number_of_edges;j++){
                
                r[j] = edges.edges_nodes_number[j+2];
                
            }
            free(edges.edges_nodes_number);
            return r;
            
        }
        
    }
    
    printf("%d ",0);
    return edges.edges_nodes_number;
    
}

int* add_node(int node_number, struct Nodes nodes){

    for(int i=0;i<nodes.number_of_nodes;i++){

        if(nodes.nodes_number[i] == node_number)
        {
            printf("%d ",-1);
            return nodes.nodes_number;
        }
        
    }
    int* r = calloc(nodes.number_of_nodes+1,sizeof(int));
    for(int j=0;j<nodes.number_of_nodes;j++){
            
        r[j] = nodes.nodes_number[j];
        
    }
    r[nodes.number_of_nodes] = node_number;
    free(nodes.nodes_number);
    return r;
}

int* remove_node(int node_number, struct Nodes nodes,struct Edges edges){
    
    for(int i=0;i<nodes.number_of_nodes;i++){
        
        if(nodes.nodes_number[i] == node_number)
        {
            
            for(int j=0;j<edges.number_of_edges;j++){
                
                if(edges.edges_nodes_number[j] == node_number){
                    
                    j=j-1;
                    if(j%2==0){
                        edges.edges_nodes_number =  remove_edge(edges.edges_nodes_number[j],edges.edges_nodes_number[j+1],nodes,edges);
                    }
                    else{
                        edges.edges_nodes_number =  remove_edge(edges.edges_nodes_number[j-1],edges.edges_nodes_number[j],nodes,edges);
                    }
                    edges.number_of_edges = edges.number_of_edges - 2;
                    printf("(%d); ",edges.number_of_edges);
                    
                }
            }
            
            int* r = calloc(nodes.number_of_nodes+1,sizeof(int));
            for(int j=0;j<i;j++){
                
                r[j] = nodes.nodes_number[j];
            }
            for(int j=i;j<nodes.number_of_nodes;j++){
                
               r[j] = nodes.nodes_number[j+1];
            }
            
            
            free(nodes.nodes_number);
            return r;
            
        }
    }
    printf("%d ",-1);
    return nodes.nodes_number;
}


int main(void)
{
    
    char command[11];
    int node_number;
    int edge1,edge2;
    int root = -1;
    
    //struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge)*0); 
    //struct Node* node = (struct Node*)malloc(sizeof(struct Node)*0);
    struct Edges edges;
    struct Nodes nodes;
    nodes.number_of_nodes = 0;
    edges.number_of_edges = 0;
    
    nodes.nodes_number = (int*)malloc(sizeof(int)*0);
    
    edges.edges_nodes_number = (int*)malloc(sizeof(int)*0);
    
    
    do{
        scanf("%s",command);
        switch
        if(!strcmp(command,"ADD_NODE"))
        {
            int* node1 = nodes.nodes_number;

            
            scanf("%d", &node_number);
            nodes.nodes_number = add_node(node_number, nodes);
            if(nodes.nodes_number != node1)
                nodes.number_of_nodes = nodes.number_of_nodes + 1;
        }
        else
        {
            if(!strcmp(command,"ADD_EDGE"))
            {
                
                int* edge12 = edges.edges_nodes_number;
                
                scanf("%d %d", &edge1, &edge2);
                edges.edges_nodes_number =  add_edge(edge1,edge2,nodes,edges);
                if(edges.edges_nodes_number != edge12)
                    edges.number_of_edges = edges.number_of_edges + 2;
                
            }
            else
            {
                if(!strcmp(command,"REMOVE_NODE"))
                {
                    
                    int* node1 = nodes.nodes_number;
                    
                    scanf("%d", &node_number);
                    nodes.nodes_number = remove_node(node_number, nodes, edges);
                    if(nodes.nodes_number != node1)
                        nodes.number_of_nodes = nodes.number_of_nodes - 1;
            
                }
                else
                {
                    if(!strcmp(command,"REMOVE_EDGE"))
                    {
                        int* edge12 = edges.edges_nodes_number;
                        
                        int edge1,edge2;
                        scanf("%d %d", &edge1, &edge2);
                        edges.edges_nodes_number =  remove_edge(edge1,edge2,nodes,edges);
                        
                        if(edges.edges_nodes_number != edge12){
                            edges.number_of_edges = edges.number_of_edges - 2;
                        }
                    }
                    else
                    {
                        if(!strcmp(command,"ROOT"))
                        {
                            
                            scanf("%d",root);
                            
                        }
                        else
                        {
                            if(!strcmp(command,"PRINT_PRO"))
                            {
                                    
                            }
                        }
                    }
                }
            }
        }
        }
    }while(!strcmp(command,"END"))
              
    for(int i=0; i<5;i=i+1){

        int* node1 = nodes.nodes_number;

        
        scanf("%d", &node_number);
        nodes.nodes_number = add_node(node_number, nodes);
        if(nodes.nodes_number != node1){
            nodes.number_of_nodes = nodes.number_of_nodes + 1;
        }
        
    }
    
    printf("%d ",1000000);
    
    for(int i=0; i<5;i=i+1){
        
        int* edge12 = edges.edges_nodes_number;
        
        
        scanf("%d %d", &edge1, &edge2);
        edges.edges_nodes_number =  add_edge(edge1,edge2,nodes,edges);
        if(edges.edges_nodes_number != edge12){
            edges.number_of_edges = edges.number_of_edges + 2;
        }

    }
    
    printf("%d ",1000000);
    
    for(int i=0; i<5;i=i+1){
        
        int* node1 = nodes.nodes_number;
        
        int node_number;
        scanf("%d", &node_number);
        nodes.nodes_number = remove_node(node_number, nodes, edges);
        if(nodes.nodes_number != node1){
            nodes.number_of_nodes = nodes.number_of_nodes - 1;
        }
        printf("(%d) ",edges.number_of_edges);

    }


    for(int i=0; i<edges.number_of_edges; i=i+2){

        printf("%d|%d ",edges.edges_nodes_number[i],edges.edges_nodes_number[i+1]);

    }
    
    
    for(int i=0; i<nodes.number_of_nodes; i=i+1){

        printf("%d, ",nodes.nodes_number[i]);

    }
    
    printf("%d ",1000000);
    
    
    for(int i=0; i<5;i=i+1){
        
        int* edge12 = edges.edges_nodes_number;
        
        int edge1,edge2;
        scanf("%d %d", &edge1, &edge2);
        edges.edges_nodes_number =  remove_edge(edge1,edge2,nodes,edges);
        
        if(edges.edges_nodes_number != edge12){
            edges.number_of_edges = edges.number_of_edges - 2;
        }

    }
    
    
    for(int i=0; i<edges.number_of_edges; i=i+2){

        printf("%d|%d ",edges.edges_nodes_number[i],edges.edges_nodes_number[i+1]);

    }
    
    
}
