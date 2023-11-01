package warmup;

import java.util.Scanner;

import static java.lang.Math.*;

public class TaskC {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long xA = scanner.nextLong();
        long yA = scanner.nextLong();
        long xB = scanner.nextLong();
        long yB = scanner.nextLong();
        scanner.close();

        double rA = sqrt(xA * xA + yA * yA);
        double rB = sqrt(xB * xB + yB * yB);
        if (rA == 0.0 || rB == 0.0) {
            System.out.println(max(rA, rB));
            return;
        }
        /* Radial path AO -> OB.  */
        double path1 = rA + rB;

        double r = min(rA, rB);
        double alpha = atan2(xA, yA) * 180 / PI;
        double beta = atan2(xB, yB) * 180 / PI;
        double phi = min(360 - abs(alpha - beta), abs(alpha - beta));
        /* Path through radius differences and shortest circular arc.  */
        double path2 = abs(rA - rB) + PI * r / 180 * phi;
        System.out.println(min(path1, path2));
    }
}
