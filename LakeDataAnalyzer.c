#include <stdio.h>
#include <stdbool.h>

/*Defining a lake structure*/
struct Lake{
	char name[30];
	double averageTemp;
	bool aboveorBelowAverage;
	bool coldest;
	bool warmest;
	double winterAvg;
	double summerAvg;
	int daysFrozen;
	int daysSwimmable;
};

/*Finds the date of occurence when given a row number, i*/
int dateFinder(int i){
	int month, day;
	char date[20];

	/*January*/
	if (0 <= i && i <= 30){
		month = 1;
		day = i+1;
		}
	else{
		/*Februrary*/
		if (31 <= i && i <= 58){
			month = 2;
			day = i-30;
			}
		else{
			/*March*/
			if (59 <= i && i <= 89){
				month = 3;
				day = i-58;
				}
			else{
				/*April*/
				if (90 <= i && i <= 119){
					month = 4;
					day = i-89;
					}
				else{
					/*May*/
					if (120 <= i && i <= 150){
						month = 5;
						day = i-119;
						}
					else{
						/*June*/
						if (151 <= i && i <= 180){
							month = 6;
							day = i-150;
							}
						else{
							/*July*/
							if (181 <= i && i <= 211){
								month = 7;
								day = i-180;
								}
						else{
							/*August*/
							if (212 <= i && i <= 242){
								month = 8; 
								day = i-211;
								}
							else{
								/*September*/
								if (243 <= i && i <= 272){
									month = 9;
									day = i-242;
									}
								else{
									/*October*/
									if (273 <= i && i <= 303){
										month = 10; 
										day = i-272;
										}
								else{
									/*November*/
									if (304 <= i && i <= 333){
										month = 11;
										day = i-303;
										}
									else{
										/*December*/
										if (334 <= i && i <= 364){
											month = 12;
											day = i-333;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	}
printf("%0.2d/%0.2d/2017\n",day,month);
}

/*Determines the amount of swimmable days (when lake temperature is over 20 degrees Celsius)*/
int swimDays(double lakeTemps[365][6]){
	int i, j, daysSwimmable;
	for (j = 0; j < 6; j++){
		daysSwimmable = 0;
		for (i = 0; i < 365; i++){
			if (lakeTemps[i][j] > 20.0){
				daysSwimmable++;
			}
		}
	}

	return daysSwimmable;
}

/*Determines the amount of days the lake is frozen (when lake temperature is below 0 degrees Celsius)*/
int frozenDays(double lakeTemps[365][6]){
	int i, j, daysFrozen;
	for (j = 0; j < 6; j++){
		daysFrozen = 0;
		for (i = 0; i < 365; i++){
			if (lakeTemps[i][j] < 0.0){
				daysFrozen++;
			}
		}
	}

	return daysFrozen;
}

/*Determines the summer water surface average of each lake*/
double *summerAverage(double lakeTemps[365][6]){
	int i,j;
	double summerAvg[6], count = 0;
	
	for (j = 0; j < 6; j++){
		for (i = 171; i < 265; i++){
			count += lakeTemps[i][j];
		}
		summerAvg[j] = count/(265-171);
	}

	return summerAvg;
}

/*Determines the winter water surface average of each lake*/
double *winterAverage(double lakeTemps[365][6]){
	int i,j;
	double winterAvg[6], count = 0;
	
	for (j = 0; j < 6; j++){
		for (i = 0; i < 79; i++){
			count += lakeTemps[i][j];
		}
		for (i = 354; i < 365; i++){
			count += lakeTemps[i][j];
		}
		winterAvg[j] = count/(79+(365-354));
	}

	return winterAvg;
}

/*Determines the warmest lake*/
bool *warmestLakes(double *warmestTemps){
	int i,j,testValue;
	bool warmest[6];

	/*Initalize each array cell as false*/
	for (i = 0; i < 6; i++){
		warmest[i] = false;
	}

	for (j = 0; j < 6; j++){
		for (i = 5; i >= 0; i--){
			testValue = warmestTemps[0];
			if (testValue > warmestTemps[i]){
				warmest[i] = true;
			}
		}
	}

	return warmest;
}

/*Determines the coldest lake*/
bool *coldestLakes(double *coldestTemps){
	int i,j,testValue;
	bool coldest[6];

	/*Initalize each array cell as false*/
	for (i = 0; i < 6; i++){
		coldest[i] = false;
	}

	for (j = 0; j < 6; j++){
		for (i = 5; i >= 0; i--){
			testValue = coldestTemps[0];
			if (testValue > coldestTemps[i]){
				coldest[i] = true;
			}
		}
	}

	return coldest;
}

double *warmestDay(double lakeTemps[365][6]){
	int i,j,k;
	double warmestTemps[6], testValue;

	/*Finds and stores warmest temperature of each lake in an array*/
	for (j = 0; j < 6; j++){
		testValue = lakeTemps[0][j];
		for (i = 0; i < 365; i++){
			if (testValue < lakeTemps[i][j]){
				testValue = lakeTemps[i][j];
				k = j;
				warmestTemps[k] = testValue;
			}
		}
	}

	/*Checking the warmest temperatures against the lakeTemps array to determine the row/day which is then checked against the CalendarArray to display the date of occurence*/
	for (j = 0; j < 6; j++){
		switch (j){
			case 0:
				printf("\nLake Superior was at its warmest temperature of %0.2lf degrees Celsius on the following dates: \n", warmestTemps[j]);
				break;
			case 1:
				printf("\nLake Michigan was at its warmest of %0.2lf degrees Celsius on the following dates: \n", warmestTemps[j]);
				break;
			case 2:
				printf("\nLake Huron was at its warmest of %0.2lf degrees Celsius on the following dates: \n", warmestTemps[j]);
				break;
			case 3:
				printf("\nLake Erie was at its warmest of %0.2lf degrees Celsius on the following dates: \n", warmestTemps[j]);
				break;
			case 4:
				printf("\nLake Ontario was at its warmest of %0.2lf degrees Celsius on the following dates: \n", warmestTemps[j]);
				break;
			case 5:
				printf("\nLake St. Clair was at its warmest of %0.2lf degrees Celsius on the following dates: \n", warmestTemps[j]);
				break;
			default:
				printf("Error\n");
				break;
		}
		for (i = 0; i < 365; i++){
			if (warmestTemps[j] == lakeTemps[i][j]){
				dateFinder(i);
			}
		}
	}

	return warmestTemps;
}

/*Finds and prints the coldest days of each lake*/ 
double *coldestDay(double lakeTemps[365][6]){
	int i,j,k;
	double coldestTemps[6], testValue;

	/*Finds and stores coldest temperature of each lake in an array*/
	for (j = 0; j < 6; j++){
		testValue = lakeTemps[0][j];
		for (i = 0; i < 365; i++){
			if (testValue > lakeTemps[i][j]){
				testValue = lakeTemps[i][j];
				k = j;
				coldestTemps[k] = testValue;
			}
		}
	}

	/*Checking the coldest temperatures against the lakeTemps array to determine the row/day which is then checked against the CalendarArray to display the date of occurence*/
	for (j = 0; j < 6; j++){
		switch (j){
			case 0:
				printf("\nLake Superior was at its coldest of %0.2lf degrees Celsius on the following dates: \n", coldestTemps[j]);
				break;
			case 1:
				printf("\nLake Michigan was at its coldest of %0.2lf degrees Celsius on the following dates: \n", coldestTemps[j]);
				break;
			case 2:
				printf("\nLake Huron was at its coldest of %0.2lf degrees Celsius on the following dates: \n", coldestTemps[j]);
				break;
			case 3:
				printf("\nLake Erie was at its coldest of %0.2lf degrees Celsius on the following dates: \n", coldestTemps[j]);
				break;
			case 4:
				printf("\nLake Ontario was at its coldest of %0.2lf degrees Celsius on the following dates: \n", coldestTemps[j]);
				break;
			case 5:
				printf("\nLake St. Clair was at its coldest of %0.2lf degrees Celsius on the following dates: \n", coldestTemps[j]);
				break;
			default:
				printf("Error\n");
				break;
		}
		for (i = 0; i < 365; i++){
			if (coldestTemps[j] == lakeTemps[i][j]){
				dateFinder(i);
			}
		}
	}
	
	return coldestTemps;
}

/*Determines whether a lake is above or below the average temperature of all the lakes*/
bool *aboveOrBelow (double averagedTemps[6]){
	int i;
	double averageTemp = 0;
	bool aboveOrBelow[6];

	/*Finding the average temperature of all the lakes*/
	for (i = 0; i < 6; i++){
		averageTemp += averagedTemps[i];
	}

	averageTemp /= 6;

	/*Determining if the average temperature of each lake is above or below the average of all lakes*/
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

/*Finds the average temperature of each lake*/
double *averageTemp(double lakeTemps[365][6]){
	int i,j;
	double averagedTemps[6];

	/*Finding the average temperature of each column and assigning them to their resepective average variable*/
	for (j = 0; j < 6; j++){
		averagedTemps[j] = 0;
		for (i = 0; i < 365; i++){
			averagedTemps[j] += lakeTemps[i][j];
		}
		averagedTemps[j] /= i;
	}

	return averagedTemps;	
}

/*Main function*/
int main(void){
	int i,j;
	double table[365][8], lakeTemps[365][6], *averagedTemps, *warmestTemps, *coldestTemps, *winterAvg, *summerAvg;
	bool *coldestLake, *warmestLake, *aboveOrBelowAverage;

	FILE*temps;
	temps = fopen("temps.txt","r");
	/*Index the temperature file and sort the data into an array*/
	for (i = 0; i < 365; i++){
		for (j = 0; j < 8; j++){
			fscanf(temps,"%lf",&table[i][j]);
		}
	}
	
	/*Removes the first 2 columns of data and puts the remaining 6 columns into a new array*/
	/*Column 1: Lake Superior*/
	/*Column 2: Lake Michigan*/
	/*Column 3: Lake Huron*/
	/*Column 4: Lake Erie*/
	/*Column 5: Lake Ontario*/
	/*Column 6: Lake St. Clair*/
	for (i = 0; i < 365; i++){
		for (j = 2; j < 8; j++){
			lakeTemps[i][j-2] = table[i][j];
		}
	}

	fclose(temps);
	printf("**NOTICE**: ALL DATES ARE PRESENTED IN DAY/MONTH/YEAR FORMAT\n\n");
	
	/*Function calls*/
	averagedTemps = averageTemp(lakeTemps);
	aboveOrBelowAverage = aboveOrBelow(averagedTemps);
	coldestTemps = coldestDay(lakeTemps);
	warmestTemps = warmestDay(lakeTemps);
	coldestLake = coldestLakes(coldestTemps);
	warmestLake = warmestLakes(warmestTemps);
	winterAvg = winterAverage(lakeTemps);
	summerAvg = summerAverage(lakeTemps);
}
