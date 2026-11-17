#include <stdio.h>
#include <unistd.h>
//#include <pigpio.h>
#define PIN 17
#define READING_COUNT 5


void checkReadings(double readings[], int count, double max, double min);
void getReadings(double readings[], int count);
int isOutOfRange(double readings[], double max, double min, int count, int TempCache[]);



void getReadings(double readings[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\nEnter reading %d: ", i + 1);
        scanf("%lf", &readings[i]);
    }
}

int isOutOfRange(double readings[], double max, double min, int count, int TempCache[])
{
	for (int i = 0; i < count; i++)
	{
		if (readings[i] > max)
		{
			TempCache[i] = 1;
			printf("%d\n",TempCache[i]); //t
		}
        else if (readings[i] < min)
        {
			TempCache[i] = 2;
			printf("%d\n",TempCache[i]); //t
		}
        
		else 
			{TempCache[i] = 0;
			printf("%d\n",TempCache[i]);} //t
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
    printf("%lf\n",max);
    return 0;
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

    double max, min;
    getMaxMin(&max,&min);
    printf("Min%lf\n",min);
    printf("Max%lf\n",max);
    
    
    int TempCache[READING_COUNT];
    double readings[READING_COUNT];
    
    
    

    printf("Enter temperature in Farrenheit:");
    getReadings(readings, READING_COUNT);

	isOutOfRange(readings, max, min, READING_COUNT, TempCache);


    //checkReadings(readings, READING_COUNT, max, min);

    return 0;
}
