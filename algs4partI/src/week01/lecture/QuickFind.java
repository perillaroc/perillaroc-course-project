public class QuickFind {
    private int[] id;
    private int count;
    public QuickFind(int n)
    {
        count = n;
        id = new int[n];
        for(int i=0;i<n;i++)
        {
            id[i] = i;
        }
    }

    public int find(int p)
    {
        return id[p];
    }

    public int count()
    {
        return count;
    }

    public void union(int p, int q)
    {
        int val = find(p);
        for(int i=0;i<count;i++)
        {
            if(id[i]==val)
                id[i]=id[q];
        }
    }

    public boolean connected(int p, int q)
    {
        return id[p]==id[q];
    }

    public static void main(String[] args)
    {
        int n = StdIn.readInt();
        QuickFind qf = new QuickFind(n);
        while(!StdIn.isEmpty())
        {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if(qf.connected(p,q))
                continue;
            qf.union(p,q);
            StdOut.println(p+"-"+q);
        }
        StdOut.println(qf.count()+" components");
    }
}
