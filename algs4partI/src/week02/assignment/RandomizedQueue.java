import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {

    private Item[] a;
    private int N;

    public RandomizedQueue()                 // construct an empty randomized queue
    {
        a = (Item []) new Object[2];
    }

    public boolean isEmpty()                 // is the queue empty?
    {
        return N == 0;
    }

    public int size()                        // return the number of items on the queue
    {
        return N;
    }

    public void enqueue(Item item)           // add the item
    {
        if (N==a.length) resize(2*a.length);
        a[N++] = item;
    }

    public Item dequeue()                    // delete and return a random item
    {
        if(isEmpty())
            throw new NoSuchElementException();
        int i = StdRandom.uniform(N);
        Item item = a[i];
        a[i] = a[N-1];
        a[N-1] = null;
        N--;
        return item;
    }

    public Item sample()                     // return (but do not delete) a random item
    {
        if(isEmpty())
            throw new NoSuchElementException();
        int i = StdRandom.uniform(N);
        Item item = a[i];
        return item;
    }

    private void resize(int new_length)
    {
        Item[] temp = (Item[]) new Object[new_length];
        for (int i = 0; i < N; i++) {
            temp[i] = a[i];
        }
        a = temp;
    }

    public Iterator<Item> iterator()         // return an independent iterator over items in random order
    {
        return new RandomizedQueueIterator();
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private int i;
        private int[] num;

        public RandomizedQueueIterator() {
            i = -1;
            num = new int[N];
            for(int i=0;i<N;i++)
            {
                num[i] = i;
            }
            StdRandom.shuffle(num);
        }

        public boolean hasNext() {
            return i < num.length-1;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            return a[num[++i]];
        }
    }

    public static void main(String[] args)   // unit testing
    {

    }
}

