void init()  
{  
    memset(prime,0,sizeof(prime));  
    memset(num,0,sizeof(num));  
    for(int i=2;i<=5000005;i++)  
    {  
        if(prime[i]==0)  
        {  
            for(int j=i;j<=5000005;j+=i)  
            {  
                int temp=j;  
                while(temp%i==0)  
                {  
                    num[j]++;  
                    temp/=i;  
                }  
                prime[j]=1;  
            }  
        }  
    }  
    for(int i=2;i<=5000005;i++)  
    {  
        num[i]=num[i-1]+num[i];  
    }  
}  
