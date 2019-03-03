
#include "sort.h"



void sortiere(int a[], int N)
{
	int j = 0;
	int einzusortieren = 0;

	//Sortierung
	for (int i = 0; i <= N-1; i++)
	{
		//Ganzzahl einzusortieren a[i]
		einzusortieren = a[i];
		//Positive Ganzzahl j:=i
		j = i;

		while (j > 0 && a[j - 1] > einzusortieren) {
			a[j] = a[j - 1];
			j = j - 1;
		}

		a[j] = einzusortieren;
	}

}
