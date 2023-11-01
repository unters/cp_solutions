package warmup;

import java.util.Arrays;
import java.util.Scanner;

public class TaskD {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        scanner.close();

        if (s.length() != t.length()) {
            System.out.println("NO");
            return;
        }

        char[] sCnt = getCharactersCounts(s);
        char[] tCnt = getCharactersCounts(t);
        System.out.println((Arrays.equals(sCnt, tCnt)) ? "YES" : "NO");
    }

    private static char[] getCharactersCounts(String s) {
        char[] cnt = new char[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }

        return cnt;
    }
}
