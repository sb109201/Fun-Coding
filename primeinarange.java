import java.util.*;

public class PrimeInRange {
    public static void primeInRange(int a, int b) {
        for (int i = a; i <= b; i++) {
            int c = 0;
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    c++;
                    break;
                }
            }
            if (c == 0 && i != 1) {
                System.out.println(i);
            }
        }
    }

    public static void main(String[] args) {
        int p = 31;
        primeInRange(20, 50);
    }
}
