#include <stdio.h>

/*Finding the number of days each lake is frozen*/ 
double frozen(double table[365][8]){
	int i,j,days;

	//CHECKING FOR DAYS BELOW 0
	for (j = 2; j < 8; j++){
		days = 0; 
		for (i = 0; i < 365; i++){
			if (table[i][j] < 0){
				days += 1;
			}
		}
		switch (j){
			case 2:
				printf("Lake Superior was frozen for %d day(s).\n",days);
				break;
			case 3:
				printf("Lake Michigan was frozen for %d day(s).\n",days);
				break;
			case 4:
				printf("Lake Huron was frozen for %d day(s).\n",days);
				break;
			case 5:
				printf("Lake Erie was frozen for %d day(s).\n",days);
				break;
			case 6:
				printf("Lake Ontario was frozen for %d day(s).\n",days);
				break;
			case 7:
				printf("Lake St. Clair was frozen for %d day(s).\n",days);
				break;
			default:
				printf("Error\n");
				break; 
		}
	}
}

/*Finding days that can be considered swimmable for each lake (where the temperature is greater than 20 degrees Celsius*/
double swimmable(double table[365][8]){
	int i,j,days;

	//CHECKING FOR DAYS OVER 20
	for (j = 2; j < 8; j++){
		days = 0; 
		for (i = 0; i < 365; i++){
			if (table[i][j] > 20){
				days += 1;
			}
		}
		switch (j){
			case 2:
				printf("Lake Superior had %d swimmable days.\n",days);
				break;
			case 3:
				printf("Lake Michigan had %d swimmable days.\n",days);
				break;
			case 4:
				printf("Lake Huron had %d swimmable days.\n",days);
				break;
			case 5:
				printf("Lake Erie had %d swimmable days.\n",days);
				break;
			case 6:
				printf("Lake Ontario had %d swimmable days.\n",days);
				break;
			case 7:
				printf("Lake St. Clair had %d swimmable days.\n",days);
				break;
			default:
				printf("Error\n");
				break; 
		}
	}
	frozen(table);
}

/*Finding the average temperature of each lake during the winter*/
double winter(double table[365][8]){
	int i,j,k,z=0;
	double winteraverage[6],test = winteraverage[0],wintersorted[6],h;
	
	//FINDING WINTER AVERAGE FOR EACH LAKE
	winteraverage[z] = 0; 
	for (j = 2; j < 8; j++){
		k = -1; 
		for (i = 0; i < 79; i++){
			z = j-2;
			k+=1;
			winteraverage[z] += table[i][j];
		}
		for (i = 354; i < 365; i++){
			z = j-2;
			k+=1;
			winteraverage[z] += table[i][j];
		}
	}
	for (j = 0; j < 6; j++){
		winteraverage[j] /= k;
	}
	//TRANSFERRING DATA TO ARRAY TO BE SORTED
	for (j = 0; j < 6; j++){
		wintersorted[j] = winteraverage[j];
	}

	//SORTING
	for (j = 0; j < 6; j++){
		for (i = j+1; i < 6; i++){
			if (wintersorted[j] < wintersorted[i]){
				h = wintersorted[j];
				wintersorted[j] = wintersorted[i];
				wintersorted[i] = h;
			}
		}
	}

	for (j = 0; j < 6; j++){
		for (i = 0; i < 6; i++){
			if (winteraverage[i] == wintersorted[j]){
				switch (i){
					case 0:
						printf("Lake Superior had a winter water surface average temperature of %0.2lf degrees Celsisus.\n",winteraverage[i]);
						break;
					case 1:
						printf("Lake Michigan had a winter water surface average temperature of %0.2lf degrees Celsisus.\n",winteraverage[i]);
						break;
					case 2:
						printf("Lake Huron had a winter water surface average temperature of %0.2lf degrees Celsisus.\n",winteraverage[i]);
						break;
					case 3:
						printf("Lake Erie had a winter water surface average temperature of %0.2lf degrees Celsisus.\n",winteraverage[i]);
						break;	
					case 4:
						printf("Lake Ontario had a winter water surface average temperature of %0.2lf degrees Celsisus.\n",winteraverage[i]);
						break;
					case 5:
						printf("Lake St. Clair had a winter water surface average temperature of %0.2lf degrees Celsisus.\n",winteraverage[i]);
						break;
					default:
						printf("Error\n");
						break;
				}
			}
		}
	}
	swimmable(table);
}

