#include <stdio.h>

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
int swimDays(double lakeTemps[365][6], int column){
	int i, j, daysSwimmable, swimmingDays;
	for (j = 0; j < 6; j++){
		daysSwimmable = 0;
		for (i = 0; i < 365; i++){
			if (lakeTemps[i][column] > 20.0){
				daysSwimmable++;
			}
			swimmingDays = daysSwimmable;
		}
	}

	return swimmingDays;
}

/*Determines the amount of days the lake is frozen (when lake temperature is below 0 degrees Celsius)*/
int frozenDays(double lakeTemps[365][6], int column){
	int i, daysFrozen, frozen;
		daysFrozen = 0;
		
	for (i = 0; i < 365; i++){
		if (lakeTemps[i][column] < 0.0){
			daysFrozen+=1;
		}
		frozen = daysFrozen;
	}

	return frozen;
}

/*Determines the summer water surface average of each lake*/
double summerAverage(double lakeTemps[365][6], int column){
	int i;
	double summerAvg, count = 0.0;
	
	for (i = 171; i < 265; i++){
		count += lakeTemps[i][column];
	}
	summerAvg = count/(265-171);

	return summerAvg;
}

/*Determines the winter water surface average of each lake*/
double winterAverage(double lakeTemps[365][6], int column){
	int i;
	double winterAvg, count = 0;
	
	for (i = 0; i < 79; i++){
		count += lakeTemps[i][column];
	}
	for (i = 354; i < 365; i++){
		count += lakeTemps[i][column];
	}
	
	winterAvg = count/(79+(365-354));
	return winterAvg;
}

/*Prints the warmest lake*/
int warmestLakes(double lakeTemps[365][6]){
	int i, j, testValue, warmest;
	double warmestTemps[6];

	for (j = 0; j < 6; j++){
	
		/*Finds and stores warmest temperature of each lake*/
		testValue = lakeTemps[0][j];
		for (i = 0; i < 365; i++){
			if (testValue < lakeTemps[i][j]){
				testValue = lakeTemps[i][j];
				warmestTemps[j] = testValue;
			}
		}
	}

	/*Finds the lake with the highest temperature*/
	for (j = 0; j < 6; j++){
		for (i = 1; i < 6; i++){
			if (warmestTemps[j] < warmestTemps[i]){
				warmest = i;
			}
		}
	}

	/*Prints which lake is the warmest and displays the highest temperature*/
	switch (warmest){
		case 0:
			printf("\nLake Superior had the highest temperature of all the lakes of %0.2lf", warmestTemps[warmest]);
			break;
		case 1:
			printf("\nLake Michigan had the highest temperature of all the lakes of %0.2lf", warmestTemps[warmest]);
			break;
		case 2:
			printf("\nLake Huron had the highest temperature of all the lakes of %0.2lf", warmestTemps[warmest]);
			break;
		case 3:
			printf("\nLake Erie had the highest temperature of all the lakes of %0.2lf", warmestTemps[warmest]);
			break;
		case 4:
			printf("\nLake Ontario had the highest temperature of all the lakes of %0.2lf", warmestTemps[warmest]);
			break;
		case 5:
			printf("\nLake St.Clair had the highest temperature of all the lakes of %0.2lf", warmestTemps[warmest]);
			break;
		default:
			printf("Error\n");
			break;
	}
}

/*Prints the coldest lake*/
int coldestLakes(double lakeTemps[365][6]){
	int i, j, testValue, coldest;
	double coldestTemps[6];

	for (j = 0; j < 6; j++){
	
		/*Finds and stores coldest temperature of each lake*/
		testValue = lakeTemps[0][j];
		for (i = 0; i < 365; i++){
			if (testValue > lakeTemps[i][j]){
				testValue = lakeTemps[i][j];
				coldestTemps[j] = testValue;
			}
		}
	}

	/*Finds the lake with the lowest temperature*/
	for (j = 0; j < 6; j++){
		for (i = 1; i < 6; i++){
			if (coldestTemps[j] > coldestTemps[i]){
				coldest = i;
			}
		}
	}

	/*Prints which lake is the coldest and displays the lowest temperature*/
	switch (coldest){
		case 0:
			printf("\nLake Superior had the lowest temperature of all the lakes of %0.2lf", coldestTemps[coldest]);
			break;
		case 1:
			printf("\nLake Michigan had the lowest temperature of all the lakes of %0.2lf", coldestTemps[coldest]);
			break;
		case 2:
			printf("\nLake Huron had the lowest temperature of all the lakes of %0.2lf", coldestTemps[coldest]);
			break;
		case 3:
			printf("\nLake Erie had the lowest temperature of all the lakes of %0.2lf", coldestTemps[coldest]);
			break;
		case 4:
			printf("\nLake Ontario had the lowest temperature of all the lakes of %0.2lf", coldestTemps[coldest]);
			break;
		case 5:
			printf("\nLake St.Clair had the lowest temperature of all the lakes of %0.2lf", coldestTemps[coldest]);
			break;
		default:
			printf("Error\n");
			break;
	}
}

