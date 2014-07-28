import java.util.Arrays;

public class Fast {
    public static void main(String[] args){
        String filename = args[0];
        In in = new In(filename);
        int N = in.readInt();
        Point[] point_array = new Point[N];
        Point[] work_array = new Point[N];
        for (int i = 0; i < N; i++) {
            int x = in.readInt();
            int y = in.readInt();
            Point p = new Point(x, y);
            point_array[i] = p;
            work_array[i] = p;
        }

        Arrays.sort(point_array, 0, N);

        for(int i1=0;i1<=N-4;i1++) {
            // copy array to work array
            for(int i = i1; i<N; i++)
            {
                work_array[i] = point_array[i];
            }
            Point p = point_array[i1];

            Arrays.sort(work_array, i1+1, N, p.SLOPE_ORDER);

            int count = 0;
            int cur_index = i1+1;
            double slope = p.slopeTo(work_array[cur_index]);
            while(cur_index<N)
            {
                double cur_slope = p.slopeTo(work_array[cur_index]);
                if(cur_slope == slope)
                    count++;
                else{
                    if(count>=3)
                    {
                        // print the list
                        StdOut.printf("%s", p);
                        for(int j = cur_index-count; j<cur_index; j++)
                        {
                            StdOut.printf(" -> %s", work_array[j]);
                        }
                        StdOut.println();
                    }
                    slope = cur_slope;
                    count = 1;
                }
                cur_index++;
            }
            if(count>=3)
            {
                // print the list
                StdOut.printf("%s", p);
                for(int j = cur_index-count; j<cur_index; j++)
                {
                    StdOut.printf(" -> %s", work_array[j]);
                }
                StdOut.println();
            }

        }

    }
}
