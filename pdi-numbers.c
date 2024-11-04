#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
int count_numbers(int n){
    int count=0;
    while(n){
        n/=10;
        count++;
    }
    return count;
}
int** divide_ranges(int threads,int start,int end){
    int** ranges= malloc(threads*sizeof(int*));
    int change = (end-start)/threads;
    int remainder = (end - start) % threads;
    for (int i = 0; i < threads; i++)
    {
        ranges[i]=malloc(2*sizeof(int));
        ranges[i][0] = start + i * change;
        ranges[i][1] = (i == threads - 1) ? end : ranges[i][0] + change - 1;
        if (i == threads - 1 && remainder > 0) {
            ranges[i][1] += remainder-1;
        }
    }
    return ranges;
}
int find_correct(int a,int power){
    int check=a;
    int sum =0;
    while (check)
    {
        int digit = check % 10;
        sum += (int)pow(digit,power);
        check /= 10; 
    }
    return sum; 
}
void* perfect_digital_invariant(void*numbers){
    int* all = numbers;
    for (int i = all[0]; i <= all[1]; i++)
    {
        if (i ==1)
        {
            printf("%d\n",i);
        }
        
        int check = i;
        int sum;
        for (int j = 1; j < 10; j++)
        {
            sum = find_correct(check,j);
            if (sum == i && i !=1)
        {
            printf("%d\n",i);
        }
        }
    }        
}


int main(int argc,char* argv[]){
    int opt;
    int threads = 1;
    int std_error_trace = 0;
    int start=1;
    int end=10000;
    while ((opt = getopt(argc,argv,"s:e:t:v")) != -1)
    {
        switch (opt)
        {
        case 's':
            start = atoi(optarg);
            break;
        case 'e':
            end = atoi(optarg);
            break;
        case 't':
            threads = atoi(optarg);
            if (threads<=0)
            {
                fprintf(stderr,"Threads cannot be less or equal to zero\n");
                exit(1);
            }
            break;
        case 'v':
            std_error_trace = 1;
            break;
        default:
            break;
        }
    }
    if (threads == 1)
    {
        int numbers[2] = {start,end};
        pthread_t t1;
        pthread_create(&t1,NULL,&perfect_digital_invariant,(void*)numbers);
        if (std_error_trace)
        {
            fprintf(stderr,"pdi-numbers: t%d searching[%d,%d]\n",threads,numbers[0],numbers[1]);
            pthread_join(t1,NULL);
            fprintf(stderr,"pdi-numbers: t%d finishing\n",threads);
        }
        pthread_join(t1,NULL);
    }
    else{
        int** numbers=divide_ranges(threads,start,end);
        pthread_t t[threads];
        for (int i = 0; i < threads; i++)
        {
            pthread_create(&t[i],NULL,&perfect_digital_invariant,(void*)numbers[i]);
        if (std_error_trace)
        {
            fprintf(stderr,"pdi-numbers: t%d searching[%d,%d]\n",i,numbers[i][0],numbers[i][1]);
        }
        }
        for (int i = 0; i < threads; i++)
        {
            pthread_join(t[i],NULL);
            if(std_error_trace){
            fprintf(stderr,"pdi-numbers: t%d finishing\n",i);
            }}
    }
    return 0;
}