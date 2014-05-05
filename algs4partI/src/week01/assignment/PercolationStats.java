import java.lang.IllegalArgumentException;

public class PercolationStats {

    double[] th;
    int n;
    int t;
    // perform T independent computational experiments on an N-by-N grid
    public PercolationStats(int N, int T)
    {
        n = N;
        t = T;
        th = new double[t];
        for(int i=0;i<t;i++)
        {
            Percolation percolation = new Percolation(n);
            int count=0;
            while(!percolation.percolates())
            {
                int p1_i=StdRandom.uniform(N);
                int p1_j=StdRandom.uniform(N);

                while(percolation.isOpen(p1_i,p1_j))
                {
                    p1_i=StdRandom.uniform(N);
                    p1_j=StdRandom.uniform(N);
                }

                percolation.open(p1_i,p1_j);
                count++;
            }
            th[i] = (double)(count) / (n*n);
        }
    }
    // sample mean of percolation threshold
    public double mean()
    {
        return StdStats.mean(th);
    }

    // sample standard deviation of percolation threshold
    public double stddev()
    {
        return StdStats.stddev(th);
    }

    // returns lower bound of the 95% confidence interval
    public double confidenceLo()
    {
        double u = mean();
        double dev = stddev();
        return u-1.96*dev/Math.sqrt(th.length);
    }

    // returns upper bound of the 95% confidence interval
    public double confidenceHi()
    {
        double u = mean();
        double dev = stddev();
        return u+1.96*dev/Math.sqrt(th.length);
    }

    // test client, described below
    public static void main(String[] args)
    {
        int n = Integer.parseInt(args[0]);
        int t = Integer.parseInt(args[1]);
        if(n<=0 || t<=0)
            throw new IllegalArgumentException();

        PercolationStats ps = new PercolationStats(n,t);

        StdOut.printf("mean                    = %f\n", ps.mean());
        StdOut.printf("stddev                  = %.17f\n", ps.stddev());
        StdOut.printf("95%% confidence interval = %.15f, %.15f\n", ps.confidenceLo(), ps.confidenceHi());
    }

}
