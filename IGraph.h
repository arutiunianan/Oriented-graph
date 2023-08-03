#ifndef IGRAPH_H_
#define IGRAPH_H_

#include <stdio.h>

enum VisitType
{
    NOT_VISITED, 
    STARTED_VISIT,
    FINISHED_VISIT
};

typedef struct Node
{

    int id; // identifier
    enum VisitType visited; // RPO visit status


} Node;

typedef struct Edge
{

    int start_id;
    int end_id;

} Edge;

typedef struct Graph
{
    
    int root;

    unsigned allocated_nodes; // maximum size of array
    unsigned current_nodes; // current size of array
    Node *nodes;

    unsigned allocated_edges; // maximum size of array
    unsigned current_edges; // current size of array
    Edge *edges;

} Graph;

#endif // #define IGRAPH_H_