/*Finds and prints the warmest days of each lake*/
double warmestDay(double lakeTemps[365][6], int column){
	int i;
	double warmestTemps, testValue;

	/*Finds and stores warmest temperature of each lake*/
	testValue = lakeTemps[0][column];
	for (i = 0; i < 365; i++){
		if (testValue < lakeTemps[i][column]){
			testValue = lakeTemps[i][column];
			warmestTemps = testValue;
		}
	}

	/*Checking the warmest temperatures against the lakeTemps array to determine the row/day which is then sent to the dateFinder to display the date of occurence*/
	printf("Experienced warmest temperature of %0.2lf degrees Celsius on:\n", warmestTemps);
	for (i = 0; i < 365; i++){
		if (warmestTemps == lakeTemps[i][column]){
			dateFinder(i);
		}
	}
}

/*Finds and prints the coldest days of each lake*/ 
double coldestDay(double lakeTemps[365][6], int column){
	int i;
	double coldestTemps, testValue;

	/*Finds and stores coldest temperature of each lake*/
	testValue = lakeTemps[0][column];
	for (i = 0; i < 365; i++){
		if (testValue > lakeTemps[i][column]){
			testValue = lakeTemps[i][column];
			coldestTemps = testValue;
		}
	}

	/*Checking the coldest temperatures against the lakeTemps array to determine the row/day which is then sent to the dateFinder to display the date of occurence*/
	printf("Experienced coldest temperature of %0.2lf degrees Celsius on:\n", coldestTemps);
	for (i = 0; i < 365; i++){
		if (coldestTemps == lakeTemps[i][column]){
			dateFinder(i);
		}
	}
}

/*Determines and prints whether a lake is above or below the average temperature of all the lakes*/
int aboveOrBelow (double lakeTemps[365][6], int column){
	int i,j;
	double averageTemp = 0.0, averagedLakeTemp = 0.0;

	/*Finding the average temperature of all the lakes*/
	for (j = 0; j < 6; j++){
		for (i = 0; i < 365; i++){
			averageTemp += lakeTemps[i][j];
		}
	}

	averageTemp /= i;

	/*Determining if the average temperature of the lake is above or below the average of all lakes*/
	for (i = 0; i < 365; i++){
		averagedLakeTemp += lakeTemps[i][column];
	}

	averagedLakeTemp /= i;

	if (averagedLakeTemp > averageTemp){
		printf("The lake is above the average temperature of all the lakes, of %0.2lf degrees Celsius\n", averagedLakeTemp);
	}
	else{
		printf("The lake is below the average temperature of all the lakes, of %0.2lf degrees Celsius\n", averagedLakeTemp);
	}
}

/*Finds the average temperature of each lake*/
double averageTemp(double lakeTemps[365][6], int column){
	int i,j;
	double averagedTemps;

	/*Finding the average temperature of each column and assigning them to their resepective average variable*/
	averagedTemps = 0;
	for (i = 0; i < 365; i++){
		averagedTemps += lakeTemps[i][column];
	}
	averagedTemps /= i;

	return averagedTemps;	
}