/* Finding the average temperature of each lake during the summer */
double summer(double table[365][8]){
	int i,j,k,z=0;
	double summeraverage[6],test = summeraverage[0],summersorted[6],h;
	
	//FINDING SUMMER AVERAGE FOR EACH LAKE
	summeraverage[z] = 0; 
	for (j = 2; j < 8; j++){
		k = -1; 
		for (i = 171; i < 265; i++){
			z = j-2;
			k+=1;
			summeraverage[z] += table[i][j];
		}
	}
	for (j = 0; j < 6; j++){
		summeraverage[j] /= k;
	}
	//TRANSFERRING DATA TO ARRAY TO BE SORTED
	for (j = 0; j < 6; j++){
		summersorted[j] = summeraverage[j];
	}

	//SORTING
	for (j = 0; j < 6; j++){
		for (i = j+1; i < 6; i++){
			if (summersorted[j] < summersorted[i]){
				h = summersorted[j];
				summersorted[j] = summersorted[i];
				summersorted[i] = h;
			}
		}
	}

	for (j = 0; j < 6; j++){
		for (i = 0; i < 6; i++){
			if (summeraverage[i] == summersorted[j]){
				switch (i){
					case 0:
						printf("Lake Superior had a summer water surface average temperature of %0.2lf degrees Celsisus.\n",summeraverage[i]);
						break;
					case 1:
						printf("Lake Michigan had a summer water surface average temperature of %0.2lf degrees Celsisus.\n",summeraverage[i]);
						break;
					case 2:
						printf("Lake Huron had a summer water surface average temperature of %0.2lf degrees Celsisus.\n",summeraverage[i]);
						break;
					case 3:
						printf("Lake Erie had a summer water surface average temperature of %0.2lf degrees Celsisus.\n",summeraverage[i]);
						break;	
					case 4:
						printf("Lake Ontario had a summer water surface average temperature of %0.2lf degrees Celsisus.\n",summeraverage[i]);
						break;
					case 5:
						printf("Lake St. Clair had a summer water surface average temperature of %0.2lf degrees Celsisus.\n",summeraverage[i]);
						break;
					default:
						printf("Error\n");
						break;
				}
			}
		}
	}
	winter(table);
}

/* Finding the highest temperature of each lake */
double overall(double warmest[6], double coldest[6],double table[365][8]){
	int i,j,z,month,day;
	double warmesttemp = warmest[0], coldesttemp = coldest[0];

	//FINDING HIGHEST TEMPERATURE
	for (j = 0; j < 6; j++){
		if (warmesttemp < warmest[j])
			warmesttemp = warmest[j];
	}

	//FINDING THE DAY & LAKE
	for (j = 2; j < 8; j++){
		for (i = 0; i < 365; i++){
			if (warmesttemp == table[i][j]){
				z = j-2;
				switch (z){
					case 0:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Superior had the highest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",warmest[z],day,month);
						break;
					case 1:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Michigan had the highest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",warmest[z],day,month);
						break;
					case 2:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Huron had the highest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",warmest[z],day,month);
						break;
					case 3:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Erie had the highest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",warmest[z],day,month);
						break;
					case 4:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Ontario had the highest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",warmest[z],day,month);
						break;
					case 5:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake St. Clair had the highest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",warmest[z],day,month);
						break;
					default:
						printf("Error\n");
				}
			}
		}
	}

	//FINDING LOWEST TEMPERATURE
	for (j = 0; j < 6; j++){
		if (coldesttemp > coldest[j])
			coldesttemp = coldest[j];
	}

	//FINDING THE DAY & LAKE
	for (j = 2; j < 8; j++){
		for (i = 0; i < 365; i++){
			if (coldesttemp == table[i][j]){
				z = j-2;
				switch (z){
					case 0:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Superior had the lowest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",coldest[z],day,month);
						break;
					case 1:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Michigan had the lowest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",coldest[z],day,month);
						break;
					case 2:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Huron had the lowest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",coldest[z],day,month);
						break;
					case 3:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Erie had the lowest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",coldest[z],day,month);
						break;
					case 4:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Ontario had the lowest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",coldest[z],day,month);
						break;
					case 5:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake St. Clair had the lowest overall water surface temperature of all the lakes, of %0.2lf degrees Celsius on %d/%d/2017.\n",coldest[z],day,month);
						break;
					default:
						printf("Error\n");
				}
			}
		}
	}
	summer(table);
}

