import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Exercise_1_1_11 {
    public static void main(String[] args) {
        int m = 15;
        int n = 20;

        int m_length = 1;
        int t = m;
        while(t/10 > 0){
            m_length++;
            t = t/10;
        }

        int n_length = 1;
        t = n;
        while(t/10 > 0){
            n_length++;
            t = t/10;
        }

        boolean[][] matrix = new boolean[m][n];

        for(int i=0; i < m; i++) {
            for (int j=0; j<n; j++) {
                matrix[i][j] = StdRandom.bernoulli();
            }
        }
        for(int i=0;i<m_length; i++)
            StdOut.print(" ");
        for (int j=0; j<n; j++) {
            StdOut.printf("%" + n_length + "d", j+1);
        }
        StdOut.println();

        for(int i=0; i < m; i++) {
            StdOut.printf("%" + m_length + "d", i+1);
            for (int j=0; j<n; j++) {
                for(int p=0;p<n_length-1; p++)
                    StdOut.print(" ");
                if(matrix[i][j])
                    StdOut.print('*');
                else
                    StdOut.print(' ');
            }
            StdOut.println();
        }
    }
}
