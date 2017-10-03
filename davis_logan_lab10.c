/*
 * Logan Davis
 * CSCI 112, Lab10
 * March 25, 2017
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_FILENAME "element_db.csv"

typedef struct {		//enum struct to declare all key variables used
    int atomic_number;
    char symbol[4];		//char array of size 4
    char name[25];		//char array of size 25
    float atomic_weight;
    char state[25];		//char array of size 25
    char bonding_type[25];	//char array of size 25
    char discovered[25];	//char array of size 25
} element_t;

element_t * find_element( element_t * list, char * symbol );

int main( int argc, char * argv[] )
{
    if ( argc < 2 )		//error checker if no argument is passed in from the command line
    {
        printf("ERROR: Please provide at least one program argument.\n");
        return 0;
    }

    element_t * elements = (element_t *)calloc( 118 , sizeof( element_t ) );
    
    FILE * element_file = fopen( ELEMENT_FILENAME, "r" );
    if ( element_file != NULL )
    {
        char line[100];		//declaration of char array of size 100
        while( fgets(line, 100, element_file ) != NULL )
        {
            // remove newline character from line
            char * nl = strchr( line, '\n' );
            if ( nl )
            {
                *nl = '\0';
            }
            //printf("line = %s\n", line );
            element_t e;
            char * str = strtok( line, "," );
            int col = 0;
            while ( str != NULL )
            {
                switch( col )	//depenending on with case is selected, will be assigning variables from the text file
                {
			case 0:	//converts string argument str to an interger number
				e.atomic_number = atoi( str );
				 break;

			case 1:	//using string copy to copy string pointed by str into the object of e.symbol 
                        	strcpy( e.symbol, str );
                        	break;

			case 2:	//using strcpy to copy string pointed to by str into the object e.symbol 
				strcpy(e.name, str);
				break;

			case 3:	//converts string argument str to a floating point number
				e.atomic_weight = atof( str ); 
				break;

			case 4:	//same as case 1 and 2, but for state varibale
				strcpy(e.state, str);
				break;

			case 5:	//same as case 1 and 2, but for bonding_type variable
				strcpy(e.bonding_type, str);
				break;

			case 6:	//same as case 1 and 2, but for discovered variable
				strcpy(e.discovered, str);
				break;

                }
                str = strtok( NULL, "," );
                col++;
            }
            elements[ e.atomic_number - 1 ] = e;

            
            //printf(" %s\n", elements[ e.atomic_number - 1].symbol );
        }
        fclose( element_file );
    }

    // process program arguments.
    FILE * output_f = NULL;
    int i;
    for(i = 1; i < argc; i++ )
    {
        if ( i == 1 ) // check for filename
        {
            char * dot = strchr( argv[i], '.' );
            if ( dot )
            {
                // this is a filename
                output_f = fopen( argv[i], "w" );
                continue;
            }
        }

        // Look up this element

        element_t * ele = find_element( elements, argv[i] );
        if ( ele )
        {
            
		if(output_f != NULL)	//if called to print in a txt file from command line, go to print_elementsO
		{
			print_elementsO(ele, output_f);
		}
		else			//else go to print_elements
		{
			print_elements(ele);
		}
        }
	else
	{
		printf("Warning: No such element: %s\n", argv[i]);//if it is not a valid element in the excel file, will throw error statement with the incorrect input
	}
    }
	if(output_f != NULL) //without this, segmentation fault when not printed to an external txt file
	{   
		 fclose(output_f);	//closes the stream.All buffers flushed
	}
	
    return 0;
}

element_t * find_element( element_t * list, char * symbol )
{
    int i;
    for( i = 0; i < 118; i++ )
    {
        if ( strcmp( list[i].symbol, symbol ) == 0 )
        {
            element_t * result = &list[i];
            return result;
        }
    }
    return NULL;
}

void print_elementsO(element_t *e, FILE *output_f) //output layout in the new txt file created
{
	fprintf(output_f, "---------------\n");
	//main layout print fucntion with pointers to the elments information entered, but is sent to the new txt file
	fprintf(output_f, "| %d\t%.4f\n| %s\t%s\n| %s\n| %s\n| Found: %s ", e->atomic_number, e->atomic_weight, e->symbol, e->name, e->state, e->bonding_type, e->discovered);
	fprintf(output_f, "\n---------------\n");
} 

void print_elements(element_t *e, FILE *output_f)//output layout from values entered from command line
{
	printf("---------------\n");
	//main layout print fucntion with pointers to the elements information enetered
	printf("| %d\t%.4f\n| %s\t%s\n| %s\n| %s\n| Found: %s ", e->atomic_number, e->atomic_weight, e->symbol, e->name, e->state, e->bonding_type, e->discovered);
	printf("\n---------------\n");
}
