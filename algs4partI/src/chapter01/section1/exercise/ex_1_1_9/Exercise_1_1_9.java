import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Exercise_1_1_9 {
    public static String intToBinaryString (int n) {
        String s = "";
        for( int i = n; i > 0; i /=2)
            s = i%2 + s;
        return s;
    }

    public static void main(String[] args) {
        StdOut.println(1024 + " " + intToBinaryString(1024));
    }
}
