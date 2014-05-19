public class Percolation {
    private WeightedQuickUnionUF uf;
    private int[] status;
    private int n;
    // create N-by-N grid, with all sites blocked
    public Percolation(int N)
    {
        n = N;
        uf = new WeightedQuickUnionUF(N*N+2);
        status = new int[N*N+2];

        for (int i = 0; i < status.length; i++)
            status[i] = 0;

        status[N*N] = 1;
    }

    // open site (row i, column j) if it is not already
    public void open(int i, int j)
    {
        if (i > n || i <= 0)
            throw new IndexOutOfBoundsException("row index i out of bounds");
        if (j > n || j <= 0)
            throw new IndexOutOfBoundsException("col index j out of bounds");

        int p1 = (i-1)*n + (j-1);
        status[p1] = 1;

        if (i == 1)
        {
            uf.union(p1, n*n);
        }

        if (i == n)
        {
            uf.union(p1, n*n+1);
        }

        if (i > 1 && isOpen(i-1, j))
        {
            int p2 = p1-n;
            uf.union(p1, p2);
        }

        if (i < n && isOpen(i+1, j))
        {
            int p2 = p1+n;
            uf.union(p1, p2);
        }

        if (j > 1 && isOpen(i, j-1))
        {
            int p2 = p1-1;
            uf.union(p1, p2);
        }
        if (j < n && isOpen(i, j+1))
        {
            int p2 = p1+1;
            uf.union(p1, p2);
        }
    }

    // is site (row i, column j) open?
    public boolean isOpen(int i, int j)
    {
        if (i > n || i <= 0)
            throw new IndexOutOfBoundsException("row index i out of bounds");
        if (j > n || j <= 0)
            throw new IndexOutOfBoundsException("col index j out of bounds");

        return status[(i-1)*n+j-1]>0;
    }

    // is site (row i, column j) full?
    public boolean isFull(int i, int j)
    {
        if (!isOpen(i, j))
            return false;
        int index = (i-1)*n+j-1;
        return uf.connected(index,n*n);
    }

    // does the system percolate?
    public boolean percolates()
    {
        return uf.connected(n*n,n*n+1);
    }
}
