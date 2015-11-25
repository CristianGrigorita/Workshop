#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char buff[255];
	char firstname[20];
	char name[20];
	char mail[20];
	char grade[5];
	char city[10];
	int buff_counter;
	int word_counter;
	int letter_counter;


	fp = fopen("students.csv", "r");
	while(fscanf(fp, "%s", buff) > 0)
	{
		word_counter = 0;
		letter_counter = 0;
		buff_counter = 0;
		while(*(buff + buff_counter) != 0)
		{
			if(buff[buff_counter] == ';')
			{
				word_counter++;
				letter_counter = 0;
			}
			else{
				if(word_counter == 0)
				{
					firstname[letter_counter] = buff[buff_counter];
					if(buff[buff_counter + 1] == ';')
						firstname[letter_counter + 1] = '\0';
				}
				if(word_counter == 1)
				{
					name[letter_counter] = buff[buff_counter];
					if(buff[buff_counter + 1] == ';')
						name[letter_counter + 1] = '\0';
				}
				if(word_counter == 2)
				{
					mail[letter_counter] = buff[buff_counter];
					if(buff[buff_counter + 1] == ';')
						mail[letter_counter + 1] = '\0';
				}
				if(word_counter == 3)
				{
					grade[letter_counter] = buff[buff_counter];
					if(buff[buff_counter + 1] == ';')
						grade[letter_counter + 1] = '\0';
				}
				if(word_counter == 4)
				{
					city[letter_counter] = buff[buff_counter];
					if(buff[buff_counter + 1] == 0)
						city[letter_counter + 1] = '\0';
				}
				letter_counter++;
			}
			buff_counter++;
		}

		if(strcmp(city,"Cluj") == 0 && atof(grade) > 8.00)
		{
			printf("%s %s\n",firstname,name);
		}
	}
	return 0;
}
