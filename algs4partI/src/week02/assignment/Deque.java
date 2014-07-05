import java.util.Iterator;
import java.util.NoSuchElementException;


public class Deque<Item> implements Iterable<Item> {
    private int N;
    private Node first;
    private Node last;

    private class Node{
        private Item item;
        private Node next;
        private Node pre;
    }

    public Deque()                           // construct an empty deque
    {
        first = null;
        last = null;
        N = 0;
    }

    public boolean isEmpty()                 // is the deque empty?
    {
        return N == 0;
    }

    public int size()                        // return the number of items on the deque
    {
        return N;
    }

    public void addFirst(Item item)          // insert the item at the front
    {
        if(item == null)
            throw new NullPointerException ();
        Node old_first = first;
        first = new Node();
        first.item = item;
        first.next = old_first;
        first.pre = null;
        if(N==0)
            last = first;
        N++;
    }

    public void addLast(Item item)           // insert the item at the end
    {
        if(item == null)
            throw new NullPointerException ();
        Node old_last = last;
        last = new Node();
        last.item = item;
        last.next = null;
        N++;
        if(old_last == null)
        {
            last.pre = null;
            first = last;
        }
        else
        {
            last.pre = old_last.pre;
            old_last.next = last;
        }
    }

    public Item removeFirst()                // delete and return the item at the front
    {
        if(isEmpty())
            throw new NoSuchElementException();
        Item item = first.item;
        first = first.next;
        N--;
        if(isEmpty())
        {
            last = null;
        }
        return item;
    }

    public Item removeLast()                 // delete and return the item at the end
    {
        if(isEmpty())
            throw new NoSuchElementException();
        Item item = last.item;
        last = last.pre;
        N--;
        if(N==0)
            first = null;
        return item;
    }


    private class DequeIterator implements Iterator<Item> {
        private Node current = first;
        public boolean hasNext()  { return current != null;                     }
        public void remove()      { throw new UnsupportedOperationException();  }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    public Iterator<Item> iterator()         // return an iterator over items in order from front to end
    {
        return new DequeIterator();
    }

    public static void main(String[] args)   // unit testing
    {

    }
}