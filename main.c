#include <string.h>
#include "Function.c"

int main(int argc, char* argv[])
//int main( void )
{

    if (argc != 2) {
        printf( "Invalid number of args to program." );
        return 0;
    }

    FILE *test;
    //char name[] = "test.txt";
    char name[strlen(argv[1]) + 1];  // Make sure there's enough space
    strcpy( name, argv[1] );
    if ((test = fopen(name, "r")) == NULL)
    {
        printf( "The file could not be opened" );
        return 0;
    }


    char command[11];
    int node_id;
    int start_id, end_id;
    int root;

    struct Graph* graph = NewGraph();

    do{
        fscanf( test, "%s", command ) ;
        if( !strcmp ( command, "ADD_NODE" ) )
        {
            
            fscanf( test, "%d", &node_id );
            graph->nodes = AddNode( graph, node_id);

        }

        else if( !strcmp ( command, "ADD_EDGE" ) )
        {
         
           fscanf( test, "%d %d", &start_id, &end_id );
            graph->edges = AddEdge( graph, start_id, end_id );

        }
        else if( !strcmp ( command, "REMOVE_NODE" ) )
        {

            fscanf( test,"%d", &node_id );
            RemoveNode( graph, node_id );

        }
        else if( !strcmp ( command, "REMOVE_EDGE" ) )
        {  

            fscanf( test, "%d %d", &start_id, &end_id );
            RemoveEdge( graph, start_id, end_id );

        }
        else if( !strcmp ( command, "ROOT" ) )
        {
                              
            fscanf( test, "%d", &root );
            MakeRoot( graph, root );
                            
        }
        else if( !strcmp ( command, "PRINT" ) )
        {
                                
            for( unsigned int i = 0; i < graph->current_nodes; i++ )
                printf( "%d ", graph->nodes[i].id );

            printf( "\n");

            for( unsigned int i = 0; i < graph->current_edges; i++ )
                printf( "%d|%d ", graph->edges[i].start_id, graph->edges[i].end_id );

        }
        else if( !strcmp ( command, "PRINT_PRO" ) )
        {

            int* pro_ides = ( int* ) malloc ( sizeof ( int ) * (graph->current_nodes + 1) ); //pro_ides[0] - current size of array
            pro_ides[0] = 1;

            if( graph->root == -1 )
                printf( "Root is not selected\n");
            else
            {

                MakeRPO( graph, FindNodeById( graph, root), pro_ides );
                for( int i =  pro_ides[0] - 1 ; i > 0; i--)
                    printf( "%d ", pro_ides[i] );
                printf("\n");

            }

        }

    }while(strcmp(command,"END"));

    return 0;        

}
