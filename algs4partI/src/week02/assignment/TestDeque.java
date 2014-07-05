

public class TestDeque {
    public void test_add_first_remove_last()
    {
        StdOut.print("test_add_first_remove_last:");

        Deque<Integer> deque = new Deque<Integer>();
        int N = 10;
        for(int i=0;i<N;i++)
        {
            deque.addFirst(i);
        }

        for(int i=N-1;i>=0;i--)
        {
            assert(deque.removeLast() == i);
        }
        StdOut.print("Done\n");
    }


    public void test_add_last_remove_last()
    {
        StdOut.print("test_add_last_remove_last:");

        Deque<Integer> deque = new Deque<Integer>();
        int N = 10;
        for(int i=0;i<N;i++)
        {
            deque.addLast(i);
        }

        for(int i=N-1;i>=0;i--)
        {
            assert(deque.removeLast() == i);
        }
        StdOut.print("Done\n");
    }

    public static void main(String[] args)
    {
        TestDeque test_deque = new TestDeque();
        test_deque.test_add_first_remove_last();
        test_deque.test_add_last_remove_last();
    }
}
