package warmup;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class TaskI {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();

        Deque<Character> dq = new LinkedList<>();
        for (char c : s.toCharArray()) {
            if (dq.isEmpty()) {
                if (isOpeningBracket(c)) {
                    dq.addLast(c);
                } else {
                    System.out.println("no");
                    return;
                }
            } else if (isOpeningBracket(c)) {
                dq.addLast(c);
            } else if (bracketsMatch(dq.getLast(), c)) {
                dq.removeLast();
            } else {
                System.out.println("no");
                return;
            }
        }

        System.out.println(dq.isEmpty() ? "yes" : "no");
    }

    private static boolean bracketsMatch(char openingBracket, char closingBracket) {
        return openingBracket == '(' && closingBracket == ')'
            || openingBracket == '[' && closingBracket == ']'
            || openingBracket == '{' && closingBracket == '}';
    }

    private static boolean isOpeningBracket(char b) {
        return b == '(' || b == '[' || b == '{';
    }
}
