#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[1000];
	int len;
	int i, j;
	int found_start = 0;
	int found_valid_orf = 0;

	printf("Enter the DNA sequence: ");
	scanf("%s", seq);
 	len = strlen(seq);

	for (i = 0; i <= len - 3; i++)
	{
		if (seq[i] == 'A' && seq[i+1] == 'T' && seq[i+2] == 'G') 
		{
			found_start = 1;
			for (j = i + 3; j <= len - 3; j += 3)
			{
				if ((seq[j] == 'T' && seq[j+1] == 'A' && seq[j+2] == 'A') || (seq[j] == 'T' && seq[j+1] == 'A' && seq[j+2] == 'G') || (seq[j] == 'T' && seq[j+1] == 'G' && seq[j+2] == 'A'))
				{
					printf("Valid ORF found. Start: %d, End: %d\n", i, j);
					found_valid_orf = 1;
				}
			}
		}
	}
}
