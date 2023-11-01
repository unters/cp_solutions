package warmup;

import java.util.Scanner;
import static java.lang.Math.min;

public class TaskB {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        scanner.close();

        int numerator = a * d + c * b;
        int denominator = b * d;
        for (int i = 2; i < min(numerator, denominator); ++i) {
            while (numerator % i == 0 && denominator % i == 0) {
                numerator /= i;
                denominator /= i;
            }
        }

        System.out.println(numerator + " " + denominator);
    }
}
