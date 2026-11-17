#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>
#define PIN 17
#define READING_COUNT 5


void checkReadings(double readings[], int count, double max, double min);
void getReadings(double readings[], int count);
int isOutOfRange(double readings[], double max, double min, int count, int TempCache[],FILE* fp);



void getReadings(double readings[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\nEnter reading %d: ", i + 1);
        scanf("%lf", &readings[i]);
    }
}

int isOutOfRange(double readings[], double max, double min, int count, int TempCache[], FILE* fp)
{
	for (int i = 0; i < count; i++)
	{
		if (readings[i] > max)
		{
			TempCache[i] = 1;
			printf("%d\n",TempCache[i]); //t
            fprintf(fp, "%.2lf   FAIL (over max)\n",readings[i]);
		}
        else if (readings[i] < min)
        {
			TempCache[i] = 2;
			printf("%d\n",TempCache[i]); //t
            fprintf(fp, "%.2lf   FAIL (under min)\n",readings[i]);
		}
        
		else
        {
            TempCache[i] = 0;
			printf("%d\n",TempCache[i]); //t
            fprintf(fp, "%.2lf   PASS (wthin range)\n",readings[i]);
        }
	}
}

double getMaxMin(double *max,double *min)
{
    
    printf("Enter maximum temperature: ");
    scanf("%lf", max);
    printf("Enter minimum temperature: ");
    scanf("%lf", min);
    
    return 0;
}

double tempAvg(double readings[], int count, double avg)
{
    for (int i = 0; i < count; i++)
    
    avg += readings[i];
    avg/=count;
    
    
    printf("\n avg%lf",avg);
    return avg;
}


int main()
{

<<<<<<< HEAD
    gpioInitialise();
    gpioSetMode(PIN, PI_OUTPUT);
    gpioWrite(PIN, 1);
    getchar();
   gpioWrite(PIN, 0);
    getchar();
    gpioTerminate();
=======
    //gpioInitialise();
    //gpioSetMode(PIN, PI_OUTPUT);
    //gpioWrite(PIN, 1);
    //getchar();
   //gpioWrite(PIN, 0);
    //getchar();
    //gpioTerminate();
    FILE *fp;


    fp = fopen("temperature_log.csv", "w");


    if (fp == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }
>>>>>>> 81f5568d513c8f530620c390cd334b7047bfd102

    double avg;
    int TempCache[READING_COUNT];
    double readings[READING_COUNT];
    double max, min;
    getMaxMin(&max,&min);
    printf("Min%lf\n",min);
    printf("Max%lf\n",max);
<<<<<<< HEAD
=======
    fprintf(fp, "Maximum temp: %.2lf\n", max);
    fprintf(fp, "Minimum temp: %.2lf\n", min);
    
    
    int TempCache[READING_COUNT];
    double readings[READING_COUNT];
    
    
    
>>>>>>> 81f5568d513c8f530620c390cd334b7047bfd102

    printf("Enter temperature in Farrenheit:");
    getReadings(readings, READING_COUNT);

	isOutOfRange(readings, max, min, READING_COUNT, TempCache, fp);

    tempAvg(readings, READING_COUNT, avg);
    printf("\n avg%lf",avg);
    
    
    //checkReadings(readings, READING_COUNT, max, min);
    fclose(fp);
    return 0;
}
