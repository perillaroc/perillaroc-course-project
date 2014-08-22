public class Board {
    private int[][] tails;
    private int N;

    // construct a board from an N-by-N array of blocks
    // (where blocks[i][j] = block in row i, column j)
    public Board(int[][] blocks) {
        N = blocks.length;
        tails = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                tails[i][j] = blocks[i][j];

    }

    // board dimension N
    public int dimension() {
        return N;
    }

    // number of blocks out of place
    public int hamming() {
        int total = 0;
        int n = dimension();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == n-1 && j == n-1)
                    continue;
                if (tails[i][j] != i*n + j + 1) {
                    total++;
                }
            }
        }
        return total;
    }

    // sum of Manhattan distances between blocks and goal
    public int manhattan() {
        int total = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int val = tails[i][j];
                int correctPositionOfi, correctPositionOfj;
                if (val == 0) {
                    continue;
                } else {
                    correctPositionOfi = (val-1)/N;
                    correctPositionOfj = (val-1) % N;
                }
                total += Math.abs(correctPositionOfi - i)
                        + Math.abs(correctPositionOfj - j);
            }
        }
        return total;
    }

    // is this board the goal board?
    public boolean isGoal() {
        boolean flag = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == N-1 && j == N-1) continue;
                if (tails[i][j] != i*N + j + 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        return flag;
    }

    // a board obtained by exchanging two adjacent blocks in the same row
    public Board twin() {
        int i = 0;
        int j = 0;
        for (int x = 0; x < N; x++) {
            if (tails[i][x] == 0)
                break;
        }
        if (j != N) {
            i = 1;
        }
        int[][] values = new int[N][N];
        for (int x = 0; x < N; x++)
            for (int y = 0; y < N; y++)
                values[x][y] = tails[x][y];
        int temp = values[i][j];
        values[i][j] = values[i][j+1];
        values[i][j+1] = temp;
        return new Board(values);
    }

    // does this board equal y?
    public boolean equals(Object y) {
        if (this == y) return true;
        if (y == null) return false;
        if (this.getClass() != y.getClass()) return false;
        Board anotherBoard = (Board) y;
        int n = this.dimension();
        if (n != ((Board) y).dimension()) return false;
        boolean flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tails[i][j] != anotherBoard.tails[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }

    // all neighboring boards
    public Iterable<Board> neighbors() {
        int i = 0, j = 0;
        boolean flag = false;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (tails[i][j] == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        Queue<Board> queue = new Queue<Board>();
        if (i > 0) {
            int[][] values = new int[N][N];
            for (int x = 0; x < N; x++)
                for (int y = 0; y < N; y++)
                    values[x][y] = tails[x][y];
            int temp = values[i-1][j];
            values[i-1][j] = values[i][j];
            values[i][j] = temp;
            queue.enqueue(new Board(values));
        }
        if (i < N-1) {
            int[][] values = new int[N][N];
            for (int x = 0; x < N; x++)
                for (int y = 0; y < N; y++)
                    values[x][y] = tails[x][y];
            int temp = values[i+1][j];
            values[i+1][j] = values[i][j];
            values[i][j] = temp;
            queue.enqueue(new Board(values));
        }
        if (j > 0) {
            int[][] values = new int[N][N];
            for (int x = 0; x < N; x++)
                for (int y = 0; y < N; y++)
                    values[x][y] = tails[x][y];
            int temp = values[i][j-1];
            values[i][j-1] = values[i][j];
            values[i][j] = temp;
            queue.enqueue(new Board(values));
        }
        if (j < N-1) {
            int[][] values = new int[N][N];
            for (int x = 0; x < N; x++)
                for (int y = 0; y < N; y++)
                    values[x][y] = tails[x][y];
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
                s.append(String.format("%2d ", tails[i][j]));
            }
            s.append("\n");
        }
        return s.toString();
    }
}
