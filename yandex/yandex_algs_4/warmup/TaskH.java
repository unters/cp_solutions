package warmup;

import java.util.Scanner;

public class TaskH {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int n = scanner.nextInt();
        scanner.close();

        int groupOneSize = a;
        int groupTwoSize = b / n + ((b % n == 0) ? 0 : 1);
        System.out.println((groupOneSize > groupTwoSize) ? "Yes" : "No");
    }
}
