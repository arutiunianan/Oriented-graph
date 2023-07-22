#include <stdio.h>
#include <stdlib.h>

struct Node{
    
    int node_number;
    
};

struct Edge {
    
    int node_number_in;
    int node_number_out;
    
};

struct Node* add_node(int node_number, int number_of_nodes, struct Node* node){

    for(int i=0;i<number_of_nodes;i++){

        if(node[i].node_number == node_number)
        {
            printf("%d ",-1);
            return node;
        }
        
    }
    struct Node* r = calloc(number_of_nodes +1,sizeof(struct Node));
    for(int j=0;j<number_of_nodes;j++){
            
        r[j].node_number = node[j].node_number;
        
    }
    r[number_of_nodes].node_number = node_number;
    free(node);
    return r;
}

struct Node* remove_node(int node_number, int number_of_nodes, struct Node* node,struct Edge* edge){
    
    for(int i=0;i<number_of_nodes;i++){
        
        if(node[i].node_number == node_number)
        {
            
            //for(int j=0;j<number_of_edges;j++){
                
            //    if(edge[i].node_number_in == node_number){
                    
            //    }
            //}
            
            struct Node* r = calloc(number_of_nodes-1,sizeof(struct Node));
            for(int j=0;j<i;j++){
                
                r[j].node_number = node[j].node_number;
            }
            for(int j=i;j<number_of_nodes;j++){
                
                r[j].node_number = node[j+1].node_number;
            }
            
            
            free(node);
            return r;
            
        }
    }
    printf("%d ",-1);
    return node;
}


struct Edge* add_edge(int edge1, int edge2, int number_of_nodes, int number_of_edges, struct Node* node,struct Edge* edge){
    
    int flag=0;
    
    for(int i=0;i<number_of_nodes;i++){
        
        if (edge1 == node[i].node_number){
            
            flag = flag + 1;
            
        }
        
        if (edge2 == node[i].node_number){
            
            flag = flag + 2;
            
        }
        
    }
    
    if (flag == 2){
        
        printf("%d ",-edge1);
        return edge;
        
    }
    
    if (flag == 1){
        
        printf("%d ",-edge2);
        return edge;
        
    }
    
    if (flag == 0){
        
        printf("%d, %d",-edge1,-edge2);
        return edge;
        
    }
    
    for(int i=0; i<number_of_edges;i++){
        
        if(edge[i].node_number_out == edge1 && edge[i].node_number_in == edge2)
        {
            printf("%d ",-0);
            return edge;
        }
        
    }
    
    struct Edge* r = calloc(number_of_nodes +1,sizeof(struct Edge));
    for(int j=0;j<number_of_edges;j++){
            
        r[j].node_number_out = edge[j].node_number_out;
        r[j].node_number_in = edge[j].node_number_in;
        
    }
    
    r[number_of_edges].node_number_out = edge1;
    r[number_of_edges].node_number_in = edge2;
    free(edge);
    return r;
    
}


struct Edge* remove_edge(int edge1, int edge2, int number_of_nodes, int number_of_edges, struct Node* node,struct Edge* edge){
    
    int flag=0;
    
    for(int i=0;i<number_of_nodes;i++){
        
        if (edge1 == node[i].node_number){
            
            flag = flag + 1;
            
        }
        
        if (edge2 == node[i].node_number){
            
            flag = flag + 2;
            
        }
        
    }
    
    if (flag == 2){
        
        printf("%d ",-edge1);
        return edge;
        
    }
    
    if (flag == 1){
        
        printf("%d ",-edge2);
        return edge;
        
    }
    
    if (flag == 0){
        
        printf("%d, %d",-edge1,-edge2);
        return edge;
        
    }
    
    for(int i=0; i<number_of_edges;i++){
        
        if(edge[i].node_number_out == edge1 && edge[i].node_number_in == edge2)
        {
            
            struct Edge* r = calloc(number_of_nodes-1,sizeof(struct Edge));
            for(int j=0;j<i;j++){
            
                r[j].node_number_out = edge[j].node_number_out;
                r[j].node_number_in = edge[j].node_number_in;
        
            }
            for(int j=i;j<number_of_edges;j++){
                
                r[j].node_number_out = edge[j+1].node_number_out;
                r[j].node_number_in = edge[j+1].node_number_in;
                
            }
            free(edge);
            return r;
            
        }
        
    }
    
    printf("%d ",-0);
    return edge;
    
}

int main(void)
{

    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge)*0); 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)*0); 
    int number_of_nodes = 0;
    int number_of_edges = 0;
    int root = -1;
    
    
    for(int i=0; i<5;i=i+1){

        struct Node* node1 = node;

        int node_number;
        scanf("%d", &node_number);
        node = add_node(node_number, number_of_nodes, node);
        if(node != node1){
            number_of_nodes = number_of_nodes + 1;
        }
        
    }
    
    printf("%d ",1000000);
    
    for(int i=0; i<5;i=i+1){
        
        struct Edge* edge12 = edge;
        
        int edge1,edge2;
        scanf("%d %d", &edge1, &edge2);
        edge =  add_edge(edge1,edge2,number_of_nodes,number_of_edges,node,edge);
        if(edge != edge12){
            number_of_edges = number_of_edges + 1;
        }

    }
    
    for(int i=0; i<5;i=i+1){
        
        struct Node* node1 = node;
        
        printf(" %p ",node);
        
        int node_number;
        scanf("%d", &node_number);
        node = remove_node(node_number, number_of_nodes, node, edge);
        if(node != node1){
            number_of_nodes = number_of_nodes - 1;
        
        }

    }

    
    for(int i=0; i<number_of_edges; i=i+1){

        printf("%d|%d ",edge[i].node_number_out,edge[i].node_number_in);

    }
    
    for(int i=0; i<number_of_nodes; i=i+1){

        printf("%d, ",node[i].node_number);

    }
    
    
    for(int i=0; i<5;i=i+1){
        
        struct Edge* edge12 = edge;
        
        int edge1,edge2;
        scanf("%d %d", &edge1, &edge2);
        edge =  add_edge(edge1,edge2,number_of_nodes,number_of_edges,node,edge);
        if(edge != edge12){
            number_of_edges = number_of_edges + 1;
        }

    }
    
    
    for(int i=0; i<number_of_edges; i=i+1){

        printf("%d|%d ",edge[i].node_number_out,edge[i].node_number_in);

    }
    
    
    
}