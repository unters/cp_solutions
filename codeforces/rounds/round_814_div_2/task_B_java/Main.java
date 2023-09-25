import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; ++i) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            k %= 4;
            if (k == 0) {
                System.out.println("NO");
                continue;
            }

            System.out.println("YES");
            if (k == 1 || k == 3) 
                for (int j = 1; j <= n; j += 2)
                    System.out.println(j + " " + (j + 1));

            else 
                for (int j = 1; j <= n; j += 2)
                    if ((j + 1) % 4 == 0)
                        System.out.println(j + " " + (j + 1));
                    else
                        System.out.println((j + 1) + " " + j);
            
        }
    }
}

