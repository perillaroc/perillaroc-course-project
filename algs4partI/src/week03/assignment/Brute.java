import java.util.Arrays;

public class Brute {
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
        for (int i = 0; i < N; i++) {
            int x = in.readInt();
            int y = in.readInt();
            Point p = new Point(x, y);
            point_array[i] = p;
            p.draw();
        }
        StdDraw.show(0);

        // reset the pen radius
        StdDraw.setPenRadius();

        Arrays.sort(point_array, 0, N);

        for(int i1=0;i1<=N-4;i1++)
            for(int i2=i1+1; i2<= N-3; i2++)
                for(int i3=i2+1; i3<= N-2; i3++) {
                    double slope_p1_p2 = point_array[i1].slopeTo(point_array[i2]);
                    double slope_p1_p3 = point_array[i1].slopeTo(point_array[i3]);
                    if(slope_p1_p2 != slope_p1_p3)
                        continue;
                    for (int i4 = i3 + 1; i4 <= N - 1; i4++) {
                        double slope_p1_p4 = point_array[i1].slopeTo(point_array[i4]);
                        if(slope_p1_p2 == slope_p1_p4)
                        {
                            // find one
                            StdOut.printf("%s -> %s -> %s -> %s\n",
                                    point_array[i1].toString(),
                                    point_array[i2].toString(),
                                    point_array[i3].toString(),
                                    point_array[i4].toString());
                            point_array[i1].drawTo(point_array[i4]);

                        }
                    }
                }

        // display to screen all at once
        StdDraw.show(0);


    }

}
