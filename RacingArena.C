#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int carPosition[6] = {0,0,0,0,0.0};

void *userCar(void *string) {
    while (carPosition[1]<40){
	    if ( getchar() == '\n') {
	    		carPosition[1]+= 1;
	    }
    }
    pthread_exit(NULL);
}

void *computerCar2(void *string){
	
	while (carPosition[2]<40){
		carPosition[2] += 1;
		usleep(1000*(rand()%100));
	}
pthread_exit(NULL);
}

void *computerCar3(void *string){
	
	while (carPosition[3]<40){
		carPosition[3] += 1;
		usleep(1000*(rand()%100));
	}
pthread_exit(NULL);
}

void *computerCar4(void *string){
	
	while (carPosition[4]<40){
		carPosition[4] += 1;
		usleep(1000*(rand()%100));
	}
pthread_exit(NULL);
}

void *computerCar5(void *string){
	
	while (carPosition[5]<40){
		carPosition[5] += 1;
		usleep(1000*(rand()%100));
	}
pthread_exit(NULL);
}

void *printThread(void *threadid){

	while (1){
	    system("clear");
        printf("Welcome to Cisc220 Racing Arena\n");
        printf("Hit Enter to move forward \n");
        for (int i = 1; i < 6; i++){
            for (int x = 0; x < carPosition[i]; x++) {
                printf("~");
            }
            printf("|->");
            for (int x = 40; x > carPosition[i]; x--) {
                printf(" ");
            }
            printf("# Line %d #\n", i);
    	    if (carPosition[i] == 40){
		        printf("Player %d Wins!\n", i);
		        pthread_exit(NULL);
            }
        }
        usleep(133337);
    }
}	

int main(){
	pthread_t run;
    pthread_create(&run, NULL, userCar, NULL);
    pthread_create(&run, NULL, computerrun, NULL);
    pthread_create(&run, NULL, computerCar3, NULL);
    pthread_create(&run, NULL, computerCar4, NULL);
    pthread_create(&run, NULL, computerCar5, NULL);
    pthread_create(&run, NULL, printThread, NULL);
    pthread_join(run, NULL);
    exit(0);
}
