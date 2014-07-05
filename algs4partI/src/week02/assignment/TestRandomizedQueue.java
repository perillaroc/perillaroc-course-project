import java.util.Iterator;
public class TestRandomizedQueue {
    public void test_one()
    {
        StdOut.println("test_one:");
        int N = 10;
        RandomizedQueue<Integer> queue = new RandomizedQueue<Integer>();
        for(int i=0;i<N;i++)
        {
            queue.enqueue(i);
        }
        for(int i=0;i<N;i++)
        {
            Iterator<Integer> iter = queue.iterator();
            while(iter.hasNext())
            {
                StdOut.print(iter.next()+" ");
            }
            StdOut.print("\n");
        }

        StdOut.println("Done");
    }

    public static void main(String[] args)
    {
        TestRandomizedQueue test_queue = new TestRandomizedQueue();
        test_queue.test_one();
    }
}
