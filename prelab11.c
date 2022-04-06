/*
 * CS1050
 * Spring 2022
 * Prelab 11 
 * by Jim Ries
 */
#include <stdio.h>

// Symbolic Constants
#define FILENAME "DnDMonsterScores.csv"

// Main
int main(void)
{
    FILE * fp;          // FILE pointer
    char name[256];     // Buffer to read in names (re-used to throw away the first line)

    fp = fopen(FILENAME,"r");

    // Only move on if we are able to open the file
    if (NULL!=fp)
    {
        // Throw away the first line
        fgets(name,255,fp);
        printf("Header line was: %s\n",name);

        // Read the important data from the next line
        if (fp && !feof(fp))
        {
            int ac,hp;
            int fieldsread;

            // Only print if we read the 3 fields we expect
            if (3==(fieldsread=fscanf(fp," %[^,],%d,%d,",name,&ac,&hp)))
            {
                printf("\"%s\" : AC=%d,HP=%d\n",name,ac,hp);
            }
            else
            {
                // This message is to help with debugging
                printf("*** Error: Tried to read 3 fields, but read %d fields.\n",fieldsread);
            }
        }

        // If you open a file, you had better close it
        fclose(fp);
    }
    else
    {
        // This message is to help if the file (DnDMonsterScores.csv) is not found or can't be opened.
        printf("*** Error: Tried to open the file, but failed.\n");
    }
}
