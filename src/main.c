#include <stdio.h>
#include <unistd.h>
//#include <pigpio.h>
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

/*
void checkReadings(double readings[], int count, double max, double min)
{
    for (int i = 0; i < count; i++)
    {
        if (isOutOfRange(readings[i], max, min,))
        {
            printf("Reading %f is out of range.\n", readings[i]);
        }
        else
        {
            printf("Reading %f is within range.\n", readings[i]);
        }
    }
}
*/
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
    
    
    return avg;
}

int main()
{

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
    
    double avg;
    double max, min;
    getMaxMin(&max,&min);
    printf("Min%lf\n",min);
    printf("Max%lf\n",max);
    fprintf(fp, "Maximum temp: %.2lf\n", max);
    fprintf(fp, "Minimum temp: %.2lf\n", min);
    
    
    int TempCache[READING_COUNT];
    double readings[READING_COUNT];
    
    
    

    printf("Enter temperature in Farrenheit:");
    getReadings(readings, READING_COUNT);

    isOutOfRange(readings, max, min, READING_COUNT, TempCache, fp);

    avg = tempAvg(readings, READING_COUNT, 0);

    //checkReadings(readings, READING_COUNT, max, min);
    fclose(fp);
    return 0;
}
