// Temperature of given city

#include <stdio.h>
#include <string.h>
#define CITY_NAME_LENGTH 50
#define COMMAND_LENGTH 500
int main()
{
	char cityName[CITY_NAME_LENGTH], *pieceOfReport;
	char command[COMMAND_LENGTH], report[COMMAND_LENGTH];
	printf("Enter City Name:");
	scanf("%s", cityName);
	fflush(stdin);
	sprintf(command, "curl -k \"https://api.openweathermap.org/data/2.5/weather?q=%s&units=metric&appid=201ac1b1456985494f5e9f7c1c258d45\">weather.txt", cityName);
	system(command);
	FILE *fpWeather = fopen("weather.txt", "r");
	fgets(report, COMMAND_LENGTH, fpWeather);
	fclose(fpWeather);
	pieceOfReport = strtok(report, ":");
	while (pieceOfReport != 0)
	{
		if (strcmp(pieceOfReport, "{\"temp\"") == 0)
		{	
			pieceOfReport = strtok('\0', ",");
			system("cls");
			printf("Temperature in %s: %s degree Celsius", cityName, pieceOfReport);
			break;
		}
		pieceOfReport = strtok('\0', ":");
	}
}



/*// tTemperature of given city

#include <stdio.h>
#include <string.h>
#define CITY_NAME_LENGTH 50
#define COMMAND_LENGTH 500
int main()
{
	int counter;
	char cityName[CITY_NAME_LENGTH], *pieceOfReport;
	char command[COMMAND_LENGTH], report[COMMAND_LENGTH];
	printf("Enter City Name:");
	scanf("%s", cityName);
	fflush(stdin);
	sprintf(command, "curl -k \"https://api.openweathermap.org/data/2.5/weather?q=%s&units=metric&appid=201ac1b1456985494f5e9f7c1c258d45\">weather.txt", cityName);
	system(command);
	FILE *fpWeather = fopen("weather.txt", "r");
	fgets(report, COMMAND_LENGTH, fpWeather);
	fclose(fpWeather);
	pieceOfReport = strtok(report, ":");
	for (counter = 0; counter < 10; counter++)
	{
		pieceOfReport = strtok('\0', ":");
	}
	pieceOfReport = strtok('\0', ",");
	system("cls");
	printf("Temperature in %s: %s", cityName, pieceOfReport);
}*/