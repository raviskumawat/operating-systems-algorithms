#include <stdio.h>
#include <conio.h>

int sum_(int a[],int n)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
        sum+=a[i];
   return sum;
}

int main()
{
	int n,i,q;
	printf("Enter the quantity time :");
	scanf("%d",&q);
	printf("Enter n: ");
	scanf("%d",&n);
	char p[n];
	int at[n];
	int ts[n],ts1[n];
	int wt[n],r_wt[n],tused[n];


    int total_wait[n],tr[n];
    double delay[n];

	for(i=0;i<n;i++)
	{
	    printf("\nEnter the start_time service_time for %d process ",i);
		//scanf("%c",&p[i]);
		scanf("%d",&at[i]);
		scanf("%d",&ts[i]);
		wt[i]=0;
		r_wt[i]=0;
		tused[i]=0;
		ts1[i]=ts[i];
	}

	 i=0;
	int c_time=0,r_c=0;
	while(sum_(ts,n)!=0)
    {
        if(i==n)
            i=0;



                c_time=sum_(wt,n)+sum_(tused,n);

                if(c_time>at[i] && ts[i]!=0)
                {

                    if(r_c==0)
                    {

                        wt[i]=c_time-at[i];
                    }
                    else{

                        r_wt[i]=c_time-at[i]-tused[i];

                    }
                }

                if(ts[i]>=q)
                {

               // printf("\nInside for reduction\n");
                    tused[i]+=q;
                    ts[i]=ts[i]-q;
                }
                else{
                    tused[i]+=ts[i];
                    ts[i]=0;
                }


           // printf("\nts=%d for process=%d",ts[i],i);
            i++;
            r_c++;
    }

    //printf("\nAverage");

    float avg=0;
    for(i=0;i<n;i++)
    {
        //printf("hsged");

        total_wait[i]=wt[i]+r_wt[i];
        avg+=total_wait[i];
        tr[i]=ts1[i]+total_wait[i];

        delay[i]=(float)tr[i]/(float)ts1[i];
        printf("\nProcess :%d\t Total wait time :%d\t tr time:%d\t  delay time:%f",i,total_wait[i],tr[i],delay[i]);
    }


    printf("\nAverage wait time: %f",avg/n);
	return 0;
}
