public class Board {
    public int[][] blocks_;
    private int N;

    // construct a board from an N-by-N array of blocks
    // (where blocks[i][j] = block in row i, column j)
    public Board(int[][] blocks){
        blocks_ = blocks;
        N = blocks_.length;
    }

    // board dimension N
    public int dimension(){
        return N;
    }

    // number of blocks out of place
    public int hamming(){
        int total = 0;
        int n = dimension();
        for(int i=0;i<n;i++) {
            for (int j = 0; j < n; j++) {
                if( i==n-1 && j==n-1)
                    continue;
                if(blocks_[i][j] != i*n + j + 1) {
                    total++;
                }
            }
        }
        return total;
    }

    // sum of Manhattan distances between blocks and goal
    public int manhattan(){
        int total = 0;
        int n = dimension();
        for(int i=0;i<n;i++) {
            for (int j = 0; j < n; j++) {
                int val = blocks_[i][j];
                int end_i,end_j;
                if(val == 0){
                    end_i = n-1;
                    end_j = n-1;
                } else {
                    end_i = val%n;
                    end_j = val - end_i*n;
                }
                total+= Math.abs(end_i - i) + Math.abs(end_j - j);
            }
        }
        return total;
    }

    // is this board the goal board?
    public boolean isGoal(){
        boolean flag = true;
        int n = dimension();
        for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                if(blocks_[i][j] != i*n + j) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }

    // a board obtained by exchanging two adjacent blocks in the same row
    public Board twin(){
        int i=0;
        int j=0;
        if(blocks_[0][0] ==0 || blocks_[0][0] ==0 || blocks_[0][1] == 0){
            i=1;
        }
        int[][] values = new int[N][N];
        int temp = values[i][j];
        values[i][j] = values[i][j+1];
        values[i][j+1] = temp;
        return new Board(values);
    }

    // does this board equal y?
    public boolean equals(Object y){
        if(this == y) return true;
        if(y == null) return false;
        if(this.getClass() != y.getClass()) return false;
        Board another_board = (Board)y;
        int n = this.dimension();
        if(n != ((Board) y).dimension()) return false;
        boolean flag = true;
        for(int i=0; i<n; i++){
            for(int j=0;j<n;j++){
                if(blocks_[i][j] != another_board.blocks_[i][j] ) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }

    // all neighboring boards
    public Iterable<Board> neighbors(){
        int i=0,j=0;
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) {
                if(blocks_[i][j]==0)
                    break;
            }
        }

        Queue<Board> queue = new Queue<Board>();
        if(i > 0) {
            int[][] values = new int[N][N];
            for(int x=0;x<N;x++)
                for(int y=0;y<N;y++)
                    values[x][y] = blocks_[x][y];
            int temp = values[i-1][j];
            values[i-1][j] = values[i][j];
            values[i][j] = temp;
            queue.enqueue(new Board(values));
        }
        if(i < N-1) {
            int[][] values = new int[N][N];
            for(int x=0;x<N;x++)
                for(int y=0;y<N;y++)
                    values[x][y] = blocks_[x][y];
            int temp = values[i+1][j];
            values[i+1][j] = values[i][j];
            values[i][j] = temp;
            queue.enqueue(new Board(values));
        }
        if(j > 0) {
            int[][] values = new int[N][N];
            for(int x=0;x<N;x++)
                for(int y=0;y<N;y++)
                    values[x][y] = blocks_[x][y];
            int temp = values[i][j-1];
            values[i][j-1] = values[i][j];
            values[i][j] = temp;
            queue.enqueue(new Board(values));
        }
        if(j < N-1) {
            int[][] values = new int[N][N];
            for(int x=0;x<N;x++)
                for(int y=0;y<N;y++)
                    values[x][y] = blocks_[x][y];
            int temp = values[i][j+1];
            values[i][j+1] = values[i][j];
            values[i][j] = temp;
            queue.enqueue(new Board(values));
        }

        return queue;
    }

    // string representation of the board (in the output format specified below)
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append(N + "\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                s.append(String.format("%2d ", blocks_[i][j]));
            }
            s.append("\n");
        }
        return s.toString();
    }
}
