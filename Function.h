#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "IGraph.h"

Graph* NewGraph( void ); // returns pointer to graph
Node* AddNode( Graph* graph, int node_id ); // returns pointer to new node
void RemoveNode( Graph* graph, int node_id );
Edge* AddEdge( Graph* graph, int start_id, int end_id ); // returns pointer to new edge
void RemoveEdge( Graph* graph, int start_id, int end_id );
void MakeRoot( Graph* graph, int root );
void MakeRPO( Graph* graph, Node* current_node, int* pro_ides );
static Node* FindNodeById( Graph* graph, int node_id );

#endif // #define FUNCTION_H_