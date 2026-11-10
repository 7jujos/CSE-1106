#include <stdio.h>
#include <unistd.h>
//#include <pigpio.h>
#define PIN 17
#define READING_COUNT 5

//int temperature;
double readings[READING_COUNT];

void checkReadings(double readings[], int count, double max, double min);
void getReadings(double readings[], int count);
int isOutOfRange(double temperature, double max, double min);
double getMaxMin(double max, double min);


int main(int argc, char *argv[])
{

    //gpioInitialise();
    //gpioSetMode(PIN, PI_OUTPUT);
    //gpioWrite(PIN, 1);
    //getchar();
   //gpioWrite(PIN, 0);
    //getchar();
    //gpioTerminate();

    double max = 0;
    double min = 0;
    double temperature = 0;
    
    getMaxMin(max, min);

    printf("Enter temperature in Farrenheit:");
    getReadings(readings, READING_COUNT);


    checkReadings(readings, READING_COUNT, max, min);

    return 0;
}

void getReadings(double readings[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\nEnter reading %d: ", i + 1);
        scanf("%.2lf", &readings[i]);
    }
}

int isOutOfRange(double temperature, double max, double min)
{
    return (temperature < max || temperature > min) ? 1 : 0;
}

void checkReadings(double readings[], int count, double max, double min)
{
    for (int i = 0; i < count; i++)
    {
        if (isOutOfRange(readings[i], max, min))
        {
            printf("Reading %.2lf is out of range.\n", readings[i]);
        }
        else
        {
            printf("Reading %f is within range.\n", readings[i]);
        }
    }
}

double getMaxMin(double max, double min)
{
    printf("Enter maximum temperature: ");
    scanf("%lf", &max);
    printf("Enter minimum temperature: ");
    scanf("%lf", &min);
    return max, min;
    
}