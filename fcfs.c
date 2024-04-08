printf("\nEnter Burst Time for Process %d -- ", i);
scanf("%d", &burstTime[i]);
}
waitingTime[0] = avgwt = 0;
turnaroundTime[0] = avgtat = burstTime[0];
for(i=1;i<n;i++)
{
waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
turnaroundTime[i] = turnaroundTime[i-1] + burstTime[i];
avgwt = avgwt + waitingTime[i];
avgtat = avgtat + turnaroundTime[i];
}
printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n"); 
for(i=0;i<n;i++)
printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, burstTime[i], waitingTime[i], turnaroundTime[i]);
avgwt = avgwt/n;
avgtat = avgtat/n;
printf("\nAverage Waiting Time - %f", avgwt); 
printf("\nAverage Turnaround Time - %f", avgtat ); 
return 0;
}
