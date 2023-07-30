#include "Function.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INITIAL_SIZE 10


Graph* NewGraph( )
{
    struct Graph* graph = ( Graph* ) malloc ( sizeof ( struct Graph ) );

    graph->root = -1;

    graph->current_nodes = 0;
    graph-> allocated_nodes = INITIAL_SIZE;
    graph->nodes = ( Node* ) malloc ( sizeof ( struct Node ) * INITIAL_SIZE );

    graph->current_edges = 0;
    graph->allocated_edges = INITIAL_SIZE;
    graph->edges = ( Edge* ) malloc ( sizeof ( struct Edge )  * INITIAL_SIZE );

    return graph;

}

extern Node* AddNode( Graph* graph, int node_id )
{
    if( FindNodeById ( graph,node_id ) )
    {

        printf( "Node with num %d is already exist\n", node_id );
        return graph->nodes;

    }

    if ( graph->current_nodes >= graph->allocated_nodes )
    {
        graph->allocated_nodes *= 2;
        graph->nodes = ( Node* ) realloc( graph->nodes, sizeof(Node) * graph->allocated_nodes );
        assert( NULL != graph->edges );
    }

    //graph->nodes = ( Node* ) realloc ( graph->nodes, sizeof( struct Node ) * ( 1 + graph->current_nodes ) );
    
    graph->nodes[graph->current_nodes++].id = node_id;
    return graph->nodes;

} 


extern Edge* AddEdge( Graph* graph, int start_id, int end_id )
{

    if( !FindNodeById ( graph,start_id ) )
    {

        printf( "Node with num %d is not exist\n" ,start_id );
        return graph->edges;

    }
    if( !FindNodeById ( graph, end_id ) )
    {

        printf( "Node with num %d is not exist\n" , end_id );
        return graph->edges;

    }

    for ( int i = 0; i < graph->current_edges; i++ )
    {
        if ( graph->edges[i].start_id == start_id && graph->edges[i].end_id == end_id)
        {
            printf("Edge between nodes %d and %d is already exist\n",start_id,end_id);
            return graph->edges;
        }
    }

    if ( graph->current_edges >= graph->allocated_edges )
    {
        graph->allocated_edges *= 2;
        graph->edges = ( Edge* ) realloc( graph->edges, sizeof(Edge) * graph->allocated_edges );
        assert( NULL != graph->edges );
    }

    graph->edges[graph->current_edges].end_id = end_id;
    graph->edges[graph->current_edges++].start_id = start_id;
    return graph->edges;

} // returns pointer to new edge

extern void RemoveEdge( Graph* graph, int start_id, int end_id )
{
    
    if( !FindNodeById ( graph,start_id ) )
    {

        printf( "Node with num %d is not exist\n" ,start_id );
        return;

    }

    if( !FindNodeById( graph, end_id ) )
    {

        printf( "Node with num %d is not exist\n" , end_id );
        return;

    }

    for ( int i = 0; i < graph->current_edges; i++ )
    {
        if ( graph->edges[i].start_id == start_id && graph->edges[i].end_id == end_id)
        {

            graph->current_edges --;
            graph->edges[i].start_id = graph->edges[graph->current_edges].start_id;
            graph->edges[i].end_id = graph->edges[graph->current_edges].end_id;
            
            return;

        }
    }

    printf("Edge between nodes %d and %d are not\n",start_id,end_id);

}

extern void RemoveNode( Graph* graph, int node_id )
{
    
    struct Node* node = FindNodeById ( graph,node_id );

    if( node )
    {

        for ( int i = 0; i < graph->current_edges; i ++ )
        {

            if( graph->edges[i].start_id == node_id )
            {
                RemoveEdge( graph, node_id, graph->edges[i].end_id );
                i--;
            }
            else
            {
                if( ( graph->edges[i].end_id == node_id ) && ( graph->edges[i].end_id != graph->edges[i].start_id ) )
                {

                    RemoveEdge( graph, graph->edges[i].start_id, node_id );
                    i--;

                }
            }

        }

    node->id = graph->nodes[graph->current_nodes - 1].id;
    graph->current_nodes --;
    return;

    }

    printf("Node with num %d is not exist\n",node_id);
}

//extern void MakeRPO( Graph* graph );

extern Node* FindNodeById( Graph* graph, int node_id )
{
    unsigned i = 0;
    assert( NULL != graph );
    for ( i = 0; i < graph->current_nodes; i++ )
    {
        if ( graph->nodes[i].id == node_id )
        {
            return &( graph->nodes[i] );
        }
    }
    return NULL;
}

/*
typedef struct Node
{
    int id; // identifier
    //unsigned rpo_id; // id by RPO
    // here can be additional fields
} Node;

typedef struct Edge
{
    int start_id;
    int end_id;
} Edge;

typedef struct Graph
{
    unsigned current_nodes; // current size of array
    Node *nodes;

    unsigned current_edges; // current size of array
    Edge *edges;
} Graph;

#endif // #define IGRAPH_H_
*/