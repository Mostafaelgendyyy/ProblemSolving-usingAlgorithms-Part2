import java.util.LinkedList;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
public class main {
    public static void main(String[] args) {
        /////////////////////////readSets///////////////////
        Scanner input = new Scanner(System.in);
        int numofSets = input.nextInt();
        int arr[][] = new int[numofSets][2];
        for (int i = 0; i < numofSets; i++) {
            for (int j = 0; j < 2; j++) {
                arr[i][j] = input.nextInt();
            }
        }
/////////////////////////////////////sortSets/////////////////////////////////////////////////
        java.util.Arrays.sort(arr, new java.util.Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Double.compare(a[0], b[0]);
            }
        });
        int tempSwap;
        for(int i = 0 ; i<numofSets-1;i++)
        {
            if(arr[i][0]!=arr[i+1][0])
            {
                continue;
            }
            int j=i+1;
            while (j<numofSets && arr[i][0]==arr[j][0])
            {
                if(arr[i][1]>arr[j][1])
                {
                    tempSwap=arr[i][1];
                    arr[i][1]=arr[j][1];
                    arr[j][1]=tempSwap;
                }
                j++;
            }

        }
/////////////////////////////findMaxNumOFSets////////////////////////////////////////
        int temp = arr[0][0];
        LinkedList<Integer> indx = new LinkedList<Integer>();
        LinkedList<Integer> tempindx = new LinkedList<Integer>();
        //int maxsum=0;
        // int counter=1;
        for (int i = 0; i < numofSets; i++) {
            if (i != 0) {
                if ((arr[i][0]) == temp) {
                    continue;
                } else {
                    temp = arr[i][0];
                }
            }
            tempindx.add(i);
            int temprow = i;
            for (int j = i + 1; j < numofSets; j++) {

                if (arr[temprow][1] < arr[j][0]) {
                    tempindx.add(j);
                    temprow = j;
                    //counter++;
                }
            }
            if (tempindx.size() > indx.size()) {
                indx.clear();
                for (int h = 0; h < tempindx.size(); h++)
                {
                    indx.add(tempindx.get(h));
                }
            }
            tempindx.clear();
        }

        for (int i = 0; i < indx.size(); i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print(arr[indx.get(i)][j]);
                System.out.print(' ');
            }
            System.out.println();
        }

    }/*
     for (int i = 0; i < numofSets; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print(arr[i][j]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

*/
}









