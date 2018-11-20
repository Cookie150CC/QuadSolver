#include <stdio.h>
#include <time.h>

int logPrint(char * msg){
	FILE * logs;
	logs =	fopen("logs.txt", "w+");
	time_t curtime;
	struct tm *loc_time;
   	//Getting current time of system
   	curtime = time (NULL);
   	// Converting current time to local time
   	loc_time = localtime (&curtime);
	fprintf(logs, "%s: %s", asctime(loc_time), msg);
	fflush(logs);
	fclose(logs);
	return 0;

}
