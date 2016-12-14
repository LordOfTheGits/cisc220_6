#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int carPosition[5] = {0,0,0,0,0};

void *userCar(void *string) {
    while (carPosition[0]<40){
	    if ( getchar() == '\n') {
	    		carPosition[0]+= 1;
	    }
    }
    pthread_exit(NULL);
}

void *computerCar(void *string){
	int lane = (int)string;
	while (carPosition[lane]<40){
		carPosition[lane] += 1;
		usleep(1000*(rand()%100));
	}
pthread_exit(NULL);
}

void *printThread(void *threadid){
	int winner = 0;
	while (1){
	    system("clear");
        printf("Welcome to Cisc220 Racing Arena\n");
        printf("Hit Enter to move forward \n");
        for (int i = 0; i < 5; i++){
        	int x;
            for (x = 0; x < carPosition[i]; x++) {
                printf("~");
            }
            printf("|->");
            for (x = 40; x > carPosition[i]; x--) {
                printf(" ");
            }
            printf("# Line %d #\n", i);
    	    if (carPosition[i] == 40){
		        winner=i;
            }
        }
        if (winner){
        	printf("Player %d Wins!\n", winner);
        	pthread_exit(NULL);
        }
        usleep(133337);
    }
}	

int main(){
    printf("Welcome to Cisc220 Racing Arena\n");
    printf("Hit Enter to move forward \n");

	pthread_t run;
	long lane = 0;

	if ( getchar() == '\n') {
		pthread_create(&run,NULL,userCar,(void *) lane );
		for(lane = 1; lane < 7; lane++) {
			pthread_create(&run,NULL,computerCar,(void *) lane);
		}
	    pthread_create(&run, NULL, printThread, NULL);
	    pthread_join(run, NULL);
	    exit(0);
	}
}