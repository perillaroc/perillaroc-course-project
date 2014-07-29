import java.util.Arrays;

public class Fast {
    public static void main(String[] args){

        // rescale coordinates and turn on animation mode
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        StdDraw.show(0);
        StdDraw.setPenRadius(0.01);  // make the points a bit larger

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
            p.draw();
        }
        StdDraw.show(0);

        // reset the pen radius
        StdDraw.setPenRadius();

        Arrays.sort(point_array, 0, N);

        for(int i1=0;i1<=N-4;i1++) {
            // copy array to work array
            for(int i = 0; i<N; i++)
            {
                work_array[i] = point_array[i];
            }
            Point p = point_array[i1];

            Arrays.sort(work_array, 0, N, p.SLOPE_ORDER);

            int count = 0;
            int cur_index = 0;
            double slope = p.slopeTo(work_array[cur_index]);
            while(cur_index<N)
            {
                double cur_slope = p.slopeTo(work_array[cur_index]);
                if(cur_slope == slope)
                    count++;
                else{
                    if(count>=3)
                    {
                        //check if p is the first point
                        boolean flag = true;
                        for(int j = cur_index-count; j<cur_index; j++)
                        {
                            if(p.compareTo(work_array[j])>0){
                                flag = false;
                                break;
                            }
                        }
                        // print the list
                        if(flag){
                            StdOut.printf("%s", p);
                            for(int j = cur_index-count; j<cur_index; j++)
                            {
                                StdOut.printf(" -> %s", work_array[j]);
                            }
                            StdOut.println();
                            p.drawTo(work_array[cur_index-1]);
                        }
                    }
                    slope = cur_slope;
                    count = 1;
                }
                cur_index++;
            }
            if(count>=3)
            {
                boolean flag = true;
                for(int j = cur_index-count; j<cur_index; j++)
                {
                    if(p.compareTo(work_array[j])>0){
                        flag = false;
                        break;
                    }
                }
                // print the list
                if(flag){
                    StdOut.printf("%s", p);
                    for(int j = cur_index-count; j<cur_index; j++)
                    {
                        StdOut.printf(" -> %s", work_array[j]);
                    }
                    StdOut.println();
                    p.drawTo(work_array[cur_index-1]);
                }
            }

        }

        // display to screen all at once
        StdDraw.show(0);

    }
}
