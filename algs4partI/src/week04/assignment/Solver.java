public class Solver {
    private Board initial_board_;
    private MinPQ<SolverStep> origin_pq_ = new MinPQ<SolverStep>();
    private SolverStep solver_step_ = null;

    private Board twin_board_;
    private MinPQ<SolverStep> twin_pq_ = new MinPQ<SolverStep>();
    private boolean is_solvable_ = false;

    private class SolverStep implements Comparable<SolverStep>{
        public Board board_;
        public SolverStep parent_;
        public int moves_;
        public int manhattan_;
        public int priority_;
        public SolverStep(Board board, int moves, SolverStep parent){
            board_ = board;
            parent_ = parent;
            moves_ = moves;
            manhattan_ = board_.manhattan();
            priority_ = moves_ + manhattan_;
        }

        public int compareTo(SolverStep that){
            if( this.priority_ < that.priority_) return -1;
            if( this.priority_ > that.priority_) return 1;
            return 0;
        }
    }

    // find a solution to the initial board (using the A* algorithm)
    public Solver(Board initial){
        initial_board_ = initial;
        twin_board_ = initial_board_.twin();
        SolverStep origin_step = new SolverStep(initial_board_, 0, null);
        origin_pq_.insert(origin_step);
        SolverStep twin_step = new SolverStep(twin_board_, 0, null);
        twin_pq_.insert(twin_step);

        // A* algorithm
        while(true){
            SolverStep current_origin_step = origin_pq_.delMin();
            //StdOut.println(current_origin_step.board_.toString());
            //StdOut.println(current_origin_step.priority_);
            if(current_origin_step.board_.isGoal()){
                is_solvable_ = true;
                solver_step_ = current_origin_step;
                break;
            } else {
                for (Board board : current_origin_step.board_.neighbors()) {
                    SolverStep a_new_step = new SolverStep(board,
                            current_origin_step.moves_+1,
                            current_origin_step);
                    if (a_new_step != current_origin_step.parent_)
                        origin_pq_.insert(a_new_step);
                }
            }

            SolverStep current_twin_step = twin_pq_.delMin();
            if(current_twin_step.board_.isGoal())
            {
                break;
            } else {
                for (Board board : current_twin_step.board_.neighbors()) {
                    SolverStep a_new_step = new SolverStep(board,
                            current_twin_step.moves_+1,
                            current_twin_step);
                    if (a_new_step != current_origin_step.parent_)
                        twin_pq_.insert(a_new_step);
                }
            }
        }

    }

    // is the initial board solvable?
    public boolean isSolvable() {
        return is_solvable_;
    }

    // min number of moves to solve initial board; -1 if no solution
    public int moves() {
        if(!isSolvable())
            return -1;
        return solver_step_.moves_;
    }

    // sequence of boards in a shortest solution; null if no solution
    public Iterable<Board> solution() {
        Stack<Board> board_seq = new Stack<Board>();
        SolverStep step = solver_step_;
        while(step != null) {
            board_seq.push(step.board_);
            step = step.parent_;
        }
        return board_seq;
    }

    // solve a slider puzzle (given below)
    public static void main(String[] args) {
        // create initial board from file
        In in = new In(args[0]);
        int N = in.readInt();
        int[][] blocks = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                blocks[i][j] = in.readInt();
        Board initial = new Board(blocks);

        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board);
        }
    }
}