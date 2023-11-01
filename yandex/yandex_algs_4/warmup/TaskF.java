package warmup;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class TaskF {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());    // 1 <= k <= 10^9
        int n = Integer.parseInt(br.readLine());    // 1 <= n <= 10^5
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = Integer.parseInt(br.readLine()); // 0 <= a <= 10^9
        }
        br.close();

        BigInteger answer = new BigInteger("0");
        int capacityLeftover = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (capacityLeftover <= a[i]) {
                a[i] -= capacityLeftover;
                capacityLeftover = 0;
            } else {
                capacityLeftover -= a[i];
                a[i] = 0;
            }

            long time = 2L * (i + 1);
            answer = answer.add(new BigInteger(Long.toString((a[i] / k) * time)));
            if (a[i] % k != 0) {
                answer = answer.add(new BigInteger(Long.toString(time)));
                capacityLeftover = k - a[i] % k;
            }
        }

        System.out.println(answer);
    }
}
