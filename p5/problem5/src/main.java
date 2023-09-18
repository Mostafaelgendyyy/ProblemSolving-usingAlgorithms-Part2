import java.util.Scanner;

public class main {
    public static void main (String[]args)
    {
        Scanner input=new Scanner(System.in);
        int N=input.nextInt();
        int k=input.nextInt();
        int countT=0;
        char []arr=new char[N];
        for(int i = 0 ;i<N;i++)
        {
            arr[i]=input.next().charAt(0);
        }
    for(int i = 0;i<N;i++)
    {
        if(arr[i]=='P')
        {
            boolean flag=false;
            if(i>0)
            {   int j = i-k;
                while (j<0)
                {
                    j++;
                }
                for(;j<i;j++)
                {
                    if(arr[j]=='T')
                    {
                        flag=true;
                        arr[j]='.';
                        countT++;
                        break;
                    }

                }

            }
            if((flag==false)&&(i!=arr.length-1))
            {
                int j=i+k;
                while (j>(arr.length-2))
                {
                    j--;
                }
                for(;j>i;j--)
                {
                    if(arr[j]=='T')
                    {
                        flag=true;
                        arr[j]='.';
                        countT++;
                    }

                }
            }
        }


    }

System.out.println(countT);


    }
}
