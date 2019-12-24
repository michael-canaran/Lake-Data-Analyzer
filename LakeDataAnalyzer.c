#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Defining a lake structure
typedef struct Lake{
	char name[30];
	double averageTemp;
	bool coldest;
	bool warmest;
	bool aboveorBelowAverage;
};

//Finds and prints the warmest days of each lake
double warmestDay(double lakeTemps[365][6]){

}

//Finds and prints the coldest days of each lake 
double coldestDay(double lakeTemps[365][6]){

}

//Initalizes a calendar array for displaying dates
char *calendar(void){
	int day, actualDay;
	char calendar[365][20], calendarDay[20];

	//Storing date formatting in the array for easy output
	for (day = 0; day < 365; day++){
		//January
		if (0 <= day && day <= 30){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/01/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//February
		if (31 <= day && day <= 58){
			actualDay = day - 30;
			sprintf(calendarDay, "%d/02/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//March
		if (59 <= day && day <= 89){
			actualDay = day - 58;
			sprintf(calendarDay, "%d/03/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//April
		if (90 <= day && day <= 119){
			actualDay = day - 89;
			sprintf(calendarDay, "%d/04/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//May
		if (120 <= day && day <= 150){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/05/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//June
		if (151 <= day && day <= 180){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/06/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//July
		if (181 <= day && day <= 211){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/07/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//August
		if (212 <= day && day <= 242){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/08/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//September
		if (243 <= day && day <= 272){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/09/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//October
		if (273 <= day && day <= 303){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/10/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//November
		if (304 <= day && day <= 333){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/11/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

		//December
		if (334 <= day && day <= 364){
			actualDay = day + 1;
			sprintf(calendarDay, "%d/12/2017", actualDay);
			strcpy(calendar[day][0], calendarDay);
		}

	}

	return calendar;
}

//Determines whether a lake is above or below the average temperature of all the lakes
bool *aboveOrBelow (double averagedTemps[6]){
	int i;
	double averageTemp = 0;
	bool aboveOrBelow[6];

	//Finding the average temperature of all the lakes
	for (i = 0; i < 6; i++){
		averageTemp += averagedTemps[i];
	}

	averageTemp /= 6;

	//Determining if the average temperature of each lake is above or below the average of all lakes
	for (i = 0; i < 6; i++){
			if (averagedTemps[i] > averageTemp){
				aboveOrBelow[i] = true;
			}
			else{
				aboveOrBelow[i] = false;
			}
	}

	return aboveOrBelow;

}

//Determines the warmest lake
bool *warmestLakes(double averagedTemps[6]){
	int i,j;
	bool warmest[6];

	for (i = 0; i < 6; i++){
		for (j = 5; j >= 0; j--){
			if (averagedTemps[i] > averagedTemps[j]){
				warmest[i] = true;
			}
			else{
				warmest[i] = false;
			}
		}
	}

	return warmest;
}

//Determines the coldest lake
bool *coldestLakes(double averagedTemps[6]){
	int i,j;
	bool coldest[6];

	for (i = 0; i < 6; i++){
		for (j = 5; j >= 0; j--){
			if (averagedTemps[i] < averagedTemps[j]){
				coldest[i] = true;
			}
			else{
				coldest[i] = false;
			}
		}
	}

	return coldest;

}

//Finds the average temperature of each lake
double *averageTemp(double lakeTemps[365][6]){
	int i,j;
	double averagedTemps[6];

	//Finding the average temperature of each column and assigning them to their resepective average variable
	for (j = 0; j < 6; j++){
		averagedTemps[j] = 0;
		for (i = 0; i < 365; i++){
			averagedTemps[j] += lakeTemps[i][j];
		}
		averagedTemps[j] /= i;
	}

	return averagedTemps;	
}

//Main function
int main(void){
	int i,j;
	double table[365][8], lakeTemps[365][6], *averagedTemps;
	bool *coldestLake, *warmestLake, *aboveOrBelowAverage;

	FILE*temps;
	temps = fopen("temps.txt","r");
	//Index the temperature file and sort the data into an array
	for (i = 0; i < 365; i++){
		for (j = 0; j < 8; j++){
			fscanf(temps,"%lf",&table[i][j]);
		}
	}
	
	//Removes the first 2 columns of data and puts the remaining 6 columns into a new array
	//Column 1: Lake Superior
	//Column 2: Lake Michigan
	//Column 3: Lake Huron 
	//Column 4: Lake Erie
	//Column 5: Lake Ontario
	//Column 6: Lake St. Clair
	for (i = 0; i < 365; i++){
		for (j = 2; j < 8; j++){
			lakeTemps[i][j-2] = table[i][j];
		}
	}

	fclose(temps);
	printf("**NOTICE**: ALL DATES ARE PRESENTED IN DAY/MONTH/YEAR FORMAT\n\n");
	
	//Finding average temperature of each lake
	averagedTemps = averageTemp(lakeTemps);
	coldestLake = coldestLakes(averagedTemps);
	warmestLake = warmestLakes(averagedTemps);
	aboveOrBelowAverage = aboveOrBelow(averagedTemps);
	coldestDay(lakeTemps);
	warmestDay(lakeTemps);

}
