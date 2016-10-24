import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Exercise_1_1_6 {
    public static void main(String[] args) {
        long f = 0;
        long g = 1;
        for (int i = 0; i <= 60; i++)
        {
            StdOut.println(f);
            f = f + g;
            g = f - g;
        }
    }
}
