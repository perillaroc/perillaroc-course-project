import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Exercise_1_1_5 {
    public static void main(String[] args) {
        while(!StdIn.isEmpty()){
            double a = StdIn.readDouble();
            if(StdIn.isEmpty())
                break;
            double b = StdIn.readDouble();

            if(a > 0 && a < 1 && b > 0 && b < 0)
                StdOut.println("true");
            else
                StdOut.println("false");
        }
    }
}
