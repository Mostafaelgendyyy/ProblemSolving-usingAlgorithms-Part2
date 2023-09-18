import java.util.Scanner;
import java.util.ArrayList;

public class ackermann {
    public static int ackermannRule(int m, int n) {
        if (m < 0 || n < 0) {
            return -1;
        }
        int Var = 0;
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i <= m; i++) {
            arr.add(new ArrayList<Integer>());
        }

        Boolean FlagOfWork = true;

        while (FlagOfWork) {
            for (int i = 0; i <= m; i++) {
                int S = arr.get(i).size();

                if (i == 0) {
                    Var = S + 1;
                } else if (S == 0) {
                    if (arr.get(i - 1).size() <= 1) break;
                    Var = arr.get(i - 1).get(1);
                } else {
                    int k = arr.get(i).get(S - 1);
                    if (arr.get(i - 1).size() <= k) {
                        break;
                    }
                    Var = arr.get(i - 1).get(k);
                }

                arr.get(i).add(Var);

                if (i == m && S == n) {
                    FlagOfWork = false;
                    break;
                }
            }
        }
        return Var;
    }

    public static void main(String[] args) {
        System.out.println(ackermannRule(3, 3));
        System.out.println(ackermannRule(4, 1));
    }
}