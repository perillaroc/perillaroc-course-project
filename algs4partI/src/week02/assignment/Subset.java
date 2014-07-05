import java.util.Iterator;

public class Subset {
    public static void main(String[] args)
    {
        RandomizedQueue<String> queue = new RandomizedQueue<String>();
        String[] nums = StdIn.readAllStrings();
        for(String str: nums)
        {
            queue.enqueue(str);
        }
        int k = Integer.parseInt(args[0]);

        Iterator<String> iter = queue.iterator();
        for(int i=0;i<k;i++)
        {
            StdOut.println(iter.next());
        }
    }
}
