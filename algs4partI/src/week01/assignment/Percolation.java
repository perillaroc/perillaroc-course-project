import java.lang.IndexOutOfBoundsException;

public class Percolation {
    private WeightedQuickUnionUF uf;
    private int[] status;
    private int n;
    // create N-by-N grid, with all sites blocked
    public Percolation(int N)
    {
        n = N;
        uf = new WeightedQuickUnionUF(N*N+2);
        for(int i=0;i<n;i++)
        {
            uf.union(i,N*N);
            uf.union((N-1)*N+i,N*N+1);
        }
        status = new int[N*N+2];
        for(int i=0;i<status.length;i++)
            status[i]=0;
    }

    // open site (row i, column j) if it is not already
    public void open(int i, int j)
    {
        if(i>=n || i<0 || j>=n || j<0)
            throw new IndexOutOfBoundsException();
        int p1 = i*n + j;
        status[p1] = 1;
        if(i>0 && isOpen(i-1,j))
        {   int p2 = (i-1)*n+j;
            uf.union(p1, p2);
        }
        if(i<n-1 && isOpen(i+1,j))
        {   int p2 = (i+1)*n+j;
            uf.union(p1, p2);
        }
        if(j>0 && isOpen(i,j-1))
        {   int p2 = (i)*n+j-1;
            uf.union(p1, p2);
        }
        if(j<n-1 && isOpen(i,j+1))
        {   int p2 = i*n+j+1;
            uf.union(p1, p2);
        }
    }

    // is site (row i, column j) open?
    public boolean isOpen(int i, int j)
    {
        if(i>=n || i<0 || j>=n || j<0)
            throw new IndexOutOfBoundsException();
        return status[i*n+j]>0;
    }

    // is site (row i, column j) full?
    public boolean isFull(int i, int j)
    {
        if(!isOpen(i,j))
            return false;
        int index = i*n+j;
        return uf.connected(index,n*n);
    }

    // does the system percolate?
    public boolean percolates()
    {
        return uf.connected(n*n,n*n+1);
    }
}