/* Finds the warmest day for each lake */
double warmestday(double table[365][8]){
	int i,j,z,month,day,k=0;
	double test,warmest[6],coldest[6];

	//WARMEST TEMP
	for (j = 2; j < 8; j++){
		test = table[0][j];
		for (i = 0; i < 365; i++){
			if (test < table[i][j]){
				test = table[i][j];
				z = j-2;
				warmest[z] = test;
			}
		}
	}

	//COLDEST TEMP
	for (j = 2; j < 8; j++){
		test = table[0][j];
		for (i = 0; i < 365; i++){
			if (test > table[i][j]){
				test = table[i][j];
				z = j-2;
				coldest[z] = test;
			}
		}
	}

	//FINDING WARMEST DAYS
	for (j = 2; j < 8; j++){
		for (i = 0; i < 365; i++){
			z = j-2;
			if (warmest[z] == table[i][j]){
				//DETERMINING MONTH AND DAY
				switch (z){
					case 0:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Superior had its highest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",warmest[z],day,month);
						break;
					case 1:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Michigan had its highest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",warmest[z],day,month);
						break;
					case 2:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Huron had its highest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",warmest[z],day,month);
						break;
					case 3:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Erie had its highest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",warmest[z],day,month);
						break;
					case 4:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Ontario had its highest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",warmest[z],day,month);
						break;
					case 5:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake St. Clair had its highest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",warmest[z],day,month);
						break;
					default:
						printf("Error\n");
						break;
				}
			}
		}
	}

	//FINDING COLDEST DAYS
	for (j = 2; j < 8; j++){
		for (i = 0; i < 365; i++){
			z = j-2;
			if (coldest[z] == table[i][j]){
				//DETERMINING MONTH AND DAY
				switch (z){
					case 0:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Superior had its lowest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",coldest[z],day,month);
						break;
					case 1:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Michigan had its lowest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",coldest[z],day,month);
						break;
					case 2:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Huron had its lowest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",coldest[z],day,month);
						break;
					case 3:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Erie had its lowest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",coldest[z],day,month);
						break;
					case 4:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake Ontario had its lowest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",coldest[z],day,month);
						break;
					case 5:
						if (0 <= i && i <= 30){
							month = 1;
							day = i+1;
						}
						else{
							if (31 <= i && i <= 58){
								month = 2;
								day = i-30;
							}
							else{
								if (59 <= i && i <= 89){
									month = 3;
									day = i-58;
								}
								else{
									if (90 <= i && i <= 119){
										month = 4;
										day = i-89;
									}
									else{
										if (120 <= i && i <= 150){
											month = 5;
											day = i-119;
										}
										else{
											if (151 <= i && i <= 180){
												month = 6;
												day = i-150;
											}
											else{
												if (181 <= i && i <= 211){
													month = 7;
													day = i-180;
												}
												else{
													if (212 <= i && i <= 242){
														month = 8; 
														day = i-211;
													}
													else{
														if (243 <= i && i <= 272){
															month = 9;
															day = i-242;
														}
														else{
															if (273 <= i && i <= 303){
																month = 10; 
																day = i-272;
															}
															else{
																if (304 <= i && i <= 333){
																	month = 11;
																	day = i-303;
																}
																else{
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
						printf("Lake St. Clair had its lowest surface water temperature of %0.2lf degrees Celsius on: %d/%d/2017\n",coldest[z],day,month);
						break;
					default:
						printf("Error\n");
						break;
				}
			}
		}
	}

	overall(warmest,coldest,table);
}

/* Finds the coldest yearly average temperature of each lake  */
double coldest(double averages[6],double lake_averages){
	int j,k,z=0;
	double coldest,warmest;
	coldest = averages[0];

	/* CALCULATING COLDEST */
	for (j = 0; j < 6; j++){
		if (coldest > averages[j]){
			coldest = averages[j];
		}
	}
	for (k = 0; k < 6; k++){
		if (coldest == averages[k]){
			z = k;
		}
	}
	switch (z){
		case 0:
			printf("Lake Superior has the coldest yearly average temperature.\n");
			break;
		case 1:
			printf("Lake Michigan has the coldest yearly average temperature.\n");
			break;
		case 2:
			printf("Lake Huron has the coldest yearly average temperature.\n");
			break;
		case 3:
			printf("Lake Erie has the coldest yearly average temperature.\n");
			break;
		case 4:
			printf("Lake Ontario has the coldest yearly average temperature.\n");
			break;
		case 5:
			printf("Lake St. Clair has the coldest yearly average temperature.\n");
			break;
		default:
			printf("Error");
			break;
	}

	/* CALCULATING WARMEST */
	for (j = 0; j < 6; j++){
		if (warmest < averages[j]){
			warmest = averages[j];
		}
	}
	for (k = 0; k < 6; k++){
		if (warmest == averages[k]){
			z = k;
		}
	}
	switch (z){
		case 0:
			printf("Lake Superior has the warmest yearly average temperature.\n");
			break;
		case 1:
			printf("Lake Michigan has the warmest yearly average temperature.\n");
			break;
		case 2:
			printf("Lake Huron has the warmest yearly average temperature.\n");
			break;
		case 3:
			printf("Lake Erie has the warmest yearly average temperature.\n");
			break;
		case 4:
			printf("Lake Ontario has the warmest yearly average temperature.\n");
			break;
		case 5:
			printf("Lake St. Clair has the warmest yearly average temperature.\n");
			break;
		default:
			printf("Error\n");
			break;
	}

	for (j = 0; j < 6; j++){
		if (averages[j] > lake_averages){
			z = j;
			switch (z){
				case 0:
					printf("Lake Superior has a yearly average temperature above the average of the lakes.\n");
					break;
				case 1:
					printf("Lake Michigan has a yearly average temperature above the average of the lakes.\n");
					break;
				case 2:
					printf("Lake Huron has a yearly average temperature above the average of the lakes.\n");
					break;
				case 3:
					printf("Lake Erie has a yearly average temperature above the average of the lakes.\n");
					break;
				case 4:
					printf("Lake Ontario has a yearly average temperature above the average of the lakes.\n");
					break;
				case 5:
					printf("Lake St. Clair has a yearly average temperature above the average of the lakes.\n");
					break;
				default:
					printf("Error\n");
			}
		}
		else{
			z = j;
			switch (z){
				case 0:
					printf("Lake Superior has a yearly average temperature below the average of the lakes.\n");
					break;
				case 1:
					printf("Lake Michigan has a yearly average temperature below the average of the lakes.\n");
					break;
				case 2:
					printf("Lake Huron has a yearly average temperature below the average of the lakes.\n");
					break;
				case 3:
					printf("Lake Erie has a yearly average temperature below the average of the lakes.\n");
					break;
				case 4:
					printf("Lake Ontario has a yearly average temperature below the average of the lakes.\n");
					break;
				case 5:
					printf("Lake St. Clair has a yearly average temperature above the average of the lakes.\n");
					break;
				default: 
					printf("Error\n");
					break;
			}
		}
	}
}

/* Finds the average temperature of each lake*/
double average(double table[365][8]){
	int i,j=2;
	double average=0,averages[6],lake_averages; 
	for (j = 2; j < 8; j++){
		for (i = 0; i < 365; i++){
			average += table[i][j];
		}
		switch (j){
			case 2:
				average = average/i;
				printf("Yearly average temperature for Lake Superior >> %0.2lf degrees Celsius\n",average);
				averages[0] = average;
				average = 0;
				break;
			case 3:
				average = average/i;
				printf("Yearly average temperature for Lake Michigan >> %0.2lf degrees Celsius\n",average);
				averages[1] = average;
				average = 0;
				break;
			case 4:
				average = average/i;
				printf("Yearly average temperature for Lake Huron >> %0.2lf degrees Celsius\n",average);
				averages[2] = average;
				average = 0;
				break;
			case 5:
				average = average/i;
				printf("Yearly average temperature for Lake Erie >> %0.2lf degrees Celsius\n",average);
				averages[3] = average;
				average = 0;
				break;
			case 6:
				average = average/i;
				printf("Yearly average temperature for Lake Ontario >> %0.2lf degrees Celsius\n",average);
				averages[4] = average;
				average = 0;
				break;
			case 7:
				average = average/i;
				printf("Yearly average temperature for Lake St. Clair >> %0.2lf degrees Celsius\n",average);
				averages[5] = average;
				average = 0;
				break;
			default:
				printf("Error\n");
				break;
		}
	}
	for (j = 0; j < 6; j++){
		lake_averages += averages[j];
	}
	lake_averages = lake_averages/j;
	printf("The average temperature of the lakes is %0.2lf degrees Celsius\n",lake_averages);
	coldest(averages,lake_averages);
}

/* MAIN FUNCTION */
int main(void){
	int i,j;
	double table[365][8];
	FILE*temps;
	temps = fopen("temps.txt","r");

	for (i = 0; i < 365; i++){
		for (j = 0; j < 8; j++){
			fscanf(temps,"%lf",&table[i][j]);
		}
	}
	printf("**NOTICE**: ALL DATES PRESENTED IN DAY/MONTH/YEAR FORMAT\n");
	fclose(temps);
	average(table);
	warmestday(table);
}