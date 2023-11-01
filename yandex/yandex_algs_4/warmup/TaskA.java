package warmup;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
import static java.lang.Math.max;

public class TaskA {
    private static final String NOT_FOUND_MESSAGE = "NOT FOUND";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = scanner.nextInt();
        }

        int[] leftMax = getLeftMax(a);
        int[] leftMin = getLeftMin(a);
        while(m-- > 0) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            if (a[l] != a[r]) {
                System.out.println(max(a[l], a[r]));
            } else if (leftMax[r] > l) {
                System.out.println(a[leftMax[r]]);
            } else if (leftMin[r] > l) {
                System.out.println(a[r]);
            } else {
                System.out.println(NOT_FOUND_MESSAGE);
            }
        }

        scanner.close();
    }

    private static int[] getLeftMax(int[] a) {
        int[] leftMax = new int[a.length];
        Deque<Integer> dq = new LinkedList<>();

        leftMax[0] = -1;
        dq.addLast(0);
        for (int i = 1; i < a.length; ++i) {
            while(!dq.isEmpty() && a[dq.getLast()] <= a[i]) {
                dq.removeLast();
            }

            if (dq.isEmpty()) {
                leftMax[i] = -1;
            } else {
                leftMax[i] = dq.getLast();
            }

            dq.addLast(i);
        }

        return leftMax;
    }

    private static int[] getLeftMin(int[] a) {
        int[] leftMin = new int[a.length];
        Deque<Integer> dq = new LinkedList<>();

        leftMin[0] = -1;
        dq.addLast(0);
        for (int i = 1; i < a.length; ++i) {
            while(!dq.isEmpty() && a[dq.getLast()] >= a[i]) {
                dq.removeLast();
            }

            if (dq.isEmpty()) {
                leftMin[i] = -1;
            } else {
                leftMin[i] = dq.getLast();
            }

            dq.addLast(i);
        }

        return leftMin;
    }
}