/*Main function*/
int main(void){
	int i, j;
	double table[365][8], lakeTemps[365][6];

	/*Opening the temperature text file with column headers removed*/
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
	printf("**NOTICE**: ALL DATES ARE PRESENTED IN DAY/MONTH/YEAR FORMAT\n");
	
	/*Printing out lake specific data*/
	for (j = 0; j < 6; j++){
		switch(j){
			case 0:
				printf("\nData for Lake Superior:\n");
				printf("Average temperature: %0.2lf degrees Celsius\n", averageTemp(lakeTemps, j));
				printf("Average winter temperature: %0.2lf degrees Celsius\n", winterAverage(lakeTemps, j));
				printf("Average summer temperature: %0.2lf degrees Celsius\n", summerAverage(lakeTemps, j));
				printf("Days frozen: %d\n", frozenDays(lakeTemps, j));
				printf("Swimmable days: %d\n", swimDays(lakeTemps, j));
				aboveOrBelow(lakeTemps, j);
				coldestDay(lakeTemps, j);
				warmestDay(lakeTemps, j);
				break;
			case 1:
				printf("\nData for Lake Michigan:\n");
				printf("Average temperature: %0.2lf degrees Celsius\n", averageTemp(lakeTemps, j));
				printf("Average winter temperature: %0.2lf degrees Celsius\n", winterAverage(lakeTemps, j));
				printf("Average summer temperature: %0.2lf degrees Celsius\n", summerAverage(lakeTemps, j));
				printf("Days frozen: %d\n", frozenDays(lakeTemps, j));
				printf("Swimmable days: %d\n", swimDays(lakeTemps, j));
				aboveOrBelow(lakeTemps, j);
				coldestDay(lakeTemps, j);
				warmestDay(lakeTemps, j);
				break;
			case 2:
				printf("\nData for Lake Huron:\n");
				printf("Average temperature: %0.2lf degrees Celsius\n", averageTemp(lakeTemps, j));
				printf("Average winter temperature: %0.2lf degrees Celsius\n", winterAverage(lakeTemps, j));
				printf("Average summer temperature: %0.2lf degrees Celsius\n", summerAverage(lakeTemps, j));
				printf("Days frozen: %d\n", frozenDays(lakeTemps, j));
				printf("Swimmable days: %d\n", swimDays(lakeTemps, j));
				aboveOrBelow(lakeTemps, j);
				coldestDay(lakeTemps, j);
				warmestDay(lakeTemps, j);
				break;
			case 3:
				printf("\nData for Lake Erie:\n");
				printf("Average temperature: %0.2lf degrees Celsius\n", averageTemp(lakeTemps, j));
				printf("Average winter temperature: %0.2lf degrees Celsius\n", winterAverage(lakeTemps, j));
				printf("Average summer temperature: %0.2lf degrees Celsius\n", summerAverage(lakeTemps, j));
				printf("Days frozen: %d\n", frozenDays(lakeTemps, j));
				printf("Swimmable days: %d\n", swimDays(lakeTemps, j));
				aboveOrBelow(lakeTemps, j);
				coldestDay(lakeTemps, j);
				warmestDay(lakeTemps, j);
				break;
			case 4:
				printf("\nData for Lake Ontario:\n");
				printf("Average temperature: %0.2lf degrees Celsius\n", averageTemp(lakeTemps, j));
				printf("Average winter temperature: %0.2lf degrees Celsius\n", winterAverage(lakeTemps, j));
				printf("Average summer temperature: %0.2lf degrees Celsius\n", summerAverage(lakeTemps, j));
				printf("Days frozen: %d\n", frozenDays(lakeTemps, j));
				printf("Swimmable days: %d\n", swimDays(lakeTemps, j));
				aboveOrBelow(lakeTemps, j);
				coldestDay(lakeTemps, j);
				warmestDay(lakeTemps, j);
				break;
			case 5:
				printf("\nData for Lake St.Clair:\n");
				printf("Average temperature: %0.2lf degrees Celsius\n", averageTemp(lakeTemps, j));
				printf("Average winter temperature: %0.2lf degrees Celsius\n", winterAverage(lakeTemps, j));
				printf("Average summer temperature: %0.2lf degrees Celsius\n", summerAverage(lakeTemps, j));
				printf("Days frozen: %d\n", frozenDays(lakeTemps, j));
				printf("Swimmable days: %d\n", swimDays(lakeTemps, j));
				aboveOrBelow(lakeTemps, j);
				coldestDay(lakeTemps, j);
				warmestDay(lakeTemps, j);
				break;
			default:
				printf("Error\n");
				break;
		}
	}

	printf("\n\nGeneral information:\n");
	coldestLakes(lakeTemps);
	warmestLakes(lakeTemps);

}

