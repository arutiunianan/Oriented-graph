#include <string.h>
#include "Function.c"

int main(void)
{
    
    char command[11];
    int node_id;
    int start_id, end_id;

    struct Graph* graph = NewGraph();

    do{
        scanf( "%s", command ) ;
        if( !strcmp ( command, "ADD_NODE" ) )
        {
            
            scanf( "%d", &node_id );
            graph->nodes = AddNode( graph, node_id);

        }

        else
        {
            if( !strcmp ( command, "ADD_EDGE" ) )
            {

                scanf( "%d %d", &start_id, &end_id );
                graph->edges = AddEdge( graph, start_id, end_id );

            }
                if( !strcmp ( command, "REMOVE_NODE" ) )
                {

                    scanf( "%d", &node_id );
                    RemoveNode( graph, node_id );

                }
                else
                {

                    if( !strcmp ( command, "REMOVE_EDGE" ) )
                    {  

                        scanf( "%d %d", &start_id, &end_id );
                        RemoveEdge( graph, start_id, end_id );

                    }
                    else
                    {
                        if( !strcmp ( command, "ROOT" ) )
                        {
                              
                            scanf( "%d", &graph->root );
                            
                        }
                        else
                        {
                            if( !strcmp ( command, "PRINT" ) )
                            {
                                
                                for( int i = 0; i < graph->current_nodes; i++ )
                                    printf( "%d ", graph->nodes[i].id );

                                printf( "\n");

                                for( int i = 0; i < graph->current_edges; i++ )
                                    printf( "%d|%d ", graph->edges[i].start_id, graph->edges[i].end_id );

                            }
                            
                        }

                    }

                }

        }

    }while(strcmp(command,"END"));
            

}