package warmup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class TaskE {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] array = br.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(array[i]);
        }
        br.close();

        int[] answer = solve(a);
        for (int i = 0; i < n; ++i) {
            System.out.print(answer[i] + " ");
        }
        System.out.println();
    }

    private static int[] solve(int[] a) {
        int n = a.length;
        int[] answer = new int[n];
        for (int i = 1; i < n; ++i) {
            answer[0] += a[i] - a[0];
        }

        for (int i = 1; i < n; ++i) {
            answer[i] = answer[i - 1] + (a[i] - a[i - 1]) * (2 * i - n);
        }

        return answer;
    }
}
