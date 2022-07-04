/* ERGASIA 1 - kalmpr.c */
/* Vekris Alexandros - AM 1115202000021*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MINNUM 2100000000
#define MAXNUM 2104000000
#define MAXK 6
#define COMPUTATIONS 30
int main(void)
{
	int n, m, divisor, prev, next, flag, n1, n2, curtime;
	int primek, prime2, i, Primes, lim1, lim2, j;
	printf("\nChecking numbers in [%d, %d]\n\n", MINNUM, MAXNUM);
	primek=0; 					 //primek counts k-primes of the field
	prime2=0; 					 //prime2 counts semiprimes of the field
	for (n=MINNUM;n<=MAXNUM;n++) //searching for k-almost primes in [MINNUM, MAXNUM]
	{
		Primes=0; 				 //counts the number of primes found that create the number 'n'
		m=n; 	  				 //'m' takes starting value of 'n', 'm' will change value
        while (m!=1 && Primes<=MAXK){
            if (m%2==0){		 //checking if 2 divides
                Primes++; 		 //found one more prime divisor of 'm' (aka 'n')
                m/=2; 			 //dividing 'm' until it equals 1
                divisor=2; 		 //saving the number that divided 'm'
            }
            else if (m%3==0){	 //checking if 3 divides
                Primes++;
                m/=3; 
                divisor=3;
            } 
            else if (m%5==0){	 //checking if 5 divides
                Primes++;
                m/=5; 	
                divisor=5; 
            }
            else if (m%7==0){	 //checking if 7 divides
                Primes++;
                m/=7; 			 
                divisor=7; 		 
            }
            else{
                i=2;
                prev=6*i-1; 	 //all prime numbers except 2,3,5,7 have form (6*i-1) and (6*i+1), i>=2
                next=prev+2;	 //so we are checking only those
                flag=0;
                while (prev*prev<=m || next*next<=m){ 		//searching the prime divisors of 'm' up to its sqrt
                    if (m%prev==0){ 
                        divisor=prev; 		//saving the number that divided 'm'
                        m/=divisor; 		//dividing 'm' until it equals 1
                        Primes++;			//found one more prime divisor of 'm' (aka 'n')
                        flag=1;				//indicating we found one prime divisor of 'm' (aka 'n')
                        break;
                    }
                    else if (m%next==0){
                        divisor=next;
                        m/=divisor;	
                        Primes++;
                        flag=1;	
                        break;      
                    }
                    i++;
                    prev=6*i-1;				//going for next couple of primes
                    next=prev+2;
                }
                if (!flag){					//if we didn't find one prime divisor of 'm' (aka 'n')
                    divisor=m;              //then 'm' is a prime so divide it by itself
                    m/=divisor;
                    Primes++;
                }
            }
            if (Primes==1){
                n1=divisor;					//saving 1st divisor of 'm' (aka 'n')
            }
            if (Primes==2){
                n2=divisor;					//saving 2nd divisor of 'm' (aka 'n')
            }
        }
		if (m==1 && Primes>=2 && Primes<=MAXK) //found k prime divisors of 'm'
			primek++;
		if (m==1 && Primes==2)				//found 2 prime divisors of 'm'
		{
			prime2++;
			if (n2-n1<=n2/100 && n1!=n2) //checking if 'm' (aka 'n') is an interesting semiprime
				printf("%d * %d = %d is an interesting semiprime\n", n1, n2, n);
		}								
	}
	printf("\nFound %d k-almost prime numbers (2 <= k <= %d)\n", primek, MAXK);
	printf("Found %d semiprimes\n\n", prime2);	
	curtime=time(NULL);
	printf("Current time is %d\n\n", curtime);
	printf("Checking %d random numbers\n\n", COMPUTATIONS);
	srand((unsigned int) curtime); //seed for random number generator
	for (j=1;j<=COMPUTATIONS;j++)
	{	
		n=((rand() % 32768)+1)*((rand() % 32768)+1)+1;		//n belongs to the 20 random numbers
		Primes=0; 			//counts the number of primes found that create the number 'n'
		divisor=2; 			//starting value of smallest divisor >1
        m=n; 	  			//m takes starting value of n, m will change value
        while (m!=1){
            if (m%2==0){	//same technique as above
                Primes++;
                m/=2;
                divisor=2;
            }
            else if (m%3==0){
                Primes++;
                m/=3;
                divisor=3;
            } 
            else if (m%5==0){
                Primes++;
                m/=5;
                divisor=5;
            }
            else if (m%7==0){
                Primes++;
                m/=7;
                divisor=7;
            }
            else{
                i=2;
                while (6*i+1<=m || 6*i-1<=m){
                    prev=6*i-1;
                    next=6*i+1;
                    if (m%prev==0){ 
                        divisor=prev;
                        m/=divisor;
                        Primes++;
                        break;
                    }
                    else if (m%next==0){
                        divisor=next;
                        m/=divisor;
                        Primes++;
                        break;      
                    }
                    i++;
                }
            }
        }
		printf("%d is a %d-almost prime number\n", n, Primes);					
	}
	printf("\n"); //empty final line for better presentation
    return 0;
}